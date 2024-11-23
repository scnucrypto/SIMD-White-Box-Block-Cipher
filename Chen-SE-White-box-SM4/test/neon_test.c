// /*
//  * @Date: 2022-09-25 10:08:50
//  * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
//  * @LastEditTime: 2022-09-25 19:41:56
//  * @FilePath: /whibox-sm4/Bai-Wu-White-box-SM4/test/main.c
//  * @Description: 
//  * 
//  * Copyright (c) 2022 by CBA511, All Rights Reserved. 
//  */
// #include <stdint.h>
// #include "wbsm4_se_cl_neon.h"
// #include "speed.h"


// unsigned char key_vector[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
// unsigned char IN[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
// unsigned char OUT[16] = {0};
// unsigned char input[16384] = {0};
// unsigned char output[16384] = {0};
// wbsm4_se_cl_neon_context *neon_ctx;

// static void dump_hex(uint8_t * h, int len)
// {
//     while(len--)
//     {   
//         printf("%02hhx ",*h++);
//         if(len%16==0) printf("\n");
//     }
//     printf("\n");
// }

// size_t test_wbsm4_se_cl_neon_ecb_crypt_loop(size_t size){
//     size_t count = 0;

//     for (count = 0; run && count < 0xffffffffffffffff; count++)
//     {
//         wbsm4_se_cl_neon_ecb_encrypt(input, output, size, neon_ctx);
//     }
    
//     return count;
// }
// int main()
// {
//     size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
//     time_t t;
	
//     neon_ctx = wbsm4_se_cl_neon_context_init(1);
    
//     wbsm4_se_cl_neon_gen_table(neon_ctx, key_vector);
//     printf("\nWBSM4_SE_CL_neon:\n");
//     // wbsm4_se_cl_neon_ecb_encrypt(test_in, test_out, 128, neon_ctx);
//     performance_test_enc(test_wbsm4_se_cl_neon_ecb_crypt_loop, size, 7, 3);

//     wbsm4_se_cl_neon_context_free(neon_ctx);
 


//     return 0;
// }