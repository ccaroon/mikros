import network
import utime

class MyNetwork:

    WLAN = network.WLAN(network.STA_IF)
    APNT  = network.WLAN(network.AP_IF)

    @classmethod
    def connect(cls):
        cls.WLAN.active(True)

        print("ESSID: ")
        essid = input()

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
    def check(cls):
        if cls.WLAN.isconnected():
            print("Connected")
            print(cls.WLAN.ifconfig())
        else:
            print("Not Connected")
