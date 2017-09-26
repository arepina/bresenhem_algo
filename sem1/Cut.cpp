#include "Cut.h"
using namespace sem1;
using namespace std;

System::Void sem1::Cut::window(int ex, int ey, int x1_cut, int x2_cut, int y1_cut, int y2_cut, Graphics^ im, Pen^ p, vector<pair<pair<int*, int*>, pair<int*, int*>>>* lines_vector)
{
	if (x1_cut == -1)
	{
		x1_cut = ex;
		y1_cut = ey;
	}
	else {
		if (ex < x1_cut) {
			x2_cut = x1_cut;
			x1_cut = ex;
		}
		else
			x2_cut = ex;
		if (ey < y1_cut) {
			y2_cut = y1_cut;
			y1_cut = ey;
		}
		else
			y2_cut = ey;
		System::Drawing::Rectangle rect = System::Drawing::Rectangle(x1_cut, y1_cut, abs(x2_cut - x1_cut), abs(y2_cut - y1_cut));
		im->DrawRectangle(p, rect);
		process_lines_cut(x1_cut, y1_cut, x2_cut, y2_cut, lines_vector);
		x1_cut = -1;
		y1_cut = -1;
	}
}

System::Void sem1::Cut::process_lines_cut(int x1_cut, int y1_cut, int x2_cut, int y2_cut, vector<pair<pair<int*, int*>, pair<int*, int*>>>* lines_vector)
{
	size_t i = lines_vector->size() - 1;
	while (!lines_vector->empty())
	{
		pair<pair<int*, int*>, pair<int*, int*>> p_sum = lines_vector->at(i);
		lines_vector->pop_back();
		int g1 = (int)p_sum.first.first;
		int g2 = (int)p_sum.first.second;
		int g3 = (int)p_sum.second.first;
		int g4 = (int)p_sum.second.second;
		//todo analise how to color the lines
		i--;
	}
}
