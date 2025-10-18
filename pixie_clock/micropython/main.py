from machine import Pin, RTC, SPI
from sr74hc595 import SR74HC595_SPI
import time

import digits

SR_COUNT = 4

def run():
    # Init Shift Register
    spi = SPI(1, 1000000, mosi=18, sck=5, miso=19)
    latch = Pin(15, Pin.OUT)
    sr = SR74HC595_SPI(spi, latch, SR_COUNT)

    # Init RTC
    rtc = RTC()

    # Tick, Tock
    while True:
        now = rtc.datetime()
        date = f"{now[1]}/{now[2]:02}/{now[0]}"
        tyme = f"{now[4]}:{now[5]:02}:{now[6]:02}"
        print(f"{date} {tyme}")

        hour = now[4]
        digit1 = hour // 10
        digit2 = hour % 10
        sr[0] = digits.DIGITS[digit1]
        sr[1] = digits.DIGITS[digit2]

        minutes = now[5]
        digit1 = minutes // 10
        digit2 = minutes % 10
        sr[2] = digits.DIGITS[digit1]
        sr[3] = digits.DIGITS[digit2]


        time.sleep(1)


run()
