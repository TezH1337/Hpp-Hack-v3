#include "IniRead.h"

#pragma warning(disable: 4800)

namespace Files
{
	void IniRead::ESP ( )
	{
		std::string esp = g_File->szDirFile ( VISUALS_PATH ).c_str ( );

		INIREAD_INT ( enable, esp, mESP, ESP_ENABLE );
		INIREAD_INT ( player, esp, mESP, ESP_PLAYER );
		INIREAD_INT ( player_box, esp, mESP, ESP_PLAYER_BOX );
		INIREAD_INT ( player_box_style, esp, mESP, ESP_PLAYER_BOX_STYLE );
	}

	void IniRead::Main ( )
	{
		std::string main = g_File->szDirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );

		INIREAD_STRING ( reload_key, main, MAIN, MAIN_RELOAD_KEY );
	}

	void IniRead::Functions ( )
	{
		std::string function = g_File->szDirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( esp, function, FUNCTIONS, FUNCTIONS_ESP );
	}

	IniRead* g_IniRead = new IniRead;
}