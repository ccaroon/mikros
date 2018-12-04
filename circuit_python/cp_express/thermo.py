# import time
# import random

from adafruit_circuitplayground.express import cpx

class Thermo:

    def __init__(self):
        pass

    def tempF(self):
        tC = cpx.temperature
        return (tC * 1.8 + 32.0)

    def run (self):
        tempF = self.tempF()

        # A - B to a-b
        # (val - A)*(b-a)/(B-A) + a
        num_pixels = int((tempF - 0) * (10-0)/(100-0) + 0)

        for i in range(0, num_pixels):
            if i < 7:
                r = 0
                g = int(i * 42.5)
                b = int(255 - (i * 42.5))
                cpx.pixels[i] = (r, g, b)
            elif i >= 7:
                r = int((i - 6) * 85)
                g = int(255 - ((i - 6) * 42.5))
                b = 0
                cpx.pixels[i] = (r, g, b)

        #  Turn off the rest of the pixels
        for i in range(num_pixels, 10):
            cpx.pixels[i] = (0,0,0)
