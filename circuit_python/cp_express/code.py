import time
import random

from adafruit_circuitplayground.express import cpx

################################################################################
# NOTE:
# Some methods, etc commented out b/c was running out of memory.
# TODO:
# Separate stuff into individual modules and only require what's needed.
################################################################################
class Thing:
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

    ############################################################################
    def __init__(self):
        self._loop_count = 0

        self._action_index = 0
        self._curr_action = None
        self._actions = None

        self._twinkle_end_idx     = 1
        self._twinkle_curr_color  = self.PRIMARY_COLORS[0]
        self._twinkle_end_color   = self.PRIMARY_COLORS[self._twinkle_end_idx]

    ############################################################################
    # Helper Functions
    ############################################################################
    def set_color(self, color = (0,0,0)):
        '''Set all 10 pixels to the same color'''
        for i in range(10):
            cpx.pixels[i] =  color

    def clear_all(self):
        '''Turn off all 10 pixels'''
        self.set_color((0,0,0,))

    def led_off(self, i):
        '''Turn individual pixel off'''
        self.led_on(i, (0,0,0))

    def led_on(self, i, color):
        '''Turn individual pixel on with the given color'''
        cpx.pixels[i] = color
    ############################################################################
    # Pixel "Animations"
    ############################################################################
    def blink(self, color = (0,42,142)):
        '''Blink all the pixels on/off in the given color'''
        self.clear_all()
        time.sleep(1.0)
        self.set_color(color)
        time.sleep(1.0)

    # def twinkle(self, count = 3, color = (64,64,176), wait = 0.25):
    #     '''Turn random pixels on & off in the given color giving the impression
    #     of them twinkling'''
    #
    #     self.clear_all()
    #     for i in range(count):
    #         p = random.randint(0,9)
    #         cpx.pixels[p] = color
    #
    #     time.sleep(wait)

    def twinkle2(self, count = 3, wait = 0.25):
        '''Turn random pixels on & off while transitioning between
        PRIMARY_COLORS giving the impression of them twinkling'''

        # If the transition is complete, set a new end color
        if self._equal_colors(self._twinkle_curr_color, self._twinkle_end_color):
            self._twinkle_end_idx += 1
            if self._twinkle_end_idx > len(self.PRIMARY_COLORS) - 1:
                self._twinkle_end_idx = 0
            self._twinkle_end_color = self.PRIMARY_COLORS[self._twinkle_end_idx]

        # Display pixels
        self.clear_all()
        for i in range(count):
            p = random.randint(0,9)
            cpx.pixels[p] = self._twinkle_curr_color

        # Get next color in the transition
        if self._loop_count % 10 == 0:
            self._twinkle_curr_color = self._tx_next_color(
                self._twinkle_curr_color,
                self._twinkle_end_color,
                10
            )

        time.sleep(wait)

    # def progress(self, duration, color, clear = True):
    #     '''Light up the pixels in order with the given color over the give duration'''
    #     wait = duration / 10
    #
    #     if clear:
    #         self.clear_all()
    #
    #     for i in range(10):
    #         p = i+1
    #         self.led_off(p - 1)
    #         time.sleep(wait)
    #         self.led_on(i, color)
    #     self.led_off(9)
    #
    # def spinner(self, duration, color, clear = True):
    #     '''Create a spinner of the given color that takes the given duration to make
    #     one complete cycle'''
    #     wait = duration / 10;
    #
    #     if clear:
    #         self.clear_all()
    #
    #     prev_i = 0
    #     prev_j = 5
    #     for i in range(10):
    #         j = 0
    #         if i < 5:
    #             j = i + 5
    #         else:
    #             j = (i + 5) - 10
    #
    #         self.led_off(prev_i)
    #         self.led_off(prev_j)
    #
    #         self.led_on(i, color)
    #         self.led_on(j, color)
    #
    #         prev_i = i
    #         prev_j = j
    #
    #         time.sleep(wait)
    #
    #     self.clear_all()
    #
    # def alt_colors(self, color1 = RED, color2 = GREEN):
    #     '''Alternate two colors on the even/odd pixels'''
    #     evn_color = color1
    #     odd_color = color2
    #     if self._loop_count % 2 == 0:
    #         evn_color = color2
    #         odd_color = color1
    #
    #     for i in range(10):
    #         if i % 2 == 0:
    #             self.led_on(i, evn_color)
    #         else:
    #             self.led_on(i, odd_color)
    #
    #     time.sleep(1.0)

    # def random_color(self):
    #     '''Set all pixels each to a random color'''
    #     for i in range(10):
    #         r = random.randint(0,255)
    #         g = random.randint(0,255)
    #         b = random.randint(0,255)
    #         self.led_on(i, (r,g,b))
    #
    #     time.sleep(0.5)
    #
    # def primary_colors(self):
    #     '''Set all pixels each to a random PRIMARY_COLOR'''
    #     color_count = len(self.PRIMARY_COLORS)
    #     for i in range(10):
    #         color_index = random.randint(0, color_count-1)
    #         self.led_on(i, self.PRIMARY_COLORS[color_index])
    #
    #     time.sleep(0.5)

    def _equal_colors(self, c1, c2):
        are_equal = True
        for i in range(3):
            if c1[i] != c2[i]:
                are_equal = False
                break
        return(are_equal)

    def _adjust_RGB(self, idx, color1, color2, inc):
        new_color = list(color1)
        if color1[idx] > color2[idx]:
            diff = color1[idx] - color2[idx]
            if (diff < inc):
                new_color[idx] = color2[idx]
            else:
                new_color[idx] -= inc
        elif color1[idx] < color2[idx]:
            diff = color2[idx] - color1[idx]
            if (diff < inc):
                new_color[idx] = color2[idx]
            else:
                new_color[idx] += inc
        elif color1[idx] == color2[idx]:
            pass

        return(new_color)

    def _tx_next_color(self, start, end, inc):
        nxt_color = start
        nxt_color = self._adjust_RGB(0,nxt_color,end,inc) # R
        nxt_color = self._adjust_RGB(1,nxt_color,end,inc) # G
        nxt_color = self._adjust_RGB(2,nxt_color,end,inc) # B

        return(tuple(nxt_color))

    def transition_color(self, start = (255,255,255), end = (0,0,0), inc=50):
        curr_color = start
        self.set_color(curr_color)
        while not self._equal_colors(curr_color,end):
            curr_color = self._tx_next_color(curr_color,end,inc)
            time.sleep(0.5)
            print("Display %s" % (str(curr_color)))
            self.set_color(curr_color)

        time.sleep(10)

    ############################################################################
    def init_actions(self):
        self._actions = [
            self.blink,
            self.twinkle2,
            # self.transition_color,
            # self.twinkle,
            # self.alt_colors,
            # self.primary_colors
        ]
        self._curr_action = self._actions[self._action_index]

    def run(self):
        if cpx.button_a:
            self._action_index += 1
            if self._action_index > len(self._actions)-1:
                self._action_index = 0
            self._curr_action = self._actions[self._action_index]

        self._curr_action()

        # if cpx.switch:
        #     self.twinkle(3,thing.YELLOW,0.25)
        # else:
        #     # self.primary_colors()
        #     self.alt_colors(thing.RED,thing.GREEN)

        print("...loop counter: %d" % (self._loop_count))
        self._loop_count += 1

################################################################################
# Main
################################################################################
thing = Thing()
thing.init_actions()
while True:
    print ("---=== BEGIN RUN ===---")
    thing.run()
    print ("---=================---")
#
# ################################################################################
