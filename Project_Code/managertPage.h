#pragma once
#include "Structure.h"
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
	 private: System::Windows::Forms::Button^ button5;
	 private: System::Windows::Forms::Button^ button6;
			System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			void InitializeComponent(void)
			{
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(managertPage::typeid));
				 this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
				 this->profile_pn = (gcnew System::Windows::Forms::Panel());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->userIDTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->AccName = (gcnew System::Windows::Forms::Label());
				 this->AccPic = (gcnew System::Windows::Forms::PictureBox());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->MainMenu_pn->SuspendLayout();
				 this->profile_pn->SuspendLayout();
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
				 // 
				 // profile_pn
				 // 
				 this->profile_pn->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 this->profile_pn->Controls->Add(this->button6);
				 this->profile_pn->Controls->Add(this->button5);
				 this->profile_pn->Controls->Add(this->label1);
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
				 this->profile_pn->Size = System::Drawing::Size(944, 282);
				 this->profile_pn->TabIndex = 1;
				 this->profile_pn->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &managertPage::profile_pn_Paint);
				 // 
				 // button5
				 // 
				 this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->button5->Location = System::Drawing::Point(757, 12);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(166, 68);
				 this->button5->TabIndex = 7;
				 this->button5->Text = L"notify Expiring Subscriptions";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &managertPage::button5_Click);
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
				 this->button2->Location = System::Drawing::Point(538, 143);
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
				 this->button3->Location = System::Drawing::Point(538, 11);
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
				 // button6
				 // 
				 this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->button6->Location = System::Drawing::Point(757, 143);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(166, 68);
				 this->button6->TabIndex = 8;
				 this->button6->Text = L"search User By ID";
				 this->button6->UseVisualStyleBackColor = true;
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

					  // Step 3: Rewrite the users to the file (excluding the deleted user)
					  std::ofstream outFile("Data/usrData.csv");

					  if (!outFile.is_open()) {
						   MessageBox::Show("Failed to open the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   return;
					  }

					  // Rewrite the header
					  outFile << "ID,name,email,password,Birthday,subscription\n";

					  // Step 4: Write all remaining users back to the file
					  /*for (const auto& pair : userList) {
						   const User& user = pair.second;
						   outFile << user.ID << "," << user.name << "," << user.email << ","
								<< user.password << "," << user.Birthday << "," << user.subscription.getType() << "\n";
					  }*/



					  outFile.close();

					  MessageBox::Show(String::Format("User {0} has been removed from the system.", userID), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 }
				 else {
					  MessageBox::Show("User not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			}


	 private:
		  System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ userIDText = userIDTextBox->Text->Trim();
			   deleteUser_and_cancelsubscription(userIDText);
		  }

		  System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		  {
			   MessageBox::Show("Display Coach Classes functionality not implemented.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		  }

		  System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
		  {
			   MessageBox::Show("Create Class functionality not implemented.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		  }

		  System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
		  {
			   MessageBox::Show("Generate Monthly Report functionality not implemented.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		  }
	 private: System::Void profile_pn_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	 }
	 private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	 }
	 };
}