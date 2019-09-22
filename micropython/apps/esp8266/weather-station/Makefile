include ../../../Ports.mk
include ../../../FileMgmt.mk

noop:
	@echo "Weather Station"

BOOT = ../../../boots/esp8266.pyc
APP  = main.pyc weather_station.pyc
LIBS = ../../../lib/adafruit_io.pyc ../../../lib/clock.pyc ../../../lib/indicator.pyc ../../../lib/wifi.pyc

include ../App.mk

get-log:
	make get-file FILE=weather-station.log
	clear
	cat /tmp/weather-station.log
