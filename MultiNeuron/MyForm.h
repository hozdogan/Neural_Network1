#pragma once
#include <vector>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include "neural_network.h"
#include <time.h>


namespace ysaproje2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	int clscount;
	std::vector<Renk> colorvec;
	Pattern2D* pat;
	Perceptron ptron;
	std::vector<Pattern2D*> vec;
	float LC = 0.5f;
	float net, hata = 0, fnet,signal,norm,x,y,sumX = 0,sumY = 0,ortX,ortY,SSX,SSY,temp;
	float** Weights;
	bool sgn, cont,normalize = false;
	int cycle = 0, step = 0, counttrue = 0, hatacount = 0;

	
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

	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;







	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ operationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ activationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continouslyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ signedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ weightsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::Button^ button3;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->operationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->activationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continouslyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->weightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(844, 380);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 42);
			this->button1->TabIndex = 1;
			this->button1->Text = L"LoadData";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->operationsToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1360, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// operationsToolStripMenuItem
			// 
			this->operationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->trainingToolStripMenuItem,
					this->activationToolStripMenuItem, this->weightsToolStripMenuItem
			});
			this->operationsToolStripMenuItem->Name = L"operationsToolStripMenuItem";
			this->operationsToolStripMenuItem->Size = System::Drawing::Size(96, 24);
			this->operationsToolStripMenuItem->Text = L"Operations";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->trainingToolStripMenuItem->Text = L"Training";
			this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::trainingToolStripMenuItem_Click);
			// 
			// activationToolStripMenuItem
			// 
			this->activationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->continouslyToolStripMenuItem,
					this->signedToolStripMenuItem
			});
			this->activationToolStripMenuItem->Name = L"activationToolStripMenuItem";
			this->activationToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->activationToolStripMenuItem->Text = L"Activation";
			// 
			// continouslyToolStripMenuItem
			// 
			this->continouslyToolStripMenuItem->Name = L"continouslyToolStripMenuItem";
			this->continouslyToolStripMenuItem->Size = System::Drawing::Size(169, 26);
			this->continouslyToolStripMenuItem->Text = L"Continously";
			this->continouslyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continouslyToolStripMenuItem_Click);
			// 
			// signedToolStripMenuItem
			// 
			this->signedToolStripMenuItem->Name = L"signedToolStripMenuItem";
			this->signedToolStripMenuItem->Size = System::Drawing::Size(169, 26);
			this->signedToolStripMenuItem->Text = L"Signed";
			this->signedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::signedToolStripMenuItem_Click);
			// 
			// weightsToolStripMenuItem
			// 
			this->weightsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomlyToolStripMenuItem });
			this->weightsToolStripMenuItem->Name = L"weightsToolStripMenuItem";
			this->weightsToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->weightsToolStripMenuItem->Text = L"Weights";
			// 
			// randomlyToolStripMenuItem
			// 
			this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			this->randomlyToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			this->randomlyToolStripMenuItem->Text = L"Randomly";
			this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::randomlyToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(57, 56);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1024, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Class No:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(802, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(802, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(802, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(958, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(958, 192);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 10;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(958, 232);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 17);
			this->label7->TabIndex = 11;
			this->label7->Text = L"label7";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(863, 68);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(764, 72);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"ClassCount";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1126, 71);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 14;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1081, 380);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 34);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Normalize";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1360, 762);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MultiNeuron";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
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
		String^ str = textBox1->Text;
		clscount = System::Convert::ToInt32(str);
		comboBox1->ItemHeight = clscount;
		for (int i = 1; i <=clscount; i++)
		{
			String^ s = "Class" + i;
			comboBox1->Items->Add(s);
		}
		
		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Graphics^ g = pictureBox1->CreateGraphics();
	g->Clear(Color::White);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	int current = comboBox1->SelectedIndex;
	
	Color c = Color::FromArgb(colorvec[current].getRed(), colorvec[current].getGreen(), colorvec[current].getBlue());
	pen = gcnew Pen(c,1);
	
	if (e->X > pictureBox1->Width / 2 && e->Y > pictureBox1->Height / 2)
	{
		label4->Text = "x1: " + (e->X - pictureBox1->Width / 2).ToString();
		label5->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
		x = (e->X - pictureBox1->Width / 2);
		y = ((pictureBox1->Height / 2 - e->Y));
	}
	else if (e->X > pictureBox1->Width / 2 && e->Y < pictureBox1->Height / 2)
	{
		label4->Text = "x1: " + (e->X - pictureBox1->Width / 2).ToString();
		label5->Text = "y1: " + (pictureBox1->Height / 2 - e->Y).ToString();
		x = (e->X - pictureBox1->Width / 2);
		y = (pictureBox1->Height / 2 - e->Y);
	}
	else if (e->X < pictureBox1->Width / 2 && e->Y < pictureBox1->Height / 2)
	{
		label4->Text = "x1: " + ((-1) * (pictureBox1->Width / 2 - e->X)).ToString();
		label5->Text = "y1: " + (pictureBox1->Height / 2 - e->Y).ToString();
		x = ((-1) * (pictureBox1->Width / 2 - e->X));
		y = (pictureBox1->Height / 2 - e->Y);

	}
	else if (e->X < pictureBox1->Width / 2 && e->Y > pictureBox1->Height / 2)
	{
		label4->Text = "x1: " + ((-1) * (pictureBox1->Width / 2 - e->X)).ToString();
		label5->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
		x = ((-1) * (pictureBox1->Width / 2 - e->X));
		y = ((pictureBox1->Height / 2 - e->Y));
	}

	pat = new Pattern2D(x, y);
	pat->setBias(1.0f);
	pat->setClassID(current);
	vec.push_back(pat);
	g->DrawLine(pen, e->X - 4, e->Y, e->X + 4, e->Y);
	g->DrawLine(pen, e->X, e->Y - 4, e->X, e->Y + 4);
}

