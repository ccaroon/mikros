noop:
	@echo "Hello"

include Ports.mk
include Firmware.mk
include FileMgmt.mk

# Other
boot-esp8266:
	cp boots/esp8266.py boot.py
	ampy --port $(PORT) put boot.py
	rm -f boot.py

install-app:
ifneq ($(APP),)
	make -C $(APP) install
else
	echo "ERROR: Must Specify an application with APP=app-name"
endif

shell:
	picocom $(PORT) -b115200

clean:
	rm -rf boots/*.pyc
	rm -rf lib/*.pyc

.PHONY: noop boot-esp8266 install-app shell clean
