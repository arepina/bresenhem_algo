//Программа выполнена студенткой группы БПИ143(1) Репиной Анастасией Андреевной. 
//Среда разработки: Visual Studio 2015 Entherprise, ОС Windows 10
//Дата 07.09.2017
//Выполнены пункты:
//1)
//2)
//3)
#pragma once
#include <cmath>

namespace sem1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			im = canvas->CreateGraphics();
			objects->SelectedIndex = 0;
			blueBrush = gcnew SolidBrush(Color::Blue);
			col = gcnew Color();
			pen = gcnew Pen(col->Red);
			x1 = -1;
			y1 = -1;
			x2 = -1;
			y2 = -1;
			rad1 = -1;
			rad2 = -1;
			existedMethod = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Graphics ^im;
	private: Color ^col;
	private: SolidBrush^ blueBrush;
	private: Pen ^pen;
	private: int x1, y1, x2, y2, rad1, rad2;
	private: bool existedMethod;
	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::CheckBox^  existedMethodChecker;
	private: System::Windows::Forms::ComboBox^  objects;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->canvas = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->existedMethodChecker = (gcnew System::Windows::Forms::CheckBox());
			this->objects = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::White;
			this->canvas->Location = System::Drawing::Point(194, 43);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(620, 297);
			this->canvas->TabIndex = 0;
			this->canvas->TabStop = false;
			this->canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::canvas_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->createObjectToolStripMenuItem,
					this->aboutProgramToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(826, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createObjectToolStripMenuItem
			// 
			this->createObjectToolStripMenuItem->Name = L"createObjectToolStripMenuItem";
			this->createObjectToolStripMenuItem->Size = System::Drawing::Size(103, 20);
			this->createObjectToolStripMenuItem->Text = L"Создать объект";
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->aboutProgramToolStripMenuItem->Text = L"О программе";
			this->aboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutProgramToolStripMenuItem_Click);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(12, 309);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(155, 31);
			this->clear->TabIndex = 5;
			this->clear->Text = L"Очистить";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &MyForm::clear_Click);
			// 
			// existedMethodChecker
			// 
			this->existedMethodChecker->AutoSize = true;
			this->existedMethodChecker->Location = System::Drawing::Point(12, 70);
			this->existedMethodChecker->Name = L"existedMethodChecker";
			this->existedMethodChecker->Size = System::Drawing::Size(138, 17);
			this->existedMethodChecker->TabIndex = 28;
			this->existedMethodChecker->Text = L"Встроенные средства";
			this->existedMethodChecker->UseVisualStyleBackColor = true;
			this->existedMethodChecker->CheckedChanged += gcnew System::EventHandler(this, &MyForm::existedMethodChecker_CheckedChanged);
			// 
			// objects
			// 
			this->objects->DisplayMember = L"Отрезок";
			this->objects->FormattingEnabled = true;
			this->objects->IntegralHeight = false;
			this->objects->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Отрезок", L"Окружность", L"Эллипс" });
			this->objects->Location = System::Drawing::Point(12, 43);
			this->objects->Name = L"objects";
			this->objects->Size = System::Drawing::Size(121, 21);
			this->objects->TabIndex = 29;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 409);
			this->Controls->Add(this->objects);
			this->Controls->Add(this->existedMethodChecker);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"HW";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
		cleanCanvas();
	}

	private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Программа выполнена студенткой группы БПИ143(1) \nРепиной Анастасией Андреевной \nСреда разработки: Visual Studio 2015 Entherprise \nОС Windows 10 \nДата 07.09.2017 \nВыполнены пункты: 1), 2), 3)", "О программе");
	}

	/*
	clean the canvas
	*/
	private: void cleanCanvas()
	{
		im->Clear(col->White);
	}

	/*
	bresenham line algo
	*/
	public: System::Void bres_line()
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
	public: System::Void bres_circle()
	{
		int x = 0;
		int y = rad1;
		int delta = 2 * (1 - rad1);
		int predel = 0;
		int sigma = 0;
		do
		{
			draw(x, y);
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
	public: System::Void bres_ellipse()
	{
		int delta_rad1 = 1 - 2 * rad1;
		int delta_rad2 = 1 - 2 * rad2;
		// first two parts of ellipse
		int x = 0;
		int y = rad2;
		int sigma = (int)(2 * pow(rad2, 2) + pow(rad1, 2) * delta_rad2);
		draw_part(x, y, rad1, rad2, sigma, true);
		// second two parts of ellipse
		x = rad1;
		y = 0;
		sigma = (int)(2 * pow(rad1, 2) + pow(rad2, 2) * delta_rad1);
		draw_part(y, x, rad2, rad1, sigma, false);
	}

	private: System::Void draw_part(int x, int y, int rad1, int rad2, int sigma, bool which_part)
	{
		while (pow(rad2, 2) * x <= pow(rad1, 2) * y)
		{
			which_part ? draw(x, y) : draw(y, x);
			if (sigma >= 0)
			{
				sigma = (int)(sigma + 4 * pow(rad1, 2) * (1 - y));
				y = y - 1;
			}
			sigma = (int)(sigma + pow(rad2, 2) * ((4 * x) + 6));
			x = x + 1;
		}
	}

	private: System::Void draw(int x, int y)
	{
		im->FillRectangle(blueBrush, x + x1, y + y1, 1, 1);
		im->FillRectangle(blueBrush, x1 - x, y + y1, 1, 1);
		im->FillRectangle(blueBrush, x + x1, y1 - y, 1, 1);
		im->FillRectangle(blueBrush, x1 - x, y1 - y, 1, 1);
	}


	private: System::Void canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
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
				rad1 = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
				existedMethod == false ? bres_circle() : im->DrawEllipse(pen, x1 - rad1, y1 - rad1, rad1 * 2, rad1 * 2);
				x1 = -1;
				y1 = -1;
				rad1 = -1;
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
				if (rad1 != -1)
				{
					rad2 = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
					existedMethod == false ? bres_ellipse() : im->DrawEllipse(pen, x1 - rad1, y1 - rad1, rad1 * 2, rad2 * 2);
					x1 = -1;
					y1 = -1;
					rad1 = -1;
				}
				else
					rad1 = (int)sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
			}
			else {
				x1 = e->X;
				y1 = e->Y;
			}
			break;
		}
		}
	}

	private: System::Void existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		existedMethod = !existedMethod;//do we use existed methods or the bresenham algo
	}


	};
}
