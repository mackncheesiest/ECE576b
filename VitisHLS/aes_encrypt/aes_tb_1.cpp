#include<stdio.h>
#include"ap_int.h"

//#define char ap_uint<8>
//#define integer ap_uint<32>
//#define unsignedint ap_uint<32>

typedef unsigned char u8;
typedef unsigned int u32;

void rijndaelEncrypt_hls(u32 rk[44], u8 pt[16], u8 ct[16]);

int main(){
	u8 plaintext[16] = {
			0x3f,0xd4,0x19,0x01,
			0x42,0xa1,0x53,0x76,
			0x3e,0x59,0xb3,0xf9,
			0x42,0x89,0x56,0x31
	};
	u8 ciphertext_ref[16] = {
			0xec,0xae,0xb0,0x2a,
			0xf2,0x51,0x45,0x25,
			0xb4,0x19,0x18,0x70,
			0x10,0x2,0x5,0x12
	};
	u8 ciphertext[16] = {
			0,0,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0
	};
	u32 roundkey[44] = {
			0x33c66d09, 0x3e685c0f, 0x63031379, 0x927c2a09,
			0x22236c46, 0x1c4b3049, 0x7f482330, 0xed340939,
			0x38227e13, 0x24694e5a, 0x5b216d6a, 0xb6156453,
			0x6561935d, 0x4108dd07, 0x1a29b06d, 0xac3cd43e,
			0x862921cc, 0xc721fccb, 0xdd084ca6, 0x71349898,
			0x8e6f676f, 0x494e9ba4, 0x9446d702, 0xe5724f9a,
			0xeeebdfb6, 0xa7a54412, 0x33e39310, 0xd691dc8a,
			0x2f6da140, 0x88c8e552, 0xbb2b7642, 0x6dbaaac8,
			0x5bc1497c, 0xd309ac2e, 0x6822da6c, 0x059870a4,
			0x06900017, 0xd599ac39, 0xbdbb7655, 0xb82306f1,
			0x16ffa17b, 0xc3660d42, 0x7edd7b17, 0xc6fe7de6
	} ;
//	printf("[SIM] Ciphertext initialized\n");
//		for(int i=0; i<16; i++){
//			printf("0x%x, ", ciphertext[i]);
//			//std::cout << ciphertext[i] << ", ";
//		}
//		printf("\n");

	printf("[SIM] Calling encryptor function\n");

	rijndaelEncrypt_hls(roundkey, plaintext, ciphertext);

	printf("[SIM] Finished encryptor function\n");
	printf("[SIM] Checking against reference ciphertext\n");
	for(int i=0; i<16; i++){
		if(ciphertext[i] != ciphertext_ref[i]){
			printf("[ERROR] Ciphertext differs from reference at index %d. Expected 0x%x, found 0x%x\n", i, ciphertext_ref[i], ciphertext[i]);
			goto error;
		}
	}
	printf("[SIM] Ciphertext Correct !!!\n");
	error:
	printf("[SIM] Ciphertext value received from aes accelerator\n");
	for(int i=0; i<16; i++){
		printf("0x%x, ", ciphertext[i]);
	}
	printf("\n");
	return 0;
}
