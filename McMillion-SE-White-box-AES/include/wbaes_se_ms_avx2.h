#ifndef WBAES_SE_MS_AVX2_H
#define WBAES_SE_MS_AVX2_H

#include <assert.h>
#include <immintrin.h>
#include "wbaes_se_ms.h"
#include "wbmatrix/WBMatrix.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


    typedef struct {
        uint8_t AL_M_F4[11][16][16][16];
        uint8_t AL_M_E4[11][16][16][16];
        uint8_t AL_V[11][16];

        uint8_t P_M_F4[2][16][16][16];
        uint8_t P_M_E4[2][16][16][16];
        uint8_t P_V[2][16];

        uint8_t P_inv_M_F4[2][16][16][16];
        uint8_t P_inv_M_E4[2][16][16][16];
        uint8_t P_inv_V[2][16];

    }wbaes_se_ms_avx2_context;
    
    wbaes_se_ms_avx2_context * wbaes_se_ms_avx2_context_init();

    void wbaes_se_ms_avx2_context_free(wbaes_se_ms_avx2_context *ctx);

    int wbaes_se_ms_avx2_gen_table(wbaes_se_ms_avx2_context *ctx, const uint8_t *key);

    int wbaes_se_ms_avx2_encrypt(const unsigned char input[512], unsigned char output[512], wbaes_se_ms_avx2_context *ctx);
   
    int wbaes_se_ms_avx2_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_ms_avx2_context *ctx);
    
#ifdef __cplusplus
}
#endif

#endif //WBSM4_SE_H
