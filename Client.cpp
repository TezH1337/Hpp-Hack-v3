#include "Client.h"

GameInfo_t BuildInfo;

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		g_Screen.iSize = sizeof ( SCREENINFO );

		g_Offset.HLType = g_Studio.IsHardware ( ) + 1;

		g_Offset.ConsoleColorInitalize ( );
		g_Offset.GetGameInfo ( &BuildInfo );

		FirstFrame = true;
	}

	g_Engine.pfnGetScreenInfo ( &g_Screen );
	g_Client.HUD_Frame ( time );
}

void HookFunction ( )
{
	g_pClient->HUD_Frame = HUD_Frame;
}