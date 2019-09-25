include ../../../Ports.mk
include ../../../FileMgmt.mk

noop:
	@echo "Weather Station"

BOOT = ../../../boots/esp8266.pyc
APP  = main.pyc sensor.pyc weather_station.pyc
LIBS = ../../../lib/adafruit_io.pyc ../../../lib/chronos.pyc ../../../lib/indicator.pyc ../../../lib/wifi.pyc

include ../App.mk

get-log:
	make get-file FILE=weather-station.log
	clear
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station.log
	@echo "-------------------------------------------------"

get-log-dev:
	make get-file FILE=weather-station-dev.log
	clear
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station-dev.log
	@echo "-------------------------------------------------"
