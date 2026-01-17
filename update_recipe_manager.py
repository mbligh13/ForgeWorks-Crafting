#!/usr/bin/env python3
"""
Script to remove SetRequiredAttachments lines from S88RecipeManager.c
Run this from the root of the repository
"""

import re

def main():
    filepath = "@Sector88_Crafting/addons/Sector88_crafting/scripts/4_world/S88RecipeManager.c"
    
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Remove all SetRequiredAttachments lines
        content = re.sub(r'\s*\w+\.SetRequiredAttachments\([^)]+\);?\s*\n', '', content)
        
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"✅ Removed all SetRequiredAttachments lines from {filepath}")
        return True
    except Exception as e:
        print(f"✗ Error: {e}")
        return False

if __name__ == "__main__":
    main()
