import re

import ntptime
import time

from machine import RTC

from config import Config

class Chronos:
    CLOCK   = RTC()
    CRONTAB = {}

    def __init__(self):
        pass

    @classmethod
    def __convert_period_to_seconds(cls, value, units):
        seconds = None

        if units == 'D':
            seconds = value * 86400
        elif units == 'H':
            seconds = value * (60 * 60)
        elif units == 'M':
            seconds = value * 60

        return (seconds)

    @classmethod
    def is_dst(cls):
        is_dst = False
        now = cls.CLOCK.datetime()
        date_code = (now[1] * 100) + now[2]

        # GET DST table for current year
        dst_period = Config.get("datetime:dst_table:%d" % (now[0]))

        if date_code >= dst_period[0] and date_code <= dst_period[1]:
            is_dst = True

        # print("DCode: %d | DST? %s | DST from %d to %d" % (date_code, is_dst, dst_period[0], dst_period[1]))

        return is_dst

    @classmethod
    def sync(cls):
        """Sync with 'Internet' Time"""
        tz_offset = Config.get("datetime:tz_offset")
        ntptime.host = "time.nist.gov"
        # ntptime is in UTC
        now_secs = ntptime.time()
        tm = time.gmtime(now_secs)

        cls.CLOCK.datetime(
            (
                # year, month, day
                tm[0],  tm[1], tm[2],
                # weekday
                tm[6] + 1,
                # hours,           minutes, seconds
                tm[3] + tz_offset, tm[4],   tm[5],
                # sub-seconds
                0
            )
        )

        # Can't check if DST until after datetime is set
        if cls.is_dst():
            print("--Adjusting for DST--")
            now = cls.CLOCK.datetime()
            dst_now = list(now)
            # Add 1 to hour
            dst_now[4] += 1
            # Set DST adjusted time
            cls.CLOCK.datetime(dst_now)

    @classmethod
    def every(cls, period, name, handler, **kwargs):
        matches = re.match("(\d+)([DdHhMm])", period)
        if matches == None:
            raise ValueError("Invalid period [%s]" % (period))

        period_value = int(matches.group(1))
        period_units = matches.group(2).upper()

        period_in_secs = cls.__convert_period_to_seconds(period_value, period_units)

        last_run = time.mktime(time.localtime())
        lrun = kwargs.get('last_run', None)
        if lrun:
            last_run = time.mktime(lrun)

        cls.CRONTAB[name] = {
            "period": period_in_secs,
            "last_run": last_run,
            "handler": handler
        }

    @classmethod
    def tick(cls, debug=False):
        now = time.mktime(time.localtime())

        for name, cron in cls.CRONTAB.items():
            passed = now - cron['last_run']

            if debug:
                print("Chronos.tick(%s) - Time Passed: %ds / %ds" % (name, passed, cron['period']))

            if  passed >= cron['period']:
                cron['handler'](now)
                cron['last_run'] = now

    @classmethod
    def now_str(cls):
        now = cls.CLOCK.datetime()
        return "%4d-%02d-%02d @ %02d:%02d:%02d" % (now[0], now[1], now[2], now[4], now[5], now[6])

    @classmethod
    def check(cls):
        print(cls.now_str())
