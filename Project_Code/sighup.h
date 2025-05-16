#pragma once
#include "Structure.h"
#include "feature_GUI/PaymentPage.h"
#include <msclr/marshal_cppstd.h>

namespace ProjectCode {
	 using namespace System;
	 using namespace System::IO;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;
	 using namespace System::Drawing::Drawing2D;
	 using namespace msclr::interop;

	 public ref class sighup : public System::Windows::Forms::Form {
	 public:
		  property bool OperationResult;
		  sighup(void) {
			   InitializeComponent();
			   selectedImagePath = nullptr;
			   panel2->Visible = true; // Ensure panel2 is visible on load
		  }

		  System::Void MakePictureCircular(PictureBox^ picBox) {
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

		  string setProfilePic(string userID, PictureBox^ pic, String^ filePath) {
			   string target = "null";
			   try {
					pic->Image = Image::FromFile(filePath); // Load image from provided path
					String^ newName = gcnew String(userID.c_str());
					System::IO::Directory::CreateDirectory(PicAsset);
					String^ newPATH = PicAsset + newName + Path::GetExtension(filePath);
					if (File::Exists(newPATH)) {
						 File::Delete(newPATH);
					}
					pic->Image->Save(newPATH); // Save image with unique filename
					target = marshal_as<string>(newPATH);
					MakePictureCircular(pic);
			   }
			   catch (Exception^ ex) {
					MessageBox::Show("Error saving image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   return target;
		  }

	 protected:
		  ~sighup() {
			   if (components) {
					delete components;
			   }
		  }

	 private:
		  System::ComponentModel::Container^ components;
	 public:
		  System::Windows::Forms::GroupBox^ groupBox1;
	 private:
		  System::Windows::Forms::RadioButton^ radioButton1;
		  System::Windows::Forms::RadioButton^ radioButton2;
		  System::Windows::Forms::Panel^ panel1;
		  System::Windows::Forms::Label^ label1;
		  System::Windows::Forms::TextBox^ textBox1;
		  System::Windows::Forms::Label^ label2;
		  System::Windows::Forms::TextBox^ textBox2;
		  System::Windows::Forms::Label^ label3;
		  System::Windows::Forms::TextBox^ textBox3;
		  System::Windows::Forms::Label^ label4;
		  System::Windows::Forms::TextBox^ textBox4;
		  System::Windows::Forms::RadioButton^ radioButton3;
		  System::Windows::Forms::RadioButton^ radioButton4;
		  System::Windows::Forms::Button^ button1;
		  System::Windows::Forms::PictureBox^ pictureBox1;
		  System::Windows::Forms::Panel^ panel2;
		  System::Windows::Forms::Label^ MemberNamelabel;
		  System::Windows::Forms::TextBox^ MemberNametextBox;
		  System::Windows::Forms::Label^ MemberEmaillabel;
		  System::Windows::Forms::TextBox^ MemberEmailtextBox;
		  System::Windows::Forms::Label^ label6;
		  System::Windows::Forms::TextBox^ textBox6;
		  System::Windows::Forms::Label^ BirthDaylabel;
		  System::Windows::Forms::ComboBox^ DaycomboBox;
		  System::Windows::Forms::ComboBox^ MonthcomboBox;
		  System::Windows::Forms::ComboBox^ YearcomboBox;
		  System::Windows::Forms::Label^ label9;
		  System::Windows::Forms::Button^ MemberNextbutton;
		  System::Windows::Forms::PictureBox^ MemberpictureBox2;
		  System::Windows::Forms::Panel^ panel3;
		  System::Windows::Forms::Label^ ChooseSublabel;
		  System::Windows::Forms::Button^ MemberSubmitbutton;
		  System::Windows::Forms::Label^ label7;
		  System::Windows::Forms::RadioButton^ OneMradioButton;
		  System::Windows::Forms::RadioButton^ ThreeMradioButton;
		  System::Windows::Forms::RadioButton^ SixMradioButton;
		  System::Windows::Forms::RadioButton^ OneYradioButton;
		  System::Windows::Forms::CheckBox^ checkBox1;
		  System::Windows::Forms::RichTextBox^ richTextBox1;
		  System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		  System::Windows::Forms::Label^ label5;
		  System::Windows::Forms::TextBox^ Pcode;
		  String^ selectedImagePath;

#pragma region Windows Form Designer generated code
		  void InitializeComponent(void) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sighup::typeid));
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->Pcode = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->YearcomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->MonthcomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->DaycomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->BirthDaylabel = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->MemberpictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->MemberNextbutton = (gcnew System::Windows::Forms::Button());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->MemberNamelabel = (gcnew System::Windows::Forms::Label());
			   this->MemberNametextBox = (gcnew System::Windows::Forms::TextBox());
			   this->MemberEmailtextBox = (gcnew System::Windows::Forms::TextBox());
			   this->MemberEmaillabel = (gcnew System::Windows::Forms::Label());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->SixMradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->OneYradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->ThreeMradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->OneMradioButton = (gcnew System::Windows::Forms::RadioButton());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->MemberSubmitbutton = (gcnew System::Windows::Forms::Button());
			   this->ChooseSublabel = (gcnew System::Windows::Forms::Label());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->groupBox1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->panel2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MemberpictureBox2))->BeginInit();
			   this->panel3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->BackColor = System::Drawing::Color::Black;
			   this->groupBox1->Controls->Add(this->radioButton2);
			   this->groupBox1->Controls->Add(this->radioButton1);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->groupBox1->Location = System::Drawing::Point(31, 10);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			   this->groupBox1->Size = System::Drawing::Size(256, 154);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Sign Up as ";
			   // 
			   // radioButton2
			   // 
			   this->radioButton2->AutoSize = true;
			   this->radioButton2->BackColor = System::Drawing::Color::Black;
			   this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 22.2F));
			   this->radioButton2->ForeColor = System::Drawing::Color::Silver;
			   this->radioButton2->Location = System::Drawing::Point(20, 115);
			   this->radioButton2->Margin = System::Windows::Forms::Padding(2);
			   this->radioButton2->Name = L"radioButton2";
			   this->radioButton2->Size = System::Drawing::Size(100, 43);
			   this->radioButton2->TabIndex = 1;
			   this->radioButton2->TabStop = true;
			   this->radioButton2->Text = L"Staff";
			   this->radioButton2->UseVisualStyleBackColor = false;
			   this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &sighup::radioButton2_CheckedChanged);
			   // 
			   // radioButton1
			   // 
			   this->radioButton1->AutoSize = true;
			   this->radioButton1->BackColor = System::Drawing::Color::Black;
			   this->radioButton1->Checked = true;
			   this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 22.2F));
			   this->radioButton1->ForeColor = System::Drawing::Color::Silver;
			   this->radioButton1->Location = System::Drawing::Point(20, 67);
			   this->radioButton1->Margin = System::Windows::Forms::Padding(2);
			   this->radioButton1->Name = L"radioButton1";
			   this->radioButton1->Size = System::Drawing::Size(156, 43);
			   this->radioButton1->TabIndex = 0;
			   this->radioButton1->TabStop = true;
			   this->radioButton1->Text = L"Member";
			   this->radioButton1->UseVisualStyleBackColor = false;
			   this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &sighup::radioButton1_CheckedChanged);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::Black;
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Controls->Add(this->Pcode);
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->radioButton4);
			   this->panel1->Controls->Add(this->radioButton3);
			   this->panel1->Controls->Add(this->textBox4);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->textBox1);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->textBox2);
			   this->panel1->Location = System::Drawing::Point(31, 181);
			   this->panel1->Margin = System::Windows::Forms::Padding(2);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(794, 333);
			   this->panel1->TabIndex = 4;
			   this->panel1->Visible = false;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->BackColor = System::Drawing::Color::Black;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label5->ForeColor = System::Drawing::Color::Silver;
			   this->label5->Location = System::Drawing::Point(2, 233);
			   this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(156, 24);
			   this->label5->TabIndex = 11;
			   this->label5->Text = L"Registration code";
			   // 
			   // Pcode
			   // 
			   this->Pcode->BackColor = System::Drawing::Color::LightGray;
			   this->Pcode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Pcode->ForeColor = System::Drawing::Color::Black;
			   this->Pcode->Location = System::Drawing::Point(158, 235);
			   this->Pcode->Margin = System::Windows::Forms::Padding(2);
			   this->Pcode->Name = L"Pcode";
			   this->Pcode->Size = System::Drawing::Size(119, 24);
			   this->Pcode->TabIndex = 10;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(300, 0);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(176, 132);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 5;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &sighup::pictureBox1_Click);
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::Black;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold));
			   this->button1->ForeColor = System::Drawing::Color::Silver;
			   this->button1->Location = System::Drawing::Point(310, 280);
			   this->button1->Margin = System::Windows::Forms::Padding(2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(166, 37);
			   this->button1->TabIndex = 5;
			   this->button1->Text = L"Submit";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &sighup::button1_Click);
			   // 
			   // radioButton4
			   // 
			   this->radioButton4->AutoSize = true;
			   this->radioButton4->BackColor = System::Drawing::Color::Black;
			   this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->radioButton4->ForeColor = System::Drawing::Color::Silver;
			   this->radioButton4->Location = System::Drawing::Point(638, 235);
			   this->radioButton4->Margin = System::Windows::Forms::Padding(2);
			   this->radioButton4->Name = L"radioButton4";
			   this->radioButton4->Size = System::Drawing::Size(83, 28);
			   this->radioButton4->TabIndex = 9;
			   this->radioButton4->TabStop = true;
			   this->radioButton4->Text = L"Coach";
			   this->radioButton4->UseVisualStyleBackColor = false;
			   // 
			   // radioButton3
			   // 
			   this->radioButton3->AutoSize = true;
			   this->radioButton3->BackColor = System::Drawing::Color::Black;
			   this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->radioButton3->ForeColor = System::Drawing::Color::Silver;
			   this->radioButton3->Location = System::Drawing::Point(506, 235);
			   this->radioButton3->Margin = System::Windows::Forms::Padding(2);
			   this->radioButton3->Name = L"radioButton3";
			   this->radioButton3->Size = System::Drawing::Size(114, 28);
			   this->radioButton3->TabIndex = 8;
			   this->radioButton3->TabStop = true;
			   this->radioButton3->Text = L"Reception";
			   this->radioButton3->UseVisualStyleBackColor = false;
			   // 
			   // textBox4
			   // 
			   this->textBox4->BackColor = System::Drawing::Color::LightGray;
			   this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBox4->ForeColor = System::Drawing::Color::Black;
			   this->textBox4->Location = System::Drawing::Point(500, 143);
			   this->textBox4->Margin = System::Windows::Forms::Padding(2);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(279, 24);
			   this->textBox4->TabIndex = 7;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Black;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label4->ForeColor = System::Drawing::Color::Silver;
			   this->label4->Location = System::Drawing::Point(414, 143);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(66, 24);
			   this->label4->TabIndex = 6;
			   this->label4->Text = L"Phone";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::Black;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label3->ForeColor = System::Drawing::Color::Silver;
			   this->label3->Location = System::Drawing::Point(405, 197);
			   this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(92, 24);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"Password";
			   // 
			   // textBox3
			   // 
			   this->textBox3->BackColor = System::Drawing::Color::LightGray;
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBox3->ForeColor = System::Drawing::Color::Black;
			   this->textBox3->Location = System::Drawing::Point(500, 197);
			   this->textBox3->Margin = System::Windows::Forms::Padding(2);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(279, 24);
			   this->textBox3->TabIndex = 4;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Black;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label1->ForeColor = System::Drawing::Color::Silver;
			   this->label1->Location = System::Drawing::Point(2, 137);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(61, 24);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Name";
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::LightGray;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBox1->ForeColor = System::Drawing::Color::Black;
			   this->textBox1->Location = System::Drawing::Point(74, 143);
			   this->textBox1->Margin = System::Windows::Forms::Padding(2);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(279, 24);
			   this->textBox1->TabIndex = 1;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Black;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label2->ForeColor = System::Drawing::Color::Silver;
			   this->label2->Location = System::Drawing::Point(2, 192);
			   this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 24);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"Email";
			   // 
			   // textBox2
			   // 
			   this->textBox2->BackColor = System::Drawing::Color::LightGray;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBox2->ForeColor = System::Drawing::Color::Black;
			   this->textBox2->Location = System::Drawing::Point(74, 197);
			   this->textBox2->Margin = System::Windows::Forms::Padding(2);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(279, 24);
			   this->textBox2->TabIndex = 3;
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::Black;
			   this->panel2->Controls->Add(this->YearcomboBox);
			   this->panel2->Controls->Add(this->MonthcomboBox);
			   this->panel2->Controls->Add(this->DaycomboBox);
			   this->panel2->Controls->Add(this->BirthDaylabel);
			   this->panel2->Controls->Add(this->label9);
			   this->panel2->Controls->Add(this->MemberpictureBox2);
			   this->panel2->Controls->Add(this->MemberNextbutton);
			   this->panel2->Controls->Add(this->label6);
			   this->panel2->Controls->Add(this->textBox6);
			   this->panel2->Controls->Add(this->MemberNamelabel);
			   this->panel2->Controls->Add(this->MemberNametextBox);
			   this->panel2->Controls->Add(this->MemberEmailtextBox);
			   this->panel2->Controls->Add(this->MemberEmaillabel);
			   this->panel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->panel2->Location = System::Drawing::Point(28, 179);
			   this->panel2->Margin = System::Windows::Forms::Padding(2);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(794, 336);
			   this->panel2->TabIndex = 10;
			   this->panel2->Visible = false;
			   // 
			   // YearcomboBox
			   // 
			   this->YearcomboBox->BackColor = System::Drawing::Color::Black;
			   this->YearcomboBox->ForeColor = System::Drawing::Color::Silver;
			   this->YearcomboBox->FormattingEnabled = true;
			   this->YearcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(53) {
					L"1955", L"1956", L"1957", L"1958", L"1959",
						 L"1960", L"1961", L"1962", L"1963", L"1964", L"1965", L"1966", L"1967", L"1968", L"1969", L"1970", L"1971", L"1972", L"1973",
						 L"1974", L"1975", L"1976", L"1977", L"1978", L"1979", L"1980", L"1981", L"1982", L"1983", L"1984", L"1985", L"1986", L"1987",
						 L"1988", L"1989", L"1990", L"1991", L"1992", L"1993", L"1994", L"1995", L"1996", L"1997", L"1998", L"1999", L"2000", L"2001",
						 L"2002", L"2003", L"2004", L"2005", L"2006", L"2007"
			   });
			   this->YearcomboBox->Location = System::Drawing::Point(687, 214);
			   this->YearcomboBox->Margin = System::Windows::Forms::Padding(2);
			   this->YearcomboBox->Name = L"YearcomboBox";
			   this->YearcomboBox->Size = System::Drawing::Size(92, 25);
			   this->YearcomboBox->TabIndex = 12;
			   this->YearcomboBox->Text = L"Year";
			   // 
			   // MonthcomboBox
			   // 
			   this->MonthcomboBox->BackColor = System::Drawing::Color::Black;
			   this->MonthcomboBox->ForeColor = System::Drawing::Color::Silver;
			   this->MonthcomboBox->FormattingEnabled = true;
			   this->MonthcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
					L"01", L"02", L"03", L"04", L"05", L"06", L"07",
						 L"08", L"09", L"10", L"11", L"12"
			   });
			   this->MonthcomboBox->Location = System::Drawing::Point(585, 214);
			   this->MonthcomboBox->Margin = System::Windows::Forms::Padding(2);
			   this->MonthcomboBox->Name = L"MonthcomboBox";
			   this->MonthcomboBox->Size = System::Drawing::Size(92, 25);
			   this->MonthcomboBox->TabIndex = 11;
			   this->MonthcomboBox->Text = L"Month";
			   // 
			   // DaycomboBox
			   // 
			   this->DaycomboBox->BackColor = System::Drawing::Color::Black;
			   this->DaycomboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->DaycomboBox->ForeColor = System::Drawing::Color::Silver;
			   this->DaycomboBox->FormattingEnabled = true;
			   this->DaycomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
					L"01", L"02", L"03", L"04", L"05", L"06", L"07",
						 L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
						 L"26", L"27", L"28", L"29", L"30", L"31"
			   });
			   this->DaycomboBox->Location = System::Drawing::Point(481, 214);
			   this->DaycomboBox->Margin = System::Windows::Forms::Padding(2);
			   this->DaycomboBox->Name = L"DaycomboBox";
			   this->DaycomboBox->Size = System::Drawing::Size(92, 25);
			   this->DaycomboBox->TabIndex = 10;
			   this->DaycomboBox->Text = L"Day";
			   // 
			   // BirthDaylabel
			   // 
			   this->BirthDaylabel->AutoSize = true;
			   this->BirthDaylabel->BackColor = System::Drawing::Color::Black;
			   this->BirthDaylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->BirthDaylabel->ForeColor = System::Drawing::Color::Silver;
			   this->BirthDaylabel->Location = System::Drawing::Point(386, 214);
			   this->BirthDaylabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->BirthDaylabel->Name = L"BirthDaylabel";
			   this->BirthDaylabel->Size = System::Drawing::Size(77, 24);
			   this->BirthDaylabel->TabIndex = 9;
			   this->BirthDaylabel->Text = L"Birthday";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->BackColor = System::Drawing::Color::Black;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->label9->ForeColor = System::Drawing::Color::Silver;
			   this->label9->Location = System::Drawing::Point(406, 315);
			   this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(34, 20);
			   this->label9->TabIndex = 8;
			   this->label9->Text = L"1/2";
			   // 
			   // MemberpictureBox2
			   // 
			   this->MemberpictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->MemberpictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MemberpictureBox2.Image")));
			   this->MemberpictureBox2->Location = System::Drawing::Point(292, 0);
			   this->MemberpictureBox2->Margin = System::Windows::Forms::Padding(2);
			   this->MemberpictureBox2->Name = L"MemberpictureBox2";
			   this->MemberpictureBox2->Size = System::Drawing::Size(176, 132);
			   this->MemberpictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->MemberpictureBox2->TabIndex = 5;
			   this->MemberpictureBox2->TabStop = false;
			   this->MemberpictureBox2->Click += gcnew System::EventHandler(this, &sighup::MemberpictureBox2_Click);
			   // 
			   // MemberNextbutton
			   // 
			   this->MemberNextbutton->BackColor = System::Drawing::Color::Black;
			   this->MemberNextbutton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.8F, System::Drawing::FontStyle::Bold));
			   this->MemberNextbutton->ForeColor = System::Drawing::Color::Silver;
			   this->MemberNextbutton->Location = System::Drawing::Point(356, 275);
			   this->MemberNextbutton->Margin = System::Windows::Forms::Padding(2);
			   this->MemberNextbutton->Name = L"MemberNextbutton";
			   this->MemberNextbutton->Size = System::Drawing::Size(112, 37);
			   this->MemberNextbutton->TabIndex = 5;
			   this->MemberNextbutton->Text = L"Next";
			   this->MemberNextbutton->UseVisualStyleBackColor = false;
			   this->MemberNextbutton->Click += gcnew System::EventHandler(this, &sighup::button2_Click);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->BackColor = System::Drawing::Color::Black;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->label6->ForeColor = System::Drawing::Color::Silver;
			   this->label6->Location = System::Drawing::Point(386, 166);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(92, 24);
			   this->label6->TabIndex = 5;
			   this->label6->Text = L"Password";
			   // 
			   // textBox6
			   // 
			   this->textBox6->BackColor = System::Drawing::Color::LightGray;
			   this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBox6->ForeColor = System::Drawing::Color::Black;
			   this->textBox6->Location = System::Drawing::Point(481, 166);
			   this->textBox6->Margin = System::Windows::Forms::Padding(2);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(279, 24);
			   this->textBox6->TabIndex = 4;
			   // 
			   // MemberNamelabel
			   // 
			   this->MemberNamelabel->AutoSize = true;
			   this->MemberNamelabel->BackColor = System::Drawing::Color::Black;
			   this->MemberNamelabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->MemberNamelabel->ForeColor = System::Drawing::Color::Silver;
			   this->MemberNamelabel->Location = System::Drawing::Point(2, 166);
			   this->MemberNamelabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->MemberNamelabel->Name = L"MemberNamelabel";
			   this->MemberNamelabel->Size = System::Drawing::Size(61, 24);
			   this->MemberNamelabel->TabIndex = 0;
			   this->MemberNamelabel->Text = L"Name";
			   // 
			   // MemberNametextBox
			   // 
			   this->MemberNametextBox->BackColor = System::Drawing::Color::LightGray;
			   this->MemberNametextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->MemberNametextBox->ForeColor = System::Drawing::Color::Black;
			   this->MemberNametextBox->Location = System::Drawing::Point(74, 166);
			   this->MemberNametextBox->Margin = System::Windows::Forms::Padding(2);
			   this->MemberNametextBox->Name = L"MemberNametextBox";
			   this->MemberNametextBox->Size = System::Drawing::Size(279, 24);
			   this->MemberNametextBox->TabIndex = 1;
			   // 
			   // MemberEmailtextBox
			   // 
			   this->MemberEmailtextBox->BackColor = System::Drawing::Color::LightGray;
			   this->MemberEmailtextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->MemberEmailtextBox->ForeColor = System::Drawing::Color::Black;
			   this->MemberEmailtextBox->Location = System::Drawing::Point(74, 220);
			   this->MemberEmailtextBox->Margin = System::Windows::Forms::Padding(2);
			   this->MemberEmailtextBox->Name = L"MemberEmailtextBox";
			   this->MemberEmailtextBox->Size = System::Drawing::Size(279, 24);
			   this->MemberEmailtextBox->TabIndex = 3;
			   // 
			   // MemberEmaillabel
			   // 
			   this->MemberEmaillabel->AutoSize = true;
			   this->MemberEmaillabel->BackColor = System::Drawing::Color::Black;
			   this->MemberEmaillabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->MemberEmaillabel->ForeColor = System::Drawing::Color::Silver;
			   this->MemberEmaillabel->Location = System::Drawing::Point(2, 220);
			   this->MemberEmaillabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->MemberEmaillabel->Name = L"MemberEmaillabel";
			   this->MemberEmaillabel->Size = System::Drawing::Size(57, 24);
			   this->MemberEmaillabel->TabIndex = 2;
			   this->MemberEmaillabel->Text = L"Email";
			   // 
			   // panel3
			   // 
			   this->panel3->BackColor = System::Drawing::Color::Black;
			   this->panel3->Controls->Add(this->richTextBox1);
			   this->panel3->Controls->Add(this->checkBox1);
			   this->panel3->Controls->Add(this->SixMradioButton);
			   this->panel3->Controls->Add(this->OneYradioButton);
			   this->panel3->Controls->Add(this->ThreeMradioButton);
			   this->panel3->Controls->Add(this->OneMradioButton);
			   this->panel3->Controls->Add(this->label7);
			   this->panel3->Controls->Add(this->MemberSubmitbutton);
			   this->panel3->Controls->Add(this->ChooseSublabel);
			   this->panel3->Location = System::Drawing::Point(28, 179);
			   this->panel3->Margin = System::Windows::Forms::Padding(2);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(794, 350);
			   this->panel3->TabIndex = 13;
			   this->panel3->Visible = false;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->BackColor = System::Drawing::Color::Black;
			   this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			   this->richTextBox1->ForeColor = System::Drawing::Color::Silver;
			   this->richTextBox1->Location = System::Drawing::Point(100, 176);
			   this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->Size = System::Drawing::Size(577, 97);
			   this->richTextBox1->TabIndex = 14;
			   this->richTextBox1->Text = L"";
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->BackColor = System::Drawing::Color::Black;
			   this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline))));
			   this->checkBox1->ForeColor = System::Drawing::Color::Silver;
			   this->checkBox1->Location = System::Drawing::Point(357, 152);
			   this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(51, 21);
			   this->checkBox1->TabIndex = 13;
			   this->checkBox1->Text = L"VIP";
			   this->checkBox1->UseVisualStyleBackColor = false;
			   // 
			   // SixMradioButton
			   // 
			   this->SixMradioButton->AutoSize = true;
			   this->SixMradioButton->BackColor = System::Drawing::Color::Black;
			   this->SixMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->SixMradioButton->ForeColor = System::Drawing::Color::Silver;
			   this->SixMradioButton->Location = System::Drawing::Point(404, 107);
			   this->SixMradioButton->Margin = System::Windows::Forms::Padding(2);
			   this->SixMradioButton->Name = L"SixMradioButton";
			   this->SixMradioButton->Size = System::Drawing::Size(85, 24);
			   this->SixMradioButton->TabIndex = 12;
			   this->SixMradioButton->TabStop = true;
			   this->SixMradioButton->Text = L"6 Month";
			   this->SixMradioButton->UseVisualStyleBackColor = false;
			   this->SixMradioButton->CheckedChanged += gcnew System::EventHandler(this, &sighup::SixMradioButton_CheckedChanged);
			   // 
			   // OneYradioButton
			   // 
			   this->OneYradioButton->AutoSize = true;
			   this->OneYradioButton->BackColor = System::Drawing::Color::Black;
			   this->OneYradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->OneYradioButton->ForeColor = System::Drawing::Color::Silver;
			   this->OneYradioButton->Location = System::Drawing::Point(549, 107);
			   this->OneYradioButton->Margin = System::Windows::Forms::Padding(2);
			   this->OneYradioButton->Name = L"OneYradioButton";
			   this->OneYradioButton->Size = System::Drawing::Size(74, 24);
			   this->OneYradioButton->TabIndex = 11;
			   this->OneYradioButton->TabStop = true;
			   this->OneYradioButton->Text = L"1 Year";
			   this->OneYradioButton->UseVisualStyleBackColor = false;
			   this->OneYradioButton->CheckedChanged += gcnew System::EventHandler(this, &sighup::OneYradioButton_CheckedChanged);
			   // 
			   // ThreeMradioButton
			   // 
			   this->ThreeMradioButton->AutoSize = true;
			   this->ThreeMradioButton->BackColor = System::Drawing::Color::Black;
			   this->ThreeMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->ThreeMradioButton->ForeColor = System::Drawing::Color::Silver;
			   this->ThreeMradioButton->Location = System::Drawing::Point(264, 107);
			   this->ThreeMradioButton->Margin = System::Windows::Forms::Padding(2);
			   this->ThreeMradioButton->Name = L"ThreeMradioButton";
			   this->ThreeMradioButton->Size = System::Drawing::Size(85, 24);
			   this->ThreeMradioButton->TabIndex = 10;
			   this->ThreeMradioButton->TabStop = true;
			   this->ThreeMradioButton->Text = L"3 Month";
			   this->ThreeMradioButton->UseVisualStyleBackColor = false;
			   this->ThreeMradioButton->CheckedChanged += gcnew System::EventHandler(this, &sighup::ThreeMradioButton_CheckedChanged);
			   // 
			   // OneMradioButton
			   // 
			   this->OneMradioButton->AutoSize = true;
			   this->OneMradioButton->BackColor = System::Drawing::Color::Black;
			   this->OneMradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->OneMradioButton->ForeColor = System::Drawing::Color::Silver;
			   this->OneMradioButton->Location = System::Drawing::Point(130, 107);
			   this->OneMradioButton->Margin = System::Windows::Forms::Padding(2);
			   this->OneMradioButton->Name = L"OneMradioButton";
			   this->OneMradioButton->Size = System::Drawing::Size(85, 24);
			   this->OneMradioButton->TabIndex = 9;
			   this->OneMradioButton->TabStop = true;
			   this->OneMradioButton->Text = L"1 Month";
			   this->OneMradioButton->UseVisualStyleBackColor = false;
			   this->OneMradioButton->CheckedChanged += gcnew System::EventHandler(this, &sighup::OneMradioButton_CheckedChanged);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->BackColor = System::Drawing::Color::Black;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->label7->ForeColor = System::Drawing::Color::Gray;
			   this->label7->Location = System::Drawing::Point(386, 325);
			   this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(34, 20);
			   this->label7->TabIndex = 8;
			   this->label7->Text = L"2/2";
			   // 
			   // MemberSubmitbutton
			   // 
			   this->MemberSubmitbutton->BackColor = System::Drawing::Color::Black;
			   this->MemberSubmitbutton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.8F, System::Drawing::FontStyle::Bold));
			   this->MemberSubmitbutton->ForeColor = System::Drawing::Color::Silver;
			   this->MemberSubmitbutton->Location = System::Drawing::Point(356, 275);
			   this->MemberSubmitbutton->Margin = System::Windows::Forms::Padding(2);
			   this->MemberSubmitbutton->Name = L"MemberSubmitbutton";
			   this->MemberSubmitbutton->Size = System::Drawing::Size(112, 37);
			   this->MemberSubmitbutton->TabIndex = 5;
			   this->MemberSubmitbutton->Text = L"Submit";
			   this->MemberSubmitbutton->UseVisualStyleBackColor = false;
			   this->MemberSubmitbutton->Click += gcnew System::EventHandler(this, &sighup::button3_Click);
			   // 
			   // ChooseSublabel
			   // 
			   this->ChooseSublabel->AutoSize = true;
			   this->ChooseSublabel->BackColor = System::Drawing::Color::Black;
			   this->ChooseSublabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic));
			   this->ChooseSublabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->ChooseSublabel->Location = System::Drawing::Point(296, 32);
			   this->ChooseSublabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ChooseSublabel->Name = L"ChooseSublabel";
			   this->ChooseSublabel->Size = System::Drawing::Size(221, 24);
			   this->ChooseSublabel->TabIndex = 0;
			   this->ChooseSublabel->Text = L"choose your subscription";
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->Filter = L"Image Files|.jpg;.jpeg;.png;.bmp;*.gif";
			   this->openFileDialog1->Title = L"Select an Image";
			   // 
			   // sighup
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Black;
			   this->ClientSize = System::Drawing::Size(1013, 569);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->panel2);
			   this->Controls->Add(this->panel3);
			   this->Controls->Add(this->groupBox1);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"sighup";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"sign up";
			   this->Load += gcnew System::EventHandler(this, &sighup::sighup_Load);
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MemberpictureBox2))->EndInit();
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->ResumeLayout(false);

		  }
