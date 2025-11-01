from machine import Pin, RTC, SPI
from sr74hc595 import SR74HC595_SPI
import time

import pixie_clock.digits as digits

class PixieClock:
    def __init__(self):
        # Init Shift Register
        spi = SPI(1, 1000000, mosi=18, sck=5, miso=19)
        latch = Pin(15, Pin.OUT)
        self.__shift_reg = SR74HC595_SPI(spi, latch, 4)

        # Init RTC
        self.__rtc = RTC()


    def __display_time(self):
            now = self.__rtc.datetime()

            hour = now[4]
            digit1 = hour // 10
            digit2 = hour % 10
            self.__shift_reg[0] = digits.DIGITS[digit1]
            self.__shift_reg[1] = digits.DIGITS[digit2]

            minutes = now[5]
            digit1 = minutes // 10
            digit2 = minutes % 10
            self.__shift_reg[2] = digits.DIGITS[digit1]
            self.__shift_reg[3] = digits.DIGITS[digit2]

            # TODO: comment out
            date = f"{now[1]}/{now[2]:02}/{now[0]}"
            tyme = f"{now[4]}:{now[5]:02}:{now[6]:02}"
            print(f"{date} {tyme}")


    def run(self):
        # Tick, Tock
        while True:
            self.__display_time()
            time.sleep(1)
