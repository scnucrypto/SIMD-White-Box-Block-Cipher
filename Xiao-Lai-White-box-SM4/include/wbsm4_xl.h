#include "wbmatrix/WBMatrix.h"
#include "sm4.h"
#include <assert.h>

#define GET32(pc)  (\
((uint32_t)(pc)[0] << 24) ^\
((uint32_t)(pc)[1] << 16) ^\
((uint32_t)(pc)[2] <<  8) ^\
((uint32_t)(pc)[3]))

#define PUT32(st, ct)\
(ct)[0] = (uint8_t)((st) >> 24);\
(ct)[1] = (uint8_t)((st) >> 16);\
(ct)[2] = (uint8_t)((st) >>  8);\
(ct)[3] = (uint8_t)(st)

static Aff32 M[32][3];
static Aff32 C[32];
static Aff32 D[32];
static Aff32 SE[4];
static Aff32 FE[4];
static uint32_t Table[32][4][256];

void printstate(unsigned char * in);
void wbsm4_xl_gen(uint8_t *key);
void wbsm4_xl_encrypt(unsigned char IN[], unsigned char OUT[]);
void wbsm4_xl_ecb_encrypt(unsigned char IN[], size_t len, unsigned char OUT[]);