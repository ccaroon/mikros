MAC_PORT = "/dev/tty.SLAB_USBtoUART"
LNX_PORT = "/dev/ttyUSB0"
PORT = $(LNX_PORT)

noop:
	@echo "Hello"

include Firmware.mk
include Upload.mk

# Other
boot-esp8266:
	cp boots/esp8266.py boot.py
	ampy --port $(PORT) put boot.py
	rm -f boot.py

install-app:
ifneq ($(APP),)
	# ampy --port $(PORT) put $(APP)
	make -C $(APP) install
else
	echo "ERROR: Must Specify an application with APP=app-name"
endif

secrets.py: .secrets
	./bin/gen_secrets.py
	ampy --port $(PORT) put secrets.py

list-files:
	ampy --port $(PORT) ls

shell:
	picocom $(PORT) -b115200



.PHONY: noop boot-esp8266 list-files shell
