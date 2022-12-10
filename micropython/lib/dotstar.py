import apa102
import machine
import random
import time

class DotStar:

    COLORS = {
        'off':   (0,   0,  0),
        'green': (0, 255,  0)
    }

    def __init__(self, rows, cols, brightness=5, sck_pin=14, mosi_pin=13):
        self.__rows = rows
        self.__cols = cols
        self.__brightness = brightness
        self.strip = apa102.APA102(machine.Pin(sck_pin), machine.Pin(mosi_pin), rows * cols)

    def __make_color(self, r, g, b, brightness=None):
        bri = brightness if brightness else self.__brightness
        return (r,g,b,bri)

    def index_to_coord(self, idx):
        col = idx % self.__cols
        row = (idx - col) / self.__cols

        return (row, col)

    def coord_to_index(self, row, col):
        return (row * self.__cols) + col

    def set_pixel(self, row, col, color):
        i = self.coord_to_index(row, col)
        self.strip[i] = color

    def color(self, name):
        color = self.COLORS.get(name)
        color_bri = self.__make_color(0,0,0,0)

        if color:
            color_bri = self.__make_color(*color)

        return color_bri

    def brightness(self, value):
        if value < 0:
            value = 0

        if value > 31:
            value = 31

        self.__brightness = value

    def fill(self, color:list, delay=0):
        color_bri = self.__make_color(*color)

        for i in range(0, self.strip.n):
            self.strip[i] = color_bri
            self.strip.write()
            if delay:
                time.sleep(delay)

    def rainbow(self):
        colors = [
            (255, 0,   0,   self.__brightness),
            (255, 165, 0,   self.__brightness),
            (255, 255, 0,   self.__brightness),
            (0,   255, 0,   self.__brightness),
            (0,   0,   255, self.__brightness),
            (128, 0,   255, self.__brightness)
        ]
        for row in range(0,6):
            for col in range(0,12):
                i = self.coord_to_index(row,col)
                print("(%d,%d) ==> %d" % (row,col,i))
                self.strip[i] = colors[row]
                self.strip.write()

    # choose a random col: 0 - 11
    #   if no pixel at row 0, set to green
    #   walk each pixel down the col by 1
    def matrix(self, delay=0.10):
        off = self.color('off')
        green = self.color('green')
        while True:
            col = random.getrandbits(8) % 12
            pixel = col + 60
            curr_color = self.strip[pixel]
            if curr_color == off:
                self.strip[pixel] = green

            # "March" each col down 1 pixel
            # TODO: don't hard-code rows and cols
            for col in range(0,12):
                for row in range(0,6):
                    i = self.coord_to_index(row,col)



    def random(self, delay=0.10):
        black = self.color('off')
        green = self.color('green')

        while True:
            pixel = random.getrandbits(8) % (self.__rows * self.__cols)
            color = (black, green)[random.getrandbits(1)]
            self.strip[pixel] = color
            self.strip.write()
            time.sleep(delay)

    def scroll_msg(self, msg):
        pass











#
