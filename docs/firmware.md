This page documents the Mathpad firmware. It is organized in four sections:
1) Overview
2) Setting up your development environment
3) Making modifications
4) Compiling

## Overview
Mathpad's firmware is built on the [QMK](https://qmk.fm) input device library. You do not need any experience with 
QMK or C to make modifications to the Mathpad firmware, but it won't hurt either.

Mathpad's firmware is found in [/firmware/mathpad/mp-1a/keymaps/default](https://github.com/Summa-Cogni/Mathpad/tree/Main/firmware/mathpad/mp_1a/keymaps/default).
There are some files in the folders above this one, but it is unlikely you will need to ever modify these, so we 
focus our attention on the `keymaps/default` folder.

Within this folder there are the following files:
- `globs.h` : Global variables
- `keymap.c`: Defines which symbols are where on Mathpad
- `mode.h`  : Functions related to mode-switching
- `modifiers.h` : Functions related to modifier keys
- `os_switch.h` : Functions related to the OS switch
- `normal_symbols_defs.h` : Logic definitions for all 'normal' (non-multitap) symbols
- `tapdance_symbols_defs.h` : Logic definitions for all multitap symbols
- `unicode_symbols.h` : Definitions of all Unicode mode symbols
- `latex.h` : Definitions of all LaTeX mode symbols
- `microsoft_office.h` : Definitions of all Microsoft Office Equation Editor symbols
- `rules.mk` : QMK configuration options

## Setting up your development environment
This guide assumes some experience with the command line terminal and Git.

### Step 1
Begin by cloning the Mathpad repository to your machine. In a command line terminal, navigate to the folder where 
you want the Mathpad repository to be cloned to, and type:
```
git clone https://github.com/Summa-Cogni/Mathpad.git
```

This may take a while, since the Mathpad repository depends on QMK, which is therefore also cloned.

### Step 2
Install the QMK build environment by following the 
'[Prepare Your Build Environment](https://docs.qmk.fm/newbs_getting_started#set-up-your-environment)' guide from 
the QMK docs.

### Step 3:
In a command line terminal, run QMK setup and provide the path to the QMK folder in the Mathpad repository:
```
qmk setup -H <path to QMK folder>
```

For example, if you cloned the Mathpad folder to `C:\Users\Jake\Mathpad`, the command must be:
```
qmk setup -H "C:\Users\Jake\Mathpad\firmware\qmk_firmware"
```

## Making modifications
This documentation cannot cover every possible modification, so only a few common changes are documented:
1) Replacing an existing symbol with a new symbol
2) Making an existing symbol multitap-enabled

### Replacing a symbol
If there is a specific symbol on Mathpad you would rather replace with some other symbol, this is easy to do.

**Step 1: Unicode**

Locate the Unicode code of your symbol on an online Unicode list, e.g. 
[compart.com](https://www.compart.com/en/unicode/). Add this code to the other `#define`'d symbols in `unicode.h`. 

**Step 2: LaTeX**

Find the LaTeX code for your symbol, for example from 
[this list](https://www.cmor-faculty.rice.edu/~heinken/latex/symbols.pdf). Add this code to the other `#define`'d 
symbols in `latex.h`. If the symbol requires any additional actions beyond just being typed, for example if you 
need the caret to backtrack a few spaces after the symbol code has been typed, add the required actions to 
`send_latex` in `latex.c`.

**Step 3: Microsoft Office**

Many symbols can be added to the equation editor of Microsoft Office as a Unicode symbol. If that is the case, you 
do not need to add a special Microsoft Office definition for your symbol. But if you do, you can add a new symbol 
definition to `microsoft_office.h`.

**Step 4: Mode-specific logic**

Open `normal_symbols_defs.h` and declare a new function definition for your symbol. Then go to `normal_symbols_defs.c` 
and define the function. Look at the other defined functions for examples of how to do it. The function will define 
how the symbol is sent depending on which mode is active, and uses the symbol definitions you added in the three 
first steps.

**Step 5: Place the symbol in the keymap**

In `keymap.c`, define a new keycode for your symbol in the enum `custom_keycodes`. Right below this enum you find 
the lists that define which symbols are on which keys. Locate the symbol you wish to replace, and replace it with 
the keycode you added to `custom_keycodes`. Finally, scroll down to the function `process_record_user` and add a new 
case that switches on they keycode you added to `custom_keycodes`, and calls the symbol function you defined in 
`normal_symbols_defs.c`.