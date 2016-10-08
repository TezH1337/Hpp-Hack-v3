#include "Drawing.h"

namespace Engine
{
	void Drawing::FillArea ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		if ( g_Offset->HLType != RENDERTYPE_HARDWARE )
		{
			g_Engine.pfnFillRGBA ( x, y, w, h, r, g, b, a );
		}
		else
		{
			glPushMatrix ( );
			glLoadIdentity ( );
			glDisable ( GL_TEXTURE_2D );
			glEnable ( GL_BLEND );
			glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glColor4ub ( r, g, b, a );
			glBegin ( GL_QUADS );
			glVertex2i ( x, y );
			glVertex2i ( x + w, y );
			glVertex2i ( x + w, y + h );
			glVertex2i ( x, y + h );
			glEnd ( );
			glDisable ( GL_BLEND );
			glEnable ( GL_TEXTURE_2D );
			glPopMatrix ( );
		}
	}

	void Drawing::FillArea2 ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		if ( g_Offset->HLType != RENDERTYPE_HARDWARE )
		{
			g_Engine.pfnFillRGBA ( x, y, w, h, r, g, b, a );
		}
		else
		{
			glPushMatrix ( );
			glLoadIdentity ( );
			glDisable ( GL_TEXTURE_2D );
			glEnable ( GL_BLEND );
			glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glColor4ub ( r, g, b, a );
			glBegin ( GL_LINE_LOOP );
			glVertex2i ( x, y );
			glVertex2i ( x + w, y );
			glVertex2i ( x + w, y + h );
			glVertex2i ( x, y + h );
			glEnd ( );
			glDisable ( GL_BLEND );
			glEnable ( GL_TEXTURE_2D );
			glPopMatrix ( );
		}
	}

	void Drawing::DrawBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		FillArea ( x, y, w, linewidth, r, g, b, a );
		FillArea ( x + w - linewidth, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea ( x, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea ( x + linewidth, y + h - linewidth, w - linewidth * 2, linewidth, r, g, b, a );
	}

	void Drawing::DrawBox2 ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		FillArea2 ( x, y, w, linewidth, r, g, b, a );
		FillArea2 ( x + w - linewidth, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea2 ( x, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea2 ( x + linewidth, y + h - linewidth, w - linewidth * 2, linewidth, r, g, b, a );
	}

	void Drawing::DrawShadowBox ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		DrawBox ( x, y, w, h, 1, r, g, b, a );
		DrawBox ( x - 1, y - 1, w + 2, h + 2, 1, 0, 0, 0, a );
		DrawBox ( x + 1, y + 1, w - 2, h - 2, 1, 0, 0, 0, a );
	}

	void Drawing::DrawLine ( int x1, int y1, int x2, int y2, float lw, BYTE r, BYTE g, BYTE b )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( r, g, b, 255 );
		glLineWidth ( lw );
		glBegin ( GL_LINES );
		glVertex2i ( x1, y1 );
		glVertex2i ( x2, y2 );
		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	void Drawing::DrawVectorLine ( float *flSrc, float *flDestination, float lw, BYTE r, BYTE g, BYTE b )
	{
		Vector vScreenSrc, vScreenDest;

		if ( !g_Util.CalcScreen ( flSrc, vScreenSrc ) || !g_Util.CalcScreen ( flDestination, vScreenDest ) )
		{
			return;
		}

		g_Drawing->DrawLine ( ( int )vScreenSrc[0], ( int )vScreenSrc[1], ( int )vScreenDest[0], ( int )vScreenDest[1], lw, r, g, b );
	}

	Drawing* g_Drawing = new Drawing;
}