// #include "wbaes_se_ms_neon.h"
// typedef union {
//     uint8x16_t vect_u8;
//     uint16x8_t vect_u16;
//     uint32x4_t vect_u32;
//     uint64x2_t vect_u64;
// } __m128i;
// #define SET8x16(res, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15)                     \
//     __asm__ __volatile__ (                                  \
//         "mov %[r].b[0], %w[x]        \n\t"                  \
//         "mov %[r].b[1], %w[y]        \n\t"                  \
//         "mov %[r].b[2], %w[z]        \n\t"                  \
//         "mov %[r].b[3], %w[k]        \n\t"                  \
//         "mov %[r].b[4], %w[x0]        \n\t"                  \
//         "mov %[r].b[5], %w[y0]        \n\t"                  \
//         "mov %[r].b[6], %w[z0]        \n\t"                  \
//         "mov %[r].b[7], %w[k0]        \n\t"                  \
//         "mov %[r].b[8], %w[x1]        \n\t"                  \
//         "mov %[r].b[9], %w[y1]        \n\t"                  \
//         "mov %[r].b[10], %w[z1]        \n\t"                  \
//         "mov %[r].b[11], %w[k1]        \n\t"                  \
//         "mov %[r].b[12], %w[x2]        \n\t"                  \
//         "mov %[r].b[13], %w[y2]        \n\t"                  \
//         "mov %[r].b[14], %w[z2]        \n\t"                  \
//         "mov %[r].b[15], %w[k2]        \n\t"                  \
//         :[r]"=w"(res)                                       \
//         :[x]"r"(e0), [y]"r"(e1), [z]"r"(e2), [k]"r"(e3), [x0]"r"(e4), [y0]"r"(e5), [z0]"r"(e6), [k0]"r"(e7), [x1]"r"(e8), [y1]"r"(e9), [z1]"r"(e10), [k1]"r"(e11), [x2]"r"(e12), [y2]"r"(e13), [z2]"r"(e14), [k2]"r"(e15)     \
//     );
// static uint8x16x4_t Table[4];
// static void dump_hex(uint8_t * h, int len)
// {
//     while(len--)
//     {   
//         printf("%02hhx ",*h++);
//         if(len%16==0) printf("\n");
//     }
//     printf("\n");
// }

// wbaes_se_ms_neon_context * wbaes_se_ms_neon_context_init(){
//     wbaes_se_ms_neon_context *ctx = malloc(sizeof(wbaes_se_ms_neon_context));
//     if (ctx == NULL) {
//         goto cleanup;
//     }
//     memset(ctx, 0, sizeof(wbaes_se_ms_neon_context));
//     return ctx;
// cleanup:
//     return NULL;
// }

// void wbaes_se_ms_neon_context_free(wbaes_se_ms_neon_context *ctx) {
//     memset(ctx, 0, sizeof(wbaes_se_ms_neon_context));
// }

// void MatrixdivM128to4(M128 mat128, M4 m4[32][32])
// {
//     uint64_t m[2][2] = {
//         {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
//         {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
//     };
//     __m128i M0,M1,mask[2],tmp0,tmp1,swap;
//     uint8_t first4[128][16] = {0};
//     uint8_t second4[128][16] = {0};
//     mask[0].vect_u64 = vld1q_u64(m[0]);
//     mask[1].vect_u64 = vld1q_u64(m[1]);
//     SET8x16(swap.vect_u8,7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8);
//     for (size_t i = 0; i < 64; i++)
//     {
//         M0.vect_u32 = vld1q_u32(mat128.M + i * 2);
//         M1.vect_u32 = vld1q_u32(mat128.M + i * 2 + 1);
//         M0.vect_u8 = vqtbl1q_u8(M0.vect_u8,swap.vect_u8);
//         M1.vect_u8 = vqtbl1q_u8(M1.vect_u8,swap.vect_u8);
//         // printf("load:\n");
//         // dump_hex(&M0,32);
//         tmp0.vect_u8 = vandq_u8(M0.vect_u8,mask[0].vect_u8);
//         tmp1.vect_u8 = vandq_u8(M1.vect_u8,mask[0].vect_u8);
//         tmp0.vect_u32 = vshrq_n_u32(tmp0.vect_u32,4);
//         tmp1.vect_u32 = vshrq_n_u32(tmp1.vect_u32,4);

