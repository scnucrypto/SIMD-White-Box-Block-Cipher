#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 32
#define WORD_SIZE 16
#define WORD_TYPE uint16_t
#define WORD_IN_TYPE SCNx16
#define WORD_OUT_TYPE PRIx16
#define ROUNDS 22

void matrix_vector_product_0(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7];
    res[1] ^= 0 ^ xy[8];
    res[2] ^= 0 ^ xy[9];
    res[3] ^= 0 ^ xy[10];
    res[4] ^= 0 ^ xy[11];
    res[5] ^= 0 ^ xy[12];
    res[6] ^= 0 ^ xy[13];
    res[7] ^= 0 ^ xy[14];
    res[8] ^= 0 ^ xy[15];
    res[9] ^= 0 ^ xy[0];
    res[10] ^= 0 ^ xy[1];
    res[11] ^= 0 ^ xy[2];
    res[12] ^= 0 ^ xy[3];
    res[13] ^= 0 ^ xy[4];
    res[14] ^= 0 ^ xy[5];
    res[15] ^= 0 ^ xy[6];
    res[16] ^= 0 ^ xy[16];
    res[17] ^= 0 ^ xy[17];
    res[18] ^= 0 ^ xy[18];
    res[19] ^= 0 ^ xy[19];
    res[20] ^= 0 ^ xy[20];
    res[21] ^= 0 ^ xy[21];
    res[22] ^= 0 ^ xy[22];
    res[23] ^= 0 ^ xy[23];
    res[24] ^= 0 ^ xy[24];
    res[25] ^= 0 ^ xy[25];
    res[26] ^= 0 ^ xy[26];
    res[27] ^= 0 ^ xy[27];
    res[28] ^= 0 ^ xy[28];
    res[29] ^= 0 ^ xy[29];
    res[30] ^= 0 ^ xy[30];
    res[31] ^= 0 ^ xy[31];
}

void matrix_vector_product_1(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[5] ^ xy[8] ^ xy[9] ^ xy[11] ^ xy[13] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[25] ^ xy[26] ^ xy[30] ^ xy[31];
    res[1] ^= 0 ^ xy[0] ^ xy[2] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[29];
    res[2] ^= 0 ^ xy[1] ^ xy[2] ^ xy[6] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[30] ^ xy[31];
    res[3] ^= 0 ^ xy[4] ^ xy[5] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[17] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[31];
    res[4] ^= 0 ^ xy[0] ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[8] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[21] ^ xy[26];
    res[6] ^= 0 ^ xy[1] ^ xy[8] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[31];
    res[7] ^= 0 ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[28];
    res[8] ^= 0 ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[12] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[0] ^ xy[3] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[12] ^ xy[13] ^ xy[16] ^ xy[17] ^ xy[21] ^ xy[23] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29];
    res[10] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[9] ^ xy[10] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[27] ^ xy[29];
    res[11] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[21] ^ xy[24] ^ xy[25] ^ xy[29];
    res[12] ^= 0 ^ xy[1] ^ xy[4] ^ xy[9] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[25] ^ xy[26];
    res[13] ^= 0 ^ xy[0] ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[14] ^= 0 ^ xy[0] ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[9] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[22] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[15] ^= 0 ^ xy[1] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[29] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[1] ^ xy[5] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[22] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29];
    res[18] ^= 0 ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[19] ^= 0 ^ xy[0] ^ xy[1] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[14] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[29] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[9] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[21] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[8] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[17] ^ xy[18] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[31];
    res[22] ^= 0 ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[11] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[22] ^ xy[24] ^ xy[26] ^ xy[28] ^ xy[29] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[29] ^ xy[30];
    res[24] ^= 0 ^ xy[2] ^ xy[3] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[25] ^ xy[28] ^ xy[29];
    res[25] ^= 0 ^ xy[7] ^ xy[9] ^ xy[12] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[26] ^ xy[29];
    res[26] ^= 0 ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[10] ^ xy[11] ^ xy[15] ^ xy[19] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[29] ^ xy[31];
    res[27] ^= 0 ^ xy[3] ^ xy[6] ^ xy[8] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[30];
    res[28] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[31];
    res[29] ^= 0 ^ xy[2] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[30] ^= 0 ^ xy[0] ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[20] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[27];
    res[31] ^= 0 ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[28] ^ xy[29] ^ xy[30];
}

void matrix_vector_product_2(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[26] ^ xy[28] ^ xy[31];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[2] ^ xy[4] ^ xy[8] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[27];
    res[16] ^= 0 ^ xy[7] ^ xy[16];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[10] ^ xy[13] ^ xy[15] ^ xy[18] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
}

void matrix_vector_product_3(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[8] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[9] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[10] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[11] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[12] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[13] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[14] ^ xy[30];
    res[8] ^= 0 ^ xy[14] ^ xy[15] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[27] ^ xy[30];
    res[9] ^= 0 ^ xy[0] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[30];
    res[15] ^= 0 ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27];
    res[16] ^= 0 ^ xy[0] ^ xy[7];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[26] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[2] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[10] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[28] ^ xy[29];
}

void matrix_vector_product_4(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7];
    res[1] ^= 0 ^ xy[0] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[15] ^ xy[18] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[30];
    res[9] ^= 0 ^ xy[0] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[26] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[2] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[27] ^ xy[29] ^ xy[30];
}

