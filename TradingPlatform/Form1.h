#pragma once
#include "data_format.h"
#include "strategies.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "HTTPRequest.hpp"
#include <msclr\marshal_cppstd.h>
using namespace std;

//cs_data candle_data = generate_dummy();
cs_data candle_data = init_data();

cs_data *cs_ptr = &candle_data;

int prev_min, cur_min;
bool man_st = false;
bool st1 = false;
bool st2 = false;

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;



	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label6;







	private: System::ComponentModel::IContainer^ components;


	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->label5);
			this->splitContainer1->Panel2->Controls->Add(this->label4);
			this->splitContainer1->Panel2->Controls->Add(this->panel5);
			this->splitContainer1->Panel2->Controls->Add(this->panel4);
			this->splitContainer1->Panel2->Controls->Add(this->panel3);
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Panel2->Controls->Add(this->panel2);
			this->splitContainer1->Panel2->Controls->Add(this->panel1);
			this->splitContainer1->Panel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.6F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->splitContainer1->Size = System::Drawing::Size(1310, 1037);
			this->splitContainer1->SplitterDistance = 749;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 0;
			// 
			// splitContainer2
			// 
			this->splitContainer2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(4);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->AutoScroll = true;
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer3);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer2->Size = System::Drawing::Size(749, 1037);
			this->splitContainer2->SplitterDistance = 623;
			this->splitContainer2->SplitterWidth = 5;
			this->splitContainer2->TabIndex = 0;
			// 
			// splitContainer3
			// 
			this->splitContainer3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->chart2);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->chart1);
			this->splitContainer3->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer3_Panel2_Paint);
			this->splitContainer3->Size = System::Drawing::Size(749, 623);
			this->splitContainer3->SplitterDistance = 300;
			this->splitContainer3->TabIndex = 0;
			// 
			// chart2
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea1);
			this->chart2->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart2->Legends->Add(legend1);
			this->chart2->Location = System::Drawing::Point(0, 0);
			this->chart2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart2->Name = L"chart2";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart2->Series->Add(series1);
			this->chart2->Size = System::Drawing::Size(747, 298);
			this->chart2->TabIndex = 0;
			this->chart2->Text = L"chart2";
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			series2->YValuesPerPoint = 4;
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(747, 317);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(747, 407);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chart3);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(739, 378);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Volumn";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			this->chart3->Dock = System::Windows::Forms::DockStyle::Fill;
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(3, 3);
			this->chart3->Name = L"chart3";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart3->Series->Add(series3);
			this->chart3->Size = System::Drawing::Size(733, 372);
			this->chart3->TabIndex = 0;
			this->chart3->Text = L"chart3";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->chart4);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(737, 378);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"MACD";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// chart4
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea4);
			this->chart4->Dock = System::Windows::Forms::DockStyle::Fill;
			legend4->Name = L"Legend1";
			this->chart4->Legends->Add(legend4);
			this->chart4->Location = System::Drawing::Point(3, 3);
			this->chart4->Name = L"chart4";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chart4->Series->Add(series4);
			this->chart4->Size = System::Drawing::Size(731, 372);
			this->chart4->TabIndex = 0;
			this->chart4->Text = L"chart4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(435, 416);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Short Position";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(438, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Long Position";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->richTextBox3);
			this->panel5->Location = System::Drawing::Point(417, 439);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(174, 239);
			this->panel5->TabIndex = 5;
			// 
			// richTextBox3
			// 
			this->richTextBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->richTextBox3->Location = System::Drawing::Point(0, 0);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(174, 239);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->richTextBox2);
			this->panel4->Location = System::Drawing::Point(417, 106);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(174, 257);
			this->panel4->TabIndex = 4;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->richTextBox2->Location = System::Drawing::Point(0, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(174, 257);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->richTextBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 779);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(554, 256);
			this->panel3->TabIndex = 3;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(554, 256);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(24, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Location = System::Drawing::Point(50, 482);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(332, 76);
			this->panel2->TabIndex = 1;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(263, 21);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(55, 31);
			this->button5->TabIndex = 2;
			this->button5->Text = L"OK";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(14, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Strategies:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Manual", L"Strategy 1", L"Strategy 2" });
			this->comboBox1->Location = System::Drawing::Point(136, 25);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Manual";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(29, 106);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(368, 348);
			this->panel1->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(3, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 36);
			this->label6->TabIndex = 4;
			this->label6->Text = L"label6";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(3, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 36);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(180, 238);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(115, 62);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Sell to Close";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(180, 172);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 62);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Sell";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(53, 238);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 62);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Buy to Cover";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(53, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Buy";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1310, 1037);
			this->Controls->Add(this->splitContainer1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Trading Platform by Y.S.L";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

		void updateTime(void) {
			time_t t = time(0);   // get time now
			tm* now = localtime(&t);

			String^ currentDateTime = gcnew String(
				(1900 + now->tm_year) + "-" + (1 + now->tm_mon) + "-" + now->tm_mday + " " + now->tm_hour + ":" + now->tm_min + ":" + now->tm_sec
			);
			this->label2->Text = (currentDateTime);
		}

		void addLog(String^ text) {
			time_t t = time(0);
			tm* now = localtime(&t);
			String^ log = gcnew String(
				"[" +
				(1900 + now->tm_year) + "-" +
				(1 + now->tm_mon) + "-" +
				now->tm_mday + " " +
				now->tm_hour + ":" +
				now->tm_min + ":" +
				now->tm_sec + "] " + text
			) ;
			this->richTextBox1->AppendText(log);
		}

		void updatePosition(void) {
			this->richTextBox2->Clear();
			for (int i = 0; i < candle_data.buy_price.Dataset.size(); i++) {
				String^ p = gcnew String("[" + (i + 1).ToString() + "] " + (candle_data.buy_price.Dataset[i]).ToString() + "\n");
				this->richTextBox2->AppendText(p);
			}
			this->richTextBox3->Clear();

			for (int i = 0; i < candle_data.sell_price.Dataset.size(); i++) {
				String^ p = gcnew String("[" + (i + 1).ToString() + "] " + (candle_data.sell_price.Dataset[i]).ToString() + "\n");
				this->richTextBox3->AppendText(p);
			}
		}

		// strategy
		void strategy_1(void) {
			bool execute = true;
			if (candle_data.buy_price.Dataset.size() > 0) {
				execute = false;
				for (std::deque<float>::iterator it = candle_data.buy_price.Dataset.begin(); it != candle_data.buy_price.Dataset.end(); ++it) {
					if ((((candle_data.close.back() - *it) / *it) < -0.0002) || (((candle_data.close.back() - *it) / *it) > 0.0002)) {
						execute = true;
					}
				}
				if (execute) {
					// sell to close
					if (candle_data.buy_price.Dataset.size() > 0) {
						float ret = 0;
						for (std::deque<float>::iterator it = candle_data.buy_price.Dataset.begin(); it != candle_data.buy_price.Dataset.end(); ++it)
							ret += (candle_data.close.back() - *it);
						candle_data.buy_price.Dataset.clear();
						candle_data.balance += ret;
						addLog(("[Strategy 1] Execute sell to close! Return: " + (ret * 50) + ".\n"));
					}
					else {
						addLog(("[Strategy 1] No execution performed. No buy position.\n"));
					}
					updatePosition();
				}
			}
			else if (candle_data.high.size() >= 3) {
				// check condition
				for (int i = 1; i < 3; i++) {
					if (candle_data.high[candle_data.high.size() - i] < candle_data.high[candle_data.high.size() - (i + 1)]) {
						execute = false;
						break;
					}
				}

				// execute
				if (execute) {
					// buy
					if (candle_data.sell_price.Dataset.size() > 0) {
						float ret = (candle_data.sell_price.Dataset.front() - candle_data.close.back());
						candle_data.sell_price.Dataset.pop_front();
						candle_data.balance += ret;
						addLog(("[Strategy 1] Execute buy to cover sell position! Return: " + (ret * 50) + ".\n"));
					}
					else {
						candle_data.buy_price.Dataset.push_back(candle_data.close.back());
						addLog(("[Strategy 1] Buy price " + candle_data.close.back() + "!\n"));
					}
					updatePosition();
				}

			}
		}

		void strategy_2(void) {
			bool execute = true;
			if (candle_data.sell_price.Dataset.size() > 0) {
				execute = false;
				for (std::deque<float>::iterator it = candle_data.sell_price.Dataset.begin(); it != candle_data.sell_price.Dataset.end(); it++) {
					if ((((*it - candle_data.sell_price.Dataset.back()) / *it) < -0.0005) || (((*it - candle_data.sell_price.Dataset.back()) / *it) > 0.0005)) {
						execute = true;
					}
				}
				if (execute) {
					if (candle_data.sell_price.Dataset.size() > 0) {
						float ret = 0;
						for (std::deque<float>::iterator it = candle_data.sell_price.Dataset.begin(); it != candle_data.sell_price.Dataset.end(); it++)
							ret += (*it - candle_data.sell_price.Dataset.back());
						candle_data.sell_price.Dataset.clear();
						candle_data.balance += ret;
						addLog(("[Strategy 2] Execute buy to cover! Return: " + (ret * 50) + ".\n"));
					}
					else {
						addLog(("[Strategy 2] No execution performed. No sell position.\n"));
					}
					updatePosition();
				}
			}
			else if (candle_data.delta_C_O.size() >= 3) {
				if ((candle_data.delta_C_O[candle_data.delta_C_O.size() - 1] + candle_data.delta_C_O[candle_data.delta_C_O.size() - 2] + candle_data.delta_C_O[candle_data.delta_C_O.size() - 3]) != -3) {
					execute = false;
				}

				if (execute) {
					if (candle_data.buy_price.Dataset.size() > 0) {
						float ret = candle_data.close.back() - candle_data.buy_price.Dataset.front();
						candle_data.buy_price.Dataset.pop_front();
						candle_data.balance += (ret);
						addLog(("[Strategy 2] Execute buy to cover! Return: " + (ret * 50) + ".\n"));
					}
					else {
						candle_data.sell_price.Dataset.push_back(candle_data.close.back());
						addLog(("[Strategy 2] Sell price" + candle_data.close.back() + "!\n"));
					}
					updatePosition();
				}
			}
		}

		float findMaxValue(const std::deque<float>& values) {
			float maxValue = values.front();  // Assume the first element is the maximum

			// Iterate over the deque starting from the second element
			for (auto it = std::next(values.begin()); it != values.end(); ++it) {
				if (*it > maxValue) {
					maxValue = *it;  // Update the maximum value
				}
			}

			return maxValue;
		}
		float findMinValue(const std::deque<float>& values) {
			float minValue = values.front();  // Assume the first element is the minimum

			// Iterate over the deque starting from the second element
			for (auto it = std::next(values.begin()); it != values.end(); ++it) {
				if (*it < minValue) {
					minValue = *it;  // Update the minimum value
				}
			}

			return minValue;
		}

		void plot_candlestick(void) {
			this->chart1->Series->Clear();
			this->chart1->Series->Add("CandleStick");
			this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;

			this->chart1->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;

			this->chart1->ChartAreas["ChartArea1"]->AxisY->Minimum = (int)findMinValue(candle_data.low)-2;
			this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.high)+2;
			this->chart1->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false; 

			this->chart1->Series["CandleStick"]->XValueMember = "Minute";
			this->chart1->Series["CandleStick"]->YValueMembers = "High,Low,Open,Close";
			this->chart1->Series["CandleStick"]->CustomProperties="PriceUpColor=Red,PriceDownColor=Green";
			this->chart1->Series["CandleStick"]->Color = Color::Black;
			this->chart1->Series["CandleStick"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;

			for (int i = 0; i < candle_data.high.size(); i++) {
				//this->chart1->Series["CandleStick"]->Points->AddXY(i, candle_data.data[i][0], candle_data.data[i][1], candle_data.data[i][2], candle_data.data[i][3]);
				this->chart1->Series["CandleStick"]->Points->AddXY(i, candle_data.high[i], candle_data.low[i], candle_data.open[i], candle_data.close[i]);
			}

			this->chart1->Series->Add("3MA");
			this->chart1->Series["3MA"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart1->Series["3MA"]->Color = Color::Pink;
			this->chart1->Series["3MA"]->BorderWidth= 3;
			for (int i = 0; i < candle_data.ma3_arr.size(); i++) {
				this->chart1->Series["3MA"]->Points->AddXY(i, candle_data.ma3_arr[i]);
			}

			this->chart1->Series->Add("5MA");
			this->chart1->Series["5MA"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart1->Series["5MA"]->Color = Color::Yellow;
			this->chart1->Series["5MA"]->BorderWidth = 3;
			for (int i = 0; i < candle_data.ma5_arr.size(); i++) {
				this->chart1->Series["5MA"]->Points->AddXY(i, candle_data.ma5_arr[i]);
			}

			this->chart1->Series->Add("20MA");
			this->chart1->Series["20MA"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart1->Series["20MA"]->Color = Color::BlueViolet;
			this->chart1->Series["20MA"]->BorderWidth = 3;
			for (int i = 0; i < candle_data.ma20_arr.size(); i++) {
				this->chart1->Series["20MA"]->Points->AddXY(i, candle_data.ma20_arr[i]);
			}

			//SK Return & information
			this->chart2->Series->Clear();
			this->chart2->Series->Add("Return");
			this->chart2->Series["Return"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart2->Series["Return"]->Color = Color::CornflowerBlue;
			this->chart2->Series["Return"]->BorderWidth = 3;
			this->chart2->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;
			this->chart2->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false;
			this->chart2->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;
			this->chart2->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.Return_arr) + 5;

			for (int i = 0; i < candle_data.Return_arr.size(); i++) {
				this->chart2->Series["Return"]->Points->AddXY(i, candle_data.Return_arr[i]);
			}

			this->chart3->Series->Clear();
			this->chart3->Series->Add("Volume");
			this->chart3->Series["Volume"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
			this->chart3->Series["Volume"]->Color = Color::CornflowerBlue;
			this->chart3->Series["Volume"]->BorderWidth = 3;
			this->chart3->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;
			this->chart3->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false;
			this->chart3->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;
			this->chart3->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.Volume_arr) + 2;
			for (int i = 0; i < candle_data.Volume_arr.size(); i++) {
				this->chart3->Series["Volume"]->Points->AddXY(i, candle_data.Volume_arr[i]);
			}

			this->chart4->Series->Clear();
			this->chart4->Series->Add("3EMA");
			this->chart4->Series["3EMA"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart4->Series["3EMA"]->Color = Color::CornflowerBlue;
			this->chart4->Series["3EMA"]->BorderWidth = 3;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;
			if (candle_data.ema12_arr.size() != 0) {
				this->chart4->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.ema12_arr) + 2;
			}
			
			for (int i = 0; i < candle_data.ema12_arr.size(); i++) {
				this->chart4->Series["3EMA"]->Points->AddXY(i, candle_data.ema12_arr[i]);
			}


			this->chart4->Series->Add("5EMA");
			this->chart4->Series["5EMA"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			this->chart4->Series["5EMA"]->Color = Color::Red;
			this->chart4->Series["5EMA"]->BorderWidth = 3;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;
			if (candle_data.ema26_arr.size() != 0) {
				this->chart4->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.ema26_arr) + 2;
			}
			
			for (int i = 0; i < candle_data.ema26_arr.size(); i++) {
				this->chart4->Series["5EMA"]->Points->AddXY(i, candle_data.ema26_arr[i]);
			}

			
			this->chart4->Series->Add("MACD");
			this->chart4->Series["MACD"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
			this->chart4->Series["MACD"]->BorderWidth = 3;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->MajorGrid->LineWidth = 0;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->LabelStyle->Enabled = false;
			this->chart4->ChartAreas["ChartArea1"]->AxisX->Maximum = MAX_ROW;
			if (candle_data.MACD_bar_arr.size() != 0) {
				this->chart4->ChartAreas["ChartArea1"]->AxisY->Maximum = (int)findMaxValue(candle_data.MACD_bar_arr) + 2;
			}
			
			for (int i = 0; i < candle_data.MACD_bar_arr.size(); i++) {
				if (candle_data.MACD_bar_arr[i] > 0)
				{
					this->chart4->Series["MACD"]->Color = Color::Red;
					this->chart4->Series["MACD"]->Points->AddXY(i, candle_data.MACD_bar_arr[i]);
				}
				else
				{
					this->chart4->Series["MACD"]->Color = Color::Green;
					this->chart4->Series["MACD"]->Points->AddXY(i, candle_data.MACD_bar_arr[i]);
				}

			}
			
		}

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		time_t t = time(0);   // get time now
		tm* now = localtime(&t);
		cur_min = now->tm_min;
		prev_min = now->tm_min;
		// test
		/*plot_candlestick();
		update_candlestick(cs_ptr);*/		

	}
	private: System::Void splitContainer3_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// update time
		time_t t = time(0);   // get time now
		tm* now = localtime(&t);
		cur_min = now->tm_min;
		
		plot_candlestick();
		update_candlestick(cs_ptr);
		float ret = cal_return(candle_data);

		String^ ret_str = (ret*50).ToString(); //gcnew String(ret);
		this->label3->Text = ("Current return: \n NTD "+ret_str);

		String^ price_str = (candle_data.close.back()).ToString(); //gcnew String(ret);
		this->label6->Text = (price_str);

		// strategies
		if (st1 == true) {
			strategy_1();
		}
		if (st2 == true) {
			strategy_2();
		}
		
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		updateTime();
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// buy
		if (candle_data.sell_price.Dataset.size() > 0) {
			float ret = (candle_data.sell_price.Dataset.front() - candle_data.close.back());
			candle_data.sell_price.Dataset.pop_front();
			candle_data.balance += ret;
			addLog(("Execute buy to cover sell position! Return: " + (ret * 50) + ".\n"));
		}
		else {
			candle_data.buy_price.Dataset.push_back(candle_data.close.back());
			addLog(("Buy price " + candle_data.close.back() + "!\n"));
		}
		updatePosition();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// sell
		if (candle_data.buy_price.Dataset.size() > 0) {
			float ret = candle_data.close.back() - candle_data.buy_price.Dataset.front();
			candle_data.buy_price.Dataset.pop_front();
			candle_data.balance += ret;
			addLog(("Execute sell to close buy position! Return: " + (ret * 50) + ".\n"));
		}
		else {
			candle_data.sell_price.Dataset.push_back(candle_data.close.back());
			addLog(("Sell price " + candle_data.close.back() + "!\n"));
		}
		updatePosition();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// buy to cover
		if (candle_data.sell_price.Dataset.size() > 0) {
			float ret = 0;
			for (std::deque<float>::iterator it = candle_data.sell_price.Dataset.begin(); it != candle_data.sell_price.Dataset.end(); ++it)
				ret += (*it - candle_data.close.back());
			candle_data.sell_price.Dataset.clear();
			candle_data.balance += ret;
			addLog(("Execute buy to cover! Return: " + (ret * 50) + ".\n"));
		}
		else {
			addLog(("No execution performed. No sell position.\n"));
		}
		updatePosition();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		// sell to close
		if (candle_data.buy_price.Dataset.size() > 0) {
			float ret = 0;
			for (std::deque<float>::iterator it = candle_data.buy_price.Dataset.begin(); it != candle_data.buy_price.Dataset.end(); ++it)
				ret += (candle_data.close.back() - *it);
			candle_data.buy_price.Dataset.clear();
			candle_data.balance += ret;
			addLog(("Execute sell to close! Return: " + (ret * 50) + ".\n"));
		}
		else {
			addLog(("No execution performed. No buy position.\n"));
		}
		updatePosition();
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->Text == "Strategy 1") {
			st1 = true;
			st2 = false;
			man_st = false;
			this->richTextBox1->AppendText("Strategy 1 selected!\n");
		}
		else if (this->comboBox1->Text == "Strategy 2") {
			st2 = true;
			st1 = false;
			man_st = false;
			this->richTextBox1->AppendText("Strategy 2 selected!\n");
		}
		else if (this->comboBox1->Text == "Manual") {
			man_st = true;
			st1 = false;
			st2 = false;
			this->richTextBox1->AppendText("Auto-trading off!\n");
		}
	}
};
}
