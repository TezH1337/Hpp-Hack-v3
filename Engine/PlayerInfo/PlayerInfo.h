#pragma once

#include "Main.h"
#include "PlayerInfo_Structures.h"

namespace Engine
{
	class PlayerInfo
	{
	public:
		//Check the player is alive or not
		__inline static bool isAliveEntity ( struct cl_entity_s *Entity );
		//Check the player is valid or not
		__inline static bool isValidEntity ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
		//Check the player is ducked or not
		__inline static bool isDuckedEntity ( struct cl_entity_s *Entity );
		//Scanning the player on the visibility
		__inline static bool ScanPlayerVisibility ( int Index );
		//Update information about local player
		static void UpdateLocalEntity ( struct cl_entity_s *Local );
		//Update information about players
		static void UpdatePlayerInfo ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
		//Get player's bones
		static void GetBoneOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
		//Get player's hitboxes
		static void GetHitboxOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
	};

	extern PlayerInfo g_PlayerInfo;
}