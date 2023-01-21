# micropython.org/download
FIRMWARE_DIR=.firmware
FIRMWARE_BASE_URL=http://www.micropython.org/resources/firmware

usage:
	@echo "MicroPython Download & Install"
	@echo "------------------------------"
	@echo "* download-firmware-esp32"
	@echo "* install-firmware-esp32"

	@echo "* download-firmware-esp8266"
	@echo "* instlal-firmware-esp8266"

	@echo "* download-firmware-rp2040"
	@echo "* instlal-firmware-rp2040"

	@echo "* clean-firmware"

# ESP 32 ----------------------------------------------------------------------
## Generic
##   - SparkFun MicroMod-ESP32
ESP32-GENERIC=esp32-20220618-v1.19.1.bin

## SPIRAM
ESP32-SPIRAM=esp32spiram-20220618-v1.19.1.bin

## OTA
##   - AdaFruit Huzzah-32 Feather
ESP32-OTA=esp32-ota-20220618-v1.19.1.bin

## D2WD
ESP32-D2WD=esp32-d2wd-20220618-v1.19.1.bin

## Default Firmware
ESP32=$(ESP32-OTA)

download-firmware-esp32:
	mkdir -p $(FIRMWARE_DIR)/esp32
	curl --output $(FIRMWARE_DIR)/esp32/$(ESP32) $(FIRMWARE_BASE_URL)/$(ESP32)

install-firmware-esp32: download-firmware-esp32
	esptool.py --port $(PORT) erase_flash
	esptool.py --chip esp32 --port $(PORT) write_flash -z 0x1000 $(FIRMWARE_DIR)/esp32/$(ESP32)
# ------------------------------------------------------------------------------

# ESP 8266 --------------------------------------------------------------------
## Generic
ESP8266-GENERIC=esp8266-20220618-v1.19.1.bin

ESP8266=$(ESP8266-GENERIC)

download-firmware-esp8266:
	mkdir -p $(FIRMWARE_DIR)/esp8266
	curl --output $(FIRMWARE_DIR)/esp8266/$(ESP8266) $(FIRMWARE_BASE_URL)/$(ESP8266)

install-firmware-esp8266: download-firmware-esp8266
	esptool.py --port $(PORT) erase_flash
	esptool.py --port $(PORT) --baud 460800 write_flash --flash_size=detect 0 $(FIRMWARE_DIR)/esp8266/$(ESP8266)
# -----------------------------------------------------------------------------

# RP2040 ----------------------------------------------------------------------
## SparkFun Pro Micro
##   - AdaFruit KB2040 (Kee Boar Driver)
RP2040-PROMICRO=SPARKFUN_PROMICRO-20220618-v1.19.1.uf2

## AdaFruit ItsyBitsy
RP2040-ITSYBITSY=ADAFRUIT_ITSYBITSY_RP2040-20220618-v1.19.1.uf2

## Default Firmware
RP2040=$(RP2040-PROMICRO)

download-firmware-rp2040:
	mkdir -p $(FIRMWARE_DIR)/rp2040
	curl --output $(FIRMWARE_DIR)/rp2040/$(RP2040) $(FIRMWARE_BASE_URL)/$(RP2040)

## See docs/rp2040/kb2040.md for Install instructions
install-firmware-rp2040: download-firmware-rp2040
	head -20 docs/rp2040/kb2040.md
# ------------------------------------------------------------------------------


clean-firmware:
	rm -rf $(FIRMWARE_DIR)

# PyBoard v1.1
# Coming Soon
