//All the info is in the about
#pragma once
#include <cmath>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <stack> 
#include <iterator>

using namespace std;

#include "Bresenhem.h"
#include "Fill.h"
#include "Cut.h"
#include "Figure.h"

namespace sem1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

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

	public: 
			List<Point>^ dots = gcnew List<Point>();
			List<Figure^>^ figures = gcnew List<Figure^>();
			static Bitmap ^bm;
			static Graphics ^im;				
			bool existed_method, is_line_by_line, is_xor, is_window_mode;
	private: System::Windows::Forms::PictureBox^  canvas;
			 System::Windows::Forms::MenuStrip^  menuStrip1;
			 System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;
			 System::Windows::Forms::Button^  clear;
			 System::Windows::Forms::CheckBox^  existedMethodChecker;
			 System::Windows::Forms::ComboBox^  objects;
			 System::Windows::Forms::Button^  random_generate;
			 System::Windows::Forms::Button^  draw_from_file;
			 System::Windows::Forms::GroupBox^  fill_groupbox;
			 System::Windows::Forms::RadioButton^  xor_fill;
			 System::Windows::Forms::RadioButton^  line_by_line_fill;
			 System::Windows::Forms::GroupBox^  draw_groupbox;
			 System::Windows::Forms::ToolStripMenuItem^  fillToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
			 System::Windows::Forms::GroupBox^  cut_groupbox;
			 System::Windows::Forms::Button^  load_lines;
			 System::Windows::Forms::CheckBox^  window_mode;
			 System::Windows::Forms::ColorDialog^  colorDialog1;
			 System::Windows::Forms::Button^  color_chooser;
			 System::Windows::Forms::PictureBox^  current_color;
			 System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  save_to_file;

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
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->existedMethodChecker = (gcnew System::Windows::Forms::CheckBox());
			this->objects = (gcnew System::Windows::Forms::ComboBox());
			this->random_generate = (gcnew System::Windows::Forms::Button());
			this->draw_from_file = (gcnew System::Windows::Forms::Button());
			this->fill_groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->xor_fill = (gcnew System::Windows::Forms::RadioButton());
			this->line_by_line_fill = (gcnew System::Windows::Forms::RadioButton());
			this->draw_groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->cut_groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->window_mode = (gcnew System::Windows::Forms::CheckBox());
			this->load_lines = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->color_chooser = (gcnew System::Windows::Forms::Button());
			this->current_color = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->save_to_file = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->fill_groupbox->SuspendLayout();
			this->draw_groupbox->SuspendLayout();
			this->cut_groupbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->current_color))->BeginInit();
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->createObjectToolStripMenuItem,
					this->fillToolStripMenuItem, this->cutToolStripMenuItem, this->aboutProgramToolStripMenuItem
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
			this->createObjectToolStripMenuItem->Size = System::Drawing::Size(112, 20);
			this->createObjectToolStripMenuItem->Text = L"Создать объекты";
			this->createObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::createObjectToolStripMenuItem_Click);
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->fillToolStripMenuItem->Text = L"Заливка";
			this->fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fillToolStripMenuItem_Click);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(78, 20);
			this->cutToolStripMenuItem->Text = L"Отсечение";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cutToolStripMenuItem_Click);
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
			this->clear->Size = System::Drawing::Size(151, 31);
			this->clear->TabIndex = 5;
			this->clear->Text = L"Очистить";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &MyForm::clear_Click);
			// 
			// existedMethodChecker
			// 
			this->existedMethodChecker->AutoSize = true;
			this->existedMethodChecker->Location = System::Drawing::Point(6, 46);
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
			this->objects->Location = System::Drawing::Point(6, 19);
			this->objects->Name = L"objects";
			this->objects->Size = System::Drawing::Size(138, 21);
			this->objects->TabIndex = 29;
			// 
			// random_generate
			// 
			this->random_generate->Location = System::Drawing::Point(6, 69);
			this->random_generate->Name = L"random_generate";
			this->random_generate->Size = System::Drawing::Size(138, 23);
			this->random_generate->TabIndex = 30;
			this->random_generate->Text = L"Рандомная генерация";
			this->random_generate->UseVisualStyleBackColor = true;
			this->random_generate->Click += gcnew System::EventHandler(this, &MyForm::random_generate_Click);
			// 
			// draw_from_file
			// 
			this->draw_from_file->Location = System::Drawing::Point(6, 98);
			this->draw_from_file->Name = L"draw_from_file";
			this->draw_from_file->Size = System::Drawing::Size(138, 26);
			this->draw_from_file->TabIndex = 31;
			this->draw_from_file->Text = L"Рисовать из файла";
			this->draw_from_file->UseVisualStyleBackColor = true;
			this->draw_from_file->Click += gcnew System::EventHandler(this, &MyForm::draw_from_file_Click);
			// 
			// fill_groupbox
			// 
			this->fill_groupbox->Controls->Add(this->xor_fill);
			this->fill_groupbox->Controls->Add(this->line_by_line_fill);
			this->fill_groupbox->Location = System::Drawing::Point(12, 27);
			this->fill_groupbox->Name = L"fill_groupbox";
			this->fill_groupbox->Size = System::Drawing::Size(151, 100);
			this->fill_groupbox->TabIndex = 33;
			this->fill_groupbox->TabStop = false;
			this->fill_groupbox->Text = L"Заливка";
			this->fill_groupbox->Visible = false;
			// 
			// xor_fill
			// 
			this->xor_fill->AutoSize = true;
			this->xor_fill->Location = System::Drawing::Point(7, 44);
			this->xor_fill->Name = L"xor_fill";
			this->xor_fill->Size = System::Drawing::Size(48, 17);
			this->xor_fill->TabIndex = 1;
			this->xor_fill->Text = L"XOR";
			this->xor_fill->UseVisualStyleBackColor = true;
			this->xor_fill->CheckedChanged += gcnew System::EventHandler(this, &MyForm::xor_fill_CheckedChanged);
			// 
			// line_by_line_fill
			// 
			this->line_by_line_fill->AutoSize = true;
			this->line_by_line_fill->Checked = true;
			this->line_by_line_fill->Location = System::Drawing::Point(7, 20);
			this->line_by_line_fill->Name = L"line_by_line_fill";
			this->line_by_line_fill->Size = System::Drawing::Size(85, 17);
			this->line_by_line_fill->TabIndex = 0;
			this->line_by_line_fill->TabStop = true;
			this->line_by_line_fill->Text = L"Построчная";
			this->line_by_line_fill->UseVisualStyleBackColor = true;
			this->line_by_line_fill->CheckedChanged += gcnew System::EventHandler(this, &MyForm::line_by_line_fill_CheckedChanged);
			// 
			// draw_groupbox
			// 
			this->draw_groupbox->Controls->Add(this->save_to_file);
			this->draw_groupbox->Controls->Add(this->objects);
			this->draw_groupbox->Controls->Add(this->existedMethodChecker);
			this->draw_groupbox->Controls->Add(this->draw_from_file);
			this->draw_groupbox->Controls->Add(this->random_generate);
			this->draw_groupbox->Location = System::Drawing::Point(12, 27);
			this->draw_groupbox->Name = L"draw_groupbox";
			this->draw_groupbox->Size = System::Drawing::Size(151, 156);
			this->draw_groupbox->TabIndex = 34;
			this->draw_groupbox->TabStop = false;
			this->draw_groupbox->Text = L"Рисование";
			// 
			// cut_groupbox
			// 
			this->cut_groupbox->Controls->Add(this->window_mode);
			this->cut_groupbox->Controls->Add(this->load_lines);
			this->cut_groupbox->Location = System::Drawing::Point(12, 27);
			this->cut_groupbox->Name = L"cut_groupbox";
			this->cut_groupbox->Size = System::Drawing::Size(151, 113);
			this->cut_groupbox->TabIndex = 35;
			this->cut_groupbox->TabStop = false;
			this->cut_groupbox->Text = L"Отсечение";
			this->cut_groupbox->Visible = false;
			// 
			// window_mode
			// 
			this->window_mode->AutoSize = true;
			this->window_mode->Location = System::Drawing::Point(7, 71);
			this->window_mode->Name = L"window_mode";
			this->window_mode->Size = System::Drawing::Size(88, 17);
			this->window_mode->TabIndex = 5;
			this->window_mode->Text = L"Режим окна";
			this->window_mode->UseVisualStyleBackColor = true;
			this->window_mode->CheckedChanged += gcnew System::EventHandler(this, &MyForm::window_mode_CheckedChanged);
			// 
			// load_lines
			// 
			this->load_lines->Location = System::Drawing::Point(7, 20);
			this->load_lines->Name = L"load_lines";
			this->load_lines->Size = System::Drawing::Size(131, 44);
			this->load_lines->TabIndex = 4;
			this->load_lines->Text = L"Загрузить отрезки из файла";
			this->load_lines->UseVisualStyleBackColor = true;
			this->load_lines->Click += gcnew System::EventHandler(this, &MyForm::load_lines_Click);
			// 
			// color_chooser
			// 
			this->color_chooser->Location = System::Drawing::Point(12, 227);
			this->color_chooser->Name = L"color_chooser";
			this->color_chooser->Size = System::Drawing::Size(151, 23);
			this->color_chooser->TabIndex = 36;
			this->color_chooser->Text = L"Выбор цвета";
			this->color_chooser->UseVisualStyleBackColor = true;
			this->color_chooser->Click += gcnew System::EventHandler(this, &MyForm::color_chooser_Click);
			// 
			// current_color
			// 
			this->current_color->BackColor = System::Drawing::Color::White;
			this->current_color->Location = System::Drawing::Point(99, 189);
			this->current_color->Name = L"current_color";
			this->current_color->Size = System::Drawing::Size(32, 32);
			this->current_color->TabIndex = 37;
			this->current_color->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 197);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Текущий цвет";
			// 
			// save_to_file
			// 
			this->save_to_file->Location = System::Drawing::Point(6, 131);
			this->save_to_file->Name = L"save_to_file";
			this->save_to_file->Size = System::Drawing::Size(138, 23);
			this->save_to_file->TabIndex = 32;
			this->save_to_file->Text = L"Сохранить в файл";
			this->save_to_file->UseVisualStyleBackColor = true;
			this->save_to_file->Click += gcnew System::EventHandler(this, &MyForm::save_to_file_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 365);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->current_color);
			this->Controls->Add(this->color_chooser);
			this->Controls->Add(this->cut_groupbox);
			this->Controls->Add(this->draw_groupbox);
			this->Controls->Add(this->fill_groupbox);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Repina Anastasia BSE143 HW2 Fill and Cut";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->fill_groupbox->ResumeLayout(false);
			this->fill_groupbox->PerformLayout();
			this->draw_groupbox->ResumeLayout(false);
			this->draw_groupbox->PerformLayout();
			this->cut_groupbox->ResumeLayout(false);
			this->cut_groupbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->current_color))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void cleanCanvas();
	private: System::Void what_to_draw(int ex, int ey);//choose what to draw
	private: System::Void random_click_imitation(int click_number);//imitate the figures random
	private: System::Void draw_objects(int ex, int ey);
	private: System::Void draw_line_by_line(int ex, int ey);
	private: System::Void draw_xor(int ex, int ey);
	private: System::Void draw_window(int ex, int ey);
	private: System::Void canvas_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);//clicked on canvas
	private: System::Void existedMethodChecker_CheckedChanged(System::Object^  sender, System::EventArgs^  e);//changed the drawing way
	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e);//clear the canvas
	private: System::Void aboutProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);//info
	private: System::Void random_generate_Click(System::Object^  sender, System::EventArgs^  e);////random button clicked
	private: System::Void draw_from_file_Click(System::Object^  sender, System::EventArgs^  e);//draw from file
	private: System::Void line_by_line_fill_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void xor_fill_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void createObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void fillToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void load_lines_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void window_mode_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void color_chooser_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void save_to_file_Click(System::Object^  sender, System::EventArgs^  e);
};
}
