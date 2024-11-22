// #include "generateTable.h"
// #include "wbsm4_se_cl_avx2.h"

// static uint32_t S1_f4_T3[32][4][256];
// static uint32_t S1_f4_T2[32][4][256];
// static uint32_t S1_f4_T1[32][4][256];
// static uint32_t S1_f4_T0[32][4][256];

// static uint32_t S2_f4_T3[32][4][256];
// static uint32_t S2_f4_T2[32][4][256];
// static uint32_t S2_f4_T1[32][4][256];
// static uint32_t S2_f4_T0[32][4][256];

// static uint32_t S1_f4a_inv_T3[32][4][256];
// static uint32_t S1_f4a_inv_T2[32][4][256];
// static uint32_t S1_f4a_inv_T1[32][4][256];
// static uint32_t S1_f4a_inv_T0[32][4][256];

// static uint32_t S2_f4a_inv_T3[32][4][256];
// static uint32_t S2_f4a_inv_T2[32][4][256];
// static uint32_t S2_f4a_inv_T1[32][4][256];
// static uint32_t S2_f4a_inv_T0[32][4][256];

// static void dump_hex(uint8_t * h, int len)
// {
//     while(len--)
//     {   
//         printf("%02hhx ",*h++);
//         if(len%16==0) printf("\n");
//     }
//     printf("\n");
// }
// #define u8 unsigned char
// #define u32 unsigned long
// wbsm4_se_cl_avx2_context *wbsm4_se_cl_avx2_context_init(int encmode) {
//     wbsm4_se_cl_avx2_context *ctx = malloc(sizeof(wbsm4_se_cl_avx2_context));
//     if (ctx == NULL) {
//         goto cleanup;
//     }
//     memset(ctx, 0, sizeof(wbsm4_se_cl_avx2_context));
//     ctx->encmode = encmode;
//     return ctx;
// cleanup:
//     return NULL;
// }

// void wbsm4_se_cl_avx2_context_free(wbsm4_se_cl_avx2_context *ctx) {
//     memset(ctx, 0, sizeof(wbsm4_se_cl_avx2_context));
// }
// //Generate S2 box and nonlinear transformation
// void gS_4_T(u8 S1_f4a[32][4][256], wbsm4_se_cl_avx2_context *ctx)
// {
// 	u8 S1_f4a_inv[32][4][256];
// 	u8 Sbox[256] = {
//    //0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
// 	0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05,//0
// 	0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99,//1
// 	0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62,//2
// 	0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6,//3
// 	0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8,//4
// 	0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35,//5
// 	0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87,//6
// 	0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e,//7
// 	0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1,//8
// 	0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3,//9
// 	0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f,//a
// 	0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51,//b
// 	0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8,//c
// 	0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0,//d
// 	0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84,//e
// 	0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48//f
// 	 };
// 	for (int i = 0; i < 32; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			ga(S1_f4a[i][j], S1_f4a_inv[i][j]);
// 			for (int k = 0; k < 256; k++)
// 			{
// 				S1_f4_T3[i][j][k] = (uint32_t)(S1_f4a[i][j][Sbox[k]]<<24);
// 				S1_f4_T2[i][j][k] = (uint32_t)(S1_f4a[i][j][Sbox[k]]<<16);
// 				S1_f4_T1[i][j][k] = (uint32_t)(S1_f4a[i][j][Sbox[k]]<<8);
// 				S1_f4_T0[i][j][k] = (uint32_t)(S1_f4a[i][j][Sbox[k]]);

// 				S1_f4a_inv_T3[i][j][k] = (uint32_t)(S1_f4a_inv[i][j][k]<<24);
// 				S1_f4a_inv_T2[i][j][k] = (uint32_t)(S1_f4a_inv[i][j][k]<<16);
// 				S1_f4a_inv_T1[i][j][k] = (uint32_t)(S1_f4a_inv[i][j][k]<<8);
// 				S1_f4a_inv_T0[i][j][k] = (uint32_t)(S1_f4a_inv[i][j][k]);
// 			}
// 		}
// 	}
// }



// //Generate S2 box and nonlinear transformation
// void gS2_4_T(u8 S2_f4a[32][4][256], wbsm4_se_cl_avx2_context *ctx)
// {
// 	u8 S2_f4a_inv[32][4][256];
// 	u8 Sbox[256] = {
// 	0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05,
// 	0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99,
// 	0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62,
// 	0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6,
// 	0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8,
// 	0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35,
// 	0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87,
// 	0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e,
// 	0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1,
// 	0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3,
// 	0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f,
// 	0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51,
// 	0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8,
// 	0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0,
// 	0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84,
// 	0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48
// 	 };

// 	u8 Sbox_inv[256];
// 	for (int i = 0; i < 256; i++)
// 	{
// 		Sbox_inv[Sbox[i]] = i;
// 	}
// 	for (int i = 0; i < 32; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			ga(S2_f4a[i][j], S2_f4a_inv[i][j]);
// 			for (int k = 0; k < 256; k++)
// 			{
// 				// S2_f4[i][j][k] = S2_f4a[i][j][Sbox_inv[k]];
// 				S2_f4_T3[i][j][k] = (uint32_t)(S2_f4a[i][j][Sbox_inv[k]]<<24);
// 				S2_f4_T2[i][j][k] = (uint32_t)(S2_f4a[i][j][Sbox_inv[k]]<<16);
// 				S2_f4_T1[i][j][k] = (uint32_t)(S2_f4a[i][j][Sbox_inv[k]]<<8);
// 				S2_f4_T0[i][j][k] = (uint32_t)(S2_f4a[i][j][Sbox_inv[k]]);

// 				S2_f4a_inv_T3[i][j][k] = (uint32_t)(S2_f4a_inv[i][j][k]<<24);
// 				S2_f4a_inv_T2[i][j][k] = (uint32_t)(S2_f4a_inv[i][j][k]<<16);
// 				S2_f4a_inv_T1[i][j][k] = (uint32_t)(S2_f4a_inv[i][j][k]<<8);
// 				S2_f4a_inv_T0[i][j][k] = (uint32_t)(S2_f4a_inv[i][j][k]);
// 			}
// 		}
// 	}

// }

// //[128,128] multiplied by [128,8] matrix operation
// void M128_128_8(u8 a[128][128], u8 b[128][8], u8 c[128][8])
// {
// 	for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 128; j++)
//         {
//             c[j][i] = 0;
//             for (int k = 0; k < 128; k++)
//             {
//                 c[j][i] = c[j][i] ^ (a[j][k] * b[k][i]);
//             }
//         }
//     }
      
// }


// void getTypeI_c_affine(u8 F8[16][8][8], u8 A_1[128][128], u8 A_1_b[128], u8 P[64][128][128], u8 P_b[65][17][128], Aff8 TypeI_c_AFF[16][16])
// {
	
// 	u8 I_cA[16][128][8];
// 	u8 A_1_b16[16][128];

