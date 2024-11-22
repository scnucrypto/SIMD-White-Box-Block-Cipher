#include <stdint.h>
#include "wbspeck_se_neon_128_256.h"
#include "speed.h"
unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char IN[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char OUT[16] = {0};
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbspeck_se_neon_128_256_context *neon_ctx;

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}

size_t test_wbspeck_se_neon_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbspeck_se_neon_128_256_ecb_encrypt(input, output, size, neon_ctx);
    }
    
    return count;
}

int main()
{
   size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
 
    neon_ctx = wbspeck_se_neon_128_256_context_init();
    wbspeck_se_neon_128_256_gen_table(neon_ctx);
    printf("\nWBSPECK_SE_NEON:\n");
    // wbspeck_se_neon_128_256_ecb_encrypt(test_in1, test_out1, 128, neon_ctx);
    performance_test_enc(test_wbspeck_se_neon_ecb_crypt_loop, size, 7, 3);
    wbspeck_se_neon_128_256_context_free(neon_ctx);
    
    return 0;
}