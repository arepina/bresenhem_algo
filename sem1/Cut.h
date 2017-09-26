#pragma once
#include <vector>
using std::pair;
using std::vector;
#include <cmath>
using namespace System::Drawing;

namespace sem1 {
	ref class Cut
	{
	public:
		static void window(int ex, int ey, int x1_cut, int x2_cut, int y1_cut, int y2_cut, Graphics^ im, Pen^ p, vector<pair<pair<int*, int*>, pair<int*, int*>>>* lines_vector);
		static void process_lines_cut(int x1_cut, int y1_cut, int x2_cut, int y2_cut, vector<pair<pair<int*, int*>, pair<int*, int*>>>* lines_vector);
	};
}

