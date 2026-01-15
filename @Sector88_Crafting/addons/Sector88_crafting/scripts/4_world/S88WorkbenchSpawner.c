// Sector 88 - Workbench Position Helper
// Use this to configure workbench positions at specific world coordinates
// Path: scripts/4_world/S88WorkbenchSpawner.c

class S88WorkbenchSpawner
{
    // Call this from your mission init to spawn workbenches at defined positions
    static void SpawnAtPosition(vector position, vector orientation = "0 0 0", string workbenchType = "S88CraftingWorkbench")
    {
        if (!GetGame().IsServer())
            return;
            
        // Adjust Y position to ground
        position[1] = GetGame().SurfaceY(position[0], position[2]);
        
        Object workbench = GetGame().CreateObject(workbenchType, position, false, false, true);
        
        if (workbench)
        {
            workbench.SetOrientation(orientation);
            workbench.SetPosition(position);
            Print("[S88] Spawned " + workbenchType + " at " + position.ToString());
        }
    }
    
    // Spawn workbench near existing DayZ workbench
    static void SpawnNearVanillaWorkbench(string vanillaWorkbenchClass = "Land_Repair_Center")
    {
        if (!GetGame().IsServer())
            return;
            
        // Find all vanilla workbenches and place S88 workbench nearby
        array<Object> objects = new array<Object>;
        array<CargoBase> cargo = new array<CargoBase>;
        
        // Search entire map (expensive, use sparingly)
        GetGame().GetObjectsAtPosition("0 0 0", 50000, objects, cargo);
        
        foreach (Object obj : objects)
        {
            if (obj.IsKindOf(vanillaWorkbenchClass))
            {
                vector pos = obj.GetPosition();
                vector offset = Vector(1.5, 0, 0);  // Offset to the side
                SpawnAtPosition(pos + offset, obj.GetOrientation());
            }
        }
    }
    
    // Quick spawn helper using coordinates as string (for admin tools)
    static void SpawnFromString(string coordString)
    {
        // Format: "x,y,z" or "x,y,z,yaw"
        TStringArray parts = new TStringArray;
        coordString.Split(",", parts);
        
        if (parts.Count() < 3)
        {
            Print("[S88] Invalid coordinate format. Use: x,y,z or x,y,z,yaw");
            return;
        }
        
        vector pos = Vector(parts[0].ToFloat(), parts[1].ToFloat(), parts[2].ToFloat());
        vector ori = "0 0 0";
        
        if (parts.Count() >= 4)
        {
            ori = Vector(parts[3].ToFloat(), 0, 0);
        }
        
        SpawnAtPosition(pos, ori);
    }
}

// ============================================
// Admin command to spawn workbench at player position
// ============================================
class S88AdminSpawnWorkbench
{
    static void Execute(PlayerBase player, string type = "S88CraftingWorkbench")
    {
        if (!player)
            return;
            
        vector pos = player.GetPosition();
        vector dir = player.GetDirection();
        
        // Spawn 2 meters in front of player
        vector spawnPos = pos + (dir * 2);
        spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]);
        
        // Get player yaw for workbench orientation
        vector ori = player.GetOrientation();
        
        S88WorkbenchSpawner.SpawnAtPosition(spawnPos, ori, type);
    }
}
