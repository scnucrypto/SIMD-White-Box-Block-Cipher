#include <string.h>
#include <stdio.h>
#include "speed.h"
#include "wbsm4_se_avx2.h"

unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char aad[23] = {
        0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x03,0x7f,0xff,0xff,0xfe,0x89,0x2c,0x38,0x00,
        0x00,0x5c,0x36,0x5c,0x36,0x5c,0x36
};
unsigned char iv_enc[16] = {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
        0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
};
uint8_t tag[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbsm4_se_avx2_context *ctx;
gcm_context *gcm_ctx;
__m256i mask;
__m256i test[4];
Aff32 testA32,testA32INV;
uint32_t test32 = 0x01234567;

uint8_t OUT[256] = {0};
uint8_t OUT1[256] = {0};
__m128i tmp[16],tmp1[16];

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}

size_t test_affine_avx2_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        AFFINE_ENCODING(test, test, ctx->D_F4[0], ctx->D_E4[0], ctx->D_V[0]);
    }
    return count;
}

size_t test_affine_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        test32 = affineU32(testA32,test32);
    }
    return count;
}

size_t test_wbsm4_se_avx2_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_avx2_ecb_encrypt(input, output, size, ctx);
    }
    
    return count;
}

size_t test_wbsm4_se_avx2_ctr_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_avx2_ctr_encrypt(input, output, size, iv_enc, ctx);
    }
    
    return count;
}

size_t test_wbsm4_se_avx2_gcm_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_avx2_gcm_encrypt(gcm_ctx, input, output, size, ctx);
    }
    
    return count;
}


size_t test_sbox_avx_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        test[0] = _mm256_i32gather_epi32((const int*)T0, _mm256_and_si256(mask, test[0]), 4)
                ^ _mm256_i32gather_epi32((const int*)T1, _mm256_and_si256(mask, _mm256_srli_epi32(test[0], 8)), 4)
                ^ _mm256_i32gather_epi32((const int*)T2, _mm256_and_si256(mask, _mm256_srli_epi32(test[0], 16)), 4) 
                ^ _mm256_i32gather_epi32((const int*)T3, _mm256_and_si256(mask, _mm256_srli_epi32(test[0], 24)), 4);

        test[1] = _mm256_i32gather_epi32((const int*)T0, _mm256_and_si256(mask, test[1]), 4)
                ^ _mm256_i32gather_epi32((const int*)T1, _mm256_and_si256(mask, _mm256_srli_epi32(test[1], 8)), 4)
                ^ _mm256_i32gather_epi32((const int*)T2, _mm256_and_si256(mask, _mm256_srli_epi32(test[1], 16)), 4) 
                ^ _mm256_i32gather_epi32((const int*)T3, _mm256_and_si256(mask, _mm256_srli_epi32(test[1], 24)), 4);

        test[2] = _mm256_i32gather_epi32((const int*)T0, _mm256_and_si256(mask, test[2]), 4)
                ^ _mm256_i32gather_epi32((const int*)T1, _mm256_and_si256(mask, _mm256_srli_epi32(test[2], 8)), 4)
                ^ _mm256_i32gather_epi32((const int*)T2, _mm256_and_si256(mask, _mm256_srli_epi32(test[2], 16)), 4) 
                ^ _mm256_i32gather_epi32((const int*)T3, _mm256_and_si256(mask, _mm256_srli_epi32(test[2], 24)), 4);

        test[3] = _mm256_i32gather_epi32((const int*)T0, _mm256_and_si256(mask, test[3]), 4)
                ^ _mm256_i32gather_epi32((const int*)T1, _mm256_and_si256(mask, _mm256_srli_epi32(test[3], 8)), 4)
                ^ _mm256_i32gather_epi32((const int*)T2, _mm256_and_si256(mask, _mm256_srli_epi32(test[3], 16)), 4) 
                ^ _mm256_i32gather_epi32((const int*)T3, _mm256_and_si256(mask, _mm256_srli_epi32(test[3], 24)), 4);
    }
    
    return count;
}

