// BUS_A
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - enable ap_done interrupt (Read/Write)
//         bit 1  - enable ap_ready interrupt (Read/Write)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - ap_done (COR/TOW)
//         bit 1  - ap_ready (COR/TOW)
//         others - reserved
// 0x010 ~
// 0x01f : Memory 'pt' (16 * 8b)
//         Word n : bit [ 7: 0] - pt[4n]
//                  bit [15: 8] - pt[4n+1]
//                  bit [23:16] - pt[4n+2]
//                  bit [31:24] - pt[4n+3]
// 0x020 ~
// 0x02f : Memory 'ct' (16 * 8b)
//         Word n : bit [ 7: 0] - ct[4n]
//                  bit [15: 8] - ct[4n+1]
//                  bit [23:16] - ct[4n+2]
//                  bit [31:24] - ct[4n+3]
// 0x100 ~
// 0x1ff : Memory 'rk' (44 * 32b)
//         Word n : bit [31:0] - rk[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

extern struct timespec accel_TX_start, accel_TX_end;
extern struct timespec accel_compute_start, accel_compute_end;
extern struct timespec accel_RX_start, accel_RX_end;

typedef unsigned int u32;
typedef unsigned char u8;

//ARM
#include<sys/mman.h>
#include<sys/types.h>

#define AES_ENC_BASE_ADDR 0xA0010000	// TODO: Change with vivado address map
#define AES_DEC_BASE_ADDR 0xA0020000

#define CONTROL_ENC_OFFSET 0x00
#define PLAINTEXT_ENC_OFFSET 0x04
#define CIPHERTEXT_ENC_OFFSET 0x08
#define ROUNDKEY_ENC_OFFSET 0x40

#define CONTROL_DEC_OFFSET 0x00
#define CIPHERTEXT_DEC_OFFSET 0x04
#define PLAINTEXT_DEC_OFFSET 0x08
#define ROUNDKEY_DEC_OFFSET 0x40

#define MEM_SIZE 512// in bytes
//
int aes_enc_control_fd;
int aes_dec_control_fd;

volatile unsigned int* aes_enc_control_base_addr;
volatile unsigned int* aes_dec_control_base_addr;

// Initialization function
/*
 * Create a memory map and get base address of aes accelerator
 * 
 */
void init_aes_enc(){
    printf("[AES] Initializing AES encryptor accelerator.\n");
    
    aes_enc_control_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (aes_enc_control_fd < 0){
        fprintf(stderr, "[AES] Can't open /dev/mem! Exiting ...\n");
	exit(1);
    }

    aes_enc_control_base_addr = (volatile unsigned int *)mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, aes_enc_control_fd,
		    					AES_ENC_BASE_ADDR);

    if (aes_enc_control_base_addr == MAP_FAILED){
        fprintf(stderr, "[AES] Can't obtain memory map to AES encryptor control slave! Exiting ...\n");
	exit(1);
    }

    printf("[AES] Successfully initialized AES encryptor accelerator!\n");
}


void init_aes_dec(){
    printf("[AES] Initializing AES decryptor accelerator.\n");

    aes_dec_control_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (aes_dec_control_fd < 0){
        fprintf(stderr, "[AES] Can't open /dev/mem! Exiting ...\n");
        exit(1);
    }

    aes_dec_control_base_addr = (volatile unsigned int *)mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, aes_dec_control_fd,
                                                          AES_DEC_BASE_ADDR);

    if (aes_dec_control_base_addr == MAP_FAILED){
        fprintf(stderr, "[AES] Can't obtain memory map to AES decryptor control slave! Exiting ...\n");
        exit(1);
    }

    printf("[AES] Successfully initialized AES decryptor accelerator!\n");
}


// write register function
void write_aes_register(volatile unsigned int* base_addr, unsigned int offset, unsigned int number){
    *(base_addr+offset) = number;
}


// start aes accelerator
void start_aes(volatile unsigned int* base_addr, unsigned int control_reg_offset){
    write_aes_register(base_addr, control_reg_offset, 0x01); // TODO: Check value being written
}

// wait for aes accelerator to complete
void wait_for_aes_complete(volatile unsigned int* base_addr){
    unsigned int control_reg_value = *(base_addr);
    int i = 0;

    while (1){
    	control_reg_value = *(base_addr);
        if ((control_reg_value & 0x2) != 0x2) break;

	    if (i%10000 == 0)
		    printf("[AES] AES status from Control register is 0x%x .. \n", control_reg_value);
	    i++;
    }
}


// close memory map
void close_aes_enc(){
    munmap((unsigned int*)aes_enc_control_base_addr, getpagesize());
    close(aes_enc_control_fd);
}
void close_aes_dec(){
    munmap((unsigned int*)aes_dec_control_base_addr, getpagesize());
    close(aes_dec_control_fd);
}

