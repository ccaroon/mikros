# Pixie Clock // Micropython Version


## Shift Register Info
* Google: "how to use shift register with micropython"
* https://github.com/mcauser/micropython-74hc595


## Requirements.txt
* mpremote mip install github:mcauser/micropython-74hc595


### Hardware Connection

    VCC and GND:
    Connect the 74HC595's VCC pin to the 3.3V or 5V supply of your MicroPython board (depending on the shift register's voltage requirements) and GND to the board's ground.

    OE (Output Enable):
    Connect OE to GND to always enable the outputs, or to a GPIO pin if you want to control when the outputs are active.

    MR (Master Reset):
    Connect MR to VCC to prevent accidental resets, or to a GPIO pin if you need to clear the register programmatically.

    Data Pin (SER):
    Connect to a MicroPython GPIO pin. This is where you send the serial data.

    Clock Pin (SRCLK):
    Connect to a MicroPython GPIO pin. This clock signal shifts the data into the register.

    Latch Pin (RCLK):
    Connect to a MicroPython GPIO pin. This clock signal transfers the data from the internal storage register to the output pins.

    Outputs (Q0-Q7):
    Connect these to the devices you want to control (e.g., LEDs with current-limiting resistors).

### Example Code
```python
from machine import Pin
import time

# Define the pins connected to the shift register
DATA_PIN = Pin(13, Pin.OUT)  # Serial Data Input -- Data Pin
CLOCK_PIN = Pin(14, Pin.OUT) # Shift Register Clock -- Clock Pin
LATCH_PIN = Pin(15, Pin.OUT) # Storage Register Clock (Latch) -- Latch Pin

def write_shift_register(value):
    """
    Writes an 8-bit value to the 74HC595 shift register.
    """
    LATCH_PIN.value(0)  # Pull latch LOW to prepare for data transfer
    for i in range(8):
        # Send the most significant bit first (MSB)
        bit = (value >> (7 - i)) & 1
        DATA_PIN.value(bit)
        CLOCK_PIN.value(1)  # Pulse clock HIGH
        CLOCK_PIN.value(0)  # Pulse clock LOW
    LATCH_PIN.value(1)  # Pull latch HIGH to update outputs

# Example usage:
while True:
    # Turn on LEDs in a sequence
    for i in range(8):
        write_shift_register(1 << i)  # Shift a single '1' bit
        time.sleep(0.1)

    # Turn off all LEDs
    write_shift_register(0)
    time.sleep(0.5)

    # Turn on all LEDs
    write_shift_register(0xFF)
    time.sleep(0.5)
```
