#include "Main.h"

PColor24 Console_TextColor;
SCREENINFO g_Screen;

cl_clientfunc_t *g_pClient = nullptr;
cl_enginefunc_t *g_pEngine = nullptr;
engine_studio_api_t *g_pStudio = nullptr;

cl_clientfunc_t g_Client;
cl_enginefunc_t g_Engine;
engine_studio_api_t g_Studio;

char* BaseDir;

DWORD WINAPI CheatEntry ( LPVOID lpThreadParameter );

DWORD WINAPI ProcessReload ( LPVOID lpThreadParameter )
{
	while ( true )
	{
		if ( FirstFrame )
		{
			Engine::g_Offset->GetRenderType ( );

			if ( !Engine::g_Offset->GetModuleInfo ( ) )
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

DWORD WINAPI CheatEntry ( LPVOID lpThreadParameter )
{
	static HANDLE ProcessReloadThread = 0;

	if ( ProcessReloadThread )
	{
		TerminateThread ( ProcessReloadThread, 0 );
		CloseHandle ( ProcessReloadThread );
	}

	BYTE find_counter = 0;

start_hook:

	if ( find_counter == 50 )
	{
		if ( !g_pClient )
		{
			Engine::g_Offset->Error ( true, CLIENT_FIND_ERROR );
		}

		if ( !g_pEngine )
		{
			Engine::g_Offset->Error ( true, ENGINE_FIND_ERROR );
		}

		if ( !g_pStudio )
		{
			Engine::g_Offset->Error ( true, STUDIO_FIND_ERROR );
		}
	}

	Sleep ( 50 );

	++find_counter;

	if ( !Engine::g_Offset->GetModuleInfo ( ) )
	{
		goto start_hook;
	}

	DWORD ClientTable = Engine::g_Offset->FindClientTable ( );

	if ( ClientTable )
	{
		g_pClient = ( cl_clientfunc_t* )ClientTable;

		g_Util.MemoryCopy ( &g_Client, g_pClient, sizeof ( cl_clientfunc_t ) );

		if ( g_Client.Initialize )
		{
			DWORD EngineTable = Engine::g_Offset->FindEngineTable ( );

			if ( EngineTable )
			{
				g_pEngine = ( cl_enginefunc_t* )EngineTable;

				g_Util.MemoryCopy ( &g_Engine, g_pEngine, sizeof ( cl_enginefunc_t ) );

				if ( g_Engine.V_CalcShake )
				{
					DWORD StudioTable = Engine::g_Offset->FindStudioTable ( );

					if ( StudioTable )
					{
						g_pStudio = ( engine_studio_api_t* )StudioTable;

						g_Util.MemoryCopy ( &g_Studio, g_pStudio, sizeof ( engine_studio_api_t ) );

						if ( g_Studio.StudioSetupSkin )
						{
							while ( !FirstFrame )
							{
								HookStudio ( );
								HookFunction ( );

								Sleep ( 50 );
							}

							ProcessReloadThread = CreateThread ( 0, 0, ProcessReload, 0, 0, 0 );
						}
						else
						{
							goto start_hook;
						}
					}
					else
					{
						goto start_hook;
					}
				}
				else
				{
					goto start_hook;
				}
			}
			else
			{
				goto start_hook;
			}
		}
		else
		{
			goto start_hook;
		}
	}
	else
	{
		goto start_hook;
	}

	return 0;
}

BOOL WINAPI DllMain ( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
	switch ( fdwReason )
	{
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls ( hinstDLL );

		BaseDir = ( char* )HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, MAX_PATH );

		GetModuleFileNameA ( hinstDLL, BaseDir, MAX_PATH );

		char* pos = BaseDir + lstrlenA ( BaseDir );

		while ( pos >= BaseDir && *pos != '\\' )
		{
			--pos;
		}

		pos[1] = 0;

		CreateThread ( 0, 0, CheatEntry, 0, 0, 0 );

		return TRUE;
	}

	return FALSE;
}