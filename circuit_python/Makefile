MAC_PORT = "/dev/tty.SLAB_USBtoUART"
LNX_PORT = "/dev/ttyACM0"
PORT = $(LNX_PORT)

shell:
	picocom $(PORT) -b115200

upload-as-main:
ifneq ($(FILE),)
	cp $(FILE) /media/$(USER)/CIRCUITPY/main.py
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif

.PHONY: shell upload-as-main
