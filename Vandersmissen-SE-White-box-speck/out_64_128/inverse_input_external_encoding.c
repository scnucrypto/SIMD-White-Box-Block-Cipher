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
#define ROUNDS 2

WORD_TYPE MATRICES[ROUNDS + 1][BLOCK_SIZE][2] = {
    {{WORD_CONSTANT_TYPE(256), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(512), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1024), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2048), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4096), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8192), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16384), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32768), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(65536), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(131072), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(262144), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(524288), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1048576), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2097152), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4194304), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8388608), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16777216), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(33554432), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(67108864), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(134217728), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(268435456), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(536870912), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1073741824), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2147483648), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(64), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(128), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(64)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(128)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(256)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(512)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1024)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2048)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4096)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8192)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16384)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32768)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(65536)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(131072)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(262144)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(524288)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1048576)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2097152)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4194304)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8388608)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16777216)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(33554432)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(67108864)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(134217728)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(268435456)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(536870912)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1073741824)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2147483648)}},
    {{WORD_CONSTANT_TYPE(1869672472), WORD_CONSTANT_TYPE(2967628856)}, {WORD_CONSTANT_TYPE(4088235987), WORD_CONSTANT_TYPE(2167667084)}, {WORD_CONSTANT_TYPE(4137785526), WORD_CONSTANT_TYPE(2325007124)}, {WORD_CONSTANT_TYPE(2268564353), WORD_CONSTANT_TYPE(3212574644)}, {WORD_CONSTANT_TYPE(2586823581), WORD_CONSTANT_TYPE(1802610357)}, {WORD_CONSTANT_TYPE(3093683043), WORD_CONSTANT_TYPE(270372894)}, {WORD_CONSTANT_TYPE(1025240360), WORD_CONSTANT_TYPE(3261087796)}, {WORD_CONSTANT_TYPE(690881), WORD_CONSTANT_TYPE(1356411029)}, {WORD_CONSTANT_TYPE(3613179128), WORD_CONSTANT_TYPE(2115133406)}, {WORD_CONSTANT_TYPE(1119222527), WORD_CONSTANT_TYPE(815415312)}, {WORD_CONSTANT_TYPE(2830806761), WORD_CONSTANT_TYPE(3566825018)}, {WORD_CONSTANT_TYPE(690368925), WORD_CONSTANT_TYPE(1052655049)}, {WORD_CONSTANT_TYPE(547046311), WORD_CONSTANT_TYPE(1336515929)}, {WORD_CONSTANT_TYPE(865053471), WORD_CONSTANT_TYPE(1918979480)}, {WORD_CONSTANT_TYPE(3116704610), WORD_CONSTANT_TYPE(156713365)}, {WORD_CONSTANT_TYPE(205407149), WORD_CONSTANT_TYPE(2014517905)}, {WORD_CONSTANT_TYPE(4189054515), WORD_CONSTANT_TYPE(3072698828)}, {WORD_CONSTANT_TYPE(2877330420), WORD_CONSTANT_TYPE(2494283134)}, {WORD_CONSTANT_TYPE(1580216441), WORD_CONSTANT_TYPE(3772357141)}, {WORD_CONSTANT_TYPE(202899555), WORD_CONSTANT_TYPE(4233193112)}, {WORD_CONSTANT_TYPE(1508698622), WORD_CONSTANT_TYPE(1821690914)}, {WORD_CONSTANT_TYPE(3564045702), WORD_CONSTANT_TYPE(3857384652)}, {WORD_CONSTANT_TYPE(2928905396), WORD_CONSTANT_TYPE(396373297)}, {WORD_CONSTANT_TYPE(4079585744), WORD_CONSTANT_TYPE(576049071)}, {WORD_CONSTANT_TYPE(3543790544), WORD_CONSTANT_TYPE(2063696146)}, {WORD_CONSTANT_TYPE(1103823453), WORD_CONSTANT_TYPE(3274451422)}, {WORD_CONSTANT_TYPE(2617620794), WORD_CONSTANT_TYPE(3441840320)}, {WORD_CONSTANT_TYPE(3994357421), WORD_CONSTANT_TYPE(72107188)}, {WORD_CONSTANT_TYPE(442537958), WORD_CONSTANT_TYPE(2342354661)}, {WORD_CONSTANT_TYPE(1910345247), WORD_CONSTANT_TYPE(928775636)}, {WORD_CONSTANT_TYPE(2302236846), WORD_CONSTANT_TYPE(2175916467)}, {WORD_CONSTANT_TYPE(528202314), WORD_CONSTANT_TYPE(1137357491)}, {WORD_CONSTANT_TYPE(3076748005), WORD_CONSTANT_TYPE(2428928955)}, {WORD_CONSTANT_TYPE(2304934485), WORD_CONSTANT_TYPE(3249197704)}, {WORD_CONSTANT_TYPE(3811193677), WORD_CONSTANT_TYPE(920954862)}, {WORD_CONSTANT_TYPE(101157278), WORD_CONSTANT_TYPE(2093500770)}, {WORD_CONSTANT_TYPE(3457378682), WORD_CONSTANT_TYPE(418148001)}, {WORD_CONSTANT_TYPE(2730954165), WORD_CONSTANT_TYPE(122323943)}, {WORD_CONSTANT_TYPE(1555014556), WORD_CONSTANT_TYPE(4276606365)}, {WORD_CONSTANT_TYPE(1766861960), WORD_CONSTANT_TYPE(3870723922)}, {WORD_CONSTANT_TYPE(1231135237), WORD_CONSTANT_TYPE(4142455722)}, {WORD_CONSTANT_TYPE(1862230446), WORD_CONSTANT_TYPE(724454455)}, {WORD_CONSTANT_TYPE(1135537635), WORD_CONSTANT_TYPE(1523312479)}, {WORD_CONSTANT_TYPE(1507269960), WORD_CONSTANT_TYPE(2985474848)}, {WORD_CONSTANT_TYPE(237163473), WORD_CONSTANT_TYPE(3160295271)}, {WORD_CONSTANT_TYPE(4274229161), WORD_CONSTANT_TYPE(7391041)}, {WORD_CONSTANT_TYPE(2004072411), WORD_CONSTANT_TYPE(163610522)}, {WORD_CONSTANT_TYPE(2355202416), WORD_CONSTANT_TYPE(3199380380)}, {WORD_CONSTANT_TYPE(3746442288), WORD_CONSTANT_TYPE(1664965212)}, {WORD_CONSTANT_TYPE(1377946970), WORD_CONSTANT_TYPE(2369000091)}, {WORD_CONSTANT_TYPE(290856236), WORD_CONSTANT_TYPE(1845237183)}, {WORD_CONSTANT_TYPE(3533825456), WORD_CONSTANT_TYPE(3238839312)}, {WORD_CONSTANT_TYPE(2041100764), WORD_CONSTANT_TYPE(401767414)}, {WORD_CONSTANT_TYPE(553307396), WORD_CONSTANT_TYPE(1417299930)}, {WORD_CONSTANT_TYPE(3859149650), WORD_CONSTANT_TYPE(3474209860)}, {WORD_CONSTANT_TYPE(1572172060), WORD_CONSTANT_TYPE(2721076385)}, {WORD_CONSTANT_TYPE(4219835740), WORD_CONSTANT_TYPE(2235913608)}, {WORD_CONSTANT_TYPE(324268835), WORD_CONSTANT_TYPE(2159802641)}, {WORD_CONSTANT_TYPE(3547075372), WORD_CONSTANT_TYPE(1901317253)}, {WORD_CONSTANT_TYPE(1563562709), WORD_CONSTANT_TYPE(3081850043)}, {WORD_CONSTANT_TYPE(2831564360), WORD_CONSTANT_TYPE(4250667211)}, {WORD_CONSTANT_TYPE(3079541270), WORD_CONSTANT_TYPE(4220479772)}, {WORD_CONSTANT_TYPE(707002813), WORD_CONSTANT_TYPE(1768932006)}, {WORD_CONSTANT_TYPE(838051217), WORD_CONSTANT_TYPE(283413183)}},
    {{WORD_CONSTANT_TYPE(16777216), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(33554432), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(67108864), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(134217728), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(268435456), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(536870912), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1073741824), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2147483648), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(64), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(128), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(256), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(512), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1024), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2048), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4096), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8192), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16384), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32768), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(65536), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(131072), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(262144), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(524288), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1048576), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2097152), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4194304), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8388608), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(64)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(128)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(256)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(512)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1024)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2048)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4096)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8192)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16384)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32768)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(65536)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(131072)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(262144)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(524288)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1048576)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2097152)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4194304)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8388608)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16777216)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(33554432)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(67108864)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(134217728)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(268435456)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(536870912)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1073741824)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2147483648)}}
};

WORD_TYPE VECTORS[ROUNDS + 1][2] = {{WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4226799350), WORD_CONSTANT_TYPE(434195604)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(0)}};

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

void modular_subtraction(WORD_TYPE xy[2]) {
    xy[0] -= xy[1];
}

int main(int argc, char *argv[]) {
    WORD_TYPE xy[2];
    WORD_TYPE res[2];
    if (argc < 3) {
        return -1;
    } else {
        sscanf(argv[1], "%" WORD_IN_TYPE, &xy[0]);
        sscanf(argv[2], "%" WORD_IN_TYPE, &xy[1]);
        res[0] = 0;
        res[1] = 0;
        matrix_vector_product(MATRICES[0], xy, res);
        vector_addition(VECTORS[0], res);
        modular_addition(res);
        vector_addition(VECTORS[1], res);
        xy[0] = 0;
        xy[1] = 0;
        matrix_vector_product(MATRICES[1], res, xy);
        modular_subtraction(xy);
        vector_addition(VECTORS[2], xy);
        res[0] = 0;
        res[1] = 0;
        matrix_vector_product(MATRICES[2], xy, res);
        printf("%" WORD_OUT_TYPE " %" WORD_OUT_TYPE "\n", res[0], res[1]);
    }
}
