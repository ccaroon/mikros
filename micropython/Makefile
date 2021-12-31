default:
	@echo "MicroPython Testing Grounds"
	@echo "---------------------------"
	@echo "* shell"
	@echo "* clean"
	@echo "---------------------------"
	@echo "* Can download and install Firmware - See Firmware.mk"
	@echo "* Can manage file on a device - See FileMgmt.mk"

include Ports.mk
include Firmware.mk
include FileMgmt.mk

shell:
	picocom $(PORT) -b115200

clean:
	find . -name "*.pyc" -exec rm -rf {} +
	find . -name "*.mpy" -exec rm -rf {} +

.PHONY: default shell clean
