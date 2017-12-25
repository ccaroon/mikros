oak_temperature.bin: project.properties src/*
	particle compile oak src/ --saveTo oak_temperature.bin

flash: oak_temperature.bin
		particle flash Cylon oak_temperature.bin

clean:
	rm -rf oak_temperature.bin
