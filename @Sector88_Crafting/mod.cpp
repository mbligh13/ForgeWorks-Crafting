class CfgMods
{
    class Sector88_Crafting
    {
        dir = "@Sector88_Crafting";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 1;
        name = "Sector 88 Crafting";
        credits = "Sector 88 Dev Team";
        author = "Sector 88";
        authorID = "";
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
