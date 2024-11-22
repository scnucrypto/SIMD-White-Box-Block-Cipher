#include <string.h>
#include <stdio.h>
#include "speed.h"
#include "wbsm4_se.h"

unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char aad[] = {
        0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x03,0x7f,0xff,0xff,0xfe,0x89,0x2c,0x38,0x00,
        0x00,0x5c,0x36,0x5c,0x36,0x5c,0x36
};
unsigned char iv_enc[] = {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
        0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
};
unsigned char ecount_buf[16]={0x00};
unsigned int num = 0;
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbsm4_se_context *ctx;
uint32_t x4 = 0x01234567;

// size_t test_wbsm4se_ctr_crypt_loop(size_t size){
//     size_t count = 0;

//     for (count = 0; run && count < 0xffffffffffffffff; count++)
//     {
//         wbcrypto_wbsm4_se_ctr_encrypt(&ctx, iv_enc, ecount_buf, &num, input, size, output);
//     }
    
//     return count;
// }

// size_t test_wbsm4se_cbc_crypt_loop(size_t size){
//     size_t count = 0;

//     for (count = 0; run && count < 0xffffffffffffffff; count++)
//     {
//         wbcrypto_wbsm4_se_cbc_encrypt(&ctx, iv_enc, input, size, output);
//     }
    
//     return count;
// }

size_t test_wbsm4_se_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_ecb_encrypt(input, output, size, ctx);
    }
    
    return count;
}

size_t test_wbsm4_se_noon_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_encrypt(input,output,ctx);
    }
    
    return count;
}

size_t test_wbsm4_se_func_opt_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_encrypt_func_opt(input,output,ctx);
    }
    
    return count;
}

size_t test_sbox_loop(){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        x4 = (sm4_sbox[(x4 >> 24) & 0xff] << 24) | (sm4_sbox[(x4 >> 16) & 0xff] << 16) |
             (sm4_sbox[(x4 >> 8) & 0xff] << 8) | sm4_sbox[x4 & 0xff];
    }
    
    return count;
}

int main() {
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
    
    ctx = wbsm4_se_context_init(1);
    wbsm4_se_gen_table(ctx, key_vector);
    for (size_t i = 0; i < 512; i+=16)
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
    wbsm4_se_encrypt_func_opt(input,output,ctx);
    printf("\n");
    for (size_t i = 0; i < 16; i++)
    {
        printf("%02x ",output[i]);
    }
    printf("\nwbsm4_se_ecb:\n");
    performance_test_enc(test_wbsm4_se_ecb_crypt_loop, size, 7, 3);
    #if 0
        while(1) {
            wbsm4_se_encrypt(input,output,ctx);
        }
    #endif
    #if 0
        performance_test_mode(test_wbsm4_se_noon_loop, 3);
    #endif
    #if 0
        performance_test_mode(test_wbsm4_se_func_opt_loop, 3);
    #endif
    #if 0
        performance_test_mode(test_sbox_loop, 3);
    #endif
    wbsm4_se_context_free(ctx);
    return 0;
}
