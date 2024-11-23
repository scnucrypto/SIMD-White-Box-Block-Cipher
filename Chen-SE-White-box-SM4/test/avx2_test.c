
#include <stdint.h>
#include "wbsm4_se_cl_avx2.h"
#include "speed.h"


unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char IN[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char OUT[16] = {0};
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbsm4_se_cl_avx2_context *avx2_ctx;

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}


size_t test_wbsm4_se_cl_avx2_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbsm4_se_cl_avx2_ecb_encrypt(input, output, size, avx2_ctx);
    }
    
    return count;
}

int main()
{
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
    time_t t;
	srand((unsigned)time(&t));
    
    avx2_ctx = wbsm4_se_cl_avx2_context_init(1);
    
    wbsm4_se_cl_avx2_gen_table(avx2_ctx, key_vector);
    printf("\nWBSM4_SE_CL_AVX2:\n");
    // wbsm4_se_cl_avx2_ecb_encrypt(test_in, test_out, 128, avx2_ctx);
    performance_test_enc(test_wbsm4_se_cl_avx2_ecb_crypt_loop, size, 7, 3);

    wbsm4_se_cl_avx2_context_free(avx2_ctx);



    return 0;
}