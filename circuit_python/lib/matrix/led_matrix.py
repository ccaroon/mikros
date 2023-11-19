import board
import displayio
import rgbmatrix
import framebufferio

def init_64x32(bit_depth=6):
    displayio.release_displays()
    matrix = rgbmatrix.RGBMatrix(
        width=64, bit_depth=bit_depth,
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

    return display

def init_64x64(bit_depth=6):
    displayio.release_displays()
    matrix = rgbmatrix.RGBMatrix(
        width=64, height=64, bit_depth=bit_depth,
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
            board.MTX_ADDRD,
            board.MTX_ADDRE
        ],
        clock_pin=board.MTX_CLK,
        latch_pin=board.MTX_LAT,
        output_enable_pin=board.MTX_OE
    )
    display = framebufferio.FramebufferDisplay(matrix)
    return display
