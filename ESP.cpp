#include "ESP.h"

namespace Functions
{
	void ESP::DrawPlayer ( int Index )
	{
		Vector Top = Vector ( Engine::g_Player[Index]->Entity->origin.x, Engine::g_Player[Index]->Entity->origin.y,
			Engine::g_Player[Index]->Entity->origin.z + Engine::g_Player[Index]->Entity->curstate.mins.z );
		Vector Bot = Vector ( Engine::g_Player[Index]->Entity->origin.x, Engine::g_Player[Index]->Entity->origin.y,
			Engine::g_Player[Index]->Entity->origin.z + Engine::g_Player[Index]->Entity->curstate.maxs.z );
		Vector ScreenTop, ScreenBot;

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float h_duck = ( ScreenBot.y - ScreenTop.y ) * 1.05f;
			float h = h_duck * 0.87f;
			float w = h / 2;
			float x = ScreenTop.x - ( w / 2 );
			float y = ScreenTop.y;

			BYTE r, g, b, a;

			if ( Engine::g_Player[Index]->Visible )
			{
				r = 255;
				g = 0;
				b = 0;
				a = 255;
			}
			else
			{
				r = 255;
				g = 255;
				b = 0;
				a = 255;
			}

			Engine::g_Drawing->DrawBox ( ( int )x, ( int )y, ( int )w,
				Engine::g_Player[Index]->Ducked ? ( int )h_duck : ( int )h, 1, r, g, b, a );
		}
	}

	void ESP::HUD_Redraw ( int Index )
	{
		if ( Engine::g_Player[Index]->Updated )
		{
			DrawPlayer ( Index );
		}
	}

	ESP* g_ESP = new ESP;
}