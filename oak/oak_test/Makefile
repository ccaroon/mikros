oak_test.bin: project.properties src/*
	mkdir -p build/
	cp -a project.properties src/* lib/Blynk/* lib/ESP8266WiFi/* build/
	particle compile oak build/ --saveTo oak_test.bin
	rm -rf build/

flash: oak_test.bin
	particle flash Adama oak_test.bin

clean:
	rm -rf oak_test.bin build/
