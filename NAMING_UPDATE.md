# ForgeWorksCrafting - Naming Consistency Update

## Changes Made

### ✅ Updated All Naming to "ForgeWorksCrafting" (No Spaces or Dashes)

All references to "ForgeWorks - Crafting" have been changed to "ForgeWorksCrafting" throughout the mod.

### Files Updated:

#### 1. Core Mod Files
- **mod.cpp** - Changed `name = "ForgeWorks - Crafting"` → `name = "ForgeWorksCrafting"`
- **meta.cpp** - Changed `name = "ForgeWorks - Crafting"` → `name = "ForgeWorksCrafting"`

#### 2. Material Files (.rvmat) - 24 Texture Path Updates
All texture paths in .rvmat files changed from:
```
"ForgeWorks - Crafting\addons\..."
```
to:
```
"ForgeWorksCrafting\addons\..."
```

**Updated Files:**
- pistol_reciever.rvmat (2 paths)
- pistol_handle.rvmat (2 paths)
- Lower_Receiver.rvmat (2 paths)
- Upper_Receiver.rvmat (2 paths)
- small_spring.rvmat (2 paths)
- large_spring.rvmat (2 paths)
- barrel.rvmat (2 paths)
- bolt.rvmat (2 paths)
- small_sheet_metal.rvmat (2 paths)
- work_bench.rvmat (2 paths)
- workbench_parts/Digital Caliper.rvmat (2 paths)
- workbench_parts/blueprint.rvmat (2 paths)
- workbench_parts/vice.rvmat (2 paths)
- workbench_parts/workbench_frame.rvmat (2 paths)
- workbench_parts/bolts.rvmat (2 paths)
- workbench_parts/top.rvmat (2 paths)
- workbench_parts/back splash.rvmat (2 paths)

## Mod Configuration Explained

### Directory Structure in mod.cpp

```cpp
class CfgMods
{
    class ForgeWorksCrafting
    {
        dir = "ForgeWorksCrafting";  // ← Mod root folder name
        
        class defs
        {
            class gameScriptModule
            {
                // Path is RELATIVE to the mod root
                files[] = { "ForgeWorksCrafting/addons/ForgeWorks_crafting/scripts/3_game" };
            };
            // ... same for worldScriptModule and missionScriptModule
        };
    };
};
```

### How It Works:

1. **`dir = "ForgeWorksCrafting"`** 
   - This is the name of your mod's root folder
   - DayZ looks for this folder in the server's `-mod=` parameter

2. **Script Paths**
   - Must include the FULL path from the mod root
   - Format: `"ModFolderName/addons/AddonName/scripts/X_game"`
   - Your paths are CORRECT: `"ForgeWorksCrafting/addons/ForgeWorks_crafting/scripts/3_game"`

3. **Why the Full Path?**
   - DayZ needs to know where scripts are located starting from the mod folder
   - When server starts with `-mod=ForgeWorksCrafting`, it uses these paths to load scripts
   - The paths are relative to the server's root directory

## Verification

### ✅ All naming is now consistent:
- **Mod folder:** `ForgeWorksCrafting`
- **Display name:** `ForgeWorksCrafting`
- **Workshop name:** `ForgeWorksCrafting`
- **All texture paths:** `ForgeWorksCrafting\...`
- **All script paths:** `ForgeWorksCrafting/addons/...`

### ✅ No spaces or dashes anywhere:
- Publisher requirement met
- All file paths updated
- All references consistent

## File Structure Reference

```
ForgeWorksCrafting/                          ← Mod root (dir = "ForgeWorksCrafting")
├── mod.cpp                                  ← Defines script paths
├── meta.cpp                                 ← Workshop metadata
├── ForgeWorks_Crafting.paa                 ← Icon (can keep underscore)
└── addons/
    └── ForgeWorks_crafting/                ← Addon folder
        └── scripts/
            ├── 3_game/                      ← Referenced in mod.cpp
            ├── 4_world/                     ← Referenced in mod.cpp
            └── 5_mission/                   ← Referenced in mod.cpp
```

## Server Launch

The server should be launched with:
```
-mod=ForgeWorksCrafting
```

This tells DayZ to:
1. Look for folder named `ForgeWorksCrafting`
2. Read `mod.cpp` from that folder
3. Load scripts from paths defined in `mod.cpp`
4. Load PBOs from `ForgeWorksCrafting/addons/`

## Important Notes

- **Spaces in folder names** can cause issues on some systems
- **Dashes in mod names** may cause workshop publishing problems
- **Underscores are fine** for sub-files (like `ForgeWorks_Crafting.paa`)
- **Main mod folder should have no spaces or special characters**

## Testing Checklist

After these changes, verify:
- [ ] Mod loads without errors
- [ ] Scripts initialize properly
- [ ] Textures display correctly on models
- [ ] No "file not found" errors in logs
- [ ] Workshop publishing works

All naming is now consistent with publisher requirements!
