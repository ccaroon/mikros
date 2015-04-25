#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <Wire.h>
#include <SPI.h>
#include <TinyScreen.h>

#include "RTCLib.h"

double moon_phase(int,int,int,double);

double phase = 0.0;
DS1339 RTC = DS1339();
TinyScreen display = TinyScreen(0);

void setup()
{
    Wire.begin();
    RTC.start();
    RTC.readTime();
    
    srand(RTC.getSeconds());
    
    display.begin();
    display.setFont(liberationSans_12ptFontInfo);
    display.fontColor(rand()%4096, 0x00);
    
    phase = moon_phase((int)RTC.getYears(), (int)RTC.getMonths(), (int)RTC.getDays(), (int)RTC.getHours());
    phase = floor(phase*1000+0.5)/10;
}

void loop()
{
    char time[8];
    
    display.setCursor(0,0);
    RTC.readTime(); 
    sprintf(time, "%02d:%02d:%02d", RTC.getHours(), RTC.getMinutes(), RTC.getSeconds());
    display.print(time);
    
    display.setCursor(0,15);
    display.print(phase);
        
    delay(1000);
}
