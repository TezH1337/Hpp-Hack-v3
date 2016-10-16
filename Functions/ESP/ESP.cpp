#include "ESP.h"

namespace Functions
{
	void ESP::DrawPlayer ( struct cl_entity_s *Entity, int Index )
	{
		if ( Engine::g_Local.Alive && ( ( Files::g_IniRead.esp.player == 1 && Engine::PlayerTeam[Index] == Engine::g_Local.Team ) ||
			( Files::g_IniRead.esp.player_visible_only && !Engine::g_Player[Index].Visible ) ) )
		{
			return;
		}

		Vector Top = Vector ( Entity->origin.x, Entity->origin.y, Entity->origin.z + Entity->curstate.mins.z );
		Vector Bot = Vector ( Entity->origin.x, Entity->origin.y, Entity->origin.z + Entity->curstate.maxs.z );

		float ScreenTop[2], ScreenBot[2];

		if ( g_Util.CalcScreen ( Top, ScreenTop ) && g_Util.CalcScreen ( Bot, ScreenBot ) )
		{
			float h = Engine::g_Player[Index].Ducked ? ScreenBot[1] - ScreenTop[1] : ( ScreenBot[1] - ScreenTop[1] ) * 0.9f;

			if ( Files::g_IniRead.esp.player_box )
			{
				BYTE r, g, b;

				if ( Files::g_IniRead.esp.player_visible_check )
				{
					if ( Engine::PlayerTeam[Index] == TERRORIST && Engine::g_Player[Index].Visible )
					{
						r = Files::g_IniRead.esp.t_vis_color[0];
						g = Files::g_IniRead.esp.t_vis_color[1];
						b = Files::g_IniRead.esp.t_vis_color[2];
					}
					else if ( Engine::PlayerTeam[Index] == TERRORIST )
					{
						r = Files::g_IniRead.esp.t_hide_color[0];
						g = Files::g_IniRead.esp.t_hide_color[1];
						b = Files::g_IniRead.esp.t_hide_color[2];
					}
					else if ( Engine::PlayerTeam[Index] == CT && Engine::g_Player[Index].Visible )
					{
						r = Files::g_IniRead.esp.ct_vis_color[0];
						g = Files::g_IniRead.esp.ct_vis_color[1];
						b = Files::g_IniRead.esp.ct_vis_color[2];
					}
					else if ( Engine::PlayerTeam[Index] == CT )
					{
						r = Files::g_IniRead.esp.ct_hide_color[0];
						g = Files::g_IniRead.esp.ct_hide_color[1];
						b = Files::g_IniRead.esp.ct_hide_color[2];
					}
					else if ( Engine::g_Player[Index].Visible )
					{
						r = 255, g = 255, b = 255;
					}
					else
					{
						r = 100, g = 100, b = 100;
					}
				}
				else
				{
					if ( Engine::PlayerTeam[Index] == TERRORIST )
					{
						r = Files::g_IniRead.esp.t_hide_color[0];
						g = Files::g_IniRead.esp.t_hide_color[1];
						b = Files::g_IniRead.esp.t_hide_color[2];
					}
					else if ( Engine::PlayerTeam[Index] == CT )
					{
						r = Files::g_IniRead.esp.ct_hide_color[0];
						g = Files::g_IniRead.esp.ct_hide_color[1];
						b = Files::g_IniRead.esp.ct_hide_color[2];
					}
					else
					{
						r = 255, g = 255, b = 255;
					}
				}

				if ( Files::g_IniRead.esp.player_box_3d )
				{
					Engine::g_Drawing.Draw3DBox ( Entity, Index, Files::g_IniRead.esp.player_box_linewidth,
						r, g, b, Files::g_IniRead.esp.player_box );
				}
				else
				{
					float w = h * 0.5f;
					float x = ScreenTop[0] - ( w * 0.5f );

					Files::g_IniRead.esp.player_box_outline ?

						Engine::g_Drawing.DrawShadowBox ( ( int )x, ( int )ScreenTop[1], ( int )w, ( int )h,
							Files::g_IniRead.esp.player_box_linewidth, r, g, b, 255, Files::g_IniRead.esp.player_box ) :

						Engine::g_Drawing.DrawBox ( ( int )x, ( int )ScreenTop[1], ( int )w, ( int )h,
							Files::g_IniRead.esp.player_box_linewidth, r, g, b, 255, Files::g_IniRead.esp.player_box );
				}
			}

			if ( Files::g_IniRead.esp.player_name || Files::g_IniRead.esp.player_weapon )
			{
				BYTE *r = &Files::g_IniRead.esp.font_color[0];
				BYTE *g = &Files::g_IniRead.esp.font_color[1];
				BYTE *b = &Files::g_IniRead.esp.font_color[2];

				if ( Files::g_IniRead.esp.player_name )
				{
					float y = h - 4 + ScreenTop[1];

					Engine::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, *r, *g, *b, 255,
						Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Engine::g_Player[Index].Info.name );
				}

				if ( Files::g_IniRead.esp.player_weapon )
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

					int Type = Cstrike_SequenceInfo[Entity->curstate.sequence];

					float y = ScreenBot[1] + ( 11 - ( ScreenBot[1] - ScreenTop[1] ) );

					switch ( Type )
					{
					case 2:
						Sequence = SEQUENCE_RELOADING;

						Engine::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y + 11, 255, 100, 100, 255,
							Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Sequence );

						break;

					case 5:
						Sequence = SEQUENCE_PLANTING;

						Engine::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y + 11, 255, 100, 100, 255,
							Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, Sequence );

						break;
					}

