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

	# Generate build information header file
	@echo "Generating build information header..."
	@BUILD_DATE="$$(date '+%Y-%m-%d')"; \
	BUILD_TIME="$$(date '+%H:%M:%S')"; \
	GIT_COMMIT="$$(git rev-parse --short HEAD 2>/dev/null || echo 'unknown')"; \
	COMPILER_VER="$$(gcc --version 2>/dev/null | head -n1 | sed 's/"/\\"/g' || echo 'unknown')"; \
	BUILD_FLAGS="-Os -g -flto"; \
	echo "Build Date: $$BUILD_DATE $$BUILD_TIME"; \
	echo "Git Commit: $$GIT_COMMIT"; \
	echo "Compiler: $$COMPILER_VER"; \
	echo "/* Auto-generated build information - DO NOT EDIT */" > mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#ifndef BUILD_INFO_GENERATED_H" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define BUILD_INFO_GENERATED_H" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define BUILD_DATE \"$$BUILD_DATE\"" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define BUILD_TIME \"$$BUILD_TIME\"" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define GIT_COMMIT_HASH \"$$GIT_COMMIT\"" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define COMPILER_VERSION \"$$COMPILER_VER\"" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#define BUILD_FLAGS \"$$BUILD_FLAGS\"" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "#endif // BUILD_INFO_GENERATED_H" >> mathpad/mp1a/keymaps/default/build_info_generated.h; \
	echo "Generated build_info_generated.h with build information"

	# run build
	qmk compile -j 0 -kb summacogni/mathpad/mp1a -km default $(if $(LAYOUT),-e SENDSTRING_LAYOUT=$(LAYOUT),)

	# cleanup symlinks (to avoid inadvertedly editing them instead of the true source files)
	rm -rf qmk_firmware/keyboards/summacogni

	# Create compile folder in case it does not exist
	mkdir -p compiled

	# Move .uf2 file to /compiled directory and calculate SHA256
	@LAYOUT_NAME="$(or $(LAYOUT),us_ansi)"; \
	EXPECTED_UF2="qmk_firmware/summacogni_mathpad_mp1a_default.uf2"; \
	echo "Looking for firmware file at: $$EXPECTED_UF2"; \
	if [ -f "$$EXPECTED_UF2" ]; then \
		echo "Found firmware file, calculating SHA256 and moving to compiled directory"; \
		FIRMWARE_SHA256=$$(sha256sum "$$EXPECTED_UF2" 2>/dev/null | cut -d' ' -f1 || shasum -a 256 "$$EXPECTED_UF2" 2>/dev/null | cut -d' ' -f1 || echo 'unknown'); \
		mv "$$EXPECTED_UF2" "compiled/summacogni_mathpad_mp1a_$$LAYOUT_NAME.uf2"; \
		echo "Firmware SHA256: $$FIRMWARE_SHA256"; \
		echo "Build completed successfully!"; \
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

# Clean target to remove build artifacts and generated files
clean:
	@echo "Cleaning build artifacts..."
	rm -rf qmk_firmware/keyboards/summacogni
	rm -f mathpad/mp1a/keymaps/default/build_info_generated.h
	rm -rf qmk_firmware/.build
	@echo "Clean complete!"