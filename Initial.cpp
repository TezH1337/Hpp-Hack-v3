#include "Initial.h"

Init g_Init;

void Init::InitHack ( )
{
	if ( !g_Engine.Con_IsVisible ( ) )
	{
		g_Engine.pfnClientCmd ( "toggleconsole" );
	}

	if ( Files::g_IniRead->main->language )
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
		g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( Engine::g_Offset->HLType ) );

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
		g_Util.ConsolePrintColor ( 255, 200, 0, g_Util.ConvertTypeToRenderString ( Engine::g_Offset->HLType ) );

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
	Engine::g_Font->InitText ( LUCIDA_CONSOLE, 12, 9 );
	Engine::g_Verdana->InitText ( VERDANA, 12, 5 );

	if ( Files::g_File->FileExists ( Files::g_File->szDirFile ( FUNCTIONS_PATH ).c_str ( ) ) )
	{
		Files::g_IniRead->Functions ( );
	}

	if ( Files::g_File->FileExists ( Files::g_File->szDirFile ( MAIN_PATH ).c_str ( ) ) )
	{
		Files::g_IniRead->Main ( );	
	}
	else
	{
		Files::g_IniRead->main->language = 1;
	}

	if ( Files::g_File->FileExists ( Files::g_File->szDirFile ( VISUALS_PATH ).c_str ( ) ) )
	{
		if ( Files::g_IniRead->function->esp )
		{
			Files::g_IniRead->ESP ( );
		}
	}
}

void Init::ReloadSettings ( )
{
	if ( Files::g_File->FileExists ( Files::g_File->szDirFile ( VISUALS_PATH ).c_str ( ) ) )
	{
		if ( Files::g_IniRead->function->esp )
		{
			Files::g_IniRead->ESP ( );
		}
	}
}