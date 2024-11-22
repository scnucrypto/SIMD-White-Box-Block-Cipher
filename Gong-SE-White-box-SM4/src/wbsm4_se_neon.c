// #include "wbsm4_se_local.h"
// #include "wbsm4_se_neon.h"

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
// #define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
// static uint8x16x4_t Table[4];
// //! test
// static void dump_hex(uint8_t * h, int len)
// {
//     while(len--)
//     {   
//         printf("%02hhx ",*h++);
//         if(len%32==0) printf("\n");
//     }
//     printf("\n");
// }

// static Aff8 A[2039], B[2039];

// static void MatrixdivM32to4(M32 mat32, M4 m4[8][8])
// {
//     printf("m-000\n");
//     uint64_t m[2][2] = {
//         {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
//         {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
//     };
 
//     __m128i M0,M1,mask[2],tmp0,tmp1,swap;
//     uint8_t first4[32][4] = {0};
//     uint8_t second4[32][4] = {0};
//     uint8_t tmp_f4[8][16] = {0};
//     uint8_t tmp_e4[8][16] = {0};
//     mask[0].vect_u64 = vld1q_u64(m[0]);
//     mask[1].vect_u64 = vld1q_u64(m[1]);
//     SET8x16(swap.vect_u8,3,2,1,0,7,6,5,4,11,10,9,8,15,14,13,12);
//     printf("m-111\n");
//     for (size_t i = 0; i < 4; i++)
//     {
//         M0.vect_u32 = vld1q_u32(mat32.M + (i * 8));
//         M1.vect_u32 = vld1q_u32(mat32.M + (i * 8 + 4));
//         M0.vect_u8 = vqtbl1q_u8(M0.vect_u8,swap.vect_u8);
//         M1.vect_u8 = vqtbl1q_u8(M1.vect_u8,swap.vect_u8);
// 	    printf("m-222\n");
//         printf("load:\n");
//         dump_hex(&M0.vect_u8,16);
//         tmp0.vect_u8 = vandq_u8(M0.vect_u8,mask[0].vect_u8);
//         tmp1.vect_u8 = vandq_u8(M1.vect_u8,mask[0].vect_u8);
//         tmp0.vect_u32 = vshrq_n_u32(tmp0.vect_u32,4);
//         tmp1.vect_u32 = vshrq_n_u32(tmp1.vect_u32,4);
        
//         vst1q_u8(tmp_f4[i*2], tmp0.vect_u8);
//         vst1q_u8(tmp_f4[i*2+1], tmp1.vect_u8);

//         tmp0.vect_u8 = vandq_u8(M0.vect_u8,mask[1].vect_u8);
//         tmp1.vect_u8 = vandq_u8(M1.vect_u8,mask[1].vect_u8);
//         vst1q_u8(tmp_e4[i*2], tmp0.vect_u8);
//         vst1q_u8(tmp_e4[i*2+1], tmp1.vect_u8);
//     }
//     printf("m-333\n");
//     memcpy(first4, tmp_f4, 256);
//     memcpy(second4, tmp_e4, 256);
//     //将first4、second4中的数据放进data
//     for (size_t i = 0; i < 8; i++)
//     {
//         for (size_t j = 0; j < 8; j+=2)
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
//     }printf("m-444\n");
    
// }

// wbsm4_se_neon_context *wbsm4_se_neon_context_init(int encmode) {
//     wbsm4_se_neon_context *ctx = malloc(sizeof(wbsm4_se_neon_context));
//     if (ctx == NULL) {
//         goto cleanup;
//     }
//     memset(ctx, 0, sizeof(wbsm4_se_neon_context));
//     ctx->encmode = encmode;
//     return ctx;
// cleanup:
//     return NULL;
// }

// int se_gen(se_context *ctx, int encmode, const uint8_t *key) {
//     int i;
//     Aff32 P[36];
//     Aff32 K[32];
//     Aff32 L;
//     Aff32 P_inv[36];
//     Aff32 AA[32], BB[32];

//     sm4_context *sm4_key = sm4_context_init();
//     if (encmode) {
//         sm4_setkey_enc(sm4_key, key);
//     } else {
//         sm4_setkey_dec(sm4_key, key);
//     }
    
//     InitRandom(((unsigned int) time(NULL)));
//     InitRandom(1);

//     SE_initial(A,B);

//     //affine L for linear layer
//     L.Mat = L_matrix;
//     L.Vec.V = 0;

