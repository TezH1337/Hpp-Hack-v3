#pragma once

#include "Main.h"

namespace Engine
{
	class Font
	{
	private:
		int iheight, height, width;
		int cheight, cwidth[255];

	public:
		GLuint g_FontListID;

		void InitText ( char* Font, int Height, int Width );

		void Render ( int x, int y, BYTE r, BYTE g, BYTE b, BYTE a, char *String );

		void Print ( int x, int y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... );
	};

	extern Font* g_Font;
	extern Font* g_Verdana;
}