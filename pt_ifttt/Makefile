pt_ifttt.bin: project.properties src/main.ino
	mkdir -p dist/
	cp project.properties src/main.ino dist/
	particle compile photon dist/ --saveTo pt_ifttt.bin
	rm -rf dist/

flash: pt_ifttt.bin
	particle flash Greebo pt_ifttt.bin

clean:
	rm -rf pt_ifttt.bin dist/