//     //! 有问题
//     for (i = 0; i < 36; i++) {
//         //affine P
//        // genaffinepairM32(&P[i], &P_inv[i]);
//        identityM32(&P[i].Mat);
//        identityM32(&P_inv[i].Mat);
//        P[i].Vec.V = 0;
//        P_inv[i].Vec.V = 0;
//     }

//     for (i = 0; i < 32; i++) {
//         // combine 4 A8 to 1 A32
//         int a0, a1, a2, a3;
        
//         a0 = cus_random() % 2039;
//         a1 = cus_random() % 2039;
//         a2 = cus_random() % 2039;
//         a3 = cus_random() % 2039;
        
//         affinecomM8to32(A[a0], A[a1], A[a2], A[a3], &AA[i]);
//         affinecomM8to32(B[a0], B[a1], B[a2], B[a3], &BB[i]);

//         //affine K for round key
//         identityM32(&K[i].Mat);
//         K[i].Vec.V = sm4_key->sk[i];

//         //affine M
//         affinemixM32(K[i], P_inv[i + 1], &ctx->M[i][0]);
//         affinemixM32(AA[i], ctx->M[i][0], &ctx->M[i][0]);

//         affinemixM32(K[i], P_inv[i + 2], &ctx->M[i][1]);
//         affinemixM32(AA[i], ctx->M[i][1], &ctx->M[i][1]);

//         affinemixM32(K[i], P_inv[i + 3], &ctx->M[i][2]);
//         affinemixM32(AA[i], ctx->M[i][2], &ctx->M[i][2]);

//         //affine C D, C for Xi0, D for Pi+4 L B
//         affinemixM32(P[i + 4], P_inv[i], &ctx->C[i]);

//         affinemixM32(L, BB[i], &ctx->D[i]);
//         affinemixM32(P[i + 4], ctx->D[i], &ctx->D[i]);

//         //! 换成常数方便测试 
//         uint32_t temp_u32 = cus_random();
      
//         ctx->C[i].Vec.V ^= temp_u32;
//         ctx->D[i].Vec.V ^= P[i + 4].Vec.V ^ temp_u32;
//     }

//     //external encoding
//     for (i = 0; i < 4; i++) {
//         ctx->SE[i].Mat = P[i].Mat;
//         ctx->SE[i].Vec = P[i].Vec;

//         ctx->FE[i].Mat = P_inv[35 - i].Mat;
//         ctx->FE[i].Vec = P_inv[35 - i].Vec;
//     }
    
//     return 1;
// }

// void wbsm4_se_neon_context_free(wbsm4_se_neon_context *ctx) {
//     memset(ctx, 0, sizeof(wbsm4_se_neon_context));
// }

// uint8_t GetMatMulVecM4(M4 Mat, uint8_t Vec){
//     V4 ret, tmp;
//     tmp.V = Vec;
//     MatMulVecM4(Mat, tmp, &ret);
//     return ret.V;
// }

// void GEN_TABLE_DATA_F4(M4 TMP[8][8], uint8_t index, uint8_t data[4][4][16]) {
//     //每4bit需要4-8查表4次，32bit中每8bit的前4bit共有4块数据，4*4
//     //前 4bit
//     data[0][0][index] = (GetMatMulVecM4(TMP[0][0], index) << 4) + GetMatMulVecM4(TMP[1][0], index);//TODO 顺序可能出错
//     data[1][0][index] = (GetMatMulVecM4(TMP[0][2], index) << 4) + GetMatMulVecM4(TMP[1][2], index);
//     data[2][0][index] = (GetMatMulVecM4(TMP[0][4], index) << 4) + GetMatMulVecM4(TMP[1][4], index);
//     data[3][0][index] = (GetMatMulVecM4(TMP[0][6], index) << 4) + GetMatMulVecM4(TMP[1][6], index);

//     data[0][1][index] = (GetMatMulVecM4(TMP[2][0], index) << 4) + GetMatMulVecM4(TMP[3][0], index);
//     data[1][1][index] = (GetMatMulVecM4(TMP[2][2], index) << 4) + GetMatMulVecM4(TMP[3][2], index);
//     data[2][1][index] = (GetMatMulVecM4(TMP[2][4], index) << 4) + GetMatMulVecM4(TMP[3][4], index);
//     data[3][1][index] = (GetMatMulVecM4(TMP[2][6], index) << 4) + GetMatMulVecM4(TMP[3][6], index);

