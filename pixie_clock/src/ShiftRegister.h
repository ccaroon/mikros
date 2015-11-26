const uint8_t latchPin = 8;
const uint8_t clockPin = 12;
const uint8_t dataPin  = 11;

void closeLatch();
void openLatch();
void sendData(byte *, uint8_t);
