#include "Tiny7SegmentDisplay.h"
#include <inttypes.h>
#include "Arduino.h"
#include <Wire.h>

Tiny7SegmentDisplay::Tiny7SegmentDisplay()
{
    lastWriteToReg[0]=0;
    lastWriteToReg[1]=0;
}

void Tiny7SegmentDisplay::init()
{
    write(0x00,0xFF);
    write(0x01,0xFF);
    write(0x02,0x00);
    write(0x03,0x00);
}

void Tiny7SegmentDisplay::off()
{
    decPointState[0]=0;
    decPointState[1]=0;
    write(0x00,0xFF);
    write(0x01,0xFF);
}

void Tiny7SegmentDisplay::write(uint8_t regAddr, uint8_t regData)
{
    Wire.beginTransmission(0x20);
    Wire.write(regAddr); 
    Wire.write(regData);
    Wire.endTransmission();

    if(regAddr == 0) {
        lastWriteToReg[0]=regData;
    }
    else if(regAddr == 1) {
        lastWriteToReg[1]=regData;
    }
}

void Tiny7SegmentDisplay::writeInt(uint8_t digit, uint8_t num)
{
    char map[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};

    if(digit != 0 && digit != 1) {
        return;
    }

    if(num+1>0 && num<10) {
        uint8_t writeData=map[num];
        if(decPointState[digit]) {
            writeData&=0x7F;
        }
        else {
            writeData|=0x80;
        }

        write(digit, writeData);
    }
}

void Tiny7SegmentDisplay::printInt(int num)
{
    num = constrain(num,0,99);
    uint8_t tens=num/10;
    writeInt(0,tens);
    writeInt(1,num-(tens*10));
}

void Tiny7SegmentDisplay::setDecPoints(uint8_t left, uint8_t right)
{
    if(decPointState[0] != left) {
        decPointState[0] = left;

        if(left) {
            write(0,lastWriteToReg[0]&0x7F);
        }
        else {
            write(0,lastWriteToReg[0]|0x80);
        }
    }

    if(decPointState[1] != right) {
        decPointState[1] = right;
        
        if(right) {
            write(1,lastWriteToReg[1]&0x7F);
        }
        else {
            write(1,lastWriteToReg[1]|0x80);
        }
    }
}
