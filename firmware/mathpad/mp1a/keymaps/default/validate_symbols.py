#!/usr/bin/env python3
"""
Mathpad Symbol Validation Tool

This script helps users validate their symbol definitions and keymap assignments
before compiling the firmware. It checks for common errors and provides helpful
feedback for non-technical users.

Usage: python validate_symbols.py
"""

import os
import re
import sys
from pathlib import Path

class SymbolValidator:
    def __init__(self):
        self.errors = []
        self.warnings = []
        self.symbols_found = {}
        self.keycodes_found = set()
        self.keymap_assignments = {}
        self.multitap_symbols = set()
        self.all_used_symbols = set()
        
    def validate_all(self):
        """Run all validation checks"""
        print("🔍 Validating Mathpad symbol definitions...")
        print()
        
        self.check_symbol_files()
        self.check_keymap_consistency()
        self.check_multitap_usage()
        self.check_unicode_validity()
        
        self.print_results()
        return len(self.errors) == 0
    
    def check_symbol_files(self):
        """Check symbol definition files for common issues"""
        symbols_dir = Path("symbols")
        if not symbols_dir.exists():
            self.errors.append("❌ symbols/ directory not found")
            return
            
        symbol_files = list(symbols_dir.glob("*_symbols.c"))
        if not symbol_files:
            self.errors.append("❌ No symbol files found in symbols/ directory")
            return
            
        for file_path in symbol_files:
            self.check_symbol_file(file_path)
    
    def check_symbol_file(self, file_path):
        """Check individual symbol file"""
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # Remove comments to simplify parsing
            content_no_comments = re.sub(r'//.*?$', '', content, flags=re.MULTILINE)
            
            # Find all DEFINE_SYMBOL definitions - more flexible pattern
            # Matches: const symbol_definition_t SYMBOL_NAME = DEFINE_SYMBOL(
            pattern = r'const\s+symbol_definition_t\s+(SYMBOL_\w+)\s*=\s*DEFINE_SYMBOL\s*\(([^)]+)\)'
            matches = re.findall(pattern, content_no_comments, re.MULTILINE | re.DOTALL)
            
            for symbol_name, params in matches:
                # Parse the parameters inside DEFINE_SYMBOL
                # Split by comma and clean up whitespace
                param_parts = [p.strip() for p in params.split(',')]
                
                if len(param_parts) >= 6:
                    internal_name = param_parts[0]
                    unicode_hex = param_parts[1].replace('0x', '')
                    latex_cmd = param_parts[2].strip('"')
                    latex_method = param_parts[3]
                    office_cmd = param_parts[4]
                    office_method = param_parts[5]
                    
                    # Store symbol info
                    self.symbols_found[symbol_name] = {
                        'file': file_path.name,
                        'unicode': unicode_hex,
                        'latex': latex_cmd.strip(),
                        'internal': internal_name
                    }
                    
                    # Validate Unicode code point
                    try:
                        unicode_int = int(unicode_hex, 16)
                        if unicode_int < 0x20 or unicode_int > 0x10FFFF:
                            self.errors.append(f"❌ {symbol_name}: Invalid Unicode range 0x{unicode_hex}")
                    except ValueError:
                        self.errors.append(f"❌ {symbol_name}: Invalid Unicode format 0x{unicode_hex}")
                
                
        except Exception as e:
            self.errors.append(f"❌ Error reading {file_path}: {e}")
    
    def check_keymap_consistency(self):
        """Check keymap.c for consistency with symbol definitions"""
        keymap_file = Path("keymap.c")
        if not keymap_file.exists():
            self.errors.append("❌ keymap.c not found")
            return
            
        try:
            with open(keymap_file, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # Find custom keycodes
            keycode_pattern = r'KC_(\w+),'
            keycodes = re.findall(keycode_pattern, content)
            self.keycodes_found = set(f"KC_{kc}" for kc in keycodes)
            
            # Find symbol mappings in get_symbol_for_keycode
            mapping_pattern = r'case\s+(KC_\w+):\s*return\s+&(SYMBOL_\w+);'
            mappings = re.findall(mapping_pattern, content)
            
            for keycode, symbol in mappings:
                if symbol not in self.symbols_found:
                    self.errors.append(f"❌ {keycode} maps to undefined symbol {symbol}")
                else:
                    self.keymap_assignments[keycode] = symbol
                    self.all_used_symbols.add(symbol)
                
        except Exception as e:
            self.errors.append(f"❌ Error reading keymap.c: {e}")
    
    def check_multitap_usage(self):
        """Check multitap.c for symbols used in multitap functions"""
        multitap_file = Path("multitap.c")
        if not multitap_file.exists():
            self.warnings.append("⚠️  multitap.c not found - skipping multitap symbol check")
            return
            
        try:
            with open(multitap_file, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # Find symbol references in multitap functions
            # Look for patterns like: &SYMBOL_NAME
            symbol_pattern = r'&(SYMBOL_\w+)'
            multitap_symbols = set(re.findall(symbol_pattern, content))
            
            # Store multitap symbols for later use
            self.multitap_symbols = multitap_symbols
            
            # Mark these symbols as used
            for symbol in multitap_symbols:
                if symbol in self.symbols_found:
                    # Mark this symbol as used in multitap
                    self.all_used_symbols.add(symbol)
                else:
                    self.errors.append(f"❌ multitap references undefined symbol {symbol}")
                    
        except Exception as e:
            self.errors.append(f"❌ Error reading multitap.c: {e}")
    
    def check_unicode_validity(self):
        """Check if Unicode characters are valid and renderable"""
        for symbol_name, info in self.symbols_found.items():
            try:
                unicode_int = int(info['unicode'], 16)
                char = chr(unicode_int)
                
                # Check if it's a printable character
                if not char.isprintable() and unicode_int > 0x1F:
                    self.warnings.append(f"⚠️  {symbol_name}: Unicode U+{info['unicode']} may not be printable")
                    
            except (ValueError, OverflowError):
                # Already caught in check_symbol_file
                pass
    
    def print_results(self):
        """Print validation results"""
        # Check for unmapped symbols before printing results
        unmapped = set(self.symbols_found.keys()) - self.all_used_symbols
        for symbol in unmapped:
            loc = self.symbols_found[symbol]['file']
            self.warnings.append(f"⚠️  Symbol {symbol} is defined in '{loc}' but not mapped to any key")
        
        print(f"📊 Validation Results:")
        print(f"   • Found {len(self.symbols_found)} symbol definitions")
        print(f"   • Found {len(self.keycodes_found)} keycodes")
        print(f"   • Found {len(self.keymap_assignments)} keycode-to-symbol mappings")
        print(f"   • Found {len(self.multitap_symbols)} symbols used in multitap")
        print(f"   • Total symbols in use: {len(self.all_used_symbols)}")
        print()
        
        if self.errors:
            print("❌ ERRORS (must fix before compiling):")
            for error in self.errors:
                print(f"   {error}")
            print()
        
        if self.warnings:
            print("⚠️  WARNINGS (should review):")
            for warning in self.warnings:
                print(f"   {warning}")
            print()
        
        if not self.errors and not self.warnings:
            print("✅ All checks passed! Your symbol definitions look good.")
        elif not self.errors:
            print("✅ No critical errors found. Review warnings above.")
        else:
            print("❌ Please fix the errors above before compiling.")
            print()
            print("💡 Common fixes:")
            print("   • Check symbol names match between .c and .h files")
            print("   • Verify Unicode code points are valid hex (0x1234)")
            print("   • Add missing keycode mappings in get_symbol_for_keycode()")

def main():
    """Main entry point"""
    # Change to the directory containing this script
    script_dir = Path(__file__).parent
    os.chdir(script_dir)
    
    validator = SymbolValidator()
    success = validator.validate_all()
    
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
