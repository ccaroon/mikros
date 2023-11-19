import random
import displayio
import time

import led_matrix


display = led_matrix.init_64x32(bit_depth=6)

palette = displayio.Palette(8)
# RGB -> RBG (B & G swapped)
palette[0] = 0x000000 # black
palette[1] = 0xff0000 # red
palette[2] = 0xff00aa # orange
palette[3] = 0xff00ff # yellow
palette[4] = 0x0000ff # green
palette[5] = 0x00ff00 # blue
palette[6] = 0x80ff00 # indigo
palette[7] = 0xffff00 # violet

bitmap = displayio.Bitmap(display.width, display.height, 8)

grid = displayio.TileGrid(
    bitmap,
    pixel_shader=palette,
    width=4,        # num cols in grid (in tiles)
    height=2,       # num rows in grid (in tiles)
    tile_width=16,  # each tile width in pixels
    tile_height=16, # each tile height in pixels
    default_tile=0  # all tiles will display contents of this tile
)

# Map a different color to each tile in the grid
# 4 x 2 = 8 tiles = 8 colors
for y in range(bitmap.height):
    for x in range(bitmap.width):
        color = ((x // 8) // 2) + (((y // 8) // 2) * 4)
        # print(f"[{x}],[{y}] -> [{color}]")
        bitmap[x,y] = color

group = displayio.Group()
group.append(grid)
display.root_group = group

print(f"Grid [{grid.width}]x[{grid.height}] - ({grid.tile_width})x({grid.tile_height})")

while True:
    # update each tile in the grid to the contents of another random tile
    for idx in range(grid.width * grid.height):
        grid[idx] = random.randint(0,7)
    time.sleep(1)
