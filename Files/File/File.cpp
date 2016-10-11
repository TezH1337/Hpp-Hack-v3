#include "File.h"
#include "io.h"

namespace Files
{
	std::string File::szDirFile ( const char* Name )
	{
		std::string szRet = BaseDir;

		return ( szRet + Name );
	}

	bool File::FileExists ( const char *FileName )
	{
		return _access ( FileName, 0 ) != -1;
	}

	int File::ReadInt ( char* Section, char* Key, int Default, char* Patch )
	{
		return GetPrivateProfileIntA ( Section, Key, Default, Patch );
	}

	char* File::IniRead ( char *FileName, char *Section, char *Key, char *Default )
	{
		char *out = new char[512];

		GetPrivateProfileStringA ( ( LPCSTR )Section, ( LPCSTR )Key, Default, out, 200, ( LPCSTR )FileName );

		return out;
	}

	int File::ReadString ( char* Section, char* Key, char* Default, char* Patch )
	{
		char cTempString[19];

		GetPrivateProfileStringA ( Section, Key, Default, cTempString, 16, Patch );

		return CharToKey ( cTempString );
	}

	int File::CharToKey ( char* Key )
	{
		PARS_STRING ( "RU", "ru", RUSSIAN );
		PARS_STRING ( "RUSSIAN", "russian", RUSSIAN );
		PARS_STRING ( "EN", "en", ENGLISH );
		PARS_STRING ( "ENGLISH", "english", ENGLISH );

		PARS_STRING ( "UP", "up", TRUE );
		PARS_STRING ( "DOWN", "down", FALSE );

		PARS_STRING ( "TAB", "tab", K_TAB );
		PARS_STRING ( "ENTER", "enter", K_ENTER );
		PARS_STRING ( "ESCAPE", "escape", K_ESCAPE );
		PARS_STRING ( "BACKSPACE", "backspace", K_BACKSPACE );
		PARS_STRING ( "UPARROW", "uparrow", K_UPARROW );
		PARS_STRING ( "DOWNARROW", "downarrow", K_DOWNARROW );
		PARS_STRING ( "LEFTARROW", "leftarrow", K_LEFTARROW );
		PARS_STRING ( "RIGHTARROW", "rightarrow", K_RIGHTARROW );

		PARS_STRING ( "[", NULL, K_BRACKET_LEFT );
		PARS_STRING ( "]", NULL, K_BRACKET_RIGHT );

		PARS_STRING ( "0", NULL, K_0 );
		PARS_STRING ( "1", NULL, K_1 );
		PARS_STRING ( "2", NULL, K_2 );
		PARS_STRING ( "3", NULL, K_3 );
		PARS_STRING ( "4", NULL, K_4 );
		PARS_STRING ( "5", NULL, K_5 );
		PARS_STRING ( "6", NULL, K_6 );
		PARS_STRING ( "7", NULL, K_7 );
		PARS_STRING ( "8", NULL, K_8 );
		PARS_STRING ( "9", NULL, K_9 );

		PARS_STRING ( ".", NULL, K_POINT );
		PARS_STRING ( ",", NULL, K_COMMA );

		PARS_STRING ( "A", "a", K_A );
		PARS_STRING ( "B", "b", K_B );
		PARS_STRING ( "C", "c", K_C );
		PARS_STRING ( "D", "d", K_D );
		PARS_STRING ( "E", "e", K_E );
		PARS_STRING ( "F", "f", K_F );
		PARS_STRING ( "G", "g", K_G );
		PARS_STRING ( "H", "h", K_H );
		PARS_STRING ( "I", "i", K_I );
		PARS_STRING ( "J", "j", K_J );
		PARS_STRING ( "K", "k", K_K );
		PARS_STRING ( "L", "l", K_L );
		PARS_STRING ( "M", "m", K_M );
		PARS_STRING ( "N", "n", K_N );
		PARS_STRING ( "O", "o", K_O );
		PARS_STRING ( "P", "p", K_P );
		PARS_STRING ( "Q", "q", K_Q );
		PARS_STRING ( "R", "r", K_R );
		PARS_STRING ( "S", "s", K_S );
		PARS_STRING ( "T", "t", K_T );
		PARS_STRING ( "U", "u", K_U );
		PARS_STRING ( "V", "v", K_V );
		PARS_STRING ( "W", "w", K_W );
		PARS_STRING ( "X", "x", K_X );
		PARS_STRING ( "Z", "z", K_Z );

		PARS_STRING ( "F1", "f1", K_F1 );
		PARS_STRING ( "F2", "f2", K_F2 );
		PARS_STRING ( "F3", "f3", K_F3 );
		PARS_STRING ( "F4", "f4", K_F4 );
		PARS_STRING ( "F5", "f5", K_F5 );
		PARS_STRING ( "F6", "f6", K_F6 );
		PARS_STRING ( "F7", "f7", K_F7 );
		PARS_STRING ( "F8", "f8", K_F8 );
		PARS_STRING ( "F9", "f9", K_F9 );
		PARS_STRING ( "F10", "f10", K_F10 );
		PARS_STRING ( "F11", "f11", K_F11 );
		PARS_STRING ( "F12", "f12", K_F12 );

		PARS_STRING ( "INSERT", "insert", K_INS );
		PARS_STRING ( "INS", "ins", K_INS );
		PARS_STRING ( "DELETE", "delete", K_DEL );
		PARS_STRING ( "DEL", "del", K_DEL );
		PARS_STRING ( "PGDN", "pgdn", K_PGDN );
		PARS_STRING ( "PGUP", "pgup", K_PGUP );
		PARS_STRING ( "HOME", "home", K_HOME );
		PARS_STRING ( "END", "end", K_END );
		PARS_STRING ( "SPACE", "space", K_SPACE );
		PARS_STRING ( "ALT", "alt", K_ALT );
		PARS_STRING ( "SHIFT", "shift", K_SHIFT );
		PARS_STRING ( "CTRL", "ctrl", K_CTRL );

		PARS_STRING ( "MWHEELDOWN", "mwheeldown", K_MWHEELDOWN );
		PARS_STRING ( "MWHEELUP", "mwheelup", K_MWHEELUP );
		PARS_STRING ( "MOUSE1", "mouse1", K_MOUSE1 );
		PARS_STRING ( "MOUSE2", "mouse2", K_MOUSE2 );
		PARS_STRING ( "MOUSE3", "mouse3", K_MOUSE3 );
		PARS_STRING ( "MOUSE4", "mouse4", K_MOUSE4 );
		PARS_STRING ( "MOUSE5", "mouse5", K_MOUSE5 );

		PARS_STRING ( "NONE", "none", NULL );

		return NULL;
	}

	File* g_File = new File;
}