class CfgMods
{
    class Sector88_Crafting
    {
        dir = "@Sector88_Crafting";
        picture = "Sector88_Weapon Crafting.paa";
        action = "";
        hideName = 0;
        hidePicture = 0;
        name = "Sector 88 Weapon Crafting";
        description = "Weapon crafting system with 68+ recipes across 8 tiers; full details on the Steam page.";
        credits = "Sector 88 Dev Team";
        author = "Rook";
        authorID = "76561198074746423";
        version = "1.0.0";
        extra = 0;
        type = "mod";
        
        dependencies[] = { "Game", "World", "Mission" };
        
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "Sector88_Crafting/scripts/3_game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "Sector88_Crafting/scripts/4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "Sector88_Crafting/scripts/5_mission" };
            };
        };
    };
};
