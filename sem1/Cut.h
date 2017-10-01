//All the info is in the about
#pragma once
#include "Figure.h"
#include "Bresenhem.h"
#include <vector>
using std::pair;
using std::vector;
#include <cmath>
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace sem1 {
	ref class Cut
	{
	public:
		static void process_lines_cut(int x1_cut, int y1_cut, int x2_cut, int y2_cut, List<Figure^>^ lines, Graphics^ im);
	};
}