size_t test_unpack_loop(){
    
   
    size_t count = 0;
    
    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        for(int i=0;i<8;i++){
            tmp1[i] = _mm_unpacklo_epi8(tmp[2*i],tmp[2*i+1]);
            tmp1[i+8] = _mm_unpackhi_epi8(tmp[2*i],tmp[2*i+1]);
        }
        // printf("\ntmp_lo:\n");
        // dump_hex(tmp_lo,128);
        // printf("\ntmp_hi:\n");
        // dump_hex(tmp_hi,128);
        tmp[0] = _mm_unpacklo_epi16(tmp1[0],tmp1[1]);
        tmp[1] = _mm_unpacklo_epi16(tmp1[2],tmp1[3]);
        tmp[2] = _mm_unpacklo_epi16(tmp1[4],tmp1[5]);
        tmp[3] = _mm_unpacklo_epi16(tmp1[6],tmp1[7]);

        tmp[4] = _mm_unpackhi_epi16(tmp1[0],tmp1[1]);
        tmp[5] = _mm_unpackhi_epi16(tmp1[2],tmp1[3]);
        tmp[6] = _mm_unpackhi_epi16(tmp1[4],tmp1[5]);
        tmp[7] = _mm_unpackhi_epi16(tmp1[6],tmp1[7]);
        // printf("\ntmp(对lo进行操作):\n");
        // dump_hex(tmp,128);  

        tmp[8] = _mm_unpacklo_epi16(tmp1[8],tmp1[9]);
        tmp[9] = _mm_unpacklo_epi16(tmp1[10],tmp1[11]);
        tmp[10] = _mm_unpacklo_epi16(tmp1[12],tmp1[13]);
        tmp[11] = _mm_unpacklo_epi16(tmp1[14],tmp1[15]);

        tmp[12] = _mm_unpackhi_epi16(tmp1[8],tmp1[9]);
        tmp[13] = _mm_unpackhi_epi16(tmp1[10],tmp1[11]);
        tmp[14] = _mm_unpackhi_epi16(tmp1[12],tmp1[13]);
        tmp[15] = _mm_unpackhi_epi16(tmp1[14],tmp1[15]);  
        // printf("\ntmp(对hi进行操作):\n");
        // dump_hex(tmp+8,128);  


        tmp1[0] = _mm_unpacklo_epi32(tmp[0],tmp[1]);//0-1
        tmp1[1] = _mm_unpacklo_epi32(tmp[2],tmp[3]);
        tmp1[2] = _mm_unpacklo_epi32(tmp[4],tmp[5]);//4-5
        tmp1[3] = _mm_unpacklo_epi32(tmp[6],tmp[7]);
        
        tmp1[4] = _mm_unpackhi_epi32(tmp[0],tmp[1]);//2-3
        tmp1[5] = _mm_unpackhi_epi32(tmp[2],tmp[3]);
        tmp1[6] = _mm_unpackhi_epi32(tmp[4],tmp[5]);//6-7
        tmp1[7] = _mm_unpackhi_epi32(tmp[6],tmp[7]);
        // printf("\ntmp1:\n");
        // dump_hex(tmp1,128); 

        tmp1[8] = _mm_unpacklo_epi32(tmp[8],tmp[9]);//0-1
        tmp1[9] = _mm_unpacklo_epi32(tmp[10],tmp[11]);
        tmp1[10] = _mm_unpacklo_epi32(tmp[12],tmp[13]);//4-5
        tmp1[11] = _mm_unpacklo_epi32(tmp[14],tmp[15]);
        
        tmp1[12] = _mm_unpackhi_epi32(tmp[8],tmp[9]);//2-3
        tmp1[13] = _mm_unpackhi_epi32(tmp[10],tmp[11]);
        tmp1[14] = _mm_unpackhi_epi32(tmp[12],tmp[13]);//6-7
        tmp1[15] = _mm_unpackhi_epi32(tmp[14],tmp[15]);
        // printf("\ntmp1:\n");
        // dump_hex(tmp1+8,128);  
        
        tmp[0] = _mm_unpacklo_epi64(tmp1[0],tmp1[1]);
        tmp[1] = _mm_unpackhi_epi64(tmp1[0],tmp1[1]);

        tmp[2] = _mm_unpacklo_epi64(tmp1[4],tmp1[5]);
        tmp[3] = _mm_unpackhi_epi64(tmp1[4],tmp1[5]);

        tmp[4] = _mm_unpacklo_epi64(tmp1[2],tmp1[3]);
        tmp[5] = _mm_unpackhi_epi64(tmp1[2],tmp1[3]);

        tmp[6] = _mm_unpacklo_epi64(tmp1[6],tmp1[7]);
        tmp[7] = _mm_unpackhi_epi64(tmp1[6],tmp1[7]);


        tmp[8] = _mm_unpacklo_epi64(tmp1[8],tmp1[9]);
        tmp[9] = _mm_unpackhi_epi64(tmp1[8],tmp1[9]);

        tmp[10] = _mm_unpacklo_epi64(tmp1[12],tmp1[13]);
        tmp[11] = _mm_unpackhi_epi64(tmp1[12],tmp1[13]);

        tmp[12] = _mm_unpacklo_epi64(tmp1[10],tmp1[11]);
        tmp[13] = _mm_unpackhi_epi64(tmp1[10],tmp1[11]);

        tmp[14] = _mm_unpacklo_epi64(tmp1[14],tmp1[15]);
        tmp[15] = _mm_unpackhi_epi64(tmp1[14],tmp1[15]);
        for (size_t i = 0; i < 16; i++)
        {
            tmp[i] = _mm_shuffle_epi32(tmp[i],27);// 27 = 0b00011011 即反序变换
        }
        
        uint8_t *output = (uint8_t*)tmp;
        memcpy(OUT,output,256);
        
    }

  
    return count;
}

