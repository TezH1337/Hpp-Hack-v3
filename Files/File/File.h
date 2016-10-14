#pragma once

#include "Main.h"

namespace Files
{
	class File
	{
	public:
		//File path
		std::string DirFile ( const char* Name );
		//Read key of .ini file
		char* IniRead ( char *FileName, char *Section, char *Key, char *Default );
		//Read key of type int of .ini file
		int ReadInt ( char* Section, char* Key, int Default, char* Patch );
		//Read string of .ini file
		int ReadString ( char* Section, char* Key, char* Default, char* Patch );
		//Convert string to integer value
		int CharToKey ( char* Key );
		//Checking File exists
		bool FileExists ( const char *FileName );
	};

	extern File g_File;
}