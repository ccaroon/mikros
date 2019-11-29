import time
from machine import Pin

class Indicator:

    PLATFORM_ESP8266 = "esp8266"
    PLATFORM_ESP32   = "esp32"

    def __init__(self, platform = "esp8266"):
        self.__platform = platform

        if platform == Indicator.PLATFORM_ESP8266:
            # NOTE: LED on/off is reversed. ON = off; OFF = on
            self.__red  = Pin(0, Pin.OUT)
            self.__blue = Pin(2, Pin.OUT)
        else:
            raise Exception("Unsupported Platform: '%s'" % (platform))

    def red(self, on=False):
        if on:
            self.__red.off()
        else:
            self.__red.on()

    def blue(self, on=False):
        if on:
            self.__blue.off()
        else:
            self.__blue.on()

    def all(self, on=False):
        self.red(on)
        self.blue(on)

    def blink_red(self, count, delay):
        for i in range(0, count):
            self.red(True)
            time.sleep(delay)
            self.red(False)
            time.sleep(delay)

    def blink_blue(self, count, delay):
        for i in range(0, count):
            self.blue(True)
            time.sleep(delay)
            self.blue(False)
            time.sleep(delay)

    def blink_all(self, count, delay):
        for i in range(0, count):
            self.blue(True)
            self.red(True)

            time.sleep(delay)

            self.blue(False)
            self.red(False)

            time.sleep(delay)

    # Method to implement the Notifer interface
    def notify(self, level, msg):
        count = level
        delay = 0.25

        self.all(True)

        if level < 3:
            self.blink_blue(count, delay)
        elif level == 3:
            self.blink_all(count, delay)
        else:
            self.blink_red(count, delay)

        self.all(False)






#
