//All the info is in the about
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

System::Void sem1::MyForm::load_lines_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	loadfileToolStripMenuItem_Click(sender, e);
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
	if (dots->Count == 0 && is_objects)
		im->FillRectangle(gcnew SolidBrush(current_color), e->X, e->Y, 1, 1);
	what_to_draw(e->X, e->Y);
}
#pragma endregion Click events

#pragma region Menu
System::Void sem1::MyForm::aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("��������� ��������� ���������� ������ ���143(1)\n" +
		"������� ���������� ����������\n" +
		"����� ����������: Visual Studio 2015 Entherprise \n" +
		"�� Windows 10\n" +
		"���� 07.09.2017\n" +
		"������ �������:\n" +
		"Bresenhem.h + Bresenhem.cpp - ���������� ���������� ����������\n" +
		"Cut.h + Cut.cpp - ���������� ���������\n" +
		"Fill.h + Fill.cpp - ���������� �������: ���������� � XOR\n" +
		"MyForm.h + MyForm.cpp - ���������� ���������� � ���������� ������������\n\n" +
		"��������� ������:\n" +
		"1)��������� �����, ����� � ������� � ������� ��������� ����������\n" +
		"2)���������� � XOR �������\n" + 
		"3)���������\n\n" +
		"��� ������� ���������� ��������� ������� ������������ ������� ����. ����� ������� ���� �� ���� ��������: �����, ����, ������ ��������� ������� ��� �������, ������� ���������, � ����� �������� ����. ����� ���������� ������ �������� ���� �������� ���������� ����� (����� � ������� ��� ����� ������ � �����). � ������� �������� ����� �������, � ������� ����� ������ ����� ����������� ���������: ���������� ��� ������������� ������� ���������. \n���� ����������� ��������� ��������� ������������� �������� � ������� ������ ������. \n��� ������� ��������� ������� ���: ���������� ��� xor. � ������ ���������� ����� ������ ������ �������� ������ ���� �� ��������� �������(���, �� �������� ���� �������). � ������ xor ���������� ����� �����, � ������� ��� �������� �����-����� ������. \n����� ����� ��������� ���������. ����� ������ ��������� ������� ��� �����, ������� ����� ������������ ��������� ����, ����� ������� ����. \n����� ���� ��� ������������� �������� ������� ����������� ��������/���������� ������ � ����. � ����� �������� ������ � �������� ������, � ����� ��������� ��� �� ��������� ���������� � ����. ������ ������� ������ ����������� � ����� figures.txt. ������ ������ ��� ��������� Xor � ����� XORdotsRed.txt. ������ ���� ��������� �������� ��� ������������ ��������� � ����� linesForCut.txt. \n��� ������� ������� ��������� �������� ������ �� ������ \"��������\".", "� ���������");
}

System::Void sem1::MyForm::cutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_window_mode = true;
	is_objects = false;
	is_xor = false;
	dots->Clear();
}

System::Void sem1::MyForm::loadfileToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
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
					is_line = true;
					Figure^ f = gcnew Figure();
					Color c = Color::FromArgb(stoi(v.at(5)));
					f->create_line(stoi(v.at(1)), stoi(v.at(2)), stoi(v.at(3)), stoi(v.at(4)), c);
					figures->Add(f);
					Bresenhem::bres_line(f, im, gcnew SolidBrush(c));
				}
				if (v.at(0) == "circle")
				{
					is_circle = true;
					Figure^ f = gcnew Figure();
					Color c = Color::FromArgb(stoi(v.at(4)));
					f->create_circle(stoi(v.at(1)), stoi(v.at(2)), stoi(v.at(3)), c);
					figures->Add(f);
					Bresenhem::bres_circle(f, im, gcnew SolidBrush(c));
				}
				if (v.at(0) == "ellipse")
				{
					is_ellipse = true;
					Figure^ f = gcnew Figure();
					Color c = Color::FromArgb(stoi(v.at(5)));
					f->create_ellipse(stoi(v.at(1)), stoi(v.at(2)), stoi(v.at(3)), stoi(v.at(4)), c);
					figures->Add(f);
					Bresenhem::bres_ellipse(f, im, gcnew SolidBrush(c));
				}
				canvas->Refresh();
			}
			myfile.close();
		}
	}
	canvas->Refresh();
}

System::Void sem1::MyForm::savefileToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SaveFileDialog ^fd = gcnew SaveFileDialog;
	fd->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	if (fd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ filename = fd->FileName;
		string converted_filename = msclr::interop::marshal_as<string>(filename);
		ofstream myfile(converted_filename);
		for (int i = 0; i < figures->Count; i++)
		{
			Figure^ f = figures[i];
			String^ s;
			switch (f->getFigureType())
			{
			case FigureType::Line: s = "line " + f->x1 + " " + f->y1 + " " + f->x2 + " " + f->y2 + " " + f->c.ToArgb(); break;
			case FigureType::Circle: s += "circle " + f->x1 + " " + f->y1 + " " + f->rad_first + " " + f->c.ToArgb(); break;
			case FigureType::Ellipse: s += "ellipse " + f->x1 + " " + f->y1 + " " + f->rad_first + " " + f->rad_second + " " + f->c.ToArgb(); break;
			}
			std::string unmanaged = msclr::interop::marshal_as<std::string>(s);
			myfile << unmanaged << "\n";
		}
		myfile.close();
	}
}

