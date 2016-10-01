#pragma once

#include "Main.h"

class Offset
{
private:

	DWORD HwDll, SwDll, HlMod;
	DWORD HwBase, HwSize, HwEnd;
	DWORD ClBase, ClSize, ClEnd;
	DWORD HlBase, HlSize, HlEnd;
	DWORD VgBase, VgSize, VgEnd;

public:

	DWORD GetModuleSize ( DWORD Address );

	DWORD FindString ( PCHAR String, DWORD Start, DWORD End, DWORD Offset );
	DWORD FindPattern ( PCHAR Pattern, DWORD PtLen, DWORD Start, DWORD End, DWORD Offset );
	DWORD FindPushString ( DWORD Start, DWORD End, DWORD Address );

	DWORD FarProc ( DWORD Address, DWORD LB, DWORD HB );

	DWORD FindClientTable ( );
	DWORD FindEngineTable ( );
	DWORD FindStudioTable ( );

	bool GetModuleInfo ( );

	void Error ( char* Message, bool Exit );

	void GetRenderType ( );
};

extern Offset g_Offset;