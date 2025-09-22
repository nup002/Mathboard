# Firmware
This page documents the Mathpad firmware. It is organized in three sections:
1) Overview
2) Making modifications
3) Troubleshooting

## Overview
Mathpad's firmware is built on the [QMK](https://qmk.fm) input device library and written in the programming language C. 

**Don't worry if you're new to this!** Previous experience with QMK or C is not required to make modifications to the Mathpad firmware. This guide will walk you through everything step-by-step.

Since Mathpad is based on QMK, you can easily develop and compile the firmware on nearly all platforms, including Windows.

### What You'll Be Working With
Mathpad's firmware is found in [/firmware/mathpad/mp1a/keymaps/default](https://github.com/Summa-Cogni/Mathpad/tree/Main/firmware/mathpad/mp1a/keymaps/default). There are some additional files in the folders above this one, but it is unlikely you will need to ever modify them. We therefore focus our attention on the `keymaps/default` folder.

Within this folder there are (among others) the following files:
- `globals.h` : Global variables
- `info.c` and `info.h` : Code related to Mathpad information (build date, version number, etc)
- `keymap.c`: Defines which symbols are where on the Mathpad
- `mode.c`  : Functions related to mode-switching
- `modifiers.c` and `modifiers.h` : Functions related to the modifier keys
- `os_switch.c` : Functions related to the OS switch
- `multitap.c` and `multitap.h` : Multitap symbol definitions
- `normal_symbols_defs.c` : Logic definitions for all 'normal' (non-multitap) symbols
- `multitap_symbols_defs.c` : Logic definitions for all multitap symbols
- `os_switch.c` and `os_switch.h` : Functions related to the OS switch
- `rules.mk` : QMK configuration options

There are two subfolders:
- `modes` : Code related to the different Mathpad modes: LaTeX, Unicode, Microsoft Office, etc.
- `symbols` : Symbol definitions

**⚠️ Important:** Only modify files in the `keymaps/default` folder and its subfolders. Modifying other files could break your Mathpad's functionality.


## Making Modifications

> >[!TIP|label:Before You Continue]
> Make sure you have followed the instructions in [Firmware Prerequisites](/firmware_prerequisites.md) before 
> trying to make any changes to the Mathpad firmware.
>

This section covers the most common modifications you might want to make to your Mathpad. We'll start with simple changes and work up to more complex ones.

### Before Making Changes
1. **Test your current setup:** Make sure you can compile the existing firmware before making changes
2. **Make one change at a time:** Don't modify multiple things at once
3. **Keep notes:** Write down what you're changing so you can undo it if needed

### Testing Your Changes

Before compiling the final firmware:

1. **Check your syntax:** Make sure all brackets, commas, and semicolons are in place
2. **Verify names match:** Ensure your symbol names, key codes, and function names are consistent
3. **Start with small changes:** Test one modification at a time

### Modification 1: Replacing an Existing Symbol

This is the most common modification - swapping out a symbol you don't use for one you do.

**What this involves:** You'll define how your new symbol works in different modes (Unicode, LaTeX, etc.), assign it a code name, and place it on a key.

