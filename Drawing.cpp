#include "Drawing.h"

namespace Engine
{
	void Drawing::FillArea ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style )
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

			switch ( style )
			{
			case 1:
				glBegin ( GL_QUADS );
			case 2:
				glBegin ( GL_LINE_LOOP );
			}

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

	void Drawing::DrawBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style )
	{
		FillArea ( x, y, w, linewidth, r, g, b, a, style );
		FillArea ( x + w - linewidth, y + linewidth, linewidth, h - linewidth, r, g, b, a, style );
		FillArea ( x, y + linewidth, linewidth, h - linewidth, r, g, b, a, style );
		FillArea ( x + linewidth, y + h - linewidth, w - linewidth * 2, linewidth, r, g, b, a, style );
	}

	void Drawing::DrawShadowBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style )
	{
		DrawBox ( x, y, w, h, linewidth, r, g, b, a, style );
		DrawBox ( x - 1, y - 1, w + 2, h + 2, 1, 0, 0, 0, a, style );
		DrawBox ( x + 1, y + 1, w - 2, h - 2, 1, 0, 0, 0, a, style );
	}

	void Drawing::DrawLine ( int x1, int y1, int x2, int y2, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( r, g, b, 255 );
		glLineWidth ( linewidth );

		switch ( style )
		{
		case 1:
			glBegin ( GL_LINES );
		case 2:
			glBegin ( GL_LINE_LOOP );
		}

		glVertex2i ( x1, y1 );
		glVertex2i ( x2, y2 );
		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	void Drawing::DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style )
	{
		Vector ScreenSrc, ScreenDest;

		if ( !g_Util.CalcScreen ( flSrc, ScreenSrc ) || !g_Util.CalcScreen ( flDestination, ScreenDest ) )
		{
			return;
		}

		g_Drawing->DrawLine ( ( int )ScreenSrc[0], ( int )ScreenSrc[1], ( int )ScreenDest[0], ( int )ScreenDest[1], linewidth, r, g, b, style );
	}

	void Drawing::Draw3DBox ( int Index, float lw, BYTE r, BYTE g, BYTE b, BYTE style )
	{
		Vector F, R, U;

		g_Engine.pfnAngleVectors ( Vector ( 0.0f, g_Player[Index]->Entity->angles[1], 0.0f ), F, R, U );

		float Forward = g_Player[Index]->Maxs.y + 15;
		float Back = g_Player[Index]->Mins.y - 5;
		float Right = g_Player[Index]->Maxs.x + 5;
		float Left = g_Player[Index]->Mins.x - 5;

		Vector UFLeft = g_Player[Index]->Origin + U * g_Player[Index]->Maxs.z + F * Forward + R * Left;
		Vector UFRight = g_Player[Index]->Origin + U * g_Player[Index]->Maxs.z + F * Forward + R * Right;
		Vector UBLeft = g_Player[Index]->Origin + U * g_Player[Index]->Maxs.z + F * Back + R * Left;
		Vector UBRight = g_Player[Index]->Origin + U * g_Player[Index]->Maxs.z + F * Back + R * Right;

		Vector BFLeft = g_Player[Index]->Origin + U * g_Player[Index]->Mins.z + F * Forward + R * Left;
		Vector BFRight = g_Player[Index]->Origin + U * g_Player[Index]->Mins.z + F * Forward + R * Right;
		Vector BBLeft = g_Player[Index]->Origin + U * g_Player[Index]->Mins.z + F * Back + R * Left;
		Vector BBRight = g_Player[Index]->Origin + U * g_Player[Index]->Mins.z + F * Back + R * Right;

		DrawVectorLine ( UBLeft, UBRight, lw, r, g, b, style );
		DrawVectorLine ( UBRight, UFRight, lw, r, g, b, style );
		DrawVectorLine ( UFRight, UFLeft, lw, r, g, b, style );
		DrawVectorLine ( UFLeft, UBLeft, lw, r, g, b, style );

		DrawVectorLine ( UBLeft, BBLeft, lw, r, g, b, style );
		DrawVectorLine ( UBRight, BBRight, lw, r, g, b, style );
		DrawVectorLine ( UFRight, BFRight, lw, r, g, b, style );
		DrawVectorLine ( UFLeft, BFLeft, lw, r, g, b, style );

		DrawVectorLine ( BBLeft, BBRight, lw, r, g, b, style );
		DrawVectorLine ( BBRight, BFRight, lw, r, g, b, style );
		DrawVectorLine ( BFRight, BFLeft, lw, r, g, b, style );
		DrawVectorLine ( BFLeft, BBLeft, lw, r, g, b, style );
	}

	Drawing* g_Drawing = new Drawing;
}