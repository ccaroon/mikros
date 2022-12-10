import dotstar

d = dotstar.DotStar(6, 12, brightness=1)

d.fill((0,0,0))
# d.rainbow()
# d.matrix()

# d.set_pixel(0,0, (255,0,0,31))
# d.strip.write()

d.random(delay=0.005)
