#pragma once

#include "Main.h"
#include "IniRead_Structures.h"

namespace Files
{
	class IniRead
	{
	public:
		esp_s* esp = new esp_s;
		main_s* main = new main_s;
		function_s* function = new function_s;

		void ESP ( );
		void Main ( );
		void Functions ( );
	};

	extern IniRead* g_IniRead;
}