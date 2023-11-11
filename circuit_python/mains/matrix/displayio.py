import board
import displayio
import time
import rgbmatrix
import framebufferio

displayio.release_displays()
matrix = rgbmatrix.RGBMatrix(
    width=64, bit_depth=4,
    rgb_pins=[
        board.MTX_R1,
        board.MTX_G1,
        board.MTX_B1,
        board.MTX_R2,
        board.MTX_G2,
        board.MTX_B2
    ],
    addr_pins=[
        board.MTX_ADDRA,
        board.MTX_ADDRB,
        board.MTX_ADDRC,
        board.MTX_ADDRD
    ],
    clock_pin=board.MTX_CLK,
    latch_pin=board.MTX_LAT,
    output_enable_pin=board.MTX_OE
)
display = framebufferio.FramebufferDisplay(matrix)

# print(dir(display))
# print(type(display))
print(dir(display))

bitmap = displayio.Bitmap(32,32,4)
palette = displayio.Palette(4)

BLACK = 0
RED = 1
GREEN = 2
BLUE = 3

colors = (RED, GREEN, BLUE)

palette[BLACK] = 0x000000
palette[RED] = 0xff0000
palette[GREEN] = 0x00ff00
palette[BLUE] = 0x0000ff


# Create a TileGrid using the Bitmap and Palette
tile_grid = displayio.TileGrid(bitmap, pixel_shader=palette)

# Create a Group
group = displayio.Group(x=16,y=0)

# Add the TileGrid to the Group
group.append(tile_grid)

# Add the Group to the Display
display.root_group = group

def color_it(pal_index):
    for x in range(32):
        for y in range(32):
            bitmap[x,y] = pal_index

while True:
    for color in colors:
        color_it(color)
        time.sleep(1)