void matrix_vector_product_5(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[8];
    res[2] ^= 0 ^ xy[0] ^ xy[9];
    res[3] ^= 0 ^ xy[0] ^ xy[10];
    res[4] ^= 0 ^ xy[0] ^ xy[11];
    res[5] ^= 0 ^ xy[0] ^ xy[12];
    res[6] ^= 0 ^ xy[0] ^ xy[13];
    res[7] ^= 0 ^ xy[0] ^ xy[14];
    res[8] ^= 0 ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29];
    res[9] ^= 0 ^ xy[16];
    res[10] ^= 0 ^ xy[0] ^ xy[1];
    res[11] ^= 0 ^ xy[0] ^ xy[2];
    res[12] ^= 0 ^ xy[0] ^ xy[3];
    res[13] ^= 0 ^ xy[0] ^ xy[4];
    res[14] ^= 0 ^ xy[0] ^ xy[5];
    res[15] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[14] ^ xy[17] ^ xy[18] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[28];
    res[16] ^= 0 ^ xy[0] ^ xy[7];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[27] ^ xy[28] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[2];
    res[19] ^= 0 ^ xy[3] ^ xy[17];
    res[20] ^= 0 ^ xy[4] ^ xy[18];
    res[21] ^= 0 ^ xy[5] ^ xy[19];
    res[22] ^= 0 ^ xy[6] ^ xy[20];
    res[23] ^= 0 ^ xy[7] ^ xy[21];
    res[24] ^= 0 ^ xy[8] ^ xy[22];
    res[25] ^= 0 ^ xy[9] ^ xy[23];
    res[26] ^= 0 ^ xy[10] ^ xy[24];
    res[27] ^= 0 ^ xy[11] ^ xy[25];
    res[28] ^= 0 ^ xy[12] ^ xy[26];
    res[29] ^= 0 ^ xy[13] ^ xy[27];
    res[30] ^= 0 ^ xy[14] ^ xy[28];
    res[31] ^= 0 ^ xy[0] ^ xy[1] ^ xy[5] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[27] ^ xy[30] ^ xy[31];
}

void matrix_vector_product_6(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[9] ^ xy[13] ^ xy[15] ^ xy[17] ^ xy[20] ^ xy[23];
    res[16] ^= 0 ^ xy[7];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[5] ^ xy[6] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[17];
}

void matrix_vector_product_7(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[29] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[15] ^ xy[17] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[28] ^ xy[29];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16];
    res[17] ^= 0 ^ xy[1] ^ xy[16] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[2] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[15] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[28] ^ xy[30] ^ xy[31];
}

void matrix_vector_product_8(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[30];
    res[1] ^= 0 ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[6] ^ xy[9] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[25] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[18] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[26] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[8] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[25] ^ xy[28] ^ xy[29] ^ xy[30];
}

void matrix_vector_product_9(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[29] ^ xy[31];
    res[9] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[5] ^ xy[8] ^ xy[11] ^ xy[16] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[30];
    res[16] ^= 0 ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[17] ^ xy[20] ^ xy[24] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[4] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[31];
}

void matrix_vector_product_10(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16];
    res[1] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[20] ^ xy[22] ^ xy[24] ^ xy[27] ^ xy[29] ^ xy[30];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[2] ^ xy[5] ^ xy[8] ^ xy[9] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[30];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[7] ^ xy[20] ^ xy[23] ^ xy[29] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[8] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[19] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[30];
}

void matrix_vector_product_11(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16];
    res[1] ^= 0 ^ xy[7] ^ xy[8] ^ xy[30];
    res[2] ^= 0 ^ xy[7] ^ xy[9] ^ xy[30];
    res[3] ^= 0 ^ xy[7] ^ xy[10] ^ xy[30];
    res[4] ^= 0 ^ xy[7] ^ xy[11] ^ xy[30];
    res[5] ^= 0 ^ xy[7] ^ xy[12] ^ xy[30];
    res[6] ^= 0 ^ xy[7] ^ xy[13] ^ xy[30];
    res[7] ^= 0 ^ xy[7] ^ xy[14] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[1] ^ xy[7] ^ xy[30];
    res[11] ^= 0 ^ xy[2] ^ xy[7] ^ xy[30];
    res[12] ^= 0 ^ xy[3] ^ xy[7] ^ xy[30];
    res[13] ^= 0 ^ xy[4] ^ xy[7] ^ xy[30];
    res[14] ^= 0 ^ xy[5] ^ xy[7] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[21] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[30];
    res[16] ^= 0 ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[7] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[10] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27];
}

