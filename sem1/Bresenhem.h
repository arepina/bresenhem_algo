//All the info is in the about
#pragma once
#include <vector>
using std::pair;
using std::vector;
using namespace System::Drawing;
#include "Figure.h"

namespace sem1 {

	ref class Bresenhem
	{

	public:
		static System::Collections::Generic::List<Point>^ bres_line_pixels(Point start, Point finish);
		static void bres_line(Figure^ f, Graphics^ im, Brush^ b);//bresenham line algo
		static void bres_circle(Figure^ f, Graphics^ im, Brush^ b);//bresenham circle algo
		static void bres_ellipse(Figure^ f, Graphics^ im, Brush^ b);//ellipse algo
		static void draw_pixels(int x, int y, int x1, int y1, Graphics^ im, Brush^ b);//place pixels on canvas
	};
}

