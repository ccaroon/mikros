
int input;
void setup () {
    Serial.begin(9600);

    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop () {
    input = analogRead(A0);

    // input = constrain(input, 250, 750);
    input = map(input, 0, 1023, 0, 255);
    Serial.println(input);

    analogWrite(10, input);
    analogWrite(11, 255-input);

    delay(500);    
}