size_t test_extract_loop(){
    size_t count = 0;
   
    for (count = 0; count < 0xffffffffffffffff && run; count++)
    {
       for (size_t j = 0; j < 4; j++)
        {
            OUT[j]  = _mm_extract_epi8(tmp[j + 12], 0);
            OUT[j + 16]  = _mm_extract_epi8(tmp[j + 12], 1);
            OUT[j + 32]  = _mm_extract_epi8(tmp[j + 12], 2);
            OUT[j + 48]  = _mm_extract_epi8(tmp[j + 12], 3);
            OUT[j + 64]  = _mm_extract_epi8(tmp[j + 12], 4);
            OUT[j + 80]  = _mm_extract_epi8(tmp[j + 12], 5);
            OUT[j + 96]  = _mm_extract_epi8(tmp[j + 12], 6);
            OUT[j + 112]  = _mm_extract_epi8(tmp[j + 12], 7);
            OUT[j + 128]  = _mm_extract_epi8(tmp[j + 12], 8);
            OUT[j + 144]  = _mm_extract_epi8(tmp[j + 12], 9);
            OUT[j + 160]  = _mm_extract_epi8(tmp[j + 12], 10);
            OUT[j + 176]  = _mm_extract_epi8(tmp[j + 12], 11);
            OUT[j + 192]  = _mm_extract_epi8(tmp[j + 12], 12);
            OUT[j + 208]  = _mm_extract_epi8(tmp[j + 12], 13);
            OUT[j + 224]  = _mm_extract_epi8(tmp[j + 12], 14);
            OUT[j + 240]  = _mm_extract_epi8(tmp[j + 12], 15);
        
        }
        for (size_t j = 4; j < 8; j++)
        {
            OUT[j]  = _mm_extract_epi8(tmp[j + 4], 0);
            OUT[j + 16]  = _mm_extract_epi8(tmp[j + 4], 1);
            OUT[j + 32]  = _mm_extract_epi8(tmp[j + 4], 2);
            OUT[j + 48]  = _mm_extract_epi8(tmp[j + 4], 3);
            OUT[j + 64]  = _mm_extract_epi8(tmp[j + 4], 4);
            OUT[j + 80]  = _mm_extract_epi8(tmp[j + 4], 5);
            OUT[j + 96]  = _mm_extract_epi8(tmp[j + 4], 6);
            OUT[j + 112]  = _mm_extract_epi8(tmp[j + 4], 7);
            OUT[j + 128]  = _mm_extract_epi8(tmp[j + 4], 8);
            OUT[j + 144]  = _mm_extract_epi8(tmp[j + 4], 9);
            OUT[j + 160]  = _mm_extract_epi8(tmp[j + 4], 10);
            OUT[j + 176]  = _mm_extract_epi8(tmp[j + 4], 11);
            OUT[j + 192]  = _mm_extract_epi8(tmp[j + 4], 12);
            OUT[j + 208]  = _mm_extract_epi8(tmp[j + 4], 13);
            OUT[j + 224]  = _mm_extract_epi8(tmp[j + 4], 14);
            OUT[j + 240]  = _mm_extract_epi8(tmp[j + 4], 15);
            
        }
        for (size_t j = 8; j < 12; j++)
        {
            OUT[j]  = _mm_extract_epi8(tmp[j - 4], 0);
            OUT[j + 16]  = _mm_extract_epi8(tmp[j - 4], 1);
            OUT[j + 32]  = _mm_extract_epi8(tmp[j - 4], 2);
            OUT[j + 48]  = _mm_extract_epi8(tmp[j - 4], 3);
            OUT[j + 64]  = _mm_extract_epi8(tmp[j - 4], 4);
            OUT[j + 80]  = _mm_extract_epi8(tmp[j - 4], 5);
            OUT[j + 96]  = _mm_extract_epi8(tmp[j - 4], 6);
            OUT[j + 112]  = _mm_extract_epi8(tmp[j - 4], 7);
            OUT[j + 128]  = _mm_extract_epi8(tmp[j - 4], 8);
            OUT[j + 144]  = _mm_extract_epi8(tmp[j - 4], 9);
            OUT[j + 160]  = _mm_extract_epi8(tmp[j - 4], 10);
            OUT[j + 176]  = _mm_extract_epi8(tmp[j - 4], 11);
            OUT[j + 192]  = _mm_extract_epi8(tmp[j - 4], 12);
            OUT[j + 208]  = _mm_extract_epi8(tmp[j - 4], 13);
            OUT[j + 224]  = _mm_extract_epi8(tmp[j - 4], 14);
            OUT[j + 240]  = _mm_extract_epi8(tmp[j - 4], 15);
            
        }
        for (size_t j = 12; j < 16; j++)
        {
            OUT[j]  = _mm_extract_epi8(tmp[j - 12], 0);
            OUT[j + 16]  = _mm_extract_epi8(tmp[j - 12], 1);
            OUT[j + 32]  = _mm_extract_epi8(tmp[j - 12], 2);
            OUT[j + 48]  = _mm_extract_epi8(tmp[j - 12], 3);
            OUT[j + 64]  = _mm_extract_epi8(tmp[j - 12], 4);
            OUT[j + 80]  = _mm_extract_epi8(tmp[j - 12], 5);
            OUT[j + 96]  = _mm_extract_epi8(tmp[j - 12], 6);
            OUT[j + 112]  = _mm_extract_epi8(tmp[j - 12], 7);
            OUT[j + 128]  = _mm_extract_epi8(tmp[j - 12], 8);
            OUT[j + 144]  = _mm_extract_epi8(tmp[j - 12], 9);
            OUT[j + 160]  = _mm_extract_epi8(tmp[j - 12], 10);
            OUT[j + 176]  = _mm_extract_epi8(tmp[j - 12], 11);
            OUT[j + 192]  = _mm_extract_epi8(tmp[j - 12], 12);
            OUT[j + 208]  = _mm_extract_epi8(tmp[j - 12], 13);
            OUT[j + 224]  = _mm_extract_epi8(tmp[j - 12], 14);
            OUT[j + 240]  = _mm_extract_epi8(tmp[j - 12], 15);
           
        }
      
    }
    
    return count;
}

