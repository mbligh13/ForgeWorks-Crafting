// Sector 88 - Open Crafting Menu Action
// Path: scripts/4_world/actions/ActionS88OpenCraftingMenu.c

class ActionS88OpenCraftingMenuCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(0.5);
    }
}

class ActionS88OpenCraftingMenu : ActionContinuousBase
{
    void ActionS88OpenCraftingMenu()
    {
        m_CallbackClass = ActionS88OpenCraftingMenuCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
        m_FullBody = false;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "#STR_S88_CRAFT";
    }
    
    override void CreateConditionComponents()
    {
        m_ConditionTarget = new CCTNone;
        m_ConditionItem = new CCINone;
    }
    
    override typename GetInputType()
    {
        return ContinuousInteractActionInput;
    }
    
    override string GetText()
    {
        return "Open Crafting Menu";
    }
    
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!target)
            return false;
            
        Object targetObject = target.GetObject();
        if (!targetObject)
            return false;
            
        // Only allow interaction with ExpansionPropWorkbench (admin-placed workbench)
        if (targetObject.IsKindOf("ExpansionPropWorkbench"))
            return true;
            
        return false;
    }
    
    override void OnFinishProgressServer(ActionData action_data)
    {
        // Server-side: validate and prepare for crafting
    }
    
    override void OnFinishProgressClient(ActionData action_data)
    {
        // Client-side: open the crafting menu
        PlayerBase player = action_data.m_Player;
        Object workbench = action_data.m_Target.GetObject();
        
        OpenCraftingMenu(player, workbench);
    }
    
    void OpenCraftingMenu(PlayerBase player, Object workbench)
    {
        if (!GetGame().IsClient())
            return;
            
        // Create and show the crafting menu
        S88CraftingMenu menu = S88CraftingMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(S88_MENU_CRAFTING, null));
        
        if (menu)
        {
            menu.SetWorkbench(workbench);
        }
    }
}

// ============================================
// Quick Action (Tap to open instantly)
// ============================================
class ActionS88OpenCraftingMenuQuick : ActionInteractBase
{
    void ActionS88OpenCraftingMenuQuick()
    {
        m_Text = "#STR_S88_CRAFT_QUICK";
    }
    
    override void CreateConditionComponents()
    {
        m_ConditionTarget = new CCTNone;
        m_ConditionItem = new CCINone;
    }
    
    override string GetText()
    {
        return "Craft (Quick)";
    }
    
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!target)
            return false;
            
        Object targetObject = target.GetObject();
        if (!targetObject)
            return false;
            
        if (targetObject.IsKindOf("S88CraftingWorkbench"))
            return true;
            
        if (targetObject.IsKindOf("Workbench"))
            return true;
            
        return false;
    }
    
    override void OnExecuteClient(ActionData action_data)
    {
        PlayerBase player = action_data.m_Player;
        Object workbench = action_data.m_Target.GetObject();
        
        // Create and show the crafting menu
        S88CraftingMenu menu = S88CraftingMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(S88_MENU_CRAFTING, null));
        
        if (menu)
        {
            menu.SetWorkbench(workbench);
        }
    }
}
