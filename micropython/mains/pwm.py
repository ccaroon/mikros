import time

from machine import Pin, PWM

pin = Pin(2, Pin.OUT)
# NOTE: Once PWM is init'd can't use Digital IO (See beat())
pwm = PWM(pin)

# fast-breathing: pulse(delay=150, step=8000)
def pulse(delay=150, step=8000, count=5):
    start = step
    for i in range(count):
        print(i)
        for brightness in range(start, 65535, step):
            pwm.duty_u16(brightness)
            time.sleep_ms(delay)

        for brightness in range(65535, start, step * -1):
            pwm.duty_u16(brightness)
            time.sleep_ms(delay)
