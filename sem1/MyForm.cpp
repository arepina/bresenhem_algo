//Программа выполнена студенткой группы БПИ143(1) Репиной Анастасией Андреевной. 
//Среда разработки: Visual Studio 2015 Entherprise, ОС Windows 10
//Дата 07.09.2017
//Выполнены пункты:
//1)bresenham line algo
//2)bresenham circle algo
//3)ellipse algo
#include "MyForm.h"
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>

using namespace sem1;
using namespace std;
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
		im->FillRectangle(gcnew SolidBrush(current_color->BackColor), x, y, 1, 1);
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

#pragma region Zalivka

System::Void sem1::MyForm::row_by_row_zalivka(stack<pair<int, int>> pixel, int ex, int ey, SolidBrush^ fill_color)
{
	Bitmap^ b = gcnew Bitmap(canvas->Width, canvas->Height);
	canvas->DrawToBitmap(b, canvas->ClientRectangle);
	pair<int, int> current;
	Color^ selected_pixel_color = b->GetPixel(ex, ey);
	Color^ current_pixel_colour;
	while (!pixel.empty()) {
		current = pixel.top();
		pixel.pop();
		int cur_x = current.first;
		int cur_y = current.second;
		int start_x = cur_x;//remember the start point		
		current_pixel_colour = b->GetPixel(cur_x, cur_y);
		//go to the right
		while (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color)) {
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), cur_x, cur_y, 1, 1);
			cur_x = cur_x + 1;
			current_pixel_colour = b->GetPixel(cur_x, cur_y);
		}
		//save the most right pixel
		int xright = cur_x - 1;
		//go to the left from start point
		cur_x = start_x - 1;
		while (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color)) {
			im->FillRectangle(gcnew SolidBrush(current_color->BackColor), cur_x, cur_y, 1, 1);
			cur_x = cur_x - 1;
			current_pixel_colour = b->GetPixel(cur_x, cur_y);
		}
		//save the most left pixel
		int xleft = cur_x + 1;
		cur_y = cur_y - 1;//go down
		int flag = 1;
		for (cur_x = xleft; cur_x <= xright; cur_x++)
		{
			current_pixel_colour = b->GetPixel(cur_x, cur_y + 1);
			if (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color))
			{
				if (flag == 1)
				{
					pixel.push(make_pair(cur_x, cur_y + 1));
					flag = 0;
				}
			}
			else
				flag = 1;
		}
		//go up
		flag = 1;
		for (cur_x = xleft; cur_x <= xright; cur_x++)
		{
			current_pixel_colour = b->GetPixel(cur_x, cur_y - 1);
			if (current_pixel_colour->Equals(selected_pixel_color) && !current_pixel_colour->Equals(fill_color->Color))
			{
				if (flag == 1)
				{
					pixel.push(make_pair(cur_x, cur_y - 1));
					flag = 0;
				}
			}
			else
				flag = 1;
		}
	}
}

System::Void sem1::MyForm::xor_zalivka(int ex, int ey)
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


#pragma endregion Zalivka

#pragma region Cut

System::Void sem1::MyForm::window(int ex, int ey)
{
	if (x1_cut == -1)
	{
		x1_cut = ex;
		y1_cut = ey;
	}
	else {
		if (ex < x1_cut) {
			x2_cut = x1_cut;
			x1_cut = ex;
		}
		else
			x2_cut = ex;
		if (ey < y1_cut) {
			y2_cut = y1_cut;
			y1_cut = ey;
		}
		else
			y2_cut = ey;
		System::Drawing::Rectangle rect = System::Drawing::Rectangle(x1_cut, y1_cut, abs(x2_cut - x1_cut), abs(y2_cut - y1_cut));
		im->DrawRectangle(gcnew Pen(current_color->BackColor), rect);
		process_lines_cut(x1_cut, y1_cut, x2_cut, y2_cut);
		x1_cut = -1;
		y1_cut = -1;
	}
}

System::Void sem1::MyForm::process_lines_cut(int x1_cut, int y1_cut, int x2_cut, int y2_cut)
{
	int i = lines_vector->size() - 1;
	while (!lines_vector->empty())
	{
		pair<pair<int*, int*>, pair<int*, int*>> p_sum = lines_vector->at(i);
		lines_vector->pop_back();
		int g1 = (int)p_sum.first.first;
		int g2 = (int)p_sum.first.second;
		int g3 = (int)p_sum.second.first;
		int g4 = (int)p_sum.second.second;
		//todo analise how to color the lines
		i--;
	}
}

#pragma endregion Cut

#pragma region Form events

#pragma region Click events
System::Void sem1::MyForm::clear_Click(System::Object^  sender, System::EventArgs^  e) {
	cleanCanvas();
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

void split(const string& s, char c,
	vector<string>& v) {
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos)
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
		string line;
		string converted_filename = msclr::interop::marshal_as<string>(filename);
		ifstream myfile(converted_filename);
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				int index = line.find_first_of(" ");
				string figure_name = line.substr(0, index);
				vector<string> v;
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

System::Void sem1::MyForm::load_lines_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	draw_from_file_Click(sender, e);
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
#pragma endregion Click events

#pragma region Menu
System::Void sem1::MyForm::aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Программа выполнена студенткой группы БПИ143(1) \nРепиной Анастасией Андреевной \nСреда разработки: Visual Studio 2015 Entherprise \nОС Windows 10 \nДата 07.09.2017 \nВыполнены пункты: \n1)bresenham line algo\n2)bresenham circle algo\n3)ellipse algo", "О программе");
}