>[!TIP]
> This guide is also available as a [video tutorial](https://www.youtube.com/watch?v=fMBz1kDZXYk)

#### Step 1: Define Your New Symbol

1. **Navigate to the symbols folder:** Open `keymaps/default/symbols/` in your file browser

2. **Choose where to add your symbol:** Open any of the files ending with `_symbols.c` (like `logic_symbols.c`). These files group related symbols together.

3. **Add your symbol definition:** Copy one of the existing symbol definitions and modify it. Here's the structure:

```clike
const symbol_definition_t SYMBOL_<NAME> = DEFINE_SYMBOL(
    "<display_name>",                                       // Human-readable name
    0x<unicode_code>,                                       // Unicode code point (with 0x prefix)
    "<latex_command>", <latex_behavior>,                    // LaTeX definition
    "<office_command>", <office_behavior>,                  // Microsoft Office definition (or NULL)
    "<libreoffice_command>", <libreoffice_behavior>         // LibreOffice definition
);
```

**Example:** Let's add the Aleph symbol (ℵ):
```clike
const symbol_definition_t SYMBOL_ALEPH = DEFINE_SYMBOL(
    "aleph",  
    0x2135,                     // Unicode code point for ℵ
    "\\aleph", LATEX_1SPACE,    // In LaTeX, type \aleph then add a space
    NULL, MOF_1SPACE,           // In MS Office, just use the Unicode symbol
    "aleph", LOF_1SPACE         // In LibreOffice, type the word "aleph" then space
);
```

**Understanding behavior codes:** These tell Mathpad what to do after typing the symbol:
- `<MODE>_1SPACE`: Add one space after the symbol
- `<MODE>_1BACKTRACK`: Move cursor back one position (useful for symbols with brackets)

All available behavior codes are documented in `keymaps/default/symbols/symbols.h`.

#### Step 2: Create a Key Code for Your Symbol

1. **Open the keymap file:** Open `keymaps/default/keymap.c` in your text editor

2. **Find the key codes section:** Look for `enum custom_keycodes` around line 34

3. **Add your key code:** Add a new line before the closing bracket. Use a descriptive name:
```clike
enum custom_keycodes {
    KC_SWITCH_MODE = SAFE_RANGE, 
    KC_RIGHTKEY,                 
    KC_CENTERKEY,                
    // ... existing key codes ...
    KC_REALS,
    KC_COMPLEXES,
    KC_ALEPH        // Your new key code (add comma to previous line!)
};
```

4. **Connect your key code to your symbol:** Find the function `get_symbol_for_keycode` (around line 107) and add your mapping:

```clike
static const symbol_definition_t* get_symbol_for_keycode(uint16_t keycode) {
    switch (keycode) {
        // ... existing mappings ...
        case KC_COMPLEXES:
            return &SYMBOL_COMPLEXES;
        case KC_ALEPH:                    // Your key code
            return &SYMBOL_ALEPH;         // Your symbol (note the & symbol!)
            
        default:
            return NULL;
    }
}
```

#### Step 3: Place Your Symbol on a Physical Key

1. **Understand the key layout:** Each physical key on your Mathpad can hold up to 6 symbols (arranged in a 2x3 grid on each key). Here's how they're positioned:

```
Physical Mathpad Layout (4x3 grid):              Key layout (6 positions):
    ┌─────┬─────┬─────┬─────┐                  ┌─────────────┐─────────────┐                   
    │key00│key01│key02│key03│                  │   top_left  │  top_right  │     
    ├─────┼─────┼─────┼─────┤                  │─────────────│─────────────│        
    │key10│key11│key12│key13│                  │ center_left │ center_right│         
    ├─────┼─────┼─────┼─────┤                  │─────────────│─────────────│       
    │key20│key21│key22│key23│                  │ bottom_left │ bottom_right│        
    └─────┴─────┴─────┴─────┘                  └─────────────┘─────────────┘        
```

2. **Find your target key:** In `keymap.c`, scroll down to around line 330. You'll see key definitions like `key13`, `key22`, etc.

3. **Replace an existing symbol:** Choose which position on which key you want to use. For example, to put Aleph in the bottom-left position of key13:

```clike
static const key_layout_t key13 = {
    .top_left = TD(PI_TD),
    .center_left = KC_PARTIALDERIVATIVE,
    .bottom_left = KC_ALEPH,            // Your new symbol here!
    .top_right = KC_RHO,
    .center_right = KC_NABLA,
    .bottom_right = TD(EMPTY_SET_TD)
};
```

**That's it!** To test your modifications, head over to the [Compilation Guide](/compile.md) and follow the instructions 
to compile the code into a firmware file. Once successful, follow the [Firmware Update Guide](/update_firmware.md) to 
flash your Mathpad with your new firmware.

### Modification 2: Making a Symbol Multitap-Enabled

Multitapping (called "Tap Dance" in QMK) lets you get different symbols by tapping the same key multiple times. For example, tap once for ∞, tap twice for ℵ.

**What this involves:** You'll create a multitap behavior that cycles through multiple symbols, then replace the original symbol with your multitap version.

#### Step 1: Define Your Additional Symbol

First, follow Step 1 from "Replacing an Existing Symbol" to create any new symbols you want to add to the multitap sequence.

#### Step 2: Create a Multitap Definition

1. **Open the multitap file:** Open `keymaps/default/multitap.c`

2. **Add your multitap function:** Copy an existing multitap function and modify it:

```clike
void <name>_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&<SYMBOL_1>, &<SYMBOL_2>, &<SYMBOL_N>};
    symbol_dance(s, d, symbols, <number_of_symbols>);
}
```

**Example:** To make infinity (∞) multitap to aleph (ℵ):
```clike
void infinity_dance(tap_dance_state_t *s, void *d) {
    const symbol_definition_t *symbols[] = {&SYMBOL_INFINITY, &SYMBOL_ALEPH};
    symbol_dance(s, d, symbols, 2);  // 2 symbols total
}
```


3. **Declare your function:** Open `keymaps/default/multitap.h` and add your function declaration:

```clike
// ... existing declarations ...
void times_dance(tap_dance_state_t *s, void *d);
void plusminus_dance(tap_dance_state_t *s, void *d);
void infinity_dance(tap_dance_state_t *s, void *d);  // Your new function

#endif // MULTITAP_H
```

#### Step 3: Create a Multitap Key Code

1. **Back in keymap.c:** Find the `enum tap_dance_keys` section (around line 217)

2. **Add your multitap key code:**

```clike
enum tap_dance_keys {
    // ... existing codes ...
    TIMES_TD,                  
    PLUSMINUS_TD,              
    INFINITY_TD        // Your new multitap key code
};
```

3. **Connect the key code to your function:** Find the `tap_dance_actions` array (around line 275) and add your mapping:

```clike
tap_dance_action_t tap_dance_actions[] = {
    // ... existing mappings ...
    [TIMES_TD] = ACTION_TAP_DANCE_FN (times_dance),
    [PLUSMINUS_TD] = ACTION_TAP_DANCE_FN (plusminus_dance),
    [INFINITY_TD] = ACTION_TAP_DANCE_FN (infinity_dance)  // Your mapping
};
```

#### Step 4: Replace the Original Symbol

1. **Find the original symbol:** Look through the key definitions to find where your original symbol (like `KC_INFINITY`) is placed

2. **Replace with multitap version:** Change `KC_INFINITY` to `TD(INFINITY_TD)`:

```clike
static const key_layout_t key22 = {
    .top_left = KC_CHI,
    .center_left = TD(DOWN_TACK_TD),
    .bottom_left = TD(INFINITY_TD),     // Changed from KC_INFINITY
    .top_right = TD(PSI_TD),
    .center_right = TD(DOUBLE_ARROW_TD),
    .bottom_right = KC_FRACTION
};
```

**How it works:** Now when you tap that key once, you get ∞. Tap twice quickly, and you get ℵ.

**That's it!** To test your modifications, head over to the [Compilation Guide](/compile.md) and follow the instructions 
to compile the code into a firmware file. Once successful, follow the [Firmware Update Guide](/update_firmware.md) to 
flash your Mathpad with your new firmware.


## Getting Help
1. **Double-check this guide:** Re-read the relevant sections carefully
2. **Check the QMK documentation:** Many issues are covered in [QMK docs](https://docs.qmk.fm/)
3. **Ask for help:** Join the [Mathpad forum](https://www.summacogni.com/forum/) or 
 [QMK Discord](https://discord.gg/qmk) with specific details about your problem.

### Recovery

If your Mathpad stops working after flashing new firmware:

1. **Don't panic!** This is usually fixable
2. **Try reflashing:** Flash a known-good firmware file

Remember: Making mistakes is part of learning! Every experienced firmware modifier has broken things while learning. 
The key is making small changes and testing frequently.