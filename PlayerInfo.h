#pragma once

#include "Main.h"
#include "PlayerInfo_Structures.h"

namespace Engine
{
	class PlayerInfo
	{
	public:
		static void UpdateLocalEntity ( );
		static void UpdatePlayerInfo ( int Index );
	};

	extern PlayerInfo* g_PlayerInfo;
}