//     u8 tmp128_8[128][8] = {0};
// 	u8 tmp128_8_1[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 15; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			A_1_b16[i][j] = rand() % 2;
// 		}
// 	}
// 	for (int i = 0; i < 128; i++)
// 	{
// 		A_1_b16[15][i] = A_1_b[i];
// 		for (int j = 0; j < 15; j++)
// 		{
// 			A_1_b16[15][i] = A_1_b16[15][i] ^ A_1_b16[j][i];
// 		}
// 	}
// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				I_cA[i][j][k] = A_1[j][i * 8 + k];
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	x[k] = (j >> (7-k))&1;
// 			// }
// 			// !这里改成F去乘A
// 			// M8_1(F8[i], x, SIF);
// 			// M128_1(I_cA[i], SIF, SIFA);
//             M128_8(I_cA[i],F8[i],tmp128_8);
                
            
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIFAk[k] = SIFA[k] ^ A_1_b16[i][k];
// 			// }
           
//             // M128_128(P[0], SIFAk, SIFAkP);
			
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = SIFAkP[k] ^ P_b[0][i][k];
// 			// }
		
// 			M128_128_8(P[0], tmp128_8, tmp128_8);
// 			M128_128(P[0], A_1_b16[i], tmp128);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ P_b[0][i][k];
// 			}

// 			// !在这里预计算查表，i表示输入的是16个明文字节的第几个，j表示查表的输入即明文字节的值，k表示输出的16个字节的index
// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeI_c[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
			
// 			// ! 将仿射矩阵转换为WBMatirx中的编码形式
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeI_c_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeI_c_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}

// 		// }
// 	}

// }

// void getTypeII_c_affine(u8 P_inv0[128][128], u8 P_b0[17][128], u8 STypeI_O0[128][128], u8 STypeI_O_b0[128],  Aff8 TypeII_c_AFF[16][16])
// {
// 	u8 II_cP[16][128][8];

// 	u8 tmp8[8] = {0};

// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				II_cP[i][j][k] = P_inv0[j][i * 8 + k];
// 			}
// 		}
// 	}
// 	for (int i = 0; i < 16; i++)
// 	{
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	x[k] = (j >> (7 - k)) & 1;
// 			// }

// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	SIIb[k] = x[k] ^ P_b0[16][i*8+k];
// 			// }

// 			// M128_1(II_cP[i], SIIb, SIIPb);
			
// 			// M128_128(STypeI_O0, SIIPb, SIIPbO);
// 			for (size_t j = 0; j < 8; j++)
// 			{
// 				tmp8[j] = P_b0[16][i*8+j];
// 			}
			
// 			M128_1(II_cP[i],tmp8,tmp128_1);
// 			M128_128_8(STypeI_O0, II_cP[i], tmp128_8);
// 			M128_1(STypeI_O0,tmp128_1,tmp128);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = SIIPbO[k] ^ STypeI_O_b0[k];
// 			// }
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ STypeI_O_b0[k];
// 			}
// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeII_c[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			// ! 将仿射矩阵转换为WBMatirx中的编码形式
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeII_c_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeII_c_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}
// 		// }
// 	}

// }


// //Generate TypeI_a lookup table
// void getTypeI_a_affine(u8 P1[128][128], u8 P_b1[17][128], u8 A_2[128][128], u8 A_2_b0[128], u8 STypeI_IP0[16][8][8], u8 STypeI_IP_b0[16][8],  Aff8 TypeI_a_AFF[16][16])
// {

// 	u8 I_aA[16][128][8];
// 	u8 A_2_b16[16][128];

// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128_8_1[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 15; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			A_2_b16[i][j] = rand()%2;
// 		}
// 	}
// 	for (int i = 0; i < 128; i++)
// 	{
// 		A_2_b16[15][i] = A_2_b0[i];
// 		for (int j = 0; j < 15; j++)
// 		{
// 			A_2_b16[15][i] = A_2_b16[j][i] ^ A_2_b16[15][i];
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				I_aA[i][j][k] = A_2[j][i * 8 + k];
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		// todo 把这个S盒的逆留着，移到加密中,放在TypeI_a之前，对前32bit的明文进行!!!
// 		// for (int j = 0; j < 256; j++)
// 		// {

// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	if (i < 4)
// 			// 		x[k] = (S1_f4a_inv1[i][j] >>( 7-k))&1;
// 			// 	else
// 			// 		x[k] = (j >> (7 - k)) & 1;
// 			// }
				
// 			// M8_1(STypeI_IP0[i], x, O);
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	 Ob[k] = O[k] ^ STypeI_IP_b0[i][k];
// 			// }
// 			M128_8(I_aA[i],STypeI_IP0[i],tmp128_8_1);
// 			M128_1(I_aA[i],STypeI_IP_b0[i],tmp128_1);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128_1[k] = tmp128_1[k] ^ A_2_b16[i][k];
// 			}

// 			// M128_1(I_aA[i], Ob, AOb);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	AObk[k] = AOb[k] ^ A_2_b16[i][k];
// 			// }
// 			// M128_128(P1, AObk, PAObk);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = PAObk[k] ^ P_b1[i][k];
// 			// }
// 			M128_128_8(P1, tmp128_8_1, tmp128_8);
// 			M128_128(P1, tmp128_1, tmp128);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ P_b1[i][k];
// 			}


// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeI_a0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeI_a_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeI_a_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}
			
// 		// }
// 	}
// }


// //Generate TypeII_a lookup table
// void getTypeII_a_affine(u8 P_inv1[128][128], u8 P_b1[17][128], u8 STypeII_O0[128][128], u8 STypeII_O_b0[128], Aff8 TypeII_a_AFF[16][16])
// {
	
// 	u8 II_aP[16][128][8];

// 	u8 tmp8[8] = {0};
// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128[128] = {0};
// 	u8 tmp128_1[128] = {0};
// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				II_aP[i][j][k] = P_inv1[j][i * 8 + k];
// 			}
// 		}
// 	}
// 	for (int i = 0; i < 16; i++)
// 	{
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	x[k] = (j >> (7 - k)) & 1;
// 			// }

// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	SIIb[k] = x[k] ^ P_b1[16][i * 8 + k];
// 			// }
			
// 			// M128_1(II_aP[i], SIIb, SIIPb);

// 			// M128_128(STypeII_O0, SIIPb, SIIPbO);
// 			for (size_t j = 0; j < 8; j++)
// 			{
// 				tmp8[j] = P_b1[16][i*8+j];
// 			}
			
// 			M128_1(II_aP[i],tmp8,tmp128_1);
// 			M128_128_8(STypeII_O0, II_aP[i], tmp128_8);
			
// 			M128_1(STypeII_O0,tmp128_1,tmp128);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = SIIPbO[k] ^ STypeII_O_b0[k];
// 			// }
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ STypeII_O_b0[k];
// 			}
// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeII_a0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeII_a_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeII_a_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}

// 		// }
// 	}





// }


