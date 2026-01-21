#!/usr/bin/env python3
import re

file_path = "@Sector88_Crafting/addons/sector88_weaponparts/config.cpp"

with open(file_path, 'r') as f:
    content = f.read()

# Replace all S88_ base class inheritances with FW_
content = re.sub(r': S88_(\w+)_Base', r': FW_\1_Base', content)

with open(file_path, 'w') as f:
    f.write(content)

print("✅ Replaced all S88_ base class inheritances with FW_")
