#include <string.h>
#include "Charliplexing.h"
#include "bc_lib.h"

void getDigits(unsigned char value, unsigned char* digits) {
    unsigned char i = 1;

    do {
        digits[i--] = value % 10;
        value /= 10; 
    } while (value);

}

void digitToBinary(unsigned char digit, unsigned char* binary) {
    unsigned char value = digit;

    if (value / 8) {
        binary[EIGHTS] = 1;
        value = value - 8;
    }

    if (value / 4) {
        binary[FOURS] = 1;
        value = value - 4;
    }

    if (value / 2) {
        binary[TWOS] = 1;
        value = value - 2;
    }

    if (value / 1) {
        binary[ONES] = 1;
        value = value - 1;
    }

}

void updateTime(unsigned char place, unsigned char value) {
    unsigned char i, j;
    unsigned char digits[2] = {0,0};
    unsigned char binary[4] = {0,0,0,0};

    getDigits(value, digits);

    for(i = 0; i < 2; i++) {
        memset(binary, 0, sizeof(unsigned char) * 4);
        digitToBinary(digits[i], binary);

        for (j = 0; j < 4; j++) {
            LedSign::Set(i+place,Y_OFFSET-j,binary[j]);
        }
    }
}

