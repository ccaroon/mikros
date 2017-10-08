htud21df_temp.bin: project.properties src/*
	particle compile photon . --saveTo htud21df_temp.bin

flash: htud21df_temp.bin
		particle flash Iapyx htud21df_temp.bin

clean:
	rm -rf htud21df_temp.bin
