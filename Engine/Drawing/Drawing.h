#pragma once

#include "Main.h"

namespace Engine
{
	class Drawing
	{
	public:
		//Fill area
		void FillArea ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );
		//Drawing box (style: 1 - GL_QUADS, 2 - GL_LINE_LOOP)
		void DrawBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a , BYTE style );
		//Drawing box with outline (style: 1 - GL_QUADS, 2 - GL_LINE_LOOP)
		void DrawShadowBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );
		//Drawing 3d box on player (style: 1 - GL_LINES, 2 - GL_LINE_LOOP)
		void Draw3DBox ( struct cl_entity_s *Entity, int Index, float lw, BYTE r, BYTE g, BYTE b, BYTE style );
		//Drawing circle
		void DrawCircle ( float x, float y, float rad, int amountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing line
		__inline void DrawLine ( int x1, int y1, int x2, int y2, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );
		//Drawing vector line
		__inline void DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );
	};

	extern Drawing g_Drawing;
}