#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 64
#define WORD_SIZE 32
#define WORD_TYPE uint32_t
#define WORD_IN_TYPE SCNx32
#define WORD_OUT_TYPE PRIx32
#define WORD_CONSTANT_TYPE UINT32_C
#define WORD_PARITY_FUNCTION __builtin_parityl
#define WORD_MASK 0xffffffff
#define ROUNDS 0

WORD_TYPE MATRICES[ROUNDS + 1][BLOCK_SIZE][2] = {
    {{WORD_CONSTANT_TYPE(4293106988), WORD_CONSTANT_TYPE(3461231603)}, {WORD_CONSTANT_TYPE(961778476), WORD_CONSTANT_TYPE(3409894133)}, {WORD_CONSTANT_TYPE(485403556), WORD_CONSTANT_TYPE(1569228627)}, {WORD_CONSTANT_TYPE(1387160080), WORD_CONSTANT_TYPE(2514253795)}, {WORD_CONSTANT_TYPE(1898229248), WORD_CONSTANT_TYPE(722035370)}, {WORD_CONSTANT_TYPE(109359458), WORD_CONSTANT_TYPE(3065576204)}, {WORD_CONSTANT_TYPE(3388122527), WORD_CONSTANT_TYPE(919696144)}, {WORD_CONSTANT_TYPE(3244235766), WORD_CONSTANT_TYPE(3007027642)}, {WORD_CONSTANT_TYPE(603152162), WORD_CONSTANT_TYPE(693836402)}, {WORD_CONSTANT_TYPE(354541276), WORD_CONSTANT_TYPE(3506438750)}, {WORD_CONSTANT_TYPE(3726716235), WORD_CONSTANT_TYPE(423781886)}, {WORD_CONSTANT_TYPE(3896788254), WORD_CONSTANT_TYPE(3716219983)}, {WORD_CONSTANT_TYPE(1928703023), WORD_CONSTANT_TYPE(1699823100)}, {WORD_CONSTANT_TYPE(1586869737), WORD_CONSTANT_TYPE(3101509308)}, {WORD_CONSTANT_TYPE(1106550092), WORD_CONSTANT_TYPE(2109599486)}, {WORD_CONSTANT_TYPE(1843159177), WORD_CONSTANT_TYPE(3962333194)}, {WORD_CONSTANT_TYPE(4197415813), WORD_CONSTANT_TYPE(4070307393)}, {WORD_CONSTANT_TYPE(3535367905), WORD_CONSTANT_TYPE(1621053049)}, {WORD_CONSTANT_TYPE(3831847710), WORD_CONSTANT_TYPE(3297181107)}, {WORD_CONSTANT_TYPE(3738027652), WORD_CONSTANT_TYPE(2151118663)}, {WORD_CONSTANT_TYPE(165499464), WORD_CONSTANT_TYPE(4038989088)}, {WORD_CONSTANT_TYPE(2493009359), WORD_CONSTANT_TYPE(2298219778)}, {WORD_CONSTANT_TYPE(932789730), WORD_CONSTANT_TYPE(2612400906)}, {WORD_CONSTANT_TYPE(2381167398), WORD_CONSTANT_TYPE(1260048967)}, {WORD_CONSTANT_TYPE(1621828709), WORD_CONSTANT_TYPE(1203491023)}, {WORD_CONSTANT_TYPE(1707438073), WORD_CONSTANT_TYPE(3168081470)}, {WORD_CONSTANT_TYPE(1105306162), WORD_CONSTANT_TYPE(1870256581)}, {WORD_CONSTANT_TYPE(644635116), WORD_CONSTANT_TYPE(2313115102)}, {WORD_CONSTANT_TYPE(234927020), WORD_CONSTANT_TYPE(1264589712)}, {WORD_CONSTANT_TYPE(2284705697), WORD_CONSTANT_TYPE(338906794)}, {WORD_CONSTANT_TYPE(67780019), WORD_CONSTANT_TYPE(4282023459)}, {WORD_CONSTANT_TYPE(3390558600), WORD_CONSTANT_TYPE(140392387)}, {WORD_CONSTANT_TYPE(2023591899), WORD_CONSTANT_TYPE(3856133753)}, {WORD_CONSTANT_TYPE(1692295192), WORD_CONSTANT_TYPE(3899279885)}, {WORD_CONSTANT_TYPE(1319415851), WORD_CONSTANT_TYPE(3691454104)}, {WORD_CONSTANT_TYPE(2752397019), WORD_CONSTANT_TYPE(3577013136)}, {WORD_CONSTANT_TYPE(3185054169), WORD_CONSTANT_TYPE(4073944090)}, {WORD_CONSTANT_TYPE(3491485839), WORD_CONSTANT_TYPE(870884661)}, {WORD_CONSTANT_TYPE(1765046564), WORD_CONSTANT_TYPE(56937029)}, {WORD_CONSTANT_TYPE(3544305568), WORD_CONSTANT_TYPE(2267187413)}, {WORD_CONSTANT_TYPE(4095770388), WORD_CONSTANT_TYPE(3579189111)}, {WORD_CONSTANT_TYPE(517467971), WORD_CONSTANT_TYPE(1652210172)}, {WORD_CONSTANT_TYPE(942289539), WORD_CONSTANT_TYPE(4128948)}, {WORD_CONSTANT_TYPE(431379743), WORD_CONSTANT_TYPE(2011952942)}, {WORD_CONSTANT_TYPE(3354174699), WORD_CONSTANT_TYPE(3808837664)}, {WORD_CONSTANT_TYPE(1517022505), WORD_CONSTANT_TYPE(1470641379)}, {WORD_CONSTANT_TYPE(25229043), WORD_CONSTANT_TYPE(4162573112)}, {WORD_CONSTANT_TYPE(2788452073), WORD_CONSTANT_TYPE(3852827944)}, {WORD_CONSTANT_TYPE(2066184743), WORD_CONSTANT_TYPE(1348852715)}, {WORD_CONSTANT_TYPE(884488317), WORD_CONSTANT_TYPE(2400394569)}, {WORD_CONSTANT_TYPE(149397806), WORD_CONSTANT_TYPE(130067117)}, {WORD_CONSTANT_TYPE(3444320432), WORD_CONSTANT_TYPE(1337375073)}, {WORD_CONSTANT_TYPE(2859496686), WORD_CONSTANT_TYPE(125177929)}, {WORD_CONSTANT_TYPE(3857841267), WORD_CONSTANT_TYPE(2864974879)}, {WORD_CONSTANT_TYPE(1062731304), WORD_CONSTANT_TYPE(3544088820)}, {WORD_CONSTANT_TYPE(743749999), WORD_CONSTANT_TYPE(3664322625)}, {WORD_CONSTANT_TYPE(55124632), WORD_CONSTANT_TYPE(1621316882)}, {WORD_CONSTANT_TYPE(214703793), WORD_CONSTANT_TYPE(4017087886)}, {WORD_CONSTANT_TYPE(3963589957), WORD_CONSTANT_TYPE(946281590)}, {WORD_CONSTANT_TYPE(2722987822), WORD_CONSTANT_TYPE(2272447546)}, {WORD_CONSTANT_TYPE(893392047), WORD_CONSTANT_TYPE(1437519828)}, {WORD_CONSTANT_TYPE(489419245), WORD_CONSTANT_TYPE(2416238088)}, {WORD_CONSTANT_TYPE(3577451678), WORD_CONSTANT_TYPE(3183396049)}, {WORD_CONSTANT_TYPE(2750971121), WORD_CONSTANT_TYPE(2021591991)}}
};

WORD_TYPE VECTORS[ROUNDS + 1][2] = {{WORD_CONSTANT_TYPE(4094269973), WORD_CONSTANT_TYPE(1449774367)}};

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