import time

from adafruit_io import AdafruitIO
from indicator import Indicator
from secrets import secrets
from weather_station import WeatherStation

MEASURE_FREQ = 1.00 * 60 # In Seconds
RETRY_DELAY  = 0.05 * 60 # In Seconds

aio      = AdafruitIO(secrets, 'dev')
indicate = Indicator()
station  = WeatherStation(14)

dry_run = True

while (True):
    indicate.red(False)
    indicate.blue(False)

    try:
        indicate.blue(True)

        data = station.get_temp_and_humidity()

        responses = []
        temp_resp = aio.publish_data("weather-station.temperature", {"value": round(data['tempF'])}, dry_run)
        responses.append(temp_resp)

        humd_resp = aio.publish_data("weather-station.humidity",    {"value": round(data['humidity'])}, dry_run)
        responses.append(humd_resp)

        for resp in responses:
            if resp['success'] and resp['dry_run']:
                results = resp['results']
                print("DRY RUN: [%d] -> %s" % (results['data']['value'], results['url']))
            elif resp['success']:
                results = resp['results']
                print("%s - %s: [%s]" % (results['id'], results['feed_key'], results['value']))
            else:
                error_msg = "Publish Error: %d - %s" % (resp['code'], resp['msg'])
                raise Exception(error_msg)

        indicate.blue(False)
        time.sleep(MEASURE_FREQ)
    except Exception as e:
        indicate.blue(False)
        indicate.red(True)
        print(e)
        time.sleep(RETRY_DELAY)
