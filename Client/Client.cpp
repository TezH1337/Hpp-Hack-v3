#include "Client.h"

GameInfo_t BuildInfo;

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		Engine::g_pUserMsgBase = ( PUserMsg )Engine::g_Offset.FindUserMsgBase ( );

		Engine::g_Screen.iSize = sizeof ( SCREENINFO );

		Engine::g_Offset.HLType = Engine::g_Studio.IsHardware ( ) + 1;

		Engine::g_Local.ppmove = ( playermove_t* )Engine::g_Offset.PlayerMovePtr ( );

		Engine::g_Offset.ConsoleColorInitalize ( );
		Engine::g_Offset.GetGameInfo ( &BuildInfo );

		HookUserMessages ( );

		g_Init.LoadSettings ( );
		g_Init.InitHack ( );

		FirstFrame = true;
	}

	Engine::g_Engine.pfnGetScreenInfo ( &Engine::g_Screen );
	Engine::g_Client.HUD_Frame ( time );
}

void HUD_Redraw ( float time, int intermission )
{
	Engine::g_Client.HUD_Redraw ( time, intermission );

	Engine::g_PlayerInfo.UpdateLocalEntity ( Engine::g_Engine.GetLocalPlayer ( ) );

	for ( BYTE Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
	{
		Engine::g_PlayerInfo.UpdatePlayerInfo ( Engine::g_Engine.GetEntityByIndex ( Index ), Index );

		if ( Files::g_IniRead.function.esp )
		{
			Functions::g_ESP.HUD_Redraw ( Index );
		}
	}
}

void StudioEntityLight ( struct alight_s *plight )
{
	if ( Engine::g_Studio.GetCurrentEntity ( )->player )
	{
		Engine::g_PlayerInfo.GetBoneOrigin ( Engine::g_Studio.GetCurrentEntity ( ) );
		Engine::g_PlayerInfo.GetHitboxOrigin ( Engine::g_Studio.GetCurrentEntity ( ) );
	}

	Engine::g_Studio.StudioEntityLight ( plight );
}

int HUD_AddEntity ( int type, struct cl_entity_s *ent, const char *modelname )
{
	Functions::g_ESP.HUD_AddEntity ( ent );

	return Engine::g_Client.HUD_AddEntity ( type, ent, modelname );
}

int HUD_Key_Event ( int down, int keynum, const char *pszCurrentBinding )
{
	if ( keynum == Files::g_IniRead.main.reload_key )
	{
		g_Init.ReloadSettings ( );

		if ( Files::g_IniRead.main.language )
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );
			g_Util.ConsolePrintColor ( 200, 255, 200, "Settings successfully reloaded.\n" );
		}
		else
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, "[Hpp] " );
			g_Util.ConsolePrintColor ( 200, 255, 200, "Настройки успешно перезагружены.\n" );
		}

		Engine::g_Engine.pfnPlaySoundByName ( "vox/ok.wav", 1 );
	}

	return Engine::g_Client.HUD_Key_Event ( down, keynum, pszCurrentBinding );
}

void HookStudio ( )
{
	Engine::g_pStudio->StudioEntityLight = StudioEntityLight;
}

void HookFunction ( )
{
	Engine::g_pClient->HUD_Frame = HUD_Frame;
	Engine::g_pClient->HUD_Redraw = HUD_Redraw;
	Engine::g_pClient->HUD_Key_Event = HUD_Key_Event;
	Engine::g_pClient->HUD_AddEntity = HUD_AddEntity;
}

void HookUserMessages ( )
{
	Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::g_UserMsg->ResetHUD );
	Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::g_UserMsg->SetFOV );
	Engine::pTeamInfo = HookUserMsg ( TEAM_INFO, Engine::g_UserMsg->TeamInfo );
	Engine::pCurWeapon = HookUserMsg ( CUR_WEAPON, Engine::g_UserMsg->CurWeapon );
	Engine::pDeathMsg = HookUserMsg ( DEATH_MSG, Engine::g_UserMsg->DeathMsg );
}