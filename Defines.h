#define HW_DLL					"hw.dll"
#define SW_DLL					"sw.dll"
#define CLIENT_DLL				"client.dll"
#define GAMEUI_DLL				"GameUI.dll"

#define CLIENT_PATTERN			"ScreenFade"
#define STUDIO_PATTERN			"Couldn't get client .dll studio model rendering interface."
#define CONSOLE_PATTERN			"GameConsole003"
#define USERMSG_PATTERN			"UserMsg: Not Present on Client %d"
#define SVC_MSG_PATTERN			"-------- Message Load ---------"
#define SVC_MESSAGES_PATTERN	"End of List."

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

#define SVC_MSG_ERROR_1			"Error #0013. Couldn't find SvcBase pointer."
#define SVC_MSG_ERROR_2			"Error #0014. Couldn't find SvcBase pointer."

#define ENGINEMSG_ERROR			"Error #0015. Couldn't find %s."

#define MSG_READ_CORD			"Error #0016. MSG_ReadCoord."
#define MSG_STR_READING			"Error #0017. MSG_StartBitReading.\nNote: If you inject Hpp Hack with another cheat, it is likely that they are not compatible."
#define MSG_END_READING			"Error #0018. MSG_EndBitReading.\nNote: If you inject Hpp Hack with another cheat, it is likely that they are not compatible."
#define ENGINE_MSG_BASE			"Error #0019. EngineMsgBase."

#define HPP						"[Hpp] "
#define SETTINGS_RELOADED_ENG	"Settings successfully reloaded.\n"
#define SETTINGS_RELOADED_RUS	"Настройки успешно перезагружены.\n"

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
#define ESP_PLAYER_WEAPON		"|ESP.Player.Weapon"
#define ESP_PLAYER_DISTANCE		"|ESP.Player.Distance"
#define ESP_WORLD				"|ESP.World"
#define ESP_WORLD_WEAPONS		"|ESP.World.Weapons"
#define ESP_WORLD_SPRITES		"|ESP.World.Sprites"
#define ESP_WORLD_NADES			"|ESP.World.Nades"
#define ESP_FONT_OUTLINE		"|ESP.Font.OutLine"
#define ESP_FONT_COLOR			"|ESP.Font.Color"
#define ESP_SOUND				"|ESP.Sound"
#define ESP_SOUND_FADE_TIME		"|ESP.Sound.FadeTime"
#define ESP_SOUND_COLOR			"|ESP.Sound.Color"

#define TERRORIST_UMSG			"TERRORIST"
#define CT_UMSG					"CT"

#define RESET_HUD				"ResetHUD"
#define SET_FOV					"SetFOV"
#define TEAM_INFO				"TeamInfo"
#define CUR_WEAPON				"CurWeapon"
#define DEATH_MSG				"DeathMsg"

#define SEQUENCE_RELOADING		"reloading"
#define SEQUENCE_PLANTING		"planting c4"

#define HEGREN					"hegrenade"
#define FLASH					"flash"
#define SMOKE					"smoke"
#define USP						"usp"
#define GLOCK18					"glock18"
#define DEAGLE					"deagle"
#define P228					"p228"
#define ELITE					"elite"
#define FIVESEVEN				"fiveseven"
#define M3						"m3"
#define XM1014					"xm1014"
#define MP5						"mp5"
#define TMP						"tmp"
#define P90						"p90"
#define MAC10					"mac10"
#define UMP45					"ump45"
#define FAMAS					"famas"
#define SG552					"sg552"
#define AK47					"ak47"
#define M4A1					"m4a1"
#define AUG						"aug"
#define SCOUT					"scout"
#define AWP						"awp"
#define G3SG1					"g3sg1"
#define SG550					"sg550"
#define GALIL					"galil"
#define M249					"m249"
#define SHIELD					"shield"
#define BACKPACK				"backpack"
#define THIGHPACK				"thighpack"
#define C4						"c4"

#define SOUND					"svc_sound"
#define SPAWN_STATIC_SOUND		"svc_spawnstaticsound"
#define STUFF_TEXT				"svc_stufftext"
#define NEW_USER_MSG			"svc_newusermsg"
#define UPDATE_USER_INFO		"svc_updateuserinfo"
#define SEND_CVAR_VALUE			"svc_sendcvarvalue"
#define SEND_CVAR_VALUE2		"svc_sendcvarvalue2"
#define DIRECTOR				"svc_director"

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address)  __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)

#define POW(x) ((x)*(x))

#define VectorLengthSquared(v) ((v)[0]*(v)[0]+(v)[1]*(v)[1]+(v)[2]*(v)[2])
#define VectorTransform(a,b,c){(c)[0]=DotProduct((a),(b)[0])+(b)[0][3];(c)[1]=DotProduct((a),(b)[1])+(b)[1][3];(c)[2]=DotProduct((a),(b)[2])+(b)[2][3];}
#define VectorDistance(a,b) sqrt(POW((a)[0]-(b)[0])+POW((a)[1]-(b)[1])+POW((a)[2]-(b)[2]))

