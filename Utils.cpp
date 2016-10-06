#include "Utils.h"

Util g_Util;

pcmd_t CommandByName ( char* szName )
{
	pcmd_t pCmd = g_Engine.pfnGetCmdList ( );

	while ( pCmd )
	{
		if ( !lstrcmpA ( pCmd->name, szName ) )
		{
			return pCmd;
		}

		pCmd = pCmd->next;
	}

	return 0;
}

void Util::MemoryCopy ( void * dst, const void * src, size_t count )
{
	_asm
	{
		mov	edi, [dst]
		mov	esi, [src]
		mov	ecx, [count]
		rep	movsb
	}
}

void Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String )
{
	PColor24 Ptr = Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	g_Engine.Con_Printf ( "%s", String );

	*Ptr = DefaultColor;
}

void Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String )
{
	PColor24 Ptr = Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String )
{
	PColor24 Ptr = Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String )
{
	PColor24 Ptr = Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String )
{
	PColor24 Ptr = Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	g_Engine.Con_Printf ( "%.1f", String );

	*Ptr = DefaultColor;
}

char* Util::ConvertTypeToRenderString ( BYTE Type )
{
	char* RenderTypeGL = "opengl";
	char* RenderTypeD3 = "d3d";
	char* RenderTypeSF = "software";

	switch ( Type )
	{
	case 1:
		return RenderTypeSF;
	case 2:
		return RenderTypeGL;
	case 3:
		return RenderTypeD3;
	default:
		return "unknown";
	}
}