//         vst1q_u8(first4[2*i], tmp0.vect_u8);
//         vst1q_u8(first4[2*i+1], tmp1.vect_u8);

//         tmp0.vect_u8 = vandq_u8(M0.vect_u8,mask[1].vect_u8);
//         tmp1.vect_u8 = vandq_u8(M1.vect_u8,mask[1].vect_u8);
//         vst1q_u8(second4[2*i], tmp0.vect_u8);
//         vst1q_u8(second4[2*i+1], tmp1.vect_u8);
//     }
    
//     //将first4、second4中的数据放进data
//     for (size_t i = 0; i < 32; i++)
//     {
//         for (size_t j = 0; j < 32; j+=2)
//         {
//             m4[i][j].M[0] = first4[4 * i    ][j / 2];
//             m4[i][j].M[1] = first4[4 * i + 1][j / 2];
//             m4[i][j].M[2] = first4[4 * i + 2][j / 2];
//             m4[i][j].M[3] = first4[4 * i + 3][j / 2];
            
//             m4[i][j + 1].M[0] = second4[4 * i    ][j / 2];
//             m4[i][j + 1].M[1] = second4[4 * i + 1][j / 2];
//             m4[i][j + 1].M[2] = second4[4 * i + 2][j / 2];
//             m4[i][j + 1].M[3] = second4[4 * i + 3][j / 2];
//         }
//     }
    
    
// }


// uint8_t GetMatMulVecM4(M4 Mat, uint8_t Vec){
//     V4 ret, tmp;
//     tmp.V = Vec;
//     MatMulVecM4(Mat, tmp, &ret);
//     return ret.V;
// }

// void GEN_TABLE_DATA_F4(M4 TMP[32][32], uint8_t index, uint8_t data[16][16][16]) {
// 	// data 的 ij 是 index 所乘8*8矩阵在大矩阵中的位置
//     for (size_t i = 0; i < 16; i++)
// 	{
// 		for (size_t j = 0; j < 16; j++)
//         {
//             data[j][i][index] = (GetMatMulVecM4(TMP[i * 2][j * 2], index) << 4) + GetMatMulVecM4(TMP[i * 2 + 1][j * 2], index);
// 			// printf("F4: i = %d  j = %d , index * [%d][%d] + index * [%d][%d] \n",i,j,i * 2,j * 2,i * 2 + 1,j * 2);
			
//         }
		
// 	}
// 	// dump_hex(data,16*16*16);
// }

// void GEN_TABLE_DATA_E4(M4 TMP[32][32], uint8_t index, uint8_t data[16][16][16]) {
// 	// data 的 ij 是 index 所乘8*8矩阵在大矩阵中的位置
//     for (size_t i = 0; i < 16; i++)
// 	{
// 		for (size_t j = 0; j < 16; j++)
//         {
//             data[j][i][index] = (GetMatMulVecM4(TMP[i * 2][j * 2 + 1], index) << 4) + GetMatMulVecM4(TMP[i * 2 + 1][j * 2 + 1], index);
// 			// printf("E4: i = %d  j = %d , index * [%d][%d] + index * [%d][%d] \n",i,j,i * 2,j * 2 + 1,i * 2 + 1,j * 2 + 1);
//         }
// 	}
// }

// void AFFINE_ENCODING(__m128i IN[16], __m128i OUT[16], uint8_t table_f4[16][16][16], uint8_t table_e4[16][16][16], uint8_t table_vec[16]) {
//         __m128i input_f4[16], input_e4[16];
// 		// ! 先用个test_out，后面再检查具体是哪里不行
// 		// __m256i test_out[16];
//         __m128i tmp_f4,tmp_e4;
//         __m128i tmp_128_mat;// 表的大小只有128
//         __m128i tmp_vec;
//         __m128i mask[2];
//         uint64_t m[2][2] = {
//             {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
//             {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
//         };
//         mask[0].vect_u64 = vld1q_u64(m[0]);
//         mask[1].vect_u64 = vld1q_u64(m[1]);
	
//         for (size_t i = 0; i < 16; i++)//从明文中取4bit
//         {
//             input_f4[i].vect_u8 = vandq_u8(mask[0].vect_u8,IN[i].vect_u8);
//             input_f4[i].vect_u32 = vshrq_n_u32(input_f4[i].vect_u32,4);
//             input_e4[i].vect_u8 = vandq_u8(mask[1].vect_u8,IN[i].vect_u8);
//         }
        
