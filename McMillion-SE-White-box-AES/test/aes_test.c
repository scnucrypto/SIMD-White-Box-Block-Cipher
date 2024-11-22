
#include <stdint.h>
#include "aes.h"
#include "speed.h"

unsigned char key_vector[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
unsigned char OUT[16] = {0};
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};
wbcrypto_aes_context ctx;

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}

// size_t test_aes_ecb_crypt_loop(size_t size){
//     size_t count = 0;

//     for (count = 0; run && count < 0xffffffffffffffff; count++)
//     {
//         wbaes_se_lt_ecb_encrypt(input, output, size, ctx);
//     }
    
//     return count;
// }

int main()
{
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
        
        wbcrypto_aes_setkey_enc(&ctx,key_vector);
        printf("\nAES_SE:\n");
        wbcrypto_aes_encrypt(IN, OUT, &ctx);
        dump_hex(OUT,16);
        // performance_test_enc(test_wbaes_se_lt_ecb_crypt_loop, size, 7, 3);
    
    return 0;
}