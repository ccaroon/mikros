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