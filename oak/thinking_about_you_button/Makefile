thinking_about_you_button.bin: project.properties src/*
	particle compile oak . --saveTo thinking_about_you_button.bin

adama: thinking_about_you_button.bin
	particle flash Adama thinking_about_you_button.bin

cylon: thinking_about_you_button.bin
		particle flash Cylon thinking_about_you_button.bin

clean:
	rm -rf thinking_about_you_button.bin