// //Generate TypeI_b lookup table
// void getTypeI_b_affine(u8 P2[128][128], u8 P_b2[17][128], u8 A_13[128][128], u8 A_13_b0[128], u8 STypeII_IP0[16][8][8], u8 STypeII_IP_b0[16][8], Aff8 TypeI_b_AFF[16][16])
// {

// 	u8 II_aA[16][128][8];
// 	u8 A_13_b16[16][128];

// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128_8_1[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 15; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			A_13_b16[i][j] = rand() % 2;
// 		}
// 	}
// 	for (int i = 0; i < 128; i++)
// 	{
// 		A_13_b16[15][i] = A_13_b0[i];
// 		for (int j = 0; j < 15; j++)
// 		{
// 			A_13_b16[15][i] = A_13_b16[15][i] ^ A_13_b16[j][i];
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				II_aA[i][j][k] = A_13[j][i * 8 + k];
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		// todo 把这个S盒的逆留着，移到加密中,放在TyoeI_b之前，对前32bit的明文进行!!!
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	if (i < 4)
// 			// 		x[k] = (S2_f4a_inv1[i][j]  >>( 7-k))&1;
// 			// 	else
// 			// 		x[k] = (j >> (7 - k)) & 1;
// 			// }

// 			// M8_1(STypeII_IP0[i], x, O);
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	Ob[k] = O[k] ^ STypeII_IP_b0[i][k];
// 			// }
// 			M128_8(II_aA[i],STypeII_IP0[i],tmp128_8_1);
// 			M128_1(II_aA[i],STypeII_IP_b0[i],tmp128_1);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128_1[k] = tmp128_1[k] ^ A_13_b16[i][k];
// 			}

// 			// M128_1(II_aA[i], Ob, AOb);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	AObk[k] = AOb[k] ^ A_13_b16[i][k];
// 			// }
// 			// M128_128(P2, AObk, PAObk);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = PAObk[k] ^ P_b2[i][k];
// 			// }

// 			M128_128_8(P2, tmp128_8_1, tmp128_8);
// 			M128_128(P2, tmp128_1, tmp128);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ P_b2[i][k];
// 			}

// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeI_b0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeI_b_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeI_b_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}

// 		// }
// 	}

// }


// //Generate TypeII_b lookup table
// void getTypeII_b_affine(u8 P_inv2[128][128], u8 P_b2[17][128], u8 STypeI_O1[128][128], u8 STypeI_O_b1[128], Aff8 TypeII_b_AFF[16][16])
// {
// 	u8 II_aP[16][128][8];

// 	u8 tmp8[8] = {0};
// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				II_aP[i][j][k] = P_inv2[j][i * 8 + k];
// 			}
// 		}
// 	}
// 	for (int i = 0; i < 16; i++)
// 	{
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	x[k] = (j >> (7 - k)) & 1;
// 			// }

// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	SIIb[k] = x[k] ^ P_b2[16][i * 8 + k];
// 			// }
			
// 			// M128_1(II_aP[i], SIIb, SIIPb);

// 			// M128_128(STypeI_O1, SIIPb, SIIPbO);

// 			for (size_t j = 0; j < 8; j++)
// 			{
// 				tmp8[j] = P_b2[16][i*8+j];
// 			}
			
// 			M128_1(II_aP[i],tmp8,tmp128_1);

// 			M128_128_8(STypeI_O1, II_aP[i], tmp128_8);
			
// 			M128_1(STypeI_O1,tmp128_1,tmp128);

// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = SIIPbO[k] ^ STypeI_O_b1[k];
// 			// }
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128[k] = tmp128[k] ^ STypeI_O_b1[k];
// 			}
// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeII_b0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeII_b_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeII_b_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}
// 		// }
// 	}

// }


// //Generate TypeI_d lookup table
// void getTypeI_d_affine(u8 A_3[128][128], u8 A_3_b[128], u8 STypeII_IP31[16][8][8], u8 STypeII_IP_b31[16][8], Aff8 TypeI_d_AFF[16][16], u8 G128[128][128])
// {
// 	u8 x[8];
// 	u8 O[8];
// 	u8 Ob[8];
// 	u8 AOb[128];
// 	u8 AObk[128];
// 	u8 GAObk[128];
// 	u8 G[16][8];
// 	u8 GA[16][8];
// 	u8 SIr[128];
// 	u8 II_aA[16][128][8];
// 	u8 A_3_b16[16][128];

// 	u8 tmp128_8[128][8] = {0};
// 	u8 tmp128_8_1[128][8] = {0};
// 	u8 tmp128[128] = {0}; 
// 	u8 tmp128_1[128] = {0}; 

// 	for (int i = 0; i < 128; i++)
// 	{
// 		for (int j = 0; j < 15; j++)
// 		{
// 			A_3_b16[j][i] = rand() % 2;
// 		}
// 	}
// 	for (int i = 0; i < 128; i++)
// 	{
// 		A_3_b16[15][i] = A_3_b[i];
// 		for (int j = 0; j < 15; j++)
// 		{
// 			A_3_b16[15][i] = A_3_b16[j][i]^A_3_b16[15][i];
// 		}
// 	}
// 	for (int i = 0; i < 16; i++)
// 	{
// 		for (int j = 0; j < 128; j++)
// 		{
// 			for (int k = 0; k < 8; k++)
// 			{
// 				II_aA[i][j][k] = A_3[j][i * 8 + k];
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 16; i++)
// 	{
// 		// todo 把这个S盒的逆留着，移到加密中,放在TyoeI_d之前，对前32bit的明文进行!!!
// 		// for (int j = 0; j < 256; j++)
// 		// {
// 		// 	for (int k = 0; k < 8; k++)
// 		// 	{
// 		// 		if (i < 4)
// 		// 			x[k] = (S2_l4a_inv31[i][j]  >> (7-k))&1;
// 		// 		else
// 		// 			x[k] = (j >> (7 - k)) & 1;
// 		// 	}

// 			// M8_1(STypeII_IP31[i], x, O);
// 			// for (int k = 0; k < 8; k++)
// 			// {
// 			// 	Ob[k] = O[k] ^ STypeII_IP_b31[i][k];
// 			// }
			
// 			M128_8(II_aA[i],STypeII_IP31[i],tmp128_8_1);
// 			M128_1(II_aA[i],STypeII_IP_b31[i],tmp128_1);
// 			for (int k = 0; k < 128; k++)
// 			{
// 				tmp128_1[k] = tmp128_1[k] ^ A_3_b16[i][k];
// 			}

// 			// M128_1(II_aA[i], Ob, AOb);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	AObk[k] = AOb[k] ^ A_3_b16[i][k];
// 			// }
// 			// M128_128(G128, AObk, GAObk);
// 			// for (int k = 0; k < 128; k++)
// 			// {
// 			// 	SIr[k] = GAObk[k] ;
// 			// }

// 			M128_128_8(G128, tmp128_8_1, tmp128_8);
// 			M128_128(G128, tmp128_1, tmp128);
		