					model_s *Model = Engine::g_Studio.GetModelByIndex ( Entity->curstate.weaponmodel );

					if ( Model->name )
					{
						char WeaponName[64];

						int Len = lstrlen ( Model->name + 9 ) - 3;

						lstrcpyn ( WeaponName, Model->name + 9, Len );
						WeaponName[Len] = '\0';

						Engine::g_Verdana.Print ( ( int )ScreenTop[0], ( int )y, *r, *g, *b, 255,
							Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, WeaponName );
					}
				}
			}
		}
	}

	void ESP::AddEntity ( char* Name, int Important, Vector Origin, BYTE Type )
	{
		if ( g_ESP.EntityIndex < MAX_ENTITY )
		{
			lstrcpy ( entity[g_ESP.EntityIndex].Name, Name );

			entity[g_ESP.EntityIndex].Important = Important;
			entity[g_ESP.EntityIndex].Origin = Origin;
			entity[g_ESP.EntityIndex].Type = Type;

			++g_ESP.EntityIndex;
		}
		else
		{
			ClearEntity ( );
		}
	}

	void ESP::ClearEntity ( )
	{
		for ( int i = 0; i < g_ESP.EntityIndex; ++i )
		{
			g_Util.MemorySet ( &entity[i].Name[0], 64, 0 );

			entity[i].Important = 0;
			entity[i].Origin = Vector ( 0, 0, 0 );
			entity[i].Type = 0;
		}

		g_ESP.EntityIndex = 0;
	}

	void ESP::HUD_AddEntity ( struct cl_entity_s *Entity )
	{
		if ( Entity->model->name && ( Files::g_IniRead.esp.world_weapons || Files::g_IniRead.esp.world_nades ) )
		{
			int Important = 0;

			if ( g_Util.native_strstr ( Entity->model->name, "w_" ) )
			{
				char Name[64];

				int Len = lstrlen ( Entity->model->name + 7 ) - 3;

				lstrcpyn ( Name, Entity->model->name + 7, Len );

				Name[Len] = '\0';

				if ( g_Util.native_strstr ( Entity->model->name, HEGREN ) )
				{
					Important = 1;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else if ( g_Util.native_strstr ( Entity->model->name, FLASH ) )
				{
					Important = 2;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else if ( g_Util.native_strstr ( Entity->model->name, SMOKE ) )
				{
					Important = 3;

					AddEntity ( Name, Important, Entity->origin, 3 );
				}
				else
				{
					if ( Files::g_IniRead.esp.world_weapons )
					{
						AddEntity ( Name, Important, Entity->origin, 1 );
					}
				}
			}
		}

		if ( Entity->model->name && Files::g_IniRead.esp.world_sprites )
		{
			if ( !g_Util.native_strstr ( Entity->model->name, "w_" ) && g_Util.native_strstr ( Entity->model->name, ".spr" ) )
			{
				AddEntity ( 0, 0, Entity->origin, 2 );
			}
		}
	}

	void ESP::DrawWorld ( )
	{
		BYTE *r = &Files::g_IniRead.esp.font_color[0];
		BYTE *g = &Files::g_IniRead.esp.font_color[1];
		BYTE *b = &Files::g_IniRead.esp.font_color[2];

		for ( int i = 0; i < g_ESP.EntityIndex; ++i )
		{
			float EntityScreen[2];

			if ( g_Util.CalcScreen ( entity[i].Origin, EntityScreen ) && entity[i].Origin.x != 0 )
			{
				float uppt[] = { entity[i].Origin.x - Engine::g_Local.ViewOrg.x,
					entity[i].Origin.y - Engine::g_Local.ViewOrg.y, entity[i].Origin.z - Engine::g_Local.ViewOrg.z };

				float l = sqrt ( VectorLengthSquared ( uppt ) );

				l = max ( 100, l );

				if ( entity[i].Type == 1 && Files::g_IniRead.esp.world_weapons )
				{
					if ( g_Util.native_strstr ( entity[i].Name, USP ) )
					{
						WEAPON_PARS ( USP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, GLOCK18 ) )
					{
						WEAPON_PARS ( GLOCK18 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, DEAGLE ) )
					{
						WEAPON_PARS ( DEAGLE );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, P228 ) )
					{
						WEAPON_PARS ( P228 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, ELITE ) )
					{
						WEAPON_PARS ( ELITE );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FIVESEVEN ) )
					{
						WEAPON_PARS ( FIVESEVEN );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M3 ) )
					{
						WEAPON_PARS ( M3 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, XM1014 ) )
					{
						WEAPON_PARS ( XM1014 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, MP5 ) )
					{
						WEAPON_PARS ( MP5 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, TMP ) )
					{
						WEAPON_PARS ( TMP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, P90 ) )
					{
						WEAPON_PARS ( P90 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, MAC10 ) )
					{
						WEAPON_PARS ( MAC10 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, UMP45 ) )
					{
						WEAPON_PARS ( UMP45 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FAMAS ) )
					{
						WEAPON_PARS ( FAMAS );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SG552 ) )
					{
						WEAPON_PARS ( SG552 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AK47 ) )
					{
						WEAPON_PARS ( AK47 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M4A1 ) )
					{
						WEAPON_PARS ( M4A1 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AUG ) )
					{
						WEAPON_PARS ( AUG );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SCOUT ) )
					{
						WEAPON_PARS ( SCOUT );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, AWP ) )
					{
						WEAPON_PARS ( AWP );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, G3SG1 ) )
					{
						WEAPON_PARS ( G3SG1 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SG550 ) )
					{
						WEAPON_PARS ( SG550 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, GALIL ) )
					{
						WEAPON_PARS ( GALIL );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, M249 ) )
					{
						WEAPON_PARS ( M249 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SHIELD ) )
					{
						WEAPON_PARS ( SHIELD );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, BACKPACK ) )
					{
						WEAPON_PARS ( BACKPACK );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, THIGHPACK ) )
					{
						WEAPON_PARS ( THIGHPACK );
					}
					else
					{
						Engine::g_Drawing.DrawBox ( ( int )( EntityScreen[0] - 2 ), 
							( int )EntityScreen[1], 5, 5, 1, 0, 0, 0, 255, 1 );

						Engine::g_Drawing.FillArea ( ( int )( EntityScreen[0] - 1 ), 
							( int )( EntityScreen[1] + 1 ), 3, 3, 255, 100, 0, 255, 1 );

						Engine::g_Verdana.Print ( ( int )EntityScreen[0], ( int )( EntityScreen[1] + 14 ), *r,
							*g, *b, 255, Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, entity[i].Name );
					}
				}
				else if ( entity[i].Type == 2 && Files::g_IniRead.esp.world_sprites )
				{
					float size = ( 30 * 16 ) / l * 10;

					Engine::g_Drawing.DrawBox ( ( int )EntityScreen[0], 
						( int )EntityScreen[1], ( int )size, ( int )size, 1, 255, 255, 255, 100, 1 );
				}
				else if ( entity[i].Type == 3 && Files::g_IniRead.esp.world_nades )
				{
					float rad = ( 30 * 10 ) / l * 10;

					if ( g_Util.native_strstr ( entity[i].Name, HEGREN ) )
					{
						Engine::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 255, 50, 50, 255 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, FLASH ) )
					{
						Engine::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 255, 255, 255, 255 );
					}
					else if ( g_Util.native_strstr ( entity[i].Name, SMOKE ) )
					{
						Engine::g_Drawing.DrawCircle ( EntityScreen[0], EntityScreen[1], rad, 100, 2, 50, 255, 50, 255 );
					}
				}
			}
		}

		ClearEntity ( );
	}

	void ESP::HUD_Redraw ( struct cl_entity_s *Entity, int Index )
	{
		if ( Files::g_IniRead.esp.enable )
		{
			if ( Files::g_IniRead.esp.player && Engine::g_Player[Index].Valid )
			{
				DrawPlayer ( Entity, Index );
			}

			if ( Files::g_IniRead.esp.world_weapons || Files::g_IniRead.esp.world_sprites || Files::g_IniRead.esp.world_nades )
			{
				DrawWorld ( );
			}
		}
	}

	ESP g_ESP;

	entity_s entity[MAX_ENTITY];
}