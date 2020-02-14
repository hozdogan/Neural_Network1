#pragma once
#include <vector>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include "neural_network.h"
#include <time.h>
#include<cstdlib>
#include<string>
#include<sstream>
#include<fstream>
#include<atlstr.h>
#include<Windows.h>

namespace ysaproje3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	int clscount,HiddenNeuron;
	std::vector<Renk> colorvec;
	Pattern2D* pat;
	Perceptron ptron;
	std::vector<Pattern2D*> vec;
	
	int** Surface;
	float LC1 = 0.5f,LC2 = 0.6f;
	float net, hata = 0, fnet, signalhl, norm, x, y, sumX = 0, sumY = 0, ortX, ortY, SSX, SSY, temphl, signalol, tempol, errorsum = 0, alfa1 = 0.8, alfa2 = 0.9;
	float** Weights;
	float** Veights;
	bool normalize = false;
	int cycle = 0, step = 0, counttrue = 0, hatacount = 0;
	std::string path = "C:\\Users\\asus\\source\\repos\\ysaproje3\\";

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			setHiddenNeuon();
			setClassCount();
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ weightsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manuallyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getDatasetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getWeightsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showAreaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showSamplesToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox5;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ setWeightsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setDatasetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setWeightsToolStripMenuItem1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ withMomentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ normalTrainingToolStripMenuItem;
	private: System::Windows::Forms::Label^ label7;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->weightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manuallyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getDatasetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->withMomentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normalTrainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showAreaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showSamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setDatasetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setWeightsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(46, 78);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1503, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->weightsToolStripMenuItem,
					this->trainingToolStripMenuItem, this->testToolStripMenuItem, this->setWeightsToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// weightsToolStripMenuItem
			// 
			this->weightsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->manuallyToolStripMenuItem,
					this->randomlyToolStripMenuItem
			});
			this->weightsToolStripMenuItem->Name = L"weightsToolStripMenuItem";
			this->weightsToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->weightsToolStripMenuItem->Text = L"Weights";
			// 
			// manuallyToolStripMenuItem
			// 
			this->manuallyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->getDatasetToolStripMenuItem,
					this->getWeightsToolStripMenuItem
			});
			this->manuallyToolStripMenuItem->Name = L"manuallyToolStripMenuItem";
			this->manuallyToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->manuallyToolStripMenuItem->Text = L"Manually";
			// 
			// getDatasetToolStripMenuItem
			// 
			this->getDatasetToolStripMenuItem->Name = L"getDatasetToolStripMenuItem";
			this->getDatasetToolStripMenuItem->Size = System::Drawing::Size(168, 26);
			this->getDatasetToolStripMenuItem->Text = L"GetDataset";
			this->getDatasetToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::getDatasetToolStripMenuItem_Click);
			// 
			// getWeightsToolStripMenuItem
			// 
			this->getWeightsToolStripMenuItem->Name = L"getWeightsToolStripMenuItem";
			this->getWeightsToolStripMenuItem->Size = System::Drawing::Size(168, 26);
			this->getWeightsToolStripMenuItem->Text = L"GetWeights";
			this->getWeightsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::getWeightsToolStripMenuItem_Click);
			// 
			// randomlyToolStripMenuItem
			// 
			this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			this->randomlyToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->randomlyToolStripMenuItem->Text = L"Randomly";
			this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomlyToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->withMomentToolStripMenuItem,
					this->normalTrainingToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// withMomentToolStripMenuItem
			// 
			this->withMomentToolStripMenuItem->Name = L"withMomentToolStripMenuItem";
			this->withMomentToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->withMomentToolStripMenuItem->Text = L"With Moment";
			this->withMomentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::withMomentToolStripMenuItem_Click);
			// 
			// normalTrainingToolStripMenuItem
			// 
			this->normalTrainingToolStripMenuItem->Name = L"normalTrainingToolStripMenuItem";
			this->normalTrainingToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->normalTrainingToolStripMenuItem->Text = L"Normal Training";
			this->normalTrainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::normalTrainingToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->showAreaToolStripMenuItem,
					this->showSamplesToolStripMenuItem
			});
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->testToolStripMenuItem->Text = L"Test";
			// 
			// showAreaToolStripMenuItem
			// 
			this->showAreaToolStripMenuItem->Name = L"showAreaToolStripMenuItem";
			this->showAreaToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->showAreaToolStripMenuItem->Text = L"ShowArea";
			this->showAreaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showAreaToolStripMenuItem_Click);
			// 
			// showSamplesToolStripMenuItem
			// 
			this->showSamplesToolStripMenuItem->Name = L"showSamplesToolStripMenuItem";
			this->showSamplesToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->showSamplesToolStripMenuItem->Text = L"ShowSamples";
			this->showSamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showSamplesToolStripMenuItem_Click);
			// 
			// setWeightsToolStripMenuItem
			// 
			this->setWeightsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->setDatasetToolStripMenuItem,
					this->setWeightsToolStripMenuItem1
			});
			this->setWeightsToolStripMenuItem->Name = L"setWeightsToolStripMenuItem";
			this->setWeightsToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->setWeightsToolStripMenuItem->Text = L"SetWeights";
			// 
			// setDatasetToolStripMenuItem
			// 
			this->setDatasetToolStripMenuItem->Name = L"setDatasetToolStripMenuItem";
			this->setDatasetToolStripMenuItem->Size = System::Drawing::Size(166, 26);
			this->setDatasetToolStripMenuItem->Text = L"SetDataset";
			this->setDatasetToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::setDatasetToolStripMenuItem_Click);
			// 
			// setWeightsToolStripMenuItem1
			// 
			this->setWeightsToolStripMenuItem1->Name = L"setWeightsToolStripMenuItem1";
			this->setWeightsToolStripMenuItem1->Size = System::Drawing::Size(166, 26);
			this->setWeightsToolStripMenuItem1->Text = L"SetWeights";
			this->setWeightsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::setWeightsToolStripMenuItem1_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox2->Location = System::Drawing::Point(1347, 196);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 3;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(1347, 132);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(121, 24);
			this->comboBox5->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1241, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"ClassCount";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1242, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"ClassID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1242, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"HiddenNeuron";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1135, 315);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1135, 352);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1135, 395);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"label6";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1211, 294);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 38);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Normalize";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1347, 75);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 18;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1327, 294);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 38);
			this->button1->TabIndex = 19;
			this->button1->Text = L"SetMatrixBounds";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1135, 433);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 17);
			this->label7->TabIndex = 20;
			this->label7->Text = L"label7";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1503, 739);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void setHiddenNeuon()
		{
			Int32 i;
			comboBox2->ItemHeight = 10;
			for (i = 1; i <=10; i++)
			{
				String^ s = i.ToString();
				comboBox2->Items->Add(s);
			}
		}
		void setClassCount()
		{
			Renk r1(255, 0, 0);
			Renk r2(0, 0, 255);
			Renk r3(0, 255, 0);
			Renk r4(239, 163, 12);
			Renk r5(247, 10, 232);
			Renk r6(0, 0, 0);
			Renk r7(61, 105, 82);
			Renk r8(107, 65, 18);
			colorvec.push_back(r1);
			colorvec.push_back(r2);
			colorvec.push_back(r3);
			colorvec.push_back(r4);
			colorvec.push_back(r5);
			colorvec.push_back(r6);
			colorvec.push_back(r7);
			colorvec.push_back(r8);
			//classcount
			clscount = 8;
			comboBox5->ItemHeight = clscount;
			for (int i = 1; i <= clscount; i++)
			{
				String^ s = "Class" + i;
				comboBox5->Items->Add(s);
			}
			Int32 i;
			comboBox1->ItemHeight = 8;
			for (i = 1; i <= 8; i++)
			{
				String^ s = i.ToString();
				comboBox1->Items->Add(s);
			}
		}
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Pen^ pen;
		Graphics^ g = pictureBox1->CreateGraphics();
		int current = comboBox5->SelectedIndex;

		Color c = Color::FromArgb(colorvec[current].getRed(), colorvec[current].getGreen(), colorvec[current].getBlue());
		pen = gcnew Pen(c, 2);
		
		label4->Text = "x1: " + (e->X - pictureBox1->Width / 2).ToString();
		label5->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
		x = e->X-(pictureBox1->Width/2);
		y = (pictureBox1->Height / 2) - e->Y;

		pat = new Pattern2D(x, y);
		pat->setBias(1.0f);
		pat->setClassID(current);
		vec.push_back(pat);
		g->DrawLine(pen, e->X - 4, e->Y, e->X + 4, e->Y);
		g->DrawLine(pen, e->X, e->Y - 4, e->X, e->Y + 4);


	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
		label4->Text = "x1: " + (e->X - pictureBox1->Width/2).ToString();
		label5->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int* normX = new int[vec.size()];
		int* normY = new int[vec.size()];
		//pictureBox1->Refresh();
		normalize = true;
		Graphics^ g = pictureBox1->CreateGraphics();
		Pen^ pen;
		for (int i = 0; i < vec.size(); i++)
		{
			normX[i] = vec[i]->getX();
			normY[i] = vec[i]->getY();
			sumX += vec[i]->getX();
			sumY += vec[i]->getY();
		}
		ortX = sumX / vec.size(); ortY = sumY / vec.size();

		SSX = ptron.s_sapma(normX, vec.size());
		SSY = ptron.s_sapma(normY, vec.size());
		
		for (int j = 0; j < vec.size(); j++)
		{
			vec[j]->setnormX(((vec[j]->getX() - ortX) / SSX));
			vec[j]->setnormY(((vec[j]->getY() - ortY) / SSY));
		}



	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void setDatasetToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int** DataMatrix = new int* [vec.size()];
	for (int i = 0; i < vec.size(); i++)
	{
		DataMatrix[i] = new int[3];
	}
	for (int i = 0; i < vec.size(); i++)
	{
		DataMatrix[i][0] = vec[i]->getX();
		DataMatrix[i][1] = vec[i]->getY();
		DataMatrix[i][2] = vec[i]->getClassID();
	}
	std::ofstream dosya;
	dosya.open(path + "V_Dataset.txt");
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dosya << DataMatrix[i][j] << ' ';
		}
		dosya << std::endl;
	}
	dosya.close();
	MessageBox::Show("Matris dosyaya yazildi");
}
private: System::Void getDatasetToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->Refresh();
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	if (vec.size() > 0)
		vec.clear();
	float x, y,bias = 1.0f;
	int row = 0, col = 0, pos, startpos = 0,cid;
	std::ifstream dosya(path+"V_Dataset.txt", std::ios::in);
	std::string line;
	char discrim = ' ';
	Pattern2D* pat;
	while (!dosya.eof())
	{
		getline(dosya, line);//tum satýrý okuyor
		pos = line.find(discrim);
		while (pos != std::string::npos)
		{
			if (col == 0)
			{
				x = (float)atof(line.substr(startpos, pos - startpos).c_str());
			}
			else if (col == 1)
			{
				y = (float)atof(line.substr(startpos, pos - startpos).c_str());
			}
			else if (col == 2)//class id = 2
			{
				cid = (float)atof(line.substr(startpos, pos - startpos).c_str());
			}
			startpos = pos + 1;
			pos = line.find(discrim, startpos);
			col++;
		}
		pat = new Pattern2D(x, y);
		pat->setClassID(cid);
		pat->setBias(bias);
		vec.push_back(pat);
		startpos = 0;
		pos = 0;
		col = 0;
	}
	dosya.close();
	for (int j = 0; j < vec.size(); j++)
	{
		Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
		pen = gcnew Pen(c, 2);
		g->DrawLine(pen, (vec[j]->getX()) - 4 + 250, 250 - vec[j]->getY(), vec[j]->getX() + 254, 250 - (vec[j]->getY()));
		g->DrawLine(pen, (vec[j]->getX()) + 250, 250 - vec[j]->getY() - 4, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) + 4);
	}
	
	MessageBox::Show("DataSet Yüklendi");
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	HiddenNeuron = comboBox2->SelectedIndex+1;
	clscount = comboBox1->SelectedIndex+1;
	Veights = new float* [HiddenNeuron];
	for (int i = 0; i < HiddenNeuron; i++)
	{
		Veights[i] = new float[3];
	}
	Weights = new float* [clscount];
	for (int i = 0; i < clscount; i++)
	{
		Weights[i] = new float[HiddenNeuron + 1];
	}
}
private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));
	for (int i = 0; i < HiddenNeuron; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Veights[i][j] = (rand() % 10) / 10.0f + ((rand() % 10) / 100.0f);
		}
	}
	for (int i = 0; i < clscount; i++)
	{
		for (int j = 0; j < HiddenNeuron+1; j++)
		{
			Weights[i][j] = (rand() % 10) / 10.0f + ((rand() % 10) / 100.0f);
		}
	}
	
}
private: System::Void setWeightsToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream dosya;
	dosya.open(path + "W_Weights.txt");
	for (int i = 0; i < clscount; i++)
	{
		for (int j = 0; j < HiddenNeuron+1; j++)
		{
			dosya << Weights[i][j] << ' ';
		}
		dosya << std::endl;
	}
	dosya.close();
	MessageBox::Show("Çýkýþ Katmaný Aðýrlýklarý Dosyaya Yazýldý");
	dosya.open(path + "V_Weights.txt");
	for (int i = 0; i <HiddenNeuron; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dosya << Veights[i][j] << ' ';
		}
		dosya << std::endl;
	}
	dosya.close();
	MessageBox::Show("Ara Katman Aðýrlýklarý Dosyaya Yazýldý");
}
private: System::Void getWeightsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Çýkýþ Katmaný Aðýrlýklarýný Veriniz");
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
		row = 0;
		for (int i = 0; i < clscount; i++)
		{
			for (int j = 0; j < HiddenNeuron + 1; j++)
			{
				vs+=Weights[i][j].ToString();
				vs += "\t";
			}
			vs += "\n";
		}
		MessageBox::Show(vs);
		vs = "";
	}
	MessageBox::Show("Ara Katman Aðýrlýklarýný Veriniz");
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

				Veights[row][col] = (float)atof(line.substr(startpos, pos - startpos).c_str());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;
			}
			row++;
			startpos = 0;
			pos = 0;
			col = 0;
		}
		row = 0;
		dosya.close();
		for (int i = 0; i < HiddenNeuron; i++)
		{
			for (int j = 0; j < 3; j++)
			{ 
				vs += Veights[i][j].ToString();
				vs += "\t";
			}
			vs += "\n";
		}
		MessageBox::Show(vs);
	}
	
	
}
private: System::Void normalTrainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	float** hloa = new float* [HiddenNeuron + 1];
	float** oloa = new float* [clscount];
	float** VecX = new float*[3];
	float sumWeights = 0;
	float** desiredArr = new float* [clscount];
	
	for (int i = 0; i < clscount; i++)
	{
		desiredArr[i] = new float[1];
	}
	for (int i = 0; i < 3; i++)
	{
		VecX[i] = new float[1];
	}
	for (int i = 0; i < HiddenNeuron + 1; i++)
		{
			hloa[i] = new float[1];
		}
	for (int i = 0; i < clscount; i++)
	{
		oloa[i] = new float[1];
	}
	//0 lama dizileri
	for (int i = 0; i < 3; i++)
	{
		VecX[i][0] = 0.0f;
	}
	for (int i = 0; i < HiddenNeuron; i++)
	{
		hloa[i][0] = 0.0f;
	}
	hloa[HiddenNeuron][0] = 1.0f;//threshold;
	for (int i = 0; i < clscount; i++)
	{
		oloa[i][0] = 0.0f;
	}
	while (true)
	{
		for (int val = 0; val < vec.size(); val++)
		{
			
			if (normalize)
			{
				VecX[0][0] = vec[val]->getnormX();
				VecX[1][0] = vec[val]->getnormY();
				VecX[2][0] = vec[val]->getBias();
			}
			else
			{
				VecX[0][0] = vec[val]->getX();
				VecX[1][0] = vec[val]->getY();
				VecX[2][0] = vec[val]->getBias();
			}
			//beklenen vektor setleme
			for (int k = 0; k < clscount; k++)//scbak
			{
				if (vec[val]->getClassID() == k)
				{
					desiredArr[k][0] = 1.0f;
				}
				else if (vec[val]->getClassID() != k)
				{
					desiredArr[k][0] = -1.0f;
				}
			}

			for (int row = 0; row < HiddenNeuron; row++)//ara katman cýkýs y0 y1 y2
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < 3; op++)
					{
						hloa[row][col] += Veights[row][op] * VecX[op][col];
					}
					hloa[row][col] = ptron.bipolar_sigmoid_function(hloa[row][col]);
				}
			}

			for (int row = 0; row < clscount; row++)//cýkýs katman setlemesi o1 o2 o3
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < HiddenNeuron + 1; op++)
					{
						oloa[row][col] += Weights[row][op] * hloa[op][col];
					}
					oloa[row][col] = ptron.bipolar_sigmoid_function(oloa[row][col]);
				}
			}

			
			//deltaWeight guncelle
			for (int k = 0; k < clscount; k++)//scbak 3x5
			{
				signalol = LC1 * (desiredArr[k][0] - oloa[k][0]) * ptron.bipolar_sigmoid_function_derive(oloa[k][0]);
				hata += (desiredArr[k][0] - oloa[k][0])* (desiredArr[k][0] - oloa[k][0]);
				for (int j = 0; j < HiddenNeuron + 1; j++)
				{
					
					Weights[k][j] += signalol* hloa[j][0];//sorun cýkarsa bak
				}
			}
			errorsum += hata;
			hata = 0;
			//Hidden Layer Guncelle
			for (int j = 0; j < HiddenNeuron; j++)//4x3
			{
				for (int i = 0; i < 3; i++)
				{
					for (int k = 0; k < clscount; k++)
					{
						sumWeights += (desiredArr[k][0] - oloa[k][0])*ptron.bipolar_sigmoid_function_derive(oloa[k][0])*Weights[k][j];
					}
					Veights[j][i] += LC2 * ptron.bipolar_sigmoid_function_derive(hloa[j][0]) * VecX[i][0] * sumWeights;
					sumWeights = 0;
				}
			}

			for (int i = 0; i < HiddenNeuron; i++)
			{
				hloa[i][0] = 0.0f;
			}
			for (int j = 0; j < clscount; j++)
			{
				oloa[j][0] = 0.0f;
			}

		}
		errorsum = sqrt(errorsum) / (clscount * vec.size());
		if (errorsum < 0.01)
			break;
		label5->Text = "Hata: " + errorsum.ToString();
		label5->Refresh();
		errorsum = 0;
		cycle++;

	}
	label6->Text = "Cycle: " + cycle.ToString();
	label7->Text = "Hata: " + errorsum.ToString();
	hata = 0;
	errorsum = 0;
	cycle = 0;
	delete[] hloa;
	delete[] oloa;
	delete[] VecX;
}
private: System::Void showAreaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	pictureBox1->Image = bmp;
	float** hloa = new float* [HiddenNeuron + 1];
	float** oloa = new float* [clscount];
	float** VecX = new float* [3];
	float max;
	int index;
	for (int i = 0; i < 3; i++)
	{
		VecX[i] = new float[1];
	}
	for (int i = 0; i < HiddenNeuron + 1; i++)
	{
		hloa[i] = new float[1];
	}
	for (int i = 0; i < clscount; i++)
	{
		oloa[i] = new float[1];
	}
	//0 lama dizileri
	for (int i = 0; i < 3; i++)
	{
		VecX[i][0] = 0.0f;
	}
	for (int i = 0; i < HiddenNeuron; i++)
	{
		hloa[i][0] = 0.0f;
	}
	hloa[HiddenNeuron][0] = 1.0f;//threshold;
	for (int i = 0; i < clscount; i++)
	{
		oloa[i][0] = 0.0f;
	}

	for (int row = 0; row < pictureBox1->Height; row+=2)
	{
		for (int col = 0; col < pictureBox1->Width; col+=2)
		{
			VecX[0][0] = ((col-pictureBox1->Width/2) - ortX) / SSX;
			VecX[1][0] = ((pictureBox1->Height/2-row) - ortY) / SSY;
			VecX[2][0] = 1.0f;

			for (int row = 0; row < HiddenNeuron; row++)//ara katman cýkýs y0 y1 y2
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < 3; op++)
					{
						hloa[row][col] += Veights[row][op] * VecX[op][col];
					}
					hloa[row][col] = ptron.bipolar_sigmoid_function(hloa[row][col]);
				}
			}

			for (int row = 0; row < clscount; row++)//cýkýs katman setlemesi o1 o2 o3
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < HiddenNeuron + 1; op++)
					{
						oloa[row][col] += Weights[row][op] * hloa[op][col];
					}
					oloa[row][col] = ptron.bipolar_sigmoid_function(oloa[row][col]);
				}
			}
			max = oloa[0][0];
			index = 0;
			for (int ind = 0; ind < clscount; ind++)
			{
				if (oloa[ind][0] > max)
				{
					max = oloa[ind][0];
					index = ind;
				}
			}
			
			for (int i = 0; i < HiddenNeuron; i++)
			{
				hloa[i][0] = 0.0f;
			}
			for (int i = 0; i < clscount; i++)
			{
				oloa[i][0] = 0.0f;
			}
			
			Color c = Color::FromArgb(colorvec[index].getRed(), colorvec[index].getGreen(), colorvec[index].getBlue());
			bmp->SetPixel(col, row, c);
			
		}
	}
}

