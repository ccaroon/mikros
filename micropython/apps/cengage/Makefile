default:
	@echo "** Cengage **"

include ../../Ports.mk
include ../../Firmware.mk
include ../../FileMgmt.mk

install-shared:
	make upload-file FILE=../../lib/file_utils.py

install-led: install-shared
	make upload-file FILE=led_blink.py
	make upload-file FILE=led_pulse.py

install-neo: install-shared
	make upload-file FILE=../../lib/adafruit_io.py
	make upload-file FILE=neo.py
	make upload-file FILE=../../secrets.py
	make upload-file FILE=../../lib/wifi.py

install-boot-main:
	make upload-as-boot FILE=../../boots/simple.py
	make upload-as-main FILE=../../mains/hello_world.py

shell:
	picocom $(PORT) -b115200

.PHONY: default install-shared install-led install-neo shell
