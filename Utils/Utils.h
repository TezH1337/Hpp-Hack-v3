#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );
pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn );
pfnEngineMsgHook HookEngineMsg ( char *MsgName, pfnEngineMsgHook pfn );

class Util
{
public:
	char* ConvertTypeToRenderString ( BYTE Type );

	char* __fastcall native_strstr ( char *in, char *str );

	float __fastcall Interp ( float s1, float s2, float s3, float f1, float f3 );

	int __fastcall native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount );

	bool __fastcall CalcScreen ( float *pflOrigin, float *pflVecScreen );

	bool __fastcall PathFree ( Vector Input );

	void MemoryCopy ( void * dst, const void * src, size_t count );
	void MemorySet ( void *Buffer, DWORD Len, DWORD Sym );

	void __fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void __fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void __fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void __fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void __fastcall ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );

	void Parse ( BYTE MaxArray, char *String, int Number[] );
	void Parse ( BYTE MaxArray, char *String, BYTE Number[] );
};

extern Util g_Util;