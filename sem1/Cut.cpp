//All the info is in the about
#include "Cut.h"

using namespace sem1;
using namespace std;
using namespace System::Collections::Generic;

System::Void sem1::Cut::process_lines_cut(int xl, int yn, int xp, int yv, List<Figure^>^ lines, Graphics^ im)
{
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ p_sum = lines[i];
		Point P1 = Point(p_sum->x1, p_sum->y1);
		Point P2 = Point(p_sum->x2, p_sum->y2);
		int p1kod = 0;
		if (P1.X < xl) p1kod = p1kod | 1;
		if (P1.X > xp) p1kod = p1kod | 2;
		if (P1.Y < yn) p1kod = p1kod | 4;
		if (P1.Y > yv) p1kod = p1kod | 8;
		int p2kod = 0;
		if (P2.X < xl) p1kod = p2kod | 1;
		if (P2.X > xp) p1kod = p2kod | 2;
		if (P2.Y < yn) p1kod = p2kod | 4;
		if (P2.Y > yv) p1kod = p2kod | 8;
		int flag = 0;
		Point see_p1 = P1;
		Point see_p2 = P2;
		int m = (unsigned int)-1;
		// fully visible
		if (p1kod == 0 && p2kod == 0)
			im->DrawLine(gcnew Pen(Color::Green), see_p1.X, see_p1.Y, see_p2.X, see_p2.Y);
		// fully invisible
		if ((p1kod & p2kod) > 0)
			flag = -1;
		// partly visible
		//need to determite whether one of the ends is inside the window

			/*
			Определить точки пересечения прямых xl, xp, yv, yn и отрезка
			Определить корректность точек пересечения
			Вывести видимые части отрезков*/		/*		int m = (P2.Y- y1) / (x2 - x1);
		int y_xl_peresech = m*(xl - x1) + y1;
		int y_xp_peresech = m*(xp - x1) + y1;
		int x_yv_peresech = x1 + (1 / m)*(yv - y1);
		int x_yn_peresech = x1 + (1 / m)*(yn - y1);*/


	}
}
