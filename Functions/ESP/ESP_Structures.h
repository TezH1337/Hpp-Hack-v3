#pragma once

#include "ESP.h"

namespace Functions
{
	struct sound_s
	{
		Vector Origin;
		DWORD Time;
	};

	extern sound_s sound[MAX_SOUNDS];

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

	struct sound_color_s
	{
		BYTE r;
		BYTE g;
		BYTE b;
	};

	extern sound_color_s sound_color;
}