void matrix_vector_product_12(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7];
    res[1] ^= 0 ^ xy[0] ^ xy[8];
    res[2] ^= 0 ^ xy[0] ^ xy[9];
    res[3] ^= 0 ^ xy[0] ^ xy[10];
    res[4] ^= 0 ^ xy[0] ^ xy[11];
    res[5] ^= 0 ^ xy[0] ^ xy[12];
    res[6] ^= 0 ^ xy[0] ^ xy[13];
    res[7] ^= 0 ^ xy[0] ^ xy[14];
    res[8] ^= 0 ^ xy[0] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[22] ^ xy[26] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[0];
    res[10] ^= 0 ^ xy[0] ^ xy[1];
    res[11] ^= 0 ^ xy[0] ^ xy[2];
    res[12] ^= 0 ^ xy[0] ^ xy[3];
    res[13] ^= 0 ^ xy[0] ^ xy[4];
    res[14] ^= 0 ^ xy[0] ^ xy[5];
    res[15] ^= 0 ^ xy[2] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[31];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[26] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16];
    res[19] ^= 0 ^ xy[3] ^ xy[17];
    res[20] ^= 0 ^ xy[4] ^ xy[18];
    res[21] ^= 0 ^ xy[5] ^ xy[19];
    res[22] ^= 0 ^ xy[6] ^ xy[20];
    res[23] ^= 0 ^ xy[7] ^ xy[21];
    res[24] ^= 0 ^ xy[8] ^ xy[22];
    res[25] ^= 0 ^ xy[9] ^ xy[23];
    res[26] ^= 0 ^ xy[10] ^ xy[24];
    res[27] ^= 0 ^ xy[11] ^ xy[25];
    res[28] ^= 0 ^ xy[12] ^ xy[26];
    res[29] ^= 0 ^ xy[13] ^ xy[27];
    res[30] ^= 0 ^ xy[14] ^ xy[28];
    res[31] ^= 0 ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[30] ^ xy[31];
}

void matrix_vector_product_13(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[23] ^ xy[26] ^ xy[27] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[30];
    res[10] ^= 0 ^ xy[1] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[2] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[3] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[4] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[5] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[15] ^ xy[18] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[29];
    res[16] ^= 0 ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[27] ^ xy[29];
}

void matrix_vector_product_14(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16];
    res[1] ^= 0 ^ xy[8] ^ xy[16];
    res[2] ^= 0 ^ xy[9] ^ xy[16];
    res[3] ^= 0 ^ xy[10] ^ xy[16];
    res[4] ^= 0 ^ xy[11] ^ xy[16];
    res[5] ^= 0 ^ xy[12] ^ xy[16];
    res[6] ^= 0 ^ xy[13] ^ xy[16];
    res[7] ^= 0 ^ xy[14] ^ xy[16];
    res[8] ^= 0 ^ xy[0] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[25] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[0] ^ xy[16];
    res[10] ^= 0 ^ xy[1] ^ xy[16];
    res[11] ^= 0 ^ xy[2] ^ xy[16];
    res[12] ^= 0 ^ xy[3] ^ xy[16];
    res[13] ^= 0 ^ xy[4] ^ xy[16];
    res[14] ^= 0 ^ xy[5] ^ xy[16];
    res[15] ^= 0 ^ xy[0] ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[9] ^ xy[13] ^ xy[18] ^ xy[19] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[29] ^ xy[31];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[2];
    res[19] ^= 0 ^ xy[3] ^ xy[17];
    res[20] ^= 0 ^ xy[4] ^ xy[18];
    res[21] ^= 0 ^ xy[5] ^ xy[19];
    res[22] ^= 0 ^ xy[6] ^ xy[20];
    res[23] ^= 0 ^ xy[7] ^ xy[21];
    res[24] ^= 0 ^ xy[8] ^ xy[22];
    res[25] ^= 0 ^ xy[9] ^ xy[23];
    res[26] ^= 0 ^ xy[10] ^ xy[24];
    res[27] ^= 0 ^ xy[11] ^ xy[25];
    res[28] ^= 0 ^ xy[12] ^ xy[26];
    res[29] ^= 0 ^ xy[13] ^ xy[27];
    res[30] ^= 0 ^ xy[14] ^ xy[28];
    res[31] ^= 0 ^ xy[4] ^ xy[9] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[31];
}

void matrix_vector_product_15(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7];
    res[1] ^= 0 ^ xy[8];
    res[2] ^= 0 ^ xy[9];
    res[3] ^= 0 ^ xy[10];
    res[4] ^= 0 ^ xy[11];
    res[5] ^= 0 ^ xy[12];
    res[6] ^= 0 ^ xy[13];
    res[7] ^= 0 ^ xy[14];
    res[8] ^= 0 ^ xy[0] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[22] ^ xy[23];
    res[9] ^= 0 ^ xy[16];
    res[10] ^= 0 ^ xy[1];
    res[11] ^= 0 ^ xy[2];
    res[12] ^= 0 ^ xy[3];
    res[13] ^= 0 ^ xy[4];
    res[14] ^= 0 ^ xy[5];
    res[15] ^= 0 ^ xy[2] ^ xy[3] ^ xy[7] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[20] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[28] ^ xy[29];
    res[16] ^= 0 ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[16] ^ xy[20] ^ xy[23] ^ xy[25] ^ xy[29] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2];
    res[19] ^= 0 ^ xy[3] ^ xy[17];
    res[20] ^= 0 ^ xy[4] ^ xy[18];
    res[21] ^= 0 ^ xy[5] ^ xy[19];
    res[22] ^= 0 ^ xy[6] ^ xy[20];
    res[23] ^= 0 ^ xy[7] ^ xy[21];
    res[24] ^= 0 ^ xy[8] ^ xy[22];
    res[25] ^= 0 ^ xy[9] ^ xy[23];
    res[26] ^= 0 ^ xy[10] ^ xy[24];
    res[27] ^= 0 ^ xy[11] ^ xy[25];
    res[28] ^= 0 ^ xy[12] ^ xy[26];
    res[29] ^= 0 ^ xy[13] ^ xy[27];
    res[30] ^= 0 ^ xy[14] ^ xy[28];
    res[31] ^= 0 ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[7] ^ xy[8] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[19] ^ xy[20] ^ xy[24] ^ xy[27] ^ xy[28] ^ xy[30] ^ xy[31];
}

