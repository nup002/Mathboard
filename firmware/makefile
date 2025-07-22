# List all supported keyboard layouts
SUPPORTED_LAYOUTS = canadian_multilingual croatian czech czech_mac_ansi czech_mac_iso \
    danish belgian uk us_international estonian finnish french french_afnor bepo \
    belgian canadian_french swiss_fr french_mac_iso german swiss_de german_mac_iso \
    hungarian icelandic italian italian_mac_ansi italian_mac_iso japanese latvian \
    lithuanian_azerty lithuanian_qwerty norwegian portuguese portuguese_mac_iso brazilian_abnt2 \
    romanian serbian_latin slovak slovenian spanish spanish_dvorak spanish_latin_america swedish \
    turkish_f turkish_q colemak dvorak dvorak_fr dvorak_programmer norman workman workman_zxcvm

.PHONY: all all-layouts check-layout
all: $(if $(LAYOUT),check-layout,)
	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/summacogni

	# make summacogni folder if not present
	mkdir -p qmk_firmware/keyboards/summacogni

	# add new symlinks (on windows, this simply makes copies)
	ln -s $(shell pwd)/mathpad qmk_firmware/keyboards/summacogni

	cd qmk_firmware; 

	# run lint check
	qmk lint -km default -kb summacogni/mathpad/mp1a --strict

	# run build
	qmk compile -j 0 --compiledb -kb summacogni/mathpad/mp1a -km default $(if $(LAYOUT),-e SENDSTRING_LAYOUT=$(LAYOUT),)

	# cleanup symlinks (to avoid inadvertedly editing them instead of the true source files)
	rm -rf qmk_firmware/keyboards/summacogni

	# Move .uf2 file to /compiled directory
	mkdir -p compiled

	# Ensure the file exists before moving it
	@LAYOUT_NAME="$(or $(LAYOUT),us_ansi)"; \
	EXPECTED_UF2="qmk_firmware/summacogni_mathpad_mp1a_default.uf2"; \
	echo "Looking for firmware file at: $$EXPECTED_UF2"; \
	if [ -f "$$EXPECTED_UF2" ]; then \
		echo "Found firmware file, moving to compiled directory"; \
		mv "$$EXPECTED_UF2" "compiled/summacogni_mathpad_mp1a_$$LAYOUT_NAME.uf2"; \
	else \
		echo "ERROR: Firmware file not found at expected location"; \
		exit 1; \
	fi


# Target to compile for all layouts
all-layouts:
	@echo "Building for all layouts..."
	$(MAKE)  # Build default first
	@for layout in $(SUPPORTED_LAYOUTS); do \
		echo "Building for $$layout..."; \
		$(MAKE) LAYOUT=$$layout; \
	done
	@echo "All layout builds complete!"

# Layout validation target
check-layout:
	@if echo "$(SUPPORTED_LAYOUTS)" | grep -wq "$(LAYOUT)"; then \
		echo "Building with $(LAYOUT) layout support"; \
	else \
		echo "Error: '$(LAYOUT)' is not a supported layout (see https://docs.qmk.fm/reference_keymap_extras#header-files)"; \
		echo "Supported layouts are: $(SUPPORTED_LAYOUTS)"; \
		exit 1; \
	fi