System::Void sem1::MyForm::cleanToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	cleanCanvas();
}

System::Void sem1::MyForm::lineByLineToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = true;
	is_window_mode = false;
	is_objects = false;
	is_xor = false;
}

System::Void sem1::MyForm::xorToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_window_mode = false;
	is_objects = false;
	is_xor = true;
}

System::Void sem1::MyForm::lineToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_window_mode = false;
	is_xor = false;
	is_objects = true;
	dots->Clear();
	is_line = true;
	is_circle = false;
	is_ellipse = false;
}

System::Void sem1::MyForm::circleToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_xor = false;
	is_window_mode = false;
	is_objects = true;
	dots->Clear();
	is_line = false;
	is_circle = true;
	is_ellipse = false;
}

System::Void sem1::MyForm::ellipseToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_window_mode = false;
	is_xor = false;
	is_objects = true;
	dots->Clear();
	is_line = false;
	is_circle = false;
	is_ellipse = true;
}

System::Void sem1::MyForm::randomToolStripMenuItem_Click_1(System::Object ^ sender, System::EventArgs ^ e)
{
	is_line_by_line = false;
	is_window_mode = false;
	is_xor = false;
	is_objects = true;
	FigureType t = FigureType(rand() % 3);
	if (t == FigureType::Line) {
		is_line = true;
		is_ellipse = false;
		is_circle = false;
		random_click_imitation(2);
	}
	if (t == FigureType::Circle) {
		is_circle = true;
		is_line = false;
		is_ellipse = false;
		random_click_imitation(2);
	}
	if (t == FigureType::Ellipse) {
		is_ellipse = true;
		is_line = false;
		is_circle = false;
		random_click_imitation(3);
	}

}

System::Void sem1::MyForm::colorChooserToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	colorDialog1->ShowDialog();
	current_color = colorDialog1->Color;
}

#pragma endregion Menu

#pragma region Check Changed

System::Void sem1::MyForm::existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	existed_method = !existed_method;
}

#pragma endregion Check Changed

#pragma endregion Form events

#pragma region Drawing

System::Void sem1::MyForm::draw_line_by_line(int ex, int ey)
{
	System::Collections::Generic::Stack<Point> ^pixel = gcnew System::Collections::Generic::Stack<Point>();
	pixel->Push(Point(ex, ey));
	Fill::row_by_row_fill(pixel, bm, im, canvas, current_color);
}

System::Void sem1::MyForm::draw_xor(int ex, int ey)
{
	im->FillRectangle(gcnew SolidBrush(current_color), ex, ey, 1, 1);
	bool is_finished = false;
	for (int i = 0; i < xordots->Count; i++)
	{
		if (abs(xordots[i].X - ex) <= 5 && abs(xordots[i].Y - ey <= 5))
			is_finished = true;
	}
	if (is_finished)
	{
		Color background_color = Color::White;
		Color border_color = current_color;
		System::Collections::Generic::List<Figure^> ^lines = gcnew System::Collections::Generic::List<Figure^>();
		for (int i = 0; i < xordots->Count - 1; i++)
		{
			Figure^ f = gcnew Figure();
			f->create_line(xordots[i].X, xordots[i].Y, xordots[i + 1].X, xordots[i + 1].Y, current_color);
			im->DrawLine(gcnew Pen(current_color), xordots[i].X, xordots[i].Y, xordots[i + 1].X, xordots[i + 1].Y);
			lines->Add(f);
		}
		Figure^ f = gcnew Figure();
		f->create_line(xordots[xordots->Count - 1].X, xordots[xordots->Count - 1].Y, xordots[0].X, xordots[0].Y, current_color);
		im->DrawLine(gcnew Pen(current_color), xordots[xordots->Count - 1].X, xordots[xordots->Count - 1].Y, xordots[0].X, xordots[0].Y);
		canvas->Refresh();
		lines->Add(f);
		Fill::xor_fill(lines, bm, im, canvas, current_color, background_color, border_color);
		im->FillRectangle(gcnew SolidBrush(current_color), ex, ey, 1, 1);
		xordots->Clear();
	}
	else {
		xordots->Add(Point(ex, ey));
	}
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
		f->create_rect(first->X, first->Y, current.X, current.Y, Color::Black);
		figures->Add(f);
		System::Drawing::Rectangle rect;
		int xl, xp, yn, yv;
		if (first->X < current.X) {
			xl = first->X;
			xp = current.X;
			if (first->Y < current.Y) {
				yn = current.Y;
				yv = first->Y;
				rect = System::Drawing::Rectangle(first->X, first->Y, abs(current.X - first->X), abs(current.Y - first->Y));
			}
			else {
				yn = first->Y;
				yv = current.Y;
				rect = System::Drawing::Rectangle(first->X, current.Y, abs(current.X - first->X), abs(current.Y - first->Y));
			}
		}
		else {
			xl = current.X;
			xp = first->X;
			if (first->Y < current.Y) {
				yn = current.Y;
				yv = first->Y;
				rect = System::Drawing::Rectangle(current.X, first->Y, abs(current.X - first->X), abs(current.Y - first->Y));
			}
			else {
				yn = first->Y;
				yv = current.Y;
				rect = System::Drawing::Rectangle(current.X, current.Y, abs(current.X - first->X), abs(current.Y - first->Y));
			}
		}
		dots->Clear();
		List<Figure^>^ lines = gcnew List<Figure^>();
		for each (Figure^ fig in figures)//collect all the lines
		{
			if (fig->getFigureType() == FigureType::Line)
				lines->Add(fig);
		}
		Cut::process_lines_cut(xl, xp, yv, yn, lines, im, canvas);
		for each (Figure^ var in figures)//redraw the non line figures
		{
			if (var->getFigureType() == FigureType::Circle)
				im->DrawEllipse(gcnew Pen(current_color), var->x1 - var->rad_first, var->y1 - var->rad_first, var->rad_first * 2, var->rad_first * 2);
			else if (var->getFigureType() == FigureType::Ellipse)
				im->DrawEllipse(gcnew Pen(current_color), var->x1 - var->rad_first, var->y1 - var->rad_first, var->rad_first * 2, var->rad_second * 2);
		}
		im->DrawRectangle(gcnew Pen(Color::Black), rect);
	}
	else
		dots->Add(current);
}

