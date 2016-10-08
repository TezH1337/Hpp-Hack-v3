#include "IniRead.h"

#pragma warning(disable: 4800)

namespace Files
{
	void IniRead::Main ( )
	{
		std::string main = g_File->szDirFile ( MAIN_PATH ).c_str ( );

		INIREAD_STRING (language, main, MAIN, MAIN_LANGUAGE );
	}

	IniRead* g_IniRead = new IniRead;
}