// 			// for (int k = 0; k < 16; k++)
// 			// {
// 			// 	TypeI_d[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
// 			// }
// 			for (int k = 0; k < 16; k++)
// 			{
// 				for (int l = 0; l < 8; l++)
// 				{
// 					TypeI_d_AFF[i][k].Mat.M[l] = tmp128_8[k * 8 + l][0] * 128 + tmp128_8[k * 8 + l][1] * 64 + tmp128_8[k * 8 + l][2] * 32 + tmp128_8[k * 8 + l][3] * 16 + tmp128_8[k * 8 + l][4] * 8 + tmp128_8[k * 8 + l][5] * 4 + tmp128_8[k * 8 + l][6] * 2 + tmp128_8[k * 8 + l][7];
// 				}
// 			}
// 			for (int k = 0; k < 16; k++)
// 			{
// 				TypeI_d_AFF[i][k].Vec.V = tmp128[k * 8 + 0] * 128 + tmp128[k * 8 + 1] * 64 + tmp128[k * 8 + 2] * 32 + tmp128[k * 8 + 3] * 16 + tmp128[k * 8 + 4] * 8 + tmp128[k * 8 + 5] * 4 + tmp128[k * 8 + 6] * 2 + tmp128[k * 8 + 7];
// 			}
// 		// }
// 	}

// }

// void MatrixdivM8to4(M8 mat8, M4 m4[2][2])
// {
//     for (size_t i = 0; i < 2; i++)
//     {
//         // printf("111-\n");
// 		m4[i][0].M[0] = (mat8.M[i * 4 + 0] & 0xf0) >> 4;
// 		m4[i][0].M[1] = (mat8.M[i * 4 + 1] & 0xf0) >> 4;
// 		m4[i][0].M[2] = (mat8.M[i * 4 + 2] & 0xf0) >> 4;
// 		m4[i][0].M[3] = (mat8.M[i * 4 + 3] & 0xf0) >> 4;

// 		m4[i][1].M[0] = mat8.M[i * 4 + 0] & 0x0f;
// 		m4[i][1].M[1] = mat8.M[i * 4 + 1] & 0x0f;
// 		m4[i][1].M[2] = mat8.M[i * 4 + 2] & 0x0f;
// 		m4[i][1].M[3] = mat8.M[i * 4 + 3] & 0x0f;
        
//     }
    
// }

// uint8_t GetMatMulVecM4(M4 Mat, uint8_t Vec){
//     V4 ret, tmp;
//     tmp.V = Vec;
//     MatMulVecM4(Mat, tmp, &ret);
//     return ret.V;
// }

// void GEN_TABLE_DATA_F4(M4 TMP[16][2][2], uint8_t index, uint8_t data[16][16]) {
// 	for (size_t i = 0; i < 16; i++)
// 	{
// 		data[i][index] = (GetMatMulVecM4(TMP[i][0][0], index) << 4) + GetMatMulVecM4(TMP[i][1][0], index);
// 	}
// }
// void GEN_TABLE_DATA_E4(M4 TMP[16][2][2], uint8_t index, uint8_t data[16][16]) {
//     //后 4bit
//     for (size_t i = 0; i < 16; i++)
// 	{
// 		data[i][index] = (GetMatMulVecM4(TMP[i][0][1], index) << 4) + GetMatMulVecM4(TMP[i][1][1], index);
// 	}
// }

// void AFFINE_ENCODING(__m256i IN[16], __m256i OUT[16], uint8_t table_f4[16][16][16], uint8_t table_e4[16][16][16], uint8_t table_vec[16][16]) {
//         __m256i input_f4[16], input_e4[16];
// 		// ! 先用个test_out，后面再检查具体是哪里不行
// 		// __m256i test_out[16];
//         __m256i tmp_f4,tmp_e4;
//         __m128i tmp_128_mat;// 表的大小只有128
//         __m256i tmp_mat;
//         __m256i tmp_vec;
//         __m256i mask[2];
//         uint64_t m[2][4] = {
//             {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
//             {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
//         };
//         mask[0] = _mm256_loadu_si256((__m256i *)m[0]);
//         mask[1] = _mm256_loadu_si256((__m256i *)m[1]);
	
//         for (size_t i = 0; i < 16; i++)//从明文中取4bit
//         {
//             input_f4[i] = _mm256_and_si256(mask[0],IN[i]);
//             input_f4[i] = _mm256_srli_epi32(input_f4[i],4);
//             input_e4[i] = _mm256_and_si256(mask[1],IN[i]);
//         }
        
// 		// 16个字节明文循环
//         for (size_t i = 0; i < 16; i++)
//         {
// 			// 每个8bit的结果需要所有16个明文的相同位置输出结果异或 
// 			// 明文过8-128bit的输出
// 			// test_out[i] = _mm256_setzero_si256(); 
//             for (size_t j = 0; j < 16; j++)
// 			{
// 				tmp_128_mat = _mm_loadu_si128(table_f4[j][i]);
// 				tmp_mat = _mm256_setr_m128i(tmp_128_mat, tmp_128_mat);
// 				tmp_f4 = _mm256_shuffle_epi8(tmp_mat, input_f4[i]);// 4-8查表

// 				tmp_128_mat = _mm_loadu_si128(table_e4[j][i]);
// 				tmp_mat = _mm256_setr_m128i(tmp_128_mat, tmp_128_mat);
// 				tmp_e4 = _mm256_shuffle_epi8(tmp_mat, input_e4[i]);// 4-8查表

// 				OUT[i] = OUT[i] ^ tmp_e4 ^ tmp_f4;
// 			}
			
//         }
     
//         for (size_t i = 0; i < 16; i++)
//         {
// 			for (size_t j = 0; j < 16; j++){
// 				tmp_vec = _mm256_set1_epi8(table_vec[j][i]);
//            		OUT[i] = OUT[i] ^ tmp_vec;
// 			}
//         }
//         // dump_hex(OUT,16);
	
// }

// void DATA_PACK( __m256i OUT[16]){
//     // printf("\npack input:\n");
//     // dump_hex(OUT,512);
//     __m256i state[16];
//     for(int i=0;i<8;i++){
//             state[i] = _mm256_unpacklo_epi8(OUT[2*i],OUT[2*i+1]);
//             state[i+8] = _mm256_unpackhi_epi8(OUT[2*i],OUT[2*i+1]);
//         }
//         // printf("\nOUT-after:\n");
//         // dump_hex(state,256);
//         OUT[0] = _mm256_unpacklo_epi16(state[0],state[1]);
//         OUT[1] = _mm256_unpacklo_epi16(state[2],state[3]);
//         OUT[2] = _mm256_unpacklo_epi16(state[4],state[5]);
//         OUT[3] = _mm256_unpacklo_epi16(state[6],state[7]);

