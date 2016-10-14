#include "Main.h"

namespace Engine
{
	PColor24 Console_TextColor;
	SCREENINFO g_Screen;
	PUserMsg g_pUserMsgBase;

	cl_clientfunc_t *g_pClient = nullptr;
	cl_enginefunc_t *g_pEngine = nullptr;
	engine_studio_api_t *g_pStudio = nullptr;

	cl_clientfunc_t g_Client;
	cl_enginefunc_t g_Engine;
	engine_studio_api_t g_Studio;

	char* BaseDir;
}

DWORD WINAPI ProcessReload ( LPVOID lpThreadParameter );

DWORD WINAPI CheatEntry ( LPVOID lpThreadParameter )
{
	static HANDLE ProcessReloadThread = 0;

	if ( ProcessReloadThread )
	{
		TerminateThread ( ProcessReloadThread, 0 );
		CloseHandle ( ProcessReloadThread );
	}

	BYTE FindCounter = 0;

StartHook:

	if ( FindCounter == 50 )
	{
		if ( !Engine::g_pClient )
		{
			Engine::g_Offset.Error ( true, CLIENT_FIND_ERROR );
		}

		if ( !Engine::g_pEngine )
		{
			Engine::g_Offset.Error ( true, ENGINE_FIND_ERROR );
		}

		if ( !Engine::g_pStudio )
		{
			Engine::g_Offset.Error ( true, STUDIO_FIND_ERROR );
		}
	}

	Sleep ( 100 );

	++FindCounter;

	if ( !Engine::g_Offset.GetModuleInfo ( ) )
	{
		goto StartHook;
	}

	DWORD ClientTable = Engine::g_Offset.FindClientTable ( );

	if ( ClientTable )
	{
		Engine::g_pClient = ( cl_clientfunc_t* )ClientTable;

		Engine::g_Offset.CopyClient ( );

		if ( Engine::g_Client.Initialize )
		{
			DWORD EngineTable = Engine::g_Offset.FindEngineTable ( );

			if ( EngineTable )
			{
				Engine::g_pEngine = ( cl_enginefunc_t* )EngineTable;

				Engine::g_Offset.CopyEngine ( );

				if ( Engine::g_Engine.V_CalcShake )
				{
					DWORD StudioTable = Engine::g_Offset.FindStudioTable ( );

					if ( StudioTable )
					{
						Engine::g_pStudio = ( engine_studio_api_t* )StudioTable;

						Engine::g_Offset.CopyStudio ( );

						if ( Engine::g_Studio.StudioSetupSkin )
						{
							while ( !FirstFrame )
							{
								HookStudio ( );
								HookFunction ( );

								Sleep ( 100 );
							}

							ProcessReloadThread = CreateThread ( 0, 0, ProcessReload, 0, 0, 0 );
						}
						else
						{
							goto StartHook;
						}
					}
					else
					{
						goto StartHook;
					}
				}
				else
				{
					goto StartHook;
				}
			}
			else
			{
				goto StartHook;
			}
		}
		else
		{
			goto StartHook;
		}
	}
	else
	{
		goto StartHook;
	}

	return 0;
}

DWORD WINAPI ProcessReload ( LPVOID lpThreadParameter )
{
	while ( true )
	{
		if ( FirstFrame )
		{
			if ( !Engine::g_Offset.GetModuleInfo ( ) )
			{
				FirstFrame = false;
			}
		}
		else
		{
			CreateThread ( 0, 0, CheatEntry, 0, 0, 0 );
		}

		Sleep ( 50 );
	}

	return 0;
}

BOOL WINAPI DllMain ( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls ( hinstDLL );

		Engine::BaseDir = ( char* )HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, MAX_PATH );

		GetModuleFileName ( hinstDLL, Engine::BaseDir, MAX_PATH );

		char* Position = Engine::BaseDir + lstrlen ( Engine::BaseDir );

		while ( Position >= Engine::BaseDir && *Position != '\\' )
		{
			--Position;
		}

		Position[1] = 0;

		CreateThread ( 0, 0, CheatEntry, 0, 0, 0 );

		return TRUE;
	}

	return FALSE;
}