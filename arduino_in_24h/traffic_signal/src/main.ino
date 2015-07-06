int stp = 6;
int yld = 2;
int go  = 6;

void stopLight(int);
void goLight(int);
void yieldLight(int);
int checkSwitch(void);

void setup () {
    Serial.begin(9600);

    pinMode(8,  INPUT_PULLUP);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
}

void loop () {
    stopLight(stp);
    goLight(go);
    yieldLight(yld);
    go = checkSwitch();
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

void goLight(int d) {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);

    Serial.print("GO - ");
    Serial.println(d);
    delay(d * 1000);
}

int checkSwitch() {
    int set = digitalRead(8);
    Serial.print("Checking Switch...");

    if (set) {
        Serial.println("OPEN");
        return 6;
    }
    else {
        Serial.println("CLOSED");
        return 10;
    }
}





