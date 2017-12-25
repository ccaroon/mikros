#include "adafruit-htu21df.h"
#define LED_PIN 1

char auth[] = "3aa131eb45734fae9ed29a4e59e3eaf1";
Adafruit_HTU21DF sensor;

void setup() {
    // pinMode(LED_PIN, OUTPUT);
    // digitalWrite(LED_PIN, LOW);
    sensor.begin();
    // Blynk.begin(auth);
}

void loop() {
    float temp;

    // digitalWrite(LED_PIN, HIGH);
    // delay(250);
    // digitalWrite(LED_PIN, LOW);
    // delay(250);
    temp = sensor.readTemperature();
    // Blynk.virtualWrite(0, temp);

    delay(5 * 1000);
}
