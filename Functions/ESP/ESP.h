#pragma once

#include "Main.h"
#include "ESP_Structures.h"

namespace Functions
{
	class ESP
	{
	public:
		int EntityIndex;

		//Get distance to player
		__inline static float GetPlayerDistance ( struct cl_entity_s *Entity, struct cl_entity_s *Local, bool Meters );
		//Set player box color
		__inline static void GetColorPlayerBox ( int Index );
		//Set font color
		__inline static void GetColorFont ( );
		//Drawing player esp
		__inline static void DrawPlayer ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
		//Drawing world esp
		__inline static void DrawWorld ( );
		//Add entity
		__inline static void AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );
		//Clear all entity
		__inline static void ClearEntity ( );

		static void HUD_AddEntity ( struct cl_entity_s *Entity );
		static void HUD_Redraw ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
	};

	extern ESP g_ESP;
}