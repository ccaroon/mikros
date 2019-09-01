from machine import Pin

import time
import dht

import urequests

from secrets import secrets
AIO_USERNAME = secrets['aio_username']
AOI_KEY = secrets['aio_key']
AIO_URL = "https://io.adafruit.com/api/v2"

dht22 = dht.DHT22(Pin(4))
# ------------------------------------------------------------------------------
# TODO:
#   limit temp to whole number
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

while (True):
    temp = get_temperature()

    print("Temperature: [%f] [%d]" % (temp[1], round(temp[1])))
    output = publish_data("weather", {"value": round(temp[1])})

    if output['success'] == False:
        print("Publish Data Failed: %d\n%s" % (output['code'], output['msg']))
    else:
        print("Success [%s]" % (output['results']['id']))

    time.sleep(30)









#
