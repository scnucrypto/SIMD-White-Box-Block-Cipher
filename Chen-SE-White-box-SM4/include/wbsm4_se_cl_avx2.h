// #ifndef WBSM4_SE_CL_AVX2_H
// #define WBSM4_SE_CL_AVX2_H

// #include <assert.h>
// #include <immintrin.h>
// #include "sm4_new.h"
// #include "wbmatrix/WBMatrix.h"
// #include <string.h>

// #ifdef __cplusplus
// extern "C" {
// #endif


//     typedef struct {
      
//         int encmode;
//         // !第一个16是明文分成16个字节，第二个16是每个明文过8-128bit仿射变换的输出126bit分成16个字节，第三个16是查找表
//         uint8_t TypeI_c_M_F4[16][16][16];
//         uint8_t TypeI_c_M_E4[16][16][16];
//         uint8_t TypeI_c_V[16][16];

//         // uint8_t TypeII_c_M_F4[16][16][16];
//         // uint8_t TypeII_c_M_E4[16][16][16];
//         // uint8_t TypeII_c_V[16][16];

//         // uint8_t TypeI_a_M_F4[32][16][16][16];
//         // uint8_t TypeI_a_M_E4[32][16][16][16];
//         // uint8_t TypeI_a_V[32][16][16];

//         // uint8_t TypeII_a_M_F4[32][16][16][16];
//         // uint8_t TypeII_a_M_E4[32][16][16][16];
//         // uint8_t TypeII_a_V[32][16][16];

//         // uint8_t TypeI_b_M_F4[31][16][16][16];
//         // uint8_t TypeI_b_M_E4[31][16][16][16];
//         // uint8_t TypeI_b_V[31][16][16];

//         // uint8_t TypeII_b_M_F4[31][16][16][16];
//         // uint8_t TypeII_b_M_E4[31][16][16][16];
//         // uint8_t TypeII_b_V[31][16][16];

//         // uint8_t TypeI_d_M_F4[16][16][16];
//         // uint8_t TypeI_d_M_E4[16][16][16];
//         // uint8_t TypeI_d_V[16][16];

//     }wbsm4_se_cl_avx2_context ;
    
//     wbsm4_se_cl_avx2_context *wbsm4_se_cl_avx2_context_init(int encmode);

//     void wbsm4_se_cl_avx2_context_free(wbsm4_se_cl_avx2_context *ctx);

//     int wbsm4_se_cl_avx2_gen_table(wbsm4_se_cl_avx2_context *ctx, const uint8_t *key);

//     int wbsm4_se_cl_avx2_encrypt(const unsigned char input[512], unsigned char output[512], wbsm4_se_cl_avx2_context *ctx);

   
//     int wbsm4_se_cl_avx2_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbsm4_se_cl_avx2_context *ctx);
    

   
// #ifdef __cplusplus
// }
// #endif

// #endif //WBSM4_SE_H
