KEYBOARDS = mathboard

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/maglaur

	#make maglaur folder if not present
	mkdir -p qmk_firmware/keyboards/maglaur

	# add new symlinks (on windows, this simply makes copies)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/maglaur

	cd qmk_firmware; 

	# run lint check
	qmk lint -km default -kb maglaur/mathboard/v1 --strict

	# run build
	qmk compile -j 0 -kb maglaur/mathboard/v1 -km default

	# Move .u2f file to /compiled
	mv qmk_firmware/*.uf2 compiled;