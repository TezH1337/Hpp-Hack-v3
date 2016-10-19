#pragma once

#include "Main.h"

namespace Engine
{
	class PlayerInfo
	{
	private:
		//Check the player is alive or not
		__inline static bool isAliveEntity ( struct cl_entity_s *Entity );
		//Check the player is valid or not
		__inline static bool isValidEntity ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
		//Check the player is ducked or not
		__inline static bool isDuckedEntity ( struct cl_entity_s *Entity );
		//Scanning the player on the visibility
		__inline static bool ScanPlayerVisibility ( int Index );

	public:		
		//Update information about local player
		static void UpdateLocalEntity ( struct cl_entity_s *Local );
		//Update information about players
		static void UpdatePlayerInfo ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index );
		//Get player bones
		static void GetBoneOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
		//Get player hitboxes
		static void GetHitboxOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local );
	};

	extern PlayerInfo g_PlayerInfo;

	struct local_s
	{
		playermove_t *ppmove;

		Vector ViewOrg;

		//Team of player
		int Team;

		//Valid player or not
		bool Alive;
	};

	extern local_s g_Local;

	struct player_s
	{
		hud_player_info_t Info;

		//Bones of player
		Vector Bone[53];
		//Hitboxes of player
		Vector HitBox[21];

		//Ducked player or not
		bool Ducked;
		//Valid player or not
		bool Valid;
		//Visible player or not
		bool Visible;
		//Alive player or not
		bool Alive;
	};

	extern player_s g_Player[33];
}