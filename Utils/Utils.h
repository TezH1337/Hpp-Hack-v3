#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );

class Util
{
public:
	char* ConvertTypeToRenderString ( BYTE Type );

	char* _fastcall native_strstr ( char *in, char *str );

	int _fastcall native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount );

	bool _fastcall CalcScreen ( float *pflOrigin, float *pflVecScreen );

	bool _fastcall PathFree ( Vector Input );

	void MemoryCopy ( void * dst, const void * src, size_t count );
	void MemorySet ( void *Buffer, DWORD Len, DWORD Sym );

	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void _fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );

	void Parse ( BYTE MaxArray, char *String, int Number[] );
	void Parse ( BYTE MaxArray, char *String, BYTE Number[] );
};

extern Util g_Util;