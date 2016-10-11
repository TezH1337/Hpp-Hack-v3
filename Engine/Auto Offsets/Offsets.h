#pragma once

#include "Main.h"

namespace Engine
{
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
		DWORD Absolute ( DWORD Address );

		DWORD FindClientTable ( );
		DWORD FindEngineTable ( );
		DWORD FindStudioTable ( );
		DWORD FindGameConsole ( );
		DWORD FindUserMsgBase ( );

		ULONG __findmemoryclone ( const ULONG Start, const ULONG End, const ULONG Clone, UINT Size );
		ULONG __findreference ( const ULONG Start, const ULONG End, const ULONG Address );

		BOOL __comparemem ( const UCHAR *Buff1, const UCHAR *Buff2, UINT Size );

		BYTE HLType;

		PVOID PlayerMovePtr ( );

		bool GetModuleInfo ( );

		void Error ( bool Exit, char* Message, ... );

		void GetRenderType ( );

		void ConsoleColorInitalize ( );
		void GetGameInfo ( pGameInfo_s GameInfo );
	};

	extern Offset* g_Offset;
}