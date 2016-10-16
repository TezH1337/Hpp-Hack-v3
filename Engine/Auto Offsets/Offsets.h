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
		__inline DWORD GetModuleSize ( DWORD Address );

		__inline DWORD FindString ( PCHAR String, DWORD Start, DWORD End, DWORD Offset );
		__inline DWORD FindPattern ( PCHAR Pattern, DWORD PtLen, DWORD Start, DWORD End, DWORD Offset );
		__inline DWORD FindPushString ( DWORD Start, DWORD End, DWORD Address );

		__inline DWORD FarProc ( DWORD Address, DWORD LB, DWORD HB );
		__inline DWORD Absolute ( DWORD Address );

		DWORD FindClientTable ( );
		DWORD FindEngineTable ( );
		DWORD FindStudioTable ( );

		__inline DWORD FindGameConsole ( );

		DWORD FindUserMsgBase ( );
		DWORD FindSVCMessages ( );

		__inline ULONG __findmemoryclone ( const ULONG Start, const ULONG End, const ULONG Clone, UINT Size );
		__inline ULONG __findreference ( const ULONG Start, const ULONG End, const ULONG Address );

		__inline BOOL __comparemem ( const UCHAR *Buff1, const UCHAR *Buff2, UINT Size );

		BYTE HLType;

		PVOID PlayerMovePtr ( );

		bool GetModuleInfo ( );

		void Error ( bool Exit, char* Message, ... );

		__inline void GetRenderType ( );

		void ConsoleColorInitalize ( );
		void GetGameInfo ( pGameInfo_s GameInfo );
	};

	extern Offset g_Offset;
}