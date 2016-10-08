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
			float h_duck = ScreenBot.y - ScreenTop.y;
			float h = h_duck * 0.9f;
			float w = h / 2;
			float x = ScreenTop.x - ( w / 2 );
			float y = ScreenTop.y;

			BYTE r, g, b, a;

			if ( Files::g_IniRead->esp->player_visible_check )
			{
				if ( Engine::PlayerTeam[Index] == TERRORIST && Engine::g_Player[Index]->Visible )
				{
					r = Files::g_IniRead->esp->t_vis_color[0];
					g = Files::g_IniRead->esp->t_vis_color[1];
					b = Files::g_IniRead->esp->t_vis_color[2];
					a = Files::g_IniRead->esp->t_vis_color[3];
				}
				else if ( Engine::PlayerTeam[Index] == TERRORIST )
				{
					r = Files::g_IniRead->esp->t_hide_color[0];
					g = Files::g_IniRead->esp->t_hide_color[1];
					b = Files::g_IniRead->esp->t_hide_color[2];
					a = Files::g_IniRead->esp->t_hide_color[3];
				}
				else if ( Engine::PlayerTeam[Index] == CT && Engine::g_Player[Index]->Visible )
				{
					r = Files::g_IniRead->esp->ct_vis_color[0];
					g = Files::g_IniRead->esp->ct_vis_color[1];
					b = Files::g_IniRead->esp->ct_vis_color[2];
					a = Files::g_IniRead->esp->ct_vis_color[3];
				}
				else if ( Engine::PlayerTeam[Index] == CT )
				{
					r = Files::g_IniRead->esp->ct_hide_color[0];
					g = Files::g_IniRead->esp->ct_hide_color[1];
					b = Files::g_IniRead->esp->ct_hide_color[2];
					a = Files::g_IniRead->esp->ct_hide_color[3];
				}
				else if ( Engine::g_Player[Index]->Visible )
				{
					r = 255;
					g = 255;
					b = 255;
					a = 255;
				}
				else
				{
					r = 100;
					g = 100;
					b = 100;
					a = 255;
				}
			}
			else
			{
				if ( Engine::PlayerTeam[Index] == TERRORIST )
				{
					r = 255;
					g = 50;
					b = 50;
					a = 255;
				}
				else if ( Engine::PlayerTeam[Index] == CT )
				{
					r = 50;
					g = 150;
					b = 255;
					a = 255;
				}
				else
				{
					r = 255;
					g = 255;
					b = 255;
					a = 255;
				}
			}

			if ( Files::g_IniRead->esp->player_box )
			{
				if ( Files::g_IniRead->esp->player_box_style == 1 )
				{
					Engine::g_Drawing->DrawBox ( ( int )x, ( int )y, ( int )w,
						Engine::g_Player[Index]->Ducked ? ( int )h_duck : ( int )h, 1, r, g, b, a );
				}
				else if ( Files::g_IniRead->esp->player_box_style == 2 )
				{
					Engine::g_Drawing->DrawBox2 ( ( int )x, ( int )y, ( int )w,
						Engine::g_Player[Index]->Ducked ? ( int )h_duck : ( int )h, 1, r, g, b, a );
				}
			}
		}
	}

	void ESP::HUD_Redraw ( int Index )
	{
		if ( Engine::g_Player[Index]->Updated )
		{
			if ( Files::g_IniRead->esp->player )
			{
				DrawPlayer ( Index );
			}
		}
	}

	ESP* g_ESP = new ESP;
}