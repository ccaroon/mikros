#include <Servo.h>

Servo servo;

void setup() {
    Serial.begin(9600);
    servo.attach(9);
}

void loop() {
    int value, angle;

    value = analogRead(A0);
    Serial.println(value);

    // Map POT value to angle between 0 and 179 degrees
    angle = map(value, 0,1023, 0, 179);
    Serial.println(angle);

    servo.write(angle);
    delay(15);
}
