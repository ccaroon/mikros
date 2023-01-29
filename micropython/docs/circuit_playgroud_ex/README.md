# AdaFruit Circuit Playground Express

## Circuit Python
www.circuitpython.org

Can access with `picocom` or similar on `/dev/ttyACM0`.
However, **cannot** upload files using `ampy`. Get "read-only" error.

CircuitPython is **very** frustrating to work with.

## Micropython

### Firmare Installation
Use "AdaFruit Feather M0 Express" firmware.

1. Double press Reset button - All LEDs should turn Green
2. CPlayBoot drive should show up and be mounted
3. Drag `.UF2` firmware file onto CPlayBoot
4. CPlayBoot should dissappear
5. Should be able to access with `picocom` or similar on `/dev/ttyACM0`

## Notes
* NeoPixel module not installed by default. Get it from: https://raw.githubusercontent.com/micropython/micropython-lib/master/micropython/drivers/led/neopixel/neopixel.py
  - however, does not work b/c `machine.bitstream` isn't available.
* Use CircuitPython
