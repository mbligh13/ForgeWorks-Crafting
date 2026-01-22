void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//GetCEApi().ExportProxyData("12288 0 12288", 24576);	// standard map groups (buildings) export, terrain center and radius needs to be specified
	//GetCEApi().ExportClusterData();	 			// cluster-type map groups export (fruit trees etc.)

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 8, reset_day = 10;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer

{
	override void OnInit()
	{
		super.OnInit();

		//THE FOLLOWING CODE SHOULD BE UNCOMMENTED IF YOU ARE USING NAMALSK SURVIVAL - OTHERWISE, LEAVE IT COMMENTED OUT!
		
		//// this piece of code is recommended otherwise event system is switched on automatically and runs from default values
		//// comment this whole block if NOT using Namalsk Survival
		//if ( m_EventManagerServer )
		//{
		//	// enable/disable event system, min time between events, max time between events, max number of events at the same time
		//	m_EventManagerServer.OnInitServer( true, 4000, 7200, 1 );
		//	m_EventManagerServer.RegisterEvent( Aurora, 1.00 );
		//	//m_EventManagerServer.RegisterEvent( Blizzard, 0. );
		//	//m_EventManagerServer.RegisterEvent( ExtremeCold, 0.0 );
		//	//m_EventManagerServer.RegisterEvent( Snowfall, 0.6 );
		//	//m_EventManagerServer.RegisterEvent( EVRStorm, 0.35 );
		//	//m_EventManagerServer.RegisterEvent( HeavyFog, 0.3 );
		//}
	}

	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			player.SetQuickBarEntityShortcut(itemEnt, 2);

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );
			player.SetQuickBarEntityShortcut(itemEnt, 1);
			SetRandomHealth( itemEnt );
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
		
   player.GetInventory().CreateInInventory("DrysackBag_Yellow");    							// added items
   player.GetInventory().CreateInInventory("Compass");    										// added items
   player.GetInventory().CreateInInventory("WaterBottle");   									// added items
   player.GetInventory().CreateInInventory("SardinesCan");    									// added items
   player.GetInventory().CreateInInventory("KitchenKnife");    									// added items
   player.GetInventory().CreateInInventory("CanOpener");    									// added items
   player.GetInventory().CreateInInventory("ChernarusMap");    									// added items
   player.GetInventory().CreateInInventory("PersonalRadio");    								// added items
   player.GetInventory().CreateInInventory("Battery9V");    									// added items
   player.GetInventory().CreateInInventory("Battery9V");    									// added items
   player.GetInventory().CreateInInventory("BandageDressing");   // added items
   player.GetInventory().CreateInInventory("BakedBeansCan");    								// added items
   player.GetInventory().CreateInInventory("TacticalBaconCan");    								// added items
   player.GetInventory().CreateInInventory("Matchbox");    										// added items
   player.GetInventory().CreateInInventory("Headtorch_Grey");    								// added items
   
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}