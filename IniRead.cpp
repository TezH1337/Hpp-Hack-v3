#include "IniRead.h"

#pragma warning(disable: 4800)

namespace Files
{
	void IniRead::ESP ( )
	{
		std::string esp = g_File->szDirFile ( VISUALS_PATH ).c_str ( );
	}

	void IniRead::Main ( )
	{
		std::string main = g_File->szDirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );
	}

	void IniRead::Functions ( )
	{
		std::string function = g_File->szDirFile ( FUNCTIONS_PATH ).c_str ( );

		INIREAD_INT ( esp, function, FUNCTIONS, FUNCTIONS_ESP );
	}

	IniRead* g_IniRead = new IniRead;
}