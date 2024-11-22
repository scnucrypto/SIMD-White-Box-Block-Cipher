#ifndef WBSPECK_SE_IL_128_256_H
#define WBSPECK_SE_IL_128_256_H
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "default_white_box_speck128_256.h"


static void matrix_vector_product_0(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_1(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_2(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_3(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_4(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_5(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_6(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_7(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_8(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_9(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_10(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_11(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_12(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_13(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_14(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_15(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_16(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_17(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_18(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_19(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_20(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_21(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_22(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_23(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_24(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_25(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_26(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_27(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_28(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_29(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_30(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_31(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_32(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_33(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);
static void matrix_vector_product_34(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]);

static void (*MATRIX_VECTOR_PRODUCTS[ROUNDS + 1])(uint8_t[BLOCK_SIZE], uint8_t[BLOCK_SIZE]) = {matrix_vector_product_0, matrix_vector_product_1, matrix_vector_product_2, matrix_vector_product_3, matrix_vector_product_4, matrix_vector_product_5, matrix_vector_product_6, matrix_vector_product_7, matrix_vector_product_8, matrix_vector_product_9, matrix_vector_product_10, matrix_vector_product_11, matrix_vector_product_12, matrix_vector_product_13, matrix_vector_product_14, matrix_vector_product_15, matrix_vector_product_16, matrix_vector_product_17, matrix_vector_product_18, matrix_vector_product_19, matrix_vector_product_20, matrix_vector_product_21, matrix_vector_product_22, matrix_vector_product_23, matrix_vector_product_24, matrix_vector_product_25, matrix_vector_product_26, matrix_vector_product_27, matrix_vector_product_28, matrix_vector_product_29, matrix_vector_product_30, matrix_vector_product_31, matrix_vector_product_32, matrix_vector_product_33, matrix_vector_product_34};

static void vector_addition_0(uint8_t xy[BLOCK_SIZE]) {
}

static void vector_addition_1(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_2(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_3(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_4(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_5(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_6(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_7(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_8(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_9(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_10(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_11(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_12(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_13(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_14(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_15(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_16(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_17(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_18(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_19(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_20(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_21(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_22(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_23(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_24(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_25(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_26(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_27(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_28(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_29(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_30(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_31(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_32(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_33(uint8_t xy[BLOCK_SIZE]);
static void vector_addition_34(uint8_t xy[BLOCK_SIZE]);

static void (*VECTOR_ADDITIONS[ROUNDS + 1])(uint8_t[BLOCK_SIZE]) = {vector_addition_0, vector_addition_1, vector_addition_2, vector_addition_3, vector_addition_4, vector_addition_5, vector_addition_6, vector_addition_7, vector_addition_8, vector_addition_9, vector_addition_10, vector_addition_11, vector_addition_12, vector_addition_13, vector_addition_14, vector_addition_15, vector_addition_16, vector_addition_17, vector_addition_18, vector_addition_19, vector_addition_20, vector_addition_21, vector_addition_22, vector_addition_23, vector_addition_24, vector_addition_25, vector_addition_26, vector_addition_27, vector_addition_28, vector_addition_29, vector_addition_30, vector_addition_31, vector_addition_32, vector_addition_33, vector_addition_34};

void inlined_from_bits(uint8_t bits[BLOCK_SIZE], WORD_TYPE *x, WORD_TYPE *y);

void inlined_to_bits(WORD_TYPE x, WORD_TYPE y, uint8_t bits[BLOCK_SIZE]);

void inlined_modular_addition(uint8_t xy[BLOCK_SIZE]);

void inlined_encrypt(WORD_TYPE p[2], WORD_TYPE c[2]);
int wbspeck_se_inlined_encrypt(const unsigned char *input, unsigned char *output);
int wbspeck_se_inlined_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len);
#endif
// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         return -1;
//     }
//     WORD_TYPE p[2];
//     WORD_TYPE c[2];
//     if (argc < 3) {
//         size_t iterations;
//         sscanf(argv[1], "%zu", &iterations);
//         for (int i = 0; i < iterations; i++) {
//             p[0] = (((WORD_TYPE) rand()) << (WORD_SIZE / 2)) | ((WORD_TYPE) rand());
//             p[1] = (((WORD_TYPE) rand()) << (WORD_SIZE / 2)) | ((WORD_TYPE) rand());
//             encrypt(p, c);
//         }
//         return -1;
//     } else {
//         sscanf(argv[1], "%" WORD_IN_TYPE, &p[0]);
//         sscanf(argv[2], "%" WORD_IN_TYPE, &p[1]);
//         encrypt(p, c);
//         printf("%" WORD_OUT_TYPE " %" WORD_OUT_TYPE "\n", c[0], c[1]);
//     }
// }
