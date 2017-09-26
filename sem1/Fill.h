#pragma once
#include <stack>
using std::stack;
using std::pair;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace sem1 {

	ref class Fill
	{
	public:
		static void row_by_row_fill(stack<pair<int, int>> pixel, int ex, int ey, SolidBrush^ fill_color, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, PictureBox^ current_color);
		static void xor_fill(int ex, int ey);
	};
}