System::Void sem1::MyForm::draw_objects(int ex, int ey)
{
	Brush^b = gcnew SolidBrush(current_color);
	Point current;
	current.X = ex;
	current.Y = ey;
	if (is_line)//line
	{
		if (dots->Count == 1) {
			Point^ first = dots[0];
			Figure^ f = gcnew Figure();
			f->create_line(first->X, first->Y, current.X, current.Y, current_color);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_line(f, im, b) : im->DrawLine(gcnew Pen(current_color), f->x1, f->y1, f->x2, f->y2);
			dots->Clear();
		}
		else
			dots->Add(current);
	}
	if (is_circle)//circle
	{
		if (dots->Count == 1) {
			Point^ center = dots[0];
			Figure^ f = gcnew Figure();
			int radius = (int)sqrt(pow((abs(current.X - center->X)), 2) + pow((abs(current.Y - center->Y)), 2));
			f->create_circle(center->X, center->Y, radius, current_color);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_circle(f, im, b) : im->DrawEllipse(gcnew Pen(current_color), center->X - radius, center->Y - radius, radius * 2, radius * 2);
			dots->Clear();
		}
		else
			dots->Add(current);
	}
	if (is_ellipse)//ellipse
	{
		if (dots->Count == 2)
		{
			Point^ center = dots[0];
			Point^ width_click = dots[1];
			Figure^ f = gcnew Figure();
			int rad_first = (int)sqrt(pow((abs(width_click->X - center->X)), 2) + pow((abs(width_click->Y - center->Y)), 2));
			int rad_second = (int)sqrt(pow((abs(current.X - center->X)), 2) + pow((abs(current.Y - center->Y)), 2));
			f->create_ellipse(center->X, center->Y, rad_first, rad_second, current_color);
			figures->Add(f);
			!existed_method ? Bresenhem::bres_ellipse(f, im, b) : im->DrawEllipse(gcnew Pen(current_color), center->X - rad_first, center->Y - rad_first, rad_first * 2, rad_second * 2);
			dots->Clear();
		}
		else
			dots->Add(current);
	}
}

System::Void sem1::MyForm::what_to_draw(int ex, int ey)
{
	if (is_objects)
		draw_objects(ex, ey);
	else if (is_line_by_line)
		draw_line_by_line(ex, ey);
	else if (is_window_mode)
		draw_window(ex, ey);
	else if (is_xor)
		draw_xor(ex, ey);
	canvas->Refresh();
}

sem1::MyForm::MyForm(void)
{
	InitializeComponent();
	bm = gcnew Bitmap(canvas->Width, canvas->Height);
	canvas->Image = bm;
	im = Graphics::FromImage(bm);
	current_color = Color::Black;
	existed_method = false;
	is_line_by_line = false;
	is_window_mode = false;
	is_objects = true;
	is_line = true;
	is_circle = false;
	is_ellipse = false;
	is_xor = false;
	cleanCanvas();
}

System::Void sem1::MyForm::cleanCanvas()
{
	im->Clear(Color::White);
	dots->Clear();
	figures->Clear();
	canvas->Refresh();
	xordots->Clear();
}
#pragma endregion Drawing