# Mathpad Unified Symbol System Guide

## Overview

This guide explains the new unified symbol system for the Mathpad firmware. The system consolidates Unicode, LaTeX, and Microsoft Office Equation Editor (MOF) symbol definitions into self-contained objects, making it easier to add, modify, and maintain symbols across all output modes.

## Key Files

1. **symbol_definitions.h/.c** - Core structure and functions for the unified symbol system
2. **symbols.h/.c** - Actual symbol definitions using the unified structure
3. **symbol_usage_example.c** - Examples of how to use the new system in keymap.c

## Symbol Definition Structure

Each symbol is now defined as a `symbol_definition_t` structure containing:

```c
typedef struct {
    // Symbol metadata
    const char* name;           // Human-readable name of the symbol
    const char* category;       // Category of the symbol (Greek, Logic, etc.)
    bool is_multitap;           // Whether this is a multitap symbol
    
    // Unicode representation
    uint32_t unicode_value;     // Unicode code point
    
    // LaTeX representation
    const char* latex_string;   // LaTeX string representation
    latex_send_method_t latex_method; // How to send the LaTeX string
    
    // Microsoft Office representation
    const char* mof_string;     // Microsoft Office string representation
    mof_send_method_t mof_method; // How to send the MOF string
} symbol_definition_t;
```

## How to Define a Symbol

Use the `DEFINE_SYMBOL` macro to create a symbol definition:

```c
const symbol_definition_t SYMBOL_ALPHA = DEFINE_SYMBOL(
    alpha, "Greek", false,
    0x03B1,                  // Unicode: α
    "\\alpha", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE   // Use Unicode for MOF
);
```

For symbols that use Unicode for MOF mode (common case), you can set `mof_string` to `NULL` and the system will automatically use the Unicode representation.

## How to Use Symbols in Keymap

Replace the old symbol key functions with calls to `handle_symbol_key()`:

```c
// Old way
case KC_A:
    alpha_key(record);
    return false;

// New way
case KC_A:
    handle_symbol_key(&SYMBOL_ALPHA, record);
    return false;
```

## Available Send Methods

### LaTeX Send Methods

- `LATEX_NORMAL` - Send the string as is
- `LATEX_BACKTRACK_1` - Send string and move cursor back 1 position
- `LATEX_BACKTRACK_3` - Send string and move cursor back 3 positions
- `LATEX_BACKTRACK_4` - Send string and move cursor back 4 positions

### MOF Send Methods

- `MOF_AS_IS_1SPACE` - Send string and one space
- `MOF_AS_IS_2SPACE` - Send string and two spaces
- `MOF_MOVE_LEFT_1SPACE` - Send string, one space, and move left
- `MOF_MOVE_LEFT_2SPACE` - Send string, two spaces, and move left
- `MOF_SPACE_DELETE_PLACEHOLDER_LIMITS` - Send string, space, and delete placeholder limits

## Adding New Symbols

To add a new symbol:

1. Define the symbol in `symbols.c` using the `DEFINE_SYMBOL` macro
2. Add an external declaration in `symbols.h`
3. Use the symbol in your keymap with `handle_symbol_key()`

Example:

```c
// In symbols.c
const symbol_definition_t SYMBOL_NEW = DEFINE_SYMBOL(
    new_symbol, "Category", false,
    0x2603,                  // Unicode: ☃
    "\\newsymbol", LATEX_NORMAL,
    NULL, MOF_AS_IS_1SPACE
);

// In symbols.h
extern const symbol_definition_t SYMBOL_NEW;

// In keymap.c
case KC_X:
    handle_symbol_key(&SYMBOL_NEW, record);
    return false;
```

## Handling Multitap Symbols

For multitap symbols, set the `is_multitap` flag to `true` and use the symbol in your tap dance functions:

```c
void tap_dance_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        handle_symbol_key(&SYMBOL_ALPHA, NULL);
    } else if (state->count == 2) {
        handle_symbol_key(&SYMBOL_BETA, NULL);
    }
}
```

## Migration Path

To migrate from the old system:

1. Define all your symbols using the new unified structure
2. Replace direct calls to `send_unicode_on_keypress()`, `send_latex_on_keypress()`, and `send_mof_on_keypress()` with `handle_symbol_key()`
3. Remove the old symbol-specific key functions

## Benefits

- All symbol information is in one place
- Easier to add new symbols
- Easier to modify existing symbols
- More maintainable code
- Cleaner keymap.c file
