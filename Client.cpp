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

	for ( BYTE i = 1; i <= g_Engine.GetMaxClients ( ); ++i )
	{
		Engine::g_PlayerInfo->UpdatePlayerInfo ( i );

		if ( Files::g_IniRead->function->esp && Files::g_IniRead->esp->enable)
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

int HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding )
{
	if ( keynum == Files::g_IniRead->main->reload_key )
	{
		g_Init.ReloadSettings ( );

		if ( Files::g_IniRead->main->language )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );
			g_Util.ConsolePrintColor ( 200, 255, 200, "Settings successfully reloaded.\n" );
		}
		else
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );
			g_Util.ConsolePrintColor ( 200, 255, 200, "Настройки успешно перезагружены.\n" );
		}

		g_Engine.pfnPlaySoundByName ( "vox/ok.wav", 1 );
	}

	return g_Client.HUD_Key_Event ( down, keynum, pszCurrentBinding );
}

void HookStudio ( )
{
	g_pStudio->StudioEntityLight = StudioEntityLight;
}

void HookFunction ( )
{
	g_pClient->HUD_Frame = HUD_Frame;
	g_pClient->HUD_Redraw = HUD_Redraw;
	g_pClient->HUD_Key_Event = HUD_Key_Event;
}

void HookUserMessages ( )
{
	Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::g_UserMsg->ResetHUD );
	Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::g_UserMsg->SetFOV );
	Engine::pTeamInfo = HookUserMsg ( TEAM_INFO, Engine::g_UserMsg->TeamInfo );
	Engine::pCurWeapon = HookUserMsg ( CUR_WEAPON, Engine::g_UserMsg->CurWeapon );
	Engine::pDeathMsg = HookUserMsg ( DEATH_MSG, Engine::g_UserMsg->DeathMsg );
}