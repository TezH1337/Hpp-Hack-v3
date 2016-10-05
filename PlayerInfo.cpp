#include "PlayerInfo.h"

PlayerInfo g_PlayerInfo;
local_s g_Local;
player_s g_Player[33];

void PlayerInfo::UpdateLocalEntity ( )
{
	g_Local.Entity = g_Engine.GetLocalPlayer ( );
}

void PlayerInfo::UpdatePlayerInfo ( int Index )
{
	g_Player[Index].Entity = g_Engine.GetEntityByIndex ( Index );

	g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );
}