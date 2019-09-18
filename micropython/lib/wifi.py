import network
import urequests
import utime

class MyNetwork:

    WLAN = network.WLAN(network.STA_IF)
    APNT  = network.WLAN(network.AP_IF)

    @classmethod
    def connect(cls, name, passwd):
        cls.WLAN.active(True)

        essid = name
        if not essid:
            print("ESSID: ")
            essid = input()

        password = passwd
        if not password:
            print("PASSWORD: ")
            password = input()

        cls.WLAN.connect(essid, password)

        count = 1
        while count <= 10 and cls.WLAN.isconnected() == False:
            print("Waiting for connection to be established: %d" % (count))
            utime.sleep(2)
            count += 1

        if cls.WLAN.isconnected():
            print("Connected to '%s'" % (essid))
        else:
            print("Failed to connect to '%s'" % (essid))

    @classmethod
    def test(cls, url="http://api.open-notify.org/iss-now.json"):
        resp = urequests.get(url)
        if resp.status_code == 200:
            return resp.json()
        else:
            return "Error GET'ting '%s': [%d]" % (url, resp.status_code)

    @classmethod
    def scan(cls):
        return cls.WLAN.scan()

    @classmethod
    def check(cls):
        if cls.WLAN.isconnected():
            print("Connected")
            print(cls.WLAN.ifconfig())
        else:
            print("Not Connected")
