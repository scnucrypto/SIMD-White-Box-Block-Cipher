/*
 * @Author: RyanCLQ
 * @Date: 2023-05-28 12:45:52
 * @LastEditors: RyanCLQ
 * @LastEditTime: 2023-06-09 22:20:50
 * @Description: 请填写简介
 */
/**
 * \file sm4_lut.h
 *
 * \brief This file contains the SM4_LUT algorithm definitions and functions.
 *
 */
#ifndef WBCRYPTO_SM4_LUT_H
#define WBCRYPTO_SM4_LUT_H



#include <stdint.h>
#include <stdlib.h>
#include "speed.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * \brief           The SM4 key context structure
     */
    typedef struct wbcrypto_sm4_lut_context
    { 
        uint32_t rk[32];           /*!<  SM4 subkeys       */
    }
    wbcrypto_sm4_lut_context;

    typedef struct wbcrypto_sm4_lut_context WBCRYPTO_SM4_LUT_KEY;


    void wbcrypto_sm4_lut_setkey_enc(wbcrypto_sm4_lut_context *ctx, const unsigned char *user_key);

    void wbcrypto_sm4_lut_setkey_dec(wbcrypto_sm4_lut_context *ctx, const unsigned char *user_key);

    void wbcrypto_sm4_lut_encrypt(const unsigned char *in, unsigned char *out, const wbcrypto_sm4_lut_context *ctx);

    void wbcrypto_sm4_lut_decrypt(const unsigned char *in, unsigned char *out, const wbcrypto_sm4_lut_context *ctx);

    int wbcrypto_sm4_lut_ecb_encrypt(const wbcrypto_sm4_lut_context *ctx, const unsigned char *input, 
                                    size_t ilen, unsigned char *output);
    void wbcrypto_sm4_lut_free(wbcrypto_sm4_lut_context *ctx);  
    
    void performance_test_sm4_lut();

    // size_t test_sm4_lut_ecb_crypt_loop(size_t size);                          

#ifdef __cplusplus
}
#endif
#endif
/* sm4_lut.h */