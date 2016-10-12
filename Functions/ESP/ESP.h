#pragma once

#include "Main.h"

namespace Functions
{
	extern int EntityIndex;

	struct entity_s
	{
		char Name[64];
		Vector Origin;
		int Important;
		BYTE Type;
	};

	extern entity_s entity[MAX_ENTITY];

	class ESP
	{
	public:
		static void DrawPlayer ( int Index );
		static void DrawWorld ( );

		static void AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );
		static void ClearEntity ( );

		static void HUD_AddEntity ( struct cl_entity_s *Entity );
		static void HUD_Redraw ( int Index );
	};

	extern ESP* g_ESP;
}