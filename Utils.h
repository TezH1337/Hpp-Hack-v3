#pragma once

#include "Main.h"

pcmd_t CommandByName ( char* szName );

class Util
{
public:
	void MemoryCopy ( void * dst, const void * src, size_t count );
};

extern Util g_Util;