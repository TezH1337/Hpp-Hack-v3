#include "ESP.h"

namespace Functions
{
	void ESP::DrawPlayer ( int Index )
	{
		if ( Engine::g_Local->Alive )
		{
			if ( ( Files::g_IniRead->esp->player == 1 && Engine::PlayerTeam[Index] == Engine::g_Local->Team ) ||
				( Files::g_IniRead->esp->player_visible_only && !Engine::g_Player[Index]->Visible ) )
			{
				return;
			}
		}

		Vector Top = Vector ( Engine::g_Player[Index]->Origin.x, Engine::g_Player[Index]->Origin.y,
			Engine::g_Player[Index]->Origin.z + Engine::g_Player[Index]->Mins.z );

		Vector Bot = Vector ( Engine::g_Player[Index]->Origin.x, Engine::g_Player[Index]->Origin.y,
			Engine::g_Player[Index]->Origin.z + Engine::g_Player[Index]->Maxs.z );

		Vector ScreenTop, ScreenBot;

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float h_duck = ScreenBot.y - ScreenTop.y;
			float h = h_duck * 0.9f;

			if ( Files::g_IniRead->esp->player_box )
			{
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
						r = 255, g = 255, b = 255, a = 255;
					}
					else
					{
						r = 100, g = 100, b = 100, a = 255;
					}
				}
				else
				{
					if ( Engine::PlayerTeam[Index] == TERRORIST )
					{
						r = Files::g_IniRead->esp->t_hide_color[0];
						g = Files::g_IniRead->esp->t_hide_color[1];
						b = Files::g_IniRead->esp->t_hide_color[2];
						a = Files::g_IniRead->esp->t_hide_color[3];
					}
					else if ( Engine::PlayerTeam[Index] == CT )
					{
						r = Files::g_IniRead->esp->ct_hide_color[0];
						g = Files::g_IniRead->esp->ct_hide_color[1];
						b = Files::g_IniRead->esp->ct_hide_color[2];
						a = Files::g_IniRead->esp->ct_hide_color[3];
					}
					else
					{
						r = 255, g = 255, b = 255, a = 255;
					}
				}

				if ( Files::g_IniRead->esp->player_box_3d )
				{
					Engine::g_Drawing->Draw3DBox ( Index,
						Files::g_IniRead->esp->player_box_linewidth, r, g, b, Files::g_IniRead->esp->player_box );
				}
				else
				{
					float w = h / 2;
					float x = ScreenTop.x - ( w / 2 );
					float y = ScreenTop.y;

					if ( Files::g_IniRead->esp->player_box_outline )
					{
						Engine::g_Drawing->DrawShadowBox ( ( int )x, ( int )y, ( int )w,
							Engine::g_Player[Index]->Ducked ? ( int )h_duck : ( int )h,
							Files::g_IniRead->esp->player_box_linewidth, r, g, b, a, Files::g_IniRead->esp->player_box );
					}
					else
					{
						Engine::g_Drawing->DrawBox ( ( int )x, ( int )y, ( int )w,
							Engine::g_Player[Index]->Ducked ? ( int )h_duck : ( int )h,
							Files::g_IniRead->esp->player_box_linewidth, r, g, b, a, Files::g_IniRead->esp->player_box );
					}
				}
			}

			if ( Files::g_IniRead->esp->player_name || Files::g_IniRead->esp->player_weapon )
			{
				BYTE r, g, b, a;

				r = Files::g_IniRead->esp->font_color[0];
				g = Files::g_IniRead->esp->font_color[1];
				b = Files::g_IniRead->esp->font_color[2];
				a = Files::g_IniRead->esp->font_color[3];

				if ( Files::g_IniRead->esp->player_name )
				{
					float y = ScreenTop.y + ( Engine::g_Player[Index]->Ducked ? h_duck - 4 : h - 4 );
					float x = ScreenTop.x;

					Engine::g_Verdana->Print ( ( int )x, ( int )y, r, g, b, a,
						Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Engine::g_Player[Index]->Info.name );
				}

				if ( Files::g_IniRead->esp->player_weapon )
				{
					float y = ScreenBot.y + ( -( ScreenBot.y - ScreenTop.y ) + 11 );
					float x = ScreenTop.x;

					model_s *Model = g_Studio.GetModelByIndex ( Engine::g_Player[Index]->Entity->curstate.weaponmodel );

					if ( Model && Model->name )
					{
						char WeaponName[64];

						int Len = lstrlen ( Model->name + 9 ) - 3;

						lstrcpynA ( WeaponName, Model->name + 9, Len );
						WeaponName[Len] = '\0';

						Engine::g_Verdana->Print ( ( int )x, ( int )y, r, g, b, a,
							Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
					}
				}
			}
		}
	}

	void ESP::HUD_Redraw ( int Index )
	{
		if ( Files::g_IniRead->esp->player && Engine::g_Player[Index]->Updated )
		{
			DrawPlayer ( Index );
		}
	}

	ESP* g_ESP = new ESP;
}