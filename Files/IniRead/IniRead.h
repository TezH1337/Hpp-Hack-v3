#pragma once

#include "Main.h"
#include "IniRead_Structures.h"

namespace Files
{
	class IniRead
	{
	public:
		esp_s esp;
		main_s main;
		function_s function;

		void ESP ( );
		void Main ( );
		void Functions ( );
	};

	extern IniRead g_IniRead;
}