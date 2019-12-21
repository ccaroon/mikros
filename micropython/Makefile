noop:
	@echo "MicroPython Testing Grounds"

include Ports.mk
include Firmware.mk
include FileMgmt.mk

shell:
	picocom $(PORT) -b115200

clean:
	find . -name "*.pyc" -exec rm -rf {} +
	find . -name "*.mpy" -exec rm -rf {} +

.PHONY: noop shell clean
