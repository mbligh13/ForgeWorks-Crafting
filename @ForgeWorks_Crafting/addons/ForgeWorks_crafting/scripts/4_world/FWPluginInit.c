// Sector 88 - Plugin Initialization
// Path: scripts/4_world/FWPluginInit.c

class FWPluginCrafting extends PluginBase
{
    protected ref FWRecipeManager m_RecipeManager;
    protected ref FWCraftingManager m_CraftingManager;
    protected ref array<ref FWWorkbenchPosition> m_WorkbenchPositions;
    
    void FWPluginCrafting()
    {
        m_WorkbenchPositions = new array<ref FWWorkbenchPosition>;
    }
    
    override void OnInit()
    {
        super.OnInit();
        
        Print("[Sector88] Crafting Plugin Initializing...");
        
        // Initialize managers
        m_RecipeManager = FWRecipeManager.GetInstance();
        m_CraftingManager = FWCraftingManager.GetInstance();
        
        // Load workbench positions from config
        LoadWorkbenchPositions();
        
        Print("[Sector88] Crafting Plugin Initialized!");
    }
    
    void LoadWorkbenchPositions()
    {
        // Load custom workbench positions from JSON config
        string configPath = FW_CONFIG_WORKBENCHES + "positions.json";
        
        if (FileExist(configPath))
        {
            JsonFileLoader<array<ref FWWorkbenchPosition>>.JsonLoadFile(configPath, m_WorkbenchPositions);
            Print("[Sector88] Loaded " + m_WorkbenchPositions.Count() + " workbench positions");
        }
    }
    
    void SpawnWorkbenches()
    {
        if (!GetGame().IsServer())
            return;
            
        foreach (FWWorkbenchPosition pos : m_WorkbenchPositions)
        {
            SpawnWorkbenchAtPosition(pos);
        }
    }
    
    protected void SpawnWorkbenchAtPosition(FWWorkbenchPosition pos)
    {
        vector position = pos.GetPosition();
        vector orientation = pos.GetOrientation();
        
        Object workbench = GetGame().CreateObject("FWCraftingWorkbench", position, false, false, true);
        
        if (workbench)
        {
            workbench.SetOrientation(orientation);
            Print("[Sector88] Spawned workbench at " + position.ToString());
        }
    }
    
    FWRecipeManager GetRecipeManager()
    {
        return m_RecipeManager;
    }
    
    FWCraftingManager GetCraftingManager()
    {
        return m_CraftingManager;
    }
    
    static FWPluginCrafting GetInstance()
    {
        return FWPluginCrafting.Cast(GetPlugin(FWPluginCrafting));
    }
}
