import urequests
from machine import RTC

import re

class MyClock:
    def __init__(self):
        pass

    CLOCK = RTC()

    @classmethod
    def sync(cls):
        """Sync with 'Internet' Time"""
        data = None

        resp = urequests.get("http://worldclockapi.com/api/json/est/now")
        if resp.status_code == 200:
            data = resp.json()
        else:
            raise Exception("Error Sync'ing Time: [%d]" % (resp.status_code))


        # 2019-09-17T17:40-04:00
        current_time = data['currentDateTime']

        matches = re.match("(\d+)-(\d+)-(\d+)T(\d+):(\d+)(\+|-)(\d+):(\d+)", current_time)

        if not matches:
            raise Exception("Error Parsing DateTime: %s" % (current_time))

        now = []

        # 1-3 == YYYY, MM, DD
        for i in range(1,4):
            now.append(int(matches.group(i)))

        # 6-7 == (+|-), TZOffset
        tz = int(matches.group(7))
        if matches.group(6) == '-':
            tz *= -1
        now.append(tz)

        # 4-5 = HH, mm
        for i in range(4,6):
            now.append(int(matches.group(i)))
        # Add seconds, milliseconds
        now.extend((0,0))

        cls.CLOCK.datetime(now)

    # TODO: alarm handling
    # ...for example, reset high, low values once a day
    # ...resync the clock once a day


    @classmethod
    def check(cls):
        print(cls.CLOCK.datetime())









#
