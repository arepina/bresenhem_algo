//All the info is in the about
#include "Fill.h"
using namespace sem1;
using namespace std;


System::Void sem1::Fill::row_by_row_fill(System::Collections::Generic::Stack<Point>^ pixel, SolidBrush^ fill_color, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, PictureBox^ current_color)
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
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), current.X, current.Y, 1, 1);
			current.X++;
		}
		im->FillRectangle(gcnew SolidBrush(current_color->BackColor), current.X, current.Y, 1, 1);
		//save the most right pixel
		right = current;

		current = start;
		//go to the left from start point
		while (current.X - 1 > 0 && bm->GetPixel(current.X - 1, current.Y) == selected_pixel_color) {
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), current.X, current.Y, 1, 1);
			current.X--;
		}
		im->FillRectangle(gcnew SolidBrush(current_color->BackColor), current.X, current.Y, 1, 1);
		//save the most left pixel
		left = current; //not on the border now

		if (current.Y - 1 >= 0)
		{
			current.Y--;//go down
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

		//go up
		current = left;
		if (current.Y + 1 < canvas->Height) {
			current.Y += 1;
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
		//system("pause");
		canvas->Refresh();
	}
}

System::Void sem1::Fill::xor_fill(int ex, int ey)
{
	/*int ymax, xmax;
	bool flag = false;
	for (int y = 0; y < ymax; y++)
	{
	flag = false;
	for (int x = 0; x < xmax; x++)
	{
	if (i[x, y] == 1)
	{
	flag = !flag;
	}
	if (flag)
	i[x, y] = 1;
	}
	}*/
}

