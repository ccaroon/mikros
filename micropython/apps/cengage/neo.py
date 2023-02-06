import time
from adafruit_io import AdafruitIO
from machine import Pin
from neopixel import NeoPixel
from wifi import MyWifi

COLORS = {
    "black":  (0,0,0),
    "red":    (255,0,0),
    "orange": (255,128,0),
    "yellow": (255,255,0),
    "green":  (0,255,0),
    "blue":   (0,0,255),
    "indigo": (75,0,255),
    "violet": (128,0,255)
}

def poll_feed(aio, neo):
    data = aio.get_data("demo")
    color_name = data["results"][0]["value"]

    # print(color_name)

    if color_name == "roy.g.biv":
        neo[0] = COLORS["red"]
        neo[1] = COLORS["orange"]
        neo[2] = COLORS["green"]
        neo[3] = COLORS["blue"]
        neo[4] = COLORS["violet"]
    else:
        color = COLORS.get(color_name)
        if color:
            for i in range(0,5):
                neo[i] = color

    neo.write()

def color_picker():
    MyWifi.autoconnect()

    aio = AdafruitIO("ccaroon")
    pin = Pin(15, Pin.OUT)
    neo = NeoPixel(pin, 5)

    while True:
        poll_feed(aio, neo)
        time.sleep(2)
