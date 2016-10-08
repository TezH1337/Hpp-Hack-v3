#include "Client.h"

GameInfo_t BuildInfo;

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		g_pUserMsgBase = ( PUserMsg )Engine::g_Offset->FindUserMsgBase ( );

		g_Screen.iSize = sizeof ( SCREENINFO );

		Engine::g_Offset->HLType = g_Studio.IsHardware ( ) + 1;

		Engine::g_Local->ppmove = ( playermove_t* )Engine::g_Offset->PlayerMovePtr ( );

		Engine::g_Offset->ConsoleColorInitalize ( );
		Engine::g_Offset->GetGameInfo ( &BuildInfo );

		HookUserMessages ( );

		g_Init.LoadSettings ( );
		g_Init.InitHack ( );

		FirstFrame = true;
	}

	g_Engine.pfnGetScreenInfo ( &g_Screen );
	g_Client.HUD_Frame ( time );
}

void HUD_Redraw ( float time, int intermission )
{
	g_Client.HUD_Redraw ( time, intermission );

	Engine::g_PlayerInfo->UpdateLocalEntity ( );

	for ( int i = 1; i <= g_Engine.GetMaxClients ( ); ++i )
	{
		Engine::g_PlayerInfo->UpdatePlayerInfo ( i );

		if ( Files::g_IniRead->function->esp )
		{
			Functions::g_ESP->HUD_Redraw ( i );
		}
	}
}

void StudioEntityLight ( struct alight_s *plight )
{
	cl_entity_s *Entity = g_Studio.GetCurrentEntity ( );

	if ( Entity->player )
	{
		Engine::g_PlayerInfo->GetBoneOrigin ( Entity );
		Engine::g_PlayerInfo->GetHitboxOrigin ( Entity );
	}

	g_Studio.StudioEntityLight ( plight );
}

void HookStudio ( )
{
	g_pStudio->StudioEntityLight = StudioEntityLight;
}

void HookFunction ( )
{
	g_pClient->HUD_Frame = HUD_Frame;
	g_pClient->HUD_Redraw = HUD_Redraw;
}

void HookUserMessages ( )
{
	Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::ResetHUD );
	Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::SetFOV );
	Engine::pTeamInfo = HookUserMsg ( TEAM_INFO, Engine::TeamInfo );
	Engine::pCurWeapon = HookUserMsg ( CUR_WEAPON, Engine::CurWeapon );
	Engine::pDeathMsg = HookUserMsg ( DEATH_MSG, Engine::DeathMsg );
}