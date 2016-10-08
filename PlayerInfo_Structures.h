#pragma once

#include "PlayerInfo.h"

namespace Engine
{
	struct local_s
	{
		playermove_t *ppmove;
		cl_entity_s *Entity;

		Vector ViewOrg;
	};

	extern local_s* g_Local;

	struct player_s
	{
		hud_player_info_t Info;
		cl_entity_s *Entity;

		Vector Bone[53];
		Vector HitBox[21];

		bool Ducked;
		bool Updated;
		bool Visible;
	};

	extern player_s* g_Player[33];
}