# Mathpad Symbols

This directory contains symbol definitions for the Mathpad firmware, organized by category.

## How to Add Your Own Symbols

To add a new symbol:

1. Identify which category file is most appropriate for your symbol (e.g., `greek_symbols.c`, `logic_symbols.c`, etc.)
2. Open the relevant file
3. Add your symbol definition using the `DEFINE_SYMBOL` macro:

```c
const symbol_definition_t SYMBOL_YOUR_SYMBOL = DEFINE_SYMBOL(
    your_symbol_name,         // Name used in code (lowercase, underscores)
    0x1234,                   // Unicode code point (find at unicode-table.com)
    "\\yourlatex", LATEX_NORMAL,  // LaTeX command and sending method
    NULL, MOF_1SPACE    // Microsoft Office string and sending method
);
```

4. Add your symbol to the corresponding header file (e.g., `logic_symbols.h`)
5. If creating an entirely new category, add an `#include` for your header file in `symbols.h`

### Symbol Categories

- `greek_symbols.c` - Greek letters (lowercase and uppercase)
- `algebra_symbols.c` - Algebra and calculus symbols
- `set_theory_symbols.c` - Set theory symbols
- `logic_symbols.c` - Logic symbols
- `comparison_symbols.c` - Comparison and equivalence symbols
- `number_system_symbols.c` - Number system symbols
- `modifier_symbols.c` - Modifiers like circumflex, tilde, etc.
- `misc_symbols.c` - Other mathematical and scientific symbols

### LaTeX sending methods
 - LATEX_NORMAL,        // Just send the string as is
 - LATEX_1BACKTRACK,    // Send string and move cursor back 1 position
 - LATEX_3BACKTRACK,    // Send string and move cursor back 3 positions
 - LATEX_4BACKTRACK     // Send string and move cursor back 4 positions

### Microsoft Office equation editor sending methods
 - MOF_1SPACE,             // Send string and send 1 space
 - MOF_2SPACE,             // Send string and send 2 spaces
 - MOF_1SPACE_1BACKTRACK,  // Send string, 1 space, and move cursor back 1 position
 - MOF_2SPACE_1BACKTRACK,  // Send string, 2 spaces, and move cursor back 1 position
 - MOF_1SPACE_DELETE_LIMS  // Send string with placeholder limits (_a^b) and delete the limits

## Mapping a new symbol to a key
Open `keymap.c` and add a new keycode to `custom_keycodes` at the top of the file. For example, if you have defined 
a symbol named SYMBOL_HBAR, you should define a keycode named KC_HBAR.

Still in `keymap.c`, scroll down to `get_symbol_for_keycode` and add a new case for your new keycode. For example:
```
case KC_HBAR:
    return &SYMBOL_HBAR;
```
This maps the keycode to the symbol.

Finally, scroll down to the key definitions around line 300 - 320. Add your new keycode to the appropriate key array.