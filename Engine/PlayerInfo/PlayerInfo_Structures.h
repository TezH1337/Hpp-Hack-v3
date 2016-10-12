#pragma once

#include "PlayerInfo.h"

namespace Engine
{
	struct local_s
	{
		playermove_t *ppmove;
		cl_entity_s *Entity;

		Vector ViewOrg;

		int Team;
		int Index;

		bool Alive;
	};

	extern local_s* g_Local;

	struct player_s
	{
		hud_player_info_t Info;
		cl_entity_s *Entity;

		Vector Origin;
		Vector Mins;
		Vector Maxs;
		Vector Bone[53];
		Vector HitBox[21];

		int WeaponModel;

		bool Ducked;
		bool Updated;
		bool Visible;
		bool Alive;
	};

	extern player_s* g_Player[33];
}