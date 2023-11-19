# import board
import displayio
import time

import led_matrix


display = led_matrix.init_64x32()
# display = led_matrix.init_64x64()
# print(f"W: {display.width} x H: {display.height}")
# print(type(display))
# print(dir(display))

WIDTH=32
HEIGHT=32
OFFSET_X = int(WIDTH/2)
OFFSET_Y = int(HEIGHT/2)
# WIDTH=display.width
# HEIGHT=display.height
# OFFSET_X = 0
# OFFSET_Y = 0

# Bitmaps
bitmap1 = displayio.Bitmap(WIDTH, HEIGHT, 4)
bitmap2 = displayio.Bitmap(WIDTH, HEIGHT, 4)

# Colors & Palette
BLACK = 0
RED = 1
GREEN = 2
BLUE = 3
colors = (RED, GREEN, BLUE)

palette = displayio.Palette(4)
palette[BLACK] = 0x000000
palette[RED] = 0xff0000
palette[GREEN] = 0x00ff88
palette[BLUE] = 0x0000ff

bitmap1.fill(GREEN)
bitmap2.fill(BLUE)

# Create a TileGrid using the Bitmap and Palette
grid1 = displayio.TileGrid(bitmap1, pixel_shader=palette)
grid2 = displayio.TileGrid(bitmap2, pixel_shader=palette, x=64-32-8,y=64-32-8)
# grid3 = displayio.TileGrid(bitmap2, pixel_shader=palette)
# grid4 = displayio.TileGrid(bitmap2, pixel_shader=palette)

# Create a Group
group1 = displayio.Group(x=0,y=0)
group2 = displayio.Group(x=64-32-8,y=64-32-8)

# Add the TileGrid to the Group
group1.append(grid1)
group1.append(grid2)
# group2.append(grid2)

# Add the Group to the Display
# display.root_group = group2

# def color_bitmap(bitmap, color):
#     for x in range(bitmap.width):
#         for y in range(bitmap.height):
#             bitmap1[x,y] = color

def walk(color):
    for y in range(WIDTH):
        for x in range(HEIGHT):
            bitmap1[x,y] = color
            time.sleep(.025)

def fill_bitmap(pal_index):
    for x in range(WIDTH):
        for y in range(HEIGHT):
            bitmap1[x,y] = pal_index

display.root_group = group1
while True:
    # --------------------
    # pass
    # --------------------
    # for color in colors:
    #     fill_bitmap(color)
    #     time.sleep(1)
    # --------------------
    # for color in colors:
    #     walk(color)
    #     time.sleep(1)
    # --------------------
    # for grp in (group1, group2):
    #     display.root_group = grp
    #     time.sleep(1)
    # --------------------
    for color in colors:
        bitmap1.fill(color)
        time.sleep(1)












#
