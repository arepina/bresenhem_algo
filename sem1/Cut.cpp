//All the info is in the about
#include "Cut.h"

using namespace sem1;
using namespace std;
using namespace System::Collections::Generic;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int getcode(Point P, int xl, int xp, int yl, int yp)
{
	int code = 0;
	//Peform Bitwise OR to get outcode
	if (P.X < xl) code = code | LEFT;
	if (P.X > xp) code = code | RIGHT;
	if (P.Y < yp) code = code | TOP;
	if (P.Y > yl) code = code | BOTTOM;
	return code;
}

System::Void sem1::Cut::process_lines_cut(int xl, int yl, int xp, int yp, List<Figure^>^ lines, Graphics^ im)
{
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ p_sum = lines[i];
		Point P1 = Point(p_sum->x1, p_sum->y1);
		Point P2 = Point(p_sum->x2, p_sum->y2);
		int p1kod = getcode(P1, xl, xp, yl, yp);
		int p2kod = getcode(P2, xl, xp, yl, yp);
		float m = (float)(P2.Y - P1.Y) / (P2.X - P1.X);
		// fully visible
		if (p1kod == 0 && p2kod == 0) {
			im->DrawLine(gcnew Pen(Color::Aquamarine), P1.X, P1.Y, P2.X, P2.Y);
			continue;
		}
		// fully invisible
		if ((p1kod & p2kod) > 0) {
			continue;
		}
		Point P;
		int temp;
		//Decide if point1 is inside. if not calculate ntersection
		if (p1kod == 0) temp = p2kod;
		else temp = p1kod;
		if (temp & TOP) {//Line clips top edge
			P.X = P1.X + (yp - P1.Y) / m;
			P.Y = yp;
		}
		else if (temp & BOTTOM) { //Line clips bottom edge
			P.X = P1.X + (yl - P1.Y) / m;
			P.Y = yl;
		}
		else if (temp & LEFT) {//Line clips left edge
			P.X = xl;
			P.Y = P1.Y + m * (xl - P1.X);
		}
		else if (temp & RIGHT) {//Line clips right edge
			P.X = xp;
			P.Y = P1.Y + m * (xp - P1.X);
		}
		if (temp == p1kod) { //Check which point we had selected earlier as temp, and replace its co-ordinates
			P1.X = P.X;
			P1.Y = P.Y;
			p1kod = getcode(P1, xl, xp, yl, yp);
		}
		else {
			P2.X = P.X;
			P2.Y = P.Y;
			p2kod = getcode(P2, xl, xp, yl, yp);
		}
		
		im->DrawLine(gcnew Pen(Color::Aquamarine), P1.X, P1.Y, P2.X, P2.Y);
	}
}
// partly visible
//need to determite whether one of the ends is inside the window

	/*
	Определить точки пересечения прямых xl, xp, yv, yn и отрезка
	Определить корректность точек пересечения
	Вывести видимые части отрезков*/	/*m = (P2.Y- P1.Y) / (P2.X - P1.X);
	int y_xl_peresech = m*(xl - P1.X) + P1.Y;
	int y_xp_peresech = m*(xp - P1.X) + P1.Y;
	int x_yv_peresech = P1.X + (1 / m)*(yv - P1.Y);
	int x_yn_peresech = P1.X + (1 / m)*(yn - P1.Y);*/

