const int redPin   = 10;
const int greenPin = 9;
const int bluePin  = 11;

const int redSensor   = A0;
const int greenSensor = A1;
const int blueSensor  = A2;

int redValue   = 0;
int greenValue = 0;
int blueValue  = 0;

int redSensorVal   = 0;
int greenSensorVal = 0;
int blueSensorVal  = 0;

void setup() {
    Serial.begin(9600);

    pinMode(redPin,   OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin,  OUTPUT);
}

void loop() {
    redSensorVal = analogRead(redSensor);
    delay(5);
    greenSensorVal = analogRead(greenSensor);
    delay(5);
    blueSensorVal = analogRead(blueSensor);

    Serial.print("Raw Sensor Values \t Red: ");
    Serial.print(redSensorVal);
    Serial.print("\t Green: ");
    Serial.print(greenSensorVal);
    Serial.print("\t Blue: ");
    Serial.println(blueSensorVal);

    redValue   = map(redSensorVal,   0, 1023, 0, 255);
    greenValue = map(greenSensorVal, 0, 1023, 0, 255);
    blueValue  = map(blueSensorVal,  0, 1023, 0, 255);

    Serial.print("Mapped Sensor Values \t Red: ");
    Serial.print(redValue);
    Serial.print("\t Green: ");
    Serial.print(greenValue);
    Serial.print("\t Blue: ");
    Serial.println(blueValue);

    analogWrite(redPin,   redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin,  blueValue);
}
