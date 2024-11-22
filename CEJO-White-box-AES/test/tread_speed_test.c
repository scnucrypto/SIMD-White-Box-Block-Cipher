#include <string.h>
#include <stdio.h>
#include "speed.h"
#include "wbaes.h"
#include "omp.h"

unsigned char key[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char tweak[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
unsigned char aad[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0x7f, 0xff, 0xff, 0xfe, 0x89, 0x2c, 0x38, 0x00,
    0x00, 0x5c, 0x36, 0x5c, 0x36, 0x5c, 0x36};
unsigned char iv_enc[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
unsigned char ecount_buf[16] = {0x00};
unsigned int num = 0;
volatile unsigned char input[16384] = {0};
unsigned char output[16384] = {0};

void test_parallel_threads(size_t sizes[], size_t slen, int count, int threads_nums)
{
    for (size_t i = 1; i <= threads_nums; i *= 2)
    {
        double begin, end;
        for (size_t j = 0; j < slen; j++)
        {
            begin = omp_get_wtime();
#pragma omp parallel for num_threads(i)
            for (size_t k = 0; k < count; k++)
            {
                wbaes_ecb_encrypt(input, output, sizes[j]);
            }
            end = omp_get_wtime();
            printf("\n threads: %d wbaes enc block_size: %d run: %d byte used time: %f s speed %f Mbps\n",
                   i, sizes[j], count * sizes[j], (end - begin), (count * sizes[j] * 8) / ((end - begin) * 1024 * 1024));
        }
    }
}

int main()
{
    size_t size[7] = {16, 64, 256, 512, 1024, 8192, 16384};

    wbaes_gen(key);

    printf("\ncejo_wbaes_ecb:\n");
    test_parallel_threads(size, 7, 10000, 16);
    return 0;
}
