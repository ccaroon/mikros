import board
import analogio

joy_x = analogio.AnalogIn(board.JOYSTICK_X)
joy_y = analogio.AnalogIn(board.JOYSTICK_Y)


x = joy_x.value
y = joy_y.value
