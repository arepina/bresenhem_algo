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
			draw_axes();//поч не рисует!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::Button^  line;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;


	private: System::Windows::Forms::Button^  circle;
	private: System::Windows::Forms::Button^  elipse;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::TextBox^  x1_field;
	private: System::Windows::Forms::TextBox^  y1_field;
	private: System::Windows::Forms::TextBox^  x2_field;
	private: System::Windows::Forms::TextBox^  y2_field;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  y1_circle;
	private: System::Windows::Forms::TextBox^  x1_circle;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  rad_circle;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  rad2_elipse;
	private: System::Windows::Forms::TextBox^  rad1_elipse;
	private: System::Windows::Forms::TextBox^  y1_elipse;
	private: System::Windows::Forms::TextBox^  x1_elipse;


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
			this->x1_field = (gcnew System::Windows::Forms::TextBox());
			this->y1_field = (gcnew System::Windows::Forms::TextBox());
			this->x2_field = (gcnew System::Windows::Forms::TextBox());
			this->y2_field = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->y1_circle = (gcnew System::Windows::Forms::TextBox());
			this->x1_circle = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->rad_circle = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->rad2_elipse = (gcnew System::Windows::Forms::TextBox());
			this->rad1_elipse = (gcnew System::Windows::Forms::TextBox());
			this->y1_elipse = (gcnew System::Windows::Forms::TextBox());
			this->x1_elipse = (gcnew System::Windows::Forms::TextBox());
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
			// 
			// line
			// 
			this->line->Location = System::Drawing::Point(12, 95);
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
			this->circle->Location = System::Drawing::Point(12, 174);
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
			// x1_field
			// 
			this->x1_field->Location = System::Drawing::Point(36, 43);
			this->x1_field->Name = L"x1_field";
			this->x1_field->Size = System::Drawing::Size(31, 20);
			this->x1_field->TabIndex = 6;
			this->x1_field->Text = L"0";
			// 
			// y1_field
			// 
			this->y1_field->Location = System::Drawing::Point(36, 69);
			this->y1_field->Name = L"y1_field";
			this->y1_field->Size = System::Drawing::Size(31, 20);
			this->y1_field->TabIndex = 7;
			this->y1_field->Text = L"0";
			// 
			// x2_field
			// 
			this->x2_field->Location = System::Drawing::Point(99, 43);
			this->x2_field->Name = L"x2_field";
			this->x2_field->Size = System::Drawing::Size(31, 20);
			this->x2_field->TabIndex = 8;
			this->x2_field->Text = L"50";
			// 
			// y2_field
			// 
			this->y2_field->Location = System::Drawing::Point(99, 69);
			this->y2_field->Name = L"y2_field";
			this->y2_field->Size = System::Drawing::Size(31, 20);
			this->y2_field->TabIndex = 9;
			this->y2_field->Text = L"10";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"x1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"y1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(75, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"x2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(75, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"y2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"y1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"x1";
			// 
			// y1_circle
			// 
			this->y1_circle->Location = System::Drawing::Point(36, 152);
			this->y1_circle->Name = L"y1_circle";
			this->y1_circle->Size = System::Drawing::Size(31, 20);
			this->y1_circle->TabIndex = 15;
			this->y1_circle->Text = L"0";
			// 
			// x1_circle
			// 
			this->x1_circle->Location = System::Drawing::Point(36, 126);
			this->x1_circle->Name = L"x1_circle";
			this->x1_circle->Size = System::Drawing::Size(31, 20);
			this->x1_circle->TabIndex = 14;
			this->x1_circle->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(75, 129);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(22, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"rad";
			// 
			// rad_circle
			// 
			this->rad_circle->Location = System::Drawing::Point(99, 126);
			this->rad_circle->Name = L"rad_circle";
			this->rad_circle->Size = System::Drawing::Size(31, 20);
			this->rad_circle->TabIndex = 18;
			this->rad_circle->Text = L"100";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 409);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->rad2_elipse);
			this->Controls->Add(this->rad1_elipse);
			this->Controls->Add(this->y1_elipse);
			this->Controls->Add(this->x1_elipse);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rad_circle);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->y1_circle);
			this->Controls->Add(this->x1_circle);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->y2_field);
			this->Controls->Add(this->x2_field);
			this->Controls->Add(this->y1_field);
			this->Controls->Add(this->x1_field);
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
		bres_line();
	}

	private: System::Void circle_Click(System::Object^  sender, System::EventArgs^  e) {
		bres_circle();
	}

	private: System::Void elipse_Click(System::Object^  sender, System::EventArgs^  e) {
		bres_elipse();
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

	public: System::Void bres_line()
	{
		if (x1_field->Text == "" || x2_field->Text == "" || y1_field->Text == "" || y2_field->Text == "")
		{
			MessageBox::Show("Требуется ввести все значения полей!", "Ошибка");
			return;
		}
		//заданные пользователем координаты
		int x1 = Convert::ToInt32(x1_field->Text);
		int y1 = Convert::ToInt32(y1_field->Text);
		int x2 = Convert::ToInt32(x2_field->Text);
		int y2 = Convert::ToInt32(y2_field->Text);
		//алгоритм Брезенхема построения отрезка
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
			im->FillRectangle(blueBrush, x, y, x, y);
			while (error_val >= 0)
			{
				obmen == 1 ? x = x + s1 : y = y + s2;
				error_val = error_val - 2 * delta_x;
			}
			obmen == 1 ? y = y + s2 : x = x + s1;
			error_val = error_val + 2 * delta_y;
		}
		im->DrawLine(pen, x1, y1, x2, y2);//для сравнения другим цветом
	}

	public: System::Void bres_circle()
	{
		//поч не юзаем игрек, поч ток часть круга!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (x1_circle->Text == "" || y1_circle->Text == "" || rad_circle->Text == "")
		{
			MessageBox::Show("Требуется ввести все значения полей!", "Ошибка");
			return;
		}
		//заданные пользователем координаты
		int x1 = Convert::ToInt32(x1_circle->Text);
		int y1 = Convert::ToInt32(y1_circle->Text);
		int rad = Convert::ToInt32(rad_circle->Text);
		im->DrawEllipse(pen, x1, y1, rad, rad);//для сравнения другим цветом
		//алгоритм Брезенхема построения окружности
		int x = 0;
		int y = rad;
		int delta = 2 * (1 - rad);
		int predel = 0;
		int sigma = 0;
		do
		{
			im->FillRectangle(blueBrush, x, y, x, y);
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
	{		//поч не рисует!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

	public: System::Void draw_axes()
	{
		int width = canvas->Width;
		int height = canvas->Height;
		im->DrawLine(gcnew Pen(col->Black), width / 2, 0, width / 2, height);
		im->DrawLine(gcnew Pen(col->Black), 0, height / 2, width, height / 2);
	}

	};
}
