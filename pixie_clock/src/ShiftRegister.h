class ShiftRegister {
public:
    static const uint8_t latchPin = 8;
    static const uint8_t clockPin = 12;
    static const uint8_t dataPin  = 11;

    static void init();

    static void closeLatch();
    static void openLatch();
    static void sendData(byte *, uint8_t);
};
