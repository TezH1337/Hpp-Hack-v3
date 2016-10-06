#define HW_DLL					"hw.dll"
#define SW_DLL					"sw.dll"
#define CLIENT_DLL				"client.dll"
#define GAMEUI_DLL				"GameUI.dll"

#define CLIENT_PATTERN			"ScreenFade"
#define STUDIO_PATTERN			"Couldn't get client .dll studio model rendering interface."
#define CONSOLE_PATTERN			"GameConsole003"

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

#define VERSION					"3.0 [dev]\n"
#define AUTHOR					"kilabeez\n"

#define CompareMemory(Buff1, Buff2, Size) __comparemem((const UCHAR *)Buff1, (const UCHAR *)Buff2, (UINT)Size)
#define FindMemoryClone(Start, End, Clone, Size) __findmemoryclone((const ULONG)Start, (const ULONG)End, (const ULONG)Clone, (UINT)Size)
#define FindReference(Start, End, Address)  __findreference((const ULONG)Start, (const ULONG)End, (const ULONG)Address)