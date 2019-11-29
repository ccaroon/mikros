include ../../../Ports.mk
include ../../../FileMgmt.mk

noop:
	@echo "Weather Station"

# NOTE: boot and main **must** be .py files ... not .mpy
BOOT = ../../../boots/weather_station.pyc
# BOOT = ../../../boots/simple.pyc
APP  = main.pyc sensor.mpy weather_station.mpy
# LIBS = ../../../lib/adafruit_io.mpy ../../../lib/chronos.mpy ../../../lib/indicator.mpy ../../../lib/log_file.mpy ../../../lib/notifier.mpy ../../../lib/wifi.mpy
LIBS = ../../../lib/adafruit_io.mpy ../../../lib/chronos.mpy ../../../lib/indicator.mpy ../../../lib/wifi.mpy ../../../lib/file_utils.mpy

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
