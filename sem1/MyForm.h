//Программа выполнена студенткой группы БПИ143(1) Репиной Анастасией Андреевной. 
//Среда разработки: Visual Studio 2015 Entherprise, ОС Windows 10
//Дата 07.09.2017
//Выполнены пункты:
//1)bresenham line algo
//2)bresenham circle algo
//3)ellipse algo
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
			rad_first = -1;
			rad_second = -1;
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
	private: int x1, y1, x2, y2, rad_first, rad_second;
	private: bool existedMethod;
	private: System::Windows::Forms::PictureBox^  canvas;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::CheckBox^  existedMethodChecker;
	private: System::Windows::Forms::ComboBox^  objects;
	private: System::Windows::Forms::Button^  random_generate;
	private: System::Windows::Forms::Button^  draw_from_file;

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
			this->random_generate = (gcnew System::Windows::Forms::Button());
			this->draw_from_file = (gcnew System::Windows::Forms::Button());
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
			this->clear->Size = System::Drawing::Size(138, 31);
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
			this->objects->Size = System::Drawing::Size(138, 21);
			this->objects->TabIndex = 29;
			// 
			// random_generate
			// 
			this->random_generate->Location = System::Drawing::Point(12, 93);
			this->random_generate->Name = L"random_generate";
			this->random_generate->Size = System::Drawing::Size(138, 23);
			this->random_generate->TabIndex = 30;
			this->random_generate->Text = L"Рандом";
			this->random_generate->UseVisualStyleBackColor = true;
			this->random_generate->Click += gcnew System::EventHandler(this, &MyForm::random_generate_Click);
			// 
			// draw_from_file
			// 
			this->draw_from_file->Location = System::Drawing::Point(12, 251);
			this->draw_from_file->Name = L"draw_from_file";
			this->draw_from_file->Size = System::Drawing::Size(138, 31);
			this->draw_from_file->TabIndex = 31;
			this->draw_from_file->Text = L"Рисовать из файла";
			this->draw_from_file->UseVisualStyleBackColor = true;
			this->draw_from_file->Click += gcnew System::EventHandler(this, &MyForm::draw_from_file_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 365);
			this->Controls->Add(this->draw_from_file);
			this->Controls->Add(this->random_generate);
			this->Controls->Add(this->objects);
			this->Controls->Add(this->existedMethodChecker);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Repina Anastasia BSE143";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void cleanCanvas();
	public: System::Void bres_line();//bresenham line algo
	public: System::Void bres_circle();//bresenham circle algo
	public: System::Void bres_ellipse();//ellipse algo
	private: System::Void draw_pixels(int x, int y);//place pixels on canvas
	private: System::Void what_to_draw(int ex, int ey);//choose what to draw
	private: System::Void random_click_imitation(int click_number);
	private: System::Void canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void random_generate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void draw_from_file_Click(System::Object^  sender, System::EventArgs^  e);
};
}
