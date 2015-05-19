#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Adafruit_CC3000.h>
#include <BlynkSimpleTinyDuino.h>
#include <Timer.h>

Timer t;
char auth[] = "a5e1ee422b51422385b44f71d45c0721";

void setup() {
    Serial.begin(9600);

    Serial.println("Connecting to Network");
    Blynk.begin(auth, "FluxNet", "", WLAN_SEC_UNSEC);
    Serial.println("Done.");

    t.every(1000, sendUptime);
}

BLYNK_WRITE(1) {
    BLYNK_LOG("Got a value: %s", param.asStr());
}

BLYNK_WRITE(13) {
    BLYNK_LOG("Button 13 Pushed [%d]", param.asInt());
}

void loop() {
    Blynk.run();
    t.update();
}

void sendUptime() {
    Blynk.virtualWrite(7, millis()/1000);
}
