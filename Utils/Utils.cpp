#include "Utils.h"

#pragma warning(disable: 4996)

Util g_Util;

pcmd_t CommandByName ( char* szName )
{
	pcmd_t pCmd = Engine::g_Engine.pfnGetCmdList ( );

	while ( pCmd )
	{
		if ( !lstrcmp ( pCmd->name, szName ) )
		{
			return pCmd;
		}

		pCmd = pCmd->next;
	}

	return 0;
}

PUserMsg UserMsgByName ( char* szMsgName )
{
	PUserMsg Ptr = Engine::g_pUserMsgBase;

	while ( Ptr->next )
	{
		if ( !lstrcmp ( Ptr->name, szMsgName ) )
		{
			return Ptr;
		}

		Ptr = Ptr->next;
	}

	Ptr->pfn = 0;

	return Ptr;
}

pfnUserMsgHook HookUserMsg ( char *szMsgName, pfnUserMsgHook pfn )
{
	pfnUserMsgHook Original = nullptr;
	PUserMsg Ptr = UserMsgByName ( szMsgName );

	if ( Ptr->pfn != 0 )
	{
		Original = Ptr->pfn;
		Ptr->pfn = pfn;
	}
	else
	{
		Engine::g_Offset.Error ( false, USERMSG_ERROR, szMsgName );
	}

	return Original;
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

void Util::MemorySet ( void *Buffer, DWORD Len, DWORD Sym )
{
	_asm
	{
		pushad
		mov edi, [Buffer]
		mov ecx, [Len]
		mov eax, [Sym]
		rep stosb
		popad
	}
}


void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, char* String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%s", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, DWORD String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, BYTE String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, int String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%d", String );

	*Ptr = DefaultColor;
}

void _fastcall Util::ConsolePrintColor ( BYTE R, BYTE G, BYTE B, float String )
{
	PColor24 Ptr = Engine::Console_TextColor;
	TColor24 DefaultColor = *Ptr;

	Ptr->R = R;
	Ptr->G = G;
	Ptr->B = B;

	Engine::g_Engine.Con_Printf ( "%.1f", String );

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

bool _fastcall Util::CalcScreen ( float *pflOrigin, float *pflVecScreen )
{
	int Result = Engine::g_Engine.pTriAPI->WorldToScreen ( pflOrigin, pflVecScreen );

	if ( pflVecScreen[0] < 1 && pflVecScreen[1] < 1 && pflVecScreen[0] > -1 && pflVecScreen[1] > -1 && !Result )
	{
		pflVecScreen[0] = pflVecScreen[0] * ( Engine::g_Screen.iWidth / 2 ) + ( Engine::g_Screen.iWidth / 2 );
		pflVecScreen[1] = -pflVecScreen[1] * ( Engine::g_Screen.iHeight / 2 ) + ( Engine::g_Screen.iHeight / 2 );

		return true;
	}

	return false;
}

bool _fastcall Util::PathFree ( Vector Input )
{
	pmtrace_t *Trace = Engine::g_Engine.PM_TraceLine ( Engine::g_Local.ViewOrg, Input, 0, 2, -1 );

	return ( Trace->fraction >= 1.0f );
}

void Util::Parse ( BYTE MaxArray, char *String, int Number[] )
{
	char* Parsing = strtok ( String, "," );

	BYTE i = 0;

	while ( Parsing && i <= ( MaxArray ) )
	{
		Number[i] = atoi ( Parsing );
		Parsing = strtok ( 0, "," );
		++i;
	}
}

void Util::Parse ( BYTE MaxArray, char *String, BYTE Number[] )
{
	char* Parsing = strtok ( String, "," );

	BYTE i = 0;

	while ( Parsing && i <= ( MaxArray ) )
	{
		Number[i] = atoi ( Parsing );
		Parsing = strtok ( 0, "," );
		++i;
	}
}

int _fastcall Util::native_strcmp ( char const* _Str1, char const* _Str2, size_t MaxCount )
{
	if ( !MaxCount )
	{
		return 0;
	}

	while ( --MaxCount && *_Str1 && *_Str1 == *_Str2 )
	{
		++_Str1;
		++_Str2;
	}

	return *( BYTE * )_Str1 - *( BYTE * )_Str2;
}

char* _fastcall Util::native_strstr ( char *in, char *str )
{
	char c = *str++;

	if ( !c )
	{
		return ( char * )in;
	}

	size_t len = lstrlenA ( str );

	do
	{
		char sc;

		do
		{
			sc = *in++;

			if ( !sc )
			{
				return ( char * )0;
			}
		} while ( sc != c );
	} while ( native_strcmp ( in, str, len ) );

	return ( char * )( in - 1 );
}