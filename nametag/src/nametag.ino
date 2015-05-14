#define BLACK           0x00
#define BLUE            0xE0
#define RED             0x03
#define GREEN           0x1C
#define DGREEN           0x0C
#define YELLOW          0x1F
#define WHITE           0xFF
#define ALPHA           0xFE
#define BROWN           0x32
#define PAUSE           1000
    
#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>

int count = 0;
TinyScreen display = TinyScreen(0);


void setup(void) {
    Wire.begin();
    display.begin();

    display.setFont(liberationSans_16ptFontInfo);
//  display.setCursor(20,0);
    display.fontColor(WHITE,RED);
    display.print("       HELLO               ");

    display.setFont(liberationSans_10ptFontInfo);
    display.setCursor(17,16);
    display.fontColor(WHITE,RED);
    display.print("my name is");
    
    display.setFont(liberationSans_16ptFontInfo);
}

void loop() {
    display.setCursor(20,35);
    display.fontColor(GREEN,BLACK);
    display.print(count);
    delay(PAUSE);
        
    display.setCursor(20,35);
    display.fontColor(BLACK,BLACK);
    display.print(count);
    
    delay(PAUSE);
    count++;
//  while(1);
    
}
