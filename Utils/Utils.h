#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );

class Util
{
public:
	char* ConvertTypeToRenderString ( BYTE Type );

	char* native_strstr ( char *in, char *str );

	int native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount );

	bool CalcScreen ( float *pflOrigin, float *pflVecScreen );

	bool PathFree ( Vector Input );

	void MemoryCopy ( void * dst, const void * src, size_t count );
	void MemorySet ( void *Buffer, DWORD Len, DWORD Sym );

	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );

	void Parse ( BYTE MaxArray, char *String, int Number[] );
	void Parse ( BYTE MaxArray, char *String, BYTE Number[] );
};

extern Util g_Util;