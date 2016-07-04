build: firmware.bin

firmware.bin: src/main.ino
	particle compile photon src --saveTo firmware.bin

upload: build
	particle flash WeatherMan2 firmware.bin

clean:
	rm firmware.bin
