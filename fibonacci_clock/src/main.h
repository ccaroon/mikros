#define ONE       0
#define ONE_PRIME 1
#define TWO       2
#define THREE     3
#define FIVE      4
#define EMPTY     255

#define WHITE  0
#define YELLOW 1
#define BLUE   2
#define GREEN  3 // YELLOW + BLUE = GREEN :)

#define UNIT_SIZE 12 //In pixels

// ------------------- white, yellow, blue, green
uint8_t colorMap[4] = {0xFF,  0x1F,   0xE0, 0x1C};

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t units;
} FibSquare;

const FibSquare one      = {x:24, y:0,  units:1};
const FibSquare onePrime = {x:24, y:12, units:1};
const FibSquare two      = {x:0,  y:0,  units:2};
const FibSquare three    = {x:0,  y:24, units:3};
const FibSquare five     = {x:36, y:0,  units:5};

#define MAX_CHOICES 4
#define MAX_COMBOS  5
const uint8_t fibMap[13][MAX_CHOICES][MAX_COMBOS] = {
    // ZERO -> Not used
    {},
    // ONE =>  1 | 1`
    {
        {ONE,       EMPTY, EMPTY, EMPTY, EMPTY},
        {ONE_PRIME, EMPTY, EMPTY, EMPTY, EMPTY},
    },
    // TWO => 1,1` | 2
    {
        {ONE, ONE_PRIME, EMPTY, EMPTY, EMPTY},
        {TWO, EMPTY,     EMPTY, EMPTY, EMPTY}
    },
    // THREE => 1,2 | 1`,2 | 3
    {
        {ONE,       TWO,   EMPTY, EMPTY, EMPTY},
        {ONE_PRIME, TWO,   EMPTY, EMPTY, EMPTY},
        {THREE,     EMPTY, EMPTY, EMPTY, EMPTY},
    },
    // FOUR => 1,3 | 1`,3 | 1,1`,2
    {
        {ONE,       THREE,     EMPTY, EMPTY, EMPTY},
        {ONE_PRIME, THREE,     EMPTY, EMPTY, EMPTY},
        {ONE,       ONE_PRIME, TWO,   EMPTY, EMPTY},
    },
    // FIVE => 1,1`,3 | 2,3 | 5
    {
        {ONE,  ONE_PRIME, THREE, EMPTY, EMPTY},
        {TWO,  THREE,     EMPTY, EMPTY, EMPTY},
        {FIVE, EMPTY,     EMPTY, EMPTY, EMPTY}
    },
    // SIX =>  1,5 | 1`,5 | 1,2,3 | 1`,2,3 
    {
        {ONE,       FIVE, EMPTY, EMPTY, EMPTY},
        {ONE_PRIME, FIVE, EMPTY, EMPTY, EMPTY},
        {ONE,       TWO,  THREE, EMPTY, EMPTY},
        {ONE_PRIME, TWO,  THREE, EMPTY, EMPTY}
    },
    // SEVEN => 2,5 | 1,1`,2,3
    {
        {TWO, FIVE,      EMPTY, EMPTY, EMPTY},
        {ONE, ONE_PRIME, TWO,   THREE, EMPTY}
    },
    // EIGHT => 3,5 | 1,2,5 | 1`,2,5
    {
        {THREE,     FIVE,  EMPTY, EMPTY, EMPTY},
        {ONE,       TWO,   FIVE,  EMPTY, EMPTY},
        {ONE_PRIME, TWO,   FIVE,  EMPTY, EMPTY}
    },
    // NINE => 1,1`,2,5 | 1,3,5 | 1`,3,5
    {
        {ONE,       ONE_PRIME, TWO,  FIVE,  EMPTY},
        {ONE,       THREE,     FIVE, EMPTY, EMPTY},
        {ONE_PRIME, THREE,     FIVE, EMPTY, EMPTY}
    },
    // TEN => 2,3,5 | 1,1`,3,5 
    {
        {TWO, THREE,     FIVE,  EMPTY, EMPTY},
        {ONE, ONE_PRIME, THREE, FIVE,  EMPTY}
    },
    // ELEVEN => 1,2,3,5 | 1`,2,3,5
    {
        {ONE,       TWO, THREE, FIVE, EMPTY},
        {ONE_PRIME, TWO, THREE, FIVE, EMPTY}
    },
    // TWELVE => 1,1`,2,3,5
    {
        {ONE, ONE_PRIME, TWO, THREE, FIVE}
    }  
};
