#include "ESP.h"

namespace Functions
{
	int EntityIndex;

	void ESP::DrawPlayer ( int Index )
	{
		if ( Engine::g_Local->Alive && ( ( Files::g_IniRead->esp->player == 1 && Engine::PlayerTeam[Index] == Engine::g_Local->Team ) ||
			( Files::g_IniRead->esp->player_visible_only && !Engine::g_Player[Index]->Visible ) ) )
		{
			return;
		}

		Vector Top = Vector ( Engine::g_Player[Index]->Origin.x, Engine::g_Player[Index]->Origin.y,
			Engine::g_Player[Index]->Origin.z + Engine::g_Player[Index]->Mins.z );

		Vector Bot = Vector ( Engine::g_Player[Index]->Origin.x, Engine::g_Player[Index]->Origin.y,
			Engine::g_Player[Index]->Origin.z + Engine::g_Player[Index]->Maxs.z );

		float ScreenTop[2], ScreenBot[2];

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float h_duck = ScreenBot[1] - ScreenTop[1];
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
					float x = ScreenTop[0] - ( w / 2 );
					float y = ScreenTop[1];

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
				BYTE r = Files::g_IniRead->esp->font_color[0];
				BYTE g = Files::g_IniRead->esp->font_color[1];
				BYTE b = Files::g_IniRead->esp->font_color[2];
				BYTE a = Files::g_IniRead->esp->font_color[3];

				if ( Files::g_IniRead->esp->player_name )
				{
					float y = ScreenTop[1] + ( Engine::g_Player[Index]->Ducked ? h_duck - 4 : h - 4 );
					float x = ScreenTop[0];

					Engine::g_Verdana->Print ( ( int )x, ( int )y, r, g, b, a,
						Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Engine::g_Player[Index]->Info.name );
				}

				if ( Files::g_IniRead->esp->player_weapon )
				{
					int Cstrike_SequenceInfo[] =
					{
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 1, 2, 0, 1, 2, 0, 1, 2, 0,
						1, 2, 0, 1, 1, 2, 0, 1, 1, 2,
						0, 1, 2, 0, 1, 2, 0, 1, 2, 0,
						1, 2, 0, 1, 2, 0, 1, 2, 0, 1,
						2, 0, 1, 2, 0, 0, 0, 4, 0, 4,
						0, 5, 0, 5, 0, 0, 1, 1, 2, 0,
						1, 1, 2, 0, 1, 0, 1, 0, 1, 2,
						0, 1, 2, 3, 3, 3, 3, 3, 3, 3,
						3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
						3
					};

					char* Sequence;

					int type = Cstrike_SequenceInfo[Engine::g_Player[Index]->Sequence];

					float y = ScreenBot[1] + ( -( ScreenBot[1] - ScreenTop[1] ) + 11 );
					float x = ScreenTop[0];

					if ( type == 2 )
					{
						Sequence = "reloading";

						Engine::g_Verdana->Print ( ( int )x, ( int )y + 11, 255, 100, 100, 255,
							Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Sequence );
					}

					if ( type == 5 )
					{
						Sequence = "planting c4";

						Engine::g_Verdana->Print ( ( int )x, ( int )y + 11, 255, 100, 100, 255,
							Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Sequence );
					}

					model_s *Model = g_Studio.GetModelByIndex ( Engine::g_Player[Index]->WeaponModel );

					if ( Model && Model->name )
					{
						char WeaponName[64];

						int Len = lstrlen ( Model->name + 9 ) - 3;

						lstrcpyn ( WeaponName, Model->name + 9, Len );
						WeaponName[Len] = '\0';

						Engine::g_Verdana->Print ( ( int )x, ( int )y, r, g, b, a,
							Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
					}
				}
			}
		}
	}

	void ESP::AddEntity ( char* Name, int Important, Vector Origin, BYTE Type )
	{
		if ( EntityIndex < MAX_ENTITY )
		{
			lstrcpy ( entity[EntityIndex].Name, Name );

			entity[EntityIndex].Important = Important;
			entity[EntityIndex].Origin = Origin;
			entity[EntityIndex].Type = Type;

			++EntityIndex;
		}
		else
		{
			ClearEntity ( );
		}
	}

	void ESP::ClearEntity ( )
	{
		for ( int i = 0; i < EntityIndex; ++i )
		{
			g_Util.MemorySet ( &entity[i].Name[0], 64, 0 );

			entity[i].Important = 0;
			entity[i].Origin = Vector ( 0, 0, 0 );
			entity[i].Type = 0;
		}

		EntityIndex = 0;
	}

	void ESP::HUD_AddEntity ( struct cl_entity_s *Entity )
	{
		if ( !Entity->player && Entity->model && Entity->model->name && ( Files::g_IniRead->esp->world_weapons ) )
		{
			int iImportant = 0;

			if ( g_Util.native_strstr ( Entity->model->name, "w_" ) )
			{
				char Name[64];

				int Len = lstrlen ( Entity->model->name + 7 ) - 3;

				lstrcpyn ( Name, Entity->model->name + 7, Len );

				Name[Len] = '\0';
		
				AddEntity ( Name, iImportant, Entity->origin, 1 );
			}
		}
	}

	void ESP::DrawWorld ( )
	{
		BYTE r = Files::g_IniRead->esp->font_color[0];
		BYTE g = Files::g_IniRead->esp->font_color[1];
		BYTE b = Files::g_IniRead->esp->font_color[2];
		BYTE a = Files::g_IniRead->esp->font_color[3];

		for ( int i = 0; i < EntityIndex; ++i )
		{
			float EntityScreen[2] = { 0 };

			if ( g_Util.CalcScreen ( entity[i].Origin, EntityScreen ) )
			{
				if ( g_Util.native_strstr ( entity[i].Name, "usp" ) )
				{
					WEAPON_PARS ( "usp" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "glock18" ) )
				{
					WEAPON_PARS ( "glock18" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "deagle" ) )
				{
					WEAPON_PARS ( "deagle" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "p228" ) )
				{
					WEAPON_PARS ( "p228" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "elite" ) )
				{
					WEAPON_PARS ( "elite" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "fiveseven" ) )
				{
					WEAPON_PARS ( "fiveseven" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "m3" ) )
				{
					WEAPON_PARS ( "m3" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "xm1014" ) )
				{
					WEAPON_PARS ( "xm1014" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "mp5" ) )
				{
					WEAPON_PARS ( "mp5" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "tmp" ) )
				{
					WEAPON_PARS ( "tmp" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "p90" ) )
				{
					WEAPON_PARS ( "p90" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "mac10" ) )
				{
					WEAPON_PARS ( "mac10" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "ump45" ) )
				{
					WEAPON_PARS ( "ump45" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "famas" ) )
				{
					WEAPON_PARS ( "famas" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "sg552" ) )
				{
					WEAPON_PARS ( "sg552" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "ak47" ) )
				{
					WEAPON_PARS ( "ak47" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "m4a1" ) )
				{
					WEAPON_PARS ( "m4a1" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "aug" ) )
				{
					WEAPON_PARS ( "aug" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "scout" ) )
				{
					WEAPON_PARS ( "scout" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "awp" ) )
				{
					WEAPON_PARS ( "awp" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "g3sg1" ) )
				{
					WEAPON_PARS ( "g3sg1" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "sg550" ) )
				{
					WEAPON_PARS ( "sg550" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "galil" ) )
				{
					WEAPON_PARS ( "galil" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "m249" ) )
				{
					WEAPON_PARS ( "m249" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "shield" ) )
				{
					WEAPON_PARS ( "shield" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "backpack" ) )
				{
					WEAPON_PARS ( "backpack" );
				}
				else if ( g_Util.native_strstr ( entity[i].Name, "thighpack" ) )
				{
					WEAPON_PARS ( "thighpack" );
				}
				else
				{
					Engine::g_Drawing->DrawBox ( ( int )( EntityScreen[0] - 2 ), ( int )EntityScreen[1], 3 + 2, 3 + 2, 1, 0, 0, 0, 255, 1 );
					Engine::g_Drawing->FillArea ( ( int )( EntityScreen[0] - 1 ), ( int )( EntityScreen[1] + 1 ), 3, 3, 255, 100, 0, 255, 1 );

					Engine::g_Verdana->Print ( ( int )EntityScreen[0], ( int )( EntityScreen[1] + 14 ), r,
						g, b, a, Files::g_IniRead->esp->font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, entity[i].Name );
				}
			}
		}

		ClearEntity ( );
	}

	void ESP::HUD_Redraw ( int Index )
	{
		if ( Files::g_IniRead->esp->player && Engine::g_Player[Index]->Updated )
		{
			DrawPlayer ( Index );
		}

		if ( Files::g_IniRead->esp->world_weapons )
		{
			DrawWorld ( );
		}
	}

	ESP* g_ESP = new ESP;
	entity_s entity[MAX_ENTITY];
}