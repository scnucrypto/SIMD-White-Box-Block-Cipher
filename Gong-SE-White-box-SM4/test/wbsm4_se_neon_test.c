#include <string.h>
#include <stdio.h>
#include "speed.h"
#include "wbsm4_se_neon.h"

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
wbsm4_se_neon_context *ctx;
uint32_t x4 = 0x01234567;

size_t test_wbsm4_se_neon_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_neon_ecb_encrypt(input, output, size, ctx);
    }
    
    return count;
}

int main() {
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
    
    ctx = wbsm4_se_neon_context_init(1);
    wbsm4_se_neon_gen_table(ctx, key_vector);
    printf("\nwbsm4_se_neon:\n");
    performance_test_enc(test_wbsm4_se_neon_ecb_crypt_loop, size, 7, 3);
    
    wbsm4_se_neon_context_free(ctx);
    return 0;
}