//     data[0][2][index] = (GetMatMulVecM4(TMP[4][0], index) << 4) + GetMatMulVecM4(TMP[5][0], index);
//     data[1][2][index] = (GetMatMulVecM4(TMP[4][2], index) << 4) + GetMatMulVecM4(TMP[5][2], index);
//     data[2][2][index] = (GetMatMulVecM4(TMP[4][4], index) << 4) + GetMatMulVecM4(TMP[5][4], index);
//     data[3][2][index] = (GetMatMulVecM4(TMP[4][6], index) << 4) + GetMatMulVecM4(TMP[5][6], index);

//     data[0][3][index] = (GetMatMulVecM4(TMP[6][0], index) << 4) + GetMatMulVecM4(TMP[7][0], index);
//     data[1][3][index] = (GetMatMulVecM4(TMP[6][2], index) << 4) + GetMatMulVecM4(TMP[7][2], index);
//     data[2][3][index] = (GetMatMulVecM4(TMP[6][4], index) << 4) + GetMatMulVecM4(TMP[7][4], index);
//     data[3][3][index] = (GetMatMulVecM4(TMP[6][6], index) << 4) + GetMatMulVecM4(TMP[7][6], index);
//     // 加密时的查表顺序是第一个4bit 从data[0][0] -> data[0][3] 第二个4bit 从data[1][0] -> data[1][3]
// }
// void GEN_TABLE_DATA_E4(M4 TMP[8][8], uint8_t index, uint8_t data[4][4][16]) {
//     //每4bit需要4-8查表4次，32bit中每8bit的前4bit共有4块数据，4*4
//     //后 4bit
//     data[0][0][index] = (GetMatMulVecM4(TMP[0][1], index) << 4) + GetMatMulVecM4(TMP[1][1], index);
//     data[1][0][index] = (GetMatMulVecM4(TMP[0][3], index) << 4) + GetMatMulVecM4(TMP[1][3], index);
//     data[2][0][index] = (GetMatMulVecM4(TMP[0][5], index) << 4) + GetMatMulVecM4(TMP[1][5], index);
//     data[3][0][index] = (GetMatMulVecM4(TMP[0][7], index) << 4) + GetMatMulVecM4(TMP[1][7], index);

//     data[0][1][index] = (GetMatMulVecM4(TMP[2][1], index) << 4) + GetMatMulVecM4(TMP[3][1], index);
//     data[1][1][index] = (GetMatMulVecM4(TMP[2][3], index) << 4) + GetMatMulVecM4(TMP[3][3], index);
//     data[2][1][index] = (GetMatMulVecM4(TMP[2][5], index) << 4) + GetMatMulVecM4(TMP[3][5], index);
//     data[3][1][index] = (GetMatMulVecM4(TMP[2][7], index) << 4) + GetMatMulVecM4(TMP[3][7], index);

//     data[0][2][index] = (GetMatMulVecM4(TMP[4][1], index) << 4) + GetMatMulVecM4(TMP[5][1], index);
//     data[1][2][index] = (GetMatMulVecM4(TMP[4][3], index) << 4) + GetMatMulVecM4(TMP[5][3], index);
//     data[2][2][index] = (GetMatMulVecM4(TMP[4][5], index) << 4) + GetMatMulVecM4(TMP[5][5], index);
//     data[3][2][index] = (GetMatMulVecM4(TMP[4][7], index) << 4) + GetMatMulVecM4(TMP[5][7], index);

//     data[0][3][index] = (GetMatMulVecM4(TMP[6][1], index) << 4) + GetMatMulVecM4(TMP[7][1], index);
//     data[1][3][index] = (GetMatMulVecM4(TMP[6][3], index) << 4) + GetMatMulVecM4(TMP[7][3], index);
//     data[2][3][index] = (GetMatMulVecM4(TMP[6][5], index) << 4) + GetMatMulVecM4(TMP[7][5], index);
//     data[3][3][index] = (GetMatMulVecM4(TMP[6][7], index) << 4) + GetMatMulVecM4(TMP[7][7], index);
// }

// int wbsm4_se_neon_gen_table(wbsm4_se_neon_context *ctx, const uint8_t *key) {
//     //原始wbsme_se_context中的矩阵
//     printf("gen-000\n");
//     se_context se_ctx;
//     se_gen(&se_ctx,ctx->encmode,key);


