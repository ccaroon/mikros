// Define the 16 points of the compass. 
// Easier to deal with than N, NNE, ENE, E, etc.
#define CP_1   0
#define CP_2   22
#define CP_3   45
#define CP_4   67
#define CP_5   90
#define CP_6   112
#define CP_7   135 
#define CP_8   157
#define CP_9   180
#define CP_10  202
#define CP_11  225
#define CP_12  247
#define CP_13  270
#define CP_14  292
#define CP_15  315
#define CP_16  337

void drawArrow(int);
void ledOn(uint8_t);
void indicateSimpleDirection(int);
