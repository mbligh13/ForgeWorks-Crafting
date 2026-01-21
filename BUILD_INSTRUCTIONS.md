# ForgeWorks Crafting - Build Instructions

## Mod Structure Overview

### Root Directory (Development Only)
These files are for development and should NOT be distributed with the mod:
- `Development Tools/` - Python scripts for development
- `.git/` - Version control
- `BUILD_INSTRUCTIONS.md` - This file
- Any other documentation or development files

### ForgeWorksCrafting Directory (Distribution)
This is your actual mod folder that gets distributed. Structure:

```
ForgeWorksCrafting/
├── mod.cpp                              (Mod metadata - UNPACKED)
├── meta.cpp                             (Mod configuration - UNPACKED)
├── ForgeWorks_Crafting.paa             (Mod icon - UNPACKED)
├── ForgeWorks_types.xml                (Server loot config - UNPACKED)
├── ForgeWorks_spawnabletypes.xml       (Server spawn config - UNPACKED)
├── CRAFTING_GUI_README.md              (Documentation - UNPACKED)
├── keys/
│   └── ForgeWorks.bikey                (Signature key - UNPACKED)
└── addons/
    ├── ForgeWorks_crafting.pbo         (Main crafting system - PACKED)
    └── forgeworks_weaponparts.pbo      (Weapon parts definitions - PACKED)
```

## What Goes In Each PBO

### ForgeWorks_crafting.pbo
Should contain:
- `config.cpp` - Main configuration file (needs to be created)
- `model.cfg` - Model definitions (now correctly placed)
- `config_workbench.cpp` - Workbench definitions (will be merged into config.cpp)
- `scripts/` - All EnforceScript code
- `gui/` - All GUI layouts
- `data/` - Stringtables and other data files
- `_core/` - Recipe system core files (fw_tags.json, recipe_list.json)
- `config/` - Config files like positions.json
- `Guns/`, `Magazines/`, `Breakdown/`, `Upgrades/` - All recipe JSON files

### forgeworks_weaponparts.pbo
Should contain:
- `config.cpp` - Weapon parts item definitions (already exists)
- `data/models/` - 3D models (.p3d files)

## Build Process

### Manual Build (Using DayZ Tools)
1. Open DayZ Tools
2. Use Addon Builder to pack each addon:
   - Source: `ForgeWorksCrafting/addons/ForgeWorks_crafting/`
   - Destination: `ForgeWorksCrafting/addons/ForgeWorks_crafting.pbo`
   - Repeat for `forgeworks_weaponparts`
3. Sign PBOs with your private key

### Automated Build (Script)
Run the build script:
```bash
./build_mod.sh
```

## Installation on Server

1. Copy entire `ForgeWorksCrafting/` folder to server's mods directory
2. Add to server launch parameters: `-mod=ForgeWorksCrafting`
3. Merge `ForgeWorks_types.xml` into server's types.xml
4. Merge `ForgeWorks_spawnabletypes.xml` into server's spawnabletypes.xml
5. Restart server

## Development Workflow

1. Make changes to files in `ForgeWorksCrafting/addons/[addon_name]/`
2. Test changes (unpacked mode if needed)
3. When ready to distribute, build PBOs
4. Distribute only the `ForgeWorksCrafting/` folder

## Files That Should NOT Be Packed

These files must remain in the mod root folder (ForgeWorksCrafting/):
- `mod.cpp` - Required by DayZ to recognize the mod
- `meta.cpp` - Workshop/mod metadata
- `ForgeWorks_Crafting.paa` - Displayed in mod list
- `ForgeWorks_types.xml` - Server admins need access
- `ForgeWorks_spawnabletypes.xml` - Server admins need access
- `keys/*.bikey` - Required for signature verification
