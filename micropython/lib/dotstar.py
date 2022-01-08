import apa102
import machine
import random
import time

class DotStar:
    def __init__(self, count, brightness=5, sck_pin=14, mosi_pin=13):
        self.__count = count
        self.__brightness = brightness
        self.strip = apa102.APA102(machine.Pin(sck_pin), machine.Pin(mosi_pin), count)

    def brightness(self, value):
        if value < 0:
            value = 0

        if value > 31:
            value = 31

        self.__brightness = value

    def fill(self, color:list, delay=0):
        color_bri = list(color)
        color_bri.append(self.__brightness)

        for i in range(0, self.__count):
            self.strip[i] = color_bri
            self.strip.write()
            if delay:
                time.sleep(delay)

    def rainbow(self):
        colors = [
            (255, 0,   0,   5),
            (255, 165, 0,   5),
            (255, 255, 0,   5),
            (0,   255, 0,   5),
            (0,   0,   255, 5),
            (128, 0,   255, 5)
        ]
        for o in range(0,6):
            offset = o * 12
            for i in range(0, 12):
                self.strip[i+offset] = colors[o]
                self.strip.write()

    def matrix(self, delay=0.10):
        black = (0,0,0,0)
        green = (0,255,0,self.__brightness)

        while (True):
            pixel = random.getrandbits(8) % 72
            color = (black, green)[random.getrandbits(1)]
            self.strip[pixel] = color
            self.strip.write()
            time.sleep(delay)

    def scroll_msg(self, msg):
        pass











#
