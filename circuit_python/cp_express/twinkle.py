import time
import random

from adafruit_circuitplayground.express import cpx

################################################################################
class Twinkle:
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

    def twinkle(self, count = 3, wait = 0.25):
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

    def run(self):
        self.twinkle()

        self._loop_count += 1

