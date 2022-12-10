# micropython.org/download
FIRMWARE_DIR=.firmware

usage:
	@echo "MicroPython Download & Install"
	@echo "------------------------------"
	@echo "* download-firmware-esp32"
	@echo "* install-firmware-esp32"

	@echo "* download-firmware-esp8266"
	@echo "* instlal-firmware-esp8266"
	@echo "* clean-firmware"

# ESP 32
ESP32-BASE_URL=http://www.micropython.org/resources/firmware

# Generic (MicroMod-ESP32)
ESP32-GENERIC=esp32-20220618-v1.19.1.bin

# SPIRAM
ESP32-SPIRAM=esp32spiram-20220618-v1.19.1.bin

# OTA (Huzzah-32)
ESP32-OTA=esp32-ota-20220618-v1.19.1.bin

# D2WD
ESP32-D2WD=esp32-d2wd-20220618-v1.19.1.bin

# Default Firmware
ESP32=$(ESP32-GENERIC)

download-firmware-esp32:
	mkdir -p $(FIRMWARE_DIR)/esp32
	curl --output $(FIRMWARE_DIR)/esp32/$(ESP32) $(ESP32-BASE_URL)/$(ESP32)

install-firmware-esp32: download-firmware-esp32
	esptool.py --port $(PORT) erase_flash
	esptool.py --chip esp32 --port $(PORT) write_flash -z 0x1000 $(FIRMWARE_DIR)/esp32/$(ESP32)

# ESP 8266
# ------------------------------------------------------------------------------
# 512k  - https://micropython.org/resources/firmware/esp8266-512k-20210902-v1.17.bin
# 1MiB  - https://micropython.org/resources/firmware/esp8266-1m-20210902-v1.17.bin
# 2MiB+ - https://micropython.org/resources/firmware/esp8266-20210902-v1.17.bin
# ------------------------------------------------------------------------------
# ESP8266=http://micropython.org/resources/firmware/esp8266-20191220-v1.12.bin
# ESP8266=https://micropython.org/resources/firmware/esp8266-20210902-v1.17.bin
ESP8266=http://www.micropython.org/resources/firmware/esp8266-20220618-v1.19.1.bin

download-firmware-esp8266:
	mkdir -p $(FIRMWARE_DIR)/esp8266
	curl --output $(FIRMWARE_DIR)/esp8266/`basename $(ESP8266)` $(ESP8266)

install-firmware-esp8266: download-firmware-esp8266
	esptool.py --port $(PORT) erase_flash
	esptool.py --port $(PORT) --baud 460800 write_flash --flash_size=detect 0 $(FIRMWARE_DIR)/esp8266/`basename $(ESP8266)`

clean-firmware:
	rm -rf $(FIRMWARE_DIR)

# PyBoard v1.1
# Coming Soon
