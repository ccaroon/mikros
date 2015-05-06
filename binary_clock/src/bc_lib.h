#define ONES   0
#define TWOS   1
#define FOURS  2
#define EIGHTS 3

#define HOURS_PLACE   0
#define MINUTES_PLACE 2
#define SECONDS_PLACE 4

#define Y_OFFSET      6 

void getDigits(unsigned char value, unsigned char* digits);
void digitToBinary(unsigned char digit, unsigned char* binary);
void updateTime(unsigned char place, unsigned char value);