//     for(size_t i = 0; i < 32; i++)//32轮M0，M1, M2, C, D等
// 	{
//         M4 M0_TMP[8][8];
//         M4 M1_TMP[8][8];
//         M4 M2_TMP[8][8];
//         M4 C_TMP[8][8];
//         M4 D_TMP[8][8];//TODO 还差SE和FE

//         // M32->M4[8][8]
//         printf("gen-0001\n");
//         MatrixdivM32to4(se_ctx.M[i][0].Mat, M0_TMP);//TODO 测试是否能正常传值
//         printf("gen-0002\n");
//         MatrixdivM32to4(se_ctx.M[i][1].Mat, M1_TMP);
//             printf("gen-0003\n");
//         MatrixdivM32to4(se_ctx.M[i][2].Mat, M2_TMP);
//             printf("gen-0004\n");
//         MatrixdivM32to4(se_ctx.C[i].Mat, C_TMP);
//             MatrixdivM32to4(se_ctx.D[i].Mat, D_TMP);
        
// 	printf("\ngen-111\n");
//         PUT32(se_ctx.M[i][0].Vec.V, ctx->M0_V[i]);
//         PUT32(se_ctx.M[i][1].Vec.V, ctx->M1_V[i]);
//         PUT32(se_ctx.M[i][2].Vec.V, ctx->M2_V[i]);
//         PUT32(se_ctx.C[i].Vec.V, ctx->C_V[i]);
//         PUT32(se_ctx.D[i].Vec.V, ctx->D_V[i]);

//         for (size_t x = 0; x < 16; x++)// 4bit的遍历
//         {
//             //每4bit需要4-8查表4次，32bit中每8bit的前4bit共有4块数据，4*4
// 			GEN_TABLE_DATA_F4(M0_TMP,x,ctx->M0_F4[i]);
//             GEN_TABLE_DATA_F4(M1_TMP,x,ctx->M1_F4[i]);
//             GEN_TABLE_DATA_F4(M2_TMP,x,ctx->M2_F4[i]);
//             GEN_TABLE_DATA_F4(C_TMP,x,ctx->C_F4[i]);
//             GEN_TABLE_DATA_F4(D_TMP,x,ctx->D_F4[i]);

//             GEN_TABLE_DATA_E4(M0_TMP,x,ctx->M0_E4[i]);
//             GEN_TABLE_DATA_E4(M1_TMP,x,ctx->M1_E4[i]);
//             GEN_TABLE_DATA_E4(M2_TMP,x,ctx->M2_E4[i]);
//             GEN_TABLE_DATA_E4(C_TMP,x,ctx->C_E4[i]);
//             GEN_TABLE_DATA_E4(D_TMP,x,ctx->D_E4[i]);
//         }
// 	}
//     for (size_t i = 0; i < 4; i++)
//     {
//         M4 SE_TMP[8][8];
//         M4 FE_TMP[8][8];
        
//         PUT32(se_ctx.SE[i].Vec.V, ctx->SE_V[i]);
//         PUT32(se_ctx.FE[i].Vec.V, ctx->FE_V[i]);

//         MatrixdivM32to4(se_ctx.SE[i].Mat, SE_TMP);//TODO 测试是否能正常传值
//         MatrixdivM32to4(se_ctx.FE[i].Mat, FE_TMP);
//         for (size_t x = 0; x < 16; x++)// 4bit的遍历
//         {
//             //每4bit需要4-8查表4次，32bit中每8bit的前4bit共有4块数据，4*4
//             GEN_TABLE_DATA_F4(SE_TMP,x,ctx->SE_F4[i]);
//             GEN_TABLE_DATA_F4(FE_TMP,x,ctx->FE_F4[i]);
//             GEN_TABLE_DATA_E4(SE_TMP,x,ctx->SE_E4[i]);
//             GEN_TABLE_DATA_E4(FE_TMP,x,ctx->FE_E4[i]);
//         }

//     }
//     printf("gen-222\n");
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             Table[i].val[j] = vld1q_u8(Sbox + 64 * i + 16 * j);
//         }
//     }
//     printf("gen-333\n");
//     return 1;
// }
// // !这里面的某个值没初始化
// void AFFINE_ENCODING(__m128i IN[4], __m128i OUT[4], uint8_t table_f4[4][4][16], uint8_t table_e4[4][4][16], uint8_t table_vec[4]) {
//         __m128i input_f4[4], input_e4[4];
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
//         for (size_t i = 0; i < 4; i++)//从明文中取4bit
//         {
//             input_f4[i].vect_u8 = vandq_u8(mask[0].vect_u8,IN[i].vect_u8);
//             input_f4[i].vect_u32 = vshrq_n_u32(input_f4[i].vect_u32,4);
//             input_e4[i].vect_u8 = vandq_u8(mask[1].vect_u8,IN[i].vect_u8);
//         }
        

