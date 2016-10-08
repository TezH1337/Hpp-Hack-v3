#pragma once

#include "Main.h"
#include "IniRead_Structures.h"

namespace Files
{
	class IniRead
	{
	public:
		main_s* main = new main_s;

		void Main ( );
	};

	extern IniRead* g_IniRead;
}