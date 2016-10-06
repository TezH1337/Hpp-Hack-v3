#pragma once

#include "Main.h"

class Drawing
{
public:

	void FillArea ( int x, int y, int w, int h, int r, int g, int b, int a );
	void FillArea2 ( int x, int y, int w, int h, int r, int g, int b, int a );

	void DrawBox ( int x, int y, int w, int h, int linewidth, int r, int g, int b, int a );
	void DrawBox2 ( int x, int y, int w, int h, int linewidth, int r, int g, int b, int a );

	void DrawShadowBox ( int x, int y, int w, int h, int r, int g, int b, int a );

	void DrawLine ( int x1, int y1, int x2, int y2, int lw, int r, int g, int b );
	void DrawVectorLine ( float *flSrc, float *flDestination, int lw, int r, int g, int b );

};

extern Drawing g_Drawing;