#define ONES   0
#define TWOS   1
#define FOURS  2
#define EIGHTS 3

#define HOURS_PLACE   0
#define MINUTES_PLACE 2
#define SECONDS_PLACE 4

#define Y_OFFSET      6 

void getDigits(int value, int* digits);
void digitToBinary(int digit, int* binary);
void updateTime(int place, int value);
