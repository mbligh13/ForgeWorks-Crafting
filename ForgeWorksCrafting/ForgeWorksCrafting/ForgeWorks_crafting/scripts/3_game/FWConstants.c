// ForgeWorks - Menu ID Constants
// Path: scripts/3_game/FWConstants.c

// Menu IDs (use high numbers to avoid conflicts)
const int FW_MENU_CRAFTING = 89001;

// Sound Sets
const string FW_SOUND_CRAFT_START = "craft_start_SoundSet";
const string FW_SOUND_CRAFT_COMPLETE = "craft_complete_SoundSet";
const string FW_SOUND_CRAFT_FAIL = "craft_fail_SoundSet";

// Config paths - use $profile: folder for server config files
// NOTE: Copy your positions.json to: <DayZServer>/profiles/ForgeWorks_Crafting/workbenches/positions.json
const string FW_CONFIG_RECIPES = "$profile:ForgeWorks_Crafting/recipes/";
const string FW_CONFIG_WORKBENCHES = "$profile:ForgeWorks_Crafting/workbenches/";

// Distance limits
const float FW_MAX_CRAFT_DISTANCE = 3.0;

// Crafting time multipliers
const float FW_CRAFT_TIME_EASY = 0.5;
const float FW_CRAFT_TIME_NORMAL = 1.0;
const float FW_CRAFT_TIME_HARD = 1.5;
