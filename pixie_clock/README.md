# Pixie Clock // Micropython Version


## PCB Design, etc...
* https://docs.kicad.org/9.0/en/getting_started_in_kicad/getting_started_in_kicad.html

### PCB Printers
* https://rushpcb.com
* https://www.pcbunlimited.com
* https://jlcpcb.com
* https://oshpark.com <-- Used Before


## Shift Register Info
* Google: "how to use shift register with micropython"
* https://github.com/mcauser/micropython-74hc595


## Requirements.txt
* mpremote mip install github:mcauser/micropython-74hc595
* wget https://raw.githubusercontent.com/BrianPugh/micropython-tomli/refs/heads/master/src/tomli/_parser.py -O lib/tomli.py


### Hardware Connection
* VCC and GND: Connect the 74HC595's VCC pin to the 3.3V or 5V supply of your MicroPython board (depending on the shift register's voltage requirements) and GND to the board's ground.
* OE (Output Enable): Connect OE to GND to always enable the outputs, or to a GPIO pin if you want to control when the outputs are active.
* MR (Master Reset): Connect MR to VCC to prevent accidental resets, or to a GPIO pin if you need to clear the register programmatically.
* Data Pin (SER): Connect to a MicroPython GPIO pin. This is where you send the serial data.
* Clock Pin (SRCLK): Connect to a MicroPython GPIO pin. This clock signal shifts the data into the register.
* Latch Pin (RCLK): Connect to a MicroPython GPIO pin. This clock signal transfers the data from the internal storage register to the output pins.
* Outputs (Q0-Q7): Connect these to the devices you want to control (e.g., LEDs with current-limiting resistors).


### Example Code
Using MCauser Library (Above)

* See sr_spi.py (SPI based)
* See sr_bb.py (Bit Blast based)
