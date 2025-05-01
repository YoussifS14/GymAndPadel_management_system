#pragma once
#include "Structure.h"
#include "feature_GUI/padelPN.h"
#include "feature_GUI/CancellingReserv.h"
#include "feature_GUI/GymPN.h"
#include"useraccount.h"
namespace ProjectCode {

	 using namespace System;
	 using namespace System::IO;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;
	 using namespace System::Drawing::Drawing2D;

	 /// <summary>
	 /// Summary for userPage
	 /// </summary>
	 public ref class userPage : public System::Windows::Forms::Form
	 {
	 public:
		  msclr::interop::marshal_context context;
		  userPage(void)
		  {
			   InitializeComponent();
			   //
			   //TODO: Add the constructor code here
			   //
		  }
		  Void loadpic(PictureBox^ pic)
		  {
			   string val = userList[loginID].PicPath;
			   if (val != "null")
					pic->Image = System::Drawing::Image::FromFile(gcnew String(val.c_str()));
			   else
					pic->Image = System::Drawing::Image::FromFile(gcnew String(defaultImagePath.c_str()));

		  }
		  Void removeProfilePic(String^ imagePath, PictureBox^ pic) {
			   try
			   {


					if (File::Exists(imagePath)) {
						 File::Delete(imagePath);
						 MessageBox::Show("done", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					pic->Image = System::Drawing::Image::FromFile(gcnew System::String(defaultImagePath.c_str()));

			   }
			   catch (const std::exception&)
			   {
					MessageBox::Show("error", "error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			   }
		  }
		  Void MakePictureCircular(PictureBox^ picBox) {


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
	 protected:
		  /// <summary>
		  /// Clean up any resources being used.
		  /// </summary>
		  ~userPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::Panel^ MainMenu_pn;
	 private: System::Windows::Forms::Button^ Padel;
	 protected:


	 private: System::Windows::Forms::PictureBox^ AccPic;
	 private: System::Windows::Forms::Panel^ profile_pn;
	 public: System::Windows::Forms::Label^ AccName;
	 private:

	 private: System::Windows::Forms::Panel^ MainPage;
	 private: System::Windows::Forms::Panel^ PadelPage;
	 private: System::Windows::Forms::Label^ label4;
	 private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	 private: System::Windows::Forms::Label^ label2;
	 private: System::Windows::Forms::ComboBox^ comboBox2;
	 private: System::Windows::Forms::Label^ label1;
	 private: System::Windows::Forms::ComboBox^ comboBox1;
	 private: System::Windows::Forms::Button^ searchOFcourts;
	 private: System::Windows::Forms::FlowLayoutPanel^ listOfCourts;
	 private: System::Windows::Forms::Button^ ListReserPadel;
	 private: System::Windows::Forms::Panel^ CancelPadel_pg;
	 private: System::Windows::Forms::Label^ label3;
	 private: System::Windows::Forms::FlowLayoutPanel^ ListOfMyRes;
	 private: System::Windows::Forms::Button^ GymReserv;
	 private: System::Windows::Forms::Panel^ GymClass_pg;
	 private: System::Windows::Forms::FlowLayoutPanel^ ListOfClasses;
	 private: System::Windows::Forms::Button^ button1;

	 private: System::Windows::Forms::Button^ btnWorkout;
	 private: System::Windows::Forms::Panel^ panelWorkoutContent;
	 private: System::Windows::Forms::Button^ btnHideWorkout;
	 private: System::Windows::Forms::TextBox^ textBox1;
	 private: System::Windows::Forms::Label^ lblDate;
	 private: System::Windows::Forms::Label^ lblType;
	 private: System::Windows::Forms::Label^ lblDuration;
	 private: System::Windows::Forms::Label^ lblWeight;
	 private: System::Windows::Forms::TextBox^ txtDate;
	 private: System::Windows::Forms::TextBox^ txtType;
	 private: System::Windows::Forms::TextBox^ txtDuration;
	 private: System::Windows::Forms::TextBox^ txtWeight;
	 private: System::Windows::Forms::Button^ btnAddWorkout;
	 private: System::Windows::Forms::Button^ btnViewHistory;
	 private: System::Windows::Forms::Button^ btnTrackProgress;
	 private: System::Windows::Forms::Label^ lblFilter;

	 private: System::Windows::Forms::Button^ btnFilter;
	 private: System::Windows::Forms::RichTextBox^ richTextOutput;
	 private: System::Windows::Forms::ComboBox^ comboFilterType;
private: System::Windows::Forms::Button^ button2;



	 private: System::ComponentModel::IContainer^ components;













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
			  System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userPage::typeid));
			  this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			  this->button1 = (gcnew System::Windows::Forms::Button());
			  this->GymReserv = (gcnew System::Windows::Forms::Button());
			  this->Padel = (gcnew System::Windows::Forms::Button());
			  this->btnWorkout = (gcnew System::Windows::Forms::Button());
			  this->profile_pn = (gcnew System::Windows::Forms::Panel());
			  this->ListReserPadel = (gcnew System::Windows::Forms::Button());
			  this->AccName = (gcnew System::Windows::Forms::Label());
			  this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			  this->MainPage = (gcnew System::Windows::Forms::Panel());
			  this->GymClass_pg = (gcnew System::Windows::Forms::Panel());
			  this->ListOfClasses = (gcnew System::Windows::Forms::FlowLayoutPanel());
			  this->CancelPadel_pg = (gcnew System::Windows::Forms::Panel());
			  this->label3 = (gcnew System::Windows::Forms::Label());
			  this->ListOfMyRes = (gcnew System::Windows::Forms::FlowLayoutPanel());
			  this->PadelPage = (gcnew System::Windows::Forms::Panel());
			  this->label4 = (gcnew System::Windows::Forms::Label());
			  this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			  this->label2 = (gcnew System::Windows::Forms::Label());
			  this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			  this->label1 = (gcnew System::Windows::Forms::Label());
			  this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			  this->searchOFcourts = (gcnew System::Windows::Forms::Button());
			  this->listOfCourts = (gcnew System::Windows::Forms::FlowLayoutPanel());
			  this->panelWorkoutContent = (gcnew System::Windows::Forms::Panel());
			  this->comboFilterType = (gcnew System::Windows::Forms::ComboBox());
			  this->btnHideWorkout = (gcnew System::Windows::Forms::Button());
			  this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			  this->lblDate = (gcnew System::Windows::Forms::Label());
			  this->txtDate = (gcnew System::Windows::Forms::TextBox());
			  this->lblType = (gcnew System::Windows::Forms::Label());
			  this->txtType = (gcnew System::Windows::Forms::TextBox());
			  this->lblDuration = (gcnew System::Windows::Forms::Label());
			  this->txtDuration = (gcnew System::Windows::Forms::TextBox());
			  this->lblWeight = (gcnew System::Windows::Forms::Label());
			  this->txtWeight = (gcnew System::Windows::Forms::TextBox());
			  this->btnAddWorkout = (gcnew System::Windows::Forms::Button());
			  this->btnViewHistory = (gcnew System::Windows::Forms::Button());
			  this->btnTrackProgress = (gcnew System::Windows::Forms::Button());
			  this->lblFilter = (gcnew System::Windows::Forms::Label());
			  this->btnFilter = (gcnew System::Windows::Forms::Button());
			  this->richTextOutput = (gcnew System::Windows::Forms::RichTextBox());
			  this->button2 = (gcnew System::Windows::Forms::Button());
			  this->MainMenu_pn->SuspendLayout();
			  this->profile_pn->SuspendLayout();
			  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			  this->MainPage->SuspendLayout();
			  this->GymClass_pg->SuspendLayout();
			  this->CancelPadel_pg->SuspendLayout();
			  this->PadelPage->SuspendLayout();
			  this->panelWorkoutContent->SuspendLayout();
			  this->SuspendLayout();
			  // 
			  // MainMenu_pn
			  // 
			  this->MainMenu_pn->Controls->Add(this->button2);
			  this->MainMenu_pn->Controls->Add(this->button1);
			  this->MainMenu_pn->Controls->Add(this->GymReserv);
			  this->MainMenu_pn->Controls->Add(this->Padel);
			  this->MainMenu_pn->Controls->Add(this->btnWorkout);
			  this->MainMenu_pn->Controls->Add(this->profile_pn);
			  this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			  this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			  this->MainMenu_pn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->MainMenu_pn->Name = L"MainMenu_pn";
			  this->MainMenu_pn->Size = System::Drawing::Size(235, 600);
			  this->MainMenu_pn->TabIndex = 0;
			  // 
			  // button1
			  // 
			  this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			  this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->button1->Location = System::Drawing::Point(0, 324);
			  this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->button1->Name = L"button1";
			  this->button1->Size = System::Drawing::Size(235, 54);
			  this->button1->TabIndex = 3;
			  this->button1->Text = L"Cancel Gym Class";
			  this->button1->UseVisualStyleBackColor = true;
			  this->button1->Click += gcnew System::EventHandler(this, &userPage::button1_Click);
			  // 
			  // GymReserv
			  // 
			  this->GymReserv->Dock = System::Windows::Forms::DockStyle::Top;
			  this->GymReserv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->GymReserv->Location = System::Drawing::Point(0, 270);
			  this->GymReserv->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->GymReserv->Name = L"GymReserv";
			  this->GymReserv->Size = System::Drawing::Size(235, 54);
			  this->GymReserv->TabIndex = 2;
			  this->GymReserv->Text = L"Subscribe to Gym Class";
			  this->GymReserv->UseVisualStyleBackColor = true;
			  this->GymReserv->Click += gcnew System::EventHandler(this, &userPage::GymReserv_Click);
			  // 
			  // Padel
			  // 
			  this->Padel->Dock = System::Windows::Forms::DockStyle::Top;
			  this->Padel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->Padel->Location = System::Drawing::Point(0, 216);
			  this->Padel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->Padel->Name = L"Padel";
			  this->Padel->Size = System::Drawing::Size(235, 54);
			  this->Padel->TabIndex = 1;
			  this->Padel->Text = L"Padel Court";
			  this->Padel->UseVisualStyleBackColor = true;
			  this->Padel->Click += gcnew System::EventHandler(this, &userPage::Padel_Click);
			  // 
			  // btnWorkout
			  // 
			  this->btnWorkout->Dock = System::Windows::Forms::DockStyle::Top;
			  this->btnWorkout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->btnWorkout->Location = System::Drawing::Point(0, 172);
			  this->btnWorkout->Margin = System::Windows::Forms::Padding(2);
			  this->btnWorkout->Name = L"btnWorkout";
			  this->btnWorkout->Size = System::Drawing::Size(235, 44);
			  this->btnWorkout->TabIndex = 4;
			  this->btnWorkout->Text = L"My Workout";
			  this->btnWorkout->UseVisualStyleBackColor = true;
			  this->btnWorkout->Click += gcnew System::EventHandler(this, &userPage::btnWorkout_Click);
			  // 
			  // profile_pn
			  // 
			  this->profile_pn->Controls->Add(this->ListReserPadel);
			  this->profile_pn->Controls->Add(this->AccName);
			  this->profile_pn->Controls->Add(this->AccPic);
			  this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			  this->profile_pn->Location = System::Drawing::Point(0, 0);
			  this->profile_pn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->profile_pn->Name = L"profile_pn";
			  this->profile_pn->Size = System::Drawing::Size(235, 172);
			  this->profile_pn->TabIndex = 1;
			  // 
			  // ListReserPadel
			  // 
			  this->ListReserPadel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ListReserPadel.BackgroundImage")));
			  this->ListReserPadel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			  this->ListReserPadel->Location = System::Drawing::Point(208, 10);
			  this->ListReserPadel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->ListReserPadel->Name = L"ListReserPadel";
			  this->ListReserPadel->Size = System::Drawing::Size(22, 29);
			  this->ListReserPadel->TabIndex = 2;
			  this->ListReserPadel->UseVisualStyleBackColor = true;
			  this->ListReserPadel->Click += gcnew System::EventHandler(this, &userPage::ListReserPadel_Click);
			  // 
			  // AccName
			  // 
			  this->AccName->AutoSize = true;
			  this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->AccName->Location = System::Drawing::Point(2, 142);
			  this->AccName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->AccName->Name = L"AccName";
			  this->AccName->Size = System::Drawing::Size(46, 18);
			  this->AccName->TabIndex = 1;
			  this->AccName->Text = L"label1";
			  // 
			  // AccPic
			  // 
			  this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			  this->AccPic->Location = System::Drawing::Point(28, 10);
			  this->AccPic->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->AccPic->Name = L"AccPic";
			  this->AccPic->Size = System::Drawing::Size(160, 119);
			  this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			  this->AccPic->TabIndex = 0;
			  this->AccPic->TabStop = false;
			  // 
			  // MainPage
			  // 
			  this->MainPage->Controls->Add(this->GymClass_pg);
			  this->MainPage->Controls->Add(this->CancelPadel_pg);
			  this->MainPage->Controls->Add(this->PadelPage);
			  this->MainPage->Dock = System::Windows::Forms::DockStyle::Left;
			  this->MainPage->Location = System::Drawing::Point(235, 0);
			  this->MainPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->MainPage->Name = L"MainPage";
			  this->MainPage->Size = System::Drawing::Size(718, 600);
			  this->MainPage->TabIndex = 1;
			  // 
			  // GymClass_pg
			  // 
			  this->GymClass_pg->Controls->Add(this->ListOfClasses);
			  this->GymClass_pg->Dock = System::Windows::Forms::DockStyle::Fill;
			  this->GymClass_pg->Location = System::Drawing::Point(0, 0);
			  this->GymClass_pg->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->GymClass_pg->Name = L"GymClass_pg";
			  this->GymClass_pg->Size = System::Drawing::Size(718, 600);
			  this->GymClass_pg->TabIndex = 1;
			  // 
			  // ListOfClasses
			  // 
			  this->ListOfClasses->AutoScroll = true;
			  this->ListOfClasses->Dock = System::Windows::Forms::DockStyle::Fill;
			  this->ListOfClasses->Location = System::Drawing::Point(0, 0);
			  this->ListOfClasses->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->ListOfClasses->Name = L"ListOfClasses";
			  this->ListOfClasses->Size = System::Drawing::Size(718, 600);
			  this->ListOfClasses->TabIndex = 1;
			  // 
			  // CancelPadel_pg
			  // 
			  this->CancelPadel_pg->Controls->Add(this->label3);
			  this->CancelPadel_pg->Controls->Add(this->ListOfMyRes);
			  this->CancelPadel_pg->Dock = System::Windows::Forms::DockStyle::Fill;
			  this->CancelPadel_pg->Location = System::Drawing::Point(0, 0);
			  this->CancelPadel_pg->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->CancelPadel_pg->Name = L"CancelPadel_pg";
			  this->CancelPadel_pg->Size = System::Drawing::Size(718, 600);
			  this->CancelPadel_pg->TabIndex = 0;
			  // 
			  // label3
			  // 
			  this->label3->AutoSize = true;
			  this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label3->ForeColor = System::Drawing::Color::Red;
			  this->label3->Location = System::Drawing::Point(35, 10);
			  this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->label3->Name = L"label3";
			  this->label3->Size = System::Drawing::Size(634, 58);
			  this->label3->TabIndex = 2;
			  this->label3->Text = L"You must cancel appointments at least 3 hours in advance.\n\n";
			  // 
			  // ListOfMyRes
			  // 
			  this->ListOfMyRes->AutoScroll = true;
			  this->ListOfMyRes->Dock = System::Windows::Forms::DockStyle::Bottom;
			  this->ListOfMyRes->Location = System::Drawing::Point(0, 56);
			  this->ListOfMyRes->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->ListOfMyRes->Name = L"ListOfMyRes";
			  this->ListOfMyRes->Size = System::Drawing::Size(718, 544);
			  this->ListOfMyRes->TabIndex = 1;
			  // 
			  // PadelPage
			  // 
			  this->PadelPage->Controls->Add(this->label4);
			  this->PadelPage->Controls->Add(this->dateTimePicker1);
			  this->PadelPage->Controls->Add(this->label2);
			  this->PadelPage->Controls->Add(this->comboBox2);
			  this->PadelPage->Controls->Add(this->label1);
			  this->PadelPage->Controls->Add(this->comboBox1);
			  this->PadelPage->Controls->Add(this->searchOFcourts);
			  this->PadelPage->Controls->Add(this->listOfCourts);
			  this->PadelPage->Dock = System::Windows::Forms::DockStyle::Fill;
			  this->PadelPage->Location = System::Drawing::Point(0, 0);
			  this->PadelPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->PadelPage->Name = L"PadelPage";
			  this->PadelPage->Size = System::Drawing::Size(718, 600);
			  this->PadelPage->TabIndex = 0;
			  // 
			  // label4
			  // 
			  this->label4->AutoSize = true;
			  this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label4->Location = System::Drawing::Point(138, 7);
			  this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->label4->Name = L"label4";
			  this->label4->Size = System::Drawing::Size(39, 18);
			  this->label4->TabIndex = 9;
			  this->label4->Text = L"Date";
			  // 
			  // dateTimePicker1
			  // 
			  this->dateTimePicker1->CustomFormat = L"MM/dd/yyyy";
			  this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			  this->dateTimePicker1->Location = System::Drawing::Point(130, 30);
			  this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->dateTimePicker1->MaxDate = System::DateTime(2026, 2, 28, 0, 0, 0, 0);
			  this->dateTimePicker1->Name = L"dateTimePicker1";
			  this->dateTimePicker1->Size = System::Drawing::Size(92, 23);
			  this->dateTimePicker1->TabIndex = 8;
			  this->dateTimePicker1->Value = System::DateTime(2025, 4, 16, 0, 0, 0, 0);
			  // 
			  // label2
			  // 
			  this->label2->AutoSize = true;
			  this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label2->Location = System::Drawing::Point(263, 7);
			  this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->label2->Name = L"label2";
			  this->label2->Size = System::Drawing::Size(44, 18);
			  this->label2->TabIndex = 5;
			  this->label2->Text = L"From";
			  // 
			  // comboBox2
			  // 
			  this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			  this->comboBox2->FormattingEnabled = true;
			  this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				  L"01:00", L"02:00", L"03:00", L"04:00", L"05:00",
					  L"06:00", L"07:00", L"08:00", L"09:00", L"10:00", L"11:00", L"12:00", L"16:00"
			  });
			  this->comboBox2->Location = System::Drawing::Point(266, 32);
			  this->comboBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->comboBox2->Name = L"comboBox2";
			  this->comboBox2->Size = System::Drawing::Size(56, 21);
			  this->comboBox2->TabIndex = 4;
			  // 
			  // label1
			  // 
			  this->label1->AutoSize = true;
			  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label1->Location = System::Drawing::Point(11, 7);
			  this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->label1->Name = L"label1";
			  this->label1->Size = System::Drawing::Size(60, 18);
			  this->label1->TabIndex = 3;
			  this->label1->Text = L"location";
			  // 
			  // comboBox1
			  // 
			  this->comboBox1->FormattingEnabled = true;
			  this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				  L"sheikh zayed", L"6th october", L"rehab city",
					  L"tagamoa", L"new cairo", L"naser city", L"maadi", L"madinaty"
			  });
			  this->comboBox1->Location = System::Drawing::Point(8, 32);
			  this->comboBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->comboBox1->Name = L"comboBox1";
			  this->comboBox1->Size = System::Drawing::Size(78, 21);
			  this->comboBox1->TabIndex = 2;
			  // 
			  // searchOFcourts
			  // 
			  this->searchOFcourts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->searchOFcourts->Location = System::Drawing::Point(608, 21);
			  this->searchOFcourts->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->searchOFcourts->Name = L"searchOFcourts";
			  this->searchOFcourts->Size = System::Drawing::Size(103, 31);
			  this->searchOFcourts->TabIndex = 1;
			  this->searchOFcourts->Text = L"search";
			  this->searchOFcourts->UseVisualStyleBackColor = true;
			  this->searchOFcourts->Click += gcnew System::EventHandler(this, &userPage::searchOFcourts_Click);
			  // 
			  // listOfCourts
			  // 
			  this->listOfCourts->AutoScroll = true;
			  this->listOfCourts->Dock = System::Windows::Forms::DockStyle::Bottom;
			  this->listOfCourts->Location = System::Drawing::Point(0, 56);
			  this->listOfCourts->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->listOfCourts->Name = L"listOfCourts";
			  this->listOfCourts->Size = System::Drawing::Size(718, 544);
			  this->listOfCourts->TabIndex = 0;
			  // 
			  // panelWorkoutContent
			  // 
			  this->panelWorkoutContent->Controls->Add(this->comboFilterType);
			  this->panelWorkoutContent->Controls->Add(this->btnHideWorkout);
			  this->panelWorkoutContent->Controls->Add(this->textBox1);
			  this->panelWorkoutContent->Controls->Add(this->lblDate);
			  this->panelWorkoutContent->Controls->Add(this->txtDate);
			  this->panelWorkoutContent->Controls->Add(this->lblType);
			  this->panelWorkoutContent->Controls->Add(this->txtType);
			  this->panelWorkoutContent->Controls->Add(this->lblDuration);
			  this->panelWorkoutContent->Controls->Add(this->txtDuration);
			  this->panelWorkoutContent->Controls->Add(this->lblWeight);
			  this->panelWorkoutContent->Controls->Add(this->txtWeight);
			  this->panelWorkoutContent->Controls->Add(this->btnAddWorkout);
			  this->panelWorkoutContent->Controls->Add(this->btnViewHistory);
			  this->panelWorkoutContent->Controls->Add(this->btnTrackProgress);
			  this->panelWorkoutContent->Controls->Add(this->lblFilter);
			  this->panelWorkoutContent->Controls->Add(this->btnFilter);
			  this->panelWorkoutContent->Controls->Add(this->richTextOutput);
			  this->panelWorkoutContent->Location = System::Drawing::Point(3, 3);
			  this->panelWorkoutContent->Name = L"panelWorkoutContent";
			  this->panelWorkoutContent->Size = System::Drawing::Size(715, 514);
			  this->panelWorkoutContent->TabIndex = 0;
			  this->panelWorkoutContent->Visible = false;
			  // 
			  // comboFilterType
			  // 
			  this->comboFilterType->FormattingEnabled = true;
			  this->comboFilterType->Location = System::Drawing::Point(109, 230);
			  this->comboFilterType->Name = L"comboFilterType";
			  this->comboFilterType->Size = System::Drawing::Size(195, 21);
			  this->comboFilterType->TabIndex = 16;
			  // 
			  // btnHideWorkout
			  // 
			  this->btnHideWorkout->Location = System::Drawing::Point(565, 3);
			  this->btnHideWorkout->Name = L"btnHideWorkout";
			  this->btnHideWorkout->Size = System::Drawing::Size(150, 30);
			  this->btnHideWorkout->TabIndex = 0;
			  this->btnHideWorkout->Text = L"Back";
			  this->btnHideWorkout->Click += gcnew System::EventHandler(this, &userPage::btnHideWorkout_Click);
			  // 
			  // textBox1
			  // 
			  this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			  this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			  this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			  this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			  this->textBox1->Location = System::Drawing::Point(11, 12);
			  this->textBox1->Name = L"textBox1";
			  this->textBox1->Size = System::Drawing::Size(145, 21);
			  this->textBox1->TabIndex = 0;
			  this->textBox1->Text = L"Workout";
			  // 
			  // lblDate
			  // 
			  this->lblDate->Location = System::Drawing::Point(20, 50);
			  this->lblDate->Name = L"lblDate";
			  this->lblDate->Size = System::Drawing::Size(100, 23);
			  this->lblDate->TabIndex = 1;
			  this->lblDate->Text = L"Date:";
			  // 
			  // txtDate
			  // 
			  this->txtDate->Location = System::Drawing::Point(120, 50);
			  this->txtDate->Name = L"txtDate";
			  this->txtDate->Size = System::Drawing::Size(200, 20);
			  this->txtDate->TabIndex = 2;
			  // 
			  // lblType
			  // 
			  this->lblType->Location = System::Drawing::Point(20, 80);
			  this->lblType->Name = L"lblType";
			  this->lblType->Size = System::Drawing::Size(100, 23);
			  this->lblType->TabIndex = 3;
			  this->lblType->Text = L"Workout Type:";
			  // 
			  // txtType
			  // 
			  this->txtType->Location = System::Drawing::Point(120, 80);
			  this->txtType->Name = L"txtType";
			  this->txtType->Size = System::Drawing::Size(200, 20);
			  this->txtType->TabIndex = 4;
			  // 
			  // lblDuration
			  // 
			  this->lblDuration->Location = System::Drawing::Point(20, 110);
			  this->lblDuration->Name = L"lblDuration";
			  this->lblDuration->Size = System::Drawing::Size(100, 23);
			  this->lblDuration->TabIndex = 5;
			  this->lblDuration->Text = L"Duration (min):";
			  // 
			  // txtDuration
			  // 
			  this->txtDuration->Location = System::Drawing::Point(120, 110);
			  this->txtDuration->Name = L"txtDuration";
			  this->txtDuration->Size = System::Drawing::Size(200, 20);
			  this->txtDuration->TabIndex = 6;
			  // 
			  // lblWeight
			  // 
			  this->lblWeight->Location = System::Drawing::Point(20, 140);
			  this->lblWeight->Name = L"lblWeight";
			  this->lblWeight->Size = System::Drawing::Size(100, 23);
			  this->lblWeight->TabIndex = 7;
			  this->lblWeight->Text = L"Weight (kg):";
			  // 
			  // txtWeight
			  // 
			  this->txtWeight->Location = System::Drawing::Point(120, 140);
			  this->txtWeight->Name = L"txtWeight";
			  this->txtWeight->Size = System::Drawing::Size(200, 20);
			  this->txtWeight->TabIndex = 8;
			  // 
			  // btnAddWorkout
			  // 
			  this->btnAddWorkout->Location = System::Drawing::Point(20, 180);
			  this->btnAddWorkout->Name = L"btnAddWorkout";
			  this->btnAddWorkout->Size = System::Drawing::Size(150, 30);
			  this->btnAddWorkout->TabIndex = 9;
			  this->btnAddWorkout->Text = L"Add Workout";
			  this->btnAddWorkout->Click += gcnew System::EventHandler(this, &userPage::btnAddWorkout_Click);
			  // 
			  // btnViewHistory
			  // 
			  this->btnViewHistory->Location = System::Drawing::Point(180, 180);
			  this->btnViewHistory->Name = L"btnViewHistory";
			  this->btnViewHistory->Size = System::Drawing::Size(150, 30);
			  this->btnViewHistory->TabIndex = 10;
			  this->btnViewHistory->Text = L"View History";
			  this->btnViewHistory->Click += gcnew System::EventHandler(this, &userPage::btnViewHistory_Click);
			  // 
			  // btnTrackProgress
			  // 
			  this->btnTrackProgress->Location = System::Drawing::Point(340, 180);
			  this->btnTrackProgress->Name = L"btnTrackProgress";
			  this->btnTrackProgress->Size = System::Drawing::Size(150, 30);
			  this->btnTrackProgress->TabIndex = 11;
			  this->btnTrackProgress->Text = L"Track Progress";
			  this->btnTrackProgress->Click += gcnew System::EventHandler(this, &userPage::btnTrackProgress_Click);
			  // 
			  // lblFilter
			  // 
			  this->lblFilter->Location = System::Drawing::Point(20, 230);
			  this->lblFilter->Name = L"lblFilter";
			  this->lblFilter->Size = System::Drawing::Size(100, 23);
			  this->lblFilter->TabIndex = 12;
			  this->lblFilter->Text = L"Filter by Type:";
			  // 
			  // btnFilter
			  // 
			  this->btnFilter->Location = System::Drawing::Point(340, 230);
			  this->btnFilter->Name = L"btnFilter";
			  this->btnFilter->Size = System::Drawing::Size(100, 23);
			  this->btnFilter->TabIndex = 14;
			  this->btnFilter->Text = L"Filter";
			  this->btnFilter->Click += gcnew System::EventHandler(this, &userPage::btnFilter_Click);
			  // 
			  // richTextOutput
			  // 
			  this->richTextOutput->Location = System::Drawing::Point(20, 270);
			  this->richTextOutput->Name = L"richTextOutput";
			  this->richTextOutput->ReadOnly = true;
			  this->richTextOutput->Size = System::Drawing::Size(670, 200);
			  this->richTextOutput->TabIndex = 15;
			  this->richTextOutput->Text = L"";
			  // 
			  // button2
			  // 
			  this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			  this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->button2->Location = System::Drawing::Point(0, 378);
			  this->button2->Margin = System::Windows::Forms::Padding(2);
			  this->button2->Name = L"button2";
			  this->button2->Size = System::Drawing::Size(235, 44);
			  this->button2->TabIndex = 5;
			  this->button2->Text = L"My Account";
			  this->button2->UseVisualStyleBackColor = true;
			  this->button2->Click += gcnew System::EventHandler(this, &userPage::button2_Click);
			  // 
			  // userPage
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->ClientSize = System::Drawing::Size(955, 600);
			  this->Controls->Add(this->MainPage);
			  this->Controls->Add(this->MainMenu_pn);
			  this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->Name = L"userPage";
			  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			  this->Text = L"userPage";
			  this->Load += gcnew System::EventHandler(this, &userPage::userPage_Load);
			  this->MainMenu_pn->ResumeLayout(false);
			  this->profile_pn->ResumeLayout(false);
			  this->profile_pn->PerformLayout();
			  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			  this->MainPage->ResumeLayout(false);
			  this->GymClass_pg->ResumeLayout(false);
			  this->CancelPadel_pg->ResumeLayout(false);
			  this->CancelPadel_pg->PerformLayout();
			  this->PadelPage->ResumeLayout(false);
			  this->PadelPage->PerformLayout();
			  this->panelWorkoutContent->ResumeLayout(false);
			  this->panelWorkoutContent->PerformLayout();
			  this->ResumeLayout(false);

		  }
