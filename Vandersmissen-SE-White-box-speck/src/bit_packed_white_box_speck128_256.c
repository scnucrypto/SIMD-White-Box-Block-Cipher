#include "bit_packed_white_box_speck128_256.h"

void bit_packed_matrix_vector_product(WORD_TYPE matrix[BLOCK_SIZE][2], WORD_TYPE xy[2], WORD_TYPE res[2]) {
    for (size_t i = WORD_SIZE; i-- > 0;) {
        res[0] = (res[0] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[i][0] & xy[0]) ^ (matrix[i][1] & xy[1])));
        res[1] = (res[1] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[WORD_SIZE + i][0] & xy[0]) ^ (matrix[WORD_SIZE + i][1] & xy[1])));
    }
}

void bit_packed_vector_addition(WORD_TYPE vector[2], WORD_TYPE xy[2]) {
    xy[0] ^= vector[0];
    xy[1] ^= vector[1];
}

void bit_packed_modular_addition(WORD_TYPE xy[2]) {
    xy[0] = (xy[0] + xy[1]) & WORD_MASK;
}

void bit_packed_encrypt(WORD_TYPE p[2], WORD_TYPE c[2]) {
    WORD_TYPE res[2];
    c[0] = p[0];
    c[1] = p[1];
    for (size_t i = 0; i < ROUNDS; i++) {
        res[0] = 0;
        res[1] = 0;
        bit_packed_matrix_vector_product(MATRICES[i], c, res);
        bit_packed_vector_addition(VECTORS[i], res);
        bit_packed_modular_addition(res);
        c[0] = res[0];
        c[1] = res[1];
    }
    res[0] = 0;
    res[1] = 0;
    bit_packed_matrix_vector_product(MATRICES[ROUNDS], c, res);
    bit_packed_vector_addition(VECTORS[ROUNDS], res);
    c[0] = res[0];
    c[1] = res[1];
}
int wbspeck_se_bit_packed_encrypt(const unsigned char *input, unsigned char *output){
    WORD_TYPE p[2] = {0};
    WORD_TYPE c[2] = {0};
    p[0] = GET64(input);
    p[1] = GET64(input + 8);
    bit_packed_encrypt(p,c);
    PUT64(c[0],output);
    PUT64(c[1],output + 8);
}

int wbspeck_se_bit_packed_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len){
    assert (len % 16 == 0);
    while (len) {
        wbspeck_se_bit_packed_encrypt(input,output);
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