//         for (size_t i = 0; i < 4; i++)//32bit分成4组8bit，每个8bit的前4bit
//         {
//             // 以第一个8bit为例，即input_space[0]，其值等于A(0,0) * x0 + A(0,1) * x1 + A(0,2) * x2 + A(0,3) * x3 涉及到32bit的其他部分
            
//             //todo 看是否需要抽成一个函数
//             // A(0,0) * x0
//             tmp_128_mat.vect_u8 = vld1q_u8(table_f4[0][i]);//todo 表装载，直接在ctx存放已经复制了的数据会不会更快
//             tmp_f4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_f4[0].vect_u8);// 4-8查表
          
//             tmp_128_mat.vect_u8 = vld1q_u8(table_e4[0][i]);
//             tmp_e4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_e4[0].vect_u8);// 4-8查表
            
//             OUT[i].vect_u8 = tmp_e4.vect_u8 ^ tmp_f4.vect_u8;//两个4-8查表异或起来，放进中间值暂存
          
//             tmp_128_mat.vect_u8 = vld1q_u8(table_f4[1][i]);
//             tmp_f4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_f4[1].vect_u8);// 4-8查表
          
//             tmp_128_mat.vect_u8 = vld1q_u8(table_e4[1][i]);
//             tmp_e4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_e4[1].vect_u8);// 4-8查表
            
//             OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_e4.vect_u8 ^ tmp_f4.vect_u8;//两个4-8查表异或起来，放进中间值暂存
//             // A(0,2) * x2
//             tmp_128_mat.vect_u8 = vld1q_u8(table_f4[2][i]);
//             tmp_f4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_f4[2].vect_u8);// 4-8查表
          
//             tmp_128_mat.vect_u8 = vld1q_u8(table_e4[2][i]);
//             tmp_e4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_e4[2].vect_u8);// 4-8查表
            
//             OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_e4.vect_u8 ^ tmp_f4.vect_u8;//两个4-8查表异或起来，放进中间值暂存

//             // A(0,3) * x3
//             tmp_128_mat.vect_u8 = vld1q_u8(table_f4[3][i]);
//             tmp_f4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_f4[3].vect_u8);// 4-8查表
          
//             tmp_128_mat.vect_u8 = vld1q_u8(table_e4[3][i]);
//             tmp_e4.vect_u8 = vqtbl1q_u8(tmp_128_mat.vect_u8, input_e4[3].vect_u8);// 4-8查表
            
//             OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_e4.vect_u8 ^ tmp_f4.vect_u8;//两个4-8查表异或起来，放进中间值暂存
//         }
        
//         for (size_t i = 0; i < 4; i++)
//         {
//             tmp_vec.vect_u8 = vdupq_n_u8(table_vec[i]);
//             OUT[i].vect_u8 = OUT[i].vect_u8 ^ tmp_vec.vect_u8;
//         }
//         // dump_hex(OUT,128);

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

// int wbsm4_se_neon_encrypt(const uint8_t IN[256], uint8_t OUT[256], wbsm4_se_neon_context *ctx)// todo 是否传这个ctx
//     {
//         __m128i state1[16];
//         __m128i state2[16];
//         __m128i tmp[4];
//         __m128i mask;

//         const static uint8_t SubData[16] = {64, 64, 64, 64, 64, 64, 64, 64,
//                                         64, 64, 64, 64, 64, 64, 64, 64};
//         uint8x16_t dec;
//         uint8x16_t tmp_8x16, tmp1_8x16;
//         dec = vld1q_u8(SubData);
//         mask.vect_u32 = vdupq_n_u32(0xFF);
//         memcpy(state1, IN, 256);
//         DATA_PACK(state1);