void matrix_vector_product_16(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[7] ^ xy[8];
    res[2] ^= 0 ^ xy[7] ^ xy[9];
    res[3] ^= 0 ^ xy[7] ^ xy[10];
    res[4] ^= 0 ^ xy[7] ^ xy[11];
    res[5] ^= 0 ^ xy[7] ^ xy[12];
    res[6] ^= 0 ^ xy[7] ^ xy[13];
    res[7] ^= 0 ^ xy[7] ^ xy[14];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[7] ^ xy[16];
    res[10] ^= 0 ^ xy[1] ^ xy[7];
    res[11] ^= 0 ^ xy[2] ^ xy[7];
    res[12] ^= 0 ^ xy[3] ^ xy[7];
    res[13] ^= 0 ^ xy[4] ^ xy[7];
    res[14] ^= 0 ^ xy[5] ^ xy[7];
    res[15] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[6] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[23] ^ xy[27];
    res[16] ^= 0 ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7];
    res[19] ^= 0 ^ xy[3] ^ xy[7] ^ xy[17];
    res[20] ^= 0 ^ xy[4] ^ xy[7] ^ xy[18];
    res[21] ^= 0 ^ xy[5] ^ xy[7] ^ xy[19];
    res[22] ^= 0 ^ xy[6] ^ xy[7] ^ xy[20];
    res[23] ^= 0 ^ xy[21];
    res[24] ^= 0 ^ xy[7] ^ xy[8] ^ xy[22];
    res[25] ^= 0 ^ xy[7] ^ xy[9] ^ xy[23];
    res[26] ^= 0 ^ xy[7] ^ xy[10] ^ xy[24];
    res[27] ^= 0 ^ xy[7] ^ xy[11] ^ xy[25];
    res[28] ^= 0 ^ xy[7] ^ xy[12] ^ xy[26];
    res[29] ^= 0 ^ xy[7] ^ xy[13] ^ xy[27];
    res[30] ^= 0 ^ xy[7] ^ xy[14] ^ xy[28];
    res[31] ^= 0 ^ xy[2] ^ xy[6] ^ xy[10] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[29] ^ xy[31];
}

void matrix_vector_product_17(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[11] ^ xy[17] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[7] ^ xy[18] ^ xy[22] ^ xy[26] ^ xy[28] ^ xy[30] ^ xy[31];
    res[18] ^= 0 ^ xy[2] ^ xy[7] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[7] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[1] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[22] ^ xy[23];
}

void matrix_vector_product_18(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16];
    res[1] ^= 0 ^ xy[0] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[14] ^ xy[15] ^ xy[20] ^ xy[22] ^ xy[26] ^ xy[29];
    res[9] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[7] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[29] ^ xy[31];
    res[16] ^= 0 ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[17] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[7] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[10] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[26] ^ xy[28] ^ xy[30];
}

void matrix_vector_product_19(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[30];
    res[2] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[30];
    res[4] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[30];
    res[5] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[30];
    res[6] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[30];
    res[7] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[28] ^ xy[29];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[30];
    res[11] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[12] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[30];
    res[13] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[30];
    res[14] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[17] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[30];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[30];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[26] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[0] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[1] ^ xy[2] ^ xy[8] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[23] ^ xy[27] ^ xy[31];
}

void matrix_vector_product_20(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[7] ^ xy[16] ^ xy[30];
    res[1] ^= 0 ^ xy[7] ^ xy[8] ^ xy[30];
    res[2] ^= 0 ^ xy[7] ^ xy[9] ^ xy[30];
    res[3] ^= 0 ^ xy[7] ^ xy[10] ^ xy[30];
    res[4] ^= 0 ^ xy[7] ^ xy[11] ^ xy[30];
    res[5] ^= 0 ^ xy[7] ^ xy[12] ^ xy[30];
    res[6] ^= 0 ^ xy[7] ^ xy[13] ^ xy[30];
    res[7] ^= 0 ^ xy[7] ^ xy[14] ^ xy[30];
    res[8] ^= 0 ^ xy[0] ^ xy[7] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27];
    res[9] ^= 0 ^ xy[7] ^ xy[30];
    res[10] ^= 0 ^ xy[1] ^ xy[7] ^ xy[30];
    res[11] ^= 0 ^ xy[2] ^ xy[7] ^ xy[30];
    res[12] ^= 0 ^ xy[3] ^ xy[7] ^ xy[30];
    res[13] ^= 0 ^ xy[4] ^ xy[7] ^ xy[30];
    res[14] ^= 0 ^ xy[5] ^ xy[7] ^ xy[30];
    res[15] ^= 0 ^ xy[0] ^ xy[2] ^ xy[4] ^ xy[6] ^ xy[8] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28];
    res[16] ^= 0 ^ xy[7] ^ xy[16];
    res[17] ^= 0 ^ xy[1] ^ xy[7] ^ xy[17] ^ xy[18] ^ xy[24] ^ xy[28] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7] ^ xy[16] ^ xy[30];
    res[19] ^= 0 ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[17] ^ xy[30];
    res[20] ^= 0 ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[18] ^ xy[30];
    res[21] ^= 0 ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[19] ^ xy[30];
    res[22] ^= 0 ^ xy[6] ^ xy[7] ^ xy[16] ^ xy[20] ^ xy[30];
    res[23] ^= 0 ^ xy[16] ^ xy[21] ^ xy[30];
    res[24] ^= 0 ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[22] ^ xy[30];
    res[25] ^= 0 ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[23] ^ xy[30];
    res[26] ^= 0 ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[24] ^ xy[30];
    res[27] ^= 0 ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[25] ^ xy[30];
    res[28] ^= 0 ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[26] ^ xy[30];
    res[29] ^= 0 ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[27] ^ xy[30];
    res[30] ^= 0 ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[28] ^ xy[30];
    res[31] ^= 0 ^ xy[0] ^ xy[5] ^ xy[10] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[29] ^ xy[30];
}

