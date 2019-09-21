include ../../../Ports.mk
include ../../../FileMgmt.mk

APP  = main.pyc weather_station.pyc
LIBS = ../../../lib/adafruit_io.pyc ../../../lib/clock.pyc ../../../lib/indicator.pyc ../../../lib/wifi.pyc

%.pyc: %.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

../../../lib/%.pyc: ../../../lib/%.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

install: $(APP) $(LIBS)

libs: $(LIBS)

clean:
	rm -rf *.pyc

.PHONY: install libs clean
