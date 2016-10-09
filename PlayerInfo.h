#pragma once

#include "Main.h"
#include "PlayerInfo_Structures.h"

namespace Engine
{
	class PlayerInfo
	{
	public:
		static bool isAliveEntity ( struct cl_entity_s *Entity );
		static bool isValidEntity ( struct cl_entity_s *Entity );

		static bool ScanPlayerVisibility ( int Index );

		static void UpdateLocalEntity ( );
		static void UpdatePlayerInfo ( int Index );

		static void GetBoneOrigin ( struct cl_entity_s *Entity );
		static void GetHitboxOrigin ( struct cl_entity_s *Entity );
	};

	extern PlayerInfo* g_PlayerInfo;
}