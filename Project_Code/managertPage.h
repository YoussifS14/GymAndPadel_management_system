#pragma once
#include "Structure.h"
#include "CreatClassForm.h"

namespace ProjectCode {
	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;
	 using namespace System::Drawing::Drawing2D;

	 public ref class managertPage : public System::Windows::Forms::Form
	 {
	 private:
		  CreatClassForm^ creatClassFormInstance; // To manage the CreatClassForm instance
	 private: System::Windows::Forms::Button^ LogOutbutton;
	 private: System::Windows::Forms::Panel^ searchCoach;
	 private: System::Windows::Forms::Panel^ Report_pn;

	 private: System::Windows::Forms::FlowLayoutPanel^ MonthReport;
	 private: System::Windows::Forms::Panel^ searchUser;

			System::Windows::Forms::Panel^ creatClassPanel; // To hold panel1 from CreatClassForm
	 public:
		  managertPage(void)
		  {
			   InitializeComponent();

		  }

	 protected:
		  ~managertPage()
		  {
			   if (components)
			   {
					delete components;
			   }
			   if (creatClassFormInstance)
			   {
					delete creatClassFormInstance;
					creatClassFormInstance = nullptr;
			   }
		  }
		  Void loadpic(PictureBox^ pic)
		  {
			   string val = staffList[loginID].PicPath;
			   if (val != "null")
					pic->Image = System::Drawing::Image::FromFile(gcnew String(val.c_str()));
			   else
					pic->Image = System::Drawing::Image::FromFile(gcnew String(defaultImagePath.c_str()));
		  }
		  Void MakePictureCircular(PictureBox^ picBox)
		  {
			   Bitmap^ bmp = gcnew Bitmap(picBox->Image);
			   int diameter = Math::Min(bmp->Width, bmp->Height);
			   Bitmap^ circularBmp = gcnew Bitmap(diameter, diameter);
			   Graphics^ g = Graphics::FromImage(circularBmp);
			   g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
			   GraphicsPath^ path = gcnew GraphicsPath();
			   path->AddEllipse(0, 0, diameter, diameter);
			   g->SetClip(path);
			   int offsetX = (bmp->Width - diameter) / 2;
			   int offsetY = (bmp->Height - diameter) / 2;
			   g->DrawImage(bmp, -offsetX, -offsetY);
			   picBox->Image = circularBmp;
		  }
	 private: System::Windows::Forms::Panel^ MainPg_pn;
	 protected:

	 private:

		  System::Windows::Forms::Panel^ profile_pn;
		  System::Windows::Forms::Label^ AccName;
		  System::Windows::Forms::Button^ button1;
		  System::Windows::Forms::TextBox^ userIDTextBox;
		  System::Windows::Forms::Button^ button2;
		  System::Windows::Forms::Button^ button3;
		  System::Windows::Forms::Button^ button4;
		  System::Windows::Forms::Label^ label1;
		  System::Windows::Forms::Button^ button6;
	 private: System::Windows::Forms::Panel^ CreateCls;

			System::Windows::Forms::Button^ button8;
			System::Windows::Forms::TextBox^ textBox2;
			System::Windows::Forms::ComboBox^ comboBox1;
			System::Windows::Forms::Button^ button5;
			System::Windows::Forms::Button^ actionButton;
			System::Windows::Forms::FlowLayoutPanel^ userInfoPanel;
			System::Windows::Forms::Panel^ panel2;

			System::Windows::Forms::PictureBox^ pictureBox1;
			System::Windows::Forms::DataGridView^ classGridView;
			System::Windows::Forms::Label^ coachInfoLabel;
			System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			void InitializeComponent(void)
			{
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(managertPage::typeid));
				 this->MainPg_pn = (gcnew System::Windows::Forms::Panel());
				 this->searchUser = (gcnew System::Windows::Forms::Panel());
				 this->actionButton = (gcnew System::Windows::Forms::Button());
				 this->userInfoPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->userIDTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->Report_pn = (gcnew System::Windows::Forms::Panel());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->MonthReport = (gcnew System::Windows::Forms::FlowLayoutPanel());
				 this->CreateCls = (gcnew System::Windows::Forms::Panel());
				 this->searchCoach = (gcnew System::Windows::Forms::Panel());
				 this->coachInfoLabel = (gcnew System::Windows::Forms::Label());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->button8 = (gcnew System::Windows::Forms::Button());
				 this->classGridView = (gcnew System::Windows::Forms::DataGridView());
				 this->profile_pn = (gcnew System::Windows::Forms::Panel());
				 this->LogOutbutton = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->AccName = (gcnew System::Windows::Forms::Label());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->MainPg_pn->SuspendLayout();
				 this->searchUser->SuspendLayout();
				 this->Report_pn->SuspendLayout();
				 this->searchCoach->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->BeginInit();
				 this->profile_pn->SuspendLayout();
				 this->panel2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // MainPg_pn
				 // 
				 this->MainPg_pn->Controls->Add(this->searchUser);
				 this->MainPg_pn->Controls->Add(this->Report_pn);
				 this->MainPg_pn->Controls->Add(this->CreateCls);
				 this->MainPg_pn->Controls->Add(this->searchCoach);
				 this->MainPg_pn->Dock = System::Windows::Forms::DockStyle::Right;
				 this->MainPg_pn->Location = System::Drawing::Point(296, 0);
				 this->MainPg_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->MainPg_pn->Name = L"MainPg_pn";
				 this->MainPg_pn->Size = System::Drawing::Size(977, 738);
				 this->MainPg_pn->TabIndex = 3;
				 this->MainPg_pn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::MainMenu_pn_Paint);
				 // 
				 // searchUser
				 // 
				 this->searchUser->BackColor = System::Drawing::SystemColors::Control;
				 this->searchUser->Controls->Add(this->actionButton);
				 this->searchUser->Controls->Add(this->userInfoPanel);
				 this->searchUser->Controls->Add(this->userIDTextBox);
				 this->searchUser->Controls->Add(this->label1);
				 this->searchUser->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->searchUser->Location = System::Drawing::Point(0, 0);
				 this->searchUser->Margin = System::Windows::Forms::Padding(4);
				 this->searchUser->Name = L"searchUser";
				 this->searchUser->Size = System::Drawing::Size(977, 738);
				 this->searchUser->TabIndex = 15;
				 // 
				 // actionButton
				 // 
				 this->actionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->actionButton->Location = System::Drawing::Point(700, 19);
				 this->actionButton->Margin = System::Windows::Forms::Padding(4);
				 this->actionButton->Name = L"actionButton";
				 this->actionButton->Size = System::Drawing::Size(146, 47);
				 this->actionButton->TabIndex = 11;
				 this->actionButton->UseVisualStyleBackColor = true;
				 this->actionButton->Click += gcnew System::EventHandler(this, &managertPage::actionButton_Click);
				 // 
				 // userInfoPanel
				 // 
				 this->userInfoPanel->AutoScroll = true;
				 this->userInfoPanel->BackColor = System::Drawing::SystemColors::Control;
				 this->userInfoPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
				 this->userInfoPanel->Location = System::Drawing::Point(73, 144);
				 this->userInfoPanel->Margin = System::Windows::Forms::Padding(4);
				 this->userInfoPanel->Name = L"userInfoPanel";
				 this->userInfoPanel->Size = System::Drawing::Size(811, 565);
				 this->userInfoPanel->TabIndex = 8;
				 this->userInfoPanel->WrapContents = false;
				 // 
				 // userIDTextBox
				 // 
				 this->userIDTextBox->BackColor = System::Drawing::SystemColors::Control;
				 this->userIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->userIDTextBox->Location = System::Drawing::Point(217, 19);
				 this->userIDTextBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->userIDTextBox->Name = L"userIDTextBox";
				 this->userIDTextBox->Size = System::Drawing::Size(200, 34);
				 this->userIDTextBox->TabIndex = 10;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(82, 20);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(111, 35);
				 this->label1->TabIndex = 9;
				 this->label1->Text = L"User ID";
				 // 
				 // Report_pn
				 // 
				 this->Report_pn->Controls->Add(this->comboBox1);
				 this->Report_pn->Controls->Add(this->button5);
				 this->Report_pn->Controls->Add(this->MonthReport);
				 this->Report_pn->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->Report_pn->Location = System::Drawing::Point(0, 0);
				 this->Report_pn->Name = L"Report_pn";
				 this->Report_pn->Size = System::Drawing::Size(977, 738);
				 this->Report_pn->TabIndex = 12;
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
					  L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
						   L"9", L"10", L"11", L"12"
				 });
				 this->comboBox1->Location = System::Drawing::Point(301, 65);
				 this->comboBox1->Margin = System::Windows::Forms::Padding(4);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(273, 30);
				 this->comboBox1->TabIndex = 6;
				 this->comboBox1->Text = L"Choose month";
				 this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &managertPage::comboBox1_SelectedIndexChanged);
				 // 
				 // button5
				 // 
				 this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button5->Location = System::Drawing::Point(777, 53);
				 this->button5->Margin = System::Windows::Forms::Padding(4);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(120, 42);
				 this->button5->TabIndex = 7;
				 this->button5->Text = L"Submit";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &managertPage::button5_Click_1);
				 // 
				 // MonthReport
				 // 
				 this->MonthReport->AutoScroll = true;
				 this->MonthReport->BackColor = System::Drawing::SystemColors::Control;
				 this->MonthReport->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
				 this->MonthReport->Location = System::Drawing::Point(73, 156);
				 this->MonthReport->Margin = System::Windows::Forms::Padding(4);
				 this->MonthReport->Name = L"MonthReport";
				 this->MonthReport->Size = System::Drawing::Size(811, 565);
				 this->MonthReport->TabIndex = 9;
				 this->MonthReport->WrapContents = false;
				 // 
				 // CreateCls
				 // 
				 this->CreateCls->BackColor = System::Drawing::SystemColors::Control;
				 this->CreateCls->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->CreateCls->Location = System::Drawing::Point(0, 0);
				 this->CreateCls->Margin = System::Windows::Forms::Padding(4);
				 this->CreateCls->Name = L"CreateCls";
				 this->CreateCls->Size = System::Drawing::Size(977, 738);
				 this->CreateCls->TabIndex = 9;
				 this->CreateCls->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::panel1_Paint);
				 // 
				 // searchCoach
				 // 
				 this->searchCoach->Controls->Add(this->coachInfoLabel);
				 this->searchCoach->Controls->Add(this->textBox2);
				 this->searchCoach->Controls->Add(this->button8);
				 this->searchCoach->Controls->Add(this->classGridView);
				 this->searchCoach->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->searchCoach->Location = System::Drawing::Point(0, 0);
				 this->searchCoach->Name = L"searchCoach";
				 this->searchCoach->Size = System::Drawing::Size(977, 738);
				 this->searchCoach->TabIndex = 14;
				 // 
				 // coachInfoLabel
				 // 
				 this->coachInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->coachInfoLabel->Location = System::Drawing::Point(29, 144);
				 this->coachInfoLabel->Margin = System::Windows::Forms::Padding(4);
				 this->coachInfoLabel->Name = L"coachInfoLabel";
				 this->coachInfoLabel->Size = System::Drawing::Size(301, 60);
				 this->coachInfoLabel->TabIndex = 13;
				 // 
				 // textBox2
				 // 
				 this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->textBox2->Location = System::Drawing::Point(360, 74);
				 this->textBox2->Margin = System::Windows::Forms::Padding(4);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(187, 34);
				 this->textBox2->TabIndex = 3;
				 // 
				 // button8
				 // 
				 this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button8->Location = System::Drawing::Point(359, 11);
				 this->button8->Margin = System::Windows::Forms::Padding(4);
				 this->button8->Name = L"button8";
				 this->button8->Size = System::Drawing::Size(188, 55);
				 this->button8->TabIndex = 4;
				 this->button8->Text = L"Enter Coach ID";
				 this->button8->UseVisualStyleBackColor = true;
				 this->button8->Click += gcnew System::EventHandler(this, &managertPage::button8_Click);
				 // 
				 // classGridView
				 // 
				 this->classGridView->AllowUserToAddRows = false;
				 this->classGridView->AllowUserToDeleteRows = false;
				 this->classGridView->BackgroundColor = System::Drawing::SystemColors::Control;
				 this->classGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->classGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->classGridView->Location = System::Drawing::Point(0, 212);
				 this->classGridView->Margin = System::Windows::Forms::Padding(4);
				 this->classGridView->Name = L"classGridView";
				 this->classGridView->ReadOnly = true;
				 this->classGridView->RowHeadersVisible = false;
				 this->classGridView->RowHeadersWidth = 51;
				 this->classGridView->RowTemplate->Height = 40;
				 this->classGridView->Size = System::Drawing::Size(977, 526);
				 this->classGridView->TabIndex = 12;
				 // 
				 // profile_pn
				 // 
				 this->profile_pn->BackColor = System::Drawing::SystemColors::Control;
				 this->profile_pn->Controls->Add(this->LogOutbutton);
				 this->profile_pn->Controls->Add(this->button1);
				 this->profile_pn->Controls->Add(this->button4);
				 this->profile_pn->Controls->Add(this->button3);
				 this->profile_pn->Controls->Add(this->button2);
				 this->profile_pn->Controls->Add(this->button6);
				 this->profile_pn->Controls->Add(this->panel2);
				 this->profile_pn->Dock = System::Windows::Forms::DockStyle::Left;
				 this->profile_pn->Location = System::Drawing::Point(0, 0);
				 this->profile_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->profile_pn->Name = L"profile_pn";
				 this->profile_pn->Size = System::Drawing::Size(297, 738);
				 this->profile_pn->TabIndex = 1;
				 this->profile_pn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::profile_pn_Paint);
				 // 
				 // LogOutbutton
				 // 
				 this->LogOutbutton->Dock = System::Windows::Forms::DockStyle::Top;
				 this->LogOutbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->LogOutbutton->Location = System::Drawing::Point(0, 648);
				 this->LogOutbutton->Name = L"LogOutbutton";
				 this->LogOutbutton->Size = System::Drawing::Size(297, 73);
				 this->LogOutbutton->TabIndex = 0;
				 this->LogOutbutton->Text = L"Log out ";
				 this->LogOutbutton->UseVisualStyleBackColor = true;
				 this->LogOutbutton->Click += gcnew System::EventHandler(this, &managertPage::LogOutbutton_Click);
				 // 
				 // button1
				 // 
				 this->button1->Dock = System::Windows::Forms::DockStyle::Top;
				 this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button1->Location = System::Drawing::Point(0, 567);
				 this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(297, 81);
				 this->button1->TabIndex = 4;
				 this->button1->Text = L"Delete User";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &managertPage::button1_Click_1);
				 // 
				 // button4
				 // 
				 this->button4->Dock = System::Windows::Forms::DockStyle::Top;
				 this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button4->Location = System::Drawing::Point(0, 468);
				 this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(297, 99);
				 this->button4->TabIndex = 1;
				 this->button4->Text = L"Generate Monthly Report";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &managertPage::button4_Click);
				 // 
				 // button3
				 // 
				 this->button3->Dock = System::Windows::Forms::DockStyle::Top;
				 this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button3->Location = System::Drawing::Point(0, 382);
				 this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(297, 86);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"Create Class";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &managertPage::button3_Click);
				 // 
				 // button2
				 // 
				 this->button2->Dock = System::Windows::Forms::DockStyle::Top;
				 this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button2->Location = System::Drawing::Point(0, 292);
				 this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(297, 90);
				 this->button2->TabIndex = 3;
				 this->button2->Text = L"Display Coach Classes";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &managertPage::button2_Click);
				 // 
				 // button6
				 // 
				 this->button6->Dock = System::Windows::Forms::DockStyle::Top;
				 this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					  static_cast<System::Byte>(0)));
				 this->button6->Location = System::Drawing::Point(0, 204);
				 this->button6->Margin = System::Windows::Forms::Padding(4);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(297, 88);
				 this->button6->TabIndex = 8;
				 this->button6->Text = L"Search User By ID";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->Click += gcnew System::EventHandler(this, &managertPage::button6_Click);
				 // 
				 // panel2
				 // 
				 this->panel2->BackColor = System::Drawing::SystemColors::Control;
				 this->panel2->Controls->Add(this->AccName);
				 this->panel2->Controls->Add(this->pictureBox1);
				 this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
				 this->panel2->Location = System::Drawing::Point(0, 0);
				 this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(297, 204);
				 this->panel2->TabIndex = 11;
				 this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::panel2_Paint);
				 // 
				 // AccName
				 // 
				 this->AccName->AutoSize = true;
				 this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->AccName->Location = System::Drawing::Point(12, 170);
				 this->AccName->Name = L"AccName";
				 this->AccName->Size = System::Drawing::Size(62, 23);
				 this->AccName->TabIndex = 1;
				 this->AccName->Text = L"Name";
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(16, 11);
				 this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(213, 146);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &managertPage::pictureBox1_Click);
				 // 
				 // managertPage
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::Control;
				 this->ClientSize = System::Drawing::Size(1273, 738);
				 this->Controls->Add(this->profile_pn);
				 this->Controls->Add(this->MainPg_pn);
				 this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->Name = L"managertPage";
				 this->Text = L"Manager Page";
				 this->Load += gcnew System::EventHandler(this, &managertPage::managertPage_Load);
				 this->MainPg_pn->ResumeLayout(false);
				 this->searchUser->ResumeLayout(false);
				 this->searchUser->PerformLayout();
				 this->Report_pn->ResumeLayout(false);
				 this->searchCoach->ResumeLayout(false);
				 this->searchCoach->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->EndInit();
				 this->profile_pn->ResumeLayout(false);
				 this->panel2->ResumeLayout(false);
				 this->panel2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);

			}
