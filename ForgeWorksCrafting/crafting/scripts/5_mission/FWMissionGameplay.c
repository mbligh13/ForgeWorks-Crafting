// ForgeWorks - Mission Integration
// Path: scripts/5_mission/FWMissionGameplay.c

modded class MissionGameplay
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = null;
        
        switch (id)
        {
            case FW_MENU_CRAFTING:
                menu = new FWCraftingMenu;
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
