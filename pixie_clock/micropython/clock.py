import machine
import time

rtc = machine.RTC()

def run():
    while True:
        now = rtc.datetime()
        date = f"{now[1]}/{now[2]:02}/{now[0]}"
        tyme = f"{now[4]}:{now[5]:02}:{now[6]:02}"
        print(f"{date} {tyme}")

        time.sleep(1)


run()
