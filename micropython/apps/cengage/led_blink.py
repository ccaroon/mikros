import time
import random
from machine import Pin

red = Pin(2, Pin.OUT)
green = Pin(3, Pin.OUT)
blue = Pin(4, Pin.OUT)

def clear():
    red.off()
    green.off()
    blue.off()

def blink():
    while True:
        red.toggle()
        time.sleep_ms(random.randint(0,1001))

        green.toggle()
        time.sleep_ms(random.randint(0,1001))

        blue.toggle()
        time.sleep_ms(random.randint(0,1001))
