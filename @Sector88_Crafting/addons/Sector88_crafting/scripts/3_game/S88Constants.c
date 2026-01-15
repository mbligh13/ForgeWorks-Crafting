// Sector 88 - Menu ID Constants
// Path: scripts/3_game/S88Constants.c

// Menu IDs (use high numbers to avoid conflicts)
const int S88_MENU_CRAFTING = 89001;

// Sound Sets
const string S88_SOUND_CRAFT_START = "craft_start_SoundSet";
const string S88_SOUND_CRAFT_COMPLETE = "craft_complete_SoundSet";
const string S88_SOUND_CRAFT_FAIL = "craft_fail_SoundSet";

// Config paths - use $profile: folder for server config files
// NOTE: Copy your positions.json to: <DayZServer>/profiles/Sector88_Crafting/workbenches/positions.json
const string S88_CONFIG_RECIPES = "$profile:Sector88_Crafting/recipes/";
const string S88_CONFIG_WORKBENCHES = "$profile:Sector88_Crafting/workbenches/";

// Distance limits
const float S88_MAX_CRAFT_DISTANCE = 3.0;

// Crafting time multipliers
const float S88_CRAFT_TIME_EASY = 0.5;
const float S88_CRAFT_TIME_NORMAL = 1.0;
const float S88_CRAFT_TIME_HARD = 1.5;
