#pragma once

#include "Main.h"

class Font
{
private:

	int fheight, height, width;
	int cheight, cwidth[255];

public:

	GLuint g_FontListID;

	void InitText ( char* Font, int Height, int Width );

	void Render ( int x, int y, int r, int g, int b, int a, char *String );

	void Print ( int x, int y, int r, int g, int b, int a, BYTE Flags, char *String, ... );

};

extern Font g_Font;