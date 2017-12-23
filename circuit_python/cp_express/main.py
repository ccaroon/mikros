import time
import random
from adafruit_circuitplayground.express import cpx

################################################################################
RED    = (255,0,0)
ORANGE = (255,128,0)
YELLOW = (255,255,0)
GREEN  = (0,255,0)
BLUE   = (0,0,255)
INDIGO = (255,0,128)
VIOLET = (128,0,255)

PRIMARY_COLORS = [
    RED,ORANGE,YELLOW,GREEN,BLUE,INDIGO,VIOLET
]
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
def blink(color = (0,42,142)):
    '''Blink all the pixels on/off in the given color'''
    clear_all()
    time.sleep(1.0)
    set_color(color)
    time.sleep(1.0)

def twinkle(count = 1, color = (128,128,0), wait = 0.25):
    '''Turn random pixels on & off in the given color giving the impression of
    them twinkling'''

    clear_all()
    for i in range(count):
        p = random.randint(0,9)
        cpx.pixels[p] = color

    time.sleep(wait)

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

def alt_colors(cycle, color1, color2):
    '''Alternate two colors on the even/odd pixels'''
    evn_color = color1
    odd_color = color2
    if cycle % 2 == 0:
        evn_color = color2
        odd_color = color1

    for i in range(10):
        if i % 2 == 0:
            led_on(i, evn_color)
        else:
            led_on(i, odd_color)

    time.sleep(1.0)

def random_color():
    '''Set all pixels each to a random color'''
    for i in range(10):
        r = random.randint(0,255)
        g = random.randint(0,255)
        b = random.randint(0,255)
        led_on(i, (r,g,b))

    time.sleep(0.5)

def primary_colors():
        '''Set all pixels each to a random PRIMARY_COLOR'''
    color_count = len(PRIMARY_COLORS)
    for i in range(10):
        color_index = random.randint(0, color_count-1)
        led_on(i, PRIMARY_COLORS[color_index])

    time.sleep(0.5)

# def wheel(pos):
#     # Input a value 0 to 255 to get a color value.
#     # The colours are a transition r - g - b - back to r.
#     # return ((0,124,255))
#     if (pos < 0):
#         return (0, 0, 0)
#     if (pos > 255):
#         return (0, 0, 0)
#     if (pos < 85):
#         return (int(pos * 3), int(255 - (pos*3)), 0)
#     elif (pos < 170):
#         pos -= 85
#         return (int(255 - pos*3), 0, int(pos*3))
#     else:
#         pos -= 170
#         return (0, int(pos*3), int(255 - pos*3))
#
# # i = 0
# def color_wheel():
#     for p in range(10):
#         # led_on(p, wheel(p))
#         # idx = int ((p * 256 / 10) + i)
#         # cpx.pixels[p] = wheel(idx & 255)
#         led_on(p, wheel(p & 255))
#
#     # i = (i+1) % 256  # run from 0 to 255
################################################################################
ACTION_INDEX = 0
ACTIONS = [twinkle,blink]
color = (64,64,128)
################################################################################
def do_loop(count):

    # if cpx.button_a:
        # color = (0,128,128)
        # pass
        # ACTION_INDEX = 0
        # ACTION_INDEX += 1
        # if ACTION_INDEX > len(ACTIONS):
        #     ACTION_INDEX = 0
        # current_action = ACTIONS[ACTION_INDEX]

    # if cpx.button_b:
        # pass
        # ACTION_INDEX = 1

    if cpx.switch:
        twinkle(3,color,0.20)
    else:
        # blink(color)
        # color_wheel()
        # alt_colors(count, (128,0,0),(0,128,0))
        # random_color()
        primary_colors()

    # ACTIONS[ACTION_INDEX]()

################################################################################
# Main
################################################################################
count = 0
while True:
    do_loop(count)
    count += 1




################################################################################
