#!/bin/bash
# ForgeWorks Crafting - Build Script
# This script builds the mod PBOs using DayZ Tools or mikero's tools

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}======================================${NC}"
echo -e "${GREEN}ForgeWorks Crafting - Build Script${NC}"
echo -e "${GREEN}======================================${NC}"
echo ""

# Configuration
MOD_DIR="ForgeWorksCrafting"
ADDONS_DIR="${MOD_DIR}/addons"
BUILD_TEMP="build_temp"

# Check if running on Windows or Linux
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    echo -e "${YELLOW}Windows environment detected${NC}"
    # Path to DayZ Tools (adjust as needed)
    ADDON_BUILDER="C:/Program Files (x86)/Steam/steamapps/common/DayZ Tools/Bin/AddonBuilder/AddonBuilder.exe"
else
    echo -e "${YELLOW}Linux/Unix environment detected${NC}"
    # Check for makepbo (part of mikero's tools)
    if command -v makepbo &> /dev/null; then
        echo -e "${GREEN}Found makepbo (Mikero's Tools)${NC}"
        USE_MAKEPBO=true
    else
        echo -e "${RED}Error: No PBO building tools found!${NC}"
        echo "Please install Mikero's Tools (makepbo) or run on Windows with DayZ Tools"
        exit 1
    fi
fi

# Create build temp directory
mkdir -p "${BUILD_TEMP}"

# Function to build a PBO using makepbo
build_pbo_makepbo() {
    local source_dir=$1
    local addon_name=$2
    
    echo -e "${YELLOW}Building ${addon_name}.pbo...${NC}"
    
    if makepbo -@="${addon_name}" "${source_dir}" "${BUILD_TEMP}/${addon_name}.pbo"; then
        echo -e "${GREEN}✓ Successfully built ${addon_name}.pbo${NC}"
        mv "${BUILD_TEMP}/${addon_name}.pbo" "${ADDONS_DIR}/"
        if [ -f "${BUILD_TEMP}/${addon_name}.pbo.key" ]; then
            rm "${BUILD_TEMP}/${addon_name}.pbo.key"
        fi
        return 0
    else
        echo -e "${RED}✗ Failed to build ${addon_name}.pbo${NC}"
        return 1
    fi
}

# Clean previous builds
echo -e "${YELLOW}Cleaning previous builds...${NC}"
rm -f "${ADDONS_DIR}/ForgeWorks_crafting.pbo"
rm -f "${ADDONS_DIR}/forgeworks_weaponparts.pbo"
echo -e "${GREEN}✓ Cleaned${NC}"
echo ""

# Build ForgeWorks_crafting.pbo
echo -e "${GREEN}Building ForgeWorks_crafting.pbo...${NC}"
if [ "$USE_MAKEPBO" = true ]; then
    build_pbo_makepbo "${ADDONS_DIR}/ForgeWorks_crafting" "ForgeWorks_crafting"
else
    echo -e "${YELLOW}Please use DayZ Tools Addon Builder to pack:${NC}"
    echo "  Source: ${ADDONS_DIR}/ForgeWorks_crafting"
    echo "  Output: ${ADDONS_DIR}/ForgeWorks_crafting.pbo"
fi
echo ""

# Build forgeworks_weaponparts.pbo
echo -e "${GREEN}Building forgeworks_weaponparts.pbo...${NC}"
if [ "$USE_MAKEPBO" = true ]; then
    build_pbo_makepbo "${ADDONS_DIR}/forgeworks_weaponparts" "forgeworks_weaponparts"
else
    echo -e "${YELLOW}Please use DayZ Tools Addon Builder to pack:${NC}"
    echo "  Source: ${ADDONS_DIR}/forgeworks_weaponparts"
    echo "  Output: ${ADDONS_DIR}/forgeworks_weaponparts.pbo"
fi
echo ""

# Cleanup
rm -rf "${BUILD_TEMP}"

echo -e "${GREEN}======================================${NC}"
echo -e "${GREEN}Build Complete!${NC}"
echo -e "${GREEN}======================================${NC}"
echo ""
echo -e "${YELLOW}Output PBOs in: ${ADDONS_DIR}/${NC}"
echo -e "${YELLOW}Mod ready for distribution: ${MOD_DIR}/${NC}"
echo ""
echo -e "${YELLOW}Note: Remember to sign your PBOs with DSSignFile before distribution${NC}"
