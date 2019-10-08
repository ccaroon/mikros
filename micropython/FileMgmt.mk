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

list-files:
	ampy --port $(PORT) ls

get-file:
ifneq ($(FILE),)
	ampy --port $(PORT) get $(FILE) > /tmp/$(FILE)
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif

rm-file:
ifneq ($(FILE),)
	ampy --port $(PORT) rm $(FILE)
else
	echo "ERROR: Must Specify a filename with FILE=filename"
endif

secrets.py: .secrets
	./bin/gen_secrets.py
	mpy-cross secrets.py
	ampy --port $(PORT) put secrets.mpy
