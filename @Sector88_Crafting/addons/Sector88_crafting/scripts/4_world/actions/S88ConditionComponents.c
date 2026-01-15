// Sector 88 - Condition Component for Workbench Distance
// Path: scripts/4_world/actions/S88ConditionComponents.c

class CCTWorkbenchDistance : CCTBase
{
    protected float m_MaxDistance;
    
    void CCTWorkbenchDistance(float maxDistance = 3.0)
    {
        m_MaxDistance = maxDistance;
    }
    
    override bool Can(PlayerBase player, ActionTarget target)
    {
        if (!target)
            return false;
            
        Object targetObj = target.GetObject();
        if (!targetObj)
            return false;
            
        // Check if target is a workbench
        if (!IsWorkbench(targetObj))
            return false;
            
        // Check distance
        float dist = vector.Distance(player.GetPosition(), targetObj.GetPosition());
        if (dist > m_MaxDistance)
            return false;
            
        return true;
    }
    
    protected bool IsWorkbench(Object obj)
    {
        if (obj.IsKindOf("S88CraftingWorkbench"))
            return true;
            
        if (obj.IsKindOf("Workbench"))
            return true;
            
        if (obj.IsKindOf("Land_Repair_Center"))
            return true;
            
        return false;
    }
}
