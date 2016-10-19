#pragma once

#include "Main.h"

namespace Engine
{
	class Drawing
	{
	private:
		//Drawing line
		__inline void DrawLine ( float x1, float y1, float x2, float y2, float linewidth, BYTE r, BYTE g, BYTE b );
		//Drawing vector line
		__inline void DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b );

	public:
		//Fill area
		void FillArea ( float x, float y, float w, float h, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing box
		void DrawBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing box with outline
		void DrawShadowBox ( float x, float y, float w, float h, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		//Drawing 3d box on player
		void Draw3DBox ( struct cl_entity_s *Entity, int Index, float lw, BYTE r, BYTE g, BYTE b );
		//Drawing circle
		void DrawCircle ( float x, float y, float rad, int amountSegments, float linewidth, BYTE r, BYTE g, BYTE b, BYTE a );		
	};

	extern Drawing g_Drawing;
}