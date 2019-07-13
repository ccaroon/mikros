# PyPortal
The PyPortal uses an ATMEL (Microchip) ATSAMD51J20, and an Espressif ESP32 Wi-Fi coprocessor with TLS/SSL support built-in. PyPortal has a 3.2″ 320 x 240 color TFT with resistive touch screen. PyPortal includes: speaker, light sensor, temperature sensor, NeoPixel, microSD card slot, 8MB flash, plug-in ports for I2C and 2 analog/digital pins, 3D files for custom enclosures / lanyard fastening. Open-source hardware, and Open-Source software, CircuitPython and Arduino. The device shows up as a USB drive and the code (Python) can be edited in any IDE, text editor, etc.

The M4 and ESP32 are a great couple - and each bring their own strengths to this board. The SAMD51 M4 has native USB so it can show up like a disk drive, act as a MIDI or HID keyboard/mouse, and of course bootload and debug over a serial port. It also has DACs, ADC, PWM, and tons of GPIO. Meanwhile, the ESP32 has secure WiFi capabilities, and plenty of Flash and RAM to buffer sockets. By letting the ESP32 focus on the complex TLS/SSL computation and socket buffering, it frees up the SAMD51 to act as the user interface. You get a great programming experience thanks to the native USB with files available for drag-n-drop, and you don't have to spend a ton of processor time and memory to do SSL encryption/decryption and certificate management. It's the best of both worlds!

## Specs
https://learn.adafruit.com/adafruit-pyportal/pinouts

* Speaker
* Light Sensor
    - Analog input, connected to board.LIGHT (CircuitPython) or A2 (Arduino)
    - Read it as any analog value ranging from 0 (dark) to 1023 (in Arduino) or 65535 (CircuitPython) when bright.
* Temperature Sensor (The sensor is I2C connected)
* NeoPixel x 1
    - board.NEOPIXEL or Arduino D2
* Status LED
    - Towards the bottom on the left is the D13 LED.
    - This is attached to board.L and Arduino 13
* MicroSD Slot
* 8MB Flash
* Plug-in ports for I2C and 2 analog/digital pins
* Reset Button
    - Click it once to re-start your firmware.
    - Click twice to enter bootloader mode

## Installing Circuit Python
1. Double-click Reset button on back
2. LED will turn Green
3. Drag `.UF2` onto `PORTALBOOT`
4. Wait for reboot and re-mount of `CIRCUITPY` drive.

## WiFi
Update the `secrets.py` on the `CIRCUITPY` drive with SSID and Password
