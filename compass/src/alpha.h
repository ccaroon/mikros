#include <stdint.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} LEDPosition;

const LEDPosition LETTER_A[6] = {{1,0},{0,1},{1,1},{2,1},{0,2},{2,2}};
const LEDPosition LETTER_B[5] = {{0,0},{0,1},{0,2},{1,1},{1,2}};
const LEDPosition LETTER_C[7] = {{0,0},{1,0},{2,0},{0,1},{0,2},{1,2},{2,2}};

// const LEDPosition *CRAIG[26] = {
//     LETTER_A,
//     LETTER_B,
//     LETTER_C
// };

void drawLetter(char letter, uint8_t x, uint8_t y);
