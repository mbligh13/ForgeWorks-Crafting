// Sector 88 - Plugin Initialization
// Path: scripts/4_world/S88PluginInit.c

class S88PluginCrafting extends PluginBase
{
    protected ref S88RecipeManager m_RecipeManager;
    protected ref S88CraftingManager m_CraftingManager;
    protected ref array<ref S88WorkbenchPosition> m_WorkbenchPositions;
    
    void S88PluginCrafting()
    {
        m_WorkbenchPositions = new array<ref S88WorkbenchPosition>;
    }
    
    override void OnInit()
    {
        super.OnInit();
        
        Print("[Sector88] Crafting Plugin Initializing...");
        
        // Initialize managers
        m_RecipeManager = S88RecipeManager.GetInstance();
        m_CraftingManager = S88CraftingManager.GetInstance();
        
        // Load workbench positions from config
        LoadWorkbenchPositions();
        
        Print("[Sector88] Crafting Plugin Initialized!");
    }
    
    void LoadWorkbenchPositions()
    {
        // Load custom workbench positions from JSON config
        string configPath = S88_CONFIG_WORKBENCHES + "positions.json";
        
        if (FileExist(configPath))
        {
            JsonFileLoader<array<ref S88WorkbenchPosition>>.JsonLoadFile(configPath, m_WorkbenchPositions);
            Print("[Sector88] Loaded " + m_WorkbenchPositions.Count() + " workbench positions");
        }
    }
    
    void SpawnWorkbenches()
    {
        if (!GetGame().IsServer())
            return;
            
        foreach (S88WorkbenchPosition pos : m_WorkbenchPositions)
        {
            SpawnWorkbenchAtPosition(pos);
        }
    }
    
    protected void SpawnWorkbenchAtPosition(S88WorkbenchPosition pos)
    {
        vector position = pos.GetPosition();
        vector orientation = pos.GetOrientation();
        
        Object workbench = GetGame().CreateObject("S88CraftingWorkbench", position, false, false, true);
        
        if (workbench)
        {
            workbench.SetOrientation(orientation);
            Print("[Sector88] Spawned workbench at " + position.ToString());
        }
    }
    
    S88RecipeManager GetRecipeManager()
    {
        return m_RecipeManager;
    }
    
    S88CraftingManager GetCraftingManager()
    {
        return m_CraftingManager;
    }
    
    static S88PluginCrafting GetInstance()
    {
        return S88PluginCrafting.Cast(GetPlugin(S88PluginCrafting));
    }
}
