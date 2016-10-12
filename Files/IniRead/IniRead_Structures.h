#pragma once

#include "IniRead.h"

namespace Files
{
	struct esp_s
	{
		char* t_vis_color_string;
		char* t_hide_color_string;
		char* ct_vis_color_string;
		char* ct_hide_color_string;
		char* font_color_string;

		BYTE player;
		BYTE player_box;
		BYTE player_box_linewidth;

		BYTE t_vis_color[4];
		BYTE t_hide_color[4];
		BYTE ct_vis_color[4];
		BYTE ct_hide_color[4];
		BYTE font_color[4];

		bool enable;

		bool player_visible_only;
		bool player_visible_check;

		bool player_box_3d;
		bool player_box_outline;

		bool player_name;
		bool player_weapon;
		
		bool world_weapons;

		bool font_outline;
	};

	struct main_s
	{
		int reload_key;

		bool language;
	};

	struct function_s
	{
		bool esp;
	};
}