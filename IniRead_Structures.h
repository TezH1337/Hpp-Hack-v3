#pragma once

#include "IniRead.h"

namespace Files
{
	struct esp_s
	{
		int player_box_style;

		bool enable;
		bool player;
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