// 		// 16个字节明文循环
//         for (size_t i = 0; i < 16; i++)
//         {
// 			OUT[i].vect_u32 = vdupq_n_u32(0); 
//             for (size_t j = 0; j < 16; j++)
// 			{
// 				tmp_128_mat.vect_u8 = vld1q_u8(table_f4[i][j]);
// 				tmp_f4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_f4[j].vect_u8);// 4-8查表

// 				tmp_128_mat.vect_u8 = vld1q_u8(table_e4[i][j]);
// 				tmp_e4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_e4[j].vect_u8);// 4-8查表

// 				OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_e4.vect_u8 ^ tmp_f4.vect_u8;
// 			}
			
//         }
     
//         for (size_t i = 0; i < 16; i++)
//         {
// 			tmp_vec.vect_u8 = vdupq_n_u8(table_vec[i]);
//            	OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_vec.vect_u8;
			
//         }
//         // dump_hex(OUT,16);
	
// }

// void DATA_PACK( __m128i OUT[16]){
//     // printf("\npack input:\n");
//     // dump_hex(OUT,512);
//     __m128i state[16];
//     for(int i=0;i<8;i++){
//             state[i].vect_u8 = vzip1q_u8(OUT[2*i].vect_u8,OUT[2*i+1].vect_u8);
//             state[i+8].vect_u8 = vzip2q_u8(OUT[2*i].vect_u8,OUT[2*i+1].vect_u8);
//         }
//         // printf("\nOUT-after:\n");
//         // dump_hex(state,256);
//         OUT[0].vect_u16 = vzip1q_u16(state[0].vect_u16,state[1].vect_u16);
//         OUT[1].vect_u16 = vzip1q_u16(state[2].vect_u16,state[3].vect_u16);
//         OUT[2].vect_u16 = vzip1q_u16(state[4].vect_u16,state[5].vect_u16);
//         OUT[3].vect_u16 = vzip1q_u16(state[6].vect_u16,state[7].vect_u16);

//         OUT[4].vect_u16 = vzip2q_u16(state[0].vect_u16,state[1].vect_u16);
//         OUT[5].vect_u16 = vzip2q_u16(state[2].vect_u16,state[3].vect_u16);
//         OUT[6].vect_u16 = vzip2q_u16(state[4].vect_u16,state[5].vect_u16);
//         OUT[7].vect_u16 = vzip2q_u16(state[6].vect_u16,state[7].vect_u16);
//         // printf("\nOUT(对lo进行操作):\n");
//         // dump_hex(OUT,128);  

//         OUT[8].vect_u16 = vzip1q_u16(state[8].vect_u16,state[9].vect_u16);
//         OUT[9].vect_u16 = vzip1q_u16(state[10].vect_u16,state[11].vect_u16);
//         OUT[10].vect_u16 = vzip1q_u16(state[12].vect_u16,state[13].vect_u16);
//         OUT[11].vect_u16 = vzip1q_u16(state[14].vect_u16,state[15].vect_u16);

//         OUT[12].vect_u16 = vzip2q_u16(state[8].vect_u16,state[9].vect_u16);
//         OUT[13].vect_u16 = vzip2q_u16(state[10].vect_u16,state[11].vect_u16);
//         OUT[14].vect_u16 = vzip2q_u16(state[12].vect_u16,state[13].vect_u16);
//         OUT[15].vect_u16 = vzip2q_u16(state[14].vect_u16,state[15].vect_u16);  
//         // printf("\nOUT(对hi进行操作):\n");
//         // dump_hex(OUT+8,128);  


//         state[0].vect_u32 = vzip1q_u32(OUT[0].vect_u32,OUT[1].vect_u32);//0-1
//         state[1].vect_u32 = vzip1q_u32(OUT[2].vect_u32,OUT[3].vect_u32);
//         state[2].vect_u32 = vzip1q_u32(OUT[4].vect_u32,OUT[5].vect_u32);//4-5
//         state[3].vect_u32 = vzip1q_u32(OUT[6].vect_u32,OUT[7].vect_u32);
        
