This page documents the Mathpad firmware. It is organized in four sections:
1) Overview
2) Setting up your development environment
3) Making modifications
4) Compiling

## Overview
Mathpad's firmware is built on the [QMK](https://qmk.fm) input device library and written in the programming language C. 
Previous experience with QMK or C is not a requirement to make modifications to the Mathpad firmware, but it certainly
won't hurt, either.

Since Mathpad is based on QMK, you can easily develop and compile the firmware on nearly all platforms, including 
Windows.

Mathpad's firmware is found in [/firmware/mathpad/mp1a/keymaps/default](https://github.com/Summa-Cogni/Mathpad/tree/Main/firmware/mathpad/mp1a/keymaps/default).
There are some additional files in the folders above this one, but it is unlikely you will need to ever modify them. 
We therefore focus our attention on the `keymaps/default` folder.

Within this folder there are (among others) the following files:
- `globals.h` : Global variables
- `keymap.c`: Defines which symbols are where on Mathpad
- `mode.c`  : Functions related to mode-switching
- `modifiers.c` : Functions related to modifier keys
- `os_switch.c` : Functions related to the OS switch
- `normal_symbols_defs.c` : Logic definitions for all 'normal' (non-multitap) symbols
- `multitap_symbols_defs.c` : Logic definitions for all multitap symbols
- `unicode_symbols.c` : Definitions of all Unicode mode symbols
- `latex.c` : Definitions of all LaTeX mode symbols
- `microsoft_office.c` : Definitions of all Microsoft Office Equation Editor symbols
- `rules.mk` : QMK configuration options

## Setting Up Your Development Environment
This guide assumes some experience with the command line terminal and Git. You must have Git installed. If you do not,
following [this guide](https://github.com/git-guides/install-git).

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
>[!TIP]
> If you are on Windows, you must use the QMK MSYS terminal for all `qmk` commands.
>

In a command line terminal (or QMK MSYS on Windows), run QMK setup and provide the path to the QMK folder in the Mathpad repository:
```
qmk setup -H <path to QMK folder>
```

For example, if you cloned the Mathpad folder to `C:\Users\Jake\Mathpad`, the command must be:
```
qmk setup -H "C:\Users\Jake\Mathpad\firmware\qmk_firmware"
```

## Making Modifications
This documentation cannot cover every possible modification someone may want to make to the Mathpad firmware, so 
only a few common changes are documented:
1) Replacing an existing symbol with a new symbol
2) Making an existing symbol multitap-enabled

### Replacing a symbol
If there is a specific symbol on Mathpad you would prefer was different, this is easy to do but 
requires a few steps. The new symbol must be defined for all the different modes (Unicode, LaTeX, etc), and 
added to the keymap.

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
do not need to add a special Microsoft Office definition for your symbol. But if your symbol requires a code to be 
typed in order to appear correctly, you must add a new symbol definition to `microsoft_office.h`.

**Step 4: Mode logic**

Open `normal_symbols_defs.h` and declare a new function definition for your symbol. Then go to `normal_symbols_defs.c` 
and define the function. Look at the other defined functions for examples of how to do it. The function defines 
how the symbol is sent depending on which mode is active, and uses the symbol definitions you added in the three 
first steps.

**Step 5: Place the symbol in the keymap**

In `keymap.c`, define a new keycode for your symbol in the enum `custom_keycodes` around line 43. Right below this enum 
you find the lists that define which symbols are on which keys. Locate the symbol you wish to replace, and replace it 
with the keycode you added to `custom_keycodes`. Finally, scroll down to the function `process_record_user` and add a new 
case that switches on they keycode you added to `custom_keycodes`, and calls the symbol function you defined in 
`normal_symbols_defs.c`.

### Multitap-enabling a symbol
If there is an existing symbol on the Mathpad that you would like to extend so that when you double-tap it you get 
a different symbol, this section will show you how.

It involves defining the new symbol, defining a multitap symbol for the existing symbol, and adding the multitap symbol
to the keymap.

>[!TIP]
>QMK calls their multitapping functionality for 'Tap Dance'. You will therefore see a lot of references to this term.
> Read more about Tap Dance [here](https://docs.qmk.fm/features/tap_dance).
>

**Step 1**

Add your new symbol by following step 1, 2, and 3 in [Replacing a Symbol](#replacing-a-symbol).

**Step 2: Make a new multitap symbol**

Go to `multitap_symbols_defs.h` and add a new multitap keycode to the `tap_dance_keys` enum. If, for 
example, you are multitap-enabling the Union symbol, you would name the new keycode `UNION_TD`.

Then, scroll down and define a new multitap function. In our example with the Union symbol, you would declare a 
function named `void union_dance(tap_dance_state *s, void *d)`.
Then go to `multitap_symbols_defs.c` and define the logic of the function. Look at the other defined functions for 
examples of how to do it. The function defines how each of the multitap symbols are sent depending on which mode 
is active, and uses the symbol definitions you added in the first step.

You must define the array of symbols that are sent when single, double, triple tapping, etc. It should be clear 
from the multitude of examples in this file how to do it.

**Step 3: Place the multitap symbol in the keymap**

Open `keymap.c` and scroll down to around line 300. Add a new entry to `tap_dance_actions` with the multitap keycode 
and multitap function you defined in step 2.

Then scroll up to around line 100 and locate the original symbol keycode you are multitap-enabling. In this example 
we are multitap-enabling the Union symbol, so the keycode we want to replace is `KC_UNION`, and we replace it with 
`TD(UNION_TD)` which we defined earlier.

## Compiling
Compiling the firmware is quite simple and is done with a single command. In a command line terminal 
(or in QMK MSYS on Windows), navigate to the `Mathpad/firmware` folder. Then, type a command depending on 
the keyboard layout being used by the computer you will be using your Mathpad with:
<!-- tabs:start -->

#### **US ANSI**

You're good to go! The default build layout is US ANSI and you just have to type:
```shell
make
```

#### **Any other layout**

Locate your layout in the [list of QMK supported layouts](https://docs.qmk.fm/reference_keymap_extras#header-files). 
In this table, locate the "Sendstring LUT Header" for your layout and note the part of its name after `sendstring_`. 
As an example, if your layout is English UK, you will find that the corresponding LUT header is `sendstring_uk.h`, 
and your layout name is therefore `uk`.

Then type
```shell
make LAYOUT=<name of your layout>
```

In our English UK example, the command would be 
```shell
make LAYOUT=uk
```

<!-- tabs:end -->

Compilation can take quite a while, depending on whether it is the first time you are compiling, and how powerful your 
hardware is.

If compilation succeeds, you will find the firmware file in `Mathpad/firmware/compiled` with the name 
`summacogni_mathpad_mp1a_<layout name>.uf2`. To flash this firmware to your Mathpad, follow the guide in 
[Update Firmware](/update_firmware.md) from Step 2.