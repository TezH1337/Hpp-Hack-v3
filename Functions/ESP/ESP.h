#pragma once

#include "Main.h"
#include "ESP_Structures.h"

namespace Functions
{
	class ESP
	{
	public:
		int EntityIndex, SoundIndex;

		//Get distance to player
		__inline static float GetPlayerDistance ( struct cl_entity_s *Entity, struct cl_entity_s *Local, bool Meters );
		//Get player box color
		__inline static void GetColorPlayerBox ( int Index );
		//Get font color
		__inline static void GetColorFont ( );
		//Get sound color
		__inline static void GetColorSound ( );
		//Drawing player esp
		static void DrawPlayer ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
		//Drawing world esp
		static void DrawWorld ( );
		//Drawing sound esp
		static void DrawSound ( );
		//Add entity
		__inline static void AddEntity ( char* Name, int Important, Vector Origin, BYTE Type );
		//Clear all entities
		__inline static void ClearEntity ( );
		//Add sound
		static void AddSound ( DWORD Time, Vector Origin );
		//Clear all sounds
		__inline static void ClearSound ( );

		static void HUD_AddEntity ( struct cl_entity_s *Entity );
	};

	extern ESP g_ESP;
}