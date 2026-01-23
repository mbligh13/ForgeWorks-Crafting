class CfgMods
{
    class ForgeWorksCrafting
    {
        dir = "crafting";
        picture = "ForgeWorks_Crafting.paa";
        action = "";
        hideName = 0;
        hidePicture = 0;
        name = "ForgeWorksCrafting";
        description = "Weapon crafting system with 68+ recipes across 8 tiers; full details on the Steam page.";
        credits = "Sector 88 Dev Team";
        author = "Rook";
        authorID = "76561198074746423";
        version = "1.0.3";
        extra = 0;
        type = "mod";
        
        dependencies[] = { "Game", "World", "Mission" };
        
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "crafting/scripts/3_game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "crafting/scripts/4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "crafting/scripts/5_mission" };
            };
        };
    };
};
