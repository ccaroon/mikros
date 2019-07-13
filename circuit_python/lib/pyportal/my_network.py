import board
import busio
import digitalio

from adafruit_esp32spi import adafruit_esp32spi
import adafruit_esp32spi.adafruit_esp32spi_requests as requests

from secrets import secrets

class MyNetwork:
    esp32_cs    = digitalio.DigitalInOut(board.ESP_CS)
    esp32_ready = digitalio.DigitalInOut(board.ESP_BUSY)
    esp32_reset = digitalio.DigitalInOut(board.ESP_RESET)

    spi = busio.SPI(board.SCK, board.MOSI, board.MISO)
    ESP = adafruit_esp32spi.ESP_SPIcontrol(spi, esp32_cs, esp32_ready, esp32_reset)

    requests.set_interface(ESP)

    def __init__(self):
        pass

    @classmethod
    def status(cls):
        if cls.ESP.status == adafruit_esp32spi.WL_IDLE_STATUS:
            print("ESP32 found and in idle mode")
        print("Firmware vers.", cls.ESP.firmware_version)
        print("MAC addr:", [hex(i) for i in cls.ESP.MAC_address])

    @classmethod
    def scan(cls):
        for ap in cls.ESP.scan_networks():
            print("\t%s\t\tRSSI: %d" % (str(ap['ssid'], 'utf-8'), ap['rssi']))

    @classmethod
    def connect(cls):
        print("Connecting to '%s'..." % (secrets['ssid']))
        cls.ESP.connect_AP(secrets['ssid'], secrets['password'])
        print("Connected to", str(cls.ESP.ssid, 'utf-8'), "\tRSSI:", cls.ESP.rssi)

    @classmethod
    def check(cls):
        print("My IP address is", cls.ESP.pretty_ip(cls.ESP.ip_address))
        print("IP lookup adafruit.com: %s" % cls.ESP.pretty_ip(cls.ESP.get_host_by_name("adafruit.com")))
        print("Ping google.com: %d ms" % cls.ESP.ping("google.com"))


    @classmethod
    def get(cls, url):
        return requests.get(url)










#
