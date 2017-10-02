//All the info is in the about
#include "Cut.h"
#include <stdio.h>

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

void draw(int p1kod, int p2kod, Point P1, Point P2, int xp, int yp, int xl, int yl, Graphics^ im, bool is_before)
{
	// fully visible
	if (p1kod == 0 && p2kod == 0) {
		im->DrawLine(gcnew Pen(Color::Green), P1.X, P1.Y, P2.X, P2.Y);
		return;
	}
	// fully invisible
	if ((p1kod & p2kod) > 0 && is_before) {
		im->DrawLine(gcnew Pen(Color::Red), P1.X, P1.Y, P2.X, P2.Y);
		return;
	}
	//partly visible
	List<Point>^ pixels = Bresenhem::bres_line_pixels(P1, P2);
	for (int i = 0; i < pixels->Count; i++)
	{
		Point cur = pixels[i];
		if (xl < cur.X && cur.X < xp && yp < cur.Y && cur.Y < yl)
			im->FillRectangle(gcnew SolidBrush(Color::Yellow), cur.X, cur.Y, 1, 1);
		else if(is_before)
			im->FillRectangle(gcnew SolidBrush(Color::Red), cur.X, cur.Y, 1, 1);
	}
}

System::Void sem1::Cut::process_lines_cut(int xl, int xp, int yp, int yl, List<Figure^>^ lines, Graphics^ im, PictureBox^ canvas)
{
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(xl, yp, abs(xl - xp), abs(yl - yp));
	im->DrawRectangle(gcnew Pen(Color::Black), rect);
	canvas->Refresh();
	im->Clear(Color::White);
	_sleep(3000);
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ p_sum = lines[i];
		Point P1 = Point(p_sum->x1, p_sum->y1);
		Point P2 = Point(p_sum->x2, p_sum->y2);
		int p1kod = getcode(P1, xl, xp, yl, yp);
		int p2kod = getcode(P2, xl, xp, yl, yp);
		draw(p1kod, p2kod, P1, P2, xp, yp, xl, yl, im, true);
	}
	im->DrawRectangle(gcnew Pen(Color::Black), rect);
	canvas->Refresh();
	im->Clear(Color::White);
	_sleep(3000);
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ p_sum = lines[i];
		Point P1 = Point(p_sum->x1, p_sum->y1);
		Point P2 = Point(p_sum->x2, p_sum->y2);
		int p1kod = getcode(P1, xl, xp, yl, yp);
		int p2kod = getcode(P2, xl, xp, yl, yp);
		draw(p1kod, p2kod, P1, P2, xp, yp, xl, yl, im, false);
	}
}