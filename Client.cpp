#include "Client.h"

bool FirstFrame = false;

void HUD_Frame ( double time )
{
	if ( !FirstFrame )
	{
		FirstFrame = true;
	}

	g_Client.HUD_Frame ( time );
}

void HookFunction ( )
{
	g_pClient->HUD_Frame = HUD_Frame;
}