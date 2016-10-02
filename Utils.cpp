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