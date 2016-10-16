#include "PlayerInfo.h"

namespace Engine
{
	bool PlayerInfo::isAliveEntity ( struct cl_entity_s *Entity )
	{
		return Entity->curstate.movetype != 6 && Entity->curstate.movetype;
	}

	bool PlayerInfo::isValidEntity ( struct cl_entity_s *Entity, struct cl_entity_s *Local )
	{
		return Local->index != Entity->index && isAliveEntity ( Entity ) && 
			!( Entity->curstate.messagenum < Local->curstate.messagenum ) && 
			!( Local->curstate.iuser1 == 4 && Local->curstate.iuser2 == Entity->index );
	}

	bool PlayerInfo::isDuckedEntity ( struct cl_entity_s *Entity )
	{
		return ( Entity->curstate.maxs[2] - Entity->curstate.mins[2] ) < 54;
	}

	bool PlayerInfo::ScanPlayerVisibility ( int Index )
	{
		BYTE HitBoxCheckVisible[8] = { 0, 2, 6, 7, 8, 9, 11, 19 };

		for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
		{
			if ( g_Util.PathFree ( g_Player[Index].HitBox[HitBoxCheckVisible[i]] ) )
			{
				return true;
			}
		}

		return false;
	}

	void PlayerInfo::UpdateLocalEntity ( struct cl_entity_s *Local )
	{
		if ( Local->player )
		{
			g_Local.Alive = isAliveEntity ( Local );

			g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local.ViewOrg );

			VectorAdd ( Local->origin, g_Local.ViewOrg, g_Local.ViewOrg );
		}
	}

	void PlayerInfo::UpdatePlayerInfo ( struct cl_entity_s *Entity, struct cl_entity_s *Local, int Index )
	{
		g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );

		if ( Entity->player )
		{
			g_Player[Index].Alive = isAliveEntity ( Entity );
			g_Player[Index].Valid = isValidEntity ( Entity, Local );
			g_Player[Index].Ducked = isDuckedEntity ( Entity );

			g_Player[Index].Visible = ScanPlayerVisibility ( Index );
		}
	}

	void PlayerInfo::GetBoneOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local )
	{
		if ( isValidEntity ( Entity, Local ) )
		{
			typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

			model_t* Model = g_Studio.SetupPlayerModel ( Entity->index );

			studiohdr_t* StudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( Model );

			TransformMatrix* BoneTransform = ( TransformMatrix* )g_Studio.StudioGetBoneTransform ( );

			for ( BYTE i = 0; i < StudioHeader->numbones; ++i )
			{
				g_Player[Entity->index].Bone[i][0] = ( *BoneTransform )[i][0][3];
				g_Player[Entity->index].Bone[i][1] = ( *BoneTransform )[i][1][3];
				g_Player[Entity->index].Bone[i][2] = ( *BoneTransform )[i][2][3];
				g_Player[Entity->index].Bone[i] = g_Player[Entity->index].Bone[i];
			}
		}
	}

	void PlayerInfo::GetHitboxOrigin ( struct cl_entity_s *Entity, struct cl_entity_s *Local )
	{
		if ( isValidEntity ( Entity, Local ) )
		{
			Vector BBMin, BBMax;

			typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

			model_t* Model = g_Studio.SetupPlayerModel ( Entity->index );

			studiohdr_t* StudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( Model );

			BoneMatrix_t* BoneMatrix = ( BoneMatrix_t* )g_Studio.StudioGetBoneTransform ( );

			mstudiobbox_t* Hitbox = ( mstudiobbox_t* )( ( byte* )StudioHeader + StudioHeader->hitboxindex );

			for ( BYTE i = 0; i < StudioHeader->numhitboxes; ++i )
			{
				VectorTransform ( Hitbox[i].bbmin, ( *BoneMatrix )[Hitbox[i].bone], BBMin );
				VectorTransform ( Hitbox[i].bbmax, ( *BoneMatrix )[Hitbox[i].bone], BBMax );

				g_Player[Entity->index].HitBox[i] = ( BBMax + BBMin ) * 0.5f;
				g_Player[Entity->index].HitBox[i] = g_Player[Entity->index].HitBox[i];
			}
		}
	}

	PlayerInfo g_PlayerInfo;

	local_s g_Local;

	player_s g_Player[33];
}