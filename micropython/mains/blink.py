from machine import Pin

import utime

red = Pin(0, Pin.OUT)
blue = Pin(2, Pin.OUT)

while True:
    red.off()
    blue.on()
    utime.sleep(.5)
    red.on()
    blue.off()
    utime.sleep(.5)

# def beat(delay=250, count=5):
#     pin.off()

#     for i in range(count):
#         print(i)

#         pin.on()
#         time.sleep_ms(int(delay/2))
#         pin.off()
#         time.sleep_ms(int(delay/2))

#         pin.on()
#         time.sleep_ms(int(delay/2))
#         pin.off()

#         time.sleep_ms(delay*3)