//         OUT[4] = _mm256_unpackhi_epi16(state[0],state[1]);
//         OUT[5] = _mm256_unpackhi_epi16(state[2],state[3]);
//         OUT[6] = _mm256_unpackhi_epi16(state[4],state[5]);
//         OUT[7] = _mm256_unpackhi_epi16(state[6],state[7]);
//         // printf("\nOUT(对lo进行操作):\n");
//         // dump_hex(OUT,128);  

//         OUT[8] = _mm256_unpacklo_epi16(state[8],state[9]);
//         OUT[9] = _mm256_unpacklo_epi16(state[10],state[11]);
//         OUT[10] = _mm256_unpacklo_epi16(state[12],state[13]);
//         OUT[11] = _mm256_unpacklo_epi16(state[14],state[15]);

//         OUT[12] = _mm256_unpackhi_epi16(state[8],state[9]);
//         OUT[13] = _mm256_unpackhi_epi16(state[10],state[11]);
//         OUT[14] = _mm256_unpackhi_epi16(state[12],state[13]);
//         OUT[15] = _mm256_unpackhi_epi16(state[14],state[15]);  
//         // printf("\nOUT(对hi进行操作):\n");
//         // dump_hex(OUT+8,128);  


//         state[0] = _mm256_unpacklo_epi32(OUT[0],OUT[1]);//0-1
//         state[1] = _mm256_unpacklo_epi32(OUT[2],OUT[3]);
//         state[2] = _mm256_unpacklo_epi32(OUT[4],OUT[5]);//4-5
//         state[3] = _mm256_unpacklo_epi32(OUT[6],OUT[7]);
        
//         state[4] = _mm256_unpackhi_epi32(OUT[0],OUT[1]);//2-3
//         state[5] = _mm256_unpackhi_epi32(OUT[2],OUT[3]);
//         state[6] = _mm256_unpackhi_epi32(OUT[4],OUT[5]);//6-7
//         state[7] = _mm256_unpackhi_epi32(OUT[6],OUT[7]);
//         // printf("\nstate:\n");
//         // dump_hex(state,128); 

//         state[8] = _mm256_unpacklo_epi32(OUT[8],OUT[9]);//0-1
//         state[9] = _mm256_unpacklo_epi32(OUT[10],OUT[11]);
//         state[10] = _mm256_unpacklo_epi32(OUT[12],OUT[13]);//4-5
//         state[11] = _mm256_unpacklo_epi32(OUT[14],OUT[15]);
        
//         state[12] = _mm256_unpackhi_epi32(OUT[8],OUT[9]);//2-3
//         state[13] = _mm256_unpackhi_epi32(OUT[10],OUT[11]);
//         state[14] = _mm256_unpackhi_epi32(OUT[12],OUT[13]);//6-7
//         state[15] = _mm256_unpackhi_epi32(OUT[14],OUT[15]);
//         // printf("\nstate:\n");
//         // dump_hex(state+8,128);  
        
//         OUT[0] = _mm256_unpacklo_epi64(state[0],state[1]);
//         OUT[1] = _mm256_unpackhi_epi64(state[0],state[1]);

//         OUT[2] = _mm256_unpacklo_epi64(state[4],state[5]);
//         OUT[3] = _mm256_unpackhi_epi64(state[4],state[5]);

//         OUT[4] = _mm256_unpacklo_epi64(state[2],state[3]);
//         OUT[5] = _mm256_unpackhi_epi64(state[2],state[3]);

//         OUT[6] = _mm256_unpacklo_epi64(state[6],state[7]);
//         OUT[7] = _mm256_unpackhi_epi64(state[6],state[7]);


//         OUT[8] = _mm256_unpacklo_epi64(state[8],state[9]);
//         OUT[9] = _mm256_unpackhi_epi64(state[8],state[9]);

//         OUT[10] = _mm256_unpacklo_epi64(state[12],state[13]);
//         OUT[11] = _mm256_unpackhi_epi64(state[12],state[13]);

//         OUT[12] = _mm256_unpacklo_epi64(state[10],state[11]);
//         OUT[13] = _mm256_unpackhi_epi64(state[10],state[11]);

//         OUT[14] = _mm256_unpacklo_epi64(state[14],state[15]);
//         OUT[15] = _mm256_unpackhi_epi64(state[14],state[15]);
// //         printf("\npack output:\n");
// //         dump_hex(OUT,512);
// }

// int wbsm4_se_cl_avx2_gen_table(wbsm4_se_cl_avx2_context *ctx, const unsigned char *key) {
	
//     sm4_context *sm4_key = sm4_context_init();
//     if (ctx->encmode) {
//         sm4_setkey_enc(sm4_key, key);
//     } else {
//         sm4_setkey_dec(sm4_key, key);
//     }
//     u8 P[64][128][128];
// 	u8 P_b[65][17][128];
// 	u8 P_inv[64][128][128];
// 	u8 F[128][128];
// 	u8 G[128][128];

// 	u8 A_1[128][128];
// 	u8 A_2[128][128];
// 	u8 A_3[128][128];
// 	u8 A_13[128][128];
// 	u8 A_1_b[128];
// 	u8 A_2_b[32][128];
// 	u8 A_3_b[128];
// 	u8 A_13_b[31][128];

// 	u8 STypeI_O[32][128][128];
// 	u8 STypeI_O_b[32][128];
// 	u8 STypeI_I[32][128][128];
// 	u8 STypeI_I_b[32][128];
// 	u8 STypeII_O[32][128][128];
// 	u8 STypeII_O_b[32][128];
// 	u8 STypeII_I[32][128][128];
// 	u8 STypeII_I_b[32][128];

//     //Coding auxiliary variables
// 	u8 F8[16][8][8];
// 	u8 G8[16][8][8];
// 	u8 STypeI_OP[32][16][8][8];
// 	u8 STypeI_OP_b[32][16][8];
// 	u8 STypeI_IP[32][16][8][8];
// 	u8 STypeI_IP_b[32][16][8];
// 	u8 STypeII_OP[32][16][8][8];
// 	u8 STypeII_OP_b[32][16][8];
// 	u8 STypeII_IP[32][16][8][8];
// 	u8 STypeII_IP_b[32][16][8];
// 	u8 S1_f4a[32][4][256];
// 	u8 S2_f4a[32][4][256];
	
	
// 	Aff8 TypeI_c_AFF[16][16];
// 	Aff8 TypeII_c_AFF[16][16];
// 	Aff8 TypeI_a_AFF[32][16][16];
// 	Aff8 TypeII_a_AFF[32][16][16];
// 	Aff8 TypeI_b_AFF[31][16][16];
// 	Aff8 TypeII_b_AFF[31][16][16];
// 	Aff8 TypeI_d_AFF[16][16];

//     getP128(P, P_inv,G);
	
//     getP_b(P_b);
	
//     //! with external code
//     getP8w(F8, STypeI_OP, STypeI_OP, STypeII_OP, STypeII_IP);
	
