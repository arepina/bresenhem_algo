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
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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
		List<Point>^ xordots = gcnew List<Point>();
		List<Figure^>^ figures = gcnew List<Figure^>();
		static Bitmap ^bm;
		static Graphics ^im;
		Color current_color;
		bool existed_method, is_line_by_line, is_window_mode, is_objects, is_line, is_circle, is_ellipse, is_xor;
	private: System::Windows::Forms::PictureBox^  canvas;
			 System::Windows::Forms::MenuStrip^  menuStrip1;
			 System::Windows::Forms::ToolStripMenuItem^  aboutProgramToolStripMenuItem;
			 System::Windows::Forms::CheckBox^  existedMethodChecker;
			 System::Windows::Forms::ColorDialog^  colorDialog1;
			 System::Windows::Forms::ToolStripMenuItem^  cleanToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  randomToolStripMenuItem;
			 System::Windows::Forms::StatusStrip^  statusStrip1;
			 System::Windows::Forms::ToolStripMenuItem^  îïöèèToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  creteObjectToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  çàëèâêàToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  linebylineToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  xorToolStripMenuItem1;
			 System::Windows::Forms::ToolStripMenuItem^  ğàáîòàÑÔàéëîìToolStripMenuItem1;
			 System::Windows::Forms::ToolStripMenuItem^  loadFileToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  saveFileToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  ellipseToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
			 System::Windows::Forms::ToolStripMenuItem^  colorChooserToolStripMenuItem;
			 
	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->canvas = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->îïöèèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creteObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàëèâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->linebylineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğàáîòàÑÔàéëîìToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorChooserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cleanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->îïöèèToolStripMenuItem,
					this->randomToolStripMenuItem, this->cleanToolStripMenuItem, this->aboutProgramToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(845, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// îïöèèToolStripMenuItem
			// 
			this->îïöèèToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->creteObjectToolStripMenuItem,
					this->çàëèâêàToolStripMenuItem, this->cutToolStripMenuItem, this->ğàáîòàÑÔàéëîìToolStripMenuItem1, this->colorChooserToolStripMenuItem
			});
			this->îïöèèToolStripMenuItem->Name = L"îïöèèToolStripMenuItem";
			this->îïöèèToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->îïöèèToolStripMenuItem->Text = L"Îïöèè";
			// 
			// creteObjectToolStripMenuItem
			// 
			this->creteObjectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->lineToolStripMenuItem,
					this->circleToolStripMenuItem, this->ellipseToolStripMenuItem
			});
			this->creteObjectToolStripMenuItem->Name = L"creteObjectToolStripMenuItem";
			this->creteObjectToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->creteObjectToolStripMenuItem->Text = L"Ñîçäàòü îáúåêòû";
			// 
			// lineToolStripMenuItem
			// 
			this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
			this->lineToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->lineToolStripMenuItem->Text = L"Ëèíèÿ";
			this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->circleToolStripMenuItem->Text = L"Îêğóæíîñòü";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// ellipseToolStripMenuItem
			// 
			this->ellipseToolStripMenuItem->Name = L"ellipseToolStripMenuItem";
			this->ellipseToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->ellipseToolStripMenuItem->Text = L"İëëèïñ";
			this->ellipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ellipseToolStripMenuItem_Click);
			// 
			// çàëèâêàToolStripMenuItem
			// 
			this->çàëèâêàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->linebylineToolStripMenuItem,
					this->xorToolStripMenuItem1
			});
			this->çàëèâêàToolStripMenuItem->Name = L"çàëèâêàToolStripMenuItem";
			this->çàëèâêàToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->çàëèâêàToolStripMenuItem->Text = L"Çàëèâêà";
			// 
			// linebylineToolStripMenuItem
			// 
			this->linebylineToolStripMenuItem->Name = L"linebylineToolStripMenuItem";
			this->linebylineToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->linebylineToolStripMenuItem->Text = L"Ïîñòğî÷íàÿ";
			this->linebylineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineByLineToolStripMenuItem_Click);
			// 
			// xorToolStripMenuItem1
			// 
			this->xorToolStripMenuItem1->Name = L"xorToolStripMenuItem1";
			this->xorToolStripMenuItem1->Size = System::Drawing::Size(141, 22);
			this->xorToolStripMenuItem1->Text = L"XOR";
			this->xorToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::xorToolStripMenuItem_Click);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->cutToolStripMenuItem->Text = L"Îòñå÷åíèå";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cutToolStripMenuItem_Click);
			// 
			// ğàáîòàÑÔàéëîìToolStripMenuItem1
			// 
			this->ğàáîòàÑÔàéëîìToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadFileToolStripMenuItem,
					this->saveFileToolStripMenuItem
			});
			this->ğàáîòàÑÔàéëîìToolStripMenuItem1->Name = L"ğàáîòàÑÔàéëîìToolStripMenuItem1";
			this->ğàáîòàÑÔàéëîìToolStripMenuItem1->Size = System::Drawing::Size(169, 22);
			this->ğàáîòàÑÔàéëîìToolStripMenuItem1->Text = L"Ğàáîòà ñ ôàéëîì";
			// 
			// loadFileToolStripMenuItem
			// 
			this->loadFileToolStripMenuItem->Name = L"loadFileToolStripMenuItem";
			this->loadFileToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->loadFileToolStripMenuItem->Text = L"Çàãğóçèòü ôàéë";
			this->loadFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadfileToolStripMenuItem_Click);
			// 
			// saveFileToolStripMenuItem
			// 
			this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
			this->saveFileToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->saveFileToolStripMenuItem->Text = L"Ñîõğàíèòü â ôàéë";
			this->saveFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::savefileToolStripMenuItem_Click);
			// 
			// colorChooserToolStripMenuItem
			// 
			this->colorChooserToolStripMenuItem->Name = L"colorChooserToolStripMenuItem";
			this->colorChooserToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->colorChooserToolStripMenuItem->Text = L"Âûáîğ öâåòà";
			this->colorChooserToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::colorChooserToolStripMenuItem_Click);
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->randomToolStripMenuItem->Text = L"Ğàíäîì";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomToolStripMenuItem_Click_1);
			// 
			// cleanToolStripMenuItem
			// 
			this->cleanToolStripMenuItem->Name = L"cleanToolStripMenuItem";
			this->cleanToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->cleanToolStripMenuItem->Text = L"Î÷èñòèòü";
			this->cleanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cleanToolStripMenuItem_Click);
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->aboutProgramToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->aboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutProgramToolStripMenuItem_Click);
			// 
			// existedMethodChecker
			// 
			this->existedMethodChecker->AutoSize = true;
			this->existedMethodChecker->BackColor = System::Drawing::SystemColors::ControlLight;
			this->existedMethodChecker->Checked = true;
			this->existedMethodChecker->CheckState = System::Windows::Forms::CheckState::Checked;
			this->existedMethodChecker->Location = System::Drawing::Point(295, 4);
			this->existedMethodChecker->Name = L"existedMethodChecker";
			this->existedMethodChecker->Size = System::Drawing::Size(138, 17);
			this->existedMethodChecker->TabIndex = 28;
			this->existedMethodChecker->Text = L"Âñòğîåííûå ñğåäñòâà";
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
	private: System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void load_lines_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void loadfileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void savefileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cleanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lineByLineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void xorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ellipseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void randomToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e);
	private: System::Void colorChooserToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
