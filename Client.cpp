#include "Client.h"

GameInfo_t BuildInfo;

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		g_Screen.iSize = sizeof ( SCREENINFO );

		Engine::g_Offset->HLType = g_Studio.IsHardware ( ) + 1;

		Engine::g_Local->ppmove = ( playermove_t* )Engine::g_Offset->PlayerMovePtr ( );

		Engine::g_Offset->ConsoleColorInitalize ( );
		Engine::g_Offset->GetGameInfo ( &BuildInfo );

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
	}
}

void HookFunction ( )
{
	g_pClient->HUD_Frame = HUD_Frame;
	g_pClient->HUD_Redraw = HUD_Redraw;
}