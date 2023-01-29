import time
import random
from machine import Pin
from neopixel import NeoPixel

# MicroMod: G0 == Pin-15
# Huzzah-32: 15
pin_num = 8

# Number of Pixel in board/strip/matrix
num_pixels = 10

# RGB == 3 | RGBW == 4
bits_per_pixel = 3

pin = Pin(pin_num, Pin.OUT)
np = NeoPixel(pin, num_pixels, bpp=bits_per_pixel)

def random_fill():
    for i in range(0,num_pixels):
        red = random.randint(0,255)
        green = random.randint(0,255)
        blue = random.randint(0,255)
        white = random.randint(0,32)

        if bits_per_pixel == 3:
            np[i] = (red, green, blue)
        else:
            np[i] = (red, green, blue, white)

    np.write()

def matrix():
    for i in range(0, num_pixels):
        color = random.choice(((0,0,0,0),(0,255,0,0)))
        np[i] = color

    np.write()
# -----------------------------------------------------------------------------
while True:
    # random_fill()
    matrix()
    time.sleep(0.5)