//         // dump_hex(state1,512);
//         // x0 = affineU32(ctx->SE[0], x0);
//         AFFINE_ENCODING(state1     , state1     , ctx->SE_F4[0], ctx->SE_E4[0], ctx->SE_V[0]);
//         // x1 = affineU32(ctx->SE[1], x1);
//         AFFINE_ENCODING(state1 +  4, state1 +  4, ctx->SE_F4[1], ctx->SE_E4[1], ctx->SE_V[1]);
//         // x2 = affineU32(ctx->SE[2], x2);
//         AFFINE_ENCODING(state1 +  8, state1 +  8, ctx->SE_F4[2], ctx->SE_E4[2], ctx->SE_V[2]);
//         // x3 = affineU32(ctx->SE[3], x3);
//         AFFINE_ENCODING(state1 + 12, state1 + 12, ctx->SE_F4[3], ctx->SE_E4[3], ctx->SE_V[3]);
//         // printf("test test\n");
//         // dump_hex(state1,512);

        
//         for (size_t i = 0; i < 32; i+=4)
//         {
//             // 这里的state1是x 而state2是xt
//             //round1
            
//             AFFINE_ENCODING(state1 +  4, state2 +  4, ctx->M0_F4[i], ctx->M0_E4[i], ctx->M0_V[i]);
//             AFFINE_ENCODING(state1 +  8, state2 +  8, ctx->M1_F4[i], ctx->M1_E4[i], ctx->M1_V[i]);
//             AFFINE_ENCODING(state1 + 12, state2 + 12, ctx->M2_F4[i], ctx->M2_E4[i], ctx->M2_V[i]);     
//             AFFINE_ENCODING(state1     , state2     , ctx->C_F4[i], ctx->C_E4[i], ctx->C_V[i]);
  
//             tmp[0].vect_u8 = state2[4].vect_u8 ^ state2[8].vect_u8 ^ state2[12].vect_u8;
//             tmp[1].vect_u8 = state2[5].vect_u8 ^ state2[9].vect_u8 ^ state2[13].vect_u8;
//             tmp[2].vect_u8 = state2[6].vect_u8 ^ state2[10].vect_u8 ^ state2[14].vect_u8;
//             tmp[3].vect_u8 = state2[7].vect_u8 ^ state2[11].vect_u8 ^ state2[15].vect_u8;
//             // printf("input:\n");
//             // dump_hex(tmp,128);
//             //todo sbox gather是对每32bit的低8bit作为序列对256个32bit'进行查表  需要抽离成一个函数？
//             tmp_8x16 = tmp[0].vect_u8;
//             tmp[0].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);
            

//             tmp_8x16 = tmp[1].vect_u8;
//             tmp[1].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[2].vect_u8;
//             tmp[2].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[3].vect_u8;
//             tmp[3].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);
            
//             AFFINE_ENCODING(tmp, tmp, ctx->D_F4[i], ctx->D_E4[i], ctx->D_V[i]);
            

//             state1[0].vect_u8 = state2[0].vect_u8 ^ tmp[0].vect_u8;
//             state1[1].vect_u8 = state2[1].vect_u8 ^ tmp[1].vect_u8;
//             state1[2].vect_u8 = state2[2].vect_u8 ^ tmp[2].vect_u8;
//             state1[3].vect_u8 = state2[3].vect_u8 ^ tmp[3].vect_u8;
         
//             //下面的是接下来的3轮，将4轮放在一起约减了32bit赋值的消耗    
//             //round2 
//             // todo 是否需要将其抽离成函数       
//             AFFINE_ENCODING(state1     , state2     , ctx->M2_F4[i + 1], ctx->M2_E4[i + 1], ctx->M2_V[i + 1]);
//             AFFINE_ENCODING(state1 +  8, state2 +  8, ctx->M0_F4[i + 1], ctx->M0_E4[i + 1], ctx->M0_V[i + 1]);
//             AFFINE_ENCODING(state1 + 12, state2 + 12, ctx->M1_F4[i + 1], ctx->M1_E4[i + 1], ctx->M1_V[i + 1]);
//             AFFINE_ENCODING(state1 +  4, state2 +  4, ctx->C_F4[i + 1], ctx->C_E4[i + 1], ctx->C_V[i + 1]);
          
//             tmp[0].vect_u8 = state2[0].vect_u8 ^ state2[8].vect_u8 ^ state2[12].vect_u8;
//             tmp[1].vect_u8 = state2[1].vect_u8 ^ state2[9].vect_u8 ^ state2[13].vect_u8;
//             tmp[2].vect_u8 = state2[2].vect_u8 ^ state2[10].vect_u8 ^ state2[14].vect_u8;
//             tmp[3].vect_u8 = state2[3].vect_u8 ^ state2[11].vect_u8 ^ state2[15].vect_u8;

//             tmp_8x16 = tmp[0].vect_u8;
//             tmp[0].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);
            

