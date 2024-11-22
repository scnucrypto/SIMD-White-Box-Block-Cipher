#ifndef WBSPECK_SE_IBP_128_256_H
#define WBSPECK_SE_IBP_128_256_H
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "default_white_box_speck128_256.h"

static void matrix_vector_product_0(WORD_TYPE xy[2], WORD_TYPE res[2]); 
   

static void matrix_vector_product_1(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_2(WORD_TYPE xy[2], WORD_TYPE res[2]); 
static void matrix_vector_product_3(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_4(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_5(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_6(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_7(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_8(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_9(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_10(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_11(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_12(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_13(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_14(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_15(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_16(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_17(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_18(WORD_TYPE xy[2], WORD_TYPE res[2]); 

static void matrix_vector_product_19(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_20(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_21(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_22(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_23(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_24(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_25(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_26(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_27(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_28(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_29(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void matrix_vector_product_30(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_31(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_32(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_33(WORD_TYPE xy[2], WORD_TYPE res[2]);
static void matrix_vector_product_34(WORD_TYPE xy[2], WORD_TYPE res[2]);

static void (*MATRIX_VECTOR_PRODUCTS[ROUNDS + 1])(WORD_TYPE[2], WORD_TYPE[2]) = {matrix_vector_product_0, matrix_vector_product_1, matrix_vector_product_2, matrix_vector_product_3, matrix_vector_product_4, matrix_vector_product_5, matrix_vector_product_6, matrix_vector_product_7, matrix_vector_product_8, matrix_vector_product_9, matrix_vector_product_10, matrix_vector_product_11, matrix_vector_product_12, matrix_vector_product_13, matrix_vector_product_14, matrix_vector_product_15, matrix_vector_product_16, matrix_vector_product_17, matrix_vector_product_18, matrix_vector_product_19, matrix_vector_product_20, matrix_vector_product_21, matrix_vector_product_22, matrix_vector_product_23, matrix_vector_product_24, matrix_vector_product_25, matrix_vector_product_26, matrix_vector_product_27, matrix_vector_product_28, matrix_vector_product_29, matrix_vector_product_30, matrix_vector_product_31, matrix_vector_product_32, matrix_vector_product_33, matrix_vector_product_34};

static void vector_addition_0(WORD_TYPE xy[2]);
static void vector_addition_1(WORD_TYPE xy[2]);
static void vector_addition_2(WORD_TYPE xy[2]);
static void vector_addition_3(WORD_TYPE xy[2]);
static void vector_addition_4(WORD_TYPE xy[2]);
static void vector_addition_5(WORD_TYPE xy[2]);
static void vector_addition_6(WORD_TYPE xy[2]);
static void vector_addition_7(WORD_TYPE xy[2]);
static void vector_addition_8(WORD_TYPE xy[2]);
static void vector_addition_9(WORD_TYPE xy[2]);
static void vector_addition_10(WORD_TYPE xy[2]);
static void vector_addition_11(WORD_TYPE xy[2]);
static void vector_addition_12(WORD_TYPE xy[2]);
static void vector_addition_13(WORD_TYPE xy[2]);
static void vector_addition_14(WORD_TYPE xy[2]);
static void vector_addition_15(WORD_TYPE xy[2]);
static void vector_addition_16(WORD_TYPE xy[2]);
static void vector_addition_17(WORD_TYPE xy[2]);
static void vector_addition_18(WORD_TYPE xy[2]);
static void vector_addition_19(WORD_TYPE xy[2]);
static void vector_addition_20(WORD_TYPE xy[2]);
static void vector_addition_21(WORD_TYPE xy[2]);
static void vector_addition_22(WORD_TYPE xy[2]);
static void vector_addition_23(WORD_TYPE xy[2]);
static void vector_addition_24(WORD_TYPE xy[2]);
static void vector_addition_25(WORD_TYPE xy[2]);
static void vector_addition_26(WORD_TYPE xy[2]);
static void vector_addition_27(WORD_TYPE xy[2]);
static void vector_addition_28(WORD_TYPE xy[2]);
static void vector_addition_29(WORD_TYPE xy[2]);
static void vector_addition_30(WORD_TYPE xy[2]);
static void vector_addition_31(WORD_TYPE xy[2]);
static void vector_addition_32(WORD_TYPE xy[2]);
static void vector_addition_33(WORD_TYPE xy[2]);
static void vector_addition_34(WORD_TYPE xy[2]);

static void (*VECTOR_ADDITIONS[ROUNDS + 1])(WORD_TYPE[2]) = {vector_addition_0, vector_addition_1, vector_addition_2, vector_addition_3, vector_addition_4, vector_addition_5, vector_addition_6, vector_addition_7, vector_addition_8, vector_addition_9, vector_addition_10, vector_addition_11, vector_addition_12, vector_addition_13, vector_addition_14, vector_addition_15, vector_addition_16, vector_addition_17, vector_addition_18, vector_addition_19, vector_addition_20, vector_addition_21, vector_addition_22, vector_addition_23, vector_addition_24, vector_addition_25, vector_addition_26, vector_addition_27, vector_addition_28, vector_addition_29, vector_addition_30, vector_addition_31, vector_addition_32, vector_addition_33, vector_addition_34};

void inlined_bit_packed_matrix_vector_product(WORD_TYPE matrix[BLOCK_SIZE][2], WORD_TYPE xy[2], WORD_TYPE res[2]);

void inlined_bit_packed_vector_addition(WORD_TYPE vector[2], WORD_TYPE xy[2]);

void inlined_bit_packed_modular_addition(WORD_TYPE xy[2]);

void inlined_bit_packed_encrypt(WORD_TYPE p[2], WORD_TYPE c[2]);
int wbspeck_se_inlined_bit_packed_encrypt(const unsigned char *input, unsigned char *output);
int wbspeck_se_inlined_bit_packed_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len);
#endif

