#include "PlayerInfo.h"

namespace Engine
{	
	void PlayerInfo::UpdateLocalEntity ( )
	{
		g_Local->Entity = g_Engine.GetLocalPlayer ( );
	}

	void PlayerInfo::UpdatePlayerInfo ( int Index )
	{
		g_Player[Index]->Entity = g_Engine.GetEntityByIndex ( Index );

		g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index]->Info );
	}

	PlayerInfo* g_PlayerInfo = new PlayerInfo;

	local_s* g_Local = new local_s;

	player_s* g_Player[33] = 
	{ 
		new player_s,
		new player_s,
		new player_s, 
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
	};
}