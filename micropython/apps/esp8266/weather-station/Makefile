include ../../../Ports.mk
include ../../../FileMgmt.mk

noop:
	@echo "Weather Station"

BOOT = ../../../boots/esp8266.pyc
APP  = main.pyc sensor.pyc weather_station.pyc
LIBS = ../../../lib/adafruit_io.pyc ../../../lib/chronos.pyc ../../../lib/indicator.pyc ../../../lib/wifi.pyc

include ../App.mk

get-log:
	@make get-file FILE=weather-station.log
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station.log
	@echo "-------------------------------------------------"

get-log-dev:
	@make get-file FILE=weather-station-dev.log
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station-dev.log
	@echo "-------------------------------------------------"

get-state:
	@make get-file FILE=weather-station.json
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station.json
	@echo "-------------------------------------------------"

get-state-dev:
	@make get-file FILE=weather-station-dev.json
	@echo "-------------------------------------------------"
	@cat /tmp/weather-station-dev.json
	@echo "-------------------------------------------------"

inspect: get-log get-state

inspect-dev: get-log-dev get-state-dev
