#!/usr/bin/env python3
import os

base_path = r"/workspaces/Sector88-Weapon-Crafting/@Sector88_Crafting/addons/Sector88_crafting"

json_files = []
for root, dirs, files in os.walk(base_path):
    for file in files:
        if file.endswith('.json'):
            json_files.append(os.path.join(root, file))

print(f"Found {len(json_files)} JSON files")

replaced_count = 0
files_updated = 0

for json_file in json_files:
    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        count_before = content.count('S88_')
        
        if count_before > 0:
            new_content = content.replace('S88_', 'FW_')
            with open(json_file, 'w', encoding='utf-8') as f:
                f.write(new_content)
            replaced_count += count_before
            files_updated += 1
            print(f"✓ {os.path.basename(json_file)}: {count_before} replacements")
    
    except Exception as e:
        print(f"✗ Error: {json_file}: {e}")

print(f"\n✅ Updated {files_updated} files with {replaced_count} total replacements")

