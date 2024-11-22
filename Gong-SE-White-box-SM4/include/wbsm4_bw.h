/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-25 19:43:51
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-25 19:43:51
 * @FilePath: /whibox-sm4/Bai-Wu-White-box-SM4/include/wbsm4.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

static Aff32 SE[4];
static Aff32 FE[4];
static uint32_t TD[32][4][4][256];
static uint32_t TR[32][4][256][256];

void printstate(unsigned char * in);
void wbsm4_bw_gen(uint8_t *key);
void wbsm4_bw_encrypt(unsigned char IN[], unsigned char OUT[]);
void wbsm4_bw_ecb_encrypt(unsigned char IN[], size_t len, unsigned char OUT[]);