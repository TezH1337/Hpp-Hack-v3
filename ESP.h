#pragma once

#include "Main.h"

namespace Functions
{
	class ESP
	{
	public:
		static void DrawPlayer ( int Index );

		static void HUD_Redraw ( int Index );
	};

	extern ESP* g_ESP;
}