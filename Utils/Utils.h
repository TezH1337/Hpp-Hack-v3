#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );

class Util
{
public:
	char* ConvertTypeToRenderString ( BYTE Type );

	bool CalcScreen ( float *pflOrigin, float *pflVecScreen );

	bool PathFree ( Vector Input );

	void MemoryCopy ( void * dst, const void * src, size_t count );

	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );

	void Parse ( BYTE MaxArray, char *String, int Number[] );
	void Parse ( BYTE MaxArray, char *String, BYTE Number[] );
};

extern Util g_Util;