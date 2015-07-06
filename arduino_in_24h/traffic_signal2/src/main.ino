boolean walk = false;

void setup () {
    Serial.begin(9600);

    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);

    attachInterrupt(INT0, crossWalk, FALLING);

    goLight();
}

void loop () {
    if (walk) {
        yieldLight(5);
        stopLight(10);
        goLight();
        walk = false;
    }
}

void stopLight(int d) {
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);

    Serial.print("STOP - ");
    Serial.println(d);
    delay(d * 1000);
}

void yieldLight(int d) {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);

    Serial.print("YIELD - ");
    Serial.println(d);
    delay(d * 1000);
}

void goLight() {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);

    Serial.print("GO");
}

void crossWalk() {
    walk = true;
}