void matrix_vector_product_21(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16];
    res[1] ^= 0 ^ xy[7] ^ xy[8];
    res[2] ^= 0 ^ xy[7] ^ xy[9];
    res[3] ^= 0 ^ xy[7] ^ xy[10];
    res[4] ^= 0 ^ xy[7] ^ xy[11];
    res[5] ^= 0 ^ xy[7] ^ xy[12];
    res[6] ^= 0 ^ xy[7] ^ xy[13];
    res[7] ^= 0 ^ xy[7] ^ xy[14];
    res[8] ^= 0 ^ xy[7] ^ xy[15] ^ xy[18] ^ xy[20] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28];
    res[9] ^= 0 ^ xy[7];
    res[10] ^= 0 ^ xy[1] ^ xy[7];
    res[11] ^= 0 ^ xy[2] ^ xy[7];
    res[12] ^= 0 ^ xy[3] ^ xy[7];
    res[13] ^= 0 ^ xy[4] ^ xy[7];
    res[14] ^= 0 ^ xy[5] ^ xy[7];
    res[15] ^= 0 ^ xy[1] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[0] ^ xy[7] ^ xy[16] ^ xy[30];
    res[17] ^= 0 ^ xy[1] ^ xy[7] ^ xy[16] ^ xy[21] ^ xy[23] ^ xy[26] ^ xy[29] ^ xy[31];
    res[18] ^= 0 ^ xy[0] ^ xy[2] ^ xy[7];
    res[19] ^= 0 ^ xy[0] ^ xy[3] ^ xy[7] ^ xy[16] ^ xy[17];
    res[20] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[16] ^ xy[18];
    res[21] ^= 0 ^ xy[0] ^ xy[5] ^ xy[7] ^ xy[16] ^ xy[19];
    res[22] ^= 0 ^ xy[0] ^ xy[6] ^ xy[7] ^ xy[16] ^ xy[20];
    res[23] ^= 0 ^ xy[0] ^ xy[16] ^ xy[21];
    res[24] ^= 0 ^ xy[0] ^ xy[7] ^ xy[8] ^ xy[16] ^ xy[22];
    res[25] ^= 0 ^ xy[0] ^ xy[7] ^ xy[9] ^ xy[16] ^ xy[23];
    res[26] ^= 0 ^ xy[0] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[24];
    res[27] ^= 0 ^ xy[0] ^ xy[7] ^ xy[11] ^ xy[16] ^ xy[25];
    res[28] ^= 0 ^ xy[0] ^ xy[7] ^ xy[12] ^ xy[16] ^ xy[26];
    res[29] ^= 0 ^ xy[0] ^ xy[7] ^ xy[13] ^ xy[16] ^ xy[27];
    res[30] ^= 0 ^ xy[0] ^ xy[7] ^ xy[14] ^ xy[16] ^ xy[28];
    res[31] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[5] ^ xy[8] ^ xy[10] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[26] ^ xy[27] ^ xy[31];
}

