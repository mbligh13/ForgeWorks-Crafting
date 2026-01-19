#!/usr/bin/env python3
"""
Script to add 'FW_' prefix to all weapon parts in types.xml, spawnabletypes.xml, and config.cpp
but NOT to workbenches which already have 'FW' prefix.
"""

import re
import os

def add_fw_prefix_to_xml(filepath):
    """Add FW_ prefix to all part type names in XML files."""
    
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Define all the part prefixes that need FW_ added
    part_prefixes = [
        'PistolReceiver_',
        'PistolHandle_',
        'Barrel_',
        'LowerReceiver_',
        'UpperReceiver_',
        'Bolt_',
        'BarrelLiner_',
        'BoltAssembly_',
        'ReceiverBracket_',
        'Spring_Elite'
    ]
    
    # Track changes
    changes_made = 0
    
    for prefix in part_prefixes:
        # Pattern to match type names without FW_ prefix
        pattern = rf'<type name="{prefix}'
        replacement = f'<type name="FW_{prefix}'
        
        # Count matches before replacement
        matches = len(re.findall(pattern, content))
        if matches > 0:
            print(f"  Found {matches} instances of '<type name=\"{prefix}\"' to prefix")
            content = content.replace(pattern, replacement)
            changes_made += matches
    
    # Write back to file
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)
    
    return changes_made

def add_fw_prefix_to_cpp(filepath):
    """Add FW_ prefix to all part class names in config.cpp file."""
    
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Define all the part prefixes that need FW_ added
    part_prefixes = [
        'PistolReceiver_',
        'PistolHandle_',
        'Barrel_',
        'LowerReceiver_',
        'UpperReceiver_',
        'Bolt_',
        'BarrelLiner_',
        'BoltAssembly_',
        'ReceiverBracket_',
        'Spring_Elite'
    ]
    
    # Track changes
    changes_made = 0
    
    for prefix in part_prefixes:
        # Pattern to match class names without FW_ prefix
        pattern = rf'class {prefix}'
        replacement = f'class FW_{prefix}'
        
        # Count matches before replacement
        matches = len(re.findall(pattern, content))
        if matches > 0:
            print(f"  Found {matches} instances of 'class {prefix}' to prefix")
            content = content.replace(pattern, replacement)
            changes_made += matches
    
    # Write back to file
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)
    
    return changes_made

def main():
    """Main execution function."""
    
    # Define files to process
    base_path = '/workspaces/ForgeWorks-Crafting/@ForgeWorks_Crafting'
    
    xml_files = [
        os.path.join(base_path, 'types.xml'),
        os.path.join(base_path, 'spawnabletypes.xml')
    ]
    
    cpp_files = [
        os.path.join(base_path, 'addons/forgeworks_weaponparts/config.cpp')
    ]
    
    print("Adding FW_ prefix to weapon parts in all files...")
    print("=" * 60)
    
    total_changes = 0
    
    # Process XML files
    print("\n=== Processing XML Files ===")
    for filepath in xml_files:
        if os.path.exists(filepath):
            print(f"\nProcessing: {os.path.basename(filepath)}")
            changes = add_fw_prefix_to_xml(filepath)
            total_changes += changes
            print(f"  ✓ Made {changes} changes")
        else:
            print(f"  ✗ File not found: {filepath}")
    
    # Process C++ files
    print("\n=== Processing C++ Files ===")
    for filepath in cpp_files:
        if os.path.exists(filepath):
            print(f"\nProcessing: {os.path.basename(filepath)}")
            changes = add_fw_prefix_to_cpp(filepath)
            total_changes += changes
            print(f"  ✓ Made {changes} changes")
        else:
            print(f"  ✗ File not found: {filepath}")
    
    print("\n" + "=" * 60)
    print(f"Total changes made: {total_changes}")
    print("\nDone! All weapon parts now have FW_ prefix.")

if __name__ == "__main__":
    main()
