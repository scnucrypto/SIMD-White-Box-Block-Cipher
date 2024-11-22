#include "aes.h"

#define ROTL8(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

static const uint8_t rCon[11] = {
        0x8d, 0x01, 0x02, 0x04, 0x08, 0x10,
        0x20, 0x40, 0x80, 0x1b, 0x36
};

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%16==0) printf("\n");
    }
}

void subBytes (uint8_t state[16])
{
    int i;
    for (i = 0; i < 16; i++)
        state[i] = SBox[state[i]];
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

void addRoundKey (uint8_t state[16], uint8_t roundKey[16])
{
    int i;
    for (i = 0; i < 16; i++)
        state[i] ^= roundKey[i];
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

void expandKey (const uint8_t key[16], uint8_t expandedKey[176]) {
    uint8_t tmp[4];
    int i = 0;
    int k;

    for (i = 0; i < 4; i++) {
        expandedKey[4*i] = key[4*i];
        expandedKey[4*i + 1] = key[4*i + 1];
        expandedKey[4*i + 2] = key[4*i + 2];
        expandedKey[4*i + 3] = key[4*i + 3];
    }

    for (i = 4; i < 44; i++) {
        tmp[0] = expandedKey[4*(i-1)];
        tmp[1] = expandedKey[4*(i-1) + 1];
        tmp[2] = expandedKey[4*(i-1) + 2];
        tmp[3] = expandedKey[4*(i-1) + 3];

        if (i % 4 == 0)
        {
            k = tmp[0];
            tmp[0] = SBox[tmp[1]] ^ rCon[i/4];
            tmp[1] = SBox[tmp[2]];
            tmp[2] = SBox[tmp[3]];
            tmp[3] = SBox[k];

        }
        expandedKey[4*i] = expandedKey[4*(i-4)] ^ tmp[0];
        expandedKey[4*i + 1] = expandedKey[4*(i-4) + 1] ^ tmp[1];
        expandedKey[4*i + 2] = expandedKey[4*(i-4) + 2] ^ tmp[2];
        expandedKey[4*i + 3] = expandedKey[4*(i-4) + 3] ^ tmp[3];
    }
}

void wbcrypto_aes_setkey_dec(wbcrypto_aes_context *ctx, const uint8_t *key){
    uint8_t rk[176]={0};
    expandKey (key, rk);
    for (size_t i = 0; i < 11; i++)
    {
        for (size_t j = 0; j < 16; j++)
        {
            ctx->expandedKey[i*16+j] = rk[(10-i)*16+j];
        }
    }
}

void wbcrypto_aes_setkey_enc(wbcrypto_aes_context *ctx, const uint8_t *key){
    expandKey (key, ctx->expandedKey);
}

void wbcrypto_aes_encrypt (const uint8_t IN[16], uint8_t OUT[16], wbcrypto_aes_context *ctx)
{
    int i;
    uint8_t ip[16];
    uint8_t key[176];
    memcpy(key, ctx->expandedKey, sizeof(key));
    memcpy(ip, IN, sizeof(ip));

    for (i = 0; i < 9; i++)
    {
        shiftRows (ip);
        shiftRows (key+16*i);
        addRoundKey (ip, key + 16*i);
        subBytes (ip);
        mixColumns (ip);
    }

    shiftRows (ip);
    shiftRows (key + 144);
    addRoundKey (ip, key + 144);
    subBytes (ip);
    addRoundKey (ip, key + 160);

    memcpy(OUT, ip, sizeof(ip));
}



void wbcrypto_aes_free(wbcrypto_aes_context *ctx)
{
    memset( ctx, 0, sizeof(wbcrypto_aes_context) );
    if(ctx!=NULL){
        free(ctx);
        ctx=NULL;
    }
}