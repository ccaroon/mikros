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

upload-file:
ifneq ($(FILE),)
	ampy --port $(PORT) put $(FILE)
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif
