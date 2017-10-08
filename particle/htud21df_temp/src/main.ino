#include "adafruit-htu21df.h"
#include "blynk.h"

char auth[] = "cbe1dca217a544c8a740c6fe35aaac23";
Adafruit_HTU21DF sensor;

void setup() {
    sensor.begin();

    delay(5000);
    Blynk.begin(auth);
}

long counter = 0;
void loop() {
    float temp;
    float hum;

    temp = sensor.readTemperature();
    char tempF[8];
    sprintf(tempF, "%0.2f", (temp * 1.8) + 32);
    Blynk.virtualWrite(0, tempF);

    hum = sensor.readHumidity();
    char humStr[8];
    sprintf(humStr, "%0.2f", hum);
    Blynk.virtualWrite(1, humStr);

    Blynk.virtualWrite(2, counter++);

    delay(5 * 1000);
}
