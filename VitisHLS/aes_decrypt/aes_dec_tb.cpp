#include<stdio.h>

typedef unsigned char u8;
typedef unsigned int u32;

void rijndaelDecrypt_hls(u32 rk[44], u8 ct[16], u8 pt[16]);

int main(){

	u8 ciphertext[16] = {
	0xec, 0xae, 0xb0, 0x2a,
	0xf2, 0x51, 0x45, 0x25,
	0xb4, 0x19, 0x18, 0x70,
	0x10, 0x2, 0x5, 0x12
	};

	u32 roundkey[44] = {
	0x16ffa17b, 0xc3660d42, 0x7edd7b17, 0xc6fe7de6, 0xcc64d3fa, 0xf90e2907, 0xa6b9271d, 0x7a2d1c27, 0x9ca8cb50, 0x356afafd, 0x5fb70e1a,
	0xdc943b3a, 0x6996bae6, 0xa9c231ad, 0x6addf4e7, 0x83233520, 0x1cde848, 0xc0548b4b, 0xc31fc54a, 0xe9fec1c7, 0x3e9f1e56, 0xc1996303,
	0x34b4e01, 0x2ae1048d, 0xde42e85, 0xff067d55, 0xc2d22d02, 0x29aa4a8c, 0x58ae211d, 0xf2e253d0, 0x3dd45057, 0xeb78678e, 0xedbc4563,
	0xaa4c72cd, 0xcf360387, 0xd6ac37d9, 0x6b5a7369, 0x47f037ae, 0x657a714a, 0x199a345e, 0x33c66d09, 0x3e685c0f, 0x63031379, 0x927c2a09
	};

	u8 plaintext_ref[16] = {
	0x3f, 0xd4, 0x19, 0x01,
	0x42, 0xa1, 0x53, 0x76,
	0x3e, 0x59, 0xb3, 0xf9,
	0x42, 0x89, 0x56, 0x31
	};

	u8 plaintext[16] = {
			0,0,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0
	};

//	printf("[SIM] Plaintext initialized\n");
//		for(int i=0; i<16; i++){
//			printf("0x%x, ", plaintet[i]);
//		}
//		printf("\n");

	printf("[SIM] Calling decryptor function\n");

	rijndaelDecrypt_hls(roundkey, ciphertext, plaintext);

	printf("[SIM] Finished decryptor function\n");
	printf("[SIM] Checking against reference ciphertext\n");
	for(int i=0; i<16; i++){
		if(plaintext[i] != plaintext_ref[i]){
			printf("[ERROR] Plaintext differs from reference at index %d. Expected 0x%x, found 0x%x\n", i, plaintext_ref[i], plaintext[i]);
			goto error;
		}
	}
	printf("[SIM] Plaintext Correct !!!\n");
	error:
	printf("[SIM] Plaintext value received from aes accelerator\n");
	for(int i=0; i<16; i++){
		printf("0x%x, ", plaintext[i]);
	}
	printf("\n");
	return 0;
}
