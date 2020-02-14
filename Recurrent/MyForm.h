#pragma once
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cmath>
#include<ctime>
#include<vector>

#include"Pattern.h"
#include<sstream>
#include<fstream>
#include<atlstr.h>
#include<Windows.h>
namespace RNN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	int InputSize,OutputSize,inputindex,patterncount=0,entrycount=0;
	Pattern* pat;
	std::string path = "C:\\Users\\asus\\Desktop\\DataSet\\";
	std::vector<Pattern*> models;
	float** Weights;
	float** test_data;
	std::vector<float**> test_Datas;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox2;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ dataSetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ loadWeightMatrixToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveWeightMatrixToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label9;

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dataSetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadWeightMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveWeightMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Red;
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(13, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(258, 146);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Input Declaration";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Input Size:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(92, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(92, 90);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Seç";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Yellow;
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(347, 45);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(272, 146);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"I/O Load File";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(28, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 32);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Load";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(166, 28);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 34);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Training";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 96);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Pattern Count:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(948, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(948, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(948, 141);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 5;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(18, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(89, 53);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Test Data Load";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->numericUpDown2);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Location = System::Drawing::Point(347, 208);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(272, 187);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Load Test Datas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(131, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 17);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Test File Index";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(18, 127);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 34);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Test";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(134, 105);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(116, 22);
			this->numericUpDown2->TabIndex = 8;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dataSetToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1163, 28);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dataSetToolStripMenuItem
			// 
			this->dataSetToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadWeightMatrixToolStripMenuItem,
					this->saveWeightMatrixToolStripMenuItem
			});
			this->dataSetToolStripMenuItem->Name = L"dataSetToolStripMenuItem";
			this->dataSetToolStripMenuItem->Size = System::Drawing::Size(76, 24);
			this->dataSetToolStripMenuItem->Text = L"DataSet";
			// 
			// loadWeightMatrixToolStripMenuItem
			// 
			this->loadWeightMatrixToolStripMenuItem->Name = L"loadWeightMatrixToolStripMenuItem";
			this->loadWeightMatrixToolStripMenuItem->Size = System::Drawing::Size(222, 26);
			this->loadWeightMatrixToolStripMenuItem->Text = L"Load Weight Matrix";
			this->loadWeightMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadWeightMatrixToolStripMenuItem_Click);
			// 
			// saveWeightMatrixToolStripMenuItem
			// 
			this->saveWeightMatrixToolStripMenuItem->Name = L"saveWeightMatrixToolStripMenuItem";
			this->saveWeightMatrixToolStripMenuItem->Size = System::Drawing::Size(222, 26);
			this->saveWeightMatrixToolStripMenuItem->Text = L"Save Weight Matrix";
			this->saveWeightMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveWeightMatrixToolStripMenuItem_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->textBox3);
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Location = System::Drawing::Point(13, 226);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(302, 169);
			this->groupBox4->TabIndex = 10;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"I/O Entry";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 125);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 17);
			this->label9->TabIndex = 5;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(150, 120);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 23);
			this->button6->TabIndex = 4;
			this->button6->Text = L"Load";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 79);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 17);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Output Array";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 30);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 17);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Input Array";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(99, 74);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(157, 22);
			this->textBox3->TabIndex = 1;
			this->textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox3_KeyDown);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(157, 22);
			this->textBox2->TabIndex = 0;
			this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyDown);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1163, 497);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		float sgn_activation_function(float net)
		{
			if (net > 0)
				return 1.0f;
			else if (net <= 0)
				return -1.0f;
			
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		InputSize = System::Convert::ToInt32(textBox1->Text->ToString());
		OutputSize = InputSize;
		Weights = new float*[InputSize];
		for (int i = 0; i < OutputSize; i++)
		{
			Weights[i] = new float[OutputSize];
		}
		for (int row = 0; row < InputSize; row++)
		{
			for (int col = 0; col < OutputSize; col++)
			{
				Weights[row][col] = 0.0f;
			}
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	pat = new Pattern(InputSize);
	
	std::ifstream dosya;
	int row = 0, col = 0, pos, startpos = 0;
	std::string line;
	String^ vs;

	char discrim = ' ';
	CString s;
	LPCTSTR input;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog1->FileName;
		input = (LPCTSTR)s;
		dosya.open(input, std::ios::in);
		while (!dosya.eof())
		{
			getline(dosya, line);//tum satýrý okuyor
			pos = line.find(discrim);
			while (pos != std::string::npos)
			{
				if (row == 1)
				{
					pat->setOutputElem(col, atof(line.substr(startpos, pos - startpos).c_str()));//output elem setle 0 da input elem setle
				}
				else
				{
					pat->setInputElem(col, atof(line.substr(startpos, pos - startpos).c_str()));
				}
				
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;

			}
			row++;
			startpos = 0;
			pos = 0;
			col = 0;
		}
		dosya.close();
	}
	models.push_back(pat);
	patterncount++; label5->Text = "Pattern Count:"+patterncount.ToString(); label5->Refresh();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < models.size(); i++)
	{
		for (int row = 0; row < InputSize; row++)
		{
			for (int col = 0; col < OutputSize; col++)
			{
				Weights[row][col] += (models[i]->getOutputElem(row) * models[i]->getInputElem(col));
			}
		}
	}//eðitim yeri
	for (int k = 0; k < InputSize; k++)
	{
		for (int j = 0; j < OutputSize; j++)
		{
			if (k == j)
				Weights[k][j] -= models.size();	
			
		}
	}//recurrent lýgý saðlayan kýsým -pI

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream dosya;
	int row = 0, col = 0, pos, startpos = 0;
	test_data = new float* [InputSize];
	for (int i = 0; i < InputSize; i++)
	{
		test_data[i] = new float[1];
	}
	std::string line;
	String^ vs;

	char discrim = ' ';
	CString s;
	LPCTSTR input;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog1->FileName;
		input = (LPCTSTR)s;
		dosya.open(input, std::ios::in);
		while (!dosya.eof())
		{
			getline(dosya, line);//tum satýrý okuyor
			pos = line.find(discrim);
			while (pos != std::string::npos)
			{
				test_data[col][0] = atof(line.substr(startpos, pos - startpos).c_str());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;
			}
			row++;
			startpos = 0;
			pos = 0;
			col = 0;
		}
		dosya.close();
	}
	test_Datas.push_back(test_data);
}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		int test_index = (int)System::Convert::ToInt32(numericUpDown2->Text)-1;
		int count = 0;
		Int32 result,num = 0;
		FLOAT** test_outputone = new FLOAT* [InputSize];
		FLOAT** test_outputtwo = new FLOAT* [InputSize];
		for (int i = 0; i < InputSize; i++)
		{
			test_outputone[i] = new FLOAT[1];
			test_outputtwo[i] = new FLOAT[1];
		}
		for (int i = 0; i < InputSize; i++)
		{
			test_outputone[i][0] = 0.0f;
			test_outputtwo[i][0] = 0.0f;
		}
		/*for (int k = 0; k < InputSize; k++)
		{
			test_outputone[k][0] = test_Datas[test_index][k][0];
			//MessageBox::Show(test_Datas[test_index][k][0].ToString());
		}*/
		for (int row = 0; row < InputSize; row++)
		{
			for (int col = 0; col < 1; col++)
			{
				for (int k = 0; k < InputSize; k++)
				{
					test_outputone[row][col] += Weights[row][k] * test_Datas[test_index][k][col];
				}
				test_outputone[row][col] = sgn_activation_function(test_Datas[test_index][row][col]);
			}
		}
		while (true)
		{
			for (int row = 0; row < InputSize; row++)
			{
				for (int col = 0; col < 1; col++)
				{
					for (int k = 0; k < InputSize; k++)
					{
						test_outputtwo[row][col] += Weights[row][k] * test_outputone[k][col];
					}
					test_outputtwo[row][col] = sgn_activation_function(test_outputtwo[row][col]);
				}
			}
			for (int j = 0; j <InputSize; j++)
			{
				if (test_outputone[j][0] == test_outputtwo[j][0])
					count++;
			}
			if(count == InputSize)
			{
				for (int i = 0; i < InputSize; i++)
				{
					label6->Text += test_outputtwo[i][0]+ " ";
				}
				break;
			}
			else
			{
				for (int i = 0; i < InputSize; i++)
				{
					test_outputone[i][0] = test_outputtwo[i][0];
					test_outputtwo[i][0] = 0.0f;
				}
				num++;
				count = 0;
				label3->Text = "Cycle :" + num.ToString();
				label3->Refresh();
			}
			
			
		}

}
private: System::Void saveWeightMatrixToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream dosya;
	dosya.open(path + "RNN_Weights.txt");
	for (int i = 0; i < InputSize; i++)
	{
		for (int j = 0; j < InputSize; j++)
		{
			dosya << Weights[i][j] << ' ';
		}
		dosya << std::endl;
	}
	dosya.close();
	MessageBox::Show("Aðýrlýklar Dosyaya Yazýldý");
	
}
private: System::Void loadWeightMatrixToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::ifstream dosya;
	int row = 0, col = 0, pos, startpos = 0;
	std::string line;
	String^ vs;

	char discrim = ' ';
	CString s;
	LPCTSTR input;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog1->FileName;
		input = (LPCTSTR)s;
		dosya.open(input, std::ios::in);
		while (!dosya.eof())
		{
			getline(dosya, line);//tum satýrý okuyor
			pos = line.find(discrim);
			while (pos != std::string::npos)
			{
				Weights[row][col] = (float)atof(line.substr(startpos, pos - startpos).c_str());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;
			}
			row++;
			startpos = 0;
			pos = 0;
			col = 0;
		}
		dosya.close();
		/*for (int i = 0; i < clscount; i++)
		{
			for (int j = 0; j < HiddenNeuron + 1; j++)
			{
				vs += Weights[i][j].ToString();
				vs += "\t";
			}
			vs += "\n";
		}
		MessageBox::Show(vs);
		vs = "";
		*/
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	
	/*LPCTSTR input;

	std::string s;

#ifdef UNICODE
	std::wstring w;
	w = input;
	s = std::string(w.begin(), w.end()); // magic here
#else
	s = input
	*/
	
	pat = new Pattern(InputSize);
	int pos, startpos = 0, col = 0;
	char discrim = ' ';
	std::wstring in_warray = (LPCTSTR)(CString)textBox2->Text->ToString();
	std::wstring out_warray = (LPCTSTR)(CString)textBox3->Text->ToString();

	std::string inarray = std::string(in_warray.begin(), in_warray.end());
	std::string outarray = std::string(out_warray.begin(), out_warray.end());
	
	pos = inarray.find(discrim);
	while (pos != std::string::npos)
	{
		pat->setInputElem(col,atof(inarray.substr(startpos, pos - startpos).c_str()));
		startpos = pos + 1;
		pos = inarray.find(discrim, startpos);
		col++;
	}
	col = 0;
	startpos = 0;
	pos = outarray.find(discrim);
	while (pos != std::string::npos)
	{
		pat->setOutputElem(col,atof(outarray.substr(startpos, pos - startpos).c_str()));
		startpos = pos + 1;
		pos = outarray.find(discrim, startpos);
		col++;
	}
	models.push_back(pat);
	textBox3->Clear();
	textBox2->Clear();
	entrycount++; label9->Text = "Pattern Count:" + entrycount.ToString(); label9->Refresh();
}
private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
	{
		textBox3->Focus();
	}
}
private: System::Void textBox3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
	{
		pat = new Pattern(InputSize);
		int pos, startpos = 0, col = 0;
		char discrim = ' ';
		std::wstring in_warray = (LPCTSTR)(CString)textBox2->Text->ToString();
		std::wstring out_warray = (LPCTSTR)(CString)textBox3->Text->ToString();

		std::string inarray = std::string(in_warray.begin(), in_warray.end());
		std::string outarray = std::string(out_warray.begin(), out_warray.end());

		pos = inarray.find(discrim);
		while (pos != std::string::npos)
		{
			pat->setInputElem(col, (float)atof(inarray.substr(startpos, pos - startpos).c_str()));
			startpos = pos + 1;
			pos = inarray.find(discrim, startpos);
			col++;
		}
		col = 0;
		startpos = 0;
		pos = outarray.find(discrim);
		while (pos != std::string::npos)
		{
			pat->setOutputElem(col, (float)atof(outarray.substr(startpos, pos - startpos).c_str()));
			startpos = pos + 1;
			pos = outarray.find(discrim, startpos);
			col++;
		}
		models.push_back(pat);
		textBox3->Clear();
		textBox2->Clear();
		entrycount++; label9->Text = "Pattern Count:" + entrycount.ToString(); label9->Refresh();
		textBox2->Focus();
	}

}
};
}
