#include "Effects.h"

Effects effects;

void setup() { Serial.begin(9600); }

void loop() {
  effects.lamp(75, 255, 128);
  delay(250);
}
