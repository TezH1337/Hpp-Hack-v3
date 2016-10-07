#include "Initial.h"

Init g_Init;

void Init::InitHack ( )
{
	if ( !g_Engine.Con_IsVisible ( ) )
	{
		g_Engine.pfnClientCmd ( "toggleconsole" );
	}

	if ( g_IniRead.main.language )
	{
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
		g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tPath: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BaseDir );
		g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
	}
	else
	{
		g_Util.ConsolePrintColor ( 80, 255, 80, "Hpp Hack успешно загружен!\n\n" );

		g_Util.ConsolePrintColor ( 255, 240, 0, "Информация о игре:\n" );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tНазвание:: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.GameName );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tВерсия: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.GameVersion );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tПротокол: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.Protocol );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tПостроение: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BuildInfo.Build );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\n\t\tРендер: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( g_Offset.HLType ) );

		g_Util.ConsolePrintColor ( 255, 240, 0, "\n\nИнформация о чите:\n" );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tВерсия: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, VERSION );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tАвтор�: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, AUTHOR );
		g_Util.ConsolePrintColor ( 0, 230, 230, "\t\tПуть: " );
		g_Util.ConsolePrintColor ( 255, 200, 0, BaseDir );
		g_Util.ConsolePrintColor ( 0, 0, 0, "\n" );
	}
}

void Init::LoadSettings ( )
{
	g_Font.InitText ( LUCIDA_CONSOLE, 12, 9 );

	if ( g_File.FileExists ( g_File.szDirFile ( MAIN_PATH ).c_str ( ) ) )
	{
		g_IniRead.Main ( );
	}
	else
	{
		g_IniRead.main.language = 1;
	}
}