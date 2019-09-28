import logging
import time

from adafruit_io import AdafruitIO
from chronos import Chronos
from indicator import Indicator
from weather_station import WeatherStation

MEASURE_FREQ = 1.00 * 60 # In Seconds
RETRY_DELAY  = 1.00 * 60 # In Seconds

dry_run = False
last_error = None

station = WeatherStation('weather-station-dev', maintain_state=True, publish=not dry_run)

indicate = Indicator()
aio = AdafruitIO(station.name())

log_stream = open("%s.log" % station.name(), "a")
logging.basicConfig(stream=log_stream, level=logging.INFO)
ws_log = logging.getLogger(station.name())

# Publish boot notification w/ datetime
aio.publish_data("notifications",
    "Boot: %s" % (Chronos.now_str()),
    dry_run=dry_run
)

# TODO: move this to Chronos
# (2019, 9, 25, 15, 57, 58, 2, 268)
# Assume it ran at midnight "today"
last_run = list(time.localtime())
for i in range(3,8):
    last_run[i] = 0

def reset_high_low():
    station.reset_high_low()
    aio.publish_data("notifications",
        "Chronos: Resetting High/Low",
        dry_run=dry_run
    )

Chronos.every("24h", "Reset High/Low", reset_high_low, last_run=last_run)
# Chronos.every("2m", "Check Time", Chronos.check, last_run=(2019, 09, 25, 15, 00, 00, 00, 00))

while (True):
    indicate.red(False)
    indicate.blue(False)

    try:
        indicate.blue(True)

        station.measure()

        indicate.blue(False)
        time.sleep(MEASURE_FREQ)
    except Exception as e:
        indicate.blue(False)
        indicate.red(True)

        msg = str(e)
        print(msg)
        ws_log.error(msg)

        # TODO: network check

        if str(last_error) != str(e):
            resp = aio.publish_data("notifications", str(e), dry_run=dry_run)
            try:
                aio.handle_response(resp)
            except Exception as e2:
                msg = "Failed to publish error: " % (e2)
                print(msg)
                ws_log.critical(msg)

            last_error = e

        time.sleep(RETRY_DELAY)
    finally:
        Chronos.tick(True)








#