//         state[4].vect_u32 = vzip2q_u32(OUT[0].vect_u32,OUT[1].vect_u32);//2-3
//         state[5].vect_u32 = vzip2q_u32(OUT[2].vect_u32,OUT[3].vect_u32);
//         state[6].vect_u32 = vzip2q_u32(OUT[4].vect_u32,OUT[5].vect_u32);//6-7
//         state[7].vect_u32 = vzip2q_u32(OUT[6].vect_u32,OUT[7].vect_u32);
//         // printf("\nstate:\n");
//         // dump_hex(state,128); 

//         state[8].vect_u32 = vzip1q_u32(OUT[8].vect_u32,OUT[9].vect_u32);//0-1
//         state[9].vect_u32 = vzip1q_u32(OUT[10].vect_u32,OUT[11].vect_u32);
//         state[10].vect_u32 = vzip1q_u32(OUT[12].vect_u32,OUT[13].vect_u32);//4-5
//         state[11].vect_u32 = vzip1q_u32(OUT[14].vect_u32,OUT[15].vect_u32);
        
//         state[12].vect_u32 = vzip2q_u32(OUT[8].vect_u32,OUT[9].vect_u32);//2-3
//         state[13].vect_u32 = vzip2q_u32(OUT[10].vect_u32,OUT[11].vect_u32);
//         state[14].vect_u32 = vzip2q_u32(OUT[12].vect_u32,OUT[13].vect_u32);//6-7
//         state[15].vect_u32 = vzip2q_u32(OUT[14].vect_u32,OUT[15].vect_u32);
//         // printf("\nstate:\n");
//         // dump_hex(state+8,128);  
        
//         OUT[0].vect_u64 = vzip1q_u64(state[0].vect_u64,state[1].vect_u64);
//         OUT[1].vect_u64 = vzip2q_u64(state[0].vect_u64,state[1].vect_u64);

//         OUT[2].vect_u64 = vzip1q_u64(state[4].vect_u64,state[5].vect_u64);
//         OUT[3].vect_u64 = vzip2q_u64(state[4].vect_u64,state[5].vect_u64);

//         OUT[4].vect_u64 = vzip1q_u64(state[2].vect_u64,state[3].vect_u64);
//         OUT[5].vect_u64 = vzip2q_u64(state[2].vect_u64,state[3].vect_u64);

//         OUT[6].vect_u64 = vzip1q_u64(state[6].vect_u64,state[7].vect_u64);
//         OUT[7].vect_u64 = vzip2q_u64(state[6].vect_u64,state[7].vect_u64);


//         OUT[8].vect_u64 = vzip1q_u64(state[8].vect_u64,state[9].vect_u64);
//         OUT[9].vect_u64 = vzip2q_u64(state[8].vect_u64,state[9].vect_u64);

//         OUT[10].vect_u64 = vzip1q_u64(state[12].vect_u64,state[13].vect_u64);
//         OUT[11].vect_u64 = vzip2q_u64(state[12].vect_u64,state[13].vect_u64);

//         OUT[12].vect_u64 = vzip1q_u64(state[10].vect_u64,state[11].vect_u64);
//         OUT[13].vect_u64 = vzip2q_u64(state[10].vect_u64,state[11].vect_u64);

//         OUT[14].vect_u64 = vzip1q_u64(state[14].vect_u64,state[15].vect_u64);
//         OUT[15].vect_u64 = vzip2q_u64(state[14].vect_u64,state[15].vect_u64);
// //         printf("\npack output:\n");
// //         dump_hex(OUT,512);
// }
// int wbaes_se_ms_neon_gen_table(wbaes_se_ms_neon_context *ctx, const uint8_t *key) {

// 	wbaes_se_ms_context aes_key;
//     wbaes_se_ms_gen_table(&aes_key,key);
//     M4 TMP[32][32];

// 	for (size_t i = 0; i < 11; i++)
// 	{
// 		MatrixdivM128to4(aes_key.AL[i].Mat,TMP);
//         for (size_t j = 0; j < 16; j++)
//         {
//             GEN_TABLE_DATA_F4(TMP,j,ctx->AL_M_F4[i]);
//             GEN_TABLE_DATA_E4(TMP,j,ctx->AL_M_E4[i]);
//         }	
// 		PUT64(aes_key.AL[i].Vec.V[0],ctx->AL_V[i]);
//         PUT64(aes_key.AL[i].Vec.V[1],ctx->AL_V[i]+8);

