#pragma once
#include "Structure.h"
#include "feature_GUI/LoadingPage.h"
#include "feature_GUI/PaymentPage.h"
#include"managertPage.h"
#include "staffPage.h"
#include "userPage.h"	 
#include<windows.h>
#include"sighup.h"



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
	 /// Summary for LoginPage
	 /// </summary>
	 public ref class LoginPage : public System::Windows::Forms::Form
	 {
	 public:
		  //  msclr::interop::marshal_context context;

		  LoginPage(void)
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
		  ~LoginPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private:
		  System::Void MakePictureCircular(PictureBox^ picBox) {

			   Bitmap^ bmp = gcnew Bitmap(picBox->Image);
			   Bitmap^ circularBmp = gcnew Bitmap(bmp->Width, bmp->Height);

			   Graphics^ g = Graphics::FromImage(circularBmp);
			   g->SmoothingMode = SmoothingMode::AntiAlias;

			   GraphicsPath^ path = gcnew GraphicsPath();
			   path->AddEllipse(0, 0, bmp->Width, bmp->Height);

			   g->SetClip(path);
			   g->DrawImage(bmp, 0, 0);

			   picBox->Image = circularBmp;
		  }
		  System::Void  setSavePic(PictureBox^ picBox) {
			   OpenFileDialog^ open = gcnew OpenFileDialog;
			   open->Filter = "Image Files |.jpg; *.png;.jpeg;";
			   if (open->ShowDialog() == aliens::DialogResult::OK) {
					picBox->Image = Image::FromFile(open->FileName);

					String^ newPATH = PicAsset + "new add" + Path::GetExtension(open->FileName);
					if (File::Exists(newPATH)) {
						 File::Delete(newPATH);
					}

					MakePictureCircular(picBox);
					MessageBox::Show(newPATH);
					picBox->Image->Save(newPATH);

			   }

		  }
	 private: System::Windows::Forms::Label^ userName_lb;
	 private: System::Windows::Forms::Button^ Login_btn;
	 private: System::Windows::Forms::TextBox^ userName_txb;
	 private: System::Windows::Forms::TextBox^ password_txb;
	 private: System::Windows::Forms::Label^ password_lb;
	 private: System::Windows::Forms::Button^ SwitchHide;
	 private: System::Windows::Forms::Label^ label1;
	 private: System::Windows::Forms::Button^ button1;
	 protected:

	 private:
		  /// <summary>
		  /// Required designer variable.
		  /// </summary>
		  System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		  /// <summary>
		  /// Required method for Designer support - do not modify
		  /// the contents of this method with the code editor.
		  /// </summary>
		  void InitializeComponent(void)
		  {
			  System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginPage::typeid));
			  this->userName_lb = (gcnew System::Windows::Forms::Label());
			  this->Login_btn = (gcnew System::Windows::Forms::Button());
			  this->userName_txb = (gcnew System::Windows::Forms::TextBox());
			  this->password_txb = (gcnew System::Windows::Forms::TextBox());
			  this->password_lb = (gcnew System::Windows::Forms::Label());
			  this->SwitchHide = (gcnew System::Windows::Forms::Button());
			  this->label1 = (gcnew System::Windows::Forms::Label());
			  this->button1 = (gcnew System::Windows::Forms::Button());
			  this->SuspendLayout();
			  // 
			  // userName_lb
			  // 
			  this->userName_lb->AutoSize = true;
			  this->userName_lb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			  this->userName_lb->Location = System::Drawing::Point(294, 200);
			  this->userName_lb->Name = L"userName_lb";
			  this->userName_lb->Size = System::Drawing::Size(91, 32);
			  this->userName_lb->TabIndex = 0;
			  this->userName_lb->Text = L"Email";
			  // 
			  // Login_btn
			  // 
			  this->Login_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->Login_btn->Location = System::Drawing::Point(471, 552);
			  this->Login_btn->Name = L"Login_btn";
			  this->Login_btn->Size = System::Drawing::Size(311, 69);
			  this->Login_btn->TabIndex = 1;
			  this->Login_btn->Text = L"Sign In ";
			  this->Login_btn->UseVisualStyleBackColor = true;
			  this->Login_btn->Click += gcnew System::EventHandler(this, &LoginPage::Login_btn_Click);
			  // 
			  // userName_txb
			  // 
			  this->userName_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			  this->userName_txb->Location = System::Drawing::Point(471, 200);
			  this->userName_txb->Name = L"userName_txb";
			  this->userName_txb->Size = System::Drawing::Size(552, 38);
			  this->userName_txb->TabIndex = 2;
			  // 
			  // password_txb
			  // 
			  this->password_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			  this->password_txb->Location = System::Drawing::Point(471, 350);
			  this->password_txb->Name = L"password_txb";
			  this->password_txb->Size = System::Drawing::Size(552, 38);
			  this->password_txb->TabIndex = 4;
			  this->password_txb->UseSystemPasswordChar = true;
			  // 
			  // password_lb
			  // 
			  this->password_lb->AutoSize = true;
			  this->password_lb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			  this->password_lb->Location = System::Drawing::Point(294, 350);
			  this->password_lb->Name = L"password_lb";
			  this->password_lb->Size = System::Drawing::Size(146, 32);
			  this->password_lb->TabIndex = 3;
			  this->password_lb->Text = L"Password";
			  // 
			  // SwitchHide
			  // 
			  this->SwitchHide->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SwitchHide.BackgroundImage")));
			  this->SwitchHide->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			  this->SwitchHide->Location = System::Drawing::Point(1048, 355);
			  this->SwitchHide->Name = L"SwitchHide";
			  this->SwitchHide->Size = System::Drawing::Size(36, 32);
			  this->SwitchHide->TabIndex = 5;
			  this->SwitchHide->UseVisualStyleBackColor = true;
			  this->SwitchHide->Click += gcnew System::EventHandler(this, &LoginPage::SwitchHide_Click);
			  // 
			  // label1
			  // 
			  this->label1->AutoSize = true;
			  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->label1->Location = System::Drawing::Point(339, 677);
			  this->label1->Name = L"label1";
			  this->label1->Size = System::Drawing::Size(282, 22);
			  this->label1->TabIndex = 6;
			  this->label1->Text = L"No account...want to sign up\?!";
			  // 
			  // button1
			  // 
			  this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->button1->Location = System::Drawing::Point(652, 674);
			  this->button1->Name = L"button1";
			  this->button1->Size = System::Drawing::Size(139, 31);
			  this->button1->TabIndex = 7;
			  this->button1->Text = L"Sign up";
			  this->button1->UseVisualStyleBackColor = true;
			  this->button1->Click += gcnew System::EventHandler(this, &LoginPage::button1_Click);
			  // 
			  // LoginPage
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->ClientSize = System::Drawing::Size(1273, 739);
			  this->Controls->Add(this->button1);
			  this->Controls->Add(this->label1);
			  this->Controls->Add(this->SwitchHide);
			  this->Controls->Add(this->password_txb);
			  this->Controls->Add(this->password_lb);
			  this->Controls->Add(this->userName_txb);
			  this->Controls->Add(this->Login_btn);
			  this->Controls->Add(this->userName_lb);
			  this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			  this->Name = L"LoginPage";
			  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			  this->Text = L"LoginPage";
			  this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginPage::LoginPage_FormClosing);
			  this->Load += gcnew System::EventHandler(this, &LoginPage::LoginPage_Load);
			  this->ResumeLayout(false);
			  this->PerformLayout();

		  }
