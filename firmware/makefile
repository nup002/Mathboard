KEYBOARDS = sweet16
PATH_sweet16 = sweet16

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/mathboard/$(PATH_$@); done
	
	#make mathboard folder if not present
	mkdir -p qmk_firmware/keyboards/mathboard
	
	# add new symlinks
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/mathboard/$(PATH_$@)

	# run lint check
	#cd qmk_firmware; qmk lint -km default -kb mathboard/$(PATH_$@) --strict

	# run build
	make BUILD_DIR=$(shell pwd)/compiled -j1 -C qmk_firmware mathboard/$(PATH_$@):default

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/mathboard/$(PATH_$@); done

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex