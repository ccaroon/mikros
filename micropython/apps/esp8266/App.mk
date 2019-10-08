default:
	@echo "Include me in your app. :)"

%.pyc: %.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

../../../lib/%.pyc: ../../../lib/%.py
	touch $@
	make upload-file FILE=$(CURDIR)/$<

../../../boots/%.pyc: ../../../boots/%.py
	touch $@
	make upload-as-boot FILE=$(CURDIR)/$<

%.mpy: %.py
	mpy-cross $<
	make upload-file FILE=$(CURDIR)/$@

../../../lib/%.mpy: ../../../lib/%.py
	mpy-cross $<
	make upload-file FILE=$(CURDIR)/$@

# `boot.py` must be `boot.py` NOT `boot.mpy`
# ../../../boots/%.mpy: ../../../boots/%.py
# 	mpy-cross $<
# 	make upload-as-boot FILE=$(CURDIR)/$@

install: $(BOOT) $(APP) $(LIBS)

boot: $(BOOT)

app: $(APP)

libs: $(LIBS)

clean:
	rm -rf *.pyc
	rm -rf *.mpy

.PHONY: install libs clean
