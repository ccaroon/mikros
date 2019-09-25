from machine import Pin

import dht

class Sensor:
    def __init__(self, pin = 14):
        self.__sensor = dht.DHT22(Pin(pin))

    def get_temperature(self):
        self.__sensor.measure()

        tempC = self.__sensor.temperature()
        tempF = Sensor.convertCtoF(tempC)

        return {'tempC': tempC, 'tempF': tempF}

    def get_humidity(self):
        self.__sensor.measure()
        humD = self.__sensor.humidity()
        return humD

    def get_temp_and_humidity(self):
        self.__sensor.measure()

        tempC = self.__sensor.temperature()
        tempF = Sensor.convertCtoF(tempC)

        humD = self.__sensor.humidity()

        return {'tempF': tempF, 'tempC': tempC, 'humidity': humD}

    @classmethod
    def convertCtoF(cls, tempC):
        return (tempC * 9/5 + 32)