#pragma endregion
	 private: System::Void searchOFcourts_Click(System::Object^ sender, System::EventArgs^ e) {

		  listOfCourts->Controls->Clear();
		  if (comboBox1->SelectedItem == nullptr || comboBox2->SelectedItem == nullptr) {
			   MessageBox::Show("Please select a location and time.");
			   return;
		  }
		  String^ location = comboBox1->SelectedItem->ToString();
		  String^ time = comboBox2->SelectedItem->ToString();
		  String^ date = dateTimePicker1->Value.ToString("MM/dd/yyyy");
		  Slot s;
		  MessageBox::Show("date: " + date + "\nlocation: " + location + "\ntime: " + time);
		  s.date = context.marshal_as<std::string>(date);
		  s.startTime = context.marshal_as<std::string>(time);

		  //  s.endTime = context.marshal_as<std::string>(time);

		  auto it = courtList.begin();
		  for (; it != courtList.end(); it++) {
			   PadelCourt co = it->second;
			   bool exists = false;
			   if (co.location == context.marshal_as<std::string>(location)) {
					if (co.slots.size() == 0) {
						 exists = false;
					}
					else {
						 for (const Slot& slo : co.slots) {
							  if (slo.date == s.date && slo.startTime == s.startTime) {
								   exists = true;
								   break;
							  }
						 }
					}
					if (!exists) {
						 padelPN^ court = gcnew padelPN();
						 court->courtName->Text += gcnew String(co.name.c_str());
						 court->courtLoc->Text += gcnew String(co.location.c_str());
						 court->courtPrice->Text += co.price.ToString();
						 court->courtDate->Text += gcnew String(s.date.c_str());
						 court->courtDate->Tag += gcnew String(s.startTime.c_str());


						 listOfCourts->Controls->Add(court);
					}
			   }
		  }
		  if (listOfCourts->Controls->Count == 0) {
			   MessageBox::Show("No available courts found for the selected date and time.\nYou can check another time.");
		  }
	 }

	 private: System::Void ListReserPadel_Click(System::Object^ sender, System::EventArgs^ e) {
		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(CancelPadel_pg);
		  CancelPadel_pg->BringToFront();
		  ListOfMyRes->Controls->Clear();
		  for (int i = 0; i < userList[loginID].myReservations.size(); i++) {
			   CancellingReserv^ res = gcnew CancellingReserv();
			   res->courtName->Text += gcnew String(userList[loginID].myReservations[i].courtName.c_str());
			   res->courtName->Tag = gcnew String(userList[loginID].myReservations[i].ID.c_str());
			   res->ReservDate->Text += gcnew String(userList[loginID].myReservations[i].date.c_str());
			   res->StartingTime->Text += gcnew String(userList[loginID].myReservations[i].startTime.c_str());
			   if (userList[loginID].myReservations[i].date == User::getCurrentDate_MM_DD_YYYY()) {
					int hourDiff = User::getHourDifferenceFromNow(userList[loginID].myReservations[i].startTime);
					if (hourDiff < 3)
						 res->Cancelling_btn->Enabled = false;

			   }if (userList[loginID].myReservations[i].date < User::getCurrentDate_MM_DD_YYYY()) {
					res->Cancelling_btn->Enabled = false;
					res->Warning->Text = "This reservation is expired";
			   }
			   ListOfMyRes->Controls->Add(res);
		  }
	 }
	 private: System::Void Padel_Click(System::Object^ sender, System::EventArgs^ e) {
		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(PadelPage);
		  PadelPage->BringToFront();
		  comboBox1->SelectedIndex = -1;
		  comboBox2->SelectedIndex = -1;
		  listOfCourts->Controls->Clear();
		  dateTimePicker1->Value = System::DateTime::Now;
		  comboBox1->SelectedIndex = 0;
		  comboBox2->SelectedIndex = 0;
	 }
	 private: System::Void GymReserv_Click(System::Object^ sender, System::EventArgs^ e) {
		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(GymClass_pg);
		  GymClass_pg->BringToFront();
		  ListOfClasses->Controls->Clear();
		  auto it = gymClassList.begin();
		  for (; it != gymClassList.end(); it++) {

			   GymPN^ class1 = gcnew GymPN(true);
			   if (userList[loginID].isClassReserved(it->first) || userList[loginID].isClassWaiting(it->first))
					continue;
			   class1->CName->Text += gcnew String(it->second.className.c_str());
			   class1->CName->Tag = gcnew String(it->second.classID.c_str());
			   class1->CInstructor->Text += gcnew String(it->second.instructor.c_str());
			   class1->CPrice->Text += it->second.price.ToString();
			   class1->CStart->Text += gcnew String(it->second.startDate.c_str());
			   class1->CEnd->Text += gcnew String(it->second.endDate.c_str());
			   if (it->second.getDaysDifference() >= 15)
					class1->Reserv_btn->Enabled = false;
			   ListOfClasses->Controls->Add(class1);
		  }
	 }
	 private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(GymClass_pg);
		  GymClass_pg->BringToFront();
		  ListOfClasses->Controls->Clear();

		  auto it = userList[loginID].myClasses.begin(); // list contain gym class key

		  if (it == userList[loginID].myClasses.end()) {
			   MessageBox::Show("No classes found for this user.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   return;
		  }
		  while (it != userList[loginID].myClasses.end()) {
			   GymPN^ class1 = gcnew GymPN(false);
			   class1->CName->Text += gcnew String(gymClassList[*it].className.c_str());
			   class1->CName->Tag = gcnew String(gymClassList[*it].classID.c_str());
			   class1->CInstructor->Text += gcnew String(gymClassList[*it].instructor.c_str());
			   class1->CPrice->Text += gymClassList[*it].price.ToString();
			   class1->CStart->Text += gcnew String(gymClassList[*it].startDate.c_str());
			   class1->CEnd->Text += gcnew String(gymClassList[*it].endDate.c_str());
			   class1->label1->Text = "Reserved";
			   class1->label1->ForeColor = System::Drawing::Color::Green;
			   if (gymClassList[*it].getDaysDifference() >= 15)
					class1->cancelling_btn->Enabled = false;
			   ListOfClasses->Controls->Add(class1);
			   it++;
		  }
		  for (auto itWait = userList[loginID].myWaitingList.begin(); itWait != userList[loginID].myWaitingList.end(); itWait++) {
			   GymPN^ class1 = gcnew GymPN(false);
			   class1->CName->Text += gcnew String(gymClassList[*itWait].className.c_str());
			   class1->CName->Tag = gcnew String(gymClassList[*itWait].classID.c_str());
			   class1->CInstructor->Text += gcnew String(gymClassList[*itWait].instructor.c_str());
			   class1->CPrice->Text += gymClassList[*itWait].price.ToString();
			   class1->CStart->Text += gcnew String(gymClassList[*itWait].startDate.c_str());
			   class1->CEnd->Text += gcnew String(gymClassList[*itWait].endDate.c_str());
			   class1->label1->Text = "Waiting";
			   class1->label1->ForeColor = System::Drawing::Color::Orange;
			   if (gymClassList[*itWait].getDaysDifference() >= 15)
					class1->cancelling_btn->Enabled = false;
			   ListOfClasses->Controls->Add(class1);
		  }


	 }

	 private: System::Void btnWorkout_Click(System::Object^ sender, System::EventArgs^ e) {

		  MainPage->Controls->Clear();

		  MainPage->Controls->Add(panelWorkoutContent);
		  panelWorkoutContent->Visible = true;
		  panelWorkoutContent->BringToFront();
	 }

	 private: System::Void btnHideWorkout_Click(System::Object^ sender, System::EventArgs^ e) {
		  panelWorkoutContent->Visible = false;
		  richTextOutput->Clear();
	 }

	 private: System::Void btnAddWorkout_Click(System::Object^ sender, System::EventArgs^ e) {


		  // Get input values
		  String^ date = txtDate->Text;
		  String^ type = txtType->Text;
		  String^ duration = txtDuration->Text;
		  String^ weight = txtWeight->Text;


		  if (String::IsNullOrEmpty(date) || String::IsNullOrEmpty(type) ||
			   String::IsNullOrEmpty(duration) || String::IsNullOrEmpty(weight)) {
			   MessageBox::Show("Please fill in all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }


		  int workoutDuration;
		  int bodyWeight;
		  try {
			   workoutDuration = System::Convert::ToInt32(duration);
			   bodyWeight = System::Convert::ToInt32(weight);

			   if (workoutDuration <= 0) {
					MessageBox::Show("Duration must be a positive number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
			   if (bodyWeight <= 0) {
					MessageBox::Show("Weight must be a positive number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
		  }
		  catch (System::FormatException^) {
			   MessageBox::Show("Please enter valid numbers for duration and weight", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }


		  workoutManager.loadFromFile("Data/workouts.csv", userList);

		  string workoutDate = context.marshal_as<std::string>(date);
		  string workoutType = context.marshal_as<std::string>(type);


		  int calories = workoutManager.calcCalories(userList[loginID], workoutDuration, workoutType, bodyWeight);

		  Workout newWorkout(workoutDate, workoutType, workoutDuration, calories);
		  workoutManager.recordWorkout(userList[loginID].ID, newWorkout);


		  workoutManager.saveToFile("Data/workouts.csv");


		  MessageBox::Show(
			   String::Format("Workout added successfully!\n\nDate: {0}\nType: {1}\nDuration: {2} minutes\nCalories Burned: {3} kcal",
					date, type, workoutDuration, calories),
			   "Success",
			   MessageBoxButtons::OK,
			   MessageBoxIcon::Information
		  );


		  txtDate->Clear();
		  txtType->Clear();
		  txtDuration->Clear();
		  txtWeight->Clear();
	 }

	 private: System::Void btnViewHistory_Click(System::Object^ sender, System::EventArgs^ e) {

		  richTextOutput->Clear();

		  workoutManager.loadFromFile("Data/workouts.csv", userList);

		  auto it = workoutManager.getWorkoutData().find(userList[loginID].ID);

		  if (it == workoutManager.getWorkoutData().end() || it->second.empty()) {
			   richTextOutput->AppendText("NO WORKOUT HISTORY FOR USER: " + gcnew String(userList[loginID].ID.c_str()) + "\n");
			   return;
		  }

		  richTextOutput->AppendText("Workout History For User " + gcnew String(userList[loginID].name.c_str()) + "\n\n");

		  richTextOutput->AppendText("Date\t\tType\t\tDuration\tCalories\n");
		  richTextOutput->AppendText("------------------------------------------------\n");

		  for (auto workoutIt = it->second.begin(); workoutIt != it->second.end(); workoutIt++) {
			   richTextOutput->AppendText(
					"Date: " + gcnew String(workoutIt->date.c_str()) + "\n" +
					"Type: " + gcnew String(workoutIt->type.c_str()) + "\n" +
					"Duration: " + workoutIt->duration + " minutes\n" +
					"Calories Burned: " + workoutIt->caloriesBurned + " kcal\n\n"
			   );
		  }


		  richTextOutput->SelectionStart = 0;
		  richTextOutput->SelectionLength = richTextOutput->TextLength;
		  richTextOutput->SelectionFont = gcnew System::Drawing::Font("Consolas", 10);

	 }


	 private: System::Void btnTrackProgress_Click(System::Object^ sender, System::EventArgs^ e) {

		  richTextOutput->Clear();

		  auto it = workoutManager.getWorkoutData().find(userList[loginID].ID);
		  if (it == workoutManager.getWorkoutData().end() || it->second.empty()) {
			   richTextOutput->AppendText("NO PROGRESS TO TRACK FOR USER: " + gcnew String(userList[loginID].ID.c_str()) + "\n");
			   return;
		  }

		  int totalCalories = 0;
		  int totalDuration = 0;

		  for (auto workoutIt = it->second.begin(); workoutIt != it->second.end(); workoutIt++) {
			   totalCalories += workoutIt->caloriesBurned;
			   totalDuration += workoutIt->duration;
		  }

		  // Display summary
		  richTextOutput->AppendText("Track Progress for User: " + gcnew String(userList[loginID].name.c_str()) + "\n\n");
		  richTextOutput->AppendText("Total workouts: " + it->second.size() + "\n");
		  richTextOutput->AppendText("Total duration: " + totalDuration + " minutes\n");
		  richTextOutput->AppendText("Total calories burned: " + totalCalories + " kcal\n");




	 }


	 private: System::Void btnFilter_Click(System::Object^ sender, System::EventArgs^ e) {

		  richTextOutput->Clear();

		  String^ selectedWorkoutType = comboFilterType->SelectedItem != nullptr
			   ? comboFilterType->SelectedItem->ToString()
			   : nullptr;

		  if (String::IsNullOrEmpty(selectedWorkoutType)) {
			   MessageBox::Show("Please select a workout type to filter.", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }


		  string type;
		  try {
			   type = msclr::interop::marshal_as<std::string>(selectedWorkoutType);


			   transform(type.begin(), type.end(), type.begin(), ::tolower);
		  }
		  catch (System::Exception^ ex) {
			   MessageBox::Show("Error processing workout type: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  for (size_t i = 0; i < type.length(); ++i) {
			   type[i] = std::tolower(type[i]);
		  }
		  type.erase(remove(type.begin(), type.end(), ' '), type.end());


		  try {
			   // Access the workout data
			   auto& workoutData = workoutManager.getWorkoutData();
			   auto it = workoutData.find(userList[loginID].ID);

			   if (it == workoutData.end() || it->second.empty()) {
					richTextOutput->AppendText("No workouts available for user: " +
						 gcnew String(userList[loginID].ID.c_str()) + "\n");
					return;
			   }

			   richTextOutput->AppendText("Filtered Workouts (Type: " + selectedWorkoutType + ")\n\n");

			   bool found = false;
			   for (const auto& workout : it->second) {
					string workoutType = workout.type;
					transform(workoutType.begin(), workoutType.end(), workoutType.begin(), ::tolower);
					workoutType.erase(remove(workoutType.begin(), workoutType.end(), ' '), workoutType.end());

					Console::WriteLine("Workout Type in file: '{0}'", gcnew String(workout.type.c_str()));

					if (workoutType == type) {
						 richTextOutput->AppendText(
							  "Date: " + gcnew String(workout.date.c_str()) + "\n" +
							  "Type: " + gcnew String(workout.type.c_str()) + "\n" +
							  "Duration: " + workout.duration.ToString() + " minutes\n" +
							  "Calories Burned: " + workout.caloriesBurned.ToString("F1") + " kcal\n" +
							  "------------------------\n"
						 );
						 found = true;
					}
			   }

			   if (!found) {
					MessageBox::Show("No workouts found for type: " + selectedWorkoutType,
						 "No Results", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
		  }
		  catch (const std::exception& ex) {
			   MessageBox::Show("Error retrieving workout data: " + gcnew String(ex.what()), "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
		  }

	 }

	 private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		 useraccount^ useraccountPage = gcnew useraccount();
		 this->Hide();
		 useraccountPage->ShowDialog();
		 this->Show();

	 }


	 private: System::Void userPage_Load(System::Object^ sender, System::EventArgs^ e) {
		  loadpic(AccPic);
		  MakePictureCircular(AccPic);
	 }
	 };
}
