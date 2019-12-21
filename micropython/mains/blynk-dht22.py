from machine import Pin

import utime
import blynklib
import dht

BLYNK_AUTH = 'UaAufOIriuP0hCw_XltDU1x8sRxTlKMM'
blynk = blynklib.Blynk(BLYNK_AUTH)

T_VPIN = 1
H_VPIN = 2

dht22 = dht.DHT22(Pin(14, Pin.IN, Pin.PULL_UP))

@blynk.handle_event('read V{}'.format(T_VPIN))
def read_handler(vpin):
    tempC = 0.0
    tempF = 0.0
    humidity = 0.0

    # read sensor data
    try:
        dht22.measure()
        tempC = dht22.temperature()
        tempF = round(tempC * 9/5 + 32)
        humidity = round(dht22.humidity())
    except OSError as o_err:
        print("Unable to get DHT22 sensor data: '{}'".format(o_err))

    # change widget values and colors according read results
    if tempF != 0.0 and humidity != 0.0:
        blynk.virtual_write(T_VPIN, tempF)
        blynk.virtual_write(H_VPIN, humidity)
        print("%02dF -- %02d%%" % (tempF, humidity))

if __name__ == "__main__":
    while True:
        blynk.run()
