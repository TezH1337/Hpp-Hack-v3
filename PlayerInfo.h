#pragma once

#include "Main.h"
#include "PlayerInfoStructures.h"

class PlayerInfo
{
public:
	static void UpdateLocalEntity ( );
	static void UpdatePlayerInfo ( int Index );
};

extern PlayerInfo g_PlayerInfo;