//     generateOI(STypeI_OP, STypeI_IP, STypeII_OP, STypeII_IP, STypeI_OP_b, STypeI_IP_b, STypeII_OP_b, STypeII_IP_b);
// 	getA(A_1, A_2, A_3, A_13);
// 	getA_b(sm4_key->sk, A_1_b, A_2_b, A_3_b, A_13_b);

// 	gOI128(STypeI_OP, STypeI_OP_b, STypeI_O, STypeI_O_b);
// 	gOI128(STypeI_IP, STypeI_IP_b, STypeI_I, STypeI_I_b);
// 	gOI128(STypeII_OP, STypeII_OP_b, STypeII_O, STypeII_O_b);
// 	gOI128(STypeII_IP, STypeII_IP_b, STypeII_I, STypeII_I_b);
	
// 	gS_4_T(S1_f4a, ctx);
// 	gS2_4_T(S2_f4a, ctx);
//     getTypeI_c_affine(F8, A_1, A_1_b, P, P_b, TypeI_c_AFF);
// 	getTypeII_c_affine(P_inv[0], P_b[0], STypeI_O[0], STypeI_O_b[0], TypeII_c_AFF);

// 	for (int i = 0; i < 31; i++)
// 	{
// 		getTypeI_a_affine(P[i * 2 + 1], P_b[i * 2 + 1], A_2, A_2_b[i], STypeI_IP[i], STypeI_IP_b[i], TypeI_a_AFF[i]);
// 		getTypeII_a_affine(P_inv[i * 2 + 1], P_b[i * 2 + 1], STypeII_O[i], STypeII_O_b[i], TypeII_a_AFF[i]);
// 		getTypeI_b_affine(P[i * 2 + 2], P_b[i * 2 + 2], A_13, A_13_b[i], STypeII_IP[i], STypeII_IP_b[i], TypeI_b_AFF[i]);
// 		getTypeII_b_affine(P_inv[i * 2 + 2], P_b[i * 2 + 2], STypeI_O[i + 1], STypeI_O_b[i + 1], TypeII_b_AFF[i]);
// 	}
	
// 	getTypeI_a_affine(P[63], P_b[63], A_2, A_2_b[31], STypeI_IP[31], STypeI_IP_b[31], TypeI_a_AFF[31]);
// 	getTypeII_a_affine(P_inv[63], P_b[63], STypeII_O[31], STypeII_O_b[31], TypeII_a_AFF[31]);
// 	getTypeI_d_affine(A_3, A_3_b, STypeII_IP[31], STypeII_IP_b[31], TypeI_d_AFF, G);


// 	for (size_t i = 0; i < 16; i++)
// 	{
// 		M4 TMP_TypeI_c[16][2][2];
// 		M4 TMP_TypeII_c[16][2][2];
// 		M4 TMP_TypeI_d[16][2][2];
	
// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			MatrixdivM8to4(TypeI_c_AFF[i][j].Mat,TMP_TypeI_c[j]);
// 			MatrixdivM8to4(TypeII_c_AFF[i][j].Mat,TMP_TypeII_c[j]);
// 			MatrixdivM8to4(TypeI_d_AFF[i][j].Mat,TMP_TypeI_d[j]);
// 		}
		
// 		// for (size_t j = 0; j < 16; j++)
// 		// {
// 		// 	ctx->TypeI_c_V[i][j] = TypeI_c_AFF[i][j].Vec.V;
// 		// 	ctx->TypeII_c_V[i][j] = TypeII_c_AFF[i][j].Vec.V;
// 		// 	ctx->TypeI_d_V[i][j] = TypeI_d_AFF[i][j].Vec.V;
// 		// }
		
// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			GEN_TABLE_DATA_F4(TMP_TypeI_c,j,ctx->TypeI_c_M_F4[i]);
// 			GEN_TABLE_DATA_E4(TMP_TypeI_c,j,ctx->TypeI_c_M_E4[i]);

// 			// GEN_TABLE_DATA_F4(TMP_TypeII_c,j,ctx->TypeII_c_M_F4[i]);
// 			// GEN_TABLE_DATA_E4(TMP_TypeII_c,j,ctx->TypeII_c_M_E4[i]);

// 			// GEN_TABLE_DATA_F4(TMP_TypeI_d,j,ctx->TypeI_d_M_F4[i]);
// 			// GEN_TABLE_DATA_E4(TMP_TypeI_d,j,ctx->TypeI_d_M_E4[i]);
// 		}
	
		
// 	}	
	
// 	for (size_t i = 0; i < 32; i++)
// 	{
// 		M4 TMP_TypeI_a[16][16][2][2];
// 		M4 TMP_TypeII_a[16][16][2][2];
// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			for (size_t k = 0; k < 16; k++)
// 			{
// 				MatrixdivM8to4(TypeI_a_AFF[i][j][k].Mat,TMP_TypeI_a[j][k]);
// 				MatrixdivM8to4(TypeII_a_AFF[i][j][k].Mat,TMP_TypeII_a[j][k]);
// 				// ctx->TypeI_a_V[i][j][k] = TypeI_a_AFF[i][j][k].Vec.V;
// 				// ctx->TypeII_a_V[i][j][k] = TypeII_a_AFF[i][j][k].Vec.V;
// 			}
			
// 		}

// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			for (size_t k = 0; k < 16; k++)
// 			{
// 				// GEN_TABLE_DATA_F4(TMP_TypeI_a[j],k,ctx->TypeI_a_M_F4[i][j]);
// 				// GEN_TABLE_DATA_E4(TMP_TypeI_a[j],k,ctx->TypeI_a_M_E4[i][j]);

// 				// GEN_TABLE_DATA_F4(TMP_TypeII_a[j],k,ctx->TypeII_a_M_F4[i][j]);
// 				// GEN_TABLE_DATA_E4(TMP_TypeII_a[j],k,ctx->TypeII_a_M_E4[i][j]);
// 			}
			
// 		}
// 	}
		
// 	for (size_t i = 0; i < 31; i++)
// 	{
// 		M4 TMP_TypeI_b[16][16][2][2];
// 		M4 TMP_TypeII_b[16][16][2][2];
// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			for (size_t k = 0; k < 16; k++)
// 			{
// 				MatrixdivM8to4(TypeI_b_AFF[i][j][k].Mat,TMP_TypeI_b[j][k]);
// 				MatrixdivM8to4(TypeII_b_AFF[i][j][k].Mat,TMP_TypeII_b[j][k]);
// 				// ctx->TypeI_b_V[i][j][k] = TypeI_b_AFF[i][j][k].Vec.V;
// 				// ctx->TypeII_b_V[i][j][k] = TypeII_b_AFF[i][j][k].Vec.V;
// 			}
			
// 		}
	
// 		for (size_t j = 0; j < 16; j++)
// 		{
// 			for (size_t k = 0; k < 16; k++)
// 			{
// 				// GEN_TABLE_DATA_F4(TMP_TypeI_b[j],k,ctx->TypeI_b_M_F4[i][j]);
// 				// GEN_TABLE_DATA_E4(TMP_TypeI_b[j],k,ctx->TypeI_b_M_E4[i][j]);

