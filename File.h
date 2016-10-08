#pragma once

#include "Main.h"

namespace Files
{
	class File
	{
	public:
		std::string szDirFile ( const char* Name );

		char* IniRead ( char *FileName, char *Section, char *Key, char *Default );

		int ReadInt ( char* Section, char* Key, int Default, char* Patch );
		int ReadString ( char* Section, char* Key, char* Default, char* Patch );

		int CharToKey ( char* Key );

		bool FileExists ( const char *FileName );
	};

	extern File* g_File;
}