System::Void sem1::MyForm::createObjectToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	draw_groupbox->Visible = true;
	fill_groupbox->Visible = false;
	cut_groupbox->Visible = false;
}

System::Void sem1::MyForm::cutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	objects->SelectedIndex = 0;
	draw_groupbox->Visible = false;
	fill_groupbox->Visible = false;
	cut_groupbox->Visible = true;
}

System::Void sem1::MyForm::fillToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	draw_groupbox->Visible = false;
	fill_groupbox->Visible = true;
	cut_groupbox->Visible = false;
}

#pragma endregion Menu

#pragma region Check Changed
System::Void sem1::MyForm::window_mode_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	is_window_mode = !is_window_mode;
}

System::Void sem1::MyForm::color_chooser_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	colorDialog1->ShowDialog();
	current_color->BackColor = colorDialog1->Color;
	
}

System::Void sem1::MyForm::line_by_line_fill_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = !is_line_by_line;
}

System::Void sem1::MyForm::xor_fill_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	is_xor = !is_xor;
}

System::Void sem1::MyForm::existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	existed_method = !existed_method;//do we use existed methods or the bresenham algo
}

#pragma endregion Check Changed

#pragma endregion Form events

#pragma region Drawing

System::Void sem1::MyForm::draw_line_by_line(int ex, int ey)
{
	ex = 10;
	ey = 10;
	/*Bitmap^ bm = gcnew Bitmap(canvas->Width, canvas->Height);*/
	Color^ co = bm->GetPixel(ex, ey);
	int f = 4;
	/*stack<pair<int, int>> pixel;
	pixel.push(make_pair(ex, ey));
	Pen^p = gcnew Pen(colorDialog1->Color);
	Brush^ v = gcnew SolidBrush(p->Color);
	im->FillRectangle(v, 0, 0, 1, 1);
	im->FillRectangle(greenBrush, 10, 10, 1, 1);
	Bitmap^ bb = gcnew Bitmap(canvas->Image);	
	//bb = gcnew Bitmap(canvas->InitialImage);
	Color^ w = bb->GetPixel(0, 0);
	Color^ w1 = bb->GetPixel(10, 10);
	im->FillRectangle(greenBrush, 1, 1, 1, 1);
	w1 = bb->GetPixel(1, 1);
	row_by_row_zalivka(pixel, ex, ey, greenBrush);*/
}

System::Void sem1::MyForm::draw_xor(int ex, int ey)
{
	xor_zalivka(ex, ey);
}

System::Void sem1::MyForm::draw_window(int ex, int ey)
{
	window(ex, ey);
}

System::Void sem1::MyForm::draw_objects(int ex, int ey)
{
	switch (objects->SelectedIndex)
	{
	case 0://line
	{
		if (x1 != -1 && y1 != -1)
		{
			x2 = ex;
			y2 = ey;
			existed_method == false ? bres_line() : im->DrawLine(gcnew Pen(current_color->BackColor), x1, y1, x2, y2);
			pair<int*, int*> p1 = make_pair((int*)x1, (int*)y1);
			pair<int*, int*> p2 = make_pair((int*)x2, (int*)y2);
			pair<pair<int*, int*>, pair<int*, int*>> p_sum = make_pair(p1, p2);
			lines_vector->push_back(p_sum);			
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
			existed_method == false ? bres_circle() : im->DrawEllipse(gcnew Pen(current_color->BackColor), x1 - rad_first, y1 - rad_first, rad_first * 2, rad_first * 2);
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
				existed_method == false ? bres_ellipse() : im->DrawEllipse(gcnew Pen(current_color->BackColor), x1 - rad_first, y1 - rad_first, rad_first * 2, rad_second * 2);
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

System::Void sem1::MyForm::what_to_draw(int ex, int ey)
{
	if (draw_groupbox->Visible || cut_groupbox->Visible)
		if (is_window_mode)
			draw_window(ex, ey);
		else 
			draw_objects(ex, ey);
	else if (is_line_by_line)
		draw_line_by_line(ex, ey);
	else if (is_xor)
		draw_xor(ex, ey);
	canvas->Refresh();
}

System::Void sem1::MyForm::draw_pixels(int x, int y)
{
	Brush^b = gcnew SolidBrush(current_color->BackColor);
	im->FillRectangle(b, x + x1, y + y1, 1, 1);
	im->FillRectangle(b, x1 - x, y + y1, 1, 1);
	im->FillRectangle(b, x + x1, y1 - y, 1, 1);
	im->FillRectangle(b, x1 - x, y1 - y, 1, 1);
}

System::Void sem1::MyForm::cleanCanvas()
{
	im->Clear(Color::White);
	lines_vector->clear();
	canvas->Refresh();
}
#pragma endregion Drawing