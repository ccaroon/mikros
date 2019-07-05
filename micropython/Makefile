MAC_PORT = "/dev/tty.SLAB_USBtoUART"
LNX_PORT = "/dev/ttyUSB0"
PORT = $(LNX_PORT)

FIRMWARE_DIR=.firmware

ESP32-1=http://micropython.org/resources/firmware/esp32-20190705-v1.11-126-g7c2e83324.bin
ESP32-2=http://micropython.org/resources/firmware/esp32spiram-20190705-v1.11-126-g7c2e83324.bin

ESP8266=http://micropython.org/resources/firmware/esp8266-20190529-v1.11.bin

download-firmware-esp32:
	mkdir -p $(FIRMWARE_DIR)/esp32
	curl --output $(FIRMWARE_DIR)/esp32/`basename $(ESP32-1)` $(ESP32-1)
	curl --output $(FIRMWARE_DIR)/esp32/`basename $(ESP32-2)` $(ESP32-2)

install-firmware-esp32: download-firmware-esp32
	esptool.py --port /dev/ttyUSB0 erase_flash
	esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash -z 0x1000 $(FIRMWARE_DIR)/esp32/`basename $(ESP32-2)`

boot-wifi:
	cp boots/wifi.py boot.py
	ampy --port $(PORT) put boot.py
	rm -f boot.py

shell:
	picocom /dev/ttyUSB0 -b115200

clean:
	rm -rf $(FIRMWARE_DIR)


.PHONY: download-firmware-esp32 install-firmware-esp32 boot-wifi shell clean
