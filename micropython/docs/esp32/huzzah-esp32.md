# ESP32
[Adafruit Huzzah32 Feather](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather)

## Specs
* 240 MHz dual core Tensilica LX6 microcontroller with 600 DMIPS
* Integrated 520 KB SRAM
* Integrated 802.11b/g/n HT40 Wi-Fi transceiver, baseband, stack and LWIP
* Integrated dual mode Bluetooth (classic and BLE)
* 4 MByte flash
* On-board PCB antenna
* Ultra-low noise analog amplifier
* Hall sensor
* 10x capacitive touch interface
* 32 kHz crystal oscillator
* 3 x UARTs (only two are configured by default in the Feather Arduino IDE support, one UART is used for bootloading/debug)
* 3 x SPI (only one is configured by default in the Feather Arduino IDE support)
* 2 x I2C (only one is configured by default in the Feather Arduino IDE support)
* 12 x ADC input channels
* 2 x I2S Audio
* 2 x DAC
* PWM/timer input/output available on every GPIO pin
* OpenOCD debug interface with 32 kB TRAX buffer
* SDIO master/slave 50 MHz
* SD-card interface support

## Power
* GND - this is the common ground for all power and logic
* BAT - this is the positive voltage to/from the JST jack for the optional Lipoly battery
* USB - this is the positive voltage to/from the micro USB jack if connected
* EN - this is the 3.3V regulator's enable pin. It's pulled up, so connect to ground to disable the 3.3V regulator
* 3V - this is the output from the 3.3V regulator. The regulator can supply 500mA peak but half of that is drawn by the ESP32, and it's a fairly power-hungry chip. So if you need a ton of power for stuff like LEDs, motors, etc. Use the USB or BAT pins, and an additional regulator

## RTC
    from machine import RTC
    #            (YYYY, MM, DD,  TZ , HH, mm, SS, MS)
    rtc.datetime((2019, 07, 06, None, 09, 54,  0,  0))
    # Should read the same as set above, except TZ will be correct.
    rtc.datetime()

### Notes
* Some pins are special about the ESP32 - here's a list of 'notorious' pins to watch for!
    - A2 / I34 - this pin is an input only! You can use it as an analog input so we suggest keeping it for that purpose
    - A3 / I39 - this pin is an input only! You can use it as an analog input so we suggest keeping it for that purpose
    - IO12 - this pin has an internal pulldown, and is used for booting up. We recommend not using it or if you do use it, as an output only so that nothing interferes with the pulldown when the board resets
    - A13 / I35 - this pin is not exposed, it is used only for measuring the voltage on the battery. The voltage is divided by 2 so be sure to double it once you've done the analog reading

#### Why does the yellow CHARGE LED blink while USB powered?
The charging circuit will flash when there is no LiPoly battery plugged in. It's harmless and doesn't mean anything. When a LiPoly battery is connect it will stabilize the charger and will stop flashing.

####  Why can I not read analog inputs once WiFi is initialized?
Due to the design of the ESP32, you can only read analog inputs on ADC #1 once WiFi has started. That means pins on ADC 2 (check the pinouts page) can't be used as analog inputs
