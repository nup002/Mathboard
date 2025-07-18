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
    NULL, MOF_AS_IS_1SPACE    // Microsoft Office string and sending method
);
```

4. Add your symbol to the corresponding header file (e.g., `logic_symbols.h`)
5. If creating a new category, add an `#include` for your header file in `symbols.h`

## Symbol Categories

- `greek_symbols.c` - Greek letters (lowercase and uppercase)
- `algebra_symbols.c` - Algebra and calculus symbols
- `set_theory_symbols.c` - Set theory symbols
- `logic_symbols.c` - Logic symbols
- `comparison_symbols.c` - Comparison and equivalence symbols
- `number_system_symbols.c` - Number system symbols
- `modifier_symbols.c` - Modifiers like circumflex, tilde, etc.
- `misc_symbols.c` - Other mathematical and scientific symbols

## Sending Methods

- `LATEX_NORMAL` - Normal LaTeX command
- `LATEX_BACKTRACK_1` - LaTeX command with 1 character backtracking
- `LATEX_BACKTRACK_3` - LaTeX command with 3 characters backtracking
- `MOF_AS_IS_1SPACE` - Microsoft Office string with 1 space
- `MOF_AS_IS_2SPACE` - Microsoft Office string with 2 spaces
- `MOF_MOVE_LEFT_1SPACE` - Microsoft Office string with left movement and one space
- `MOF_MOVE_LEFT_2SPACE` - Microsoft Office string with left movement and two spaces
- `MOF_SPACE_DELETE_PLACEHOLDER_LIMITS` - Microsoft Office string with placeholder limits
