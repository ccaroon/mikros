// #define BLYNK_DEBUG 1
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Adafruit_CC3000.h>
#include <BlynkSimpleTinyDuino.h>

char auth[] = "5b374d27c31e485e9e6f1f20b2666ec1";

void setup() {
    Serial.begin(9600);

    Serial.println("Connecting to Network");
    Blynk.begin(auth, "FluxNet", "", WLAN_SEC_UNSEC);
    Serial.println("Done.");
}


void loop() {
    Blynk.run();
}