#define	SVC_BAD					0
#define	SVC_NOP                 1
#define	SVC_DISCONNECT          2
#define	SVC_EVENT               3
#define	SVC_VERSION             4
#define	SVC_SETVIEW             5
#define	SVC_SOUND               6
#define	SVC_TIME                7
#define	SVC_PRINT               8
#define	SVC_STUFFTEXT           9
#define	SVC_SETANGLE            10
#define	SVC_SERVERINFO          11
#define	SVC_LIGHTSTYLE          12
#define	SVC_UPDATEUSERINFO      13
#define	SVC_DELTADESCRIPTION    14
#define	SVC_CLIENTDATA          15
#define	SVC_STOPSOUND           16
#define	SVC_PINGS               17
#define	SVC_PARTICLE            18
#define	SVC_DAMAGE              19
#define	SVC_SPAWNSTATIC         20
#define	SVC_EVENT_RELIABLE      21
#define	SVC_SPAWNBASELINE       22
#define	SVC_TEMPENTITY          23
#define	SVC_SETPAUSE            24
#define	SVC_SIGNONNUM           25
#define	SVC_CENTERPRINT         26
#define	SVC_KILLEDMONSTER		27
#define	SVC_FOUNDSECRET         28
#define	SVC_SPAWNSTATICSOUND    29
#define	SVC_INTERMISSION        30
#define	SVC_FINALE              31
#define	SVC_CDTRACK             32
#define	SVC_RESTORE             33
#define	SVC_CUTSCENE            34
#define	SVC_WEAPONANIM          35
#define	SVC_DECALNAME           36
#define	SVC_ROOMTYPE            37
#define	SVC_ADDANGLE			38
#define	SVC_NEWUSERMSG          39
#define	SVC_PACKETENTITIES      40
#define	SVC_DELTAPACKETENTITIES 41
#define	SVC_CHOKE               42
#define	SVC_RESOURCELIST        43
#define	SVC_NEWMOVEVARS         44
#define	SVC_RESOURCEREQUEST     45
#define	SVC_CUSTOMIZATION       46
#define	SVC_CROSSHAIRANGLE      47
#define	SVC_SOUNDFADE           48
#define	SVC_FILETXFERFAILED     49
#define	SVC_HLTV                50
#define	SVC_DIRECTOR            51
#define	SVC_VOICEINIT           52
#define	SVC_VOICEDATA           53
#define	SVC_SENDEXTRAINFO       54
#define	SVC_TIMESCALE           55
#define	SVC_RESOURCELOCATION    56
#define	SVC_SENDCVARVALUE       57
#define	SVC_SENDCVARVALUE2      58

#define DEFAULT_SOUND_PACKET_VOLUME			255
#define DEFAULT_SOUND_PACKET_ATTENUATION	1.0f
#define DEFAULT_SOUND_PACKET_PITCH			100

#define BIT(n) (1<<(n))

#define SND_FL_VOLUME			BIT(0)
#define SND_FL_ATTENUATION		BIT(1)
#define SND_FL_LARGE_INDEX		BIT(2)
#define SND_FL_PITCH			BIT(3)
#define SND_FL_SENTENCE			BIT(4)
#define SND_FL_STOP				BIT(5)
#define SND_FL_CHANGE_VOL		BIT(6)
#define SND_FL_CHANGE_PITCH		BIT(7)
#define SND_FL_SPAWNING			BIT(8)

#define MAX_ENTITY				1024
#define MAX_SOUNDS				1024

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

#define WEAPON_PARS(name) {\
	Engine::g_Drawing.DrawBox(EntityScreen[0] - 2, EntityScreen[1], 3 + 2, 3 + 2, 1, 0, 0, 0, 255, 1);\
	Engine::g_Drawing.FillArea(EntityScreen[0] - 1, EntityScreen[1] + 1, 3, 3, 255, 100, 0, 255, 1);\
	Engine::g_Verdana.Print(EntityScreen[0], EntityScreen[1] + 15, font_color.r, font_color.g, font_color.b, 255, Files::g_IniRead.esp.font_outline ? FL_CENTER | FL_OUTLINE : FL_CENTER, name);}

#define INIREAD_INT(var, path, section, key) g_IniRead.path.var = atoi(g_File.IniRead((char*)path.c_str(), section, key, "0"))
#define INIREAD_FLOAT(var, path, section, key) g_IniRead.path.var = atof(g_File.IniRead((char*)path.c_str(), section, key, "0"))
#define INIREAD_STRING(var, path, section, key) g_IniRead.path.var = g_File.ReadString(section, key, "0", (char*)path.c_str())
#define INIREAD(var, path, section, key) g_IniRead.path.var = g_File.IniRead((char*)path.c_str(), section, key, "0")