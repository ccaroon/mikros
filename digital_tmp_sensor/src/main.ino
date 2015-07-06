// platformio lib install 54
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2);
DallasTemperature sensor(&oneWire);

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    uint8_t count = sensor.getDeviceCount();
    Serial.print("Count: ");
    Serial.println(count);

    uint8_t addr;
    sensor.getAddress(&addr, 0);
    Serial.println(addr);

    sensor.requestTemperaturesByAddress(&addr);

    float temp = sensor.getTempF(&addr);
    Serial.println(temp);

    delay(1000);
}
