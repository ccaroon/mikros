include ../../../Ports.mk
include ../../../FileMgmt.mk

BOOT = ../../../boots/esp8266.pyc
APP  = main.pyc weather_station.pyc
LIBS = ../../../lib/adafruit_io.pyc ../../../lib/clock.pyc ../../../lib/indicator.pyc ../../../lib/wifi.pyc

%.pyc: %.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

../../../lib/%.pyc: ../../../lib/%.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

../../../boots/%.pyc: ../../../boots/%.py
	touch $@
	make upload-as-boot FILE=$(CURDIR)/$<

install: $(BOOT) $(APP) $(LIBS)

boot: $(BOOT)

app: $(APP)

libs: $(LIBS)

clean:
	rm -rf *.pyc

.PHONY: install libs clean
