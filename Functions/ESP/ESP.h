#pragma once

#include "Main.h"

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

	class ESP
	{
	public:
		int EntityIndex;

		//Drawing player esp
		__inline static void DrawPlayer ( struct cl_entity_s *Entity, int Index );
		//Drawing world esp
		__inline static void DrawWorld ( );
		//Add entity
		__inline static void AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );
		//Clear all entity
		__inline static void ClearEntity ( );

		static void HUD_AddEntity ( struct cl_entity_s *Entity );
		static void HUD_Redraw ( struct cl_entity_s *Entity, int Index );
	};

	extern ESP g_ESP;
}