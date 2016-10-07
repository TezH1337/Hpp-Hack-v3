#include "IniRead.h"

#pragma warning(disable: 4800)

IniRead g_IniRead;

void IniRead::Main ( )
{
	std::string main = g_File.szDirFile ( MAIN_PATH ).c_str ( );

	INIREAD_STRING ( language, main, MAIN, MAIN_LANGUAGE );
}