#pragma endregion

	 private:
		  System::Void sighup_Load(System::Object^ sender, System::EventArgs^ e) {
			   if (MemberpictureBox2->Image != nullptr) {
					MakePictureCircular(MemberpictureBox2);
			   }
			   radioButton1->Checked = true;
			   panel2->BringToFront();
			   this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
		  }

		  System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (radioButton1->Checked) {
					panel1->Visible = false;
					panel2->Visible = true;
					panel3->Visible = false;
			   }
		  }

		  System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (radioButton2->Checked) {
					panel1->Visible = true;
					panel2->Visible = false;
					panel3->Visible = false;
					if (pictureBox1->Image != nullptr) {
						 MakePictureCircular(pictureBox1);
					}
			   }
			   else {
					panel1->Visible = false;
			   }
		  }

		  System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
			   OpenFileDialog^ open = gcnew OpenFileDialog();
			   open->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";
			   if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					try {
						 pictureBox1->Image = Image::FromFile(open->FileName);
						 selectedImagePath = open->FileName;
						 MakePictureCircular(pictureBox1);
					}
					catch (Exception^ ex) {
						 MessageBox::Show("Error loading image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
			   }
		  }

		  System::Void MemberpictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
			   OpenFileDialog^ open = gcnew OpenFileDialog();
			   open->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";
			   if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					try {
						 MemberpictureBox2->Image = Image::FromFile(open->FileName);
						 selectedImagePath = open->FileName;
						 MakePictureCircular(MemberpictureBox2);
					}
					catch (Exception^ ex) {
						 MessageBox::Show("Error loading image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
			   }
		  }

		  System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ name = textBox1->Text->Trim();
			   String^ email = textBox2->Text->Trim();
			   String^ password = textBox3->Text->Trim();
			   String^ phone = textBox4->Text->Trim();

			   if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password) || String::IsNullOrWhiteSpace(phone)) {
					MessageBox::Show("Please fill all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   if (!email->Contains("@") || !email->Contains(".")) {
					MessageBox::Show("Please enter a valid email.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   if (phone->Length <= 11) {
					MessageBox::Show("Phone number must be more than 11 digits.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   if (Pcode->Text == "") {
					MessageBox::Show("Please enter a registration code,\nCreated by the manager.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   for each(Char c in phone) {
					if (!Char::IsDigit(c)) {
						 MessageBox::Show("Phone number must contain only digits.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						 return;
					}
			   }

			   String^ role = "";
			   if (radioButton3->Checked) {
					role = "Reception";
			   }
			   else if (radioButton4->Checked) {
					role = "Coach";
			   }
			   else {
					MessageBox::Show("Please select a role.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   string temp = marshal_as<std::string>(Pcode->Text);
			   if (PassCode != temp || PassCode == "null") {
					MessageBox::Show("Invalid registration code.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   PassCode = "null"; // Code used
			   Staff newstaff;
			   string imagePath = "null";
			   if (selectedImagePath != nullptr && File::Exists(selectedImagePath)) {
					// Temporarily set ID for setProfilePic (will be overwritten by registerStaff)
					newstaff.ID = "temp_" + std::to_string(rand()); // Temporary ID to avoid conflict
					imagePath = setProfilePic(newstaff.ID, pictureBox1, selectedImagePath);
			   }
			   newstaff.PicPath = imagePath;

			   bool registed = newstaff.registerStaff(
					marshal_as<std::string>(name),
					marshal_as<std::string>(email),
					marshal_as<std::string>(password),
					marshal_as<std::string>(phone),
					marshal_as<std::string>(role)
			   );

			   OperationResult = registed;

			   if (registed) {
					// If image was saved with temp ID, rename it to use the actual staff ID
					if (imagePath != "null") {
						 String^ oldPath = gcnew String(imagePath.c_str());
						 String^ newPath = PicAsset + gcnew String(newstaff.ID.c_str()) + Path::GetExtension(oldPath);
						 try {
							  if (File::Exists(oldPath)) {
								   if (File::Exists(newPath)) {
										File::Delete(newPath);
								   }
								   File::Move(oldPath, newPath);
								   newstaff.PicPath = marshal_as<std::string>(newPath);
							  }
							  else {
								   newstaff.PicPath = "null";
							  }
						 }
						 catch (Exception^ ex) {
							  MessageBox::Show("Error renaming image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
							  newstaff.PicPath = "null";
						 }
					}

					staffList[newstaff.ID] = newstaff;

					MessageBox::Show("Staff registered successfully. ID: " + gcnew String(newstaff.ID.c_str()), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->Close();
					textBox1->Clear();
					textBox2->Clear();
					textBox3->Clear();
					textBox4->Clear();
					Pcode->Clear();
					pictureBox1->Image = nullptr;
					selectedImagePath = nullptr;
					radioButton3->Checked = false;
					radioButton4->Checked = false;
			   }
			   else {
					if (imagePath != "null" && File::Exists(gcnew String(imagePath.c_str()))) {
						 try {
							  File::Delete(gcnew String(imagePath.c_str()));
						 }
						 catch (Exception^ ex) {
						 }
					}
					MessageBox::Show("Sign Up failed. This email already has an account or name contains invalid characters.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		  }

		  System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ name = MemberNametextBox->Text->Trim();
			   String^ email = MemberEmailtextBox->Text->Trim();
			   String^ password = textBox6->Text->Trim();
			   String^ day = DaycomboBox->SelectedItem ? DaycomboBox->SelectedItem->ToString() : "";
			   String^ month = MonthcomboBox->SelectedItem ? MonthcomboBox->SelectedItem->ToString() : "";
			   String^ year = YearcomboBox->SelectedItem ? YearcomboBox->SelectedItem->ToString() : "";

			   if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password) ||
					String::IsNullOrWhiteSpace(day) || String::IsNullOrWhiteSpace(month) || String::IsNullOrWhiteSpace(year)) {
					MessageBox::Show("Please fill all fields in this step.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   User tempUser;
			   if (!tempUser.isNameValid(marshal_as<std::string>(name))) {
					MessageBox::Show("Invalid name. Use letters and spaces only.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   if (!tempUser.isEmailCorrect(marshal_as<std::string>(email))) {
					MessageBox::Show("Invalid email format. Must contain '@' and end with '.com'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   if (!tempUser.isEmailUnique(marshal_as<std::string>(email))) {
					MessageBox::Show("Email already exists. Try another.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   panel3->Visible = true;
			   panel1->Visible = false;
			   panel2->Visible = false;
		  }

		  System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ name = MemberNametextBox->Text->Trim();
			   String^ email = MemberEmailtextBox->Text->Trim();
			   String^ password = textBox6->Text->Trim();
			   String^ day = DaycomboBox->SelectedItem ? DaycomboBox->SelectedItem->ToString() : "";
			   String^ month = MonthcomboBox->SelectedItem ? MonthcomboBox->SelectedItem->ToString() : "";
			   String^ year = YearcomboBox->SelectedItem ? YearcomboBox->SelectedItem->ToString() : "";
			   String^ bday = String::Format("{0}/{1}/{2}", month, day, year);

			   String^ subType = "";
			   if (OneMradioButton->Checked) subType = "1 month";
			   else if (ThreeMradioButton->Checked) subType = "3 month";
			   else if (SixMradioButton->Checked) subType = "6 month";
			   else if (OneYradioButton->Checked) subType = "1 year";
			   bool isVip = checkBox1->Checked;

			   if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password) ||
					String::IsNullOrWhiteSpace(day) || String::IsNullOrWhiteSpace(month) || String::IsNullOrWhiteSpace(year)) {
					MessageBox::Show("Please complete all fields in the first step.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					panel2->Visible = true;
					panel3->Visible = false;
					return;
			   }

			   if (String::IsNullOrWhiteSpace(subType)) {
					MessageBox::Show("Please select a subscription type.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   Subscriptions tempSub(marshal_as<std::string>(subType), User::getCurrentDate_MM_DD_YYYY(), isVip);
			   double price = tempSub.getPrice();
			   PaymentPage^ paymentPage = gcnew PaymentPage(price);
			   paymentPage->ShowDialog();
			   if (!paymentPage->OperationResult) {
					MessageBox::Show("Payment failed. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }

			   User newUser;
			   string imagePath = "null";
			   bool registered = newUser.registerMember(
					marshal_as<std::string>(name),
					marshal_as<std::string>(email),
					marshal_as<std::string>(password),
					marshal_as<std::string>(bday),
					marshal_as<std::string>(subType),
					isVip,
					imagePath
			   );

			   if (!registered) {
					if (imagePath != "null" && File::Exists(gcnew String(imagePath.c_str()))) {
						 try {
							  File::Delete(gcnew String(imagePath.c_str()));
						 }
						 catch (Exception^ ex) {
						 }
					}
					MessageBox::Show("Registration failed. Check your inputs (name, email, birthday, or subscription).",
						 "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					panel2->Visible = true;
					panel3->Visible = false;
					return;
			   }
			   if (selectedImagePath != nullptr && File::Exists(selectedImagePath)) {
					imagePath = setProfilePic(newUser.ID, MemberpictureBox2, selectedImagePath);
					newUser.PicPath = imagePath;
					userList[newUser.ID] = newUser;
			   }
			   MessageBox::Show(String::Format("Member registered successfully.\nYour ID is: {0}\nTotal Price: ${1:F2}", gcnew String(newUser.ID.c_str()), price), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   OperationResult = registered;
			   this->Close();
			   MemberNametextBox->Clear();
			   MemberEmailtextBox->Clear();
			   textBox6->Clear();
			   DaycomboBox->Text = "Day";
			   MonthcomboBox->Text = "Month";
			   YearcomboBox->Text = "Year";
			   OneMradioButton->Checked = false;
			   ThreeMradioButton->Checked = false;
			   SixMradioButton->Checked = false;
			   OneYradioButton->Checked = false;
			   checkBox1->Checked = false;
			   MemberpictureBox2->Image = nullptr;
			   selectedImagePath = nullptr;
			   panel3->Visible = false;
			   panel2->Visible = true;
		  }

		  System::Void OneMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
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

		  System::Void ThreeMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
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

		  System::Void SixMradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
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

		  System::Void OneYradioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
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
	 };
}