#pragma endregion
	 private: System::Void LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
		  this->Hide(); // Hide the login page when it loads
		  LoadingPage^ loading = gcnew LoadingPage();
		  loading->ShowDialog();
		  this->Show(); // Show the login page after loading


	 }
	 private: System::Void Login_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  string email = msclr::interop::marshal_as<string>(userName_txb->Text);
		  string password = msclr::interop::marshal_as<string>(password_txb->Text);
		  if (Staff::login(email, password)) {


			   string id = "";
			   std::string staffRole = "";

			   for (auto& pair : staffList) {
					if (pair.second.email == email) {
						 id = pair.second.ID;
						 break;
					}
			   }

			   // Check if staff exists in the list
			   auto it = staffList.find(id);
			   if (it != staffList.end()) {
					staffRole = it->second.role; // Retrieve role from map
			   }
			   else {
					MessageBox::Show("Staff email not found in staffList");
					return;
			   }

			   LoadingPage^ loading = gcnew LoadingPage();
			   MessageBox::Show("Login successful as Staff");
			   this->Hide();
			   loading->label1->Text = "Loading Staff Page...";
			   loading->ShowDialog();

			   if (staffRole == "manager") {
					managertPage^ managerPage = gcnew managertPage();
					managerPage->ShowDialog();

			   }
			   else {
					staffPage^ staffPg = gcnew staffPage();
					staffPg->ShowDialog();


			   }

			   userName_txb->Text = "";
			   password_txb->Text = "";
			   this->Show();
		  }

		  else if (User::login(email, password)) {
			   LoadingPage^ loading = gcnew LoadingPage();
			   //  MessageBox::Show("Login successful as User");
			   if (userList[loginID].subscription.get_is_VIP()) {
					loading->label1->Text = "Loading Vip...";
			   }
			   else {
					loading->label1->Text = "Loading...";
			   }
			   this->Hide(); // Hide the login page
			   //loading->label1->Text = "Loading User Page...";
			   loading->ShowDialog();
			   userPage^ userPg = gcnew userPage();
			   userName_txb->Text = "";
			   password_txb->Text = "";
			   userPg->AccName->Text = gcnew String(userList[loginID].name.c_str());
			   userPg->Wallet->Text = "Your wallet $" + userList[loginID].myWallet.ToString();
			   userPg->ShowDialog();
			   this->Show();
			   // Proceed to the next form or functionality
		  }
		  else {
			   MessageBox::Show("Invalid email or password");
		  }
	 }
	 private: System::Void SwitchHide_Click(System::Object^ sender, System::EventArgs^ e) {
		  password_txb->UseSystemPasswordChar = !password_txb->UseSystemPasswordChar;
	 }

	 private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		  sighup^ signupPage = gcnew sighup();
		  this->Hide();
		  signupPage->ShowDialog();
		  this->Show();

	 }

	 private: System::Void LoginPage_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		  LoadingPage^ loading = gcnew LoadingPage();
		  loading->label1->Text = "Exiting...";
		  this->Hide();
		  loading->ShowDialog();
	 }
	 };
}