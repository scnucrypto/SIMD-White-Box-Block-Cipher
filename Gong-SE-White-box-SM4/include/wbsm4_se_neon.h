// #ifndef WBSM4_SE_NEON_H
// #define WBSM4_SE_NEON_H

// #include <wbmatrix/WBMatrix.h>
// #include <assert.h>
// #include <arm_neon.h>
// #include "sm4.h"
// #include "wbsm4_se_simd_mode_gcm.h"

// #ifdef __cplusplus
// extern "C" {
// #endif
//     typedef struct {
//         Aff32 M[32][3];
//         Aff32 C[32];
//         Aff32 D[32];
//         Aff32 SE[4];
//         Aff32 FE[4];
//     }se_context ;

//     typedef struct {
//         int encmode;
       
//         uint8_t M0_F4[32][4][4][16];
//         uint8_t M0_E4[32][4][4][16];
   
//         uint8_t M0_V[32][4];
        
//         uint8_t M1_F4[32][4][4][16];
//         uint8_t M1_E4[32][4][4][16];
//         uint8_t M1_V[32][4];
        
//         uint8_t M2_F4[32][4][4][16];
//         uint8_t M2_E4[32][4][4][16];
//         uint8_t M2_V[32][4];
        
//         uint8_t C_F4[32][4][4][16];
//         uint8_t C_E4[32][4][4][16];
//         uint8_t C_V[32][4];
        
//         uint8_t D_F4[32][4][4][16];
//         uint8_t D_E4[32][4][4][16];
//         uint8_t D_V[32][4];
        
//         uint8_t SE_F4[4][4][4][16];
//         uint8_t SE_E4[4][4][4][16];
//         uint8_t SE_V[4][4];
        
//         uint8_t FE_F4[4][4][4][16];
//         uint8_t FE_E4[4][4][4][16];
//         uint8_t FE_V[4][4];

//     }wbsm4_se_neon_context ;
//     /******************************************basic function**********************************************/
//     /**
//     * the function initializes the se_wbsm4 context
//     * @param encmode encrypto mode. {WBCRYPTO_ENCRYPT_MODE: encrypto mode; WBCRYPTO_DECRYPT_MODE: decrypto mode}
//     * @return ctx Context to initialize, NULL is fault, otherwise successful
//     */
//     wbsm4_se_neon_context *wbsm4_se_neon_context_init(int encmode);

//     /**
//     * free se_wbsm4 context
//     * @param ctx
//     */
//     void wbsm4_se_neon_context_free(wbsm4_se_neon_context *ctx);

//     /**
//     * the function generate key-tables by the key in the context
//     * @param key key used to generate the key-tables, which need to hide
//     * @param keylen key length
//     * @return 1 if success, 0 if error
//     */
//     int wbsm4_se_neon_gen_table(wbsm4_se_neon_context *ctx, const uint8_t *key);

//     /**
//     * the function is used to encrypt(**generally not used directly**)
//     * @param ctx se-wbsm4-ctx must be init
//     * @param input plaintext
//     * @param output ciphertext
//     * @return 1 if success, 0 if error
//     */
//     int wbsm4_se_neon_encrypt(const unsigned char input[256], unsigned char output[256], wbsm4_se_neon_context *ctx);

//     /**
//     * the function is used to decrypt(**generally not used directly**)
//     * @param ctx se-wbsm4-ctx must be init
//     * @param input ciphertext
//     * @param output plaintext
//     * @return 1 if success, 0 if error
//     */
// //    int wbsm4_se_decrypt(const unsigned char *input, unsigned char *output, wbsm4_se_context *ctx);
//     int wbsm4_se_neon_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbsm4_se_neon_context *ctx);
   
