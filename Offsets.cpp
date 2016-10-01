#include "Offsets.h"

Offset g_Offset;

void Offset::Error ( char* Message )
{
	MessageBoxA ( 0, Message, ERROR_HEADER, MB_OK | MB_ICONERROR );
	ExitProcess ( 0 );
}

void Offset::GetRenderType ( )
{
	HwDll = ( DWORD )GetModuleHandleA ( HW_DLL );
	SwDll = ( DWORD )GetModuleHandleA ( SW_DLL );
	HlMod = ( DWORD )GetModuleHandleA ( 0 );
}

DWORD Offset::GetModuleSize ( DWORD Address )
{
	return PIMAGE_NT_HEADERS ( Address + ( DWORD )PIMAGE_DOS_HEADER ( Address )->e_lfanew )->OptionalHeader.SizeOfImage;
}

bool Offset::GetModuleInfo ( )
{
	GetRenderType ( );

	if ( HwDll )
	{
		HwBase = HwDll;
	}
	else if ( SwDll )
	{
		HwBase = SwDll;
	}
	else
	{
		HwBase = HlMod;
	}

	HwSize = GetModuleSize ( HwBase );
	HwEnd = HwBase + HwSize - 1;

	HlBase = HlMod;
	HlSize = GetModuleSize ( HlBase );
	HlEnd = HlBase + HlSize - 1;

	ClBase = ( DWORD )GetModuleHandleA ( CLIENT_DLL );

	if ( ClBase )
	{
		ClSize = GetModuleSize ( ClBase );
		ClEnd = ClBase + ClSize - 1;
	}
	else
	{
		ClBase = HwBase;
		ClEnd = HwEnd;
		ClSize = HwSize;
	}

	VgBase = ( DWORD )GetModuleHandleA ( GAMEUI_DLL );

	if ( VgBase )
	{
		VgSize = GetModuleSize ( VgBase );
		VgEnd = VgBase + VgSize - 1;
	}

	return ( HwBase && ClBase && VgBase );
}

DWORD Offset::FindString ( PCHAR String, DWORD Start, DWORD End, DWORD Offset )
{
	DWORD PtLen = lstrlenA ( String );

	bool Found = false;

	for ( DWORD i = Start; i < End - PtLen; ++i )
	{
		Found = true;

		for ( DWORD idx = 0; idx < PtLen; ++idx )
		{
			if ( String[idx] != *( PCHAR )( i + idx ) )
			{
				Found = false;

				break;
			}
		}

		if ( Found )
		{
			return i + Offset;
		}
	}

	return 0;
}

DWORD Offset::FindPattern ( PCHAR Pattern, DWORD PtLen, DWORD Start, DWORD End, DWORD Offset )
{
	bool Found = false;

	for ( DWORD i = Start; i < End - PtLen; ++i )
	{
		Found = true;

		for ( DWORD idx = 0; idx < PtLen; ++idx )
		{
			if ( Pattern[idx] != *( PCHAR )( i + idx ) )
			{
				Found = false;

				break;
			}
		}

		if ( Found )
		{
			return i + Offset;
		}
	}

	return 0;
}

DWORD Offset::FindPushString ( DWORD Start, DWORD End, DWORD Address )
{
	char Pattern[5] =
	{
		0x68,
		0x00,
		0x00,
		0x00,
		0x00
	};

	*( PDWORD )&Pattern[1] = Address;

	return FindPattern ( Pattern, sizeof ( Pattern ), Start, End, 0 );
}

DWORD Offset::FarProc ( DWORD Address, DWORD LB, DWORD HB )
{
	return ( ( Address < LB ) || ( Address > HB ) );
}

DWORD Offset::FindClientTable ( )
{
	DWORD ClientPattern = FindString ( CLIENT_PATTERN, HwBase, HwEnd, 0 );

	BYTE ClientOffset[2] =
	{
		0x10,
		0x13
	};

	if ( ClientPattern )
	{
		for ( BYTE i = 0; i < sizeof ( ClientOffset ); ++i )
		{
			DWORD ClientTablePtr = *( PDWORD )( FindPushString ( HwBase, HwEnd, ClientPattern ) + ClientOffset[i] );

			if ( !FarProc ( ClientTablePtr, HwBase, HwEnd ) &&
				!IsBadReadPtr ( ( PVOID )ClientTablePtr, sizeof ( cl_clientfunc_t ) ) )
			{
				return ClientTablePtr;
			}
		}
	}

	return 0;
}

DWORD Offset::FindEngineTable ( )
{
	BYTE EngineOffset[7] =
	{
		0x22,
		0x23,
		0x1C,
		0x1D,
		0x37,
		0x2D,
		0x0E
	};

	for ( BYTE bOffset = 0; bOffset < sizeof ( EngineOffset ); ++bOffset )
	{
		PVOID EnginePtr = ( cl_enginefunc_t* )*( PDWORD )( ( DWORD )g_pClient->Initialize + EngineOffset[bOffset] );

		if ( FarProc ( ( DWORD )EnginePtr, HwBase, HwEnd ) &&
			FarProc ( ( DWORD )EnginePtr, HlBase, HlEnd ) && !FarProc ( ( DWORD )EnginePtr, ClBase, ClEnd ) )
		{
			return ( DWORD )EnginePtr;
		}
	}

	return 0;
}

DWORD Offset::FindStudioTable ( )
{
	DWORD StudioPattern = FindString ( STUDIO_PATTERN, HwBase, HwEnd, 0 );

	if ( StudioPattern )
	{
		DWORD StudioTablePtr = *( PDWORD )( FindPushString ( HwBase, HwEnd, StudioPattern ) - 0x14 );

		if ( !FarProc ( StudioTablePtr, HwBase, HwEnd ) )
		{
			return StudioTablePtr;
		}
		else
		{
			goto find_next;
		}
	}

	return 0;

find_next:

	DWORD StudioTablePtr = *( DWORD* )( ( DWORD )g_pClient->HUD_GetStudioModelInterface + 0x30 );

	if ( FarProc ( StudioTablePtr, HwBase, HwEnd ) && FarProc ( StudioTablePtr, HlBase, HlEnd ) &&
		FarProc ( StudioTablePtr, ClBase, ClEnd ) )
	{
		StudioTablePtr = *( DWORD* )( ( DWORD )g_pClient->HUD_GetStudioModelInterface + 0x1A );

		if ( FarProc ( ( DWORD )StudioTablePtr, ClBase, ClEnd ) )
		{
			StudioTablePtr = *( DWORD* )( ( DWORD )g_pClient->HUD_GetStudioModelInterface + 0x20 );

			if ( FarProc ( StudioTablePtr, ClBase, ClEnd ) )
			{
				return 0;
			}
		}
	}

	return StudioTablePtr;
}