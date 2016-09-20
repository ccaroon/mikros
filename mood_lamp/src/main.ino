#include "Effects.h"

Effects effects;

void setup() {
    Serial.begin(9600);
    effects.off();
}

void loop() {
    effects.candle();
    delay(250);
}
