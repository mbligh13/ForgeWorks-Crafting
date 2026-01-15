// Sector 88 - Player Action Registration
// Path: scripts/4_world/entities/S88PlayerBase.c
// This modded class adds the crafting action to the player so it works on any workbench

modded class PlayerBase
{
    override void SetActions()
    {
        super.SetActions();
        
        // Add the crafting menu action - this allows it to work on any valid workbench target
        AddAction(ActionS88OpenCraftingMenu);
    }
}