private: System::Void continouslyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	sgn = false;
	cont = true;
}
private: System::Void signedToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	sgn = true;
	cont = false;
}
private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));
	Weights = new float* [clscount];
	for (int j = 0; j < clscount; ++j)
	{
		Weights[j] = new float[3];
	}

	for (int i = 0; i < clscount; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Weights[i][j] = (rand() % 10) / 10.0f + ((rand() % 10) / 100.0f);
		}
	}
	label4->Text = Weights[1][0].ToString();
	label5->Text = Weights[1][1].ToString();
	label6->Text = Weights[1][2].ToString();


}
private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	Graphics^ g = pictureBox1->CreateGraphics();
	Pen^ pen;
	float** outputarray = new float*[clscount];
	for (int i = 0; i < clscount; i++)
	{
		outputarray[i] = new float[1];
	}
	for (int row = 0; row < clscount; row++)
	{
		for (int col = 0; col < 1; col++)
		{
			outputarray[row][col] = 0.0f;
		}
	}
	float** VecX = new float* [3];
	for (int i = 0; i < 3; i++)
	{
		VecX[i] = new float[1];
	}

	if (sgn)
	{
		while (true)//counttrue < (vec.size() * clscount)
		{
			for (int k = 0; k < vec.size(); k++)
			{
				VecX[0][0] = vec[k]->getX();
				VecX[1][0] = vec[k]->getY();
				VecX[2][0] = vec[k]->getBias();

				for (int row = 0; row < clscount; row++)
				{
					for (int col = 0; col < 1; col++)
					{
						for (int op = 0; op < 3; op++)
						{
							outputarray[row][col] += Weights[row][op] * VecX[op][col];
						}
					}
				}

				for (int i = 0; i < clscount; i++)
				{
					
					if (vec[k]->getClassID() == i)
					{
						vec[k]->setDesiredValue(1.0f);
					}
					else if (vec[k]->getClassID() != i)
					{
						vec[k]->setDesiredValue(-1.0f);
					}
					temp = ptron.sgn_activation_function(outputarray[i][0]);
					signal = LC * (vec[k]->getDesiredValue() - temp);
					hata += 0.5 * (powf(vec[k]->getDesiredValue() - temp, 2));
					Weights[i][0] = (signal * vec[k]->getX()) + Weights[i][0];
					Weights[i][1] = (signal * vec[k]->getY()) + Weights[i][1];
					Weights[i][2] = (signal * vec[k]->getBias()) + Weights[i][2];
					
				}
				for (int ind = 0; ind < clscount; ind++)
				{	
					outputarray[ind][0] = 0.0f;
				}
			}
			if (hata == 0)
				break;
			hata = 0;
			cycle++;
			pictureBox1->Refresh();
			if (normalize)
			{
				for (int j = 0; j < vec.size(); j++)
				{
					Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
					pen = gcnew Pen(c, 1);
					g->DrawLine(pen, (vec[j]->getX() * 30) - 4 + 250, 250 - (vec[j]->getY() * 30), (vec[j]->getX() * 30) + 254, 250 - (vec[j]->getY() * 30));
					g->DrawLine(pen, (vec[j]->getX() * 30) + 250, 250 - (vec[j]->getY() * 30) - 4, (vec[j]->getX() * 30) + 250, 250 - (vec[j]->getY() * 30) + 4);
				}
				for (int i = 0; i < clscount; i++)
				{
					Color c = Color::FromArgb(colorvec[i].getRed(), colorvec[i].getGreen(), colorvec[i].getBlue());
					pen = gcnew Pen(c, 1);
					float x12 = ((-Weights[i][0] * (pictureBox1->Width / 2)) - Weights[i][2] * 30) / Weights[i][1];
					float x22 = ((-Weights[i][0] * (-pictureBox1->Width / 2)) - Weights[i][2] * 30) / Weights[i][1];
					g->DrawLine(pen, 500.0f, 250 - x12, 0.0f, 250 - x22);

				}
			}
			else
			{
				for (int j = 0; j < vec.size(); j++)
				{
					Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
					pen = gcnew Pen(c, 1);
					g->DrawLine(pen, (vec[j]->getX()) - 4 + 250, 250 - (vec[j]->getY()), (vec[j]->getX()) + 254, 250 - (vec[j]->getY()));
					g->DrawLine(pen, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) - 4, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) + 4);
				}
				for (int i = 0; i < clscount; i++)
				{
					Color c = Color::FromArgb(colorvec[i].getRed(), colorvec[i].getGreen(), colorvec[i].getBlue());
					pen = gcnew Pen(c, 1);
					float x12 = ((-Weights[i][0] * (pictureBox1->Width / 2)) - Weights[i][2]) / Weights[i][1];
					float x22 = ((-Weights[i][0] * (-pictureBox1->Width / 2)) - Weights[i][2]) / Weights[i][1];
					g->DrawLine(pen, 500.0f, 250 - x12, 0.0f, 250 - x22);

				}
			}
			label4->Text = "cycle: " + cycle.ToString();
			label4->Refresh();
			
			
		}
		
		label4->Text = "cycle: " + cycle.ToString();
		delete [] outputarray;
		delete [] VecX;
	}
	else if (cont)
	{
		while (true)//hatacount < vec.size()
		{
			for (int k = 0; k < vec.size(); k++)
			{
				VecX[0][0] = vec[k]->getX();
				VecX[1][0] = vec[k]->getY();
				VecX[2][0] = vec[k]->getBias();

				for (int row = 0; row < clscount; row++)
				{
					for (int col = 0; col < 1; col++)
					{
						for (int op = 0; op < 3; op++)
						{
							outputarray[row][col] += Weights[row][op] * VecX[op][col];
						}
					}
				}

				for (int i = 0; i < clscount; i++)
				{
					
					if (vec[k]->getClassID() == i)
					{
						vec[k]->setDesiredValue(1.0f);
					}
					else if (vec[k]->getClassID() != i)
					{
						vec[k]->setDesiredValue(-1.0f);
					}

					temp = ptron.bipolar_sigmoid_function(outputarray[i][0]);
					signal = LC * (vec[k]->getDesiredValue() - temp) * ptron.bipolar_sigmoid_function_derive(temp);
					hata += 0.5 * pow(vec[k]->getDesiredValue() - temp,2);
					Weights[i][0] += (signal * vec[k]->getX());
					Weights[i][1] += (signal * vec[k]->getY());
					Weights[i][2] += (signal * vec[k]->getBias());

				}
				
				for (int row = 0; row < clscount; row++)
				{
					outputarray[row][0] = 0.0f;
				}
			
				
			}
			if (hata <0.01)
			{
				break;
			}
			hata = 0;
			cycle++;
			pictureBox1->Refresh();
			if (normalize)
			{
				for (int j = 0; j < vec.size(); j++)
				{
					Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
					pen = gcnew Pen(c, 1);
					g->DrawLine(pen, (vec[j]->getX() * 30) - 4 + 250, 250 - (vec[j]->getY() * 30), (vec[j]->getX() * 30) + 254, 250 - (vec[j]->getY() * 30));
					g->DrawLine(pen, (vec[j]->getX() * 30) + 250, 250 - (vec[j]->getY() * 30) - 4, (vec[j]->getX() * 30) + 250, 250 - (vec[j]->getY() * 30) + 4);
				}
				for (int i = 0; i < clscount; i++)
				{
					Color c = Color::FromArgb(colorvec[i].getRed(), colorvec[i].getGreen(), colorvec[i].getBlue());
					pen = gcnew Pen(c, 1);
					float x12 = ((-Weights[i][0] * (pictureBox1->Width / 2)) - Weights[i][2]*30) / Weights[i][1];
					float x22 = ((-Weights[i][0] * (-pictureBox1->Width / 2)) - Weights[i][2]*30) / Weights[i][1];
					g->DrawLine(pen, 500.0f, 250 - x12, 0.0f, 250 - x22);

				}
			}
			else
			{
				for (int j = 0; j < vec.size(); j++)
				{
					Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
					pen = gcnew Pen(c, 1);
					g->DrawLine(pen, (vec[j]->getX()) - 4 + 250, 250 - (vec[j]->getY()), (vec[j]->getX()) + 254, 250 - (vec[j]->getY()));
					g->DrawLine(pen, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) - 4, (vec[j]->getX()) + 250, 250 - (vec[j]->getY()) + 4);
				}
				for (int i = 0; i < clscount; i++)
				{
					Color c = Color::FromArgb(colorvec[i].getRed(), colorvec[i].getGreen(), colorvec[i].getBlue());
					pen = gcnew Pen(c, 1);
					float x12 = ((-Weights[i][0] * (pictureBox1->Width / 2)) - Weights[i][2]) / Weights[i][1];
					float x22 = ((-Weights[i][0] * (-pictureBox1->Width / 2)) - Weights[i][2]) / Weights[i][1];
					g->DrawLine(pen, 500.0f, 250 - x12, 0.0f, 250 - x22);

				}
			}
			label4->Text = "cycle: " + cycle.ToString();
			label4->Refresh();
		
		}
		
		
		label4->Text = "cycle: " + cycle.ToString();
		label5->Text = "hata: " + hata.ToString();
		
		hata = 0;
	}
	
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int* normX = new int[vec.size()];
	int* normY = new int[vec.size()];
	pictureBox1->Refresh();
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
		vec[j]->setX(((vec[j]->getX() - ortX) / SSX));//*30
		vec[j]->setY(((vec[j]->getY() - ortY) / SSY));

		Color c = Color::FromArgb(colorvec[vec[j]->getClassID()].getRed(), colorvec[vec[j]->getClassID()].getGreen(), colorvec[vec[j]->getClassID()].getBlue());
		pen = gcnew Pen(c, 1);
		g->DrawLine(pen, (vec[j]->getX()*30) - 4 + 250, 250 -(vec[j]->getY()*30), (vec[j]->getX()*30) + 254, 250 -(vec[j]->getY()*30));
		g->DrawLine(pen, (vec[j]->getX()*30) + 250, 250 -(vec[j]->getY()*30) - 4, (vec[j]->getX()*30) + 250, 250 -(vec[j]->getY()*30) + 4);
	}
	
	

}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->X > pictureBox1->Width / 2 && e->Y > pictureBox1->Height / 2)
	{
		label2->Text = "x1: " + (e->X - pictureBox1->Width / 2).ToString();
		label3->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
		
	}
	else if (e->X > pictureBox1->Width / 2 && e->Y < pictureBox1->Height / 2)
	{
		label2->Text = "x1: " + (e->X - pictureBox1->Width / 2).ToString();
		label3->Text = "y1: " + (pictureBox1->Height / 2 - e->Y).ToString();
		
	}
	else if (e->X < pictureBox1->Width / 2 && e->Y < pictureBox1->Height / 2)
	{
		label2->Text = "x1: " + ((-1) * (pictureBox1->Width / 2 - e->X)).ToString();
		label3->Text = "y1: " + (pictureBox1->Height / 2 - e->Y).ToString();
		

	}
	else if (e->X < pictureBox1->Width / 2 && e->Y > pictureBox1->Height / 2)
	{
		label2->Text = "x1: " + ((-1) * (pictureBox1->Width / 2 - e->X)).ToString();
		label3->Text = "y1: " + ((pictureBox1->Height / 2 - e->Y)).ToString();
		
	}
}
};
}
