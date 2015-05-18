#define BLYNK_PRINT Serial
// #include <Wire.h>
#include <SPI.h>
#include <Adafruit_CC3000.h>
#include <BlynkSimpleTinyDuino.h>
// #include "TinyScreen.h"

// TinyScreen display = TinyScreen(0);

char auth[] = "a5e1ee422b51422385b44f71d45c0721";

void setup() {

    // Wire.begin();
    // display.begin();
    Serial.begin(9600);

    // display.setFont(liberationSans_8ptFontInfo);
    // display.fontColor(0x1c, 0x00);
    // display.setCursor(0,0);
    // display.print("Connecting...");
    Serial.println("Connecting to Network");
    Blynk.begin(auth, "FluxNet", "", WLAN_SEC_UNSEC);
    // display.print("done!");
    Serial.println("Done.");

    pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);
    // for (int i = 0; i < 9; i++) {
    //     digitalWrite(13, i % 2);
    //     delay(1000);
    // }
}

// This function will be called every time
// when App writes value to Virtual Pin 1
BLYNK_WRITE(1) {
    BLYNK_LOG("Got a value: %s", param.asStr());
}

BLYNK_WRITE(13) {
    digitalWrite(13, param.asInt());
    BLYNK_LOG("Button 13 Pushed [%d]", param.asInt());
}

void loop() {
    Blynk.run();
}
