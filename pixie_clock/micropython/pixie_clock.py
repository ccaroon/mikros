from machine import Pin, RTC, SPI
from sr74hc595 import SR74HC595_SPI
import time

import digits

SR_COUNT = 2

def run():
    # Init Shift Register
    spi = SPI(1, 1000000)
    rclk = Pin("D5", Pin.OUT)
    sr = SR74HC595_SPI(spi, rclk, SR_COUNT)

    # Init RTC
    rtc = RTC()

    # Tick, Tock
    while True:
        now = rtc.datetime()
        date = f"{now[1]}/{now[2]:02}/{now[0]}"
        tyme = f"{now[4]}:{now[5]:02}:{now[6]:02}"
        print(f"{date} {tyme}")

        seconds = now[6]
        digit1 = seconds // 10
        digit2 = seconds % 10
        print(f"{digit1}:{digit2}")
        sr[0] = digits.DIGITS[digit1]
        sr[1] = digits.DIGITS[digit2]


        time.sleep(1)


run()
