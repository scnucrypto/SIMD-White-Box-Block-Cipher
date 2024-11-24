
#include <stdint.h>
#include "wbaes_se_ms_avx2.h"
#include "speed.h"

unsigned char key_vector[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
unsigned char OUT[16] = {0};
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbaes_se_ms_avx2_context *avx2_ctx;

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}

size_t test_wbaes_se_ms_avx2_ecb_crypt_loop(size_t size){
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbaes_se_ms_avx2_ecb_encrypt(input, output, size, avx2_ctx);
    }
    
    return count;
}

int main()
{
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};

    avx2_ctx = wbaes_se_ms_avx2_context_init();
    
    wbaes_se_ms_avx2_gen_table(avx2_ctx, key_vector);

    wbaes_se_ms_avx2_ecb_encrypt(IN, OUT, 16, avx2_ctx);
    printf("\nWBAES_SE_MS_AVX2:\n");
    dump_hex(OUT,16);
    // performance_test_enc(test_wbaes_se_ms_avx2_ecb_crypt_loop, size, 7, 3);
  
   
    wbaes_se_ms_avx2_context_free(avx2_ctx);
    return 0;
}