#include "PololuLedStrip.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_COUNT 10

#define BLACK  (rgb_color){0x00,0x00,0x00}
#define RED    (rgb_color){0x80,0x00,0x00}
#define ORANGE (rgb_color){0x80,0x00,0xA5}
#define YELLOW (rgb_color){0x80,0x00,0x80}
#define GREEN  (rgb_color){0x00,0x00,0x80}
#define BLUE   (rgb_color){0x00,0x80,0x00}
#define INDIGO (rgb_color){0x4B,0x82,0x00}
#define VIOLET (rgb_color){0x9F,0x80,0x00}

rgb_color colors[LED_COUNT];
OneWire oneWire(2);
DallasTemperature sensor(&oneWire);
PololuLedStrip<12> ledStrip;

uint8_t sensorAddr;
void setup() {
    Serial.begin(9600);
    sensor.begin();
    sensor.getAddress(&sensorAddr, 0);
}

void loop() {
    rgb_color viewColor = BLACK;
    sensor.requestTemperaturesByAddress(&sensorAddr);
    float temp = sensor.getTempF(&sensorAddr);
    Serial.println(temp);

    if (temp >= 90) {
        viewColor = RED;
    }
    else if (temp > 80 && temp < 90) {
        viewColor = ORANGE;
    }
    else if (temp >= 75 && temp <= 80) {
        viewColor = YELLOW;
    }
    else if (temp < 75) {
        viewColor = BLUE;
    }

    for (int i = 0; i < LED_COUNT; i++) {
        colors[i] = viewColor;
    }

    ledStrip.write(colors, LED_COUNT);

    delay(2000);
}
