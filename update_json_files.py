#!/usr/bin/env python3
"""
Script to remove 'Workbench': 'ExpansionWorkbench' lines from all JSON recipe files
Run this from the root of the repository
"""

import os
import json
import re

def process_json_file(filepath):
    """Remove Workbench line from JSON file"""
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Remove the Workbench line (handles various whitespace patterns)
        content = re.sub(r'\s*"Workbench":\s*"[^"]+",?\s*\n', '', content)
        
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"✓ Updated: {filepath}")
        return True
    except Exception as e:
        print(f"✗ Error processing {filepath}: {e}")
        return False

def main():
    base_path = "@Sector88_Crafting/addons/Sector88_crafting"
    
    # Find all JSON files except in _core directory
    updated_count = 0
    for root, dirs, files in os.walk(base_path):
        # Skip _core directory
        if '_core' in root:
            continue
            
        for file in files:
            if file.endswith('.json'):
                filepath = os.path.join(root, file)
                if process_json_file(filepath):
                    updated_count += 1
    
    print(f"\n✅ Updated {updated_count} JSON files")

if __name__ == "__main__":
    main()
