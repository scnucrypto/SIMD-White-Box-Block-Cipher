
// #include <stdint.h>
// #include "wbaes_se_ms_neon.h"
// #include "speed.h"

// unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
// unsigned char IN[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
// unsigned char OUT[16] = {0};
// unsigned char input[16384] = {0};
// unsigned char output[16384] = {0};
// wbaes_se_ms_neon_context *neon_ctx;

// static void dump_hex(uint8_t * h, int len)
// {
//     while(len--)
//     {   
//         printf("%02hhx ",*h++);
//         if(len%16==0) printf("\n");
//     }
//     printf("\n");
// }

// size_t test_wbaes_se_ms_neon_ecb_crypt_loop(size_t size){
//     size_t count = 0;

//     for (count = 0; run && count < 0xffffffffffffffff; count++)
//     {
//         wbaes_se_ms_neon_ecb_encrypt(input, output, size, neon_ctx);
//     }
    
//     return count;
// }

// int main()
// {
//     size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
//     // ! 注意不能同时测试，会影响性能，每次只测试一个算法
 
//     neon_ctx = wbaes_se_ms_neon_context_init();
    
//     wbaes_se_ms_neon_gen_table(neon_ctx, key_vector);

//     // wbaes_se_ms_neon_ecb_encrypt(IN, OUT, 16, ms_ctx);
//     printf("\nWBAES_SE_MS_neon:\n");
//     performance_test_enc(test_wbaes_se_ms_neon_ecb_crypt_loop, size, 7, 3);
 
//     wbaes_se_ms_neon_context_free(neon_ctx);
//     return 0;
// }