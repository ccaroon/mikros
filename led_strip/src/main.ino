 #include "PololuLedStrip.h"

PololuLedStrip<12> ledStrip;

#define LED_COUNT 10
rgb_color colors[LED_COUNT];

#define BLACK  (rgb_color){0x00,0x00,0x00}
#define RED    (rgb_color){0xFF,0x00,0x00}
#define ORANGE (rgb_color){0xFF,0x00,0xA5}
#define YELLOW (rgb_color){0xFF,0x00,0xFF}
#define GREEN  (rgb_color){0x00,0x00,0xFF}
#define BLUE   (rgb_color){0x00,0xFF,0x00}
#define INDIGO (rgb_color){0x4B,0x82,0x00}
#define VIOLET (rgb_color){0x9F,0xFF,0x00}

void setup() {

}

void loop() {

    // for (int i = 0; i < LED_COUNT; i++) {
    //     colors[i] = (rgb_color){random(64),random(64),random(64)};
    // }

    colors[0] = RED;
    colors[1] = ORANGE;
    colors[2] = YELLOW;
    colors[3] = GREEN;
    colors[4] = BLUE;
    colors[5] = INDIGO;
    colors[6] = VIOLET;
    colors[7] = BLACK;
    colors[8] = BLACK;
    colors[9] = BLACK;

    ledStrip.write(colors, LED_COUNT);

    // if (segment >= 10) {
    //     segment = 0;
    // }

    delay(5000);
}
