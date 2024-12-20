#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 32
#define WORD_SIZE 16
#define WORD_TYPE uint16_t
#define WORD_IN_TYPE SCNx16
#define WORD_OUT_TYPE PRIx16
#define WORD_CONSTANT_TYPE UINT16_C
#define WORD_PARITY_FUNCTION __builtin_parity
#define WORD_MASK 0xffff
#define ROUNDS 0

WORD_TYPE MATRICES[ROUNDS + 1][BLOCK_SIZE][2] = {
    {{WORD_CONSTANT_TYPE(30215), WORD_CONSTANT_TYPE(28033)}, {WORD_CONSTANT_TYPE(44137), WORD_CONSTANT_TYPE(27478)}, {WORD_CONSTANT_TYPE(64982), WORD_CONSTANT_TYPE(46314)}, {WORD_CONSTANT_TYPE(14683), WORD_CONSTANT_TYPE(21647)}, {WORD_CONSTANT_TYPE(14370), WORD_CONSTANT_TYPE(37231)}, {WORD_CONSTANT_TYPE(63488), WORD_CONSTANT_TYPE(15119)}, {WORD_CONSTANT_TYPE(44166), WORD_CONSTANT_TYPE(35113)}, {WORD_CONSTANT_TYPE(20480), WORD_CONSTANT_TYPE(55752)}, {WORD_CONSTANT_TYPE(268), WORD_CONSTANT_TYPE(27307)}, {WORD_CONSTANT_TYPE(4572), WORD_CONSTANT_TYPE(10091)}, {WORD_CONSTANT_TYPE(18917), WORD_CONSTANT_TYPE(49354)}, {WORD_CONSTANT_TYPE(3289), WORD_CONSTANT_TYPE(42376)}, {WORD_CONSTANT_TYPE(65422), WORD_CONSTANT_TYPE(48734)}, {WORD_CONSTANT_TYPE(30093), WORD_CONSTANT_TYPE(9486)}, {WORD_CONSTANT_TYPE(41342), WORD_CONSTANT_TYPE(3758)}, {WORD_CONSTANT_TYPE(60161), WORD_CONSTANT_TYPE(19401)}, {WORD_CONSTANT_TYPE(41784), WORD_CONSTANT_TYPE(20516)}, {WORD_CONSTANT_TYPE(26599), WORD_CONSTANT_TYPE(37835)}, {WORD_CONSTANT_TYPE(62581), WORD_CONSTANT_TYPE(59297)}, {WORD_CONSTANT_TYPE(50877), WORD_CONSTANT_TYPE(13309)}, {WORD_CONSTANT_TYPE(33312), WORD_CONSTANT_TYPE(42801)}, {WORD_CONSTANT_TYPE(58802), WORD_CONSTANT_TYPE(13183)}, {WORD_CONSTANT_TYPE(58207), WORD_CONSTANT_TYPE(55395)}, {WORD_CONSTANT_TYPE(14021), WORD_CONSTANT_TYPE(57736)}, {WORD_CONSTANT_TYPE(1050), WORD_CONSTANT_TYPE(2678)}, {WORD_CONSTANT_TYPE(4483), WORD_CONSTANT_TYPE(54964)}, {WORD_CONSTANT_TYPE(61389), WORD_CONSTANT_TYPE(33397)}, {WORD_CONSTANT_TYPE(62284), WORD_CONSTANT_TYPE(57184)}, {WORD_CONSTANT_TYPE(51259), WORD_CONSTANT_TYPE(63273)}, {WORD_CONSTANT_TYPE(35654), WORD_CONSTANT_TYPE(3676)}, {WORD_CONSTANT_TYPE(14997), WORD_CONSTANT_TYPE(64959)}, {WORD_CONSTANT_TYPE(37788), WORD_CONSTANT_TYPE(24045)}}
};

WORD_TYPE VECTORS[ROUNDS + 1][2] = {{WORD_CONSTANT_TYPE(3187), WORD_CONSTANT_TYPE(17929)}};

void matrix_vector_product(WORD_TYPE matrix[BLOCK_SIZE][2], WORD_TYPE xy[2], WORD_TYPE res[2]) {
    for (size_t i = WORD_SIZE; i-- > 0;) {
        res[0] = (res[0] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[i][0] & xy[0]) ^ (matrix[i][1] & xy[1])));
        res[1] = (res[1] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[WORD_SIZE + i][0] & xy[0]) ^ (matrix[WORD_SIZE + i][1] & xy[1])));
    }
}

void vector_addition(WORD_TYPE vector[2], WORD_TYPE xy[2]) {
    xy[0] ^= vector[0];
    xy[1] ^= vector[1];
}

void modular_addition(WORD_TYPE xy[2]) {
    xy[0] = (xy[0] + xy[1]) & WORD_MASK;
}

int main(int argc, char *argv[]) {
    WORD_TYPE xy[2];
    WORD_TYPE res[2];
    if (argc < 3) {
        return -1;
    } else {
        sscanf(argv[1], "%" WORD_IN_TYPE, &xy[0]);
        sscanf(argv[2], "%" WORD_IN_TYPE, &xy[1]);
        vector_addition(VECTORS[0], xy);
        res[0] = 0;
        res[1] = 0;
        matrix_vector_product(MATRICES[0], xy, res);
        printf("%" WORD_OUT_TYPE " %" WORD_OUT_TYPE "\n", res[0], res[1]);
    }
}
