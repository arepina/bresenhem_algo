//Программа выполнена студенткой группы БПИ143(1) Репиной Анастасией Андреевной. 
//Среда разработки: Visual Studio 2015 Entherprise, ОС Windows 10
//Дата 07.09.2017
//Выполнены пункты:
//1)bresenham line algo
//2)bresenham circle algo
//3)ellipse algo
#include "MyForm.h"

using namespace sem1;
using namespace std;

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	srand((unsigned int)time(0));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

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
				auto index = line.find_first_of(" ");
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

System::Void sem1::MyForm::save_to_file_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ofstream myfile("..//figures.txt");
	for (int i = 0; i < figures->Count; i++)
	{
		Figure^ f = figures[i];
		String^ s;
		switch (f->getFigureType())
		{
		case FigureType::Line: s = "line " + f->x1 + " " + f->y1 + " " + f->x2 + " " + f->y2; break;
		case FigureType::Circle: s += "circle " + f->x1 + " " + f->y1 + " " + f->rad_first; break;
		case FigureType::Ellipse: s += "ellipse " + f->x1 + " " + f->y1 + " " + f->rad_first + " " + f->rad_second; break;
		}
		std::string unmanaged = msclr::interop::marshal_as<std::string>(s);
		myfile << unmanaged << "\n";
	}
	myfile.close();
	MessageBox::Show("Файл сохранен, он называется figures.txt");
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
	dots->Clear();
}

System::Void sem1::MyForm::cutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	objects->SelectedIndex = 0;
	draw_groupbox->Visible = false;
	fill_groupbox->Visible = false;
	cut_groupbox->Visible = true;
	dots->Clear();
}

System::Void sem1::MyForm::fillToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	draw_groupbox->Visible = false;
	fill_groupbox->Visible = true;
	cut_groupbox->Visible = false;
	dots->Clear();
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
	existed_method = !existed_method;
}

#pragma endregion Check Changed

#pragma endregion Form events

#pragma region Drawing

System::Void sem1::MyForm::draw_line_by_line(int ex, int ey)
{
	stack<pair<int, int>> pixel;
	pixel.push(make_pair(ex, ey));
	Fill::row_by_row_fill(pixel, ex, ey, gcnew SolidBrush(color_chooser->BackColor), bm, im, canvas, current_color);
}

System::Void sem1::MyForm::draw_xor(int ex, int ey)
{
	Fill::xor_fill(ex, ey);
}

System::Void sem1::MyForm::draw_window(int ex, int ey)
{
	Point current;
	current.X = ex;
	current.Y = ey;
	if (dots->Count == 1)
	{
		Point^ first = dots[0];
		Figure^ f = gcnew Figure();
		f->create_rect(first->X, first->Y, current.X, current.Y);
		figures->Add(f);
		System::Drawing::Rectangle rect;
		if (first->X < current.X)
			first->Y < current.Y ?
			rect = System::Drawing::Rectangle(first->X, first->Y, abs(current.X - first->X), abs(current.Y - first->Y)) : rect = System::Drawing::Rectangle(first->X, current.Y, abs(current.X - first->X), abs(current.Y - first->Y));
		else
			first->Y < current.Y ?
			rect = System::Drawing::Rectangle(current.X, first->Y, abs(current.X - first->X), abs(current.Y - first->Y)) : rect = System::Drawing::Rectangle(current.X, current.Y, abs(current.X - first->X), abs(current.Y - first->Y));
		im->DrawRectangle(gcnew Pen(current_color->BackColor), rect);
		dots->Clear();
	}
	else
		dots->Add(current);
}

System::Void sem1::MyForm::draw_objects(int ex, int ey)
{
	Brush^b = gcnew SolidBrush(current_color->BackColor);
	Point current;
	current.X = ex;
	current.Y = ey;
	switch (objects->SelectedIndex)
	{
	case 0://line
	{
		if (dots->Count == 1) {
			Point^ first = dots[0];
			Figure^ f = gcnew Figure();
			f->create_line(first->X, first->Y, current.X, current.Y);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_line(f, im, b) : im->DrawLine(gcnew Pen(current_color->BackColor), f->x1, f->y1, f->x2, f->y2);
			dots->Clear();
		}
		else
			dots->Add(current);
		break;
	}
	case 1://circle
	{
		if (dots->Count == 1) {
			Point^ center = dots[0];
			Figure^ f = gcnew Figure();
			int radius = (int)sqrt(pow((abs(current.X - center->X)), 2) + pow((abs(current.Y - center->Y)), 2));
			f->create_circle(center->X, center->Y, radius);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_circle(f, im, b) : im->DrawEllipse(gcnew Pen(current_color->BackColor), center->X - radius, center->Y - radius, radius * 2, radius * 2);
			dots->Clear();
		}
		else
			dots->Add(current);
		break;
	}
	case 2://ellipse
	{
		if (dots->Count == 2)
		{
			Point^ center = dots[0];
			Point^ width_click = dots[1];
			Figure^ f = gcnew Figure();
			int rad_first = (int)sqrt(pow((abs(width_click->X - center->X)), 2) + pow((abs(width_click->Y - center->Y)), 2));
			int rad_second = (int)sqrt(pow((abs(current.X - center->X)), 2) + pow((abs(current.Y - center->Y)), 2));
			f->create_ellipse(center->X, center->Y, rad_first, rad_second);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_ellipse(f, im, b) : im->DrawEllipse(gcnew Pen(current_color->BackColor), center->X - rad_first, center->Y - rad_first, rad_first * 2, rad_second * 2);
			dots->Clear();
		}
		else
			dots->Add(current);
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


System::Void sem1::MyForm::cleanCanvas()
{
	im->Clear(Color::White);
	dots->Clear();
	figures->Clear();
	canvas->Refresh();
}
#pragma endregion Drawing