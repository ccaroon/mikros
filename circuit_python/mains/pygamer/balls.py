import ugame
import stage

class Ball(stage.Sprite):
    BANK_NUM = 1

    def __init__(self, bank, x, y):
        super().__init__(bank, self.BANK_NUM, x, y)

        self.dx = 8
        self.dy = 4

    def update(self):
        super().update()

        self.set_frame(self.frame % 4 + 1)
        self.move(self.x + self.dx, self.y + self.dy)

        if not 0 < self.x < 144:
            self.dx = -self.dx

        if not 0 < self.y < 112:
            self.dy = -self.dy

# ------------------------------------------------------------------------------
if __name__ == "__main__":

    bank = stage.Bank.from_bmp16("balls.bmp")

    WIDTH = 10
    HEIGHT = 8
    background = stage.Grid(bank, WIDTH, HEIGHT)

    text = stage.Text(13, 1)
    text.move(32, 60)
    text.text("Hello, World!")

    balls = [
        Ball(bank, 8, 8),
        Ball(bank, 64, 0),
        Ball(bank, 0, 76),
        Ball(bank, 111, 64)
    ]

    FPS = 12
    game = stage.Stage(ugame.display, FPS)
    game.layers = [text]
    game.layers.extend(balls)
    game.layers.append(background)
    game.render_block()

    dx = 2
    while True:
        for ball in balls:
            ball.update()

        game.render_sprites(balls)
        game.tick()







#
