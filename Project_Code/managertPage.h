#pragma once
#include "Structure.h"
#include"CreatClassForm.h"
namespace ProjectCode {
	// In managertPage.h (or another relevant header file)
   // extern std::string loginID;  // Declare the variable here

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class managertPage : public System::Windows::Forms::Form
	{
	public:
		managertPage(void)
		{
			InitializeComponent();
			panel1->Visible = false;
			label6->Visible = false;
			panel3->Visible = false;
			userIDTextBox->Visible = false;
			label1->Visible = false;
			textBox1->Visible = false;
			richTextBox1->Visible = false;
			richTextBox2->Visible = false;
		}

	protected:
		~managertPage()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ MainMenu_pn;
		System::Windows::Forms::Panel^ profile_pn;
		System::Windows::Forms::Label^ AccName;
		System::Windows::Forms::PictureBox^ AccPic;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::TextBox^ userIDTextBox;

		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel1;







	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;



		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(managertPage::typeid));
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->userIDTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->panel3->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Margin = System::Windows::Forms::Padding(2);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(944, 600);
			   this->MainMenu_pn->TabIndex = 3;
			   this->MainMenu_pn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::MainMenu_pn_Paint);
			   // 
			   // profile_pn
			   // 
			   this->profile_pn->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->profile_pn->Controls->Add(this->label6);
			   this->profile_pn->Controls->Add(this->panel1);
			   this->profile_pn->Controls->Add(this->button6);
			   this->profile_pn->Controls->Add(this->label1);
			   this->profile_pn->Controls->Add(this->textBox1);
			   this->profile_pn->Controls->Add(this->userIDTextBox);
			   this->profile_pn->Controls->Add(this->button2);
			   this->profile_pn->Controls->Add(this->button1);
			   this->profile_pn->Controls->Add(this->button3);
			   this->profile_pn->Controls->Add(this->button4);
			   this->profile_pn->Controls->Add(this->AccName);
			   this->profile_pn->Controls->Add(this->AccPic);
			   this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			   this->profile_pn->Location = System::Drawing::Point(0, 0);
			   this->profile_pn->Margin = System::Windows::Forms::Padding(2);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(944, 589);
			   this->profile_pn->TabIndex = 1;
			   this->profile_pn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::profile_pn_Paint);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(695, 86);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(57, 19);
			   this->label6->TabIndex = 10;
			   this->label6->Text = L"UserID";
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->richTextBox1);
			   this->panel1->Controls->Add(this->button5);
			   this->panel1->Controls->Add(this->panel3);
			   this->panel1->Controls->Add(this->comboBox1);
			   this->panel1->Location = System::Drawing::Point(265, 12);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(676, 574);
			   this->panel1->TabIndex = 9;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Location = System::Drawing::Point(26, 72);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->Size = System::Drawing::Size(609, 460);
			   this->richTextBox1->TabIndex = 8;
			   this->richTextBox1->Text = L"";
			   this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &managertPage::richTextBox1_TextChanged);
			   // 
			   // button5
			   // 
			   this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button5->Location = System::Drawing::Point(187, 7);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(220, 34);
			   this->button5->TabIndex = 7;
			   this->button5->Text = L"Enter Month To generate Report";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &managertPage::button5_Click_1);
			   // 
			   // panel3
			   // 
			   this->panel3->Controls->Add(this->richTextBox2);
			   this->panel3->Controls->Add(this->button8);
			   this->panel3->Controls->Add(this->textBox2);
			   this->panel3->Controls->Add(this->label4);
			   this->panel3->Controls->Add(this->label5);
			   this->panel3->Controls->Add(this->label3);
			   this->panel3->Controls->Add(this->label2);
			   this->panel3->Location = System::Drawing::Point(0, 7);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(669, 551);
			   this->panel3->TabIndex = 5;
			   // 
			   // richTextBox2
			   // 
			   this->richTextBox2->Location = System::Drawing::Point(13, 106);
			   this->richTextBox2->Name = L"richTextBox2";
			   this->richTextBox2->Size = System::Drawing::Size(634, 417);
			   this->richTextBox2->TabIndex = 5;
			   this->richTextBox2->Text = L"";
			   // 
			   // button8
			   // 
			   this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button8->Location = System::Drawing::Point(211, 19);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(141, 45);
			   this->button8->TabIndex = 4;
			   this->button8->Text = L"Enter Coach ID";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &managertPage::button8_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(211, 85);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(141, 20);
			   this->textBox2->TabIndex = 3;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(28, 280);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(130, 20);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"coach Classes:";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(28, 222);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(121, 20);
			   this->label5->TabIndex = 2;
			   this->label5->Text = L"Coach Phone:";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(28, 176);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(114, 20);
			   this->label3->TabIndex = 1;
			   this->label3->Text = L"Coach Email:";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(26, 125);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(116, 20);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"Coach Name:";
			   this->label2->Click += gcnew System::EventHandler(this, &managertPage::label2_Click);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					   L"9", L"10", L"11", L"12"
			   });
			   this->comboBox1->Location = System::Drawing::Point(187, 47);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(206, 21);
			   this->comboBox1->TabIndex = 6;
			   this->comboBox1->Text = L"Months";
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &managertPage::comboBox1_SelectedIndexChanged);
			   // 
			   // button6
			   // 
			   this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->button6->Location = System::Drawing::Point(754, 11);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(166, 68);
			   this->button6->TabIndex = 8;
			   this->button6->Text = L"search User By ID";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &managertPage::button6_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(268, 215);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(57, 19);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"UserID";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(757, 85);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(163, 20);
			   this->textBox1->TabIndex = 1;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &managertPage::textBox1_TextChanged);
			   // 
			   // userIDTextBox
			   // 
			   this->userIDTextBox->BackColor = System::Drawing::SystemColors::Control;
			   this->userIDTextBox->Location = System::Drawing::Point(323, 215);
			   this->userIDTextBox->Margin = System::Windows::Forms::Padding(2);
			   this->userIDTextBox->Name = L"userIDTextBox";
			   this->userIDTextBox->Size = System::Drawing::Size(166, 20);
			   this->userIDTextBox->TabIndex = 5;
			   // 
			   // button2
			   // 
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->button2->Location = System::Drawing::Point(757, 143);
			   this->button2->Margin = System::Windows::Forms::Padding(2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(166, 68);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Display Coach Classes";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &managertPage::button2_Click);
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(323, 143);
			   this->button1->Margin = System::Windows::Forms::Padding(2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(166, 68);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Delete User";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &managertPage::button1_Click_1);
			   // 
			   // button3
			   // 
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(520, 85);
			   this->button3->Margin = System::Windows::Forms::Padding(2);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(166, 68);
			   this->button3->TabIndex = 2;
			   this->button3->Text = L"Create Class";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &managertPage::button3_Click);
			   // 
			   // button4
			   // 
			   this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->button4->Location = System::Drawing::Point(323, 11);
			   this->button4->Margin = System::Windows::Forms::Padding(2);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(166, 68);
			   this->button4->TabIndex = 1;
			   this->button4->Text = L"Generate Monthly Report";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &managertPage::button4_Click);
			   // 
			   // AccName
			   // 
			   this->AccName->AutoSize = true;
			   this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->AccName->Location = System::Drawing::Point(23, 177);
			   this->AccName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->AccName->Name = L"AccName";
			   this->AccName->Size = System::Drawing::Size(51, 19);
			   this->AccName->TabIndex = 1;
			   this->AccName->Text = L"Name";
			   // 
			   // AccPic
			   // 
			   this->AccPic->BackColor = System::Drawing::SystemColors::ControlLight;
			   this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			   this->AccPic->Location = System::Drawing::Point(38, 11);
			   this->AccPic->Margin = System::Windows::Forms::Padding(2);
			   this->AccPic->Name = L"AccPic";
			   this->AccPic->Size = System::Drawing::Size(225, 150);
			   this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->AccPic->TabIndex = 0;
			   this->AccPic->TabStop = false;
			   // 
			   // managertPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ClientSize = System::Drawing::Size(955, 600);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"managertPage";
			   this->Text = L"Manager Page";
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   void deleteUser_and_cancelsubscription(System::String^ userID) {
			   if (String::IsNullOrEmpty(userID)) {
				   MessageBox::Show("Please enter a valid user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   std::string userIDStr = msclr::interop::marshal_as<std::string>(userID);

			   // Step 1: Check if the user exists in userList
			   if (userList.find(userIDStr) != userList.end()) {
				   // Step 2: Remove the user from the userList
				   userList.erase(userIDStr);


				   MessageBox::Show(String::Format("User {0} has been removed from the system.", userID), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
			   else {
				   MessageBox::Show("User not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }


	private:

		System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			// If the textbox is not visible, show the UI elements
			if (!userIDTextBox->Visible) {
				userIDTextBox->Visible = true;
				label1->Visible = true;
				panel1->Visible = false;
				panel3->Visible = false;
				textBox1->Visible = false;
				label6->Visible = false;
			}
			// If the textbox is already visible, process the input
			else {
				System::String^ userIDText = userIDTextBox->Text->Trim();
				if (!String::IsNullOrEmpty(userIDText)) {
					deleteUser_and_cancelsubscription(userIDText);
				}
				else {
					MessageBox::Show("Please enter a user ID to delete.", "Input Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			panel1->Visible = true;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
			panel3->Visible = true;
			panel3->BringToFront();

		}
		void displayCoachClasses(System::String^ coachIDText, System::Windows::Forms::RichTextBox^ outputBox) {
			extern unordered_map<std::string, Staff> staffList;
			extern unordered_map<std::string, GymClasses> gymClassList;

			System::String^ trimmedID = coachIDText->Trim();
			outputBox->Visible = false;
			outputBox->Clear();

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

			System::Text::StringBuilder^ report = gcnew System::Text::StringBuilder();
			report->AppendLine("Coach Information");
			report->AppendLine("-----------------------------");
			report->AppendLine("Name  : " + gcnew String(foundCoach.name.c_str()));
			report->AppendLine("Email : " + gcnew String(foundCoach.email.c_str()));
			report->AppendLine("Phone : " + gcnew String(foundCoach.phone.c_str()));
			report->AppendLine("");

			bool hasClasses = false;
			report->AppendLine("Assigned Classes:");
			report->AppendLine("-----------------------------");

			for (const auto& pair : gymClassList) {
				const GymClasses& gymClass = pair.second;
				if (gymClass.instructorID == coachID) {
					hasClasses = true;
					report->AppendLine("Class ID   : " + gcnew String(gymClass.classID.c_str()));
					report->AppendLine("Class Name : " + gcnew String(gymClass.className.c_str()));
					report->AppendLine("Sessions:");
					for (const auto& session : gymClass.sessions) {
						report->AppendLine("  Date: " + gcnew String(session.date.c_str()) +
							" | Time: " + gcnew String(session.startTime.c_str()) +
							" - " + gcnew String(session.endTime.c_str()));
					}
					report->AppendLine("-----------------------------");
				}
			}

			if (!hasClasses) {
				report->AppendLine("No classes assigned to this coach.");
			}

			// Display in the richTextBox
			outputBox->Font = gcnew System::Drawing::Font("Consolas", 10);
			outputBox->Text = report->ToString();
			outputBox->Visible = true;
		}


	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ coachIDText = textBox2->Text->Trim();
		if (String::IsNullOrEmpty(coachIDText)) {
			MessageBox::Show("Please enter a valid Coach ID in the text box.",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		displayCoachClasses(coachIDText, richTextBox2); 
	}


		   System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   CreatClassForm^ CreatClassFormPage = gcnew CreatClassForm();
			   this->Hide();
			   CreatClassFormPage->ShowDialog();
			   this->Show();
		   }


		   System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			   panel1->Visible = true;
			   panel3->Visible = false;

		   }
	private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
		// Hide and clear the report box every time before generating a new report
		this->richTextBox1->Visible = false;
		this->richTextBox1->Clear();

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
			String^ managedReport = gcnew String(report.c_str());

			this->richTextBox1->Font = gcnew System::Drawing::Font("Consolas", 10);
			this->richTextBox1->Text = managedReport;
			this->richTextBox1->Visible = true; // Show only when data exists
		}
		else {
			MessageBox::Show("No data available for the selected month.", "Report Empty",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}


	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchUserByID(textBox1->Text);
	}
	private: void SearchUserByID(System::String^ userIDText) {
		extern unordered_map<std::string, User> userList;
		System::String^ trimmedID = userIDText->Trim();
		if (String::IsNullOrEmpty(trimmedID)) {
			MessageBox::Show("Please enter a valid user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
			String^ userInfo = "Name: " + gcnew String(foundUser.name.c_str()) +
				"\nSubscription: " + gcnew String(foundUser.subscription.getType().c_str());
			MessageBox::Show(userInfo, "User Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("User not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!textBox1->Visible) {
			userIDTextBox->Visible = false;
			label1->Visible = false;
			panel1->Visible = false;
			panel3->Visible = false;
			textBox1->Visible = true;
			label6->Visible = true;
		}
		else {
			System::String^ userIDText = textBox1->Text->Trim();
			if (!String::IsNullOrEmpty(userIDText)) {
				SearchUserByID(userIDText);
			}
			else {
				MessageBox::Show("Please enter a user ID to search.", "Input Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   System::Void profile_pn_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainMenu_pn_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}