// #ifndef WBAES_SE_LT_NEON_H
// #define WBAES_SE_LT_NEON_H

// #include <assert.h>
// #include <arm_neon.h>
// #include "wbaes_se_lt.h"
// #include "wbmatrix/WBMatrix.h"
// #include <string.h>

// #ifdef __cplusplus
// extern "C" {
// #endif

//     typedef struct {
//         uint8_t AL_F_M_F4[16][16][16];
//         uint8_t AL_F_M_E4[16][16][16];
//         uint8_t AL_F_V[16];

//         uint8_t AL_LP_M_F4[10][16][16][16];
//         uint8_t AL_LP_M_E4[10][16][16][16];
//         uint8_t AL_LP_V[10][16];

//         uint8_t AL_LQ_M_F4[10][16][16][16];
//         uint8_t AL_LQ_M_E4[10][16][16][16];
//         uint8_t AL_LQ_V[10][16];

//         uint8_t P_M_F4[2][16][16][16];
//         uint8_t P_M_E4[2][16][16][16];
//         uint8_t P_V[2][16];

//         uint8_t P_inv_M_F4[2][16][16][16];
//         uint8_t P_inv_M_E4[2][16][16][16];
//         uint8_t P_inv_V[2][16];

//     }wbaes_se_lt_neon_context;
    
//     wbaes_se_lt_neon_context * wbaes_se_lt_neon_context_init();

//     void wbaes_se_lt_neon_context_free(wbaes_se_lt_neon_context *ctx);

//     int wbaes_se_lt_neon_gen_table(wbaes_se_lt_neon_context *ctx, const uint8_t *key);

//     int wbaes_se_lt_neon_encrypt(const unsigned char input[256], unsigned char output[256], wbaes_se_lt_neon_context *ctx);
   
//     int wbaes_se_lt_neon_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_lt_neon_context *ctx);
   
// #ifdef __cplusplus
// }
// #endif

// #endif //WBSM4_SE_H
