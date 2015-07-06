#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

int buttonState = 0;
 
void setup() {
    // Serial.begin(9600);
    EsploraTFT.begin();
    EsploraTFT.background(0,0,0);
    EsploraTFT.setTextSize(5);
}

int tempX = 50;
int tempY = 40;
void displayTemperature() {
    char tempPrintout[3];
    int temp;

    temp = Esplora.readTemperature(DEGREES_F);
    String temperature = String(temp);
    temperature.toCharArray(tempPrintout, 3);

    if (temp > 85) {
        Esplora.writeRGB(128,0,0);
    }
    else if (temp > 75 && temp <= 85) {
        Esplora.writeRGB(128,100,0);
    }
    else if (temp > 68 && temp <= 75 ) {
        Esplora.writeRGB(0,128,0);
    }
    else if (temp <= 68) {
        Esplora.writeRGB(0,0,128);
    }

    EsploraTFT.stroke(255, 255, 255);
    EsploraTFT.text(tempPrintout, tempX, tempY);

    delay(2000);

    EsploraTFT.stroke(0, 0, 0);
    EsploraTFT.text(tempPrintout, tempX, tempY);
}

void buttonStuff() {
    buttonState = Esplora.readButton(SWITCH_2);

    if (buttonState == LOW) {
        Esplora.writeRGB(0,255,0);
    }
    else {
        Esplora.writeRGB(0,0,0);
    }
}

void loop() {
    displayTemperature();
}
