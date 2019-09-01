MAC_PORT = "/dev/tty.SLAB_USBtoUART"
LNX_PORT = "/dev/ttyUSB0"
PORT = $(LNX_PORT)

FIRMWARE_DIR=.firmware

# ESP 32
ESP32-1=http://micropython.org/resources/firmware/esp32-20190705-v1.11-126-g7c2e83324.bin
ESP32-2=http://micropython.org/resources/firmware/esp32spiram-20190705-v1.11-126-g7c2e83324.bin

download-firmware-esp32:
	mkdir -p $(FIRMWARE_DIR)/esp32
	curl --output $(FIRMWARE_DIR)/esp32/`basename $(ESP32-1)` $(ESP32-1)
	curl --output $(FIRMWARE_DIR)/esp32/`basename $(ESP32-2)` $(ESP32-2)

install-firmware-esp32: download-firmware-esp32
	esptool.py --port $(PORT) erase_flash
	esptool.py --chip esp32 --port $(PORT) write_flash -z 0x1000 $(FIRMWARE_DIR)/esp32/`basename $(ESP32-2)`

# ESP 8266
ESP8266=http://micropython.org/resources/firmware/esp8266-20190529-v1.11.bin

download-firmware-esp8266:
	mkdir -p $(FIRMWARE_DIR)/esp8266
	curl --output $(FIRMWARE_DIR)/esp8266/`basename $(ESP8266)` $(ESP8266)

install-firmware-esp8266: download-firmware-esp8266
	esptool.py --port $(PORT) erase_flash
	esptool.py --port $(PORT) --baud 460800 write_flash --flash_size=detect 0 $(FIRMWARE_DIR)/esp8266/`basename $(ESP8266)`

# Other
boot-wifi:
	cp boots/wifi.py boot.py
	ampy --port $(PORT) put boot.py
	rm -f boot.py

upload-as-main:
ifneq ($(FILE),)
	cp $(FILE) /tmp/main.py
	ampy --port $(PORT) put /tmp/main.py
	rm -f /tmp/main.py
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif

upload-as-boot:
ifneq ($(FILE),)
	cp $(FILE) /tmp/boot.py
	ampy --port $(PORT) put /tmp/boot.py
	rm -f /tmp/boot.py
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif

secrets.py: .secrets
	./bin/gen_secrets.py
	ampy --port $(PORT) put secrets.py

list-files:
	ampy --port $(PORT) ls

shell:
	picocom $(PORT) -b115200

clean:
	rm -rf $(FIRMWARE_DIR)


.PHONY: download-firmware-esp32 install-firmware-esp32 download-firmware-esp8266 install-firmware-esp8266 boot-wifi shell clean