private: System::Void showSamplesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Pen^ pen = gcnew Pen(Color::Black, 5);
	Pen^ pp;
	Graphics^ g = pictureBox1->CreateGraphics();
	g->DrawLine(pen, 250, 0, 250, 500);
	g->DrawLine(pen, 0, 250, 500, 250);
	for (int j = 0; j < vec.size(); j++)
	{
		Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
		pp = gcnew Pen(c, 2);
		g->DrawLine(pp, (vec[j]->getX()) - 4 + 250, 250 - vec[j]->getY(), vec[j]->getX() + 254, 250 - (vec[j]->getY()));
		g->DrawLine(pp, (vec[j]->getX()) + 250, 250 - vec[j]->getY() - 4, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) + 4);
	}

}
private: System::Void withMomentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	float** hloa = new float* [HiddenNeuron + 1];
	float** tempW = new float* [clscount];
	float** tempV = new float* [HiddenNeuron];
	float** oloa = new float* [clscount];
	float** VecX = new float* [3];
	float sumWeights = 0;
	float** desiredArr = new float* [clscount];
	for (int i = 0; i < clscount; i++)
	{
		desiredArr[i] = new float[1];
	}

	for (int i = 0; i < clscount; i++)
	{
		tempW[i] = new float[HiddenNeuron+1];
	}
	for (int i = 0; i < HiddenNeuron; i++)
	{
		tempV[i] = new float[3];
	}
	for (int i = 0; i < 3; i++)
	{
		VecX[i] = new float[1];
	}
	for (int i = 0; i < HiddenNeuron + 1; i++)
	{
		hloa[i] = new float[1];
		
	}
	for (int i = 0; i < clscount; i++)
	{
		oloa[i] = new float[1];
	}
	//0 lama dizileri
	for (int i = 0; i < 3; i++)
	{
		VecX[i][0] = 0.0f;
	}
	for (int i = 0; i < HiddenNeuron; i++)
	{
		hloa[i][0] = 0.0f;
		
	}
	hloa[HiddenNeuron][0] = 1.0f;//threshold;
	for (int i = 0; i < clscount; i++)
	{
		oloa[i][0] = 0.0f;
	}

	//temp temizleme
	for (int i = 0; i < clscount; i++)
	{
		for (int j = 0; j < HiddenNeuron + 1; j++)
		{
			tempW[i][j] = 0.0f;
		}
	}
	for (int i = 0; i < HiddenNeuron; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempV[i][j] = 0.0f;
		}
	}


	while (true)
	{
		for (int val = 0; val < vec.size(); val++)
		{

			if (normalize)
			{
				VecX[0][0] = vec[val]->getnormX();
				VecX[1][0] = vec[val]->getnormY();
				VecX[2][0] = vec[val]->getBias();
			}
			else
			{
				VecX[0][0] = vec[val]->getX();
				VecX[1][0] = vec[val]->getY();
				VecX[2][0] = vec[val]->getBias();
			}
			//beklenen vektor setleme
			for (int k = 0; k < clscount; k++)//scbak
			{
				if (vec[val]->getClassID() == k)
				{
					desiredArr[k][0] = 1.0f;
				}
				else if (vec[val]->getClassID() != k)
				{
					desiredArr[k][0] = -1.0f;
				}
			}

			for (int row = 0; row < HiddenNeuron; row++)//ara katman cýkýs y0 y1 y2
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < 3; op++)
					{
						hloa[row][col] += Veights[row][op] * VecX[op][col];
					}
					hloa[row][col] = ptron.bipolar_sigmoid_function(hloa[row][col]);
				}
			}

			for (int row = 0; row < clscount; row++)//cýkýs katman setlemesi o1 o2 o3
			{
				for (int col = 0; col < 1; col++)
				{
					for (int op = 0; op < HiddenNeuron + 1; op++)
					{
						oloa[row][col] += Weights[row][op] * hloa[op][col];
					}
					oloa[row][col] = ptron.bipolar_sigmoid_function(oloa[row][col]);
				}
			}


			//deltaWeight guncelle
			for (int k = 0; k < clscount; k++)//scbak 3x5
			{
				signalol = LC1 * (desiredArr[k][0] - oloa[k][0]) * ptron.bipolar_sigmoid_function_derive(oloa[k][0]);
				hata += (desiredArr[k][0] - oloa[k][0]) * (desiredArr[k][0] - oloa[k][0]);
				for (int j = 0; j < HiddenNeuron + 1; j++)
				{
					Weights[k][j] += (alfa1 * signalol * hloa[j][0]) + (alfa2 * tempW[k][j]);//sorun cýkarsa bak
					tempW[k][j] = alfa1*signalol * hloa[j][0];
				}
			}
			errorsum += hata;
			hata = 0;
			//Hidden Layer Guncelle
			for (int j = 0; j < HiddenNeuron; j++)//4x3
			{
				for (int i = 0; i < 3; i++)
				{
					for (int k = 0; k < clscount; k++)
					{
						sumWeights += (desiredArr[k][0] - oloa[k][0]) * ptron.bipolar_sigmoid_function_derive(oloa[k][0]) * Weights[k][j];
					}
					
					Veights[j][i] += alfa1*(LC2 * ptron.bipolar_sigmoid_function_derive(hloa[j][0]) * VecX[i][0] * sumWeights)+alfa2*tempV[j][i];
					tempV[j][i] = alfa1*(LC2 * ptron.bipolar_sigmoid_function_derive(hloa[j][0]) * VecX[i][0] * sumWeights);
					sumWeights = 0;
				}
			}

			for (int i = 0; i < HiddenNeuron; i++)
			{
				hloa[i][0] = 0.0f;
			}
			for (int j = 0; j < clscount; j++)
			{
				oloa[j][0] = 0.0f;
			}

		}
		errorsum = sqrt(errorsum) / (clscount * vec.size());
		if (errorsum < 0.01)
			break;
		label5->Text = "Hata: " + errorsum.ToString();
		label5->Refresh();
		errorsum = 0;
		cycle++;

	}
	label6->Text = "Cycle: " + cycle.ToString();
	label7->Text = "Hata: " + errorsum.ToString();
	errorsum = 0;
	hata = 0;
	cycle = 0;
	delete[] hloa;
	delete[] oloa;
	delete[] VecX;
}
};
}
