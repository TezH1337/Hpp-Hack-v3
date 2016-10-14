#pragma once

#include "PlayerInfo.h"

namespace Engine
{
	struct local_s
	{
		playermove_t *ppmove;

		Vector ViewOrg;

		//Team of player
		int Team;

		//Valid player or not
		bool Alive;
	};

	extern local_s g_Local;

	struct player_s
	{
		hud_player_info_t Info;

		Vector Bone[53];
		Vector HitBox[21];

		//Ducked player or not
		bool Ducked;
		//Valid player or not
		bool Valid;
		//Visible player or not
		bool Visible;
		//Alive player or not
		bool Alive;
	};

	extern player_s g_Player[33];
}