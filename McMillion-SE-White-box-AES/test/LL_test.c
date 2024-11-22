#include <stdint.h>
#include "wbmatrix/WBMatrix.h"
#include <wbaes_se_local.h>

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
    printf("\n");
}
void shiftRows (uint8_t state[16])
{
    int i;
    uint8_t out[16];
    int shiftTab[16] = {0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11};
    for (i = 0; i < 16; i++)
    {
        out[i] = state[shiftTab[i]];
    }
    memcpy(state, out, sizeof(out));
}

uint8_t gMul (uint8_t a, uint8_t b)
{
    int i;
    uint8_t p = 0;
    uint8_t hi_bit_set;

    for (i = 0; i < 8; i++) {
        if ((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}
void mixColumns (uint8_t state[16])
{
    int i;
    uint8_t out[16];
    for (i = 0; i < 4; i++) {
        // todo 第一行乘第一列然后异或，直接把0，1，2拼成对角阵
        out[4*i] = gMul(2, state[4*i]) ^ gMul(3, state[4*i + 1]) ^ state[4*i + 2] ^ state[4*i + 3];
        out[4*i + 1] = state[4*i] ^ gMul(2, state[4*i + 1]) ^ gMul(3, state[4*i + 2]) ^ state[4*i + 3];
        out[4*i + 2] = state[4*i] ^ state[4*i + 1] ^ gMul(2, state[4*i + 2]) ^ gMul(3, state[4*i + 3]);
        out[4*i + 3] = gMul(3, state[4*i]) ^ state[4*i+1] ^ state[4*i + 2] ^ gMul(2, state[4*i + 3]);
    }
    memcpy(state, out, sizeof(out));
}
int main()
{
    M128 shiftrow;
    identityM128(&shiftrow);
    uint64_t tmp[2];
    // 1换5
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+8][0];
        tmp[1] = shiftrow.M[i+8][1];
        shiftrow.M[i+8][0] = shiftrow.M[i+8*5][0];
        shiftrow.M[i+8][1] = shiftrow.M[i+8*5][1];
        shiftrow.M[i+8*5][0] = tmp[0];
        shiftrow.M[i+8*5][1] = tmp[1];
    }
    // 2换10
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+2*8][0];
        tmp[1] = shiftrow.M[i+2*8][1];
        shiftrow.M[i+2*8][0] = shiftrow.M[i+8*10][0];
        shiftrow.M[i+2*8][1] = shiftrow.M[i+8*10][1];
        shiftrow.M[i+8*10][0] = tmp[0];
        shiftrow.M[i+8*10][1] = tmp[1];
    }
    // 3换15
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+3*8][0];
        tmp[1] = shiftrow.M[i+3*8][1];
        shiftrow.M[i+3*8][0] = shiftrow.M[i+8*15][0];
        shiftrow.M[i+3*8][1] = shiftrow.M[i+8*15][1];
        shiftrow.M[i+8*15][0] = tmp[0];
        shiftrow.M[i+8*15][1] = tmp[1];
    }
    // 6 换14
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+6*8][0];
        tmp[1] = shiftrow.M[i+6*8][1];
        shiftrow.M[i+6*8][0] = shiftrow.M[i+8*14][0];
        shiftrow.M[i+6*8][1] = shiftrow.M[i+8*14][1];
        shiftrow.M[i+8*14][0] = tmp[0];
        shiftrow.M[i+8*14][1] = tmp[1];
    }
    // 9 换13
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+9*8][0];
        tmp[1] = shiftrow.M[i+9*8][1];
        shiftrow.M[i+9*8][0] = shiftrow.M[i+8*13][0];
        shiftrow.M[i+9*8][1] = shiftrow.M[i+8*13][1];
        shiftrow.M[i+8*13][0] = tmp[0];
        shiftrow.M[i+8*13][1] = tmp[1];
    }
    // 7 换11
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+7*8][0];
        tmp[1] = shiftrow.M[i+7*8][1];
        shiftrow.M[i+7*8][0] = shiftrow.M[i+8*11][0];
        shiftrow.M[i+7*8][1] = shiftrow.M[i+8*11][1];
        shiftrow.M[i+8*11][0] = tmp[0];
        shiftrow.M[i+8*11][1] = tmp[1];
    }
    // 第二轮 5换13即原来的1换原来的9
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+5*8][0];
        tmp[1] = shiftrow.M[i+5*8][1];
        shiftrow.M[i+5*8][0] = shiftrow.M[i+8*13][0];
        shiftrow.M[i+5*8][1] = shiftrow.M[i+8*13][1];
        shiftrow.M[i+8*13][0] = tmp[0];
        shiftrow.M[i+8*13][1] = tmp[1];
    }
    // 第二轮 7换15即原来的11换原来的3
    for (size_t i = 0; i <8; i++)
    {
        tmp[0] = shiftrow.M[i+7*8][0];
        tmp[1] = shiftrow.M[i+7*8][1];
        shiftrow.M[i+7*8][0] = shiftrow.M[i+8*15][0];
        shiftrow.M[i+7*8][1] = shiftrow.M[i+8*15][1];
        shiftrow.M[i+8*15][0] = tmp[0];
        shiftrow.M[i+8*15][1] = tmp[1];
    }

    // printbitM128(shiftrow);
    // V128 test;
    // V128 res;
    // test.V[0] = 0x1011121314151617;
    // test.V[1] = 0x18191a1b1c1d1e1f;

    // MatMulVecM128(shiftrow,test,&res);
    // printV128(res);
    
    M8 m1,m2,m3;
    identityM8(&m1);
    m2.M[0] = 0x01;
    m2.M[1] = 0x81;
    m2.M[2] = 0x40;
    m2.M[3] = 0x21;
    m2.M[4] = 0x11;
    m2.M[5] = 0x08;
    m2.M[6] = 0x04;
    m2.M[7] = 0x02;
    for (size_t i = 0; i < 8; i++)
    {
        m3.M[i] = m1.M[i] ^ m2.M[i];
    }
    M32 mixcolumn32;
    for (size_t i = 0; i < 8; i++)
    {
        mixcolumn32.M[i] = (uint32_t)(m2.M[i]) << 24 ^ (uint32_t)(m3.M[i]) << 16 ^ (uint32_t)(m1.M[i]) << 16 ^ (uint32_t)(m1.M[i]);
    }
    for (size_t i = 0; i < 8; i++)
    {
        mixcolumn32.M[i+8] = (uint32_t)(m1.M[i]) << 24 ^ (uint32_t)(m2.M[i]) << 16 ^ (uint32_t)(m3.M[i]) << 16 ^ (uint32_t)(m1.M[i]);
    }
    for (size_t i = 0; i < 8; i++)
    {
        mixcolumn32.M[i+16] = (uint32_t)(m1.M[i]) << 24 ^ (uint32_t)(m1.M[i]) << 16 ^ (uint32_t)(m2.M[i]) << 16 ^ (uint32_t)(m3.M[i]);
    }
    for (size_t i = 0; i < 8; i++)
    {
        mixcolumn32.M[i+24] = (uint32_t)(m3.M[i]) << 24 ^ (uint32_t)(m1.M[i]) << 16 ^ (uint32_t)(m1.M[i]) << 16 ^ (uint32_t)(m2.M[i]);
    }
    
    M128 mixcolumn;
    MatrixcomM32to128(mixcolumn32,mixcolumn32,mixcolumn32,mixcolumn32,&mixcolumn);
    M128 LL;
    MatMulMatM128(mixcolumn,shiftrow,&LL);
    // printM128(LL);

    M128 e;
    identityM128(&e);
    uint8_t e8[16]={0};
    for (size_t i = 0; i < 128; i++)
    {
        PUT64(e.M[i][0],e8);
        PUT64(e.M[i][1],e8+8);
        dump_hex(e8,16);
        
        shiftRows(e8);
        printf("after shift row:");
        dump_hex(e8,16);
        // mixColumns(e8);
        printf("after mix col:");
        dump_hex(e8,16);
        e.M[i][0] = GET64(e8);
        e.M[i][1] = GET64(e8+8);
        V128 vv;
        vv.V[0] = e.M[i][0];
        vv.V[1] = e.M[i][1];
        printV128(vv);
    }
    MattransM128(e,&e);
    // todo 11.17 单位阵的转置还是单位阵，所以直接将单位阵转成uint8_t去过线性层
    printM128(e);
    uint8_t test1[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    shiftRows(test1);
    // mixColumns(test1);
    dump_hex(test1,16);
    uint8_t test2[16] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    V128 testv;
    testv.V[0] = GET64(test2);
    testv.V[1] = GET64(test2+8);
    printV128(testv);
    MatMulVecM128(e,testv,&testv);
    PUT64(testv.V[0],test2);
    PUT64(testv.V[1],test2+8);
    printV128(testv);
    dump_hex(test2,16);
    return 0;
}