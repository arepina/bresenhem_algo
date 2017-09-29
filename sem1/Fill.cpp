//All the info is in the about
#include "Fill.h"
using namespace sem1;
using namespace std;

void up_and_down(System::Collections::Generic::Stack<Point>^ pixel, Bitmap^ bm, Point current, Point right, Color current_pixel_colour, Color next_pixel_color, Color selected_pixel_color)
{
	current_pixel_colour = bm->GetPixel(current.X, current.Y);
	while (current.X < right.X) {
		next_pixel_color = bm->GetPixel(current.X + 1, current.Y);
		if (current_pixel_colour == selected_pixel_color && next_pixel_color != selected_pixel_color) {
			pixel->Push(current);
		}
		current_pixel_colour = next_pixel_color;
		current.X += 1;
	}
	if (current_pixel_colour == selected_pixel_color) {
		pixel->Push(current);
	}
}

System::Void sem1::Fill::row_by_row_fill(System::Collections::Generic::Stack<Point>^ pixel, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, Color current_color)
{
	Point current;
	Color selected_pixel_color = bm->GetPixel(pixel->Peek().X, pixel->Peek().Y); // pixel color we first clicked on
	Color current_pixel_colour; // current pixel color
	Color next_pixel_color; //next pixel color
	Point right, left, start;
	while (pixel->Count > 0) {
		current = pixel->Pop();
		start = Point(current.X, current.Y);//remember the start point	
		//go to the right
		while (current.X + 1 < canvas->Width  && bm->GetPixel(current.X + 1, current.Y) == selected_pixel_color) {
			im->FillRectangle(gcnew SolidBrush(current_color), current.X, current.Y, 1, 1);
			current.X++;
		}
		im->FillRectangle(gcnew SolidBrush(current_color), current.X, current.Y, 1, 1);
		//save the most right pixel
		right = current;

		current = start;//return to start point
		//go to the left from start point
		while (current.X - 1 > 0 && bm->GetPixel(current.X - 1, current.Y) == selected_pixel_color) {
			im->FillRectangle(gcnew SolidBrush(current_color), current.X, current.Y, 1, 1);
			current.X--;
		}
		im->FillRectangle(gcnew SolidBrush(current_color), current.X, current.Y, 1, 1);

		left = current;//save the most left pixel

		//go down
		if (current.Y - 1 >= 0)
		{
			current.Y--;
			up_and_down(pixel, bm, current, right, current_pixel_colour, next_pixel_color, selected_pixel_color);
		}

		//go up
		current = left;
		if (current.Y + 1 < canvas->Height) {
			current.Y += 1;
			up_and_down(pixel, bm, current, right, current_pixel_colour, next_pixel_color, selected_pixel_color);
		}
		canvas->Refresh();
	}
}

System::Void sem1::Fill::xor_fill(System::Collections::Generic::List<Figure^>^ lines, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, Color current_color)
{
	int xmax = -1;
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ f = lines[i];
		if (f->x1 > xmax)
			xmax = f->x1;
		if (f->x2 > xmax)
			xmax = f->x2;
	}
	for (int i = 0; i < lines->Count; i++)
	{
		Figure^ f = lines[i];
		Point p1 = Point(f->x1, f->y1);
		Point p2 = Point(f->x2, f->y2);
		int from, to;
		if (p1.Y > p2.Y) {
			from = p2.Y;
			to = p1.Y;
		}
		else {
			from = p1.Y;
			to = p2.Y;
		}
		for (from; from <= to; from++) {
			float up = (p2.Y - p1.Y);
			float down = (p2.X - p1.X)*(from - p1.Y);
			float cur_x =  up / down + p1.X + 1;
			for (int j = cur_x; j <= xmax; j++)
			{
				if (bm->GetPixel(cur_x, p1.Y) == Color::White)
					im->FillRectangle(gcnew SolidBrush(current_color), (int)cur_x, (int)from, 1, 1);
				else
					im->FillRectangle(gcnew SolidBrush(Color::White), (int)cur_x, (int)from, 1, 1);
				canvas->Refresh();
			}
		}
	}
}

