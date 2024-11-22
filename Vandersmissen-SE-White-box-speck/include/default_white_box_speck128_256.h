#ifndef WBSPECK_SE_128_256_H
#define WBSPECK_SE_128_256_H

#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BLOCK_SIZE 128
#define WORD_SIZE 64
#define WORD_TYPE uint64_t
#define WORD_IN_TYPE SCNx64
#define WORD_OUT_TYPE PRIx64
#define WORD_CONSTANT_TYPE UINT64_C
#define WORD_PARITY_FUNCTION __builtin_parityll
#define WORD_MASK 0xffffffffffffffff
#define ROUNDS 34

#define GET64(pc)  (\
((uint64_t)(pc)[0] << 56) ^\
((uint64_t)(pc)[1] << 48) ^\
((uint64_t)(pc)[2] << 40) ^\
((uint64_t)(pc)[3] << 32) ^\
((uint64_t)(pc)[0] << 24) ^\
((uint64_t)(pc)[1] << 16) ^\
((uint64_t)(pc)[2] << 8) ^\
((uint64_t)(pc)[3]))

#define PUT64(st, ct)\
(ct)[0] = (uint8_t)((st) >> 56);\
(ct)[1] = (uint8_t)((st) >> 48);\
(ct)[2] = (uint8_t)((st) >> 40);\
(ct)[3] = (uint8_t)((st) >> 32);\
(ct)[4] = (uint8_t)((st) >> 24);\
(ct)[5] = (uint8_t)((st) >> 16);\
(ct)[6] = (uint8_t)((st) >>  8);\
(ct)[7] = (uint8_t)(st)

void default_from_bits(uint8_t bits[BLOCK_SIZE], WORD_TYPE *x, WORD_TYPE *y);
void default_to_bits(WORD_TYPE x, WORD_TYPE y, uint8_t bits[BLOCK_SIZE]);
void default_matrix_vector_product(uint8_t matrix[BLOCK_SIZE][BLOCK_SIZE], uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
void default_vector_addition(uint8_t vector[BLOCK_SIZE], uint8_t xy[BLOCK_SIZE]);
void default_modular_addition(uint8_t xy[BLOCK_SIZE]);
void default_encrypt(WORD_TYPE p[2], WORD_TYPE c[2]);
int wbspeck_se_default_encrypt(const unsigned char *input, unsigned char *output);
int wbspeck_se_default_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len);

#endif




























