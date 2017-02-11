// IN1 & IN2 control the direction of the motor
// Must be set to opposite values HIGH vs LOW
#define IN1 9
#define IN2 10

// ENABLE1 controls the speed of the motor
// Must be connected to an analog/PWM pin
#define ENABLE1 11

#define FORWARD 0
#define BACKWARD 1

int count = 0;
uint8_t currDir = FORWARD;
void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENABLE1, OUTPUT);

    setDirection(currDir);
    setSpeed(128);
}

// Spin one direction for about 10 secs, then change to spin the opposite
// direction for about 10 secs.
void loop() {
    if (count > 10) {
        currDir = !currDir;
        setSpeed(0);
        setDirection(currDir);
        setSpeed(128);
        count = 0;
    } else {
        count++;
        delay(1000);
    }
}

void setSpeed(uint8_t speed) {
    analogWrite(ENABLE1, speed);
}

void setDirection(uint8_t direction) {
    switch (direction) {
    case FORWARD:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        break;
    case BACKWARD:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        break;
    }
}
