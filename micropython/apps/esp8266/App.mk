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

install: $(BOOT) $(APP) $(LIBS)

boot: $(BOOT)

app: $(APP)

libs: $(LIBS)

clean:
	rm -rf *.pyc

.PHONY: install libs clean
