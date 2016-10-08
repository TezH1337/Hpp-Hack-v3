#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );

class Util
{
public:
	char* ConvertTypeToRenderString ( BYTE Type );

	bool CalcScreen ( float *pflOrigin, float *pflVecScreen );

	void MemoryCopy ( void * dst, const void * src, size_t count );

	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String );
	void ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String );
};

extern Util g_Util;