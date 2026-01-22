{
    "Turrets": [ // Dont change this, or it will break config
        {
            "m_sTurretClassName": "M60_Turret_Bottom_1000HP", // Turret Class Name. Get it from ClassNames.txt
            "m_vTurretPosition": [ // Turret XYZ Position
                1234.0,
                123.0,
                1234.0
            ],
            "m_vTurretRotation": [ // Turret XYZ Rotation
                0.0,
                0.0,
                0.0
            ],
            "m_fTurretGuardRadius": 50.0, // The radius in which the turret searches for targets (Search Radius)
            "m_sTurretAmmoClassName": "Bullet_556x45", // Ammo Type, that Turret shoots (you can find this types in "DZ\data\config.cpp - cfgAmmoTypes" or here "https://pastebin.com/uwbyBH3x 1.18 Patch!!!"). Turret damage depends on this variable. You can use bullets from other mods, but you will need to get cfgAmmoTypes yourself 
            "m_nTurretShootingRPM": 650, // Turret fire rate in rounds per minute (RPM 60 = 1 round per second -> turret will fire every second)
            "m_nTurretHitChance": 80, // Chance of the turret hitting the target
            "m_bTurretExplosiveRounds": 0, // If True - the bullet explodes when it hits the target
            "m_bTurretCanIdle": 1, // If True - the turret will move from left to right, “scanning” for targets when idle.
            "m_fTurretMaxIdleAngle": 45.0, // The angle at which the turret will rotate when idle
            "m_bTurretCanBeDestroyed": 1, // If True - the turret can be destroyed
            "m_nTurretTimeToRespawn": 3600, // Time after which the turret will respawn
            "m_aTurretTargetsPlayers": [
                "76561198180634871"
                /*
                Player targets | You can use: 
                ALL = All players will be targets
                NONE = Players will be disabled for this turret as targets.
                STEAM ID 64 = Player with this steam id will be target
                REVERSE = Will reverse this targets list, so IDs in this list will not be targets, but all other Players will be
                */
            ],
            "m_aTurretTargetsZombies": [
                "REVERSE",
                "ZmbM_PatrolNormal_Summer",
                "ZmbM_NBC_Grey",
                "ZmbF_PoliceWomanNormal"
                /*
                Zombies targets | You can use: 
                ALL = All zombies will be targets
                NONE = Zombies will be disabled for this Turret as targets
                ClassName(Type) = Zombies with this Class Name will be targets (You can find this class names in "DZ\characters\config.cpp or just type ZmbM_ / ZmbF_ in the item spawner you have)
                REVERSE = Will reverse this targets list, so Zombies in this list will not be targets, but all other Zombies will be
                */
            ],
            "m_aTurretTargetsAnimals": [
                "NONE"
                /*
                Animals targets | You can use: 
                ALL = All animals will be targets
                NONE = Animals will be disabled for this Turret as targets
                ClassName(Type) = Animals with this Class Name will be targets (You can find this class names in "DZ\animals | DZ\animals_bliss"(if you have Livonia DLC) or just type Animal_ in the item spawner you have)
                REVERSE = Will reverse this targets list, so Animals in this list will not be targets, but all other Animals will be
                */
            ],
            "m_aTurretTargetsVehicles": [
                "IGNORE PLAYERS LIST",
                "ALL"
                /*
                Vehicles targets | You can use: 
                ALL = All vehicles will be targets
                NONE = Vehicles will be disabled for this Turret as targets
                ClassName(Type) = Vehicles with this Class Name will be targets (You can find this class names in "DZ\vehicles\wheeled\config.cpp or in the item spawner you have)
                REVERSE = Will reverse this targets list, so Vehicles in this list will not be targets, but all other Vehicles will be
                IGNORE PLAYERS LIST = Turret will ignore players targets list, so if player is not target, but vehicle is target -> turret will destroy vehicle and kill everyone inside

                Turret will not fire at empty vehicle, it will fire only if vehicle has players inside, even if "m_aTurretTargetsPlayers" disabled!!!
                */
            ]
        }
    ]
}

