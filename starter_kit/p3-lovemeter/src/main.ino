const int baseTemp = 23.75;


void setup () {
    Serial.begin(9600);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
}

void loop () {
    int val;
    float voltage, temp;

    val = analogRead(A0);
    Serial.print("Temp Sensor Value: ");
    Serial.print(val);

    voltage = (val / 1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);

    temp = (voltage - 0.5) * 100;
    Serial.print(", Temperature: ");
    Serial.println(temp);

    if (temp < baseTemp) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temp >= baseTemp+2 && temp < baseTemp+4) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temp >= baseTemp+4 && temp < baseTemp+6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    else if (temp >= baseTemp+6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }

    delay(100);
}