// 				// GEN_TABLE_DATA_F4(TMP_TypeII_b[j],k,ctx->TypeII_b_M_F4[i][j]);
// 				// GEN_TABLE_DATA_E4(TMP_TypeII_b[j],k,ctx->TypeII_b_M_E4[i][j]);
// 			}
			
// 		}
// 	}	
				

		
// 		return 1;
// }



// int wbsm4_se_cl_avx2_encrypt(const uint8_t IN[512], uint8_t OUT[512], wbsm4_se_cl_avx2_context *ctx) {
   
//     // u8 states[16];
// 	// u8 state16[16][16];
// 	// u8 state128[16][128];
// 	// u8 states128[128];

// 	__m256i state1[16];
// 	__m256i state2[16];
// 	__m256i mask;

// 	mask = _mm256_set1_epi32(0xFF);
// 	memcpy(state1, IN, 512);
// 	DATA_PACK(state1);
//     // for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		state16[i][j] = ctx->TypeI_c[i][input[i]][j];
// 	// 	}
// 	// }
	
// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		for (int k = 0; k < 8; k++)
// 	// 		{
// 	// 			state128[i][j * 8 + k] = (state16[i][j] >> (7 - k)) & 1;
// 	// 		}
// 	// 	}
// 	// }



// 	// for (int i = 0; i < 128; i++)
// 	// {
// 	// 	states128[i] = 0;
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		states128[i] = states128[i] ^ state128[j][i];
// 	// 	}
// 	// }

// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	states[i] = states128[i * 8 + 0] * 128 + states128[i * 8 + 1] * 64 + states128[i * 8 + 2] * 32 + states128[i * 8 + 3] * 16 + states128[i * 8 + 4] * 8 + states128[i * 8 + 5] * 4 + states128[i * 8 + 6] * 2 + states128[i * 8 + 7];

// 	// }
	
// 	AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 	//TypeII_C
// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		state16[i][j] = ctx->TypeII_c[i][states[i]][j];
// 	// 	}
// 	// }

// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		for (int k = 0; k < 8; k++)
// 	// 		{
// 	// 			state128[i][j * 8 + k] = (state16[i][j] >> (7 - k)) & 1;
// 	// 		}
// 	// 	}
// 	// }

// 	// for (int i = 0; i < 128; i++)
// 	// {
// 	// 	states128[i] = 0;
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		states128[i] = states128[i] ^ state128[j][i];
// 	// 	}
// 	// }

// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	states[i] = states128[i * 8 + 0] * 128 + states128[i * 8 + 1] * 64 + states128[i * 8 + 2] * 32 + states128[i * 8 + 3] * 16 + states128[i * 8 + 4] * 8 + states128[i * 8 + 5] * 4 + states128[i * 8 + 6] * 2 + states128[i * 8 + 7];

// 	// }
	
// 	// AFFINE_ENCODING(state1, state2, ctx->TypeII_c_M_F4, ctx->TypeII_c_M_E4, ctx->TypeII_c_V);
// 	AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 	// TODO 查表
// 	// for (int i = 0; i < 4; i++)
// 	// {

// 	// 	states[i] = ctx->S1_f4[0][i][states[i]];

// 	// }
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		state2[i] = _mm256_i32gather_epi32((const int*)S1_f4_T0[0][i], _mm256_and_si256(mask, state2[i]), 4)
//                     ^ _mm256_i32gather_epi32((const int*)S1_f4_T1[0][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
//                     ^ _mm256_i32gather_epi32((const int*)S1_f4_T2[0][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
//                     ^ _mm256_i32gather_epi32((const int*)S1_f4_T3[0][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 	}

// 	//31 rounds of table lookup
// 	for (int i = 0; i < 31; i++)
// 	{

// 		//TypeI_a
// 		// for (int j = 0; j < 16; j++)
// 		// {
// 		// 	for (int k = 0; k < 16; k++)
// 		// 	{
// 		// 		state16[j][k] = ctx->TypeI_a[i][j][states[j]][k];
// 		// 	}
// 		// }

// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		for (int k = 0; k < 8; k++)
// 		// 		{
// 		// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 		// 		}
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 128; i1++)
// 		// {
// 		// 	states128[i1] = 0;
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 		// }

// 		for (size_t j = 0; j < 4; j++)
// 		{
// 			state2[i] = _mm256_i32gather_epi32((const int*)S1_f4a_inv_T0[i][j], _mm256_and_si256(mask, state2[i]), 4)
// 						^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T1[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 						^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T2[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 						^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T3[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 		}

// 		// AFFINE_ENCODING(state2, state1, ctx->TypeI_a_M_F4[i], ctx->TypeI_a_M_E4[i], ctx->TypeI_a_V[i]);
// 		AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);

// 		//TypeII_a
// 		// for (int j = 0; j < 16; j++)
// 		// {
// 		// 	for (int k = 0; k < 16; k++)
// 		// 	{
// 		// 		state16[j][k] = ctx->TypeII_a[i][j][states[j]][k];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		for (int k = 0; k < 8; k++)
// 		// 		{
// 		// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 		// 		}
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 128; i1++)
// 		// {
// 		// 	states128[i1] = 0;
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 		// }
// 		// AFFINE_ENCODING(state1, state2, ctx->TypeII_a_M_F4[i], ctx->TypeII_a_M_E4[i], ctx->TypeII_a_V[i]);
// 		AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 		// TODO 查表
// 		//S2
// 		// for (int j = 0; j < 4; j++)
// 		// {

// 		// 	states[j] = ctx->S2_f4[i][j][states[j]];

// 		// }
// 		for (size_t j = 0; j < 4; j++)
// 		{
// 			state2[i] = _mm256_i32gather_epi32((const int*)S2_f4_T0[i][j], _mm256_and_si256(mask, state2[i]), 4)
// 						^ _mm256_i32gather_epi32((const int*)S2_f4_T1[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 						^ _mm256_i32gather_epi32((const int*)S2_f4_T2[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 						^ _mm256_i32gather_epi32((const int*)S2_f4_T3[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 		}
	
		

// 		//TypeI_b
// 		// for (int j = 0; j < 16; j++)
// 		// {
// 		// 	for (int k = 0; k < 16; k++)
// 		// 	{
// 		// 		state16[j][k] = ctx->TypeI_b[i][j][states[j]][k];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		for (int k = 0; k < 8; k++)
// 		// 		{
// 		// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 		// 		}
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 128; i1++)
// 		// {
// 		// 	states128[i1] = 0;
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 		// }

