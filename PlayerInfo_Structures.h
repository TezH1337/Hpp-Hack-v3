#pragma once

#include "PlayerInfo.h"

struct local_s
{
	playermove_t *ppmove;
	cl_entity_s *Entity;
};

extern local_s g_Local;

struct player_s
{
	hud_player_info_t Info;
	cl_entity_s *Entity;
};

extern player_s g_Player[33];
