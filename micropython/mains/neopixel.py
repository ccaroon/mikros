import time
import random
from machine import Pin
from neopixel import NeoPixel

# MicroMod: G0 == Pin-15
pin = Pin(15, Pin.OUT)
np = NeoPixel(pin, 5)


while True:
    for i in range(0,5):
        red = random.randint(0,255)
        green = random.randint(0,255)
        blue = random.randint(0,255)
        np[i] = (red, green, blue)

    np.write()
    time.sleep(1)
