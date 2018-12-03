#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define DELAY 1000
#define LEDPIN 13
#define NEOPIN 6
#define LED_COUNT 5
Adafruit_NeoPixel strip =
    Adafruit_NeoPixel(LED_COUNT, NEOPIN, NEO_GRB + NEO_KHZ800);

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t black = strip.Color(0, 0, 0);
uint32_t colors[3] = {red, green, blue};

void pixelOn(uint32_t color) {
  strip.setPixelColor(0, color);
  strip.show();
}

void pixelOff() {
  strip.setPixelColor(0, black);
  strip.show();
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) {
    // ***
    // *** 5 cycles of all colors on wheel
    // ***
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }

    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }

  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }

  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void setup() {
  pinMode(LEDPIN, OUTPUT);
  strip.begin();
}

void loop() {
  // digitalWrite(LEDPIN, HIGH);
  // uint8_t i = random(3);
  // pixelOn(colors[i]);
  // delay(DELAY);
  // digitalWrite(LEDPIN, LOW);
  // pixelOff();
  // delay(DELAY);

  rainbowCycle(60);
}
