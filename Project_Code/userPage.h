#pragma once
#include "Structure.h"
#include "feature_GUI/padelPN.h"
#include "feature_GUI/CancellingReserv.h"
#include "feature_GUI/GymPN.h"
#include"useraccount.h"
#include "MSGsShow.h"
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
	 private: System::Windows::Forms::ToolTip^ toolTip1;
	 private: System::Windows::Forms::Button^ logout_btn;
	 private: System::Windows::Forms::Button^ button3;
	 private: System::Windows::Forms::Panel^ RenewPG;
	 private: System::Windows::Forms::Button^ button4;
	 private: System::Windows::Forms::RichTextBox^ richTextBox1;
	 private: System::Windows::Forms::CheckBox^ checkBox1;
	 private: System::Windows::Forms::RadioButton^ SixMradioButton;
	 private: System::Windows::Forms::Label^ ChooseSublabel;
	 private: System::Windows::Forms::RadioButton^ OneYradioButton;
	 private: System::Windows::Forms::RadioButton^ OneMradioButton;
	 private: System::Windows::Forms::RadioButton^ ThreeMradioButton;
	 public: System::Windows::Forms::Label^ Wallet;
	 private: System::Windows::Forms::Button^ button5;
	 private: System::Windows::Forms::Timer^ delayedRenewTimer;



	 public:


	 private:





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
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userPage::typeid));
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->logout_btn = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->GymReserv = (gcnew System::Windows::Forms::Button());
			   this->Padel = (gcnew System::Windows::Forms::Button());
			   this->btnWorkout = (gcnew System::Windows::Forms::Button());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->Wallet = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->ListReserPadel = (gcnew System::Windows::Forms::Button());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainPage = (gcnew System::Windows::Forms::Panel());
			   this->RenewPG = (gcnew System::Windows::Forms::Panel());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->SixMradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->ChooseSublabel = (gcnew System::Windows::Forms::Label());
			   this->OneYradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->OneMradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->ThreeMradioButton = (gcnew System::Windows::Forms::RadioButton());
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
			   this->GymClass_pg = (gcnew System::Windows::Forms::Panel());
			   this->ListOfClasses = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->CancelPadel_pg = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->ListOfMyRes = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			   this->delayedRenewTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->MainPage->SuspendLayout();
			   this->RenewPG->SuspendLayout();
			   this->PadelPage->SuspendLayout();
			   this->panelWorkoutContent->SuspendLayout();
			   this->GymClass_pg->SuspendLayout();
			   this->CancelPadel_pg->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->BackColor = System::Drawing::Color::Gray;
			   this->MainMenu_pn->Controls->Add(this->button3);
			   this->MainMenu_pn->Controls->Add(this->logout_btn);
			   this->MainMenu_pn->Controls->Add(this->button1);
			   this->MainMenu_pn->Controls->Add(this->GymReserv);
			   this->MainMenu_pn->Controls->Add(this->Padel);
			   this->MainMenu_pn->Controls->Add(this->btnWorkout);
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(313, 738);
			   this->MainMenu_pn->TabIndex = 0;
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::White;
			   this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(0, 456);
			   this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(313, 66);
			   this->button3->TabIndex = 6;
			   this->button3->Text = L"Renew my subscription";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &userPage::button3_Click);
			   // 
			   // logout_btn
			   // 
			   this->logout_btn->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->logout_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->logout_btn->Location = System::Drawing::Point(0, 672);
			   this->logout_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->logout_btn->Name = L"logout_btn";
			   this->logout_btn->Size = System::Drawing::Size(313, 66);
			   this->logout_btn->TabIndex = 5;
			   this->logout_btn->Text = L"log out";
			   this->logout_btn->UseVisualStyleBackColor = true;
			   this->logout_btn->Click += gcnew System::EventHandler(this, &userPage::logout_btn_Click);
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::White;
			   this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(0, 390);
			   this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(313, 66);
			   this->button1->TabIndex = 3;
			   this->button1->Text = L"Cancel Gym Class";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &userPage::button1_Click);
			   // 
			   // GymReserv
			   // 
			   this->GymReserv->BackColor = System::Drawing::Color::White;
			   this->GymReserv->Dock = System::Windows::Forms::DockStyle::Top;
			   this->GymReserv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->GymReserv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->GymReserv->Location = System::Drawing::Point(0, 324);
			   this->GymReserv->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->GymReserv->Name = L"GymReserv";
			   this->GymReserv->Size = System::Drawing::Size(313, 66);
			   this->GymReserv->TabIndex = 2;
			   this->GymReserv->Text = L"Subscribe to Gym Class";
			   this->GymReserv->UseVisualStyleBackColor = false;
			   this->GymReserv->Click += gcnew System::EventHandler(this, &userPage::GymReserv_Click);
			   // 
			   // Padel
			   // 
			   this->Padel->BackColor = System::Drawing::Color::White;
			   this->Padel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->Padel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Padel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Padel->Location = System::Drawing::Point(0, 258);
			   this->Padel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Padel->Name = L"Padel";
			   this->Padel->Size = System::Drawing::Size(313, 66);
			   this->Padel->TabIndex = 1;
			   this->Padel->Text = L"Padel Court";
			   this->Padel->UseVisualStyleBackColor = false;
			   this->Padel->Click += gcnew System::EventHandler(this, &userPage::Padel_Click);
			   // 
			   // btnWorkout
			   // 
			   this->btnWorkout->BackColor = System::Drawing::Color::White;
			   this->btnWorkout->Dock = System::Windows::Forms::DockStyle::Top;
			   this->btnWorkout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnWorkout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->btnWorkout->Location = System::Drawing::Point(0, 204);
			   this->btnWorkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnWorkout->Name = L"btnWorkout";
			   this->btnWorkout->Size = System::Drawing::Size(313, 54);
			   this->btnWorkout->TabIndex = 4;
			   this->btnWorkout->Text = L"My Workout";
			   this->btnWorkout->UseVisualStyleBackColor = false;
			   this->btnWorkout->Click += gcnew System::EventHandler(this, &userPage::btnWorkout_Click);
			   // 
			   // profile_pn
			   // 
			   this->profile_pn->Controls->Add(this->button5);
			   this->profile_pn->Controls->Add(this->Wallet);
			   this->profile_pn->Controls->Add(this->button2);
			   this->profile_pn->Controls->Add(this->ListReserPadel);
			   this->profile_pn->Controls->Add(this->AccName);
			   this->profile_pn->Controls->Add(this->AccPic);
			   this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			   this->profile_pn->Location = System::Drawing::Point(0, 0);
			   this->profile_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(313, 204);
			   this->profile_pn->TabIndex = 1;
			   // 
			   // button5
			   // 
			   this->button5->BackColor = System::Drawing::Color::Transparent;
			   this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			   this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->button5->FlatAppearance->BorderSize = 0;
			   this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button5->Location = System::Drawing::Point(5, 11);
			   this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(36, 36);
			   this->button5->TabIndex = 7;
			   this->button5->UseVisualStyleBackColor = false;
			   this->button5->Click += gcnew System::EventHandler(this, &userPage::button5_Click);
			   // 
			   // Wallet
			   // 
			   this->Wallet->AutoSize = true;
			   this->Wallet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Wallet->ForeColor = System::Drawing::Color::White;
			   this->Wallet->Location = System::Drawing::Point(3, 177);
			   this->Wallet->Name = L"Wallet";
			   this->Wallet->Size = System::Drawing::Size(58, 22);
			   this->Wallet->TabIndex = 6;
			   this->Wallet->Text = L"label1";
			   // 
			   // button2
			   // 
			   this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			   this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->button2->Location = System::Drawing::Point(271, 14);
			   this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(36, 38);
			   this->button2->TabIndex = 5;
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &userPage::button2_Click);
			   // 
			   // ListReserPadel
			   // 
			   this->ListReserPadel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ListReserPadel.BackgroundImage")));
			   this->ListReserPadel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ListReserPadel->Location = System::Drawing::Point(271, 57);
			   this->ListReserPadel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->ListReserPadel->Name = L"ListReserPadel";
			   this->ListReserPadel->Size = System::Drawing::Size(36, 36);
			   this->ListReserPadel->TabIndex = 2;
			   this->ListReserPadel->UseVisualStyleBackColor = true;
			   this->ListReserPadel->Click += gcnew System::EventHandler(this, &userPage::ListReserPadel_Click);
			   // 
			   // AccName
			   // 
			   this->AccName->AutoSize = true;
			   this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->AccName->ForeColor = System::Drawing::Color::White;
			   this->AccName->Location = System::Drawing::Point(3, 148);
			   this->AccName->Name = L"AccName";
			   this->AccName->Size = System::Drawing::Size(58, 22);
			   this->AccName->TabIndex = 1;
			   this->AccName->Text = L"label1";
			   // 
			   // AccPic
			   // 
			   this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			   this->AccPic->Location = System::Drawing::Point(47, 9);
			   this->AccPic->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->AccPic->Name = L"AccPic";
			   this->AccPic->Size = System::Drawing::Size(196, 130);
			   this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->AccPic->TabIndex = 0;
			   this->AccPic->TabStop = false;
			   // 
			   // MainPage
			   // 
			   this->MainPage->Controls->Add(this->RenewPG);
			   this->MainPage->Controls->Add(this->PadelPage);
			   this->MainPage->Controls->Add(this->panelWorkoutContent);
			   this->MainPage->Controls->Add(this->GymClass_pg);
			   this->MainPage->Controls->Add(this->CancelPadel_pg);
			   this->MainPage->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainPage->Location = System::Drawing::Point(313, 0);
			   this->MainPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MainPage->Name = L"MainPage";
			   this->MainPage->Size = System::Drawing::Size(957, 738);
			   this->MainPage->TabIndex = 1;
			   // 
			   // RenewPG
			   // 
			   this->RenewPG->Controls->Add(this->richTextBox1);
			   this->RenewPG->Controls->Add(this->checkBox1);
			   this->RenewPG->Controls->Add(this->button4);
			   this->RenewPG->Controls->Add(this->SixMradioButton);
			   this->RenewPG->Controls->Add(this->ChooseSublabel);
			   this->RenewPG->Controls->Add(this->OneYradioButton);
			   this->RenewPG->Controls->Add(this->OneMradioButton);
			   this->RenewPG->Controls->Add(this->ThreeMradioButton);
			   this->RenewPG->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->RenewPG->Location = System::Drawing::Point(0, 0);
			   this->RenewPG->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->RenewPG->Name = L"RenewPG";
			   this->RenewPG->Size = System::Drawing::Size(957, 738);
			   this->RenewPG->TabIndex = 2;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->BackColor = System::Drawing::SystemColors::Menu;
			   this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			   this->richTextBox1->Location = System::Drawing::Point(88, 262);
			   this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->ReadOnly = true;
			   this->richTextBox1->Size = System::Drawing::Size(768, 159);
			   this->richTextBox1->TabIndex = 14;
			   this->richTextBox1->Text = L"";
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			   this->checkBox1->Location = System::Drawing::Point(431, 231);
			   this->checkBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(60, 24);
			   this->checkBox1->TabIndex = 13;
			   this->checkBox1->Text = L"VIP";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   // 
			   // button4
			   // 
			   this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 25.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->button4->Location = System::Drawing::Point(355, 571);
			   this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(211, 62);
			   this->button4->TabIndex = 0;
			   this->button4->Text = L"Pay";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &userPage::button4_Click);
			   // 
			   // SixMradioButton
			   // 
			   this->SixMradioButton->AutoSize = true;
			   this->SixMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->SixMradioButton->Location = System::Drawing::Point(493, 177);
			   this->SixMradioButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->SixMradioButton->Name = L"SixMradioButton";
			   this->SixMradioButton->Size = System::Drawing::Size(104, 29);
			   this->SixMradioButton->TabIndex = 12;
			   this->SixMradioButton->TabStop = true;
			   this->SixMradioButton->Text = L"6 Month";
			   this->SixMradioButton->UseVisualStyleBackColor = true;
			   this->SixMradioButton->CheckedChanged += gcnew System::EventHandler(this, &userPage::SixMradioButton_CheckedChanged);
			   // 
			   // ChooseSublabel
			   // 
			   this->ChooseSublabel->AutoSize = true;
			   this->ChooseSublabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->ChooseSublabel->Location = System::Drawing::Point(349, 84);
			   this->ChooseSublabel->Name = L"ChooseSublabel";
			   this->ChooseSublabel->Size = System::Drawing::Size(280, 29);
			   this->ChooseSublabel->TabIndex = 0;
			   this->ChooseSublabel->Text = L"choose your subscription";
			   // 
			   // OneYradioButton
			   // 
			   this->OneYradioButton->AutoSize = true;
			   this->OneYradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->OneYradioButton->Location = System::Drawing::Point(687, 177);
			   this->OneYradioButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OneYradioButton->Name = L"OneYradioButton";
			   this->OneYradioButton->Size = System::Drawing::Size(90, 29);
			   this->OneYradioButton->TabIndex = 11;
			   this->OneYradioButton->TabStop = true;
			   this->OneYradioButton->Text = L"1 Year";
			   this->OneYradioButton->UseVisualStyleBackColor = true;
			   this->OneYradioButton->CheckedChanged += gcnew System::EventHandler(this, &userPage::OneYradioButton_CheckedChanged);
			   // 
			   // OneMradioButton
			   // 
			   this->OneMradioButton->AutoSize = true;
			   this->OneMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->OneMradioButton->Location = System::Drawing::Point(129, 177);
			   this->OneMradioButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OneMradioButton->Name = L"OneMradioButton";
			   this->OneMradioButton->Size = System::Drawing::Size(104, 29);
			   this->OneMradioButton->TabIndex = 9;
			   this->OneMradioButton->TabStop = true;
			   this->OneMradioButton->Text = L"1 Month";
			   this->OneMradioButton->UseVisualStyleBackColor = true;
			   this->OneMradioButton->CheckedChanged += gcnew System::EventHandler(this, &userPage::OneMradioButton_CheckedChanged);
			   // 
			   // ThreeMradioButton
			   // 
			   this->ThreeMradioButton->AutoSize = true;
			   this->ThreeMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->ThreeMradioButton->Location = System::Drawing::Point(307, 177);
			   this->ThreeMradioButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->ThreeMradioButton->Name = L"ThreeMradioButton";
			   this->ThreeMradioButton->Size = System::Drawing::Size(104, 29);
			   this->ThreeMradioButton->TabIndex = 10;
			   this->ThreeMradioButton->TabStop = true;
			   this->ThreeMradioButton->Text = L"3 Month";
			   this->ThreeMradioButton->UseVisualStyleBackColor = true;
			   this->ThreeMradioButton->CheckedChanged += gcnew System::EventHandler(this, &userPage::ThreeMradioButton_CheckedChanged);
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
			   this->PadelPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->PadelPage->Name = L"PadelPage";
			   this->PadelPage->Size = System::Drawing::Size(957, 738);
			   this->PadelPage->TabIndex = 0;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(184, 9);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(48, 22);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Date";
			   // 
			   // dateTimePicker1
			   // 
			   this->dateTimePicker1->CustomFormat = L"MM/dd/yyyy";
			   this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			   this->dateTimePicker1->Location = System::Drawing::Point(173, 37);
			   this->dateTimePicker1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->dateTimePicker1->MaxDate = System::DateTime(2026, 2, 28, 0, 0, 0, 0);
			   this->dateTimePicker1->Name = L"dateTimePicker1";
			   this->dateTimePicker1->Size = System::Drawing::Size(121, 27);
			   this->dateTimePicker1->TabIndex = 8;
			   this->dateTimePicker1->Value = System::DateTime(2025, 4, 16, 0, 0, 0, 0);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(351, 9);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(51, 22);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"From";
			   // 
			   // comboBox2
			   // 
			   this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox2->FormattingEnabled = true;
			   this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
					L"00:00", L"12:00", L"13:00", L"14:00", L"15:00",
						 L"16::00", L"17:00", L"18:00", L"19:00", L"20:00", L"21:00", L"22:00", L"23:00"
			   });
			   this->comboBox2->Location = System::Drawing::Point(355, 39);
			   this->comboBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->comboBox2->Name = L"comboBox2";
			   this->comboBox2->Size = System::Drawing::Size(73, 24);
			   this->comboBox2->TabIndex = 4;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(15, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(72, 22);
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
			   this->comboBox1->Location = System::Drawing::Point(11, 39);
			   this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(103, 24);
			   this->comboBox1->TabIndex = 2;
			   // 
			   // searchOFcourts
			   // 
			   this->searchOFcourts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->searchOFcourts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->searchOFcourts->Location = System::Drawing::Point(811, 25);
			   this->searchOFcourts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->searchOFcourts->Name = L"searchOFcourts";
			   this->searchOFcourts->Size = System::Drawing::Size(137, 38);
			   this->searchOFcourts->TabIndex = 1;
			   this->searchOFcourts->Text = L"search";
			   this->searchOFcourts->UseVisualStyleBackColor = true;
			   this->searchOFcourts->Click += gcnew System::EventHandler(this, &userPage::searchOFcourts_Click);
			   // 
			   // listOfCourts
			   // 
			   this->listOfCourts->AutoScroll = true;
			   this->listOfCourts->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->listOfCourts->Location = System::Drawing::Point(0, 68);
			   this->listOfCourts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->listOfCourts->Name = L"listOfCourts";
			   this->listOfCourts->Size = System::Drawing::Size(957, 670);
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
			   this->panelWorkoutContent->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panelWorkoutContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->panelWorkoutContent->Location = System::Drawing::Point(0, 0);
			   this->panelWorkoutContent->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->panelWorkoutContent->Name = L"panelWorkoutContent";
			   this->panelWorkoutContent->Size = System::Drawing::Size(957, 738);
			   this->panelWorkoutContent->TabIndex = 0;
			   this->panelWorkoutContent->Visible = false;
			   // 
			   // comboFilterType
			   // 
			   this->comboFilterType->FormattingEnabled = true;
			   this->comboFilterType->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
					L"Cardio", L"Strength", L"Pilates", L"Yoga",
						 L"Cycling", L"HIIT"
			   });
			   this->comboFilterType->Location = System::Drawing::Point(119, 255);
			   this->comboFilterType->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->comboFilterType->Name = L"comboFilterType";
			   this->comboFilterType->Size = System::Drawing::Size(195, 33);
			   this->comboFilterType->TabIndex = 16;
			   // 
			   // btnHideWorkout
			   // 
			   this->btnHideWorkout->Location = System::Drawing::Point(804, 7);
			   this->btnHideWorkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnHideWorkout->Name = L"btnHideWorkout";
			   this->btnHideWorkout->Size = System::Drawing::Size(149, 30);
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
			   this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(391, 26);
			   this->textBox1->TabIndex = 0;
			   this->textBox1->Text = L"Workout";
			   // 
			   // lblDate
			   // 
			   this->lblDate->Location = System::Drawing::Point(20, 43);
			   this->lblDate->Name = L"lblDate";
			   this->lblDate->Size = System::Drawing::Size(100, 23);
			   this->lblDate->TabIndex = 1;
			   this->lblDate->Text = L"Date:";
			   // 
			   // txtDate
			   // 
			   this->txtDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->txtDate->Location = System::Drawing::Point(119, 39);
			   this->txtDate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtDate->Name = L"txtDate";
			   this->txtDate->Size = System::Drawing::Size(447, 30);
			   this->txtDate->TabIndex = 2;
			   // 
			   // lblType
			   // 
			   this->lblType->Location = System::Drawing::Point(20, 81);
			   this->lblType->Name = L"lblType";
			   this->lblType->Size = System::Drawing::Size(100, 23);
			   this->lblType->TabIndex = 3;
			   this->lblType->Text = L"Workout Type:";
			   // 
			   // txtType
			   // 
			   this->txtType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->txtType->Location = System::Drawing::Point(119, 76);
			   this->txtType->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtType->Name = L"txtType";
			   this->txtType->Size = System::Drawing::Size(447, 30);
			   this->txtType->TabIndex = 4;
			   // 
			   // lblDuration
			   // 
			   this->lblDuration->Location = System::Drawing::Point(20, 119);
			   this->lblDuration->Name = L"lblDuration";
			   this->lblDuration->Size = System::Drawing::Size(100, 23);
			   this->lblDuration->TabIndex = 5;
			   this->lblDuration->Text = L"Duration (min):";
			   // 
			   // txtDuration
			   // 
			   this->txtDuration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->txtDuration->Location = System::Drawing::Point(119, 112);
			   this->txtDuration->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtDuration->Name = L"txtDuration";
			   this->txtDuration->Size = System::Drawing::Size(447, 30);
			   this->txtDuration->TabIndex = 6;
			   // 
			   // lblWeight
			   // 
			   this->lblWeight->Location = System::Drawing::Point(20, 158);
			   this->lblWeight->Name = L"lblWeight";
			   this->lblWeight->Size = System::Drawing::Size(100, 23);
			   this->lblWeight->TabIndex = 7;
			   this->lblWeight->Text = L"Weight (kg):";
			   // 
			   // txtWeight
			   // 
			   this->txtWeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->txtWeight->Location = System::Drawing::Point(119, 148);
			   this->txtWeight->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->txtWeight->Name = L"txtWeight";
			   this->txtWeight->Size = System::Drawing::Size(447, 30);
			   this->txtWeight->TabIndex = 8;
			   // 
			   // btnAddWorkout
			   // 
			   this->btnAddWorkout->Location = System::Drawing::Point(19, 204);
			   this->btnAddWorkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnAddWorkout->Name = L"btnAddWorkout";
			   this->btnAddWorkout->Size = System::Drawing::Size(149, 30);
			   this->btnAddWorkout->TabIndex = 9;
			   this->btnAddWorkout->Text = L"Add Workout";
			   this->btnAddWorkout->Click += gcnew System::EventHandler(this, &userPage::btnAddWorkout_Click);
			   // 
			   // btnViewHistory
			   // 
			   this->btnViewHistory->Location = System::Drawing::Point(179, 204);
			   this->btnViewHistory->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnViewHistory->Name = L"btnViewHistory";
			   this->btnViewHistory->Size = System::Drawing::Size(149, 30);
			   this->btnViewHistory->TabIndex = 10;
			   this->btnViewHistory->Text = L"View History";
			   this->btnViewHistory->Click += gcnew System::EventHandler(this, &userPage::btnViewHistory_Click);
			   // 
			   // btnTrackProgress
			   // 
			   this->btnTrackProgress->Location = System::Drawing::Point(339, 204);
			   this->btnTrackProgress->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnTrackProgress->Name = L"btnTrackProgress";
			   this->btnTrackProgress->Size = System::Drawing::Size(149, 30);
			   this->btnTrackProgress->TabIndex = 11;
			   this->btnTrackProgress->Text = L"Track Progress";
			   this->btnTrackProgress->Click += gcnew System::EventHandler(this, &userPage::btnTrackProgress_Click);
			   // 
			   // lblFilter
			   // 
			   this->lblFilter->Location = System::Drawing::Point(20, 258);
			   this->lblFilter->Name = L"lblFilter";
			   this->lblFilter->Size = System::Drawing::Size(100, 23);
			   this->lblFilter->TabIndex = 12;
			   this->lblFilter->Text = L"Filter by Type:";
			   // 
			   // btnFilter
			   // 
			   this->btnFilter->Location = System::Drawing::Point(355, 254);
			   this->btnFilter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->btnFilter->Name = L"btnFilter";
			   this->btnFilter->Size = System::Drawing::Size(100, 33);
			   this->btnFilter->TabIndex = 14;
			   this->btnFilter->Text = L"Filter";
			   this->btnFilter->Click += gcnew System::EventHandler(this, &userPage::btnFilter_Click);
			   // 
			   // richTextOutput
			   // 
			   this->richTextOutput->Location = System::Drawing::Point(20, 318);
			   this->richTextOutput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->richTextOutput->Name = L"richTextOutput";
			   this->richTextOutput->ReadOnly = true;
			   this->richTextOutput->Size = System::Drawing::Size(928, 355);
			   this->richTextOutput->TabIndex = 15;
			   this->richTextOutput->Text = L"";
			   // 
			   // GymClass_pg
			   // 
			   this->GymClass_pg->Controls->Add(this->ListOfClasses);
			   this->GymClass_pg->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->GymClass_pg->Location = System::Drawing::Point(0, 0);
			   this->GymClass_pg->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->GymClass_pg->Name = L"GymClass_pg";
			   this->GymClass_pg->Size = System::Drawing::Size(957, 738);
			   this->GymClass_pg->TabIndex = 1;
			   // 
			   // ListOfClasses
			   // 
			   this->ListOfClasses->AutoScroll = true;
			   this->ListOfClasses->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->ListOfClasses->Location = System::Drawing::Point(0, 0);
			   this->ListOfClasses->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->ListOfClasses->Name = L"ListOfClasses";
			   this->ListOfClasses->Size = System::Drawing::Size(957, 738);
			   this->ListOfClasses->TabIndex = 1;
			   this->ListOfClasses->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &userPage::ListOfClasses_Paint);
			   // 
			   // CancelPadel_pg
			   // 
			   this->CancelPadel_pg->Controls->Add(this->label3);
			   this->CancelPadel_pg->Controls->Add(this->ListOfMyRes);
			   this->CancelPadel_pg->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->CancelPadel_pg->Location = System::Drawing::Point(0, 0);
			   this->CancelPadel_pg->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->CancelPadel_pg->Name = L"CancelPadel_pg";
			   this->CancelPadel_pg->Size = System::Drawing::Size(957, 738);
			   this->CancelPadel_pg->TabIndex = 0;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::Color::Red;
			   this->label3->Location = System::Drawing::Point(47, 12);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(791, 72);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"You must cancel appointments at least 3 hours in advance.\n\n";
			   // 
			   // ListOfMyRes
			   // 
			   this->ListOfMyRes->AutoScroll = true;
			   this->ListOfMyRes->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ListOfMyRes->Location = System::Drawing::Point(0, 68);
			   this->ListOfMyRes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->ListOfMyRes->Name = L"ListOfMyRes";
			   this->ListOfMyRes->Size = System::Drawing::Size(957, 670);
			   this->ListOfMyRes->TabIndex = 1;
			   // 
			   // delayedRenewTimer
			   // 
			   this->delayedRenewTimer->Tick += gcnew System::EventHandler(this, &userPage::delayedRenewTimer_Tick);
			   // 
			   // userPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1273, 738);
			   this->ControlBox = false;
			   this->Controls->Add(this->MainPage);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Name = L"userPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"userPage";
			   this->Load += gcnew System::EventHandler(this, &userPage::userPage_Load);
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->MainPage->ResumeLayout(false);
			   this->RenewPG->ResumeLayout(false);
			   this->RenewPG->PerformLayout();
			   this->PadelPage->ResumeLayout(false);
			   this->PadelPage->PerformLayout();
			   this->panelWorkoutContent->ResumeLayout(false);
			   this->panelWorkoutContent->PerformLayout();
			   this->GymClass_pg->ResumeLayout(false);
			   this->CancelPadel_pg->ResumeLayout(false);
			   this->CancelPadel_pg->PerformLayout();
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
<<<<<<< HEAD
		  if (userList[loginID].subscription.getEndDate() < User::getCurrentDate_MM_DD_YYYY()) {
=======
		  string endDate = userList[loginID].subscription.getEndDate();
		  time_t currentTime = time(0);
		  time_t endTime_t = getTime_t(endDate);
		  if (endTime_t < currentTime) {
>>>>>>> f16765b177e2aac6ee0f4a25a94d764e8a9fedd7
			   MessageBox::Show("You cannot reserve  any padel court because your subscription has expired.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   return;
		  }
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
<<<<<<< HEAD
		  if (userList[loginID].subscription.getEndDate() < User::getCurrentDate_MM_DD_YYYY()) {
=======
		  string endDate = userList[loginID].subscription.getEndDate();
		  time_t currentTime = time(0);
		  time_t endTime_t = getTime_t(endDate);
		  if (endTime_t < currentTime) {
>>>>>>> f16765b177e2aac6ee0f4a25a94d764e8a9fedd7
			   MessageBox::Show("You cannot subscribe to any classes because your general subscription has expired.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   return;
		  }
		  MainPage->Controls->Add(GymClass_pg);
		  GymClass_pg->BringToFront();
		  ListOfClasses->Controls->Clear();
		  //auto it = userList[loginID].myClasses.begin(); // list contain gym class key
		  auto gymClass = userList[loginID].subscription.getAvailableClasses();
		  for (auto it = gymClass.begin(); it != gymClass.end(); it++) {

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

			string convertYMDtoMDY(const string& ymd) {
				 int year, month, day;
				 if (sscanf(ymd.c_str(), "%d/%d/%d", &year, &month, &day) != 3) {
					  return ""; // or handle error
				 }

				 char buffer[11];
				 snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d", month, day, year);
				 return string(buffer); // MM/DD/YYYY
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

		  time_t today = time(0);
		  string fixedStartDate = convertYMDtoMDY(userList[loginID].subscription.getStartDate());
		  string fixedEndDate = convertYMDtoMDY(userList[loginID].subscription.getEndDate());

		  time_t subStart = getTime_t(fixedStartDate);
		  time_t subEnd = getTime_t(fixedEndDate);



		  if (fixedStartDate.empty() || fixedEndDate.empty()) {
			   MessageBox::Show("Invalid subscription date format.", "Date Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  if (today < subStart || today > subEnd) {
			   MessageBox::Show("Your subscription is expired. Please renew to add workouts.",
					"Subscription Inactive", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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

		  workoutManager.loadFromFile("Data/workouts.csv", userList);

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


			string normalizeWorkoutType(const std::string& input) {
				 std::string cleaned;
				 cleaned.reserve(input.size());

				 for (char c : input) {
					  if (c != ' ')
						   cleaned += std::tolower(c);
				 }

				 if (cleaned == "cardioworkout" || cleaned == "cardio") return "cardio";
				 if (cleaned == "strenght" || cleaned == "strenghtworkout" || cleaned == "strength") return "strength";
				 if (cleaned == "hiit" || cleaned == "hitt") return "hiit";
				 if (cleaned == "yoga") return "yoga";
				 if (cleaned == "pilates") return "pilates";
				 if (cleaned == "cykling") return "cycling";

				 return cleaned;
			}

	 private: System::Void btnFilter_Click(System::Object^ sender, System::EventArgs^ e) {

		  richTextOutput->Clear();
		  workoutManager.loadFromFile("Data/workouts.csv", userList);


		  String^ selectedWorkoutType = comboFilterType->SelectedItem != nullptr
			   ? comboFilterType->SelectedItem->ToString()
			   : nullptr;

		  if (String::IsNullOrEmpty(selectedWorkoutType)) {
			   MessageBox::Show("Please select a workout type to filter.", "Input Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }


		  string type, normalizedFilterType;
		  try {
			   type = msclr::interop::marshal_as<std::string>(selectedWorkoutType);
			   normalizedFilterType = normalizeWorkoutType(type);

		  }
		  catch (System::Exception^ ex) {
			   MessageBox::Show("Error processing workout type: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }



		  try {

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
					string workoutType = normalizeWorkoutType(workout.type);

					Console::WriteLine("Workout Type in file: '{0}'", gcnew String(workout.type.c_str()));

					if (workoutType == normalizedFilterType) {
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
		  this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
		  toolTip1->AutoPopDelay = 5000;
		  toolTip1->InitialDelay = 1000;
		  toolTip1->ReshowDelay = 500;
		  toolTip1->ShowAlways = true;

		  toolTip1->SetToolTip(this->button2, "To show your personal info");
		  toolTip1->SetToolTip(this->ListReserPadel, "To show your padel court reservation");
		  int remainingDays = userList[loginID].subscription.getRemainingDays();
		  double discount = userList[loginID].subscription.applyOffer(remainingDays) * 100;
		  if (remainingDays < 7) {
			   string  msg = Notification::standardMessage(userList[loginID], "", 0);
			   if (msg != "") {
					MessageBox::Show(gcnew String(msg.c_str()), "Notification", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
		  }
		  if (remainingDays >= 3 && remainingDays <= 6) {
			   System::Windows::Forms::DialogResult result = MessageBox::Show(
					"You have an early renewal discount of " + discount.ToString() + "%!\nWould you like to renew now and save?",
					"Special Offer",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Information
			   );
			   if (result == System::Windows::Forms::DialogResult::Yes) {
					delayedRenewTimer->Start();

			   }

		  }
		  if (userList[loginID].MessagesNotRead()) {
			   button5->BackgroundImage = System::Drawing::Image::FromFile("assets/notread.png");

		  }


		  MainPage->Controls->Clear();


	 }
	 private: System::Void logout_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		  LoadingPage^ loadingPage = gcnew LoadingPage();
		  loadingPage->label1->Text = "Logging out...";
		  this->Hide();
		  loadingPage->ShowDialog();
		  loginID = "";
		  this->Close();
	 }
	 private: System::Void ListOfClasses_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	 }

	 private:void showRenewPage() {


		  //calc days before subscription end
		  int remainingDays = userList[loginID].subscription.getRemainingDays();
		  if (remainingDays > 15) {
			   MessageBox::Show("You can not renew your subscription now, you have " + remainingDays + " days left", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }

		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(RenewPG);
		  RenewPG->BringToFront();
		  RenewPG->Visible = true;


		  if (userList[loginID].subscription.get_is_VIP()) {
			   checkBox1->Checked = true;
		  }

		  if (userList[loginID].subscription.getType() == "1 month")
			   OneMradioButton->Checked = true;
		  else if (userList[loginID].subscription.getType() == "3 month")
			   ThreeMradioButton->Checked = true;
		  else if (userList[loginID].subscription.getType() == "6 month")
			   SixMradioButton->Checked = true;
		  else if (userList[loginID].subscription.getType() == "1 year")
			   OneYradioButton->Checked = true;;
	 }
	 private: System::Void delayedRenewTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		  delayedRenewTimer->Stop();
		  showRenewPage();
	 }

	 private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		  showRenewPage();

	 }
	 private: System::Void OneMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		  if (OneMradioButton->Checked) {
			   Subscriptions nonVipSub("1 month", User::getCurrentDate_MM_DD_YYYY(), false);
			   Subscriptions vipSub("1 month", User::getCurrentDate_MM_DD_YYYY(), true);
			   double basePrice = nonVipSub.getPrice();
			   double vipPrice = vipSub.getPrice();
			   String^ startDate = gcnew String(User::getCurrentDate_MM_DD_YYYY().c_str());
			   String^ endDate = gcnew String(nonVipSub.calculateEndDate().c_str());

			   richTextBox1->Text = String::Format(
					"1 Month Subscription Details:\n"
					"Duration: 1 Month\n"
					"Base Price: ${0:F2}\n"
					"VIP Price: ${1:F2}\n"
					"Start Date: {2}\n"
					"End Date: {3}",
					basePrice, vipPrice, startDate, endDate);
		  }
		  else {
			   richTextBox1->Text = "";
		  }
	 }
	 private: System::Void ThreeMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		  if (ThreeMradioButton->Checked) {
			   Subscriptions nonVipSub("3 month", User::getCurrentDate_MM_DD_YYYY(), false);
			   Subscriptions vipSub("3 month", User::getCurrentDate_MM_DD_YYYY(), true);
			   double basePrice = nonVipSub.getPrice();
			   double vipPrice = vipSub.getPrice();
			   String^ startDate = gcnew String(User::getCurrentDate_MM_DD_YYYY().c_str());
			   String^ endDate = gcnew String(nonVipSub.calculateEndDate().c_str());

			   richTextBox1->Text = String::Format(
					"3 Month Subscription Details:\n"
					"Duration: 3 Months\n"
					"Base Price: ${0:F2}\n"
					"VIP Price: ${1:F2}\n"
					"Start Date: {2}\n"
					"End Date: {3}",
					basePrice, vipPrice, startDate, endDate);
		  }
		  else {
			   richTextBox1->Text = "";
		  }
	 }
	 private: System::Void SixMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		  if (SixMradioButton->Checked) {
			   Subscriptions nonVipSub("6 month", User::getCurrentDate_MM_DD_YYYY(), false);
			   Subscriptions vipSub("6 month", User::getCurrentDate_MM_DD_YYYY(), true);
			   double basePrice = nonVipSub.getPrice();
			   double vipPrice = vipSub.getPrice();
			   String^ startDate = gcnew String(User::getCurrentDate_MM_DD_YYYY().c_str());
			   String^ endDate = gcnew String(nonVipSub.calculateEndDate().c_str());

			   richTextBox1->Text = String::Format(
					"6 Month Subscription Details:\n"
					"Duration: 6 Months\n"
					"Base Price: ${0:F2}\n"
					"VIP Price: ${1:F2}\n"
					"Start Date: {2}\n"
					"End Date: {3}",
					basePrice, vipPrice, startDate, endDate);
		  }
		  else {
			   richTextBox1->Text = "";
		  }
	 }
	 private: System::Void OneYradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		  if (OneYradioButton->Checked) {
			   Subscriptions nonVipSub("1 year", User::getCurrentDate_MM_DD_YYYY(), false);
			   Subscriptions vipSub("1 year", User::getCurrentDate_MM_DD_YYYY(), true);
			   double basePrice = nonVipSub.getPrice();
			   double vipPrice = vipSub.getPrice();
			   String^ startDate = gcnew String(User::getCurrentDate_MM_DD_YYYY().c_str());
			   String^ endDate = gcnew String(nonVipSub.calculateEndDate().c_str());

			   richTextBox1->Text = String::Format(
					"1 Year Subscription Details:\n"
					"Duration: 1 Year\n"
					"Base Price: ${0:F2}\n"
					"VIP Price: ${1:F2}\n"
					"Start Date: {2}\n"
					"End Date: {3}",
					basePrice, vipPrice, startDate, endDate);
		  }
		  else {
			   richTextBox1->Text = "";
		  }
	 }
	 private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		  bool isVIP = checkBox1->Checked;
		  string subType = "";
		  if (OneMradioButton->Checked) subType = "1 month";
		  else if (ThreeMradioButton->Checked) subType = "3 month";
		  else if (SixMradioButton->Checked) subType = "6 month";
		  else if (OneYradioButton->Checked) subType = "1 year";

		  Subscriptions sub(subType, userList[loginID].subscription.getEndDate(), isVIP);
		  double price = sub.getPrice();
		  // Check offers
		  int remainingDays = userList[loginID].subscription.getRemainingDays();
		  double discount = userList[loginID].subscription.applyOffer(remainingDays);
		  double priceAfterDiscount = price * (1 - discount);

		  if (userList[loginID].myWallet >= priceAfterDiscount) {
			   MessageBox::Show("Subscription renewed successfully", "successful operation", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   userList[loginID].myWallet -= priceAfterDiscount;
			   Wallet->Text = "Wallet: $" + userList[loginID].myWallet.ToString();
		  }
		  else {
			   priceAfterDiscount = userList[loginID].myWallet > 0 ? (priceAfterDiscount - userList[loginID].myWallet) : priceAfterDiscount;
			   PaymentPage^ paymentPage = gcnew PaymentPage(price);
			   this->Hide();
			   paymentPage->ShowDialog();
			   this->Show();
			   if (paymentPage->OperationResult) {
					MessageBox::Show("Subscription renewed successfully", "successful operation", MessageBoxButtons::OK, MessageBoxIcon::Information);
					userList[loginID].subscription.renewSub(sub);
					userList[loginID].myWallet = 0;
					//  userList[loginID].saveToFile("Data/users.csv");
					  // Update the wallet label
					Wallet->Text = "Wallet: $" + userList[loginID].myWallet.ToString();
			   }

		  }
	 }
	 private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		  MSGsShow^ show = gcnew MSGsShow();
		  show->ShowDialog();
		  if (userList[loginID].MessagesNotRead()) {
			   button5->BackgroundImage = System::Drawing::Image::FromFile("assets/notread.png");
		  }
		  else {
			   button5->BackgroundImage = System::Drawing::Image::FromFile("assets/read.png");
		  }
	 }

	 };
}
