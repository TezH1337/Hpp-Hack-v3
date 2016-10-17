#include "Client.h"

GameInfo_t BuildInfo;

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		Engine::g_Screen.iSize = sizeof ( SCREENINFO );

		Engine::g_Offset.HLType = Engine::g_Studio.IsHardware ( ) + 1;

		Engine::g_Local.ppmove = ( playermove_t* )Engine::g_Offset.PlayerMovePtr ( );

		Engine::g_Offset.ConsoleColorInitalize ( );
		Engine::g_Offset.GetGameInfo ( &BuildInfo );

		Engine::g_pUserMsgBase = ( PUserMsg )Engine::g_Offset.FindUserMsgBase ( );
		Engine::g_pEngineMsgBase = ( PEngineMsg )Engine::g_Offset.FindSVCMessages ( );

		HookUserMessages ( );
		HookEngineMessages ( );

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

	struct cl_entity_s *Local = Engine::g_Engine.GetLocalPlayer ( );

	if ( Local->player )
	{
		Engine::g_PlayerInfo.UpdateLocalEntity ( Local );
	}

	for ( BYTE Index = 1; Index <= Engine::g_Engine.GetMaxClients ( ); ++Index )
	{
		struct cl_entity_s *Entity = Engine::g_Engine.GetEntityByIndex ( Index );

		if ( Entity->player && Index != Local->index )
		{
			Engine::g_PlayerInfo.UpdatePlayerInfo ( Entity, Local, Index );
		}

		if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.enable )
		{
			Functions::g_ESP.HUD_Redraw ( Entity, Local, Index );
		}
	}
}

void StudioEntityLight ( struct alight_s *plight )
{
	struct cl_entity_s *Local = Engine::g_Engine.GetLocalPlayer ( );
	struct cl_entity_s *Entity = Engine::g_Studio.GetCurrentEntity ( );

	if ( Entity->player && Entity->index != Local->index)
	{
		Engine::g_PlayerInfo.GetBoneOrigin ( Entity, Local );
		Engine::g_PlayerInfo.GetHitboxOrigin ( Entity, Local );
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
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_ENG );
		}
		else
		{
			g_Util.ConsolePrintColor ( 100, 255, 200, HPP );
			g_Util.ConsolePrintColor ( 200, 255, 200, SETTINGS_RELOADED_RUS );
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
	Engine::pResetHUD = HookUserMsg ( RESET_HUD, Engine::g_UserMsg.ResetHUD );
	Engine::pSetFOV = HookUserMsg ( SET_FOV, Engine::g_UserMsg.SetFOV );
	Engine::pTeamInfo = HookUserMsg ( TEAM_INFO, Engine::g_UserMsg.TeamInfo );
	Engine::pCurWeapon = HookUserMsg ( CUR_WEAPON, Engine::g_UserMsg.CurWeapon );
	Engine::pDeathMsg = HookUserMsg ( DEATH_MSG, Engine::g_UserMsg.DeathMsg );
}

void HookEngineMessages ( )
{
	Engine::pSVC_sound = HookEngineMsg ( SOUND, Engine::SVC_Sound );
	Engine::pSVC_SpawnStaticSound = HookEngineMsg ( SPAWN_STATIC_SOUND, Engine::SVC_SpawnStaticSound );
	Engine::pSVC_StuffText = HookEngineMsg ( STUFF_TEXT, Engine::SVC_StuffText );
	Engine::pSVC_NewUserMsg = HookEngineMsg ( NEW_USER_MSG, Engine::SVC_NewUserMsg );
	Engine::pSVC_UpdateUserInfo = HookEngineMsg ( UPDATE_USER_INFO, Engine::SVC_UpdateUserInfo );
	Engine::pSVC_SendCvarValue = HookEngineMsg ( SEND_CVAR_VALUE, Engine::SVC_SendCvarValue );
	Engine::pSVC_SendCvarValue2 = HookEngineMsg ( SEND_CVAR_VALUE2, Engine::SVC_SendCvarValue2 );
	Engine::pSVC_Director = HookEngineMsg ( DIRECTOR, Engine::SVC_Director );
}