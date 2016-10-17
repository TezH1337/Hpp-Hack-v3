#pragma once

#include "Main.h"

namespace Engine
{
	class UserMsg
	{
	public:
		static int ResetHUD ( const char *pszName, int iSize, void *pbuf );
		static int SetFOV ( const char *pszName, int iSize, void *pbuf );
		static int TeamInfo ( const char *pszName, int iSize, void *pbuf );
		static int CurWeapon ( const char *pszName, int iSize, void *pbuf );
		static int DeathMsg ( const char *pszName, int iSize, void *pbuf );
	};

	extern UserMsg g_UserMsg;

	//Team of player
	extern int PlayerTeam[33];

	extern pfnUserMsgHook pResetHUD;
	extern pfnUserMsgHook pSetFOV;
	extern pfnUserMsgHook pTeamInfo;
	extern pfnUserMsgHook pCurWeapon;
	extern pfnUserMsgHook pDeathMsg;
}