//     // void MatrixdivM32to4_NEON(M32 mat32, M4 m4[8][8]);
//     // void GEN_TABLE_DATA_F4(M4 TMP[8][8], uint8_t index, uint8_t data[4][4][16]);
//     // void GEN_TABLE_DATA_E4(M4 TMP[8][8], uint8_t index, uint8_t data[4][4][16]);
//     static const unsigned char Sbox[256] =
//     {
//         0xd6, 0x90, 0xe9, 0xfe, 0xcc, 0xe1, 0x3d, 0xb7, 0x16, 0xb6, 0x14, 0xc2, 0x28, 0xfb, 0x2c, 0x05,
//         0x2b, 0x67, 0x9a, 0x76, 0x2a, 0xbe, 0x04, 0xc3, 0xaa, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99,
//         0x9c, 0x42, 0x50, 0xf4, 0x91, 0xef, 0x98, 0x7a, 0x33, 0x54, 0x0b, 0x43, 0xed, 0xcf, 0xac, 0x62,
//         0xe4, 0xb3, 0x1c, 0xa9, 0xc9, 0x08, 0xe8, 0x95, 0x80, 0xdf, 0x94, 0xfa, 0x75, 0x8f, 0x3f, 0xa6,
//         0x47, 0x07, 0xa7, 0xfc, 0xf3, 0x73, 0x17, 0xba, 0x83, 0x59, 0x3c, 0x19, 0xe6, 0x85, 0x4f, 0xa8,
//         0x68, 0x6b, 0x81, 0xb2, 0x71, 0x64, 0xda, 0x8b, 0xf8, 0xeb, 0x0f, 0x4b, 0x70, 0x56, 0x9d, 0x35,
//         0x1e, 0x24, 0x0e, 0x5e, 0x63, 0x58, 0xd1, 0xa2, 0x25, 0x22, 0x7c, 0x3b, 0x01, 0x21, 0x78, 0x87,
//         0xd4, 0x00, 0x46, 0x57, 0x9f, 0xd3, 0x27, 0x52, 0x4c, 0x36, 0x02, 0xe7, 0xa0, 0xc4, 0xc8, 0x9e,
//         0xea, 0xbf, 0x8a, 0xd2, 0x40, 0xc7, 0x38, 0xb5, 0xa3, 0xf7, 0xf2, 0xce, 0xf9, 0x61, 0x15, 0xa1,
//         0xe0, 0xae, 0x5d, 0xa4, 0x9b, 0x34, 0x1a, 0x55, 0xad, 0x93, 0x32, 0x30, 0xf5, 0x8c, 0xb1, 0xe3,
//         0x1d, 0xf6, 0xe2, 0x2e, 0x82, 0x66, 0xca, 0x60, 0xc0, 0x29, 0x23, 0xab, 0x0d, 0x53, 0x4e, 0x6f,
//         0xd5, 0xdb, 0x37, 0x45, 0xde, 0xfd, 0x8e, 0x2f, 0x03, 0xff, 0x6a, 0x72, 0x6d, 0x6c, 0x5b, 0x51,
//         0x8d, 0x1b, 0xaf, 0x92, 0xbb, 0xdd, 0xbc, 0x7f, 0x11, 0xd9, 0x5c, 0x41, 0x1f, 0x10, 0x5a, 0xd8,
//         0x0a, 0xc1, 0x31, 0x88, 0xa5, 0xcd, 0x7b, 0xbd, 0x2d, 0x74, 0xd0, 0x12, 0xb8, 0xe5, 0xb4, 0xb0,
//         0x89, 0x69, 0x97, 0x4a, 0x0c, 0x96, 0x77, 0x7e, 0x65, 0xb9, 0xf1, 0x09, 0xc5, 0x6e, 0xc6, 0x84,
//         0x18, 0xf0, 0x7d, 0xec, 0x3a, 0xdc, 0x4d, 0x20, 0x79, 0xee, 0x5f, 0x3e, 0xd7, 0xcb, 0x39, 0x48
//     };
// #ifdef __cplusplus
// }
// #endif

// #endif //WBSM4_SE_H