//             tmp_8x16 = tmp[1].vect_u8;
//             tmp[1].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[2].vect_u8;
//             tmp[2].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[3].vect_u8;
//             tmp[3].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);
            
//             AFFINE_ENCODING(tmp, tmp, ctx->D_F4[i + 1], ctx->D_E4[i + 1], ctx->D_V[i + 1]);

//             state1[4].vect_u8 = state2[4].vect_u8 ^ tmp[0].vect_u8;
//             state1[5].vect_u8 = state2[5].vect_u8 ^ tmp[1].vect_u8;
//             state1[6].vect_u8 = state2[6].vect_u8 ^ tmp[2].vect_u8;
//             state1[7].vect_u8 = state2[7].vect_u8 ^ tmp[3].vect_u8;
            
//             //round3
//             AFFINE_ENCODING(state1     , state2     , ctx->M1_F4[i + 2], ctx->M1_E4[i + 2], ctx->M1_V[i + 2]);
//             AFFINE_ENCODING(state1 +  4, state2 +  4, ctx->M2_F4[i + 2], ctx->M2_E4[i + 2], ctx->M2_V[i + 2]);
//             AFFINE_ENCODING(state1 + 12, state2 + 12, ctx->M0_F4[i + 2], ctx->M0_E4[i + 2], ctx->M0_V[i + 2]);
            
//             AFFINE_ENCODING(state1 +  8, state2 +  8, ctx->C_F4[i + 2], ctx->C_E4[i + 2], ctx->C_V[i + 2]);
          
//             tmp[0].vect_u8 = state2[0].vect_u8 ^ state2[4].vect_u8 ^ state2[12].vect_u8;
//             tmp[1].vect_u8 = state2[1].vect_u8 ^ state2[5].vect_u8 ^ state2[13].vect_u8;
//             tmp[2].vect_u8 = state2[2].vect_u8 ^ state2[6].vect_u8 ^ state2[14].vect_u8;
//             tmp[3].vect_u8 = state2[3].vect_u8 ^ state2[7].vect_u8 ^ state2[15].vect_u8;

//             tmp_8x16 = tmp[0].vect_u8;
//             tmp[0].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);
            

//             tmp_8x16 = tmp[1].vect_u8;
//             tmp[1].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[2].vect_u8;
//             tmp[2].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[3].vect_u8;
//             tmp[3].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);
//             AFFINE_ENCODING(tmp, tmp, ctx->D_F4[i + 2], ctx->D_E4[i + 2], ctx->D_V[i + 2]);

//             state1[8].vect_u8 = state2[8].vect_u8 ^ tmp[0].vect_u8;
//             state1[9].vect_u8 = state2[9].vect_u8 ^ tmp[1].vect_u8;
//             state1[10].vect_u8 = state2[10].vect_u8 ^ tmp[2].vect_u8;
//             state1[11].vect_u8 = state2[11].vect_u8 ^ tmp[3].vect_u8;

//             //round4
//             AFFINE_ENCODING(state1     , state2     , ctx->M0_F4[i + 3], ctx->M0_E4[i + 3], ctx->M0_V[i + 3]);
//             AFFINE_ENCODING(state1 +  4, state2 +  4, ctx->M1_F4[i + 3], ctx->M1_E4[i + 3], ctx->M1_V[i + 3]);
//             AFFINE_ENCODING(state1 +  8, state2 +  8, ctx->M2_F4[i + 3], ctx->M2_E4[i + 3], ctx->M2_V[i + 3]);
            
//             AFFINE_ENCODING(state1 + 12, state2 + 12, ctx->C_F4[i + 3], ctx->C_E4[i + 3], ctx->C_V[i + 3]);
          
//             tmp[0].vect_u8 = state2[0].vect_u8 ^ state2[4].vect_u8 ^ state2[8].vect_u8;
//             tmp[1].vect_u8 = state2[1].vect_u8 ^ state2[5].vect_u8 ^ state2[9].vect_u8;
//             tmp[2].vect_u8 = state2[2].vect_u8 ^ state2[6].vect_u8 ^ state2[10].vect_u8;
//             tmp[3].vect_u8 = state2[3].vect_u8 ^ state2[7].vect_u8 ^ state2[11].vect_u8;

//             tmp_8x16 = tmp[0].vect_u8;
//             tmp[0].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[0].vect_u8 = veorq_u8(tmp[0].vect_u8, tmp1_8x16);
            