size_t test_load_loop(){
    size_t count = 0;
   
    for (count = 0; count < 0xffffffffffffffff && run; count++)
    {
        uint8_t *output = (uint8_t*)tmp;
        memcpy(OUT1,output,256);
        for (size_t j = 0; j < 4; j++)
        {
            OUT[j]  = OUT1[j*16 + 192];
            OUT[j + 16]  = OUT1[j*16 + 193];
            OUT[j + 32]  = OUT1[j*16 + 194];
            OUT[j + 48]  = OUT1[j*16 + 195];
            OUT[j + 64]  = OUT1[j*16 + 196];
            OUT[j + 80]  = OUT1[j*16 + 197];
            OUT[j + 96]  = OUT1[j*16 + 198];
            OUT[j + 112]  = OUT1[j*16 + 199];
            OUT[j + 128]  = OUT1[j*16 + 200];
            OUT[j + 144]  = OUT1[j*16 + 201];
            OUT[j + 160]  = OUT1[j*16 + 202];
            OUT[j + 176]  = OUT1[j*16 + 203];
            OUT[j + 192]  = OUT1[j*16 + 204];
            OUT[j + 208]  = OUT1[j*16 + 205];
            OUT[j + 224]  = OUT1[j*16 + 206];
            OUT[j + 240]  = OUT1[j*16 + 207];
        
        }
        for (size_t j = 4; j < 8; j++)
        {
            OUT[j]  = OUT1[j*16 + 64];
            OUT[j + 16]  = OUT1[j*16 + 65];
            OUT[j + 32]  = OUT1[j*16 + 66];
            OUT[j + 48]  = OUT1[j*16 + 67];
            OUT[j + 64]  = OUT1[j*16 + 68];
            OUT[j + 80]  = OUT1[j*16 + 69];
            OUT[j + 96]  = OUT1[j*16 + 70];
            OUT[j + 112]  = OUT1[j*16 + 71];
            OUT[j + 128]  = OUT1[j*16 + 72];
            OUT[j + 144]  = OUT1[j*16 + 73];
            OUT[j + 160]  = OUT1[j*16 + 74];
            OUT[j + 176]  = OUT1[j*16 + 75];
            OUT[j + 192]  = OUT1[j*16 + 76];
            OUT[j + 208]  = OUT1[j*16 + 78];
            OUT[j + 224]  = OUT1[j*16 + 79];
            OUT[j + 240]  = OUT1[j*16 + 80];
            
        }
        for (size_t j = 8; j < 12; j++)
        {
            OUT[j]  = OUT1[j*16 - 64];
            OUT[j + 16]  = OUT1[j*16 - 63];
            OUT[j + 32]  = OUT1[j*16 - 62];
            OUT[j + 48]  = OUT1[j*16 - 61];
            OUT[j + 64]  = OUT1[j*16 - 60];
            OUT[j + 80]  = OUT1[j*16 - 59];
            OUT[j + 96]  = OUT1[j*16 - 58];
            OUT[j + 112]  = OUT1[j*16 - 57];
            OUT[j + 128]  = OUT1[j*16 - 56];
            OUT[j + 144]  = OUT1[j*16 - 55];
            OUT[j + 160]  = OUT1[j*16 - 54];
            OUT[j + 176]  = OUT1[j*16 - 53];
            OUT[j + 192]  = OUT1[j*16 - 52];
            OUT[j + 208]  = OUT1[j*16 - 51];
            OUT[j + 224]  = OUT1[j*16 - 50];
            OUT[j + 240]  = OUT1[j*16 - 49];
            
        }
        for (size_t j = 12; j < 16; j++)
        {
            OUT[j]  = OUT1[j*16 - 192];
            OUT[j + 16]  = OUT1[j*16 - 191];
            OUT[j + 32]  = OUT1[j*16 - 190];
            OUT[j + 48]  = OUT1[j*16 - 189];
            OUT[j + 64]  = OUT1[j*16 - 188];
            OUT[j + 80]  = OUT1[j*16 - 187];
            OUT[j + 96]  = OUT1[j*16 - 186];
            OUT[j + 112]  = OUT1[j*16 - 185];
            OUT[j + 128]  = OUT1[j*16 - 184];
            OUT[j + 144]  = OUT1[j*16 - 183];
            OUT[j + 160]  = OUT1[j*16 - 182];
            OUT[j + 176]  = OUT1[j*16 - 181];
            OUT[j + 192]  = OUT1[j*16 - 180];
            OUT[j + 208]  = OUT1[j*16 - 179];
            OUT[j + 224]  = OUT1[j*16 - 178];
            OUT[j + 240]  = OUT1[j*16 - 177];
           
        }
        // dump_hex(OUT,256);
    }
    
    return count;
}

