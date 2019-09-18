include ../../../Ports.mk
include ../../../FileMgmt.mk

install: main.py libs weather_station.py
	# make secrets.py
	# make upload-as-main FILE=$(CURDIR)/main.py
	# make upload-file FILE=$(CURDIR)/weather_station.py

main.py:
	make upload-as-main FILE=$(CURDIR)/main.py

weather_station.py:
	make upload-file FILE=$(CURDIR)/weather_station.py

libs:
	make upload-file FILE=../../../lib/adafruit_io.py
	make upload-file FILE=../../../lib/clock.py
	make upload-file FILE=../../../lib/indicator.py
	make upload-file FILE=../../../lib/wifi.py


.PHONY: install main.py weather_station.py libs
