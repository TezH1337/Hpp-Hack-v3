#pragma once

#include "Main.h"

namespace Engine
{
	class Drawing
	{
	public:
		void FillArea ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );

		void DrawBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a , BYTE style );

		void DrawShadowBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a, BYTE style );

		void DrawLine ( int x1, int y1, int x2, int y2, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );
		void DrawVectorLine ( float *flSrc, float *flDestination, float linewidth, BYTE r, BYTE g, BYTE b, BYTE style );

		void Draw3DBox ( int Index, float lw, BYTE r, BYTE g, BYTE b, BYTE style );
	};

	extern Drawing* g_Drawing;
}