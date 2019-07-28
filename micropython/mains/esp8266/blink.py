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
