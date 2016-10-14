#include "PlayerInfo.h"

namespace Engine
{
	bool PlayerInfo::isAliveEntity ( struct cl_entity_s *Entity )
	{
		return Entity->curstate.movetype != 6 && Entity->curstate.movetype;
	}

	bool PlayerInfo::isValidEntity ( struct cl_entity_s *Entity )
	{
		return g_Engine.GetLocalPlayer ( )->index != Entity->index && Entity->curstate.movetype != 6 &&
			Entity->curstate.movetype && !( Entity->curstate.messagenum < g_Engine.GetLocalPlayer ( )->curstate.messagenum ) &&
			!( g_Engine.GetLocalPlayer ( )->curstate.iuser1 == 4 && g_Engine.GetLocalPlayer ( )->curstate.iuser2 == Entity->index );
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

	void PlayerInfo::UpdateLocalEntity ( struct cl_entity_s *Entity )
	{
		g_Local.Alive = isAliveEntity ( Entity );

		g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local.ViewOrg );

		VectorAdd ( Entity->origin, g_Local.ViewOrg, g_Local.ViewOrg );
	}

	void PlayerInfo::UpdatePlayerInfo ( struct cl_entity_s *Entity, int Index )
	{
		g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index].Info );

		g_Player[Index].Alive = isAliveEntity ( Entity );
		g_Player[Index].Valid = isValidEntity ( Entity );
		g_Player[Index].Ducked = isDuckedEntity ( Entity );

		g_Player[Index].Visible = ScanPlayerVisibility ( Index );
	}

	void PlayerInfo::GetBoneOrigin ( struct cl_entity_s *Entity )
	{
		if ( isValidEntity ( Entity ) )
		{
			typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

			model_t* pModel = g_Studio.SetupPlayerModel ( Entity->index );

			studiohdr_t* pStudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( pModel );

			TransformMatrix* pbonetransform = ( TransformMatrix* )g_Studio.StudioGetBoneTransform ( );

			for ( BYTE i = 0; i < pStudioHeader->numbones; ++i )
			{
				g_Player[Entity->index].Bone[i][0] = ( *pbonetransform )[i][0][3];
				g_Player[Entity->index].Bone[i][1] = ( *pbonetransform )[i][1][3];
				g_Player[Entity->index].Bone[i][2] = ( *pbonetransform )[i][2][3];
				g_Player[Entity->index].Bone[i] = g_Player[Entity->index].Bone[i];
			}
		}
	}

	void PlayerInfo::GetHitboxOrigin ( struct cl_entity_s *Entity )
	{
		if ( isValidEntity ( Entity ) )
		{
			Vector BBMin, BBMax;

			typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

			model_t* pModel = g_Studio.SetupPlayerModel ( Entity->index );

			studiohdr_t* pStudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( pModel );

			BoneMatrix_t* pBoneMatrix = ( BoneMatrix_t* )g_Studio.StudioGetBoneTransform ( );

			mstudiobbox_t* pHitbox = ( mstudiobbox_t* )( ( byte* )pStudioHeader + pStudioHeader->hitboxindex );

			for ( BYTE i = 0; i < pStudioHeader->numhitboxes; ++i )
			{
				VectorTransform ( pHitbox[i].bbmin, ( *pBoneMatrix )[pHitbox[i].bone], BBMin );
				VectorTransform ( pHitbox[i].bbmax, ( *pBoneMatrix )[pHitbox[i].bone], BBMax );

				g_Player[Entity->index].HitBox[i] = ( BBMax + BBMin ) * 0.5f;
				g_Player[Entity->index].HitBox[i] = g_Player[Entity->index].HitBox[i];
			}
		}
	}

	PlayerInfo g_PlayerInfo;

	local_s g_Local;

	player_s g_Player[33];
}