void matrix_vector_product_22(uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    res[0] ^= 0 ^ xy[0] ^ xy[1] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[13] ^ xy[14] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[28];
    res[1] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[14] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[30] ^ xy[31];
    res[2] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[9] ^ xy[12] ^ xy[13] ^ xy[15] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30];
    res[3] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[31];
    res[4] ^= 0 ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[15] ^ xy[19] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[5] ^= 0 ^ xy[0] ^ xy[2] ^ xy[5] ^ xy[8] ^ xy[9] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[19] ^ xy[21] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[29];
    res[6] ^= 0 ^ xy[3] ^ xy[5] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30];
    res[7] ^= 0 ^ xy[4] ^ xy[7] ^ xy[8] ^ xy[12] ^ xy[14] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30];
    res[8] ^= 0 ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[19] ^ xy[21] ^ xy[24] ^ xy[25] ^ xy[27] ^ xy[30] ^ xy[31];
    res[9] ^= 0 ^ xy[1] ^ xy[8] ^ xy[9] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[17] ^ xy[18] ^ xy[20] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30];
    res[10] ^= 0 ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[17] ^ xy[20] ^ xy[21] ^ xy[23] ^ xy[24] ^ xy[25];
    res[11] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[14] ^ xy[15] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[31];
    res[12] ^= 0 ^ xy[0] ^ xy[1] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[16] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[27];
    res[13] ^= 0 ^ xy[0] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[30] ^ xy[31];
    res[14] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[17] ^ xy[18] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[28] ^ xy[30];
    res[15] ^= 0 ^ xy[1] ^ xy[2] ^ xy[4] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[15] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[24] ^ xy[30] ^ xy[31];
    res[16] ^= 0 ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[6] ^ xy[7] ^ xy[10] ^ xy[16] ^ xy[17] ^ xy[21] ^ xy[22] ^ xy[26];
    res[17] ^= 0 ^ xy[0] ^ xy[1] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[12] ^ xy[13] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29];
    res[18] ^= 0 ^ xy[3] ^ xy[4] ^ xy[6] ^ xy[8] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[17] ^ xy[19] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[30];
    res[19] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[5] ^ xy[6] ^ xy[9] ^ xy[10] ^ xy[15] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30];
    res[20] ^= 0 ^ xy[0] ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[25] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[31];
    res[21] ^= 0 ^ xy[0] ^ xy[2] ^ xy[6] ^ xy[7] ^ xy[8] ^ xy[10] ^ xy[13] ^ xy[15] ^ xy[19] ^ xy[21] ^ xy[25] ^ xy[26] ^ xy[27];
    res[22] ^= 0 ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[23] ^ xy[25] ^ xy[29] ^ xy[31];
    res[23] ^= 0 ^ xy[1] ^ xy[3] ^ xy[4] ^ xy[5] ^ xy[6] ^ xy[7] ^ xy[9] ^ xy[10] ^ xy[16] ^ xy[18] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[30];
    res[24] ^= 0 ^ xy[2] ^ xy[3] ^ xy[5] ^ xy[6] ^ xy[8] ^ xy[11] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[19] ^ xy[22] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29];
    res[25] ^= 0 ^ xy[1] ^ xy[3] ^ xy[5] ^ xy[9] ^ xy[11] ^ xy[15] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[29] ^ xy[30] ^ xy[31];
    res[26] ^= 0 ^ xy[2] ^ xy[3] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[28] ^ xy[30] ^ xy[31];
    res[27] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[7] ^ xy[8] ^ xy[9] ^ xy[10] ^ xy[11] ^ xy[13] ^ xy[15] ^ xy[16] ^ xy[18] ^ xy[20] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[26] ^ xy[28];
    res[28] ^= 0 ^ xy[0] ^ xy[1] ^ xy[4] ^ xy[5] ^ xy[8] ^ xy[10] ^ xy[13] ^ xy[14] ^ xy[27] ^ xy[29];
    res[29] ^= 0 ^ xy[0] ^ xy[4] ^ xy[7] ^ xy[8] ^ xy[11] ^ xy[13] ^ xy[14] ^ xy[15] ^ xy[16] ^ xy[17] ^ xy[18] ^ xy[21] ^ xy[22] ^ xy[23] ^ xy[24] ^ xy[25] ^ xy[26] ^ xy[27];
    res[30] ^= 0 ^ xy[1] ^ xy[2] ^ xy[7] ^ xy[9] ^ xy[14] ^ xy[19] ^ xy[20] ^ xy[25] ^ xy[26] ^ xy[27] ^ xy[29] ^ xy[30] ^ xy[31];
    res[31] ^= 0 ^ xy[1] ^ xy[2] ^ xy[3] ^ xy[8] ^ xy[9] ^ xy[12] ^ xy[13] ^ xy[14] ^ xy[17] ^ xy[20] ^ xy[28] ^ xy[29];
}

void (*MATRIX_VECTOR_PRODUCTS[ROUNDS + 1])(uint8_t[BLOCK_SIZE], uint8_t[BLOCK_SIZE]) = {matrix_vector_product_0, matrix_vector_product_1, matrix_vector_product_2, matrix_vector_product_3, matrix_vector_product_4, matrix_vector_product_5, matrix_vector_product_6, matrix_vector_product_7, matrix_vector_product_8, matrix_vector_product_9, matrix_vector_product_10, matrix_vector_product_11, matrix_vector_product_12, matrix_vector_product_13, matrix_vector_product_14, matrix_vector_product_15, matrix_vector_product_16, matrix_vector_product_17, matrix_vector_product_18, matrix_vector_product_19, matrix_vector_product_20, matrix_vector_product_21, matrix_vector_product_22};

void vector_addition_0(uint8_t xy[BLOCK_SIZE]) {
}

