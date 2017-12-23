import time
import random
from adafruit_circuitplayground.express import cpx

################################################################################
# Helper Functions
################################################################################
def set_color(color = (0,0,0)):
    '''Set all 10 pixels to the same color'''
    for i in range(10):
        cpx.pixels[i] =  color

def clear_all():
    '''Turn off all 10 pixels'''
    set_color((0,0,0,))

def led_off(i):
    '''Turn individual pixel off'''
    led_on(i, (0,0,0))

def led_on(i, color):
    '''Turn individual pixel on with the given color'''
    cpx.pixels[i] = color
################################################################################
# Pixel "Animations"
################################################################################
def blink(color):
    '''Blink all the pixels on/off in the given color'''
    clear_all()
    time.sleep(1.0)
    set_color(color)
    time.sleep(1.0)

def twinkle(color = (128,128,0)):
    '''Turn random pixels on & off in the given color giving the impression of
    them twinkling'''
    i = random.randint(0,9);

    clear_all()
    cpx.pixels[i] = color

    time.sleep(0.20)

def progress(duration, color, clear = True):
    '''Light up the pixels in order with the given color over the give duration'''
    wait = duration / 10

    if clear:
        clear_all()

    for i in range(10):
        p = i+1
        led_off(p - 1)
        time.sleep(wait)
        led_on(i, color)
    led_off(9)

def spinner(duration, color, clear = True):
    '''Create a spinner of the given color that takes the given duration to make
    one complete cycle'''
    wait = duration / 10;

    if clear:
        clear_all()

    prev_i = 0
    prev_j = 5
    for i in range(10):
        j = 0
        if i < 5:
            j = i + 5
        else:
            j = (i + 5) - 10

        led_off(prev_i)
        led_off(prev_j)

        led_on(i, color)
        led_on(j, color)

        prev_i = i
        prev_j = j

        time.sleep(wait)

    clear_all()
################################################################################
def do_loop():
    pass
################################################################################
# Main
################################################################################
while True:
    # blink((0,255,128))
    # twinkle()
    # spinner(0.75, (128,0,255))
    progress(2.0, (255,0,128))
    # time.sleep(1.0)
