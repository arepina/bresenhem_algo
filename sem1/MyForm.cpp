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
	rad_second = rad_first;
	bres_ellipse();
}

/*
ellipse algo
*/
System::Void sem1::MyForm::bres_ellipse()
{
	int x = 0;
	int y = rad_first;
	int delta = 2 * (1 - rad_first);
	int predel = 0;
	int sigma = 0;
	int a = rad_first;
	int b = rad_second;
	do
	{
		draw_pixels(x, y);//draw 4 pixels on the canvas having only one coordinate
		if (y <= predel)
			return;
		if (delta < 0)
		{
			sigma = (int)(2 * delta + pow(a, 2) * (2 * y - 1));//choose between diagonal and horizontal
			if (sigma <= 0)
			{
				x = x + 1;
				delta = (int)(delta + pow(b, 2)*(2 * x + 1));//horizontal
			}
			else {
				x = x + 1;
				y = y - 1;
				delta = (int)(delta + pow(b, 2)*(2 * x + 1) - pow(a, 2)*(2 * y - 1));//diagonal
			}
		}
		else if (delta > 0)
		{
			sigma = (int)(2 * delta - pow(b, 2) * (2 * x - 1));;//choose between diagonal and vertical
			if (sigma <= 0)
			{
				x = x + 1;
				y = y - 1;
				delta = (int)(delta + pow(b, 2)*(2 * x + 1) - pow(a, 2)*(2 * y - 1));//diagonal
			}
			else {
				y = y - 1;
				delta = (int)(delta - pow(a, 2)*(2 * y - 1));//vertical
			}
		}
		else {
			x = x + 1;
			y = y - 1;
			delta = (int)(delta + pow(b, 2)*(2 * x + 1) - pow(a, 2)*(2 * y - 1));//diagonal
		}
	} while (true);
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