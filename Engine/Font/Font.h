#pragma once

#include "Main.h"

namespace Engine
{
	class Font
	{
	private:
		int iheight, height, width;
		int cheight, cwidth[255];

		__inline void Render ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, char *String );

	public:
		GLuint g_FontListID;

		void InitText ( char* Font, int Height, int Width );

		void Print ( float x, float y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... );
	};

	extern Font g_Font, g_Verdana;
}