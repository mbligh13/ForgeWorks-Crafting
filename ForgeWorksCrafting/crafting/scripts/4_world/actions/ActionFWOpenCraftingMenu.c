// Sector 88 - Open Crafting Menu Action
// Path: scripts/4_world/actions/ActionFWOpenCraftingMenu.c

class ActionFWOpenCraftingMenuCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(0.5);
    }
}

class ActionFWOpenCraftingMenu : ActionContinuousBase
{
    void ActionFWOpenCraftingMenu()
    {
        m_CallbackClass = ActionFWOpenCraftingMenuCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
        m_FullBody = false;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "#STR_FW_CRAFT";
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
            
        // Only allow interaction with FWCraftingWorkbench
        if (targetObject.IsKindOf("FWCraftingWorkbench"))
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
        FWCraftingMenu menu = FWCraftingMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(FW_MENU_CRAFTING, null));
        
        if (menu)
        {
            menu.SetWorkbench(workbench);
        }
    }
}

// ============================================
// Quick Action (Tap to open instantly)
// ============================================
class ActionFWOpenCraftingMenuQuick : ActionInteractBase
{
    void ActionFWOpenCraftingMenuQuick()
    {
        m_Text = "#STR_FW_CRAFT_QUICK";
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
            
        // Only FWCraftingWorkbench
        if (targetObject.IsKindOf("FWCraftingWorkbench"))
            return true;
            
        return false;
    }
    
    override void OnExecuteClient(ActionData action_data)
    {
        PlayerBase player = action_data.m_Player;
        Object workbench = action_data.m_Target.GetObject();
        
        // Create and show the crafting menu
        FWCraftingMenu menu = FWCraftingMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(FW_MENU_CRAFTING, null));
        
        if (menu)
        {
            menu.SetWorkbench(workbench);
        }
    }
}
