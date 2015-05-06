#include <string.h>
#include "Charliplexing.h"
#include "bc_lib.h"

void getDigits(int value, int* digits) {
    int i = 1;

    do {
        digits[i--] = value % 10;
        value /= 10; 
    } while (value);

}

void digitToBinary(int digit, int* binary) {
    int value = digit;

    memset(binary, 0, sizeof(int) * 4);

    if (value / 8) {
        binary[EIGHTS] = 7;
        value = value - 8;
    }

    if (value / 4) {
        binary[FOURS] = 7;
        value = value - 4;
    }

    if (value / 2) {
        binary[TWOS] = 7;
        value = value - 2;
    }

    if (value / 1) {
        binary[ONES] = 7;
        value = value - 1;
    }
}

void updateTime(int place, int value) {
    int i, j;
    int digits[2];
    int binary[4];

    getDigits(value, digits);

    for(i = 0; i < 2; i++) {
        digitToBinary(digits[i], binary);

        for (j = 0; j < 4; j++) {
            LedSign::Set(i+place,Y_OFFSET-j,binary[j]);
        }
    }
}

