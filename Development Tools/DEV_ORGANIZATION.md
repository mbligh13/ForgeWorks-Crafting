# Development Tools Organization

## Purpose
This folder contains ALL development-related files, scripts, and documentation that are NOT needed for the mod's distribution or runtime operation.

## Current Structure

### Python Scripts (Automation Tools)
- `add_fw_prefix_to_parts.py` - Adds FW prefix to part definitions
- `fix_config.py` - Configuration file fixes
- `replace_s88.py` - Replaces S88 references with FW
- `update_all_crafting_times.py` - Batch update crafting times
- `update_json_files.py` - JSON file updates
- `update_json_s88_to_fw.py` - S88 to FW migration for JSON
- `update_recipe_manager.py` - Recipe manager updates

### Documentation (Historical/Development)
- `README.md` - Development documentation
- `REBRAND_COMPLETE.md` - Rebranding completion notes
- `UPDATE_SUMMARY.md` - Update history

### Build & Structure Documentation
Located in root (to be moved here):
- `BUILD_INSTRUCTIONS.md` - How to build PBOs
- `STRUCTURE_CHECKLIST.md` - Mod structure validation
- `STRUCTURE_SUMMARY.md` - Current structure overview
- `TROUBLESHOOTING.md` - Common issues and fixes
- `NAMING_UPDATE.md` - Naming consistency documentation
- `build_mod.sh` - Automated build script

## What Goes Here

### ✅ Should Be In Development Tools:
- Python scripts for automation
- Build scripts and tools
- Development documentation
- Testing utilities
- Migration/update scripts
- Historical notes and changelogs
- Structure validation tools
- Any files used during development but not needed by end users

### ❌ Should NOT Be In Development Tools:
- Mod runtime files (config.cpp, scripts, etc.)
- Server configuration files (types.xml, spawnabletypes.xml)
- Mod metadata (mod.cpp, meta.cpp)
- User-facing documentation
- Models, textures, or other assets
- Anything required for the mod to function

## Usage Guidelines

### For Development Work:
1. All new development tools should be added to this folder
2. Document scripts with comments explaining their purpose
3. Keep historical documentation for reference
4. Don't commit temporary test files

### For Distribution:
1. **NEVER distribute this folder with the mod**
2. This folder should be excluded from:
   - PBO builds
   - Workshop uploads
   - Server packages
   - Client downloads
3. Keep this folder in version control for team development

### File Organization:
```
Development Tools/
├── scripts/              (Python automation scripts)
│   ├── *.py
├── docs/                 (Development documentation)
│   ├── *.md
├── tools/                (Build and utility tools)
│   ├── build_mod.sh
└── archive/              (Old/deprecated tools)
    └── (historical files)
```

## Recommended .gitignore
Add to root .gitignore:
```
# But do NOT ignore Development Tools folder itself
# It should be in version control for the team

# Do ignore temporary files in Development Tools
Development Tools/__pycache__/
Development Tools/*.pyc
Development Tools/temp/
Development Tools/test_output/
```

## Quick Reference

### Building the Mod:
See: `BUILD_INSTRUCTIONS.md` (should be in this folder)

### Troubleshooting:
See: `TROUBLESHOOTING.md` (should be in this folder)

### Structure Validation:
See: `STRUCTURE_CHECKLIST.md` (should be in this folder)

### Automation Scripts:
Run Python scripts from workspace root:
```bash
python "Development Tools/script_name.py"
```

## Future Tools to Add

Consider adding:
- Automated testing scripts
- Config validation tools
- Recipe balance calculators
- Workshop publishing scripts
- Server deployment automation
- Documentation generators

---

**Note:** If you're preparing a distribution package, make sure to exclude this entire folder!
