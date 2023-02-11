# import time

# from twinkle import Twinkle
# ################################################################################
# # Main
# ################################################################################
# twinkle = Twinkle()
# while True:
#     t.run()
#     time.sleep(1.0)
# ------------------------------------------------------------------------------
import time
# from adafruit_circuitplayground import cp
from adafruit_circuitplayground.express import cpx

cpx.pixels[0] = (0,255,0)
time.sleep(10)
# ------------------------------------------------------------------------------
# """This example lights up the NeoPixels with a rainbow swirl."""
# def wheel(pos):
#     # Input a value 0 to 255 to get a color value.
#     # The colours are a transition r - g - b - back to r.
#     if (pos < 0) or (pos > 255):
#         return (0, 0, 0)
#     if pos < 85:
#         return (int(pos * 3), int(255 - (pos*3)), 0)
#     if pos < 170:
#         pos -= 85
#         return (int(255 - pos*3), 0, int(pos*3))
#     pos -= 170
#     return (0, int(pos*3), int(255 - pos*3))


# def rainbow_cycle(wait):
#     for j in range(255):
#         for i in range(cp.pixels.n):
#             idx = int((i * 256 / len(cp.pixels)) + j)
#             cp.pixels[i] = wheel(idx & 255)
#         cp.pixels.show()
#         time.sleep(wait)


# cp.pixels.auto_write = False
# cp.pixels.brightness = 0.3
# while True:
#     rainbow_cycle(0.001)    # rainbowcycle with 1ms delay per step
