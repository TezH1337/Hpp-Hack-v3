#pragma once

#include "ESP.h"

namespace Functions
{
	struct entity_s
	{
		char Name[64];
		Vector Origin;
		int Important;
		BYTE Type;
	};

	extern entity_s entity[MAX_ENTITY];

	struct player_box_color_s
	{
		BYTE r;
		BYTE g;
		BYTE b;
	};

	extern player_box_color_s player_box_color;

	struct font_color_s
	{
		BYTE r;
		BYTE g;
		BYTE b;
	};

	extern font_color_s font_color;
}