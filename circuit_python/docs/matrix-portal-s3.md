# Adafruit MatrixPortal S3 with ESP32S3
LED Matrix Driver Board

## Links
* Board: https://www.adafruit.com/product/5778
* Tutorial: https://learn.adafruit.com/adafruit-matrixportal-s3
* Bootloader Repair: https://learn.adafruit.com/adafruit-matrixportal-s3/factory-reset#factory-reset-and-bootloader-repair-3107941
* Python: https://circuitpython.org/board/adafruit_matrixportal_s3/

## Info
* Port: /dev/ttyACM0

## Hardware
* ESP32-S3 with 3.3v logic/power.
  - It has 8MB of Flash and 2MB of RAM.
* LIS3DH Triple-Axis Accelerometer
  - The accelerometer is connected via the I2C bus.
  - Please note the address of the accelerometer is 0x19 not 0x18 which is the default in our libraries
* RGB status NeoPixel labeled "STATUS". It is connected to `board.NEOPIXEL` or Arduino 4
* D13 LED. This is attached to `board.LED` and Arduino 13.
* UP button is attached to `board.BUTTON_UP` and Arduino 6.
* Down button is attached to `board.BUTTON_DOWN` and Arduino 7.
* NOTE: buttons do not have any pull-up resistors connect; pressing either of them pulls the input low.

## Development
* PortalBase: https://docs.circuitpython.org/projects/portalbase/en/latest/index.html
* MatrixPortal: https://docs.circuitpython.org/projects/matrixportal/en/latest/
* DisplayIO:
  - https://docs.circuitpython.org/en/latest/shared-bindings/displayio/
  - https://learn.adafruit.com/circuitpython-display-support-using-displayio
* Matrices with CPy: https://learn.adafruit.com/rgb-led-matrices-matrix-panels-with-circuitpython
