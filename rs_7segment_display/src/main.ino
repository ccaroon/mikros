#define SEGMENT_1 2
#define SEGMENT_2 3
#define SEGMENT_3 4
#define SEGMENT_4 5
#define SEGMENT_5 6
#define SEGMENT_6 7
#define SEGMENT_7 8
#define SEGMENT_8 9
#define SEGMENT_9 10

void setup() {
    for (int pin = SEGMENT_1; pin <= SEGMENT_9; pin++) {
        pinMode(pin, OUTPUT);
    }
}

void loop() {

    for (int pin = SEGMENT_1; pin <= SEGMENT_9; pin++) {
        digitalWrite(pin, HIGH);
        delay(500);
        digitalWrite(pin, LOW);
    }   

    delay(5000);
}
