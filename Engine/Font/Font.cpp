#include "Font.h"

namespace Engine
{
	void Font::InitText ( char* Font, int Height, int Width )
	{
		if ( g_Offset.HLType != RENDERTYPE_HARDWARE )
		{
			return;
		}

		HDC hDC;

		HFONT hFont, hOldFont;

		iheight = Height;
		hDC = wglGetCurrentDC ( );
		g_FontListID = glGenLists ( 256 );

		hFont = CreateFont ( Height, Width, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET,
			OUT_TT_PRECIS, 0, ANTIALIASED_QUALITY, 0, Font );

		hOldFont = ( HFONT )SelectObject ( hDC, hFont );

		if ( !wglUseFontBitmaps ( hDC, 0, 255, g_FontListID ) )
		{
			wglUseFontBitmaps ( hDC, 0, 255, g_FontListID );
		}

		for ( int i = 0; i < 255; ++i )
		{
			SIZE s;

			char line[2] = { ( char )i, 0 };

			GetTextExtentPoint ( hDC, line, 1, &s );

			cwidth[i] = s.cx;
			cheight = s.cy;
		}

		SelectObject ( hDC, hOldFont );
		DeleteObject ( hFont );
	}

	void Font::Render ( int x, int y, BYTE r, BYTE g, BYTE b, BYTE a, char *String )
	{
		int i = 0;

		while ( x < 0 )
		{
			x += cwidth[String[i]];
			++i;

			if ( !String[i] )
			{
				return;
			}
		}

		glColor4ub ( r, g, b, a );
		glRasterPos2i ( x, y );

		glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
		glPushAttrib ( GL_LIST_BIT );
		glListBase ( g_FontListID );
		glCallLists ( strlen ( String ) - i, GL_UNSIGNED_BYTE, String + i );
		glPopAttrib ( );
	}

	void Font::Print ( int x, int y, BYTE r, BYTE g, BYTE b, BYTE a, BYTE Flags, char *String, ... )
	{
		char strText[256];

		va_list argumentPtr;

		va_start ( argumentPtr, String );
		vsprintf_s ( strText, String, argumentPtr );
		va_end ( argumentPtr );

		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

		int drawlen = 0;

		for ( char *p = strText; *p; ++p )
		{
			drawlen += cwidth[*p];
		}

		if ( Flags & FL_CENTER )
		{
			x -= ( drawlen / 2 );
		}

		if ( Flags & FL_OUTLINE )
		{
			Render ( x, y - 1, 0, 0, 0, 200, strText );
			Render ( x, y + 1, 0, 0, 0, 200, strText );
			Render ( x - 1, y, 0, 0, 0, 200, strText );
			Render ( x + 1, y, 0, 0, 0, 200, strText );

			Render ( x - 1, y - 1, 0, 0, 0, 200, strText );
			Render ( x + 1, y - 1, 0, 0, 0, 200, strText );
			Render ( x - 1, y + 1, 0, 0, 0, 200, strText );
			Render ( x + 1, y + 1, 0, 0, 0, 200, strText );
		}

		if ( Flags & FL_BACKDROP )
		{
			Render ( x, y - 1, 0, 0, 0, 255, strText );
			Render ( x, y - 1, 0, 0, 0, 255, strText );
			Render ( x - 1, y, 0, 0, 0, 255, strText );
			Render ( x - 1, y, 0, 0, 0, 255, strText );

			Render ( x - 1, y - 1, 0, 0, 0, 255, strText );
			Render ( x, y - 1, 0, 0, 0, 255, strText );
			Render ( x - 1, y - 1, 0, 0, 0, 255, strText );
			Render ( x, y - 1, 0, 0, 0, 255, strText );
		}

		Render ( x, y, r, g, b, a, strText );

		glDisable ( GL_BLEND );
		glEnable ( GL_TEXTURE_2D );
	}

	Font g_Font, g_Verdana;
}