void vector_addition_1(uint8_t xy[BLOCK_SIZE]) {
    xy[2] ^= 1;
    xy[5] ^= 1;
    xy[6] ^= 1;
    xy[8] ^= 1;
    xy[10] ^= 1;
    xy[12] ^= 1;
    xy[14] ^= 1;
    xy[15] ^= 1;
    xy[16] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[30] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_2(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[8] ^= 1;
    xy[10] ^= 1;
    xy[15] ^= 1;
    xy[16] ^= 1;
    xy[22] ^= 1;
    xy[23] ^= 1;
    xy[30] ^= 1;
}

void vector_addition_3(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[3] ^= 1;
    xy[5] ^= 1;
    xy[7] ^= 1;
    xy[8] ^= 1;
    xy[10] ^= 1;
    xy[12] ^= 1;
    xy[13] ^= 1;
    xy[14] ^= 1;
    xy[15] ^= 1;
    xy[16] ^= 1;
    xy[17] ^= 1;
    xy[18] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[27] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
}

void vector_addition_4(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[3] ^= 1;
    xy[4] ^= 1;
    xy[11] ^= 1;
    xy[13] ^= 1;
    xy[16] ^= 1;
    xy[19] ^= 1;
    xy[22] ^= 1;
    xy[25] ^= 1;
    xy[28] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_5(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[3] ^= 1;
    xy[4] ^= 1;
    xy[5] ^= 1;
    xy[7] ^= 1;
    xy[13] ^= 1;
    xy[16] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[21] ^= 1;
    xy[24] ^= 1;
    xy[25] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_6(uint8_t xy[BLOCK_SIZE]) {
    xy[2] ^= 1;
    xy[3] ^= 1;
    xy[5] ^= 1;
    xy[6] ^= 1;
    xy[7] ^= 1;
    xy[9] ^= 1;
    xy[10] ^= 1;
    xy[12] ^= 1;
    xy[13] ^= 1;
    xy[14] ^= 1;
    xy[19] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[23] ^= 1;
    xy[25] ^= 1;
    xy[26] ^= 1;
    xy[28] ^= 1;
    xy[29] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_7(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[4] ^= 1;
    xy[8] ^= 1;
    xy[9] ^= 1;
    xy[11] ^= 1;
    xy[13] ^= 1;
    xy[14] ^= 1;
    xy[15] ^= 1;
    xy[18] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[24] ^= 1;
    xy[25] ^= 1;
    xy[27] ^= 1;
    xy[30] ^= 1;
}

void vector_addition_8(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[4] ^= 1;
    xy[7] ^= 1;
    xy[10] ^= 1;
    xy[14] ^= 1;
    xy[16] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[23] ^= 1;
    xy[24] ^= 1;
    xy[25] ^= 1;
    xy[27] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_9(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[3] ^= 1;
    xy[6] ^= 1;
    xy[7] ^= 1;
    xy[8] ^= 1;
    xy[9] ^= 1;
    xy[11] ^= 1;
    xy[17] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[23] ^= 1;
    xy[24] ^= 1;
    xy[26] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
    xy[31] ^= 1;
}

void vector_addition_10(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[3] ^= 1;
    xy[4] ^= 1;
    xy[5] ^= 1;
    xy[7] ^= 1;
    xy[8] ^= 1;
    xy[9] ^= 1;
    xy[10] ^= 1;
    xy[11] ^= 1;
    xy[16] ^= 1;
    xy[18] ^= 1;
    xy[21] ^= 1;
    xy[23] ^= 1;
    xy[24] ^= 1;
    xy[26] ^= 1;
    xy[27] ^= 1;
    xy[28] ^= 1;
    xy[30] ^= 1;
}

void vector_addition_11(uint8_t xy[BLOCK_SIZE]) {
    xy[3] ^= 1;
    xy[5] ^= 1;
    xy[6] ^= 1;
    xy[7] ^= 1;
    xy[10] ^= 1;
    xy[13] ^= 1;
    xy[17] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[26] ^= 1;
    xy[28] ^= 1;
    xy[29] ^= 1;
}

void vector_addition_12(uint8_t xy[BLOCK_SIZE]) {
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[4] ^= 1;
    xy[6] ^= 1;
    xy[8] ^= 1;
    xy[10] ^= 1;
    xy[13] ^= 1;
    xy[14] ^= 1;
    xy[15] ^= 1;
    xy[16] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[23] ^= 1;
    xy[26] ^= 1;
    xy[28] ^= 1;
}

void vector_addition_13(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[4] ^= 1;
    xy[9] ^= 1;
    xy[10] ^= 1;
    xy[13] ^= 1;
    xy[14] ^= 1;
    xy[15] ^= 1;
    xy[16] ^= 1;
    xy[17] ^= 1;
    xy[18] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[23] ^= 1;
    xy[24] ^= 1;
    xy[25] ^= 1;
    xy[27] ^= 1;
}

void vector_addition_14(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[2] ^= 1;
    xy[3] ^= 1;
    xy[4] ^= 1;
    xy[5] ^= 1;
    xy[7] ^= 1;
    xy[12] ^= 1;
    xy[15] ^= 1;
    xy[19] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[23] ^= 1;
    xy[25] ^= 1;
    xy[26] ^= 1;
    xy[27] ^= 1;
    xy[28] ^= 1;
}

void vector_addition_15(uint8_t xy[BLOCK_SIZE]) {
    xy[2] ^= 1;
    xy[6] ^= 1;
    xy[8] ^= 1;
    xy[13] ^= 1;
    xy[18] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[25] ^= 1;
    xy[29] ^= 1;
}

void vector_addition_16(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[2] ^= 1;
    xy[4] ^= 1;
    xy[6] ^= 1;
    xy[9] ^= 1;
    xy[12] ^= 1;
    xy[14] ^= 1;
    xy[16] ^= 1;
    xy[17] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[25] ^= 1;
    xy[27] ^= 1;
    xy[29] ^= 1;
}

void vector_addition_17(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[3] ^= 1;
    xy[7] ^= 1;
    xy[10] ^= 1;
    xy[11] ^= 1;
    xy[14] ^= 1;
    xy[16] ^= 1;
    xy[19] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[25] ^= 1;
    xy[27] ^= 1;
    xy[28] ^= 1;
    xy[29] ^= 1;
}

void vector_addition_18(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[2] ^= 1;
    xy[12] ^= 1;
    xy[16] ^= 1;
    xy[17] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[23] ^= 1;
    xy[25] ^= 1;
}

void vector_addition_19(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[4] ^= 1;
    xy[6] ^= 1;
    xy[9] ^= 1;
    xy[10] ^= 1;
    xy[12] ^= 1;
    xy[13] ^= 1;
    xy[16] ^= 1;
    xy[19] ^= 1;
    xy[20] ^= 1;
    xy[23] ^= 1;
    xy[24] ^= 1;
    xy[27] ^= 1;
    xy[29] ^= 1;
}

void vector_addition_20(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[1] ^= 1;
    xy[2] ^= 1;
    xy[3] ^= 1;
    xy[4] ^= 1;
    xy[6] ^= 1;
    xy[10] ^= 1;
    xy[13] ^= 1;
    xy[15] ^= 1;
    xy[18] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[22] ^= 1;
    xy[24] ^= 1;
    xy[25] ^= 1;
    xy[26] ^= 1;
    xy[27] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
}

void vector_addition_21(uint8_t xy[BLOCK_SIZE]) {
    xy[0] ^= 1;
    xy[4] ^= 1;
    xy[5] ^= 1;
    xy[11] ^= 1;
    xy[12] ^= 1;
    xy[13] ^= 1;
    xy[16] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[20] ^= 1;
    xy[21] ^= 1;
    xy[27] ^= 1;
    xy[28] ^= 1;
}

void vector_addition_22(uint8_t xy[BLOCK_SIZE]) {
    xy[1] ^= 1;
    xy[4] ^= 1;
    xy[5] ^= 1;
    xy[6] ^= 1;
    xy[7] ^= 1;
    xy[8] ^= 1;
    xy[10] ^= 1;
    xy[11] ^= 1;
    xy[15] ^= 1;
    xy[17] ^= 1;
    xy[18] ^= 1;
    xy[19] ^= 1;
    xy[22] ^= 1;
    xy[23] ^= 1;
    xy[27] ^= 1;
    xy[28] ^= 1;
    xy[29] ^= 1;
    xy[30] ^= 1;
}

void (*VECTOR_ADDITIONS[ROUNDS + 1])(uint8_t[BLOCK_SIZE]) = {vector_addition_0, vector_addition_1, vector_addition_2, vector_addition_3, vector_addition_4, vector_addition_5, vector_addition_6, vector_addition_7, vector_addition_8, vector_addition_9, vector_addition_10, vector_addition_11, vector_addition_12, vector_addition_13, vector_addition_14, vector_addition_15, vector_addition_16, vector_addition_17, vector_addition_18, vector_addition_19, vector_addition_20, vector_addition_21, vector_addition_22};

void from_bits(uint8_t bits[BLOCK_SIZE], WORD_TYPE *x, WORD_TYPE *y) {
    *x = 0;
    *y = 0;
    for (size_t i = 0; i < WORD_SIZE; i++) {
        *x |= ((WORD_TYPE) bits[i]) << i;
        *y |= ((WORD_TYPE) bits[WORD_SIZE + i]) << i;
    }
}

void to_bits(WORD_TYPE x, WORD_TYPE y, uint8_t bits[BLOCK_SIZE]) {
    for (size_t i = 0; i < WORD_SIZE; i++) {
        bits[i] = (x >> i) & 1;
        bits[WORD_SIZE + i] = (y >> i) & 1;
    }
}

void modular_addition(uint8_t xy[BLOCK_SIZE]) {
    uint8_t carry = 0;
    for (size_t i = 0; i < WORD_SIZE; i++) {
        xy[i] = xy[i] + xy[WORD_SIZE + i] + carry;
        carry = xy[i] > 1;
        xy[i] &= 1;
    }
}

void encrypt(WORD_TYPE p[2], WORD_TYPE c[2]) {
    uint8_t xy[BLOCK_SIZE];
    uint8_t res[BLOCK_SIZE];
    to_bits(p[0], p[1], xy);
    for (size_t i = 0; i < ROUNDS; i++) {
        memset(&res, 0, BLOCK_SIZE * sizeof(uint8_t));
        MATRIX_VECTOR_PRODUCTS[i](xy, res);
        VECTOR_ADDITIONS[i](res);
        modular_addition(res);
        memcpy(&xy, &res, BLOCK_SIZE * sizeof(uint8_t));
    }

    memset(&res, 0, BLOCK_SIZE * sizeof(uint8_t));
    MATRIX_VECTOR_PRODUCTS[ROUNDS](xy, res);
    VECTOR_ADDITIONS[ROUNDS](res);
    from_bits(res, &c[0], &c[1]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
    WORD_TYPE p[2];
    WORD_TYPE c[2];
    if (argc < 3) {
        size_t iterations;
        sscanf(argv[1], "%zu", &iterations);
        for (int i = 0; i < iterations; i++) {
            p[0] = (((WORD_TYPE) rand()) << (WORD_SIZE / 2)) | ((WORD_TYPE) rand());
            p[1] = (((WORD_TYPE) rand()) << (WORD_SIZE / 2)) | ((WORD_TYPE) rand());
            encrypt(p, c);
        }
        return -1;
    } else {
        sscanf(argv[1], "%" WORD_IN_TYPE, &p[0]);
        sscanf(argv[2], "%" WORD_IN_TYPE, &p[1]);
        encrypt(p, c);
        printf("%" WORD_OUT_TYPE " %" WORD_OUT_TYPE "\n", c[0], c[1]);
    }
}