// 	}
//     for (size_t i = 0; i < 2; i++)
// 	{
// 		MatrixdivM128to4(aes_key.P[i].Mat,TMP);
//         for (size_t j = 0; j < 16; j++)
//         {
//             GEN_TABLE_DATA_F4(TMP,j,ctx->P_M_F4[i]);
//             GEN_TABLE_DATA_E4(TMP,j,ctx->P_M_E4[i]);
//         }	
// 		PUT64(aes_key.P[i].Vec.V[0],ctx->P_V[i]);
//         PUT64(aes_key.P[i].Vec.V[1],ctx->P_V[i]+8);

//         MatrixdivM128to4(aes_key.P_inv[i].Mat,TMP);
//         for (size_t j = 0; j < 16; j++)
//         {
//             GEN_TABLE_DATA_F4(TMP,j,ctx->P_inv_M_F4[i]);
//             GEN_TABLE_DATA_E4(TMP,j,ctx->P_inv_M_E4[i]);
//         }	
// 		PUT64(aes_key.P_inv[i].Vec.V[0],ctx->P_inv_V[i]);
//         PUT64(aes_key.P_inv[i].Vec.V[1],ctx->P_inv_V[i]+8);
// 	}	
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             Table[i].val[j] = vld1q_u8(SBox + 64 * i + 16 * j);
//         }
//     }
// 	// dump_hex(ctx->AL_M_F4,35*16*16*16);
// 		return 1;
// }



// int wbaes_se_ms_neon_encrypt(const uint8_t IN[256], uint8_t OUT[256], wbaes_se_ms_neon_context *ctx) {
   
// 	__m128i state1[16];
// 	// __m256i state2[16];
// 	__m128i mask;

//     const static uint8_t SubData[16] = {64, 64, 64, 64, 64, 64, 64, 64,
//                                         64, 64, 64, 64, 64, 64, 64, 64};
//     uint8x16_t dec;
//     uint8x16_t tmp_8x16, tmp1_8x16;
//     dec = vld1q_u8(SubData);
//     mask.vect_u32 = vdupq_n_u32(0xFF);
// 	memcpy(state1, IN, 256);
// 	DATA_PACK(state1);
	
//     AFFINE_ENCODING(state1, state1, ctx->P_M_F4[0], ctx->P_M_E4[0], ctx->P_V[0]);

// 	for (size_t i = 0; i < 10; i++)
// 	{
//         AFFINE_ENCODING(state1, state1, ctx->AL_M_F4[i], ctx->AL_M_E4[i], ctx->AL_V[i]);
//         for (size_t j = 0; j < 16; j++)
//         {
//             tmp_8x16 = state1[j].vect_u8;
//             state1[j].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             state1[j].vect_u8 = veorq_u8(state1[j].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             state1[j].vect_u8 = veorq_u8(state1[j].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             state1[j].vect_u8 = veorq_u8(state1[j].vect_u8, tmp1_8x16);
//         }
        
        
// 	}
   
//     AFFINE_ENCODING(state1, state1, ctx->AL_M_F4[10], ctx->AL_M_E4[10], ctx->AL_V[10]);

//     AFFINE_ENCODING(state1, state1, ctx->P_inv_M_F4[1], ctx->P_inv_M_E4[1], ctx->P_inv_V[1]);
// 	DATA_PACK(state1);
	
// 	memcpy(OUT,state1,256);

//     return 1;
// }

// int wbaes_se_ms_neon_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_ms_neon_context *ctx) {
//     	uint8_t tmp_input[256] = {0};
//         uint8_t tmp_output[256] = {0};
//         memset(output,0,len);
//         uint8_t* out = output;
//         uint8_t* in = input;
        
//         while(len > 0)
//         {
//             if(len < 256)
//             {
//                 memset(tmp_input, 0, 256);
//                 memcpy(tmp_input, in, len);
        
//                 wbaes_se_ms_neon_encrypt(tmp_input, tmp_output, ctx);
				
//                 memcpy(out, tmp_output, len);
				
//                 len = 0;
//             }
//             else
//             {
//                 memcpy(tmp_input, in, 256);
    
//                 wbaes_se_ms_neon_encrypt(tmp_input, tmp_output, ctx);

//                 memcpy(out, tmp_output, 256);

//                 len -= 256;
//                 out += 256;
//                 in += 256;
//             }
//         }
//         return 1;
// }