void __attribute__((constructor)) setup() {
  printf("[aes] Initializing accelerator...\n");
  init_aes_enc();
  init_aes_dec();  
  printf("[aes] Initialization complete!\n");
}

void __attribute__((destructor)) teardown() {
  printf("[aes] Tearing down accelerator...\n");
  close_aes_enc();
  close_aes_dec();
  printf("[aes] Teardown complete!\n");
}


// ########################################### Program to perform AES encryption on accelerator ##############################################
int rijndaelEncrypt_acc(u32 *rk, u8 *pt, u8 *ct){
    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_TX_start);
    //printf("[AES] Copying round key to accelerator\n");
    u32 *addr = memcpy((void*)(aes_enc_control_base_addr+ROUNDKEY_ENC_OFFSET), (const void*) rk, 44*sizeof(u32));
    if (addr==NULL){
        printf("[AES-ERROR] memcpy of round key failed!!!\n");
        exit(1);
    }
    //printf("[AES] Done copying round key to accelerator\n");

    //printf("[AES] Copying plaintext to accelerator\n");
    u8 *chaddr = memcpy((void*)(aes_enc_control_base_addr+PLAINTEXT_ENC_OFFSET), pt, 16*sizeof(u8));
    if (chaddr == NULL){
        printf("[AES-ERROR] mempcy of plaintext failed!!!\n");
        exit(1);
    }
    //printf("[AES] Done copying plaintext to accelerator\n");

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_compute_start);

    //printf("[AES] Launching AES accelerator\n");
    start_aes(aes_enc_control_base_addr, CONTROL_ENC_OFFSET);
    //printf("[AES] Waiting for AES accelerator to complete\n");
    wait_for_aes_complete(aes_enc_control_base_addr);
    //printf("[AES] AES accelerator finished execution\n");

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_start);

    //printf("[AES] Copying ciphertext back from accelerator\n");
    chaddr = memcpy(ct, (aes_enc_control_base_addr+CIPHERTEXT_ENC_OFFSET), 16*sizeof(u8));
    if (chaddr == NULL){
        printf("[AES-ERROR] memcpy of ciphertext from accelarator to memory failed\n");
        exit(1);
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_end);
    //printf("[AES] Ciphertext received from accelerator\n");

    /*printf("[AES] Received ciphertext is\n");
    for (int i=0; i<4; i++){
	    for (int j=0; j<4; j++)
	        printf("0x%x, ", ct[i*4+j]);
	    printf("\n");
    }
    printf("\n");*/
    //printf("[AES] Bye bye from AES accelerator...\n");
    return 0;
}


// ########################################### Program to perform AES decryption on accelerator ##############################################
int rijndaelDecrypt_acc(u32 *rk, u8 *ct, u8 *pt){
    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_TX_start);
    //printf("[AES] Copying round key to accelerator\n");
    u32 *addr = memcpy((void*)(aes_dec_control_base_addr+ROUNDKEY_DEC_OFFSET), (const void*) rk, 44*sizeof(u32));
    if (addr==NULL){
        printf("[AES-ERROR] memcpy of round key failed!!!\n");
        exit(1);
    }
    //printf("[AES] Done copying round key to accelerator\n");

    //printf("[AES] Copying ciphertext to accelerator\n");
    u8 *chaddr = memcpy((void*)(aes_dec_control_base_addr+CIPHERTEXT_DEC_OFFSET), ct, 16*sizeof(u8));
    if (chaddr == NULL){
        printf("[AES-ERROR] mempcy of ciphertext failed!!!\n");
        exit(1);
    }
    //printf("[AES] Done copying ciphertext to accelerator\n");

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_compute_start);

    //printf("[AES] Launching AES decryptor accelerator\n");
    start_aes(aes_dec_control_base_addr, CONTROL_DEC_OFFSET);
    //printf("[AES] Waiting for AES decryptor accelerator to complete\n");
    wait_for_aes_complete(aes_dec_control_base_addr);
    //printf("[AES] AES decryptor accelerator finished execution\n");

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_start);

    //printf("[AES] Copying plaintext back from accelerator\n");
    chaddr = memcpy(pt, (aes_dec_control_base_addr+PLAINTEXT_DEC_OFFSET), 16*sizeof(u8));
    if (chaddr == NULL){
        printf("[AES-ERROR] memcpy of plaintext from accelarator to memory failed\n");
        exit(1);
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &accel_RX_end);
    //printf("[AES] Plaintext received from accelerator\n");

    /*printf("[AES] Received ciphertext is\n");
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++)
            printf("0x%x, ", ct[i*4+j]);
        printf("\n");
    }
    printf("\n");*/
    //printf("[AES] Bye bye from AES accelerator...\n");
    return 0;
}

