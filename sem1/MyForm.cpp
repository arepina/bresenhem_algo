#include "MyForm.h"
#include <Windows.h>
using namespace sem1; //пространство имен из заголовочного файла формы !!!
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

/*
clean the canvas
*/
System::Void sem1::MyForm::cleanCanvas()
{
	im->Clear(col->White);
}

/*
bresenham line algo
*/
System::Void sem1::MyForm::bres_line()
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
		im->FillRectangle(blueBrush, x, y, 1, 1);
		while (error_val >= 0)
		{
			obmen == 1 ? x = x + s1 : y = y + s2;
			error_val = error_val - 2 * delta_x;
		}
		obmen == 1 ? y = y + s2 : x = x + s1;
		error_val = error_val + 2 * delta_y;
	}
}

/*
bresenham circle algo
*/
System::Void sem1::MyForm::bres_circle()
{
	int x = 0;
	int y = rad_first;
	int delta = 2 * (1 - rad_first);
	int predel = 0;
	int sigma = 0;
	do
	{
		draw_pixels(x, y);
		if (y <= predel)
			return;
		if (delta < 0)
		{
			sigma = 2 * delta + 2 * y - 1;
			if (sigma <= 0)
			{
				x = x + 1;
				delta = delta + 2 * x + 1;
			}
			else {
				x = x + 1;
				y = y - 1;
				delta = delta + 2 * x - 2 * y + 2;
			}
		}
		else if (delta > 0)
		{
			sigma = 2 * delta - 2 * x - 1;
			if (sigma <= 0)
			{
				x = x + 1;
				y = y - 1;
				delta = delta + 2 * x - 2 * y + 2;
			}
			else {
				y = y - 1;
				delta = delta - 2 * y + 1;
			}
		}
		else {
			x = x + 1;
			y = y - 1;
			delta = delta + 2 * x - 2 * y + 2;
		}

	} while (true);
}

/*
ellipse algo
*/
System::Void sem1::MyForm::bres_ellipse()
{
	int delta_rad1 = 1 - 2 * rad_first;
	int delta_rad2 = 1 - 2 * rad_second;
	// first two parts of ellipse
	int x = 0;
	int y = rad_second;
	int sigma = (int)(2 * pow(rad_second, 2) + pow(rad_first, 2) * delta_rad2);
	draw_part(x, y, rad_first, rad_second, sigma, true);
	// second two parts of ellipse
	x = rad_first;
	y = 0;
	sigma = (int)(2 * pow(rad_first, 2) + pow(rad_second, 2) * delta_rad1);
	draw_part(y, x, rad_second, rad_first, sigma, false);
}

System::Void sem1::MyForm::draw_part(int x, int y, int rad_one, int rad_two, int sigma, bool which_part)
{
	while (pow(rad_two, 2) * x <= pow(rad_one, 2) * y)
	{
		which_part ? draw_pixels(x, y) : draw_pixels(y, x);
		if (sigma >= 0)
		{
			sigma = (int)(sigma + 4 * pow(rad_one, 2) * (1 - y));
			y = y - 1;
		}
		sigma = (int)(sigma + pow(rad_two, 2) * ((4 * x) + 6));
		x = x + 1;
	}
}

System::Void sem1::MyForm::draw_pixels(int x, int y)
{
	im->FillRectangle(blueBrush, x + x1, y + y1, 1, 1);
	im->FillRectangle(blueBrush, x1 - x, y + y1, 1, 1);
	im->FillRectangle(blueBrush, x + x1, y1 - y, 1, 1);
	im->FillRectangle(blueBrush, x1 - x, y1 - y, 1, 1);
}

System::Void sem1::MyForm::clear_Click(System::Object^  sender, System::EventArgs^  e) {
	cleanCanvas();
}

System::Void sem1::MyForm::aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Программа выполнена студенткой группы БПИ143(1) \nРепиной Анастасией Андреевной \nСреда разработки: Visual Studio 2015 Entherprise \nОС Windows 10 \nДата 07.09.2017 \nВыполнены пункты: \n1)bresenham line algo\n2)bresenham circle algo\n3)ellipse algo", "О программе");
}

System::Void sem1::MyForm::canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	switch (objects->SelectedIndex)
	{
	case 0://line
	{
		if (x1 != -1 && y1 != -1)
		{
			x2 = e->X;
			y2 = e->Y;
			existedMethod == false ? bres_line() : im->DrawLine(pen, x1, y1, x2, y2);
			x1 = -1;
			y1 = -1;
		}
		else {
			x1 = e->X;
			y1 = e->Y;
		}
		break;
	}
	case 1://circle
	{
		if (x1 != -1 && y1 != -1)
		{
			int cur_x = e->X;
			int cur_y = e->Y;
			rad_first = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
			existedMethod == false ? bres_circle() : im->DrawEllipse(pen, x1 - rad_first, y1 - rad_first, rad_first * 2, rad_first * 2);
			x1 = -1;
			y1 = -1;
			rad_first = -1;
		}
		else {
			x1 = e->X;
			y1 = e->Y;
		}
		break;
	}
	case 2://ellipse
	{
		if (x1 != -1 && y1 != -1)
		{
			int cur_x = e->X;
			int cur_y = e->Y;
			if (rad_first != -1)
			{
				rad_second = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
				existedMethod == false ? bres_ellipse() : im->DrawEllipse(pen, x1 - rad_first, y1 - rad_first, rad_first * 2, rad_second * 2);
				x1 = -1;
				y1 = -1;
				rad_first = -1;
			}
			else
				rad_first = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
		}
		else {
			x1 = e->X;
			y1 = e->Y;
		}
		break;
	}
	}
}

System::Void sem1::MyForm::existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	existedMethod = !existedMethod;//do we use existed methods or the bresenham algo
}