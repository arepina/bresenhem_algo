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
	private: int switcher;
	private: int x1, y1, x2, y2, rad1, rad2;
	private: bool existedMethod;
	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::Button^  line;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;


	private: System::Windows::Forms::Button^  circle;
	private: System::Windows::Forms::Button^  elipse;
	private: System::Windows::Forms::Button^  clear;






	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  rad2_elipse;
	private: System::Windows::Forms::TextBox^  rad1_elipse;
	private: System::Windows::Forms::TextBox^  y1_elipse;
	private: System::Windows::Forms::TextBox^  x1_elipse;
	private: System::Windows::Forms::CheckBox^  existedMethodChecker;



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
			this->line = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circle = (gcnew System::Windows::Forms::Button());
			this->elipse = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->rad2_elipse = (gcnew System::Windows::Forms::TextBox());
			this->rad1_elipse = (gcnew System::Windows::Forms::TextBox());
			this->y1_elipse = (gcnew System::Windows::Forms::TextBox());
			this->x1_elipse = (gcnew System::Windows::Forms::TextBox());
			this->existedMethodChecker = (gcnew System::Windows::Forms::CheckBox());
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
			// line
			// 
			this->line->Location = System::Drawing::Point(12, 54);
			this->line->Name = L"line";
			this->line->Size = System::Drawing::Size(155, 23);
			this->line->TabIndex = 1;
			this->line->Text = L"Отрезок";
			this->line->UseVisualStyleBackColor = true;
			this->line->Click += gcnew System::EventHandler(this, &MyForm::line_Click);
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
			// circle
			// 
			this->circle->Location = System::Drawing::Point(12, 83);
			this->circle->Name = L"circle";
			this->circle->Size = System::Drawing::Size(155, 25);
			this->circle->TabIndex = 3;
			this->circle->Text = L"Окружность";
			this->circle->UseVisualStyleBackColor = true;
			this->circle->Click += gcnew System::EventHandler(this, &MyForm::circle_Click);
			// 
			// elipse
			// 
			this->elipse->Location = System::Drawing::Point(12, 254);
			this->elipse->Name = L"elipse";
			this->elipse->Size = System::Drawing::Size(155, 29);
			this->elipse->TabIndex = 4;
			this->elipse->Text = L"Элипсы";
			this->elipse->UseVisualStyleBackColor = true;
			this->elipse->Click += gcnew System::EventHandler(this, &MyForm::elipse_Click);
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
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(75, 234);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 13);
			this->label8->TabIndex = 27;
			this->label8->Text = L"rad2";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(75, 208);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(28, 13);
			this->label9->TabIndex = 26;
			this->label9->Text = L"rad1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 234);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"y1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 208);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(18, 13);
			this->label11->TabIndex = 24;
			this->label11->Text = L"x1";
			// 
			// rad2_elipse
			// 
			this->rad2_elipse->Location = System::Drawing::Point(109, 231);
			this->rad2_elipse->Name = L"rad2_elipse";
			this->rad2_elipse->Size = System::Drawing::Size(31, 20);
			this->rad2_elipse->TabIndex = 23;
			this->rad2_elipse->Text = L"10";
			// 
			// rad1_elipse
			// 
			this->rad1_elipse->Location = System::Drawing::Point(109, 205);
			this->rad1_elipse->Name = L"rad1_elipse";
			this->rad1_elipse->Size = System::Drawing::Size(31, 20);
			this->rad1_elipse->TabIndex = 22;
			this->rad1_elipse->Text = L"50";
			// 
			// y1_elipse
			// 
			this->y1_elipse->Location = System::Drawing::Point(36, 231);
			this->y1_elipse->Name = L"y1_elipse";
			this->y1_elipse->Size = System::Drawing::Size(31, 20);
			this->y1_elipse->TabIndex = 21;
			this->y1_elipse->Text = L"0";
			// 
			// x1_elipse
			// 
			this->x1_elipse->Location = System::Drawing::Point(36, 205);
			this->x1_elipse->Name = L"x1_elipse";
			this->x1_elipse->Size = System::Drawing::Size(31, 20);
			this->x1_elipse->TabIndex = 20;
			this->x1_elipse->Text = L"0";
			// 
			// existedMethodChecker
			// 
			this->existedMethodChecker->AutoSize = true;
			this->existedMethodChecker->Location = System::Drawing::Point(12, 135);
			this->existedMethodChecker->Name = L"existedMethodChecker";
			this->existedMethodChecker->Size = System::Drawing::Size(138, 17);
			this->existedMethodChecker->TabIndex = 28;
			this->existedMethodChecker->Text = L"Встроенные средства";
			this->existedMethodChecker->UseVisualStyleBackColor = true;
			this->existedMethodChecker->CheckedChanged += gcnew System::EventHandler(this, &MyForm::existedMethodChecker_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 409);
			this->Controls->Add(this->existedMethodChecker);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->rad2_elipse);
			this->Controls->Add(this->rad1_elipse);
			this->Controls->Add(this->y1_elipse);
			this->Controls->Add(this->x1_elipse);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->elipse);
			this->Controls->Add(this->circle);
			this->Controls->Add(this->line);
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


	private: System::Void line_Click(System::Object^  sender, System::EventArgs^  e) {
		switcher = 0;
	}

	private: System::Void circle_Click(System::Object^  sender, System::EventArgs^  e) {
		switcher = 1;
	}

	private: System::Void elipse_Click(System::Object^  sender, System::EventArgs^  e) {
		switcher = 2;
	}

	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
		cleanCanvas();
	}

	private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Программа выполнена студенткой группы БПИ143(1) \nРепиной Анастасией Андреевной \nСреда разработки: Visual Studio 2015 Entherprise \nОС Windows 10 \nДата 07.09.2017 \nВыполнены пункты: 1), 2), 3)", "О программе");
	}

	private: void cleanCanvas()
	{
		im->Clear(col->White);
	}

			 //алгоритм Брезенхема построения отрезка
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

	//алгоритм Брезенхема построения окружности
	public: System::Void bres_circle()
	{
		int x = 0;
		int y = rad1;
		int delta = 2 * (1 - rad1);
		int predel = 0;
		int sigma = 0;
		do
		{
			im->FillRectangle(blueBrush, x, y, 1, 1);
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

	public: System::Void bres_elipse()
	{
		//поч не рисует!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (x1_elipse->Text == "" || rad1_elipse->Text == "" || y1_elipse->Text == "" || rad2_elipse->Text == "")
		{
			MessageBox::Show("Требуется ввести все значения полей!", "Ошибка");
			return;
		}
		//заданные пользователем координаты
		int x1 = Convert::ToInt32(x1_elipse->Text);
		int y1 = Convert::ToInt32(y1_elipse->Text);
		int rad1 = Convert::ToInt32(rad1_elipse->Text);
		int rad2 = Convert::ToInt32(rad2_elipse->Text);
		im->DrawEllipse(pen, x1, y1, rad1, rad2);//для сравнения другим цветом
		//целочисленный алгоритм построения	эллипса
	}


	private: System::Void canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		switch (switcher)
		{
		case 0://line
		{
			if (x1 != -1 && y1 != -1)
			{
				x2 = e->X;
				y2 = e->Y;
				existedMethod == false ? im->DrawLine(pen, x1, y1, x2, y2) : bres_line();
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
				rad1 = sqrt(pow((abs(cur_x - x1)), 2) + pow((abs(cur_y - y1)), 2));
				existedMethod == false ? im->DrawEllipse(pen, x1 - rad1, y1 - rad1, rad1 * 2, rad1 * 2) : bres_circle();
				x1 = -1;
				y1 = -1;
			}
			else {
				x1 = e->X;
				y1 = e->Y;
			}
			break;
		}
		case 2://elipse
		{
			break;
		}
		}
	}
	private: System::Void existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		existedMethod = !existedMethod;
	}
	};
}