//Your AutomatedTurretsConfig.json should look something like this:

{
    "Turrets": [
        {
            "m_sTurretClassName": "M60_Turret_Bottom_1000HP",
            "m_vTurretPosition": [
                1234.0,
                123.0,
                1234.0
            ],
            "m_vTurretRotation": [
                0.0,
                0.0,
                0.0
            ],
            "m_fTurretGuardRadius": 50.0,
            "m_sTurretAmmoClassName": "Bullet_556x45",
            "m_nTurretShootingRPM": 650,
            "m_nTurretHitChance": 80,
            "m_bTurretExplosiveRounds": 0,
            "m_bTurretCanIdle": 1,
            "m_fTurretMaxIdleAngle": 45.0,
            "m_bTurretCanBeDestroyed": 1,
            "m_nTurretTimeToRespawn": 3600,
            "m_aTurretTargetsPlayers": [
                "76561198180634871"
            ],
            "m_aTurretTargetsZombies": [
                "REVERSE",
                "ZmbM_PatrolNormal_Summer",
                "ZmbM_NBC_Grey",
                "ZmbF_PoliceWomanNormal"
            ],
            "m_aTurretTargetsAnimals": [
                "NONE"
            ],
            "m_aTurretTargetsVehicles": [
                "ALL"
            ]
        },
        {
            "m_sTurretClassName": "M134_Turret_Bottom_5000HP",
            "m_vTurretPosition": [
                1234.0,
                123.0,
                1234.0
            ],
            "m_vTurretRotation": [
                0.0,
                0.0,
                0.0
            ],
            "m_fTurretGuardRadius": 75.0,
            "m_sTurretAmmoClassName": "Bullet_556x45",
            "m_nTurretShootingRPM": 6000,
            "m_nTurretHitChance": 25,
            "m_bTurretExplosiveRounds": 0,
            "m_bTurretCanIdle": 0,
            "m_fTurretMaxIdleAngle": 0.0,
            "m_bTurretCanBeDestroyed": 1,
            "m_nTurretTimeToRespawn": 60,
            "m_aTurretTargetsPlayers": [
                "76561198180634871"
            ],
            "m_aTurretTargetsZombies": [
                "REVERSE",
                "ZmbM_PatrolNormal_Summer",
                "ZmbM_NBC_Grey",
                "ZmbF_PoliceWomanNormal"
            ],
            "m_aTurretTargetsAnimals": [
                "NONE"
            ],
            "m_aTurretTargetsVehicles": [
                "ALL"
            ]
        },
        {
            "m_sTurretClassName": "M134_Turret_Top_10000HP",
            "m_vTurretPosition": [
                1234.0,
                123.0,
                1234.0
            ],
            "m_vTurretRotation": [
                0.0,
                0.0,
                0.0
            ],
            "m_fTurretGuardRadius": 150.0,
            "m_sTurretAmmoClassName": "Bullet_308Win",
            "m_nTurretShootingRPM": 30,
            "m_nTurretHitChance": 100,
            "m_bTurretExplosiveRounds": 1,
            "m_bTurretCanIdle": 1,
            "m_fTurretMaxIdleAngle": 125.0,
            "m_bTurretCanBeDestroyed": 0,
            "m_nTurretTimeToRespawn": 0,
            "m_aTurretTargetsPlayers": [
                "76561198180634871"
            ],
            "m_aTurretTargetsZombies": [
                "REVERSE",
                "ZmbM_PatrolNormal_Summer",
                "ZmbM_NBC_Grey",
                "ZmbF_PoliceWomanNormal"
            ],
            "m_aTurretTargetsAnimals": [
                "NONE"
            ],
            "m_aTurretTargetsVehicles": [
                "ALL"
            ]
        }
    ]
}