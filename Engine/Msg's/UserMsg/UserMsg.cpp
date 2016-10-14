#include "UserMsg.h"

namespace Engine
{
	pfnUserMsgHook pResetHUD = nullptr;
	pfnUserMsgHook pSetFOV = nullptr;
	pfnUserMsgHook pTeamInfo = nullptr;
	pfnUserMsgHook pCurWeapon = nullptr;
	pfnUserMsgHook pDeathMsg = nullptr;

	int PlayerTeam[33];

	int UserMsg::ResetHUD ( const char *pszName, int iSize, void *pbuf )
	{
		return pResetHUD ( pszName, iSize, pbuf );
	}

	int UserMsg::SetFOV ( const char *pszName, int iSize, void *pbuf )
	{
		return pSetFOV ( pszName, iSize, pbuf );
	}

	int UserMsg::TeamInfo ( const char *pszName, int iSize, void *pbuf )
	{
		BEGIN_READ ( pbuf, iSize );

		int Index = READ_BYTE( );
		char *Team = READ_STRING ( );

		if ( !strcmp ( Team, TERRORIST_UMSG ) )
		{
			PlayerTeam[Index] = TERRORIST;

			if ( Index == g_Engine.GetLocalPlayer ( )->index )
			{
				Engine::g_Local.Team = TERRORIST;
			}
		}
		else if ( !strcmp ( Team, CT_UMSG ) )
		{
			PlayerTeam[Index] = CT;

			if ( Index == g_Engine.GetLocalPlayer ( )->index )
			{
				Engine::g_Local.Team = CT;
			}
		}
		else
		{
			PlayerTeam[Index] = SPECTATOR;

			if ( Index == g_Engine.GetLocalPlayer ( )->index )
			{
				Engine::g_Local.Team = SPECTATOR;
			}
		}

		return pTeamInfo ( pszName, iSize, pbuf );
	}

	int UserMsg::CurWeapon ( const char *pszName, int iSize, void *pbuf )
	{
		return pCurWeapon ( pszName, iSize, pbuf );
	}

	int UserMsg::DeathMsg ( const char *pszName, int iSize, void *pbuf )
	{
		return pDeathMsg ( pszName, iSize, pbuf );
	}

	UserMsg* g_UserMsg = new UserMsg;
}