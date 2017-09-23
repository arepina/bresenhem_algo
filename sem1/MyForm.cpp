#include "MyForm.h"
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
using namespace sem1; //пространство имен из заголовочного файла формы !!!
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	srand(time(0));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

#pragma region Bresenham
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
	int y = rad_second; 
	int sigma = 0;
	int a = rad_first;
	int b = rad_second;
	//b^2(0+1)^2-a^2*(y-1)^2-a^2b^2 = b^2-a^2*(b-1)^2-a^2b^2 = b^2-a^2*(b-1)-a^2(2b - 1)
	int delta = pow(b, 2) - pow(a, 2) * (2 * b - 1);
	int predel = 0;
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

#pragma endregion Bresenham algo

#pragma region Form events
System::Void sem1::MyForm::clear_Click(System::Object^  sender, System::EventArgs^  e) {
	cleanCanvas();
}

System::Void sem1::MyForm::aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Программа выполнена студенткой группы БПИ143(1) \nРепиной Анастасией Андреевной \nСреда разработки: Visual Studio 2015 Entherprise \nОС Windows 10 \nДата 07.09.2017 \nВыполнены пункты: \n1)bresenham line algo\n2)bresenham circle algo\n3)ellipse algo", "О программе");
}

System::Void sem1::MyForm::random_generate_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	switch (objects->SelectedIndex)
	{
	case 0://line
	{
		random_click_imitation(2);
		break;
	}
	case 1://circle
	{
		random_click_imitation(2);
		break;
	}
	case 2://ellipse
	{
		random_click_imitation(3);
		break;
	}
	}
}

void split(const std::string& s, char c,
	std::vector<std::string>& v) {
	std::string::size_type i = 0;
	std::string::size_type j = s.find(c);

	while (j != std::string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == std::string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

System::Void sem1::MyForm::draw_from_file_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	OpenFileDialog ^fd = gcnew OpenFileDialog;
	fd->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	if (fd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ filename = fd->FileName;
		std::string line;
		std::string converted_filename = msclr::interop::marshal_as< std::string >(filename);
		std::ifstream myfile(converted_filename);
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				int index = line.find_first_of(" ");
				std::string figure_name = line.substr(0, index);
				std::vector<std::string> v;
				split(line, ' ', v);
				if (v.at(0) == "line")
				{
					objects->SelectedIndex = 0;
					what_to_draw(stoi(v.at(1)), stoi(v.at(2)));
					what_to_draw(stoi(v.at(3)), stoi(v.at(4)));
				}
				if (v.at(0) == "circle")
				{
					objects->SelectedIndex = 1;
					what_to_draw(stoi(v.at(1)), stoi(v.at(2)));
					what_to_draw(stoi(v.at(3)), stoi(v.at(4)));
				}
				if (v.at(0) == "ellipse")
				{
					objects->SelectedIndex = 2;
					what_to_draw(stoi(v.at(1)), stoi(v.at(2)));
					what_to_draw(stoi(v.at(3)), stoi(v.at(4)));
					what_to_draw(stoi(v.at(5)), stoi(v.at(6)));
				}
				
			}
			myfile.close();
		}
		
	}
}

System::Void sem1::MyForm::random_click_imitation(int click_number)
{
	int ex, ey;
	for (int i = 0; i < click_number; i++)
	{
		ex = rand() % static_cast<int>(canvas->Width + 1);
		ey = rand() % static_cast<int>(canvas->Height + 1);
		what_to_draw(ex, ey);
	}
}

System::Void sem1::MyForm::canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	what_to_draw(e->X, e->Y);
}

System::Void sem1::MyForm::existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	existedMethod = !existedMethod;//do we use existed methods or the bresenham algo
}

#pragma endregion Form events

#pragma region Drawing
System::Void sem1::MyForm::what_to_draw(int ex, int ey)
{
	switch (objects->SelectedIndex)
	{
	case 0://line
	{
		if (x1 != -1 && y1 != -1)
		{
			x2 = ex;
			y2 = ey;
			existedMethod == false ? bres_line() : im->DrawLine(pen, x1, y1, x2, y2);
			x1 = -1;
			y1 = -1;
		}
		else {
			x1 = ex;
			y1 = ey;
		}
		break;
	}
	case 1://circle
	{
		if (x1 != -1 && y1 != -1)
		{
			int cur_x = ex;
			int cur_y = ey;
			rad_first = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
			existedMethod == false ? bres_circle() : im->DrawEllipse(pen, x1 - rad_first, y1 - rad_first, rad_first * 2, rad_first * 2);
			x1 = -1;
			y1 = -1;
			rad_first = -1;
		}
		else {
			x1 = ex;
			y1 = ey;
		}
		break;
	}
	case 2://ellipse
	{
		if (x1 != -1 && y1 != -1)
		{
			int cur_x = ex;
			int cur_y = ey;
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
			x1 = ex;
			y1 = ey;
		}
		break;
	}
	}
}

System::Void sem1::MyForm::draw_pixels(int x, int y)
{
	im->FillRectangle(blueBrush, x + x1, y + y1, 1, 1);
	im->FillRectangle(blueBrush, x1 - x, y + y1, 1, 1);
	im->FillRectangle(blueBrush, x + x1, y1 - y, 1, 1);
	im->FillRectangle(blueBrush, x1 - x, y1 - y, 1, 1);
}

/*
clean the canvas
*/
System::Void sem1::MyForm::cleanCanvas()
{
	im->Clear(col->White);
}
#pragma endregion Drawing