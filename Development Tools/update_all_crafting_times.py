#!/usr/bin/env python3
"""
Update all crafting times in JSON files
New scale: 30 seconds (minimum) to 300 seconds (5 minutes) for highest tier
"""

import os
import re

def process_json_file(filepath):
    """Update crafting time in JSON file"""
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Extract current crafting time
        match = re.search(r'"CraftingTime":\s*(\d+)', content)
        if not match:
            return False
        
        old_time = int(match.group(1))
        filepath_lower = filepath.lower()
        
        # Determine new time based on file type and old time
        if 'pistol' in filepath_lower or ('22' in filepath_lower and 'pistol' in filepath_lower):
            if 'break' in filepath_lower:
                new_time = 15 if old_time <= 3 else 20
            else:
                new_time = 30 if old_time <= 3 else 35 if old_time == 4 else 40
        elif '380' in filepath_lower and 'gun' in filepath_lower:
            new_time = 30 if 'craft' in filepath_lower else 15
        elif '762x25' in filepath_lower and 'gun' in filepath_lower and 'smg' not in filepath_lower:
            new_time = 35 if 'craft' in filepath_lower else 20
        elif 'smg' in filepath_lower or ('762x25' in filepath_lower and 'smg' in filepath_lower):
            new_time = 60 if 'craft' in filepath_lower else 30
        elif '556' in filepath_lower or '545' in filepath_lower or '762x39' in filepath_lower:
            new_time = 90 if 'craft' in filepath_lower else 45
        elif '300blk' in filepath_lower or '939' in filepath_lower:
            new_time = 100 if 'craft' in filepath_lower else 50
        elif '308' in filepath_lower or '762x54' in filepath_lower:
            new_time = 150 if 'craft' in filepath_lower else 75
        elif '300wm' in filepath_lower:
            new_time = 180 if 'craft' in filepath_lower else 90
        elif '338' in filepath_lower:
            new_time = 210 if 'craft' in filepath_lower else 105
        elif '408' in filepath_lower:
            new_time = 240 if 'craft' in filepath_lower else 120
        elif '50bmg' in filepath_lower:
            new_time = 300 if 'craft' in filepath_lower else 150
        elif '12ga' in filepath_lower or 'shotgun' in filepath_lower:
            new_time = 75 if 'craft' in filepath_lower else 40
        elif '22' in filepath_lower and 'rifle' in filepath_lower:
            new_time = 75 if 'craft' in filepath_lower else 40
        elif 'magazine' in filepath_lower:
            if 'lmg' in filepath_lower:
                new_time = 150 if 'craft' in filepath_lower else 75
            elif 'drum' in filepath_lower:
                new_time = 120 if 'craft' in filepath_lower else 60
            elif 'highcap' in filepath_lower or 'extended' in filepath_lower:
                new_time = 75 if 'craft' in filepath_lower else 40
            elif '45' in filepath_lower and 'pistol' in filepath_lower:
                new_time = 45 if 'craft' in filepath_lower else 25
            elif 'large' in filepath_lower:
                new_time = 60 if 'craft' in filepath_lower else 30
            else:
                new_time = 40 if 'craft' in filepath_lower else 20
        elif 'upgrade' in filepath_lower or 'barrel_liner' in filepath_lower or 'precision' in filepath_lower:
            if 'barrel_liner' in filepath_lower or 'precision_bolt' in filepath_lower:
                new_time = 300 if 'craft' in filepath_lower else 150
            elif 'receiver' in filepath_lower:
                new_time = 270 if 'craft' in filepath_lower else 135
            else:
                new_time = 240 if 'craft' in filepath_lower else 120
        else:
            # Default multiplier
            new_time = old_time * 10
        
        # Replace the crafting time
        new_content = re.sub(
            r'"CraftingTime":\s*\d+',
            f'"CraftingTime": {new_time}',
            content
        )
        
        if new_content != content:
            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(new_content)
            print(f"✓ {os.path.basename(filepath)}: {old_time}s → {new_time}s")
            return True
        
    except Exception as e:
        print(f"✗ Error: {filepath}: {e}")
        return False
    
    return False

def main():
    base_path = "@Sector88_Crafting/addons/Sector88_crafting"
    
    updated_count = 0
    for root, dirs, files in os.walk(base_path):
        if '_core' in root:
            continue
            
        for file in files:
            if file.endswith('.json'):
                filepath = os.path.join(root, file)
                if process_json_file(filepath):
                    updated_count += 1
    
    print(f"\n✅ Updated {updated_count} JSON recipe files")
    print("\n📊 New Crafting Time Scale:")
    print("  Pistols (.22, 9mm, .380, .45, 7.62x25): 30-40 seconds")
    print("  SMGs: 60 seconds")
    print("  Rifles (5.56, 5.45, 7.62x39): 90 seconds")
    print("  Rifles (.300 BLK, 9x39): 100 seconds")
    print("  DMR (.308, 7.62x54R): 150 seconds")
    print("  Heavy Sniper (.300 WM): 180 seconds (3 minutes)")
    print("  Elite Sniper (.338): 210 seconds (3.5 minutes)")
    print("  Ultra Sniper (.408): 240 seconds (4 minutes)")
    print("  Anti-Materiel (.50 BMG): 300 seconds (5 minutes)")
    print("  Shotguns (12ga): 75 seconds")
    print("  Magazines: 40-150 seconds")
    print("  Upgrades: 240-300 seconds (4-5 minutes)")
    print("\n  Breakdown times are 50% of crafting times")

if __name__ == "__main__":
    main()
