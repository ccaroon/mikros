import board
import digitalio
import time
import neopixel
import random

from egg import Egg

# NeoPixel strip connected on D4
NUMPIXELS = 16
neopixels = neopixel.NeoPixel(board.D4, NUMPIXELS, brightness=1.0, auto_write=False)

egg = Egg(neopixels)

def tester():
    for i in range(0, NUMPIXELS):
        neopixels[i] = (random.randint(0,255),random.randint(0,255),random.randint(0,255))

    neopixels.show()

    time.sleep(0.25)

while True:
    # tester()
    egg.run()

    time.sleep(0.25)
