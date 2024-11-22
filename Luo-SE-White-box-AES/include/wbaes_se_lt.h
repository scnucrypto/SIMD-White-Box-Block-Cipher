#ifndef WBAES_SE_LT_H
#define WBAES_SE_LT_H

#include <wbmatrix/WBMatrix.h>
#include <assert.h>
#include <aes.h>
#include <wbaes_se_local.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        Aff128 AL_F;
        Aff128 AL_LP[10];
        Aff128 AL_LQ[10];
        Aff128 P[2];
        Aff128 P_inv[2];

    }wbaes_se_lt_context ;
  
    wbaes_se_lt_context *wbaes_se_lt_context_init();

 
    void wbaes_se_lt_context_free(wbaes_se_lt_context *ctx);


    int wbaes_se_lt_gen_table(wbaes_se_lt_context *ctx, const uint8_t *key);


    int wbaes_se_lt_encrypt(const unsigned char *input, unsigned char *output, wbaes_se_lt_context *ctx);

    int wbaes_se_lt_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_lt_context *ctx);
   
#ifdef __cplusplus
}
#endif

#endif 
