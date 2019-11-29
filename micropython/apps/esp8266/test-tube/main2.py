from machine import Pin

import utime
import blynklib

from chronos import Chronos

import blynklib

print("--- Connecting to Blynk...")
BLYNK_AUTH = 'kzV-4_HpLd3urNbZAAMggixDxFbcyPvM'
blynk = blynklib.Blynk(BLYNK_AUTH)

red = Pin(0, Pin.OUT)
red.on()

blue = Pin(2, Pin.OUT)
blue.on()

count = 0

print("--- Registering V1...")
@blynk.handle_event('read V1')
def handle_red(vpin):
    print("%d: %d" % (vpin,count))
    blynk.virtual_write(vpin, count)
    count += 1

# def blynk_blink():
#     pass

# def auto_blink():
#     red.off()
#     blue.on()
#     utime.sleep(.5)
#     red.on()
#     blue.off()
#     utime.sleep(.5)
#    Chronos.check()

print("--- Running...")
while True:
    blynk.run()
