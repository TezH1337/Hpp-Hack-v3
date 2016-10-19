#include "Drawing.h"

namespace Engine
{
	void Drawing::FillArea ( float x, float y, float w, float h, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		if ( g_Offset.HLType != RENDERTYPE_HARDWARE )
		{
			g_Engine.pfnFillRGBA ( ( int )x, ( int )y, ( int )w, ( int )h, r, g, b, a );
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
			glVertex2f ( x, y );
			glVertex2f ( x + w, y );
			glVertex2f ( x + w, y + h );
			glVertex2f ( x, y + h );
			glEnd ( );
			glDisable ( GL_BLEND );
			glEnable ( GL_TEXTURE_2D );
			glPopMatrix ( );
		}
	}

	void Drawing::DrawBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		FillArea ( x, y, w, linewidth, r, g, b, a );
		FillArea ( x + w - linewidth, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea ( x, y + linewidth, linewidth, h - linewidth, r, g, b, a );
		FillArea ( x + linewidth, y + h - linewidth, w - linewidth * 2, linewidth, r, g, b, a );
	}

	void Drawing::DrawShadowBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		DrawBox ( x, y, w, h, linewidth, r, g, b, a );
		DrawBox ( x - 1, y - 1, w + 2, h + 2, 1, 0, 0, 0, a );
		DrawBox ( x + linewidth, y + linewidth, w - linewidth * 2, h - linewidth * 2, 1, 0, 0, 0, a );
	}

	void Drawing::DrawLine ( float x1, float y1, float x2, float y2, float linewidth, BYTE r, BYTE g, BYTE b )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( r, g, b, 255 );
		glLineWidth ( linewidth );
		glBegin ( GL_LINES );
		glVertex2f ( x1, y1 );
		glVertex2f ( x2, y2 );
		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	void Drawing::DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b )
	{
		float ScreenSrc[2], ScreenDest[2];

		if ( !g_Util.CalcScreen ( flSrc, ScreenSrc ) || !g_Util.CalcScreen ( flDestination, ScreenDest ) )
		{
			return;
		}

		g_Drawing.DrawLine ( ScreenSrc[0], ScreenSrc[1], ScreenDest[0], ScreenDest[1], linewidth, r, g, b );
	}

	void Drawing::Draw3DBox ( struct cl_entity_s *Entity, int Index, float lw, BYTE r, BYTE g, BYTE b )
	{
		Vector F, R, U;

		g_Engine.pfnAngleVectors ( Vector ( 0.0f, g_Engine.GetEntityByIndex ( Index )->angles[1], 0.0f ), F, R, U );

		float Forward = Entity->curstate.maxs.y + 15;
		float Back = Entity->curstate.mins.y - 5;
		float Right = Entity->curstate.maxs.x + 5;
		float Left = Entity->curstate.mins.x - 5;

		Vector UFLeft = Entity->origin + U * Entity->curstate.maxs.z + F * Forward + R * Left;
		Vector UFRight = Entity->origin + U * Entity->curstate.maxs.z + F * Forward + R * Right;
		Vector UBLeft = Entity->origin + U * Entity->curstate.maxs.z + F * Back + R * Left;
		Vector UBRight = Entity->origin + U * Entity->curstate.maxs.z + F * Back + R * Right;

		Vector BFLeft = Entity->origin + U * Entity->curstate.mins.z + F * Forward + R * Left;
		Vector BFRight = Entity->origin + U * Entity->curstate.mins.z + F * Forward + R * Right;
		Vector BBLeft = Entity->origin + U * Entity->curstate.mins.z + F * Back + R * Left;
		Vector BBRight = Entity->origin + U * Entity->curstate.mins.z + F * Back + R * Right;

		DrawVectorLine ( UBLeft, UBRight, lw, r, g, b );
		DrawVectorLine ( UBRight, UFRight, lw, r, g, b );
		DrawVectorLine ( UFRight, UFLeft, lw, r, g, b );
		DrawVectorLine ( UFLeft, UBLeft, lw, r, g, b );

		DrawVectorLine ( UBLeft, BBLeft, lw, r, g, b );
		DrawVectorLine ( UBRight, BBRight, lw, r, g, b );
		DrawVectorLine ( UFRight, BFRight, lw, r, g, b );
		DrawVectorLine ( UFLeft, BFLeft, lw, r, g, b );

		DrawVectorLine ( BBLeft, BBRight, lw, r, g, b );
		DrawVectorLine ( BBRight, BFRight, lw, r, g, b );
		DrawVectorLine ( BFRight, BFLeft, lw, r, g, b );
		DrawVectorLine ( BFLeft, BBLeft, lw, r, g, b );
	}

	void Drawing::DrawCircle ( float x, float y, float rad, int amountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a )
	{
		glDisable ( GL_TEXTURE_2D );
		glEnable ( GL_BLEND );
		glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glColor4ub ( r, g, b, a );
		glLineWidth ( linewidth );
		glBegin ( GL_LINE_LOOP );

		for ( int i = 0; i < amountSegments; ++i )
		{
			float angle = 2.0f * 3.1415926f * float ( i ) / float ( amountSegments );

			float dx = rad * cosf ( angle );
			float dy = rad * sinf ( angle );

			glVertex2f ( x + dx, y + dy );
		}

		glEnd ( );
		glColor3f ( 1.0f, 1.0f, 1.0f );
		glEnable ( GL_TEXTURE_2D );
		glDisable ( GL_BLEND );
	}

	Drawing g_Drawing;
}