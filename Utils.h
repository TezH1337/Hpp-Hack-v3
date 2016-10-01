#pragma once

#include "Main.h"

class Util
{
public:
	void MemoryCopy ( void * dst, const void * src, size_t count );
};

extern Util g_Util;