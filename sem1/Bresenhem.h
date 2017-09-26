#pragma once
#include <vector>
using std::pair;
using std::vector;
using namespace System::Drawing;

namespace sem1 {

	ref class Bresenhem
	{

	public:
		static void bres_line(int x1, int y1, int x2, int y2, Graphics^ im, Brush^ b);//bresenham line algo
		static void bres_circle(int x1, int y1, int rad_first, Graphics^ im, Brush^ b);//bresenham circle algo
		static void bres_ellipse(int x1, int y1, int rad_first, int rad_second, Graphics^ im, Brush^ b);//ellipse algo
		static void draw_pixels(int x, int y, int x1, int y1, Graphics^ im, Brush^ b);//place pixels on canvas
	};
}

