import time

from adafruit_io import AdafruitIO
from chronos import Chronos
from indicator import Indicator
# from log_file import LogFile
# from notifier import Notifier
from weather_station import WeatherStation

# ------------------------------------------------------------------------------
station = WeatherStation('weather-station', maintain_state=True, publish=True)
aio = AdafruitIO(station.name())
# ------------------------------------------------------------------------------
def reset_high_low():
    station.reset_high_low()
    aio.publish_data("notifications",
        "Chronos: Resetting High/Low",
        dry_run=False
    )

# ------------------------------------------------------------------------------
def simple_main():
    MEASURE_FREQ = 1.00 * 60 # In Seconds

    indicate = Indicator()

    last_run = list(time.localtime())
    for i in range(3,8):
        last_run[i] = 0

    Chronos.every("24h", "Reset High/Low", reset_high_low, last_run=last_run)

    while (True):
        try:
            indicate.red(False)
            indicate.blue(False)

            indicate.blue(True)
            station.measure()
            indicate.blue(False)
        except Exception as e:
            indicate.blue(False)
            indicate.red(True)
            print(str(e))
        finally:
            Chronos.tick(True)
            time.sleep(MEASURE_FREQ)

# ------------------------------------------------------------------------------
def main():
    MEASURE_FREQ = 1.00 * 60 # In Seconds
    RETRY_DELAY  = 1.00 * 60 # In Seconds

    dry_run = False
    last_error = None

    station = WeatherStation('weather-station', maintain_state=True, publish=not dry_run)

    indicate = Indicator()
    aio = AdafruitIO(station.name())

    LogFile.init(station.name())
    main_log = LogFile.get_logger("main")

    # notifier = Notifier(indicate, aio, main_log)

    # Publish boot notification w/ datetime
    # aio.publish_data("notifications",
    #     "Boot: %s" % (Chronos.now_str()),
    #     dry_run=dry_run
    # )

    # TODO: move this to Chronos
    # (2019, 9, 25, 15, 57, 58, 2, 268)
    # Assume it ran at midnight "today"
    last_run = list(time.localtime())
    for i in range(3,8):
        last_run[i] = 0

    Chronos.every("24h", "Reset High/Low", reset_high_low, last_run=last_run)

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
            # notifier.error(msg)
            main_log.error(msg)

            # TODO: network check??

            if str(last_error) != str(e):
                resp = aio.publish_data("notifications", str(e), dry_run=dry_run)
                try:
                    aio.handle_response(resp)
                except Exception as e2:
                    msg = "Failed to publish error: " % (e2)
                    print(msg)
                    main_log.critical(msg)
                    # notifier.critical(msg)

                last_error = e

            time.sleep(RETRY_DELAY)
        finally:
            Chronos.tick(True)
# ------------------------------------------------------------------------------
# try:
    # main()
simple_main()
# except Exception as main_e:
#     with open("main-errors.log", "a") as error_log:
#         error_log.write(str(main_e))







#                           ----- EOF -----                                    #
