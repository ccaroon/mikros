import time

from adafruit_io import AdafruitIO
from indicator import Indicator
from secrets import secrets
from weather_station import WeatherStation

MEASURE_FREQ = 1.00 * 60 # In Seconds
RETRY_DELAY  = 0.50 * 60 # In Seconds

aio      = AdafruitIO(secrets, 'dev')
indicate = Indicator()
station  = WeatherStation(14)

dry_run = True
last_error = None

def handle_aio_response(resp):
    if resp['success'] and resp['dry_run']:
        results = resp['results']
        print("DRY RUN: [%s] -> %s" % (results['data']['value'], results['url']))
    elif resp['success']:
        results = resp['results']
        print("%s - %s: [%s]" % (results['id'], results['feed_key'], results['value']))
    else:
        error_msg = "Publish Error: %d - %s" % (resp['code'], resp['msg'])
        raise Exception(error_msg)

while (True):
    indicate.red(False)
    indicate.blue(False)

    try:
        indicate.blue(True)

        data = station.get_temp_and_humidity()

        responses = []

        temp_resp = aio.publish_data("weather-station.temperature", round(data['tempF']), dry_run)
        responses.append(temp_resp)

        humd_resp = aio.publish_data("weather-station.humidity",    round(data['humidity']), dry_run)
        responses.append(humd_resp)

        for resp in responses:
            handle_aio_response(resp)

        indicate.blue(False)
        time.sleep(MEASURE_FREQ)
    except Exception as e:
        indicate.blue(False)
        indicate.red(True)

        print(e)

        if last_error != e:
            resp = aio.publish_data("weather-station.errors", str(e), dry_run)
            try:
                handle_aio_response(resp)
            except Exception as e:
                print(e)

            last_error = e

        time.sleep(RETRY_DELAY)








#
