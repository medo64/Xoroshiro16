#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "xoroshiro16.h"


void main(int argc, char *argv[]) {
    uint8_t seed = 0x00;
    if (argc > 1) { seed = atoi(argv[1]); }

    random_init_seed(seed);

    FILE* filePtr = fopen("xoroshiro16.bin", "wb");

    uint8_t* buffer = (uint8_t*)malloc(1024 * 1024);
    for (int n = 0; n < 16; n++) {
        printf("."); fflush(stdout);
        for (int m = 0; m < 1024; m++) {
            for (int i = 0; i < 1024 * 1024; i++) {
                buffer[i] = random_next();
            }
            fwrite(buffer, 1, 1024 * 1024, filePtr);
        }
        fflush(filePtr);
    }
    printf("\n");

    fclose(filePtr);
}
