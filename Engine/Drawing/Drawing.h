#pragma once

#include "Main.h"

namespace Engine
{
	class Drawing
	{
	public:
		//Fill area
		void FillArea ( float x, float y, float w, float h, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );
		//Drawing box (style: 1 - GL_QUADS, 2 - GL_LINE_LOOP)
		void DrawBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );
		//Drawing box with outline (style: 1 - GL_QUADS, 2 - GL_LINE_LOOP)
		void DrawShadowBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );
		//Drawing 3d box on player (style: 1 - GL_LINES, 2 - GL_LINE_LOOP)
		void Draw3DBox ( struct cl_entity_s *Entity, int Index, float lw, BYTE r, BYTE g, BYTE b, BYTE style );
		//Drawing circle
		void DrawCircle ( float x, float y, float rad, int amountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing line
		__inline void DrawLine ( float x1, float y1, float x2, float y2, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );
		//Drawing vector line
		__inline void DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );
	};

	extern Drawing g_Drawing;
}