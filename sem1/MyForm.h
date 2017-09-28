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
		Color current_color;
		bool existed_method, is_line_by_line, is_xor, is_window_mode, is_objects, is_line, is_circle, is_ellipse;
	private: System::Windows::Forms::PictureBox^  canvas;
			 System::Windows::Forms::MenuStrip^  menuStrip1;
			 System::Windows::Forms::ToolStripMenuItem^  createObjectToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;
			 System::Windows::Forms::CheckBox^  existedMethodChecker;
			 System::Windows::Forms::ToolStripMenuItem^  fillToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
			 System::Windows::Forms::ColorDialog^  colorDialog1;
			 System::Windows::Forms::ToolStripMenuItem^  работаСФайломToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  loadfileToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  savefileToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  cleanToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  lineByLineToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  xorToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  LineToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  ellipseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  randomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorChooserToolStripMenuItem;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;


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
			this->LineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineByLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->работаСФайломToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->savefileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cleanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorChooserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->existedMethodChecker = (gcnew System::Windows::Forms::CheckBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->BackColor = System::Drawing::Color::White;
			this->canvas->Location = System::Drawing::Point(-71, 27);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(1532, 686);
			this->canvas->TabIndex = 0;
			this->canvas->TabStop = false;
			this->canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::canvas_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->createObjectToolStripMenuItem,
					this->randomToolStripMenuItem, this->fillToolStripMenuItem, this->cutToolStripMenuItem, this->работаСФайломToolStripMenuItem,
					this->cleanToolStripMenuItem, this->colorChooserToolStripMenuItem, this->aboutProgramToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(845, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createObjectToolStripMenuItem
			// 
			this->createObjectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->LineToolStripMenuItem,
					this->circleToolStripMenuItem, this->ellipseToolStripMenuItem
			});
			this->createObjectToolStripMenuItem->Name = L"createObjectToolStripMenuItem";
			this->createObjectToolStripMenuItem->Size = System::Drawing::Size(112, 20);
			this->createObjectToolStripMenuItem->Text = L"Создать объекты";
			this->createObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::createObjectToolStripMenuItem_Click);
			// 
			// LineToolStripMenuItem
			// 
			this->LineToolStripMenuItem->Name = L"LineToolStripMenuItem";
			this->LineToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->LineToolStripMenuItem->Text = L"Линия";
			this->LineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LineToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->circleToolStripMenuItem->Text = L"Круг";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// ellipseToolStripMenuItem
			// 
			this->ellipseToolStripMenuItem->Name = L"ellipseToolStripMenuItem";
			this->ellipseToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->ellipseToolStripMenuItem->Text = L"Эллипс";
			this->ellipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->randomToolStripMenuItem->Text = L"Рандом";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomToolStripMenuItem_Click_1);
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->lineByLineToolStripMenuItem,
					this->xorToolStripMenuItem
			});
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->fillToolStripMenuItem->Text = L"Заливка";
			// 
			// lineByLineToolStripMenuItem
			// 
			this->lineByLineToolStripMenuItem->Name = L"lineByLineToolStripMenuItem";
			this->lineByLineToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->lineByLineToolStripMenuItem->Text = L"Построчная";
			this->lineByLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineByLineToolStripMenuItem_Click);
			// 
			// xorToolStripMenuItem
			// 
			this->xorToolStripMenuItem->Name = L"xorToolStripMenuItem";
			this->xorToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->xorToolStripMenuItem->Text = L"XOR";
			this->xorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::xorToolStripMenuItem_Click);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(78, 20);
			this->cutToolStripMenuItem->Text = L"Отсечение";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cutToolStripMenuItem_Click);
			// 
			// работаСФайломToolStripMenuItem
			// 
			this->работаСФайломToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadfileToolStripMenuItem,
					this->savefileToolStripMenuItem
			});
			this->работаСФайломToolStripMenuItem->Name = L"работаСФайломToolStripMenuItem";
			this->работаСФайломToolStripMenuItem->Size = System::Drawing::Size(114, 20);
			this->работаСФайломToolStripMenuItem->Text = L"Работа с файлом";
			// 
			// loadfileToolStripMenuItem
			// 
			this->loadfileToolStripMenuItem->Name = L"loadfileToolStripMenuItem";
			this->loadfileToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->loadfileToolStripMenuItem->Text = L"Загрузка";
			this->loadfileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadfileToolStripMenuItem_Click);
			// 
			// savefileToolStripMenuItem
			// 
			this->savefileToolStripMenuItem->Name = L"savefileToolStripMenuItem";
			this->savefileToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->savefileToolStripMenuItem->Text = L"Сохранение";
			this->savefileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::savefileToolStripMenuItem_Click);
			// 
			// cleanToolStripMenuItem
			// 
			this->cleanToolStripMenuItem->Name = L"cleanToolStripMenuItem";
			this->cleanToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->cleanToolStripMenuItem->Text = L"Очистить";
			this->cleanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cleanToolStripMenuItem_Click);
			// 
			// colorChooserToolStripMenuItem
			// 
			this->colorChooserToolStripMenuItem->Name = L"colorChooserToolStripMenuItem";
			this->colorChooserToolStripMenuItem->Size = System::Drawing::Size(89, 20);
			this->colorChooserToolStripMenuItem->Text = L"Выбор цвета";
			this->colorChooserToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::colorChooserToolStripMenuItem_Click);
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->aboutProgramToolStripMenuItem->Text = L"О программе";
			this->aboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutProgramToolStripMenuItem_Click);
			// 
			// existedMethodChecker
			// 
			this->existedMethodChecker->AutoSize = true;
			this->existedMethodChecker->BackColor = System::Drawing::SystemColors::ControlLight;
			this->existedMethodChecker->Location = System::Drawing::Point(686, 4);
			this->existedMethodChecker->Name = L"existedMethodChecker";
			this->existedMethodChecker->Size = System::Drawing::Size(138, 17);
			this->existedMethodChecker->TabIndex = 28;
			this->existedMethodChecker->Text = L"Встроенные средства";
			this->existedMethodChecker->UseVisualStyleBackColor = false;
			this->existedMethodChecker->CheckedChanged += gcnew System::EventHandler(this, &MyForm::existedMethodChecker_CheckedChanged);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 343);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(845, 22);
			this->statusStrip1->TabIndex = 39;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(845, 365);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->existedMethodChecker);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Repina Anastasia BSE143 HW2 Fill and Cut";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvas))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
	private: System::Void createObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void load_lines_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void loadfileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void savefileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cleanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lineByLineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void xorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ellipseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void randomToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e);
	private: System::Void colorChooserToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
