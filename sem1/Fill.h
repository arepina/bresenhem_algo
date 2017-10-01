//All the info is in the about
#pragma once
#include <stack>
#include "Figure.h"
using std::stack;
using std::pair;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace sem1 {

	ref class Fill
	{
	public:
		static void row_by_row_fill(System::Collections::Generic::Stack<Point>^ pixel, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, Color current_color);
		static void xor_fill(System::Collections::Generic::List<Figure^>^ lines, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, Color current_color, Color background_color, Color border_color);
	};
}

