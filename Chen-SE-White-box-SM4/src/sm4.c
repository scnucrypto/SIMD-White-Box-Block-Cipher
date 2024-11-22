#include<stdio.h>
#include<stdlib.h>
#include"generateTable.h"
#include<time.h>


//S-box

const u8 Sbox[256] = {
	0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05,
	0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99,
	0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62,
	0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6,
	0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8,
	0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35,
	0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87,
	0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e,
	0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1,
	0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3,
	0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f,
	0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51,
	0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8,
	0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0,
	0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84,
	0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48
};


//The constant FK of the key extension algorithm
const u32 FK[4] = {
	0xa3b1bac6, 0x56aa3350, 0x677d9197, 0xb27022dc
};

//Fixed parameters CK of the key extension algorithm  
const u32 CK[32] = {
	0x00070e15, 0x1c232a31, 0x383f464d, 0x545b6269,
	0x70777e85, 0x8c939aa1, 0xa8afb6bd, 0xc4cbd2d9,
	0xe0e7eef5, 0xfc030a11, 0x181f262d, 0x343b4249,
	0x50575e65, 0x6c737a81, 0x888f969d, 0xa4abb2b9,
	0xc0c7ced5, 0xdce3eaf1, 0xf8ff060d, 0x141b2229,
	0x30373e45, 0x4c535a61, 0x686f767d, 0x848b9299,
	0xa0a7aeb5, 0xbcc3cad1, 0xd8dfe6ed, 0xf4fb0209,
	0x10171e25, 0x2c333a41, 0x484f565d, 0x646b7279
};

u32 functionB(u32 b); //The function B of checking the S-box
u32 loopLeft(u32 a, short length); //The shift of circle left
u32 functionL1(u32 a); //Linear transformation L
u32 functionL2(u32 a); //Linear transformation L'
u32 functionT(u32 a, short mode); //The transformation T
void extendFirst(u32 MK[], u32 K[]); //The first step of the key extension algorithm
void extendSecond(u32 RK[], u32 K[]); //The second step of the key extension algorithm
void getRK(u32 MK[], u32 K[], u32 RK[]); //The algorithm of generating round keys
void iterate32(u32 X[], u32 RK[]); //Iterative algorithm
void reverse(u32 X[], u32 Y[]); //The function of reversing the order
void encryptSM4(u32 X[], u32 RK[], u32 Y[]); //Encryption algorithm
void decryptSM4(u32 X[], u32 RK[], u32 Y[]); //Decryption algorithm


//The function B of checking the S-box

u32 functionB(u32 b) {
	u8 a[4];
	short i;
	a[0] = b / 0x1000000;
	a[1] = b / 0x10000;
	a[2] = b / 0x100;
	a[3] = b;
	b = Sbox[a[0]] * 0x1000000 + Sbox[a[1]] * 0x10000 + Sbox[a[2]] * 0x100 + Sbox[a[3]];
	return b;
}


//The shift of circle left
u32 loopLeft(u32 a, short length) {
	short i;
	for (i = 0; i < length; i++) {
		a = a * 2 + a / 0x80000000;
	}
	return a;
}


//Linear transformation L
u32 functionL1(u32 a) {
	return a ^ loopLeft(a, 2) ^ loopLeft(a, 10) ^ loopLeft(a, 18) ^ loopLeft(a, 24);
}


//Linear transformation L'
u32 functionL2(u32 a) {
	return a ^ loopLeft(a, 13) ^ loopLeft(a, 23);
}


//The transformation T
u32 functionT(u32 a, short mode) {
	return mode == 1 ? functionL1(functionB(a)) : functionL2(functionB(a));
}


//The first step of the key extension algorithm
void extendFirst(u32 MK[], u32 K[]) {
	int i;
	for (i = 0; i < 4; i++) {
		K[i] = MK[i] ^ FK[i];
	}
}


