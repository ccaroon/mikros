import board
import time
import neopixel
import random

# PyGamer: D8 - 5 Pixels
PIN = board.D8
NUMPIXELS = 5

neopixels = neopixel.NeoPixel(PIN, NUMPIXELS, brightness=1.0, auto_write=False)

def tester():
    color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
    for i in range(0, NUMPIXELS):
        neopixels[i] = color

    neopixels.show()

    time.sleep(1.00)

while True:
    tester()
