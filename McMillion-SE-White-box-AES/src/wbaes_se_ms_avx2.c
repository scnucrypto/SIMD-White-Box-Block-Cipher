#include "wbaes_se_ms_avx2.h"

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%32==0) printf("\n");
    }
    // printf("\n");
}

wbaes_se_ms_avx2_context * wbaes_se_ms_avx2_context_init(){
    wbaes_se_ms_avx2_context *ctx = malloc(sizeof(wbaes_se_ms_avx2_context));
    if (ctx == NULL) {
        goto cleanup;
    }
    memset(ctx, 0, sizeof(wbaes_se_ms_avx2_context));
    return ctx;
cleanup:
    return NULL;
}

void wbaes_se_ms_avx2_context_free(wbaes_se_ms_avx2_context *ctx) {
    memset(ctx, 0, sizeof(wbaes_se_ms_avx2_context));
}
// todo 11.23有问题
void MatrixdivM128to4(M128 mat128, M4 m4[32][32])
{
    uint64_t m[2][4] = {
        {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
        {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
    };
    __m256i M0,mask[2],tmp,swap;
    uint8_t first4[128][16] = {0};
    uint8_t second4[128][16] = {0};
    mask[0] = _mm256_loadu_si256((const __m256i *)m[0]);
    mask[1] = _mm256_loadu_si256((const __m256i *)m[1]);
    swap = _mm256_setr_epi8(7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8);
    for (size_t i = 0; i < 64; i++)
    {
        M0 = _mm256_loadu_si256((const __m256i *)mat128.M + i);
        M0 = _mm256_shuffle_epi8(M0,swap);
        // printf("load:\n");
        // dump_hex(&M0,32);
        tmp = _mm256_and_si256(M0,mask[0]);
        tmp = _mm256_srli_epi32(tmp,4);
        _mm256_storeu_si256((__m256i*)first4 + i, tmp);

        tmp = _mm256_and_si256(M0,mask[1]);
        _mm256_storeu_si256((__m256i*)second4 + i, tmp);
    }
    
    //将first4、second4中的数据放进data
    for (size_t i = 0; i < 32; i++)
    {
        for (size_t j = 0; j < 32; j+=2)
        {
            m4[i][j].M[0] = first4[4 * i    ][j / 2];
            m4[i][j].M[1] = first4[4 * i + 1][j / 2];
            m4[i][j].M[2] = first4[4 * i + 2][j / 2];
            m4[i][j].M[3] = first4[4 * i + 3][j / 2];
            
            m4[i][j + 1].M[0] = second4[4 * i    ][j / 2];
            m4[i][j + 1].M[1] = second4[4 * i + 1][j / 2];
            m4[i][j + 1].M[2] = second4[4 * i + 2][j / 2];
            m4[i][j + 1].M[3] = second4[4 * i + 3][j / 2];
        }
    }
    
    
}

uint8_t GetMatMulVecM4(M4 Mat, uint8_t Vec){
    V4 ret, tmp;
    tmp.V = Vec;
    MatMulVecM4(Mat, tmp, &ret);
    return ret.V;
}

void GEN_TABLE_DATA_F4(M4 TMP[32][32], uint8_t index, uint8_t data[16][16][16]) {
	// data 的 ij 是 index 所乘8*8矩阵在大矩阵中的位置
    for (size_t i = 0; i < 16; i++)
	{
		for (size_t j = 0; j < 16; j++)
        {
            data[j][i][index] = (GetMatMulVecM4(TMP[i * 2][j * 2], index) << 4) + GetMatMulVecM4(TMP[i * 2 + 1][j * 2], index);
			// printf("F4: i = %d  j = %d , index * [%d][%d] + index * [%d][%d] \n",i,j,i * 2,j * 2,i * 2 + 1,j * 2);
			
        }
		
	}
	// dump_hex(data,16*16*16);
}

void GEN_TABLE_DATA_E4(M4 TMP[32][32], uint8_t index, uint8_t data[16][16][16]) {
	// data 的 ij 是 index 所乘8*8矩阵在大矩阵中的位置
    for (size_t i = 0; i < 16; i++)
	{
		for (size_t j = 0; j < 16; j++)
        {
            data[j][i][index] = (GetMatMulVecM4(TMP[i * 2][j * 2 + 1], index) << 4) + GetMatMulVecM4(TMP[i * 2 + 1][j * 2 + 1], index);
			// printf("E4: i = %d  j = %d , index * [%d][%d] + index * [%d][%d] \n",i,j,i * 2,j * 2 + 1,i * 2 + 1,j * 2 + 1);
        }
	}
}

void AFFINE_ENCODING(__m256i IN[16], __m256i OUT[16], uint8_t table_f4[16][16][16], uint8_t table_e4[16][16][16], uint8_t table_vec[16]) {
        __m256i input_f4[16], input_e4[16];
		// __m256i test_out[16];
        __m256i tmp_f4,tmp_e4;
        __m128i tmp_128_mat;// 表的大小只有128
        __m256i tmp_mat;
        __m256i tmp_vec;
        __m256i mask[2];
        uint64_t m[2][4] = {
            {0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0,0xf0f0f0f0f0f0f0f0},//取前4位
            {0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f,0x0f0f0f0f0f0f0f0f},//取后4位
        };
        mask[0] = _mm256_loadu_si256((__m256i *)m[0]);
        mask[1] = _mm256_loadu_si256((__m256i *)m[1]);
	
        for (size_t i = 0; i < 16; i++)//从明文中取4bit
        {
            input_f4[i] = _mm256_and_si256(mask[0],IN[i]);
            input_f4[i] = _mm256_srli_epi32(input_f4[i],4);
            input_e4[i] = _mm256_and_si256(mask[1],IN[i]);
        }
        // printf("input:\n");
        // dump_hex(IN,512);
        // printf("input f4:\n");
        // dump_hex(input_f4,512);
        // printf("input e4:\n");
        // dump_hex(input_e4,512);
       
		// 16个字节明文循环
        for (size_t i = 0; i < 16; i++)
        {
			OUT[i] = _mm256_setzero_si256(); 
            // printf("out:%d\n",i);
            // dump_hex(&OUT[i],32);
            for (size_t j = 0; j < 16; j++)
			{
			
                tmp_128_mat = _mm_loadu_si128(table_f4[j][i]);
				tmp_mat = _mm256_setr_m128i(tmp_128_mat, tmp_128_mat);
				tmp_f4 = _mm256_shuffle_epi8(tmp_mat, input_f4[j]);// 4-8查表
                
             
				tmp_128_mat = _mm_loadu_si128(table_e4[j][i]);
				tmp_mat = _mm256_setr_m128i(tmp_128_mat, tmp_128_mat);
				tmp_e4 = _mm256_shuffle_epi8(tmp_mat, input_e4[j]);// 4-8查表
        
				OUT[i] = OUT[i] ^ tmp_e4 ^ tmp_f4;
           
			}
			
        }
        // printf("before vec\n");
        // dump_hex(OUT,512);
        for (size_t i = 0; i < 16; i++)
        {
			tmp_vec = _mm256_set1_epi8(table_vec[i]);
           	OUT[i] = OUT[i] ^ tmp_vec;
			
        }
        // dump_hex(OUT,512);
	
}

void DATA_PACK( __m256i OUT[16]){
    // printf("\npack input:\n");
    // dump_hex(OUT,512);
    __m256i state[16];
    for(int i=0;i<8;i++){
            state[i] = _mm256_unpacklo_epi8(OUT[2*i],OUT[2*i+1]);
            state[i+8] = _mm256_unpackhi_epi8(OUT[2*i],OUT[2*i+1]);
        }
        // printf("\nOUT-after:\n");
        // dump_hex(state,256);
        OUT[0] = _mm256_unpacklo_epi16(state[0],state[1]);
        OUT[1] = _mm256_unpacklo_epi16(state[2],state[3]);
        OUT[2] = _mm256_unpacklo_epi16(state[4],state[5]);
        OUT[3] = _mm256_unpacklo_epi16(state[6],state[7]);

        OUT[4] = _mm256_unpackhi_epi16(state[0],state[1]);
        OUT[5] = _mm256_unpackhi_epi16(state[2],state[3]);
        OUT[6] = _mm256_unpackhi_epi16(state[4],state[5]);
        OUT[7] = _mm256_unpackhi_epi16(state[6],state[7]);
        // printf("\nOUT(对lo进行操作):\n");
        // dump_hex(OUT,128);  

        OUT[8] = _mm256_unpacklo_epi16(state[8],state[9]);
        OUT[9] = _mm256_unpacklo_epi16(state[10],state[11]);
        OUT[10] = _mm256_unpacklo_epi16(state[12],state[13]);
        OUT[11] = _mm256_unpacklo_epi16(state[14],state[15]);

        OUT[12] = _mm256_unpackhi_epi16(state[8],state[9]);
        OUT[13] = _mm256_unpackhi_epi16(state[10],state[11]);
        OUT[14] = _mm256_unpackhi_epi16(state[12],state[13]);
        OUT[15] = _mm256_unpackhi_epi16(state[14],state[15]);  
        // printf("\nOUT(对hi进行操作):\n");
        // dump_hex(OUT+8,128);  


        state[0] = _mm256_unpacklo_epi32(OUT[0],OUT[1]);//0-1
        state[1] = _mm256_unpacklo_epi32(OUT[2],OUT[3]);
        state[2] = _mm256_unpacklo_epi32(OUT[4],OUT[5]);//4-5
        state[3] = _mm256_unpacklo_epi32(OUT[6],OUT[7]);
        
        state[4] = _mm256_unpackhi_epi32(OUT[0],OUT[1]);//2-3
        state[5] = _mm256_unpackhi_epi32(OUT[2],OUT[3]);
        state[6] = _mm256_unpackhi_epi32(OUT[4],OUT[5]);//6-7
        state[7] = _mm256_unpackhi_epi32(OUT[6],OUT[7]);
        // printf("\nstate:\n");
        // dump_hex(state,128); 

        state[8] = _mm256_unpacklo_epi32(OUT[8],OUT[9]);//0-1
        state[9] = _mm256_unpacklo_epi32(OUT[10],OUT[11]);
        state[10] = _mm256_unpacklo_epi32(OUT[12],OUT[13]);//4-5
        state[11] = _mm256_unpacklo_epi32(OUT[14],OUT[15]);
        
        state[12] = _mm256_unpackhi_epi32(OUT[8],OUT[9]);//2-3
        state[13] = _mm256_unpackhi_epi32(OUT[10],OUT[11]);
        state[14] = _mm256_unpackhi_epi32(OUT[12],OUT[13]);//6-7
        state[15] = _mm256_unpackhi_epi32(OUT[14],OUT[15]);
        // printf("\nstate:\n");
        // dump_hex(state+8,128);  
        
        OUT[0] = _mm256_unpacklo_epi64(state[0],state[1]);
        OUT[1] = _mm256_unpackhi_epi64(state[0],state[1]);

        OUT[2] = _mm256_unpacklo_epi64(state[4],state[5]);
        OUT[3] = _mm256_unpackhi_epi64(state[4],state[5]);

        OUT[4] = _mm256_unpacklo_epi64(state[2],state[3]);
        OUT[5] = _mm256_unpackhi_epi64(state[2],state[3]);

        OUT[6] = _mm256_unpacklo_epi64(state[6],state[7]);
        OUT[7] = _mm256_unpackhi_epi64(state[6],state[7]);


        OUT[8] = _mm256_unpacklo_epi64(state[8],state[9]);
        OUT[9] = _mm256_unpackhi_epi64(state[8],state[9]);

        OUT[10] = _mm256_unpacklo_epi64(state[12],state[13]);
        OUT[11] = _mm256_unpackhi_epi64(state[12],state[13]);

        OUT[12] = _mm256_unpacklo_epi64(state[10],state[11]);
        OUT[13] = _mm256_unpackhi_epi64(state[10],state[11]);

        OUT[14] = _mm256_unpacklo_epi64(state[14],state[15]);
        OUT[15] = _mm256_unpackhi_epi64(state[14],state[15]);
//         printf("\npack output:\n");
//         dump_hex(OUT,512);
}

int wbaes_se_ms_avx2_gen_table(wbaes_se_ms_avx2_context *ctx, const uint8_t *key) {

	wbaes_se_ms_context aes_key;
    wbaes_se_ms_gen_table(&aes_key,key);
    M4 TMP[32][32];

	for (size_t i = 0; i < 11; i++)
	{
        // 测试
		MatrixdivM128to4(aes_key.AL[i].Mat,TMP);
        // if(i == 1){
        //     printf("before div:");
        //     printM128(aes_key.P[i].Mat);
        //     printf("after div:");
        //     for (size_t i = 0; i < 16; i++)
        //     {
        //         for (size_t j = 0; j < 32; j++)
        //         {
        //             printf("row:%d, col:%d :",i,j);
        //             printM4(TMP[i][j]);
        //         } 
        //     }
        // }
        for (size_t j = 0; j < 16; j++)
        {
            GEN_TABLE_DATA_F4(TMP,j,ctx->AL_M_F4[i]);
            GEN_TABLE_DATA_E4(TMP,j,ctx->AL_M_E4[i]);
        }	
		PUT64(aes_key.AL[i].Vec.V[0],ctx->AL_V[i]);
        PUT64(aes_key.AL[i].Vec.V[1],ctx->AL_V[i]+8);

	}
    // todo test
    for (size_t i = 0; i < 2; i++)
	{
		MatrixdivM128to4(aes_key.P[i].Mat,TMP);
        
        for (size_t j = 0; j < 16; j++)
        {
            GEN_TABLE_DATA_F4(TMP,j,ctx->P_M_F4[i]);
            GEN_TABLE_DATA_E4(TMP,j,ctx->P_M_E4[i]);
        }	
		PUT64(aes_key.P[i].Vec.V[0],ctx->P_V[i]);
        PUT64(aes_key.P[i].Vec.V[1],ctx->P_V[i]+8);

        MatrixdivM128to4(aes_key.P_inv[i].Mat,TMP);
        for (size_t j = 0; j < 16; j++)
        {
            GEN_TABLE_DATA_F4(TMP,j,ctx->P_inv_M_F4[i]);
            GEN_TABLE_DATA_E4(TMP,j,ctx->P_inv_M_E4[i]);
        }	
		PUT64(aes_key.P_inv[i].Vec.V[0],ctx->P_inv_V[i]);
        PUT64(aes_key.P_inv[i].Vec.V[1],ctx->P_inv_V[i]+8);
	}	
	// dump_hex(ctx->AL_M_F4,35*16*16*16);
		return 1;
}



int wbaes_se_ms_avx2_encrypt(const uint8_t IN[512], uint8_t OUT[512], wbaes_se_ms_avx2_context *ctx) {
   
	__m256i state1[16];
	// __m256i state2[16];
	__m256i mask;
	mask = _mm256_set1_epi32(0xFF);
	memcpy(state1, IN, 512);
	DATA_PACK(state1);
	// dump_hex(state1,512);
    AFFINE_ENCODING(state1, state1, ctx->P_M_F4[0], ctx->P_M_E4[0], ctx->P_V[0]);
    // printf("after external encoding:\n");
    // dump_hex(state1,512);
 
	for (size_t i = 0; i < 10; i++)
	{
        AFFINE_ENCODING(state1, state1, ctx->AL_M_F4[i], ctx->AL_M_E4[i], ctx->AL_V[i]);
        printf("after AL:\n");
        dump_hex(state1,512);
        for (size_t j = 0; j < 16; j++)
        {
            state1[j] = _mm256_i32gather_epi32((const int*)T0, _mm256_and_si256(mask, state1[j]), 4)
                    ^ _mm256_i32gather_epi32((const int*)T1, _mm256_and_si256(mask, _mm256_srli_epi32(state1[j], 8)), 4)
                    ^ _mm256_i32gather_epi32((const int*)T2, _mm256_and_si256(mask, _mm256_srli_epi32(state1[j], 16)), 4) 
                    ^ _mm256_i32gather_epi32((const int*)T3, _mm256_and_si256(mask, _mm256_srli_epi32(state1[j], 24)), 4);
        }
        printf("after SBOX:\n");
        dump_hex(state1,512);
        
	}
 
    AFFINE_ENCODING(state1, state1, ctx->AL_M_F4[10], ctx->AL_M_E4[10], ctx->AL_V[10]);

    AFFINE_ENCODING(state1, state1, ctx->P_inv_M_F4[1], ctx->P_inv_M_E4[1], ctx->P_inv_V[1]);
	DATA_PACK(state1);
	
	memcpy(OUT,state1,512);

    return 1;
}

int wbaes_se_ms_avx2_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_ms_avx2_context *ctx) {
    	uint8_t tmp_input[512] = {0};
        uint8_t tmp_output[512] = {0};
        memset(output,0,len);
        uint8_t* out = output;
        uint8_t* in = input;
        
        while(len > 0)
        {
            if(len < 512)
            {
                memset(tmp_input, 0, 512);
                memcpy(tmp_input, in, len);
        
                wbaes_se_ms_avx2_encrypt(tmp_input, tmp_output, ctx);
				
                memcpy(out, tmp_output, len);
				
                len = 0;
            }
            else
            {
                memcpy(tmp_input, in, 512);
    
                wbaes_se_ms_avx2_encrypt(tmp_input, tmp_output, ctx);

                memcpy(out, tmp_output, 512);

                len -= 512;
                out += 512;
                in += 512;
            }
        }
        return 1;
}