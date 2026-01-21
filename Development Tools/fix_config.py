import re
import sys

file_path = sys.argv[1] if len(sys.argv) > 1 else "@Sector88_Crafting/addons/sector88_weaponparts/config.cpp"

with open(file_path, 'r', encoding='utf-8') as f:
    content = f.read()

# Count before
before_count = content.count(': S88_')

# Replace all S88_ base class inheritances with FW_
content = re.sub(r': S88_(\w+)_Base', r': FW_\1_Base', content)

# Count after
after_count = content.count(': S88_')

with open(file_path, 'w', encoding='utf-8') as f:
    f.write(content)

print(f"✅ Replaced {before_count - after_count} S88_ base class inheritances with FW_")
print(f"Remaining S88_ inheritances: {after_count}")
