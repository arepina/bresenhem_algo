#include "Bresenhem.h"
using namespace sem1;
using namespace std;

System::Void sem1::Bresenhem::bres_line(int x1, int y1, int x2, int y2, Graphics^ im, Brush^brush)
{
	int x = x1;
	int y = y1;
	int delta_x = abs(x2 - x1);
	int delta_y = abs(y2 - y1);
	int s1 = x2 - x1 >= 0 ? 1 : -1;
	int s2 = y2 - y1 >= 0 ? 1 : -1;
	int obmen = 0;
	if (delta_y > delta_x)
	{
		int temp = delta_x;
		delta_x = delta_y;
		delta_y = temp;
		obmen = 1;
	}
	else
		obmen = 0;
	int error_val = 2 * delta_y - delta_x;
	for (int i = 1; i <= delta_x; i++)
	{
		im->FillRectangle(brush, x, y, 1, 1);
		while (error_val >= 0)
		{
			obmen == 1 ? x = x + s1 : y = y + s2;
			error_val = error_val - 2 * delta_x;
		}
		obmen == 1 ? y = y + s2 : x = x + s1;
		error_val = error_val + 2 * delta_y;
	}
}

System::Void sem1::Bresenhem::bres_circle(int x1, int y1, int rad_first, Graphics^ im, Brush^brush)
{
	int rad_second = rad_first;
	bres_ellipse(x1, y1, rad_first, rad_second, im, brush);
}

System::Void sem1::Bresenhem::bres_ellipse(int x1, int y1, int rad_first, int rad_second, Graphics^ im, Brush^brush)
{
	int x = 0;
	int y = rad_second;
	int sigma = 0;
	int a = rad_first;
	int b = rad_second;
	//b^2(0+1)^2-a^2*(y-1)^2-a^2b^2 = b^2-a^2*(b-1)^2-a^2b^2 = b^2-a^2*(b-1)-a^2(2b - 1)
	int delta = b*b - a*a * (2 * b - 1);
	int predel = 0;
	do
	{
		draw_pixels(x, y, x1, y1, im, brush);//draw 4 pixels on the canvas having only one coordinate
		if (y <= predel)
			return;
		if (delta < 0)
		{
			sigma = (int)(2 * delta + a*a * (2 * y - 1));//choose between diagonal and horizontal
			if (sigma <= 0)
			{
				x = x + 1;
				delta = (int)(delta + b*b*(2 * x + 1));//horizontal
			}
			else {
				x = x + 1;
				y = y - 1;
				delta = (int)(delta + b*b*(2 * x + 1) - a*a*(2 * y - 1));//diagonal
			}
		}
		else if (delta > 0)
		{
			sigma = (int)(2 * delta - b*b * (2 * x - 1));;//choose between diagonal and vertical
			if (sigma <= 0)
			{
				x = x + 1;
				y = y - 1;
				delta = (int)(delta + b*b*(2 * x + 1) - a*a*(2 * y - 1));//diagonal
			}
			else {
				y = y - 1;
				delta = (int)(delta - a*a*(2 * y - 1));//vertical
			}
		}
		else {
			x = x + 1;
			y = y - 1;
			delta = (int)(delta + b*b*(2 * x + 1) - a*a*(2 * y - 1));//diagonal
		}
	} while (true);
}

System::Void sem1::Bresenhem::draw_pixels(int x, int y, int x1, int y1, Graphics^ im, Brush^b)
{
	im->FillRectangle(b, x + x1, y + y1, 1, 1);
	im->FillRectangle(b, x1 - x, y + y1, 1, 1);
	im->FillRectangle(b, x + x1, y1 - y, 1, 1);
	im->FillRectangle(b, x1 - x, y1 - y, 1, 1);
}
