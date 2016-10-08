#include "UserMsg.h"

namespace Engine
{
	pfnUserMsgHook pResetHUD;
	pfnUserMsgHook pSetFOV;
	pfnUserMsgHook pTeamInfo;
	pfnUserMsgHook pCurWeapon;
	pfnUserMsgHook pDeathMsg;

	int PlayerTeam[33];

	int ResetHUD ( const char *pszName, int iSize, void *pbuf )
	{
		return pResetHUD ( pszName, iSize, pbuf );
	}

	int SetFOV ( const char *pszName, int iSize, void *pbuf )
	{
		return pSetFOV ( pszName, iSize, pbuf );
	}

	int TeamInfo ( const char *pszName, int iSize, void *pbuf )
	{
		BEGIN_READ ( pbuf, iSize );

		int Index = READ_BYTE ( );
		char *Team = READ_STRING ( );

		if ( !strcmp ( Team, TERRORIST_UMSG ) )
		{
			PlayerTeam[Index] = TERRORIST;

			if ( Index == Engine::g_Local->Entity->index )
			{
				Engine::g_Local->Team = TERRORIST;
			}
		}
		else if ( !strcmp ( Team, CT_UMSG ) )
		{
			PlayerTeam[Index] = CT;

			if ( Index == Engine::g_Local->Entity->index )
			{
				Engine::g_Local->Team = CT;
			}
		}
		else
		{
			PlayerTeam[Index] = SPECTATOR;

			if ( Index == Engine::g_Local->Entity->index )
			{
				Engine::g_Local->Team = SPECTATOR;
			}
		}

		return pTeamInfo ( pszName, iSize, pbuf );
	}

	int CurWeapon ( const char *pszName, int iSize, void *pbuf )
	{
		return pCurWeapon ( pszName, iSize, pbuf );
	}

	int DeathMsg ( const char *pszName, int iSize, void *pbuf )
	{
		return pDeathMsg ( pszName, iSize, pbuf );
	}
}