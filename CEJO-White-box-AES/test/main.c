#include "wbaes.h"
#include "speed.h"

unsigned char key_vector[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
unsigned char OUT[16] = {0};
unsigned char input[16384] = {0};
unsigned char output[16384] = {0};

static void dump_hex(uint8_t *h, int len)
{
    while (len--)
    {
        printf("%02hhx ", *h++);
        if (len % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

size_t test_wbaes_ecb_crypt_loop(size_t size)
{
    size_t count = 0;

    for (count = 0; run && count < 0xffffffffffffffff; count++)
    {
        wbaes_ecb_encrypt(input, output, size);
    }
    return count;
}
int main(int argc, char *argv[])
{
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};
    int i;
    unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char EX_IN[16];
    unsigned char EX_OUT[16];
    unsigned char OUT[16];
    unsigned char OOUT[16];

    wbaes_gen(key_vector);
    // external encodings
    for (i = 0; i < 16; i++)
    {
        EX_IN[i] = TypeIa[i][IN[i]];
    }
    // encryption
    wbaes_encrypt(EX_IN, EX_OUT);
    // external encodings
    for (i = 0; i < 16; i++)
    {
        OUT[i] = TypeIb[i][EX_OUT[i]];
    }
    printstate(OUT);

    // aes_128_encrypt(IN, key, OOUT);
    // printstate(OOUT);
    // wbaes_gen(key_vector);
    printf("CEJO-WBAES:\n");
    performance_test_enc(test_wbaes_ecb_crypt_loop, size, 7, 3);

    return 0;
}
