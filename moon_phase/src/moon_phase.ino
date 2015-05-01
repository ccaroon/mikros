#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <Wire.h>
#include <SPI.h>
#include <TinyScreen.h>

#include "RTCLib.h"
#include "moon_phase.h"

DS1339 RTC = DS1339();
TinyScreen display = TinyScreen(0);

void setup()
{
    Wire.begin();
    Serial.begin(9600);
    RTC.start();
    RTC.readTime();
    
    srand(RTC.getSeconds());
    
    display.begin();
    display.setFont(liberationSans_12ptFontInfo);
//  display.fontColor(rand()%4096, 0x00);
    display.fontColor(0xFF, 0x00);
    
    drawCircle(48,32,30);
}

void drawFilledCircle (int ox, int oy, int radius) {
    for(int y=-radius; y<=radius; y++) {
        for(int x=-radius; x<=radius; x++) {
            if(x*x+y*y <= radius*radius) {
                display.drawPixel(ox+x, oy+y, 0xFF);                
            }           
        }       
    }
}

void drawCircle(int x0, int y0, int radius) {
    int x = radius;
    int y = 0;
    int radiusError = 1-x;
    
    while(x >= y) {
        display.drawPixel( x + x0,  y + y0, 0xFF);
        display.drawPixel( y + x0,  x + y0, 0xFF);
        display.drawPixel(-x + x0,  y + y0, 0xFF);
        display.drawPixel(-y + x0,  x + y0, 0xFF);
        display.drawPixel(-x + x0, -y + y0, 0xFF);
        display.drawPixel(-y + x0, -x + y0, 0xFF);
        display.drawPixel( x + x0, -y + y0, 0xFF);
        display.drawPixel( y + x0, -x + y0, 0xFF);
        y++;
        
        if (radiusError<0) {
            radiusError += 2 * y + 1;
        }
        else {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
}

//void plotQuadBezierSegAA(int x0, int y0, int x1, int y1, int x2, int y2)
//{                    /* draw an limited anti-aliased quadratic Bezier segment */
//   int sx = x2-x1, sy = y2-y1;
//   long xx = x0-x1, yy = y0-y1, xy;             /* relative values for checks */
//   double dx, dy, err, ed, cur = xx*sy-yy*sx;                    /* curvature */
//
//   assert(xx*sx <= 0 && yy*sy <= 0);      /* sign of gradient must not change */
//
//   if (sx*(long)sx+sy*(long)sy > xx*xx+yy*yy) {     /* begin with longer part */
//      x2 = x0; x0 = sx+x1; y2 = y0; y0 = sy+y1; cur = -cur;     /* swap P0 P2 */
//   }
//   if (cur != 0)
//   {                                                      /* no straight line */
//      xx += sx; xx *= sx = x0 < x2 ? 1 : -1;              /* x step direction */
//      yy += sy; yy *= sy = y0 < y2 ? 1 : -1;              /* y step direction */
//      xy = 2*xx*yy; xx *= xx; yy *= yy;             /* differences 2nd degree */
//      if (cur*sx*sy < 0) {                              /* negated curvature? */
//         xx = -xx; yy = -yy; xy = -xy; cur = -cur;
//      }
//      dx = 4.0*sy*(x1-x0)*cur+xx-xy;                /* differences 1st degree */
//      dy = 4.0*sx*(y0-y1)*cur+yy-xy;
//      xx += xx; yy += yy; err = dx+dy+xy;                   /* error 1st step */
//      do {
//         cur = fmin(dx+xy,-xy-dy);
//         ed = fmax(dx+xy,-xy-dy);               /* approximate error distance */
//         ed += 2*ed*cur*cur/(4*ed*ed+cur*cur);
//         setPixelAA(x0,y0, 255*fabs(err-dx-dy-xy)/ed);          /* plot curve */
//         if (x0 == x2 || y0 == y2) break;     /* last pixel -> curve finished */
//         x1 = x0; cur = dx-err; y1 = 2*err+dy < 0;
//         if (2*err+dx > 0) {                                        /* x step */
//            if (err-dy < ed) setPixelAA(x0,y0+sy, 255*fabs(err-dy)/ed);
//            x0 += sx; dx -= xy; err += dy += yy;
//         }
//         if (y1) {                                                  /* y step */
//            if (cur < ed) setPixelAA(x1+sx,y0, 255*fabs(cur)/ed);
//            y0 += sy; dy -= xy; err += dx += xx;
//         }
//      } while (dy < dx);                  /* gradient negates -> close curves */
//   }
//   plotLineAA(x0,y0, x2,y2);                  /* plot remaining needle to end */
//}

void displayInfo () {
    char output[16];
    double phase;

    RTC.readTime();
    
    display.setCursor(0,0);
    sprintf(output, "%02d:%02d:%02d  ", RTC.getHours(), RTC.getMinutes(), RTC.getSeconds());
    display.print(output);

    double days = (double)RTC.getDays() + (double)RTC.getHours() / 24;
    double j = julian(RTC.getYears(), RTC.getMonths(), days);
    display.setCursor(0,15);
    display.print(j);
    
    display.setCursor(0,30);
    sprintf(output, "%02d/%02d/%d", RTC.getMonths(), RTC.getDays(), RTC.getYears());
    display.print(output);

    display.setCursor(0,45);
    phase = moon_phase((int)RTC.getYears(), (int)RTC.getMonths(), (int)RTC.getDays(), (double)RTC.getHours()+5);
    phase = floor(phase*1000+0.5)/10;
    display.print(phase);   
    
    delay(1000);
}

void moonPhase () {
    char output[8];
    double phase;

    RTC.readTime();
    
    display.setCursor(27,0);
    sprintf(output, " %02d:%02d  ", RTC.getHours(), RTC.getMinutes());
    display.print(output);
    
    phase = moon_phase((int)RTC.getYears(), (int)RTC.getMonths(), (int)RTC.getDays(), (double)RTC.getHours()+5);
    phase = floor(phase*1000+0.5)/10;
//  sprintf(output, "%4.2f", 77.2);
//  Serial.println(output);
    
    display.setCursor(30,24);
    display.print(phase);
    
    delay(60 * 1000);
}

void loop()
{
    moonPhase();
}
