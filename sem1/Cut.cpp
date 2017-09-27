//All the info is in the about
#include "Cut.h"
using namespace sem1;
using namespace std;

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
