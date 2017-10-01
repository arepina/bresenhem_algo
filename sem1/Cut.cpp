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
	if (P.X < xl)
		code = code | LEFT;
	if (P.X > xp) 
		code = code | RIGHT;
	if (P.Y > yl)
		code = code | BOTTOM;
	if (P.Y < yp) 
		code = code | TOP;
	return code;
}

List<Point>^ get_pixels(Point p1, Point p2)
{
	List<Point> ^pixels = gcnew List<Point>();
	Point start, finish;
	if (p1.Y > p2.Y)
	{
		start = p2;
		finish = p1;
	}
	else
	{
		start = p1;
		finish = p2;
	}
	for (start.Y; start.Y <= finish.Y; start.Y++)
	{
		float down = (p1.Y - p2.Y);
		float up = (start.Y - p1.Y) * (p1.X - p2.X) + p1.X*(p1.Y - p2.Y);
		float cur_x = up / down;//find the x from point and add 1 because it is border
		pixels->Add(Point(cur_x, start.Y));
	}
	return pixels;
}

System::Void sem1::Cut::process_lines_cut(int xl, int xp, int yp, int yl, List<Figure^>^ lines, Graphics^ im)
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
			im->DrawLine(gcnew Pen(Color::Green), P1.X, P1.Y, P2.X, P2.Y);
			continue;
		}
		// fully invisible
		if ((p1kod & p2kod) > 0) {
			im->DrawLine(gcnew Pen(Color::Red), P1.X, P1.Y, P2.X, P2.Y);
			continue;
		}
		//partly visible
		List<Point>^ pixels = get_pixels(P1, P2);
		for (int i = 0; i < pixels->Count; i++)
		{
			Point cur = pixels[i];
			if (xl < cur.X && cur.X < xp && yp < cur.Y && cur.Y < yl)
				im->FillRectangle(gcnew SolidBrush(Color::Green), cur.X,  cur.Y, 1, 1);
			else
				im->FillRectangle(gcnew SolidBrush(Color::Red), cur.X, cur.Y, 1, 1);
		}
		/*Point P;
		int temp;
		//Decide if point1 is inside. if not calculate intersection
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

		//Check which point we had selected earlier as temp, and replace its co-ordinates
		if (temp == p1kod) {
			P1.X = P.X;
			P1.Y = P.Y;
			p1kod = getcode(P1, xl, xp, yl, yp);
		}
		else {
			P2.X = P.X;
			P2.Y = P.Y;
			p2kod = getcode(P2, xl, xp, yl, yp);
		}
		
		im->DrawLine(gcnew Pen(Color::Green), P1.X, P1.Y, P2.X, P2.Y);
		int new_x1 = -1, new_x2 = -1, new_y1 = -1, new_y2 = -1;
		if (p_sum->x1 != P1.X)
		{
			new_x1 = p_sum->x1;
			new_y1 = p_sum->y1;
			new_x2 = P1.X;
			new_y2 = P1.Y;
			im->DrawLine(gcnew Pen(Color::Red), new_x1, new_y1, new_x2, new_y2);
		}
		if (p_sum->x2 != P2.X)
		{
			new_x1 = p_sum->x2;
			new_y1 = p_sum->y2;
			new_x2 = P2.X;
			new_y2 = P2.Y; 
			im->DrawLine(gcnew Pen(Color::Red), new_x1, new_y1, new_x2, new_y2);
		}*/
	}
}