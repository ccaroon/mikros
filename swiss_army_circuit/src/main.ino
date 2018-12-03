#include "MultiFunction.h"

MultiFunction mf;

void setup() {
    Serial.begin(9600);
    mf.begin();
}

void loop() {
    mf.loop();
}
