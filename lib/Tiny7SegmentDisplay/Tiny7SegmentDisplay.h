#ifndef Tiny7SegmentDisplay_h
#define Tiny7SegmentDisplay_h

#include <inttypes.h>

class Tiny7SegmentDisplay {
    public:
        Tiny7SegmentDisplay();
        void init();
        void off();
        void write(uint8_t, uint8_t);
        void writeInt(uint8_t,uint8_t);
        void printInt(int);
        void setDecPoints(uint8_t,uint8_t);
        uint8_t lastWriteToReg[2];
        uint8_t decPointState[2];
};

#endif