#pragma endregion

			void deleteUser_and_cancelsubscription(System::String^ userID) {
				 if (String::IsNullOrEmpty(userID)) {
					  MessageBox::Show("Please enter a valid user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }

				 std::string userIDStr = msclr::interop::marshal_as<std::string>(userID);

				 if (userList.find(userIDStr) != userList.end()) {
					  userList.erase(userIDStr);
					  MessageBox::Show(String::Format("User {0} has been removed from the system.", userID), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 }
				 else {
					  MessageBox::Show("User not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			}

			void SearchUserByID(System::String^ userIDText, System::Windows::Forms::FlowLayoutPanel^ infoPanel) {
				 extern unordered_map<std::string, User> userList;
				 System::String^ trimmedID = userIDText->Trim();
				 infoPanel->Controls->Clear();

				 if (String::IsNullOrEmpty(trimmedID)) {
					  Label^ errorLabel = gcnew Label();
					  errorLabel->AutoSize = true;
					  errorLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  errorLabel->ForeColor = Color::Red;
					  errorLabel->Text = L"Please enter a valid user ID.";
					  infoPanel->Controls->Add(errorLabel);
					  return;
				 }

				 std::string userID = msclr::interop::marshal_as<std::string>(trimmedID);
				 User foundUser;
				 for (const auto& pair : userList) {
					  if (pair.first == userID) {
						   foundUser = pair.second;
						   break;
					  }
				 }

				 if (foundUser.ID != "") {
					  // Header
					  Label^ headerLabel = gcnew Label();
					  headerLabel->AutoSize = true;
					  headerLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
					  headerLabel->ForeColor = Color::DarkBlue;
					  headerLabel->Text = L"User Information:\n";
					  infoPanel->Controls->Add(headerLabel);

					  // Name
					  Label^ nameLabel = gcnew Label();
					  nameLabel->AutoSize = true;
					  nameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  nameLabel->Text = L"Name: " + gcnew String(foundUser.name.c_str());
					  infoPanel->Controls->Add(nameLabel);

					  // Birthday
					  Label^ birthdayLabel = gcnew Label();
					  birthdayLabel->AutoSize = true;
					  birthdayLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  birthdayLabel->Text = L"Birthday: " + gcnew String(foundUser.Birthday.c_str());
					  infoPanel->Controls->Add(birthdayLabel);

					  // Subscription
					  Label^ subscriptionLabel = gcnew Label();
					  subscriptionLabel->AutoSize = true;
					  subscriptionLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  subscriptionLabel->Text = L"Subscription: " + gcnew String(foundUser.subscription.getType().c_str());
					  infoPanel->Controls->Add(subscriptionLabel);

					  // Classes Entered
					  Label^ classesEnteredLabel = gcnew Label();
					  classesEnteredLabel->AutoSize = true;
					  classesEnteredLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  classesEnteredLabel->Text = L"Classes Entered: " + foundUser.classEntered.ToString();
					  infoPanel->Controls->Add(classesEnteredLabel);

					  // Wallet
					  Label^ walletLabel = gcnew Label();
					  walletLabel->AutoSize = true;
					  walletLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  walletLabel->Text = L"Wallet Balance: " + String::Format(L"${0:F2}", foundUser.myWallet);
					  infoPanel->Controls->Add(walletLabel);

					  // VIP Status
					  Label^ vipLabel = gcnew Label();
					  vipLabel->AutoSize = true;
					  vipLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  vipLabel->Text = L"VIP Status: " + (foundUser.isVip ? L"Yes" : L"No");
					  infoPanel->Controls->Add(vipLabel);

					  // Picture Path
					  Label^ picPathLabel = gcnew Label();
					  picPathLabel->AutoSize = true;
					  picPathLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  picPathLabel->Text = L"Picture Path: " + gcnew String(foundUser.PicPath.c_str()) + L"\n";
					  infoPanel->Controls->Add(picPathLabel);

					  // Reserved Classes
					  Label^ reservedClassesHeader = gcnew Label();
					  reservedClassesHeader->AutoSize = true;
					  reservedClassesHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  reservedClassesHeader->ForeColor = Color::Navy;
					  reservedClassesHeader->Text = L"Reserved Classes:\n";
					  infoPanel->Controls->Add(reservedClassesHeader);

					  if (foundUser.myClasses.empty()) {
						   Label^ noClassesLabel = gcnew Label();
						   noClassesLabel->AutoSize = true;
						   noClassesLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noClassesLabel->ForeColor = Color::DarkGreen;
						   noClassesLabel->Text = L"  None";
						   infoPanel->Controls->Add(noClassesLabel);
					  }
					  else {
						   for (const auto& classID : foundUser.myClasses) {
								Label^ classLabel = gcnew Label();
								classLabel->AutoSize = true;
								classLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								classLabel->ForeColor = Color::DarkGreen;
								classLabel->Text = L"  - " + gcnew String(classID.c_str());
								infoPanel->Controls->Add(classLabel);
						   }
					  }

					  // Waiting List
					  Label^ waitingListHeader = gcnew Label();
					  waitingListHeader->AutoSize = true;
					  waitingListHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  waitingListHeader->ForeColor = Color::Navy;
					  waitingListHeader->Text = L"\nWaiting List Classes:\n";
					  infoPanel->Controls->Add(waitingListHeader);

					  if (foundUser.myWaitingList.empty()) {
						   Label^ noWaitingLabel = gcnew Label();
						   noWaitingLabel->AutoSize = true;
						   noWaitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noWaitingLabel->ForeColor = Color::DarkGreen;
						   noWaitingLabel->Text = L"  None";
						   infoPanel->Controls->Add(noWaitingLabel);
					  }
					  else {
						   for (const auto& classID : foundUser.myWaitingList) {
								Label^ waitingLabel = gcnew Label();
								waitingLabel->AutoSize = true;
								waitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								waitingLabel->ForeColor = Color::DarkGreen;
								waitingLabel->Text = L"  - " + gcnew String(classID.c_str());
								infoPanel->Controls->Add(waitingLabel);
						   }
					  }

					  // Reservations
					  Label^ reservationsHeader = gcnew Label();
					  reservationsHeader->AutoSize = true;
					  reservationsHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  reservationsHeader->ForeColor = Color::Navy;
					  reservationsHeader->Text = L"\nReserved Slots:\n";
					  infoPanel->Controls->Add(reservationsHeader);

					  if (foundUser.myReservations.empty()) {
						   Label^ noReservationsLabel = gcnew Label();
						   noReservationsLabel->AutoSize = true;
						   noReservationsLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noReservationsLabel->ForeColor = Color::DarkGreen;
						   noReservationsLabel->Text = L"  None";
						   infoPanel->Controls->Add(noReservationsLabel);
					  }
					  else {
						   int slotIndex = 1;
						   for (const auto& slot : foundUser.myReservations) {
								Label^ slotHeader = gcnew Label();
								slotHeader->AutoSize = true;
								slotHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								slotHeader->ForeColor = Color::DarkGreen;
								slotHeader->Text = String::Format(L"  Slot {0}:", slotIndex);
								infoPanel->Controls->Add(slotHeader);

								Label^ courtNameLabel = gcnew Label();
								courtNameLabel->AutoSize = true;
								courtNameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								courtNameLabel->ForeColor = Color::DarkGreen;
								courtNameLabel->Text = L"    Court Name: " + gcnew String(slot.courtName.c_str());
								infoPanel->Controls->Add(courtNameLabel);

								Label^ dateLabel = gcnew Label();
								dateLabel->AutoSize = true;
								dateLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								dateLabel->ForeColor = Color::DarkGreen;
								dateLabel->Text = L"    Date: " + gcnew String(slot.date.c_str());
								infoPanel->Controls->Add(dateLabel);

								Label^ startTimeLabel = gcnew Label();
								startTimeLabel->AutoSize = true;
								startTimeLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								startTimeLabel->ForeColor = Color::DarkGreen;
								startTimeLabel->Text = L"    Start Time: " + gcnew String(slot.startTime.c_str());
								infoPanel->Controls->Add(startTimeLabel);

								Label^ courtIDLabel = gcnew Label();
								courtIDLabel->AutoSize = true;
								courtIDLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								courtIDLabel->ForeColor = Color::DarkGreen;
								courtIDLabel->Text = L"    Court ID: " + gcnew String(slot.ID.c_str());
								infoPanel->Controls->Add(courtIDLabel);

								slotIndex++;
						   }
					  }
				 }
				 else {
					  Label^ notFoundLabel = gcnew Label();
					  notFoundLabel->AutoSize = true;
					  notFoundLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  notFoundLabel->ForeColor = Color::Red;
					  notFoundLabel->Text = L"User not found.";
					  infoPanel->Controls->Add(notFoundLabel);
				 }
			}

			void displayCoachClasses(System::String^ coachIDText, System::Windows::Forms::DataGridView^ gridView, System::Windows::Forms::Label^ infoLabel) {
				 extern unordered_map<std::string, Staff> staffList;
				 extern unordered_map<std::string, GymClasses> gymClassList;

				 System::String^ trimmedID = coachIDText->Trim();
				 gridView->Visible = false;
				 infoLabel->Visible = false;
				 gridView->Rows->Clear();
				 gridView->Columns->Clear();
				 infoLabel->Text = L"";

				 if (String::IsNullOrEmpty(trimmedID)) {
					  MessageBox::Show("Please enter a valid Coach ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }
				 std::string coachID = msclr::interop::marshal_as<std::string>(trimmedID);

				 if (staffList.empty()) {
					  MessageBox::Show("No staff data available. Please ensure staff list is populated.",
						   "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }

				 Staff foundCoach;
				 bool coachFound = false;
				 for (const auto& pair : staffList) {
					  if (pair.first == coachID &&
						   _stricmp(pair.second.role.c_str(), "coach") == 0) {
						   foundCoach = pair.second;
						   coachFound = true;
						   break;
					  }
				 }

				 if (!coachFound) {
					  bool idExists = staffList.find(coachID) != staffList.end();
					  String^ errorMsg = "Coach with ID " + trimmedID + " not found or not a coach.\n";
					  if (idExists) {
						   errorMsg += "ID exists but role is '" + gcnew String(staffList[coachID].role.c_str()) + "'. Expected 'Coach'.";
					  }
					  else {
						   errorMsg += "ID not found in staff list.";
					  }
					  errorMsg += "\nPlease verify the ID and role.";
					  MessageBox::Show(errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }

				 // Set coach information
				 infoLabel->Text = "Coach Information\n" +
					  "Name: " + gcnew String(foundCoach.name.c_str()) + "\n" +
					  "Email: " + gcnew String(foundCoach.email.c_str()) + "\n" +
					  "Phone: " + gcnew String(foundCoach.phone.c_str());

				 // Configure DataGridView columns
				 gridView->Columns->Add("ClassID", "Class ID");
				 gridView->Columns->Add("ClassName", "Class Name");
				 gridView->Columns->Add("Date", "Date");
				 gridView->Columns->Add("StartTime", "Start Time");
				 gridView->Columns->Add("EndTime", "End Time");

				 // Style DataGridView
				 gridView->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular);
				 gridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				 gridView->AllowUserToOrderColumns = false;
				 gridView->ColumnHeadersHeight = 40;
				 gridView->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Navy;
				 gridView->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
				 gridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold);
				 gridView->DefaultCellStyle->BackColor = System::Drawing::Color::White;
				 gridView->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
				 gridView->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::AliceBlue;
				 gridView->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightBlue;
				 gridView->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
				 gridView->GridColor = System::Drawing::Color::LightGray;
				 gridView->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
				 gridView->CellBorderStyle = DataGridViewCellBorderStyle::Single;
				 gridView->EnableHeadersVisualStyles = false;

				 bool hasClasses = false;
				 for (const auto& pair : gymClassList) {
					  const GymClasses& gymClass = pair.second;
					  if (gymClass.instructorID == coachID) {
						   hasClasses = true;
						   for (const auto& session : gymClass.sessions) {
								gridView->Rows->Add(
									 gcnew String(gymClass.classID.c_str()),
									 gcnew String(gymClass.className.c_str()),
									 gcnew String(session.date.c_str()),
									 gcnew String(session.startTime.c_str()),
									 gcnew String(session.endTime.c_str())
								);
						   }
					  }
				 }

				 if (!hasClasses) {
					  infoLabel->Text += "\n\nNo classes assigned to this coach.";
				 }

				 gridView->Visible = true;
				 infoLabel->Visible = true;
			}

	 private:
		  System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			   MainPg_pn->Controls->Clear();
			   MainPg_pn->Controls->Add(searchUser);
			   searchUser->BringToFront();
			   actionButton->Text = L"Delete";
			   userIDTextBox->Text = "";

		  }

		  System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			   MainPg_pn->Controls->Clear();
			   MainPg_pn->Controls->Add(searchUser);
			   searchUser->BringToFront();

			   actionButton->Text = L"Search";
			   userIDTextBox->Text = "";

		  }

		  System::Void actionButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ userIDText = userIDTextBox->Text->Trim();
			   if (String::IsNullOrEmpty(userIDText)) {
					userInfoPanel->Controls->Clear();
					Label^ errorLabel = gcnew Label();
					errorLabel->AutoSize = true;
					errorLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					errorLabel->ForeColor = Color::Red;
					errorLabel->Text = L"Please enter a user ID.";
					userInfoPanel->Controls->Add(errorLabel);

					return;
			   }

			   if (actionButton->Text == L"Delete") {
					deleteUser_and_cancelsubscription(userIDText);
					userIDTextBox->Visible = false;
					label1->Visible = false;
					actionButton->Visible = false;
					CreateCls->Visible = false;
					userInfoPanel->Visible = false;
			   }
			   else if (actionButton->Text == L"Search") {
					SearchUserByID(userIDText, userInfoPanel);
					userInfoPanel->Visible = true;

			   }


			   userIDTextBox->Clear();
		  }

		  System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			   /*if (creatClassPanel != nullptr) {
				   panel1->Controls->Remove(creatClassPanel);
				   creatClassPanel = nullptr;
			   }
			   if (creatClassFormInstance != nullptr) {
				   delete creatClassFormInstance;
				   creatClassFormInstance = nullptr;
			   }
			   userInfoPanel->Controls->Clear();
			   userIDTextBox->Visible = false;
			   label1->Visible = false;
			   actionButton->Visible = false;
			   panel1->Visible = true;
			   textBox2->Visible = true;
			   button8->Visible = true;
			   userInfoPanel->Visible = false;
			   comboBox1->Visible = false;
			   button5->Visible = false;
			   classGridView->Visible = true;
			   coachInfoLabel->Visible = true;
			   classGridView->Rows->Clear();
			   classGridView->Columns->Clear();
			   coachInfoLabel->Text = L"";
			   textBox2->Clear();*/
			   MainPg_pn->Controls->Clear();
			   MainPg_pn->Controls->Add(searchCoach);
			   MainPg_pn->Visible = true;
			   searchCoach->BringToFront();
		  }

		  System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			   userIDTextBox->Visible = false;
			   label1->Visible = false;
			   actionButton->Visible = false;
			   comboBox1->Visible = false;
			   button5->Visible = false;
			   userInfoPanel->Visible = false;
			   System::String^ coachIDText = textBox2->Text->Trim();
			   if (String::IsNullOrEmpty(coachIDText)) {
					MessageBox::Show("Please enter a valid Coach ID in the text box.",
						 "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
			   displayCoachClasses(coachIDText, classGridView, coachInfoLabel);
		  }

		  System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   MainPg_pn->Controls->Clear();
			   MainPg_pn->Controls->Add(CreateCls);
			   CreateCls->BringToFront();
			   if (creatClassPanel != nullptr) {
					CreateCls->Controls->Remove(creatClassPanel);
					creatClassPanel = nullptr;
			   }
			   if (creatClassFormInstance != nullptr) {
					delete creatClassFormInstance;
					creatClassFormInstance = nullptr;
			   }
			   creatClassFormInstance = gcnew CreatClassForm();
			   creatClassPanel = creatClassFormInstance->ClassPanel;
			   int formHeight = CreateCls->ClientSize.Height;
			   int formWidth = CreateCls->ClientSize.Width;
			   int panelHeight = 350;
			   int panelWidth = 800;
			   int verticalPosition = 163;
			   int horizontalPosition = (formWidth - panelWidth) / 2;
			   creatClassPanel->Size = System::Drawing::Size(panelWidth, panelHeight);
			   creatClassPanel->Location = System::Drawing::Point(horizontalPosition, verticalPosition);
			   CreateCls->Controls->Add(creatClassPanel);
		  }

		  System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			   /*   if (creatClassPanel != nullptr) {
					   panel1->Controls->Remove(creatClassPanel);
					   creatClassPanel = nullptr;
				  }
				  if (creatClassFormInstance != nullptr) {
					   delete creatClassFormInstance;
					   creatClassFormInstance = nullptr;
				  }
				  userInfoPanel->Controls->Clear();
				  userIDTextBox->Visible = false;
				  label1->Visible = false;
				  actionButton->Visible = false;
				  panel1->Visible = true;
				  comboBox1->Visible = true;
				  button5->Visible = true;
				  userInfoPanel->Visible = true;
				   textBox2->Visible = false;
				   button8->Visible = false;
				   classGridView->Visible = false;
				 coachInfoLabel->Visible = false;*/
			   MainPg_pn->Controls->Clear();
			   MainPg_pn->Controls->Add(Report_pn);
			   Report_pn->BringToFront();

		  }

		  System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {

			   MonthReport->Controls->Clear();



			   if (this->comboBox1->SelectedIndex == -1) {
					MessageBox::Show("Please select a month first.", "Missing Selection",
						 MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
			   }

			   String^ selectedMonth = this->comboBox1->SelectedItem->ToString();
			   int selectedYear = DateTime::Now.Year;

			   std::string selectedMonthStr = msclr::interop::marshal_as<std::string>(selectedMonth);

			   Staff newStaff;
			   std::string report = newStaff.generateMonthlyReport(selectedMonthStr, selectedYear);

			   if (!report.empty()) {
					Label^ reportLabel = gcnew Label();
					reportLabel->AutoSize = true;
					reportLabel->Font = gcnew System::Drawing::Font(L"Consolas", 10);
					reportLabel->Text = gcnew String(report.c_str());
					MonthReport->Controls->Add(reportLabel);
			   }
			   else {
					MessageBox::Show("No data available for the selected month.", "Report Empty",
						 MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   }
			   //comboBox1->Items->RemoveAt(comboBox1->SelectedIndex);
			   comboBox1->Text = "Choose a month";
		  }

		  System::Void profile_pn_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
		  System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
		  System::Void MainMenu_pn_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
		  System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
		  System::Void managertPage_Load(System::Object^ sender, System::EventArgs^ e) {
			   this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
			   if (staffList.find(loginID) != staffList.end()) {
					AccName->Text = gcnew String(staffList[loginID].name.c_str());
			   }
			   else {
					MessageBox::Show("Staff member not found for loginID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					AccName->Text = L"Unknown";
			   }

			   loadpic(pictureBox1);
			   MakePictureCircular(pictureBox1);
		  }
		  System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
		  System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	 private: System::Void LogOutbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		  LoadingPage^ loadingPage = gcnew LoadingPage();
		  loadingPage->label1->Text = "Logging out...";
		  this->Hide();
		  loadingPage->ShowDialog();
		  loginID = "";
		  this->Close();
	 }
	 };
}