// 		for (size_t j = 0; j < 4; j++)
// 		{
// 			state2[i] = _mm256_i32gather_epi32((const int*)S2_f4a_inv_T0[i][j], _mm256_and_si256(mask, state2[i]), 4)
// 						^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T1[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 						^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T2[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 						^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T3[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 		}
// 		// AFFINE_ENCODING(state2, state1, ctx->TypeI_b_M_F4[i], ctx->TypeI_b_M_E4[i], ctx->TypeI_b_V[i]);
// 		AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 		//TypeII_b
// 		// for (int j = 0; j < 16; j++)
// 		// {
// 		// 	for (int k = 0; k < 16; k++)
// 		// 	{
// 		// 		state16[j][k] = ctx->TypeII_b[i][j][states[j]][k];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		for (int k = 0; k < 8; k++)
// 		// 		{
// 		// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 		// 		}
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 128; i1++)
// 		// {
// 		// 	states128[i1] = 0;
// 		// 	for (int j = 0; j < 16; j++)
// 		// 	{
// 		// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 		// 	}
// 		// }
// 		// for (int i1 = 0; i1 < 16; i1++)
// 		// {
// 		// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 		// }
// 		// AFFINE_ENCODING(state1, state2, ctx->TypeII_b_M_F4[i], ctx->TypeII_b_M_E4[i], ctx->TypeII_b_V[i]);
// 		AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 		// TODO 查表
// 		//S1
// 		// for (int j = 0; j < 4; j++)
// 		// {
// 		// 	states[j] = ctx->S1_f4[i + 1][j][states[j]];
// 		// }
// 		for (size_t j = 0; j < 4; j++)
// 		{
// 			state2[i] = _mm256_i32gather_epi32((const int*)S1_f4_T0[i][j], _mm256_and_si256(mask, state2[i]), 4)
// 						^ _mm256_i32gather_epi32((const int*)S1_f4_T1[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 						^ _mm256_i32gather_epi32((const int*)S1_f4_T2[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 						^ _mm256_i32gather_epi32((const int*)S1_f4_T3[i][j], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 		}

// 	}
	

// 	//TypeI_a
// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		state16[i][j] = ctx->TypeI_a[31][i][states[i]][j];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		for (int k = 0; k < 8; k++)
// 	// 		{
// 	// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 	// 		}
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 128; i1++)
// 	// {
// 	// 	states128[i1] = 0;
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 	// }
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		state2[i] = _mm256_i32gather_epi32((const int*)S1_f4a_inv_T0[31][i], _mm256_and_si256(mask, state2[i]), 4)
// 					^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T1[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 					^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T2[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 					^ _mm256_i32gather_epi32((const int*)S1_f4a_inv_T3[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 	}
// 	// AFFINE_ENCODING(state2, state1, ctx->TypeI_a_M_F4[31], ctx->TypeI_a_M_E4[31], ctx->TypeI_a_V[31]);
// 	AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 	//TypeII_a
// 	// for (int j = 0; j < 16; j++)
// 	// {
// 	// 	for (int k = 0; k < 16; k++)
// 	// 	{
// 	// 		state16[j][k] = ctx->TypeII_a[31][j][states[j]][k];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		for (int k = 0; k < 8; k++)
// 	// 		{
// 	// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 	// 		}
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 128; i1++)
// 	// {
// 	// 	states128[i1] = 0;
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 	// }
	
// 	// AFFINE_ENCODING(state1, state2, ctx->TypeII_a_M_F4[31], ctx->TypeII_a_M_E4[31], ctx->TypeII_a_V[31]);
// 	AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 	// TODO 查表
// 	//S2
// 	// for (int i = 0; i < 4; i++)
// 	// {

// 	// 	states[i] = ctx->S2_f4[31][i][states[i]];

// 	// }
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		state2[i] = _mm256_i32gather_epi32((const int*)S2_f4_T0[31][i], _mm256_and_si256(mask, state2[i]), 4)
//                     ^ _mm256_i32gather_epi32((const int*)S2_f4_T1[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
//                     ^ _mm256_i32gather_epi32((const int*)S2_f4_T2[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
//                     ^ _mm256_i32gather_epi32((const int*)S2_f4_T3[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 	}

// 	//TypeI_d
// 	// for (int i = 0; i < 16; i++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		state16[i][j] = ctx->TypeI_d[i][states[i]][j];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		for (int k = 0; k < 8; k++)
// 	// 		{
// 	// 			state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
// 	// 		}
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 128; i1++)
// 	// {
// 	// 	states128[i1] = 0;
// 	// 	for (int j = 0; j < 16; j++)
// 	// 	{
// 	// 		states128[i1] = states128[i1] ^ state128[j][i1];
// 	// 	}
// 	// }
// 	// for (int i1 = 0; i1 < 16; i1++)
// 	// {
// 	// 	states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

// 	// }
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		state2[i] = _mm256_i32gather_epi32((const int*)S2_f4a_inv_T0[31][i], _mm256_and_si256(mask, state2[i]), 4)
// 					^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T1[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 8)), 4)
// 					^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T2[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 16)), 4) 
// 					^ _mm256_i32gather_epi32((const int*)S2_f4a_inv_T3[31][i], _mm256_and_si256(mask, _mm256_srli_epi32(state2[i], 24)), 4);
// 	}
// 	// AFFINE_ENCODING(state2, state1, ctx->TypeI_d_M_F4, ctx->TypeI_d_M_E4, ctx->TypeI_d_V);
// 	AFFINE_ENCODING(state1, state1, ctx->TypeI_c_M_F4, ctx->TypeI_c_M_E4, ctx->TypeI_c_V);
// 	//Reverse
// 	// for (int i = 0; i < 4; i++)
// 	// {
// 	// 	output[i] = states[i + 12];
// 	// 	output[i + 4] = states[i + 8];
// 	// 	output[i + 8] = states[i + 4];
// 	// 	output[i + 12] = states[i];
// 	// }
// 	DATA_PACK(state1);
// 	for (size_t i = 0; i < 16; i++)
// 	{
// 		state1[i] = _mm256_shuffle_epi32(state1[i],27);// 27 = 0b00011011 即反序变换
// 	}
// 	memcpy(OUT,state1,512);

//     return 1;
// }

// int wbsm4_se_cl_avx2_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbsm4_se_cl_avx2_context *ctx) {
//     	uint8_t tmp_input[512] = {0};
//         uint8_t tmp_output[512] = {0};
//         memset(output,0,len);
//         uint8_t* out = output;
//         uint8_t* in = input;
        
//         while(len > 0)
//         {
//             if(len < 512)
//             {
//                 memset(tmp_input, 0, 512);
//                 memcpy(tmp_input, in, len);
        
//                 wbsm4_se_cl_avx2_encrypt(tmp_input, tmp_output, ctx);
				
//                 memcpy(out, tmp_output, len);
				
//                 len = 0;
//             }
//             else
//             {
//                 memcpy(tmp_input, in, 512);
    
//                 wbsm4_se_cl_avx2_encrypt(tmp_input, tmp_output, ctx);

//                 memcpy(out, tmp_output, 512);

//                 len -= 512;
//                 out += 512;
//                 in += 512;
//             }
//         }
//         return 1;
// }