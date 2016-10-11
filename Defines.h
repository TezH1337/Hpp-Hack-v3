#define HW_DLL					"hw.dll"
#define SW_DLL					"sw.dll"
#define CLIENT_DLL				"client.dll"
#define GAMEUI_DLL				"GameUI.dll"

#define CLIENT_PATTERN			"ScreenFade"
#define STUDIO_PATTERN			"Couldn't get client .dll studio model rendering interface."
#define CONSOLE_PATTERN			"GameConsole003"
#define USERMSG_PATTERN			"UserMsg: Not Present on Client %d"

#define ERROR_HEADER			"Hpp Hack"

#define CLIENT_FIND_ERROR		"Error #0001. Couldn't find g_pClient pointer."
#define ENGINE_FIND_ERROR		"Error #0002. Couldn't find g_pEngine pointer."
#define STUDIO_FIND_ERROR		"Error #0003. Couldn't find g_pStudio pointer."

#define CONSOLE_ERROR_1			"Error #0004. Couldn't find GameConsole pointer."
#define CONSOLE_ERROR_2			"Error #0005. Couldn't find GameConsole pointer."
#define CONSOLE_ERROR_3			"Error #0006. Couldn't find GameConsole pointer."

#define ABSOLUTE_ERROR			"Error #0007. Absolute Address Error."

#define GAMEINFO_ERROR			"Error #0008. Couldn't find GameInfo pointer."

#define PPMOVE_PTR_ERROR		"Error #0009. Couldn't find PlayerMove pointer."

#define USERMSG_ERROR_1			"Error #0010. Couldn't find UserMsgBase pointer."
#define USERMSG_ERROR_2			"Error #0011. Couldn't find UserMsgBase pointer."

#define USERMSG_ERROR			"Error #0012. Couldn't find %s.\nNote: Cheat can't support this game.\nSupported Games: Half-Life, Counter-Strike, Counter-Strike: Condition Zero, Counter-Strike: Condition Zero Deleted Scenes."

#define VERSION					"3.0 [dev]\n"
#define AUTHOR					"kilabeez\n"

#define LUCIDA_CONSOLE			"Lucida Console"
#define VERDANA					"Verdana"

#define MAIN					"Main"
#define FUNCTIONS				"Functions"
#define mESP					"ESP"

#define MAIN_PATH				"\\Settings\\Main.ini"
#define VISUALS_PATH			"\\Settings\\Visuals.ini"
#define FUNCTIONS_PATH			"\\Settings\\Functions.ini"

#define MAIN_LANGUAGE			"|Language"
#define MAIN_RELOAD_KEY			"|Reload.Key"

#define FUNCTIONS_ESP			"|ESP"

#define ESP_ENABLE				"|ESP.Enable"
#define ESP_PLAYER				"|ESP.Player"
#define ESP_PLAYER_VISIBLE_ONLY	"|ESP.Player.VisibleOnly"
#define ESP_VISIBLE_CHECK		"|ESP.Player.VisibleCheck"
#define ESP_PLAYER_BOX			"|ESP.Player.Box"
#define ESP_PLAYER_BOX_3D		"|ESP.Player.Box.3D"
#define ESP_PLAYER_BOX_OUTLINE	"|ESP.Player.Box.OutLine"
#define ESP_PLAYER_BOX_LW		"|ESP.Player.Box.LineWidth"
#define ESP_PLAYER_BOX_T_VIS	"|ESP.Player.Box.T.Vis"
#define ESP_PLAYER_BOX_T_HIDE	"|ESP.Player.Box.T.Hide"
#define ESP_PLAYER_BOX_CT_VIS	"|ESP.Player.Box.CT.Vis"
#define ESP_PLAYER_BOX_CT_HIDE	"|ESP.Player.Box.CT.Hide"
#define ESP_PLAYER_NAME			"|ESP.Player.Name"
#define ESP_FONT_OUTLINE		"|ESP.Font.OutLine"
#define ESP_FONT_COLOR			"|ESP.Font.Color"

#define TERRORIST_UMSG			"TERRORIST"
#define CT_UMSG					"CT"

#define RESET_HUD				"ResetHUD"
#define SET_FOV					"SetFOV"
#define TEAM_INFO				"TeamInfo"
#define CUR_WEAPON				"CurWeapon"
#define DEATH_MSG				"DeathMsg"

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address)  __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)

#define VectorTransform(a,b,c){(c)[0]=DotProduct((a),(b)[0])+(b)[0][3];(c)[1]=DotProduct((a),(b)[1])+(b)[1][3];(c)[2]=DotProduct((a),(b)[2])+(b)[2][3];}

#define TERRORIST				1
#define CT						2
#define SPECTATOR				0

#define FL_NONE					0
#define FL_OUTLINE				2
#define FL_BACKDROP				4
#define FL_CENTER				8
#define FL_ALL					255

#define RUSSIAN					0
#define ENGLISH					1

#define	K_POINT					46
#define K_COMMA					44
#define K_0						48
#define K_1						49
#define K_2						50
#define K_3						51
#define K_4						52
#define K_5						53
#define K_6						54
#define K_7						55
#define K_8						56
#define K_9						57
#define K_BRACKET_LEFT			91
#define K_BRACKET_RIGHT			93
#define K_A						97
#define K_B						98
#define K_C						99
#define K_D						100
#define K_E						101
#define K_F						102
#define K_G						103
#define K_H						104
#define K_I						105
#define K_J						106
#define K_K						107
#define K_L						108
#define K_M						109
#define K_N						110
#define K_O						111
#define K_P						112
#define K_Q						113
#define K_R						114
#define K_S						115
#define K_T						116
#define K_U						117
#define K_V						118
#define K_W						119
#define K_X						120
#define K_Y						121
#define K_Z						122

#define PARS_STRING(key_1, key_2, to_convent) {\
	if (!lstrcmpA(Key, key_1) || !lstrcmpA(Key, key_2))\
		return to_convent;}

#define INIREAD_INT(var, path, section, key) g_IniRead->path->var = atoi(g_File->IniRead((char*)path.c_str(), section, key, "0"))
#define INIREAD_FLOAT(var, path, section, key) g_IniRead->path->var = atof(g_File->IniRead((char*)path.c_str(), section, key, "0"))
#define INIREAD_STRING(var, path, section, key) g_IniRead->path->var = g_File->ReadString(section, key, "0", (char*)path.c_str())
#define INIREAD(var, path, section, key) g_IniRead->path->var = g_File->IniRead((char*)path.c_str(), section, key, "0")