# Repository Cleanup - Files to Move

## Current Issue
Several development files are still in the repository root and should be moved to `Development Tools/` folder.

## Files to Move to Development Tools/

From repository root → Development Tools/:
- `BUILD_INSTRUCTIONS.md`
- `STRUCTURE_CHECKLIST.md`
- `STRUCTURE_SUMMARY.md`
- `TROUBLESHOOTING.md`
- `NAMING_UPDATE.md`
- `build_mod.sh`

## How to Move Files

### Using Terminal:
```bash
cd /workspaces/ForgeWorks-Crafting
mv BUILD_INSTRUCTIONS.md "Development Tools/"
mv STRUCTURE_CHECKLIST.md "Development Tools/"
mv STRUCTURE_SUMMARY.md "Development Tools/"
mv TROUBLESHOOTING.md "Development Tools/"
mv NAMING_UPDATE.md "Development Tools/"
mv build_mod.sh "Development Tools/"
```

### Or using VS Code:
1. Select the files in the Explorer
2. Drag and drop them into the "Development Tools" folder

## Final Structure Should Be:

```
ForgeWorks-Crafting/
├── .git/
├── .gitignore
├── README.md                    ← Root readme with quick links
│
├── Development Tools/           ← ALL development files here
│   ├── DEV_ORGANIZATION.md
│   ├── BUILD_INSTRUCTIONS.md
│   ├── STRUCTURE_CHECKLIST.md
│   ├── STRUCTURE_SUMMARY.md
│   ├── TROUBLESHOOTING.md
│   ├── NAMING_UPDATE.md
│   ├── build_mod.sh
│   ├── README.md
│   ├── REBRAND_COMPLETE.md
│   ├── UPDATE_SUMMARY.md
│   ├── add_fw_prefix_to_parts.py
│   ├── fix_config.py
│   ├── replace_s88.py
│   ├── update_all_crafting_times.py
│   ├── update_json_files.py
│   ├── update_json_s88_to_fw.py
│   └── update_recipe_manager.py
│
└── ForgeWorksCrafting/          ← Distribution mod folder
    ├── mod.cpp
    ├── meta.cpp
    ├── ForgeWorks_Crafting.paa
    ├── ForgeWorks_types.xml
    ├── ForgeWorks_spawnabletypes.xml
    ├── CRAFTING_GUI_README.md
    ├── keys/
    └── addons/
        ├── ForgeWorks_crafting/
        └── forgeworks_weaponparts/
```

## Verification

After moving files, verify:
1. Root directory should only have:
   - `.git/`
   - `.gitignore`
   - `README.md`
   - `Development Tools/` (folder)
   - `ForgeWorksCrafting/` (folder)
   - `_codeql_detected_source_root` (can stay)

2. Everything else should be in `Development Tools/`

## Why This Organization?

- **Clean root:** Only essential files at top level
- **Clear separation:** Development vs. Distribution
- **Easy distribution:** Just package `ForgeWorksCrafting/` folder
- **Version control:** Keep dev tools in git for team
- **Documentation:** All dev docs in one place
