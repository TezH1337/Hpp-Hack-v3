#pragma once

#include "Main.h"

namespace Engine
{
	class Drawing
	{
	public:
		void FillArea ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a );
		void FillArea2 ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a );

		void DrawBox ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a );
		void DrawBox2 ( int x, int y, int w, int h, int linewidth, BYTE r, BYTE g, BYTE b, BYTE a );

		void DrawShadowBox ( int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a );

		void DrawLine ( int x1, int y1, int x2, int y2, float lw, BYTE r, BYTE g, BYTE b );
		void DrawVectorLine ( float *flSrc, float *flDestination, float lw, BYTE r, BYTE g, BYTE b );
	};

	extern Drawing* g_Drawing;
}