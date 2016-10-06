#include "Initial.h"

Init g_Init;

void Init::InitHack ( )
{
	if ( !g_Engine.Con_IsVisible ( ) )
	{
		g_Engine.pfnClientCmd ( "toggleconsole" );
	}

	g_Util.ConsolePrintColor ( 80, 255, 80, "Hpp Hack successfully injected!\n\n" );

	g_Util.ConsolePrintColor ( 255, 240, 0, "Information about game:\n" );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tName: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.GameName );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tVersion: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.GameVersion );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tProtocol: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.Protocol );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tBuild: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.Build );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tRender: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( g_Offset.HLType ) );

	g_Util.ConsolePrintColor ( 255, 240, 0, "\n\nInformation about cheat:\n" );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tVersion: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, VERSION );
	g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tAuthor: " );
	g_Util.ConsolePrintColor ( 255, 200, 0, AUTHOR );
}