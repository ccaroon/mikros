#include <Adafruit_NeoPixel.h>

#define COUNT 3
#define PIN 7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() { strip.begin(); }

void loop() {

  for (int i = 0; i < 3; i++) {
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
    strip.setPixelColor(i, r, g, b);
  }

  strip.show();

  delay(250);
}