size_t test_set_loop(){
    
   
    size_t count = 0;
    
    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
         for (size_t i = 0; i < 16; i++)// TODO 是否直接全部装载，而是留几个用于tmp
        {
            tmp[i] = _mm_setr_epi8(input[0 + i], input[16 + i], input[32 + i], input[48 + i], 
                                    input[64 + i], input[80 + i], input[96 + i], input[112 + i], 
                                    input[128 + i], input[144 + i], input[160 + i], input[176 + i],
                                    input[192 + i], input[208 + i], input[224 + i], input[240 + i]);
        }
    }
    return count;
}

size_t test_unpack_set_loop(){
    
   
    size_t count = 0;
    
    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        uint8_t *output = (uint8_t*)tmp;
        memcpy(output,input,256);
        // printf("\ntmp-before:\n");
        // dump_hex(tmp,256);
        for(int i=0;i<8;i++){
            tmp1[i] = _mm_unpacklo_epi8(tmp[2*i],tmp[2*i+1]);
            tmp1[i+8] = _mm_unpackhi_epi8(tmp[2*i],tmp[2*i+1]);
        }
        // printf("\ntmp-after:\n");
        // dump_hex(tmp1,256);
        tmp[0] = _mm_unpacklo_epi16(tmp1[0],tmp1[1]);
        tmp[1] = _mm_unpacklo_epi16(tmp1[2],tmp1[3]);
        tmp[2] = _mm_unpacklo_epi16(tmp1[4],tmp1[5]);
        tmp[3] = _mm_unpacklo_epi16(tmp1[6],tmp1[7]);

        tmp[4] = _mm_unpackhi_epi16(tmp1[0],tmp1[1]);
        tmp[5] = _mm_unpackhi_epi16(tmp1[2],tmp1[3]);
        tmp[6] = _mm_unpackhi_epi16(tmp1[4],tmp1[5]);
        tmp[7] = _mm_unpackhi_epi16(tmp1[6],tmp1[7]);
        // printf("\ntmp(对lo进行操作):\n");
        // dump_hex(tmp,128);  

        tmp[8] = _mm_unpacklo_epi16(tmp1[8],tmp1[9]);
        tmp[9] = _mm_unpacklo_epi16(tmp1[10],tmp1[11]);
        tmp[10] = _mm_unpacklo_epi16(tmp1[12],tmp1[13]);
        tmp[11] = _mm_unpacklo_epi16(tmp1[14],tmp1[15]);

        tmp[12] = _mm_unpackhi_epi16(tmp1[8],tmp1[9]);
        tmp[13] = _mm_unpackhi_epi16(tmp1[10],tmp1[11]);
        tmp[14] = _mm_unpackhi_epi16(tmp1[12],tmp1[13]);
        tmp[15] = _mm_unpackhi_epi16(tmp1[14],tmp1[15]);  
        // printf("\ntmp(对hi进行操作):\n");
        // dump_hex(tmp+8,128);  


        tmp1[0] = _mm_unpacklo_epi32(tmp[0],tmp[1]);//0-1
        tmp1[1] = _mm_unpacklo_epi32(tmp[2],tmp[3]);
        tmp1[2] = _mm_unpacklo_epi32(tmp[4],tmp[5]);//4-5
        tmp1[3] = _mm_unpacklo_epi32(tmp[6],tmp[7]);
        
        tmp1[4] = _mm_unpackhi_epi32(tmp[0],tmp[1]);//2-3
        tmp1[5] = _mm_unpackhi_epi32(tmp[2],tmp[3]);
        tmp1[6] = _mm_unpackhi_epi32(tmp[4],tmp[5]);//6-7
        tmp1[7] = _mm_unpackhi_epi32(tmp[6],tmp[7]);
        // printf("\ntmp1:\n");
        // dump_hex(tmp1,128); 

        tmp1[8] = _mm_unpacklo_epi32(tmp[8],tmp[9]);//0-1
        tmp1[9] = _mm_unpacklo_epi32(tmp[10],tmp[11]);
        tmp1[10] = _mm_unpacklo_epi32(tmp[12],tmp[13]);//4-5
        tmp1[11] = _mm_unpacklo_epi32(tmp[14],tmp[15]);
        
        tmp1[12] = _mm_unpackhi_epi32(tmp[8],tmp[9]);//2-3
        tmp1[13] = _mm_unpackhi_epi32(tmp[10],tmp[11]);
        tmp1[14] = _mm_unpackhi_epi32(tmp[12],tmp[13]);//6-7
        tmp1[15] = _mm_unpackhi_epi32(tmp[14],tmp[15]);
        // printf("\ntmp1:\n");
        // dump_hex(tmp1+8,128);  
        
        tmp[0] = _mm_unpacklo_epi64(tmp1[0],tmp1[1]);
        tmp[1] = _mm_unpackhi_epi64(tmp1[0],tmp1[1]);

        tmp[2] = _mm_unpacklo_epi64(tmp1[4],tmp1[5]);
        tmp[3] = _mm_unpackhi_epi64(tmp1[4],tmp1[5]);

        tmp[4] = _mm_unpacklo_epi64(tmp1[2],tmp1[3]);
        tmp[5] = _mm_unpackhi_epi64(tmp1[2],tmp1[3]);

        tmp[6] = _mm_unpacklo_epi64(tmp1[6],tmp1[7]);
        tmp[7] = _mm_unpackhi_epi64(tmp1[6],tmp1[7]);


        tmp[8] = _mm_unpacklo_epi64(tmp1[8],tmp1[9]);
        tmp[9] = _mm_unpackhi_epi64(tmp1[8],tmp1[9]);

        tmp[10] = _mm_unpacklo_epi64(tmp1[12],tmp1[13]);
        tmp[11] = _mm_unpackhi_epi64(tmp1[12],tmp1[13]);

        tmp[12] = _mm_unpacklo_epi64(tmp1[10],tmp1[11]);
        tmp[13] = _mm_unpackhi_epi64(tmp1[10],tmp1[11]);

        tmp[14] = _mm_unpacklo_epi64(tmp1[14],tmp1[15]);
        tmp[15] = _mm_unpackhi_epi64(tmp1[14],tmp1[15]);
        // dump_hex(tmp,256);
    }
    return count;
}

