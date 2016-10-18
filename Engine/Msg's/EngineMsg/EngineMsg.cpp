#include "EngineMsg.h"

namespace Engine
{
	int* MSG_ReadCount = nullptr;
	int* MSG_CurrentSize = nullptr;
	int* MSG_BadRead = nullptr;

	int MSG_SavedReadCount = 0;

	sizebuf_t* MSG_Buffer = nullptr;

	HL_MSG_ReadByte MSG_ReadByte = nullptr;
	HL_MSG_ReadShort MSG_ReadShort = nullptr;
	HL_MSG_ReadLong MSG_ReadLong = nullptr;
	HL_MSG_ReadFloat MSG_ReadFloat = nullptr;
	HL_MSG_ReadString MSG_ReadString = nullptr;
	HL_MSG_ReadCoord MSG_ReadCoord = nullptr;
	HL_MSG_ReadBitVec3Coord MSG_ReadBitVec3Coord = nullptr;
	HL_MSG_ReadBits MSG_ReadBits = nullptr;
	HL_MSG_StartBitReading MSG_StartBitReading = nullptr;
	HL_MSG_EndBitReading MSG_EndBitReading = nullptr;

	pfnEngineMsgHook pSVC_sound;
	pfnEngineMsgHook pSVC_SpawnStaticSound;
	pfnEngineMsgHook pSVC_NewUserMsg;
	pfnEngineMsgHook pSVC_UpdateUserInfo;
	pfnEngineMsgHook pSVC_StuffText;
	pfnEngineMsgHook pSVC_SendCvarValue;
	pfnEngineMsgHook pSVC_SendCvarValue2;
	pfnEngineMsgHook pSVC_Director;

	void MSG_SaveReadCount ( )
	{
		MSG_SavedReadCount = *MSG_ReadCount;
	}

	void MSG_RestoreReadCount ( )
	{
		*MSG_ReadCount = MSG_SavedReadCount;
	}

	void SVC_Sound ( )
	{
		MSG_SaveReadCount ( );

		Vector Origin;

		float Attenuation;

		int FieldMask, Volume, Pitch;
		int Channel, Entity, SoundNum;

		MSG_StartBitReading ( MSG_Buffer );

		FieldMask = MSG_ReadBits ( 9 );

		if ( FieldMask & SND_FL_VOLUME )
		{
			Volume = MSG_ReadBits ( 8 ) / 255;
		}
		else
		{
			Volume = DEFAULT_SOUND_PACKET_VOLUME;
		}

		if ( FieldMask & SND_FL_ATTENUATION )
		{
			Attenuation = MSG_ReadBits ( 8 ) / 64.0f;
		}

		Channel = MSG_ReadBits ( 3 );
		Entity = MSG_ReadBits ( 11 );

		if ( FieldMask & SND_FL_LARGE_INDEX )
		{
			SoundNum = MSG_ReadBits ( 16 );
		}
		else
		{
			SoundNum = MSG_ReadBits ( 8 );
		}

		MSG_ReadBitVec3Coord ( Origin );

		if ( FieldMask & SND_FL_PITCH )
		{
			Pitch = MSG_ReadBits ( 8 );
		}

		MSG_EndBitReading ( MSG_Buffer );

		if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.sound )
		{
			if ( Entity != Engine::g_Engine.GetLocalPlayer ( )->index )
			{
				Functions::g_ESP.AddSound ( GetTickCount ( ), Origin );
			}
		}

		MSG_RestoreReadCount ( );
		pSVC_sound ( );
	}

	void SVC_SpawnStaticSound ( )
	{
		MSG_SaveReadCount ( );

		Vector Position;

		float Volume, Attenuation;

		int SoundNum, Flags;
		int Entity, Pitch;

		MSG_StartBitReading ( MSG_Buffer );

		Position.x = MSG_ReadCoord ( );
		Position.y = MSG_ReadCoord ( );
		Position.z = MSG_ReadCoord ( );

		SoundNum = MSG_ReadShort ( );
		Volume = MSG_ReadByte ( ) / 255.0f;
		Attenuation = MSG_ReadByte ( ) / 64.0f;
		Entity = MSG_ReadShort ( );
		Pitch = MSG_ReadByte ( );
		Flags = MSG_ReadByte ( );

		if ( Files::g_IniRead.function.esp && Files::g_IniRead.esp.sound )
		{
			if ( Entity != Engine::g_Engine.GetLocalPlayer ( )->index )
			{
				Functions::g_ESP.AddSound ( GetTickCount ( ), Position );
			}
		}

		MSG_EndBitReading ( MSG_Buffer );

		MSG_RestoreReadCount ( );
		pSVC_SpawnStaticSound ( );
	}

	void SVC_NewUserMsg ( )
	{
		MSG_SaveReadCount ( );

		MSG_RestoreReadCount ( );
		pSVC_NewUserMsg ( );
	}

	void SVC_UpdateUserInfo ( )
	{
		MSG_SaveReadCount ( );

		BYTE ClientCDKeyHash[16] = { 0 };

		for ( int i = 0; i < 16; ++i )
		{
			ClientCDKeyHash[i] = MSG_ReadByte ( );
		}

		MSG_RestoreReadCount ( );
		pSVC_UpdateUserInfo ( );
	}

	void SVC_StuffText ( )
	{
		MSG_SaveReadCount ( );

		MSG_RestoreReadCount ( );
		pSVC_StuffText ( );
	}

	void SVC_SendCvarValue ( )
	{
		MSG_SaveReadCount ( );

		MSG_RestoreReadCount ( );
		pSVC_SendCvarValue ( );
	}

	void SVC_SendCvarValue2 ( )
	{
		MSG_SaveReadCount ( );

		MSG_RestoreReadCount ( );
		pSVC_SendCvarValue2 ( );
	}

	void SVC_Director ( )
	{
		MSG_SaveReadCount ( );

		MSG_RestoreReadCount ( );
		pSVC_Director ( );
	}
}