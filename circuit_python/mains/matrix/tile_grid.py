import random
import displayio
import time

import led_matrix

display = led_matrix.init_64x32(bit_depth=6)

# Rainbox Colors
palette = displayio.Palette(8)
palette[0] = 0x000000
palette[1] = 0xff0000
palette[2] = 0xfb9c13
palette[3] = 0xfffb09
palette[4] = 0x00ff00
palette[5] = 0x0000ff
palette[6] = 0x5f09ff
palette[7] = 0xa209ff

bitmap = displayio.Bitmap(display.width, display.height, 8)

tile_width = 16
tile_height = 16
grid = displayio.TileGrid(
    bitmap,
    pixel_shader=palette,
    width=4,
    height=2,
    tile_width=tile_width,
    tile_height=tile_height,
    default_tile=0
)


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
    for idx in range(grid.width * grid.height):
        grid[idx] = random.randint(0,7)
    time.sleep(1)
