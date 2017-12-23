import board
import digitalio
import time
import neopixel
import random

# led = digitalio.DigitalInOut(board.D4)
# led.direction = digitalio.Direction.OUTPUT

# NeoPixel strip (of 16 LEDs) connected on D4
NUMPIXELS = 5
neopixels = neopixel.NeoPixel(board.D4, NUMPIXELS, brightness=0.2, auto_write=False)

while True:
    # led.value = True
    # time.sleep(0.5)
    # led.value = False
    # time.sleep(0.5)
    # print("hello")

    for i in range(NUMPIXELS):
        r = random.randint(0,255)
        g = random.randint(0,255)
        b = random.randint(0,255)
        neopixels[i] = (r,g,b)
    neopixels.show()

    time.sleep(1)