//The second step of the key extension algorithm
void extendSecond(u32 RK[], u32 K[]) {
	short i;
	for (i = 0; i < 32; i++) {
		K[(i + 4) % 4] = K[i % 4] ^ functionT(K[(i + 1) % 4] ^ K[(i + 2) % 4] ^ K[(i + 3) % 4] ^ CK[i], 2);
		RK[i] = K[(i + 4) % 4];
	}
}

// ! 原有密钥扩展函数错误
// ! The original code function has an issue where it fails to output the standard round key.
//The algorithm of generating round keys
void getRK(u32 MK[], u32 K[], u32 RK[]) {
	extendFirst(MK, K);
	extendSecond(RK, K);
}


//Iterative algorithm
void iterate32(u32 X[], u32 RK[]) {
	short i;
	for (i = 0; i < 32; i++) {
		X[(i + 4) % 4] = X[i % 4] ^ functionT(X[(i + 1) % 4] ^ X[(i + 2) % 4] ^ X[(i + 3) % 4] ^ RK[i], 1);
	}
}


//The function of reversing the order
void reverse(u32 X[], u32 Y[]) {
	short i;
	for (i = 0; i < 4; i++) {
		Y[i] = X[4 - 1 - i];
	}
}


//Encryption algorithm
void encryptSM4(u32 X[], u32 RK[], u32 Y[]) {
	iterate32(X, RK);
	reverse(X, Y);
}


//Decryption algorithm
void decryptSM4(u32 X[], u32 RK[], u32 Y[]) {
	short i;
	u32 reverseRK[32];
	for (i = 0; i < 32; i++) {
		reverseRK[i] = RK[32 - 1 - i];
	}
	iterate32(X, reverseRK);
	reverse(X, Y);
}

void getx(u32 X[4], u8 x8[16])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x8[j + i * 4] = (X[i] >> (24 - j * 8)) & 255;
		}
	}
}

void getca(u8 a[16], u8 c[128])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			c[i * 8 + j] = (a[i] >> (7 - j)) & 1;
		}
	}
}

/*
	The data of testing��
	plaintext:01234567 89abcdef fedcba98 76543210
	key:��01234567 89abcdef fedcba98 76543210
	ciphertext��681edf34 d206965e 86b3e94f 536e4246
*/
// int main(void) 
// {

// 	time_t t;
// 	srand((unsigned)time(&t));

// 	u32 X[4] = {0x01234567, 0x89abcdef, 0xfedcba98, 0x76543210}; //plaintext
// 	u8 x8[16];//Plaintext stored by byte
// 	u32 MK[4] = {0x01234567, 0x89abcdef, 0xfedcba98, 0x76543210}; //Key
// 	u32 RK[32] = {0}; //Round keys
// 	u32 K[4] = {0}; //Intermediate data
// 	u32 Y[4]; //Ciphertext
// 	short i; //Temporary Variables
	
// 	getx(X, x8);

// 	printf("\nGenerate Round Keys:\n");
// 	getRK(MK, K, RK);
// 	for (i = 0; i < 32; i++) {
// 		printf("[%2d]%08x    ", i, RK[i]);
// 		if (i % 4 == 3)	printf("\n");
// 	}
	
// 	printf("\nGenerate ciphertext of SM4: ");
// 	encryptSM4(X, RK, Y);
// 	printf("%08x %08x %08x %08x\n", Y[0], Y[1], Y[2], Y[3]);
	
// 	decryptSM4(Y, RK, X);


// 	printf("\nWhite-box implementation (Please wait a moment)��");


// 	u8 wY[16];//White-box ciphertext

	
// 	//White-box encryption(With external code)
// 	Wencrypt(X, MK, wY, 1);

// 	printf("\n\nGenerate ciphertext of white-box SM4 (With external code):\n");
// 	for (int i = 0; i < 16; i++)
// 	{
// 		printf("%x ", wY[i]);
// 	}

	
// 	//White-box encryption(Without external code)
// 	Wencrypt(X, MK, wY, 0);

// 	printf("\n\nGenerate ciphertext of white-box SM4 (Without external code):\n");
// 	for (int i = 0; i < 16; i++)
// 	{
// 		printf("%x ", wY[i]);
// 	}
// 	printf("\n");

// 	return 0;

// }