int main() {

    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
    for (size_t i = 0; i < 16; i+=16)
    {
        input[i] = 0x01;
        input[i+1] = 0x23;
        input[i+2] = 0x45;
        input[i+3] = 0x67;
        input[i+4] = 0x89;
        input[i+5] = 0xab;
        input[i+6] = 0xcd;
        input[i+7] = 0xef;
        input[i+8] = 0xfe;
        input[i+9] = 0xdc;
        input[i+10] = 0xba;
        input[i+11] = 0x98;
        input[i+12] = 0x76;
        input[i+13] = 0x54;
        input[i+14] = 0x32;
        input[i+15] = 0x10;
    }
    ctx = wbsm4_se_avx2_context_init(1);

    wbsm4_se_avx2_gen_table(ctx, key_vector);
    gcm_ctx = gcm_init();
    wbsm4_se_avx2_gcm_init(gcm_ctx,iv_enc,aad,23,tag,16,ctx);
    
    printf("\nwbsm4_se_avx2_ecb:\n");
    wbsm4_se_avx2_ecb_encrypt(input,output,16,ctx);
    dump_hex(output,16);
    performance_test_enc(test_wbsm4_se_avx2_ecb_crypt_loop, size, 7, 3);
    // performance_test_enc(test_wbsm4_se_avx2_ctr_crypt_loop, size, 7, 3);
    // performance_test_enc(test_wbsm4_se_avx2_gcm_crypt_loop, size, 7, 3);
    

    // for (size_t i = 0; i < 32; i++)
    // {
    //     printf("%02x,%02x,%02x,%02x  ",ctx->M0_V[i][0],ctx->M0_V[i][1],ctx->M0_V[i][2],ctx->M0_V[i][3]);
    // }
    // printf("\n");

    // for (size_t i = 0; i < 16; i++)
    // {
    //     printf("%02x ",ctx->M0_F4[i][0][i]);
    // }
    // printf("\n");

   
    // for (size_t i = 0; i < 1024; i++)
    // {
    //     printf("%02x ",output[i]);
    //     if ((i+1) % 16 == 0)
    //     {
    //         printf("\n");
    //     }
    // }
    #if 1
        // test[0] = _mm256_set1_epi32(0x3c3c3c3c);
        // test[1] = _mm256_set1_epi32(0x12345678);
        // test[2] = _mm256_set1_epi32(0x9abcdef0);
        // test[3] = _mm256_set1_epi32(0x26566452);

        // performance_test_mode(test_affine_avx2_loop,3);
    #endif
    #if 0
        genaffinepairM32(&testA32,&testA32INV);
        performance_test_mode(test_affine_loop,3);
    #endif
    #if 0
        test[0] = _mm256_set1_epi32(0x3c3c3c3c);
        test[1] = _mm256_set1_epi32(0x12345678);
        test[2] = _mm256_set1_epi32(0x9abcdef0);
        test[3] = _mm256_set1_epi32(0x26566452);
        mask = _mm256_set1_epi32(0xFF);
        performance_test_mode(test_sbox_avx_loop,3);
    #endif
    #if 0
        while(1) {
            wbsm4_se_avx2_encrypt(input,output,ctx);
        }
    #endif
    #if 0
        performance_test_mode(test_set_loop,3);
        tmp[0] = _mm_setr_epi8(0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xa0,0xb0,0xc0,0xd0,0xe0,0xf0);
        tmp[1] = _mm_setr_epi8(0x01,0x11,0x21,0x31,0x41,0x51,0x61,0x71,0x81,0x91,0xa1,0xb1,0xc1,0xd1,0xe1,0xf1);
        tmp[2] = _mm_setr_epi8(0x02,0x12,0x22,0x32,0x42,0x52,0x62,0x72,0x82,0x92,0xa2,0xb2,0xc2,0xd2,0xe2,0xf2);
        tmp[3] = _mm_setr_epi8(0x03,0x13,0x23,0x33,0x43,0x53,0x63,0x73,0x83,0x93,0xa3,0xb3,0xc3,0xd3,0xe3,0xf3);
        tmp[4] = _mm_setr_epi8(0x04,0x14,0x24,0x34,0x44,0x54,0x64,0x74,0x84,0x94,0xa4,0xb4,0xc4,0xd4,0xe4,0xf4);
        tmp[5] = _mm_setr_epi8(0x05,0x15,0x25,0x35,0x45,0x55,0x65,0x75,0x85,0x95,0xa5,0xb5,0xc5,0xd5,0xe5,0xf5);
        tmp[6] = _mm_setr_epi8(0x06,0x16,0x26,0x36,0x46,0x56,0x66,0x76,0x86,0x96,0xa6,0xb6,0xc6,0xd6,0xe6,0xf6);
        tmp[7] = _mm_setr_epi8(0x07,0x17,0x27,0x37,0x47,0x57,0x67,0x77,0x87,0x97,0xa7,0xb7,0xc7,0xd7,0xe7,0xf7);
        tmp[8] = _mm_setr_epi8(0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78,0x88,0x98,0xa8,0xb8,0xc8,0xd8,0xe8,0xf8);
        tmp[9] = _mm_setr_epi8(0x09,0x19,0x29,0x39,0x49,0x59,0x69,0x79,0x89,0x99,0xa9,0xb9,0xc9,0xd9,0xe9,0xf9);
        tmp[10] = _mm_setr_epi8(0x0a,0x1a,0x2a,0x3a,0x4a,0x5a,0x6a,0x7a,0x8a,0x9a,0xaa,0xba,0xca,0xda,0xea,0xfa);
        tmp[11] = _mm_setr_epi8(0x0b,0x1b,0x2b,0x3b,0x4b,0x5b,0x6b,0x7b,0x8b,0x9b,0xab,0xbb,0xcb,0xdb,0xeb,0xfb);
        tmp[12] = _mm_setr_epi8(0x0c,0x1c,0x2c,0x3c,0x4c,0x5c,0x6c,0x7c,0x8c,0x9c,0xac,0xbc,0xcc,0xdc,0xec,0xfc);
        tmp[13] = _mm_setr_epi8(0x0d,0x1d,0x2d,0x3d,0x4d,0x5d,0x6d,0x7d,0x8d,0x9d,0xad,0xbd,0xcd,0xdd,0xed,0xfd);
        tmp[14] = _mm_setr_epi8(0x0e,0x1e,0x2e,0x3e,0x4e,0x5e,0x6e,0x7e,0x8e,0x9e,0xae,0xbe,0xce,0xde,0xee,0xfe);
        tmp[15] = _mm_setr_epi8(0x0f,0x1f,0x2f,0x3f,0x4f,0x5f,0x6f,0x7f,0x8f,0x9f,0xaf,0xbf,0xcf,0xdf,0xef,0xff);
        
        performance_test_mode(test_unpack_set_loop,3);

        // performance_test_mode(test_load_loop,3);
        // performance_test_mode(test_unpack_loop,3);
        // performance_test_mode(test_extract_loop,3);
    #endif
    wbsm4_se_avx2_context_free(ctx);
    return 0;
}
