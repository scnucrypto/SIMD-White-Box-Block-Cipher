#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sparse_matrix_white_box_speck128_256.h"

void sparse_matrix_from_bits(uint8_t bits[BLOCK_SIZE], WORD_TYPE *x, WORD_TYPE *y) {
    *x = 0;
    *y = 0;
    for (size_t i = 0; i < WORD_SIZE; i++) {
        *x |= ((WORD_TYPE) bits[i]) << i;
        *y |= ((WORD_TYPE) bits[WORD_SIZE + i]) << i;
    }
}

void sparse_matrix_to_bits(WORD_TYPE x, WORD_TYPE y, uint8_t bits[BLOCK_SIZE]) {
    for (size_t i = 0; i < WORD_SIZE; i++) {
        bits[i] = (x >> i) & 1;
        bits[WORD_SIZE + i] = (y >> i) & 1;
    }
}

void sparse_matrix_matrix_vector_product(uint8_t sparse_matrix[][2], uint16_t sparse_matrix_entries, uint8_t xy[BLOCK_SIZE], uint8_t res[BLOCK_SIZE]) {
    for (uint16_t i = 0; i < sparse_matrix_entries; i++) {
        res[sparse_matrix[i][0]] ^= xy[sparse_matrix[i][1]];
    }
}

void sparse_matrix_vector_addition(uint8_t sparse_vector[], uint8_t sparse_vector_entries, uint8_t xy[BLOCK_SIZE]) {
    for (uint8_t i = 0; i < sparse_vector_entries; i++) {
        xy[sparse_vector[i]] ^= 1;
    }
}

void sparse_matrix_modular_addition(uint8_t xy[BLOCK_SIZE]) {
    uint8_t carry = 0;
    for (size_t i = 0; i < WORD_SIZE; i++) {
        xy[i] = xy[i] + xy[WORD_SIZE + i] + carry;
        carry = xy[i] > 1;
        xy[i] &= 1;
    }
}

void sparse_matrix_encrypt(WORD_TYPE p[2], WORD_TYPE c[2]) {
    uint8_t xy[BLOCK_SIZE];
    uint8_t res[BLOCK_SIZE];
    sparse_matrix_to_bits(p[0], p[1], xy);
    for (size_t i = 0; i < ROUNDS; i++) {
        memset(&res, 0, BLOCK_SIZE);
        sparse_matrix_matrix_vector_product(SPARSE_MATRICES[i], SPARSE_MATRIX_ENTRIES[i], xy, res);
        sparse_matrix_vector_addition(SPARSE_VECTORS[i], SPARSE_VECTOR_ENTRIES[i], res);
        sparse_matrix_modular_addition(res);
        memcpy(&xy, &res, sizeof(res));
    }

    memset(&res, 0, BLOCK_SIZE);
    sparse_matrix_matrix_vector_product(SPARSE_MATRICES[ROUNDS], SPARSE_MATRIX_ENTRIES[ROUNDS], xy, res);
    sparse_matrix_vector_addition(SPARSE_VECTORS[ROUNDS], SPARSE_VECTOR_ENTRIES[ROUNDS], res);
    sparse_matrix_from_bits(res, &c[0], &c[1]);
}
int wbspeck_se_sparse_matrix_encrypt(const unsigned char *input, unsigned char *output){
    WORD_TYPE p[2] = {0};
    WORD_TYPE c[2] = {0};
    p[0] = GET64(input);
    p[1] = GET64(input + 8);
    sparse_matrix_encrypt(p,c);
    PUT64(c[0],output);
    PUT64(c[1],output + 8);
}

int wbspeck_se_sparse_matrix_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len){
    assert (len % 16 == 0);
    while (len) {
        wbspeck_se_sparse_matrix_encrypt(input,output);
        len -= 16;
        input += 16;
        output += 16;
    }
}
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
