UNICODE_ENABLE = yes
TAP_DANCE_ENABLE = yes
DIP_SWITCH_ENABLE = yes
RGBLIGHT_ENABLE = yes
CONSOLE_ENABLE=no

# Main keymap files
SRC += modifiers.c
SRC += os_switch.c
SRC += multitap.c

# Symbol files
SRC += symbols/symbols.c
SRC += symbols/calculus_symbols.c
SRC += symbols/comparison_symbols.c
SRC += symbols/greek_symbols.c
SRC += symbols/logic_symbols.c
SRC += symbols/misc_symbols.c
SRC += symbols/modifier_symbols.c
SRC += symbols/number_system_symbols.c
SRC += symbols/set_theory_symbols.c

# Mode-specific files
SRC += modes/mode.c
SRC += modes/latex/latex_mode.c
SRC += modes/microsoft_office/microsoft_office_mode.c
SRC += modes/unicode/unicode_mode.c
SRC += modes/libreoffice/libreoffice_mode.c