//             tmp_8x16 = tmp[1].vect_u8;
//             tmp[1].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16);  //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[1].vect_u8 = veorq_u8(tmp[1].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[2].vect_u8;
//             tmp[2].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[2].vect_u8 = veorq_u8(tmp[2].vect_u8, tmp1_8x16);

//             tmp_8x16 = tmp[3].vect_u8;
//             tmp[3].vect_u8 = vqtbl4q_u8(Table[0], tmp_8x16); //第一次查表

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[1], tmp_8x16);  //第二次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[2], tmp_8x16);  //第三次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);

//             tmp_8x16 = vsubq_u8(tmp_8x16, dec);
//             tmp1_8x16 = vqtbl4q_u8(Table[3], tmp_8x16);  //第四次查表
//             tmp[3].vect_u8 = veorq_u8(tmp[3].vect_u8, tmp1_8x16);
//             AFFINE_ENCODING(tmp, tmp, ctx->D_F4[i + 2], ctx->D_E4[i + 2], ctx->D_V[i + 2]);

//             state1[8].vect_u8 = state2[8].vect_u8 ^ tmp[0].vect_u8;
//             state1[9].vect_u8 = state2[9].vect_u8 ^ tmp[1].vect_u8;
//             state1[10].vect_u8 = state2[10].vect_u8 ^ tmp[2].vect_u8;
//             state1[11].vect_u8 = state2[11].vect_u8 ^ tmp[3].vect_u8;
            
//             AFFINE_ENCODING(tmp, tmp, ctx->D_F4[i + 3], ctx->D_E4[i + 3], ctx->D_V[i + 3]);

//             state1[12].vect_u8 = state2[12].vect_u8 ^ tmp[0].vect_u8;
//             state1[13].vect_u8 = state2[13].vect_u8 ^ tmp[1].vect_u8;
//             state1[14].vect_u8 = state2[14].vect_u8 ^ tmp[2].vect_u8;
//             state1[15].vect_u8 = state2[15].vect_u8 ^ tmp[3].vect_u8;
//         }
        
//         AFFINE_ENCODING(state1     , state1     , ctx->FE_F4[3], ctx->FE_E4[3], ctx->FE_V[3]);
//         AFFINE_ENCODING(state1 +  4, state1 +  4, ctx->FE_F4[2], ctx->FE_E4[2], ctx->FE_V[2]);
//         AFFINE_ENCODING(state1 +  8, state1 +  8, ctx->FE_F4[1], ctx->FE_E4[1], ctx->FE_V[1]);
//         AFFINE_ENCODING(state1 + 12, state1 + 12, ctx->FE_F4[0], ctx->FE_E4[0], ctx->FE_V[0]);
//         // dump_hex(state1,512);
//         // 提取数据和反序变换  
//         uint32_t tmp_32;
//         DATA_PACK(state1);
//         for (size_t i = 0; i < 16; i++)
//         {
//             uint32x2_t high = vget_high_u32(state1[i].vect_u32);
//             uint32x2_t low = vget_low_u32(state1[i].vect_u32);
//             high = vrev64_u32(high);
//             low = vrev64_u32(low);
//             state1[i].vect_u32 = vcombine_u32(high, low);
//         }
        
//         memcpy(OUT,state1,256);
//         return 1;
//     }

// int wbsm4_se_neon_ecb_encrypt(const uint8_t* inputb, uint8_t* outputb, size_t size, wbsm4_se_neon_context *ctx)
//     {
//         uint8_t tmp_input[256] = {0};
//         uint8_t tmp_output[256] = {0};
//         memset(outputb,0,size);
//         uint8_t* out = outputb;
//         uint8_t* in = inputb;
        
//         while(size > 0)
//         {
//             if(size < 256)
//             {
//                 memset(tmp_input, 0, 256);
//                 memcpy(tmp_input, in, size);
        
//                 wbsm4_se_neon_encrypt(tmp_input, tmp_output, ctx);

//                 memcpy(out, tmp_output, size);
//                 size = 0;
//             }
//             else
//             {
//                 memcpy(tmp_input, in, 256);
    
//                 wbsm4_se_neon_encrypt(tmp_input, tmp_output, ctx);

//                 memcpy(out, tmp_output, 256);

//                 size -= 256;
//                 out += 256;
//                 in += 256;
//             }
//         }
//         return 1;
//     }

// //int wbsm4_se_decrypt(const unsigned char *input, unsigned char *output, wbsm4_se_context *ctx) {
// //    return wbsm4_se_encrypt(input, output, ctx);
// //}
