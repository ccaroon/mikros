#include "Effects.h"

Effects effects;

void setup() {
}

void loop() {
    
    effects.lamp(random(255), random(255), random(255));
    Bean.sleep(1000);
}
