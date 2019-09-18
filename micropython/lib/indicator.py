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
