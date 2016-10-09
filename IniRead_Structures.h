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

		int player_box_style;

		BYTE t_vis_color[4];
		BYTE t_hide_color[4];
		BYTE ct_vis_color[4];
		BYTE ct_hide_color[4];

		bool enable;

		bool player;
		bool player_enemy_only;
		bool player_visible_only;
		bool player_visible_check;
		bool player_box;
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