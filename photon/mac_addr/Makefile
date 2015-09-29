build: firmware.bin

firmware.bin: src/main.ino
	particle compile photon src --saveTo firmware.bin

upload: build
	particle flash Dalek-77 firmware.bin

clean:
	rm firmware.bin
