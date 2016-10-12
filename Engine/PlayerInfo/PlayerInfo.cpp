#include "PlayerInfo.h"

namespace Engine
{
	bool PlayerInfo::isAliveEntity ( struct cl_entity_s *Entity )
	{
		return ( Entity && !( Entity->curstate.effects & EF_NODRAW ) &&
			Entity->player && Entity->curstate.movetype != 6 && Entity->curstate.movetype );
	}

	bool PlayerInfo::isValidEntity ( struct cl_entity_s *Entity )
	{
		return ( Entity->player && g_Local->Index != Entity->index && Entity->curstate.movetype != 6 &&
			Entity->curstate.movetype && !( Entity->curstate.messagenum < g_Engine.GetLocalPlayer ( )->curstate.messagenum ) &&
			!( g_Engine.GetLocalPlayer ( )->curstate.iuser1 == 4 && g_Engine.GetLocalPlayer ( )->curstate.iuser2 == Entity->index ) );
	}

	bool PlayerInfo::ScanPlayerVisibility ( int Index )
	{
		BYTE HitBoxCheckVisible[8] = { 0, 2, 6, 7, 8, 9, 11, 19 };

		for ( BYTE i = 0; i < sizeof ( HitBoxCheckVisible ); ++i )
		{
			if ( g_Util.PathFree ( g_Player[Index]->HitBox[HitBoxCheckVisible[i]] ) )
			{
				return true;
			}
		}

		return false;
	}

	void PlayerInfo::UpdateLocalEntity ( )
	{
		g_Local->Entity = g_Engine.GetLocalPlayer ( );

		g_Local->Index = g_Local->Entity->index;

		if ( Files::g_IniRead->function->esp )
		{
			if ( Files::g_IniRead->esp->enable && Files::g_IniRead->esp->player )
			{
				g_Local->Alive = isAliveEntity ( g_Local->Entity );
			}
		}

		g_Engine.pEventAPI->EV_LocalPlayerViewheight ( g_Local->ViewOrg );

		VectorAdd ( g_Local->Entity->origin, g_Local->ViewOrg, g_Local->ViewOrg );
	}

	void PlayerInfo::UpdatePlayerInfo ( int Index )
	{
		g_Player[Index]->Entity = g_Engine.GetEntityByIndex ( Index );

		g_Engine.pfnGetPlayerInfo ( Index, &g_Player[Index]->Info );

		if ( Files::g_IniRead->function->esp )
		{
			if ( Files::g_IniRead->esp->enable && Files::g_IniRead->esp->player &&
				( Files::g_IniRead->esp->player_visible_check || Files::g_IniRead->esp->player_visible_only ) )
			{
				g_Player[Index]->Visible = ScanPlayerVisibility ( Index );
			}

			g_Player[Index]->Updated = isValidEntity ( g_Player[Index]->Entity );

			g_Player[Index]->Ducked = ( g_Player[Index]->Entity->curstate.maxs[2] -
				g_Player[Index]->Entity->curstate.mins[2] ) < 54 ? true : false;

			g_Player[Index]->Origin = g_Player[Index]->Entity->origin;

			g_Player[Index]->Mins = g_Player[Index]->Entity->curstate.mins;
			g_Player[Index]->Maxs = g_Player[Index]->Entity->curstate.maxs;

			if ( Files::g_IniRead->esp->player_weapon )
			{
				g_Player[Index]->WeaponModel = g_Player[Index]->Entity->curstate.weaponmodel;
			}
		}

		g_Player[Index]->Alive = isAliveEntity ( g_Player[Index]->Entity );
	}

	void PlayerInfo::GetBoneOrigin ( struct cl_entity_s *Entity )
	{
		if ( Entity->index != -1 && isValidEntity ( Entity ) )
		{
			typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

			model_t* pModel = g_Studio.SetupPlayerModel ( Entity->index );
			studiohdr_t* pStudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( pModel );
			TransformMatrix* pbonetransform = ( TransformMatrix* )g_Studio.StudioGetBoneTransform ( );

			for ( BYTE i = 0; i < pStudioHeader->numbones; ++i )
			{
				g_Player[Entity->index]->Bone[i][0] = ( *pbonetransform )[i][0][3];
				g_Player[Entity->index]->Bone[i][1] = ( *pbonetransform )[i][1][3];
				g_Player[Entity->index]->Bone[i][2] = ( *pbonetransform )[i][2][3];
				g_Player[Entity->index]->Bone[i] = g_Player[Entity->index]->Bone[i];
			}
		}
	}

	void PlayerInfo::GetHitboxOrigin ( struct cl_entity_s *Entity )
	{
		if ( Entity->index != -1 && isValidEntity ( Entity ) )
		{
			Vector vBBMin, vBBMax;

			typedef float BoneMatrix_t[MAXSTUDIOBONES][3][4];

			model_t* pModel = g_Studio.SetupPlayerModel ( Entity->index );
			studiohdr_t* pStudioHeader = ( studiohdr_t* )g_Studio.Mod_Extradata ( pModel );
			BoneMatrix_t* pBoneMatrix = ( BoneMatrix_t* )g_Studio.StudioGetBoneTransform ( );
			mstudiobbox_t* pHitbox = ( mstudiobbox_t* )( ( byte* )pStudioHeader + pStudioHeader->hitboxindex );

			for ( BYTE i = 0; i < pStudioHeader->numhitboxes; ++i )
			{
				VectorTransform ( pHitbox[i].bbmin, ( *pBoneMatrix )[pHitbox[i].bone], vBBMin );
				VectorTransform ( pHitbox[i].bbmax, ( *pBoneMatrix )[pHitbox[i].bone], vBBMax );

				g_Player[Entity->index]->HitBox[i] = ( vBBMax + vBBMin ) * 0.5f;
				g_Player[Entity->index]->HitBox[i] = g_Player[Entity->index]->HitBox[i];
			}
		}
	}

	PlayerInfo* g_PlayerInfo = new PlayerInfo;

	local_s* g_Local = new local_s;

	player_s* g_Player[33] =
	{
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
		new player_s,
	};
}