from adafruit_io import AdafruitIO
from sensor import Sensor

class WeatherStation:

    def __init__(self, name):
        self.__name = name

        self.__aio     = AdafruitIO(name)
        self.__sensor  = Sensor(14)

        self.reset_high_low()

    def name(self):
        return self.__name

    def measure(self, publish=True):
        data = self.__sensor.get_temp_and_humidity()

        self.__update_high_temp(data['tempF'], publish)
        self.__update_low_temp(data['tempF'], publish)

        responses = []

        temp_resp = self.__aio.publish_data("temperature", round(data['tempF']), not publish)
        responses.append(temp_resp)

        humd_resp = self.__aio.publish_data("humidity", round(data['humidity']), not publish)
        responses.append(humd_resp)

        for resp in responses:
            self.__aio.handle_response(resp)

    def reset_high_low(self):
        self.__temp_high = -999
        self.__temp_low  = 999

    def __update_high_temp(self, tempF, publish):
        if tempF > self.__temp_high:
            self.__temp_high = tempF
            resp = self.__aio.publish_data("temperature-high", round(tempF), not publish)
            self.__aio.handle_response(resp)

    def __update_low_temp(self, tempF, publish):
        if tempF < self.__temp_low:
            self.__temp_low = tempF
            resp = self.__aio.publish_data("temperature-low", round(tempF), not publish)
            self.__aio.handle_response(resp)
