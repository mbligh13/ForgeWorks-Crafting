# ForgeWorksCrafting Development

## Quick Links

- **Build Instructions:** `Development Tools/BUILD_INSTRUCTIONS.md`
- **Troubleshooting:** `Development Tools/TROUBLESHOOTING.md`
- **Structure Guide:** `Development Tools/STRUCTURE_SUMMARY.md`
- **Development Tools:** See `Development Tools/DEV_ORGANIZATION.md`

## Repository Structure

```
ForgeWorks-Crafting/
├── Development Tools/          ← All development scripts, docs, and tools
│   ├── *.py                   (Python automation scripts)
│   ├── *.md                   (Development documentation)
│   └── build_mod.sh           (Build script)
│
└── ForgeWorksCrafting/         ← Actual mod distribution folder
    ├── mod.cpp                (Mod configuration)
    ├── meta.cpp               (Workshop metadata)
    ├── *.xml                  (Server configuration)
    └── addons/                (To be packed into PBOs)
        ├── ForgeWorks_crafting/
        └── forgeworks_weaponparts/
```

## For Developers

All development work, scripts, and documentation should be placed in the `Development Tools/` folder. See `Development Tools/DEV_ORGANIZATION.md` for details.

## For Distribution

Only the `ForgeWorksCrafting/` folder should be distributed. Never include `Development Tools/` in releases.

## Quick Start

1. **Making changes:** Edit files in `ForgeWorksCrafting/`
2. **Building PBOs:** Use `Development Tools/build_mod.sh` or DayZ Tools
3. **Testing:** See `Development Tools/TROUBLESHOOTING.md`
4. **Documentation:** All dev docs are in `Development Tools/`
