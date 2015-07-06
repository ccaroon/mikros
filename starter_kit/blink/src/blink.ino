void setup () {
    pinMode(13, OUTPUT);
}

void loop () {

    if (millis() % 1000 == 0) {
        digitalWrite(13, 1);
        delay(100);
    }
    else {
        digitalWrite(13, 0);
    }
    
    // delay(250);
    // digitalWrite(13,0);
    // delay(250);
}
