KEYBOARDS = mathboard

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/maglaur

	#make maglaur folder if not present
	mkdir -p qmk_firmware/keyboards/maglaur

	# add new symlinks
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/maglaur

	# run lint check
	cd qmk_firmware; qmk lint -km dev -kb maglaur/mathboard/v1 --strict

	# run build
	make BUILD_DIR=$(shell pwd)/compiled -j1 -C qmk_firmware maglaur/mathboard/v1:dev

	# cleanup symlinks
	rm -rf qmk_firmware/keyboards/maglaur

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex