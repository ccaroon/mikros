# General
import board
import time

# Status LED
import simpleio

# NeoPixel
import neopixel

# Temp Sensor
import busio
import adafruit_adt7410

# Status LED
def status_led():
    status_led = simpleio.DigitalOut(board.D13)

    # Make it blink
    while True:
        status_led.value = 1
        time.sleep(1)
        status_led.value = 0
        time.sleep(1)

# NeoPixel
def neo_pixel():
    pixel = neopixel.NeoPixel(board.NEOPIXEL, 1)

    # Make it breathe
    inc = 5
    max = 128
    min = 5
    color = [0, min, min]
    while True:
        print(color)
        pixel[0] = color
        time.sleep(.012)

        # Only changing G & B to get a Cyan color
        new_clr = color[1] + inc

        if new_clr > max:
            new_clr = max
        elif new_clr < min:
            new_clr = min

        color[1] = color[2] = new_clr

        if new_clr >= max:
            inc = -inc

        if new_clr <= min:
            inc = -inc

# RTC
# TODO

# Light Sensor
# TODO

# Temperature Sensor
def temp_sensor():
    i2c_bus = busio.I2C(board.SCL, board.SDA)
    adt = adafruit_adt7410.ADT7410(i2c_bus, address=0x48)
    adt.high_resolution = True

    while True:
        celcius = adt.temperature
        # (29.5°C × 9/5) + 32 = 85.1°F
        fahr = (celcius * 9/5) + 32
        print("C: %.1f | F: %.1f" % (celcius, fahr))
        time.sleep(1)

# Network
# TODO

# Adafruit IO
# TODO

# ------------------------------------------------------------------------------
if __name__ == "__main__":
    # status_led()
    # neo_pixel()
    temp_sensor()








#
