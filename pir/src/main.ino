#define LED 7
#define PIR 2

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(PIR, INPUT);

    digitalWrite(LED, LOW);
    digitalWrite(PIR, LOW);

    // wait for sensor to calibrate
    delay(30000);
}

void loop() {

    if (digitalRead(PIR) == HIGH) {
        digitalWrite(LED, HIGH);
    }
    else {
        digitalWrite(LED, LOW);
    }

    delay(100);
}