from machine import Pin

import time
import dht

import urequests

from secrets import secrets
AIO_USERNAME = secrets['aio_username']
AOI_KEY = secrets['aio_key']
AIO_URL = "https://io.adafruit.com/api/v2"

MEASURE_FREQ = 1 * 60 # In Seconds
RETRY_DELAY  = .05 * 60 # In Seconds

red = Pin(0, Pin.OUT)
blue = Pin(2, Pin.OUT)

dht22 = dht.DHT22(Pin(14))
# ------------------------------------------------------------------------------
def publish_data(feed, data):
    resp = urequests.post(
        "%s/%s/feeds/%s/data" % (AIO_URL, AIO_USERNAME, feed),
        headers={'X-AIO-Key': AOI_KEY},
        json=data
    )

    output = None
    if resp.status_code == 200:
        output = {
            "success": True,
            "results" : resp.json()
        }
    else:
        output = {
            "success": False,
            "code": resp.status_code,
            "msg": resp.content
        }

    return (output)

def get_temperature():
    dht22.measure()

    tempC = dht22.temperature()
    tempF = tempC * 9/5 + 32

    return (tempC, tempF)

def get_humidity():
    dht22.measure()
    humD = dht22.humidity()
    return humD

def get_temp_and_humidity():
    dht22.measure()

    tempC = dht22.temperature()
    tempF = tempC * 9/5 + 32

    humD = dht22.humidity()

    return {'tempF': tempF, 'tempC': tempC, 'humidity': humD}

# NOTE: LED on/off is reversed. ON = off; OFF = on
while (True):
    red.on()
    blue.on()

    try:
        blue.off()

        data = get_temp_and_humidity()

        responses = []
        temp_resp = publish_data("weather-station.temperature", {"value": round(data['tempF'])})
        responses.append(temp_resp)

        humd_resp = publish_data("weather-station.humidity",    {"value": round(data['humidity'])})
        responses.append(humd_resp)

        for resp in responses:
            if resp['success']:
                results = resp['results']
                print("%s - %s: [%s]" % (results['id'], results['feed_key'], results['value']))
            else:
                error_msg = "Publish Error: %d - %s" % (resp['code'], resp['msg'])
                raise Exception(error_msg)

        blue.on()
        time.sleep(MEASURE_FREQ)
    except Exception as e:
        blue.on()
        red.off()
        print(e)
        time.sleep(RETRY_DELAY)
