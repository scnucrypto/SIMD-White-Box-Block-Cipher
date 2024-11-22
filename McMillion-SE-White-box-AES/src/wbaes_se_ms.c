#include "wbaes_se_ms.h"

static void dump_hex(uint8_t * h, int len)
{
    while(len--)
    {   
        printf("%02hhx ",*h++);
        if(len%32==0) printf("\n");
    }
    printf("\n");
}

static Aff8 A[2039], B[2039];


wbaes_se_ms_context *wbaes_se_ms_context_init() {
    wbaes_se_ms_context *ctx = malloc(sizeof(wbaes_se_ms_context));
    if (ctx == NULL) {
        goto cleanup;
    }
    memset(ctx, 0, sizeof(wbaes_se_ms_context));
    return ctx;
cleanup:
    return NULL;
}

void wbaes_se_ms_context_free(wbaes_se_ms_context *ctx) {
    memset(ctx, 0, sizeof(wbaes_se_ms_context));
}

int wbaes_se_ms_gen_table(wbaes_se_ms_context *ctx, const uint8_t *key) {
    int i;
   
    Aff128 K[11];
    Aff128 L;
    Aff128 shiftrow;
    Aff128 AA[10], BB[10];

    wbcrypto_aes_context aes_key;
    wbcrypto_aes_setkey_enc(&aes_key,key);
    //! test
    InitRandom(1);
    // InitRandom(((unsigned int) time(NULL)));

    SE_initial(A,B);

    //affine L for linear layer
    L.Mat = L_matrix;
    L.Vec.V[0] = 0;
    L.Vec.V[1] = 0;
    
    shiftrow.Mat = shiftrows;
    shiftrow.Vec.V[0] = 0;
    shiftrow.Vec.V[1] = 0;
    // !test
    for (i = 0; i < 2; i++) {
        //affine P
        genaffinepairM128(&ctx->P[i], &ctx->P_inv[i]);
      
    }
    for (size_t i = 0; i < 10; i++)
    {
        int a[16];
        for (size_t j = 0; j < 16; j++)
        {
            a[j] = cus_random() % 2039;
        }
        affinecomM8to128(A[a[0]], A[a[1]], A[a[2]], A[a[3]], A[a[4]], A[a[5]], A[a[6]], A[a[7]], A[a[8]], A[a[9]], A[a[10]], A[a[11]], A[a[12]], A[a[13]], A[a[14]], A[a[15]], &AA[i]);
        affinecomM8to128(B[a[0]], B[a[1]], B[a[2]], B[a[3]], B[a[4]], B[a[5]], B[a[6]], B[a[7]], B[a[8]], B[a[9]], B[a[10]], B[a[11]], B[a[12]], B[a[13]], B[a[14]], B[a[15]], &BB[i]);
        
    }
    // 这个K[i]可以用TMP_K代替
    // first AL
    identityM128(&K[0].Mat);
    K[0].Vec.V[0] = GET64(&aes_key.expandedKey[0]);
    K[0].Vec.V[1] = GET64(&aes_key.expandedKey[8]);
    affinemixM128(K[0], ctx->P_inv[0], &ctx->AL[0]);
    affinemixM128(AA[0], ctx->AL[0], &ctx->AL[0]);

    for (i = 1; i < 10; i++) {
        //affine K for round key
        identityM128(&K[i].Mat);
        // todo 不知道是从轮密钥开始还是主密钥开始，这里用主密钥开始
        K[i].Vec.V[0] = GET64(&aes_key.expandedKey[i*16]);
        K[i].Vec.V[1] = GET64(&aes_key.expandedKey[i*16+8]);

        //affine middle AL
        affinemixM128(L, BB[i-1], &ctx->AL[i]);
        affinemixM128(K[i], ctx->AL[i], &ctx->AL[i]);
        affinemixM128(AA[i], ctx->AL[i], &ctx->AL[i]);
    }

    identityM128(&K[10].Mat);
    K[10].Vec.V[0] = GET64(&aes_key.expandedKey[160]);
    K[10].Vec.V[1] = GET64(&aes_key.expandedKey[168]);
    affinemixM128(shiftrow, BB[9], &ctx->AL[10]);
    affinemixM128(K[10], ctx->AL[10], &ctx->AL[10]);
    affinemixM128(ctx->P[1], ctx->AL[10], &ctx->AL[10]);
    
    return 1;
}

int wbaes_se_ms_encrypt(const unsigned char *input, unsigned char *output,wbaes_se_ms_context *ctx) {
    int i;
    uint64_t x[2];
    uint8_t x8[16];

    x[0] = GET64(input);
    x[1] = GET64(input + 8);
    //加外部编码
    
    affineU128(ctx->P[0],x,x);

    affineU128(ctx->AL[0],x,x);
    
    for (size_t i = 1; i < 10; i++)
    {
        PUT64(x[0],x8);
        PUT64(x[1],x8+8);
        for (size_t j = 0; j < 16; j++)
            x8[j] = SBox[x8[j]];
        x[0] = GET64(x8);
        x[1] = GET64(x8 + 8);
        affineU128(ctx->AL[i],x,x);
    }
    PUT64(x[0],x8);
    PUT64(x[1],x8+8);
    for (size_t j = 0; j < 16; j++)
            x8[j] = SBox[x8[j]];
    x[0] = GET64(x8);
    x[1] = GET64(x8 + 8);
    affineU128(ctx->AL[10],x,x);
    // 抵消外部编码
    affineU128(ctx->P_inv[1],x,x);
    PUT64(x[0],output);
    PUT64(x[1],output+8);
    return 1;
}

int wbaes_se_ms_ecb_encrypt(const unsigned char *input, unsigned char *output, size_t len, wbaes_se_ms_context *ctx) {
    assert (len % 16 == 0);
    while (len) {
        wbaes_se_ms_encrypt(input,output,ctx);
        len -= 16;
        input += 16;
        output += 16;
    }
}
