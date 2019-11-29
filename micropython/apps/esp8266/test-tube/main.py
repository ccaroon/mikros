from machine import Pin

import utime
import blynklib
import dht

print("--- Connecting to Blynk...")
# BLINK
# BLYNK_AUTH = 'kzV-4_HpLd3urNbZAAMggixDxFbcyPvM'

# WS
BLYNK_AUTH = 'ePczqByz8YHSJJnYJDow8Dgb6K0TIAi-'
blynk = blynklib.Blynk(BLYNK_AUTH)

T_COLOR = '#f5b041'
H_COLOR = '#85c1e9'
ERR_COLOR = '#444444'

T_VPIN = 1
H_VPIN = 2

dht22 = dht.DHT22(Pin(14, Pin.IN, Pin.PULL_UP))

@blynk.handle_event('read V{}'.format(T_VPIN))
def read_handler(vpin):
    temperature = 0.0
    humidity = 0.0

    # read sensor data
    try:
        dht22.measure()
        temperature = dht22.temperature()
        humidity = dht22.humidity()
    except OSError as o_err:
        print("Unable to get DHT22 sensor data: '{}'".format(o_err))

    # change widget values and colors according read results
    if temperature != 0.0 and humidity != 0.0:
        blynk.set_property(T_VPIN, 'color', T_COLOR)
        blynk.set_property(H_VPIN, 'color', H_COLOR)
        blynk.virtual_write(T_VPIN, temperature)
        blynk.virtual_write(H_VPIN, humidity)
        print(temperature, humidity)
    else:
        # show widgets aka 'disabled' that mean we had errors during read sensor operation
        blynk.set_property(T_VPIN, 'color', ERR_COLOR)
        blynk.set_property(H_VPIN, 'color', ERR_COLOR)


while True:
    blynk.run()
