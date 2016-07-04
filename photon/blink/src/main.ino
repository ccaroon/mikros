
void setup() {
    pinMode(D7, OUTPUT);
    digitalWrite(D7, LOW);
}

void loop() {
    digitalWrite(D7, HIGH);
    delay(1000);
    digitalWrite(D7, LOW);
    delay(1000);
}
