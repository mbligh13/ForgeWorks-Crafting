// Sector 88 - Mission Integration
// Path: scripts/5_mission/S88MissionGameplay.c

modded class MissionGameplay
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = null;
        
        switch (id)
        {
            case S88_MENU_CRAFTING:
                menu = new S88CraftingMenu;
                break;
        }
        
        if (menu)
        {
            menu.SetID(id);
            return menu;
        }
        
        return super.CreateScriptedMenu(id);
    }
}
