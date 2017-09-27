//All the info is in the about
#include "Fill.h"
using namespace sem1;
using namespace std;

System::Void sem1::Fill::row_by_row_fill(stack<pair<int, int>> pixel, int ex, int ey, SolidBrush^ fill_color, Bitmap^ bm, Graphics^ im, PictureBox^ canvas, PictureBox^ current_color)
{
	pair<int, int> current;
	Color^ selected_pixel_color = bm->GetPixel(ex, ey);
	Color^ current_pixel_colour;
	int xright, xleft, start_x;
	while (!pixel.empty()) {
		current = pixel.top();
		pixel.pop();
		int cur_x = current.first;
		int cur_y = current.second;
		start_x = cur_x;//remember the start point	
		current_pixel_colour = bm->GetPixel(cur_x, cur_y);
		//go to the right
		while (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color)) {
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), cur_x, cur_y, 1, 1);
			cur_x = cur_x + 1;
			current_pixel_colour = bm->GetPixel(cur_x, cur_y);
		}
		canvas->Refresh();
		//save the most right pixel
		xright = cur_x - 1;
		//go to the left from start point
		cur_x = start_x - 1;
		current_pixel_colour = bm->GetPixel(cur_x, cur_y);
		while (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color)) {
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), cur_x, cur_y, 1, 1);
			cur_x = cur_x - 1;
			current_pixel_colour = bm->GetPixel(cur_x, cur_y);
		}
		canvas->Refresh();
		//save the most left pixel
		xleft = cur_x + 1;
		cur_y = cur_y - 1;//go down
		for (cur_x = xleft; cur_x <= xright + 1; cur_x++)
		{
			current_pixel_colour = bm->GetPixel(cur_x, cur_y);
			if (!current_pixel_colour->Equals(selected_pixel_color) && current_pixel_colour->Equals(fill_color->Color))
				pixel.push(make_pair(cur_x - 1, cur_y));
		}
		canvas->Refresh();
		//go up
		cur_y = cur_y + 2;
		for (cur_x = xleft; cur_x <= xright + 1; cur_x++)
		{
			current_pixel_colour = bm->GetPixel(cur_x, cur_y);
			if (!current_pixel_colour->Equals(selected_pixel_color) && current_pixel_colour->Equals(fill_color->Color))
				pixel.push(make_pair(cur_x - 1, cur_y));
		}
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

