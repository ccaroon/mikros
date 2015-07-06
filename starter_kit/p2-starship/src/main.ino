// #define blinkRate 1000

int blinkRate   = 50;
int switchState = 0;

void setup() {
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

int count = 0;
unsigned long startHold = 0;
boolean buttonDown = false;

void loop() {
    switchState = digitalRead(2);

    if (switchState == LOW) {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        buttonDown = false;
    }
    else {

        if (buttonDown == false) {
            startHold = millis();
            buttonDown = true;
            blinkRate = 50;
            count = 0;
        }
        else {
            if ((millis() - startHold) > 1000*count) {
                blinkRate += 25;
                count++;
            }
        }

        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        delay(blinkRate);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(blinkRate);
    }
}
