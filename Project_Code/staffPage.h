#pragma once
#include "Structure.h"
#include"userExpired.h"
#include "sighup.h"
namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 /// <summary>
	 /// Summary for staffPage
	 /// </summary>
	 public ref class staffPage : public System::Windows::Forms::Form
	 {
	 public:
		  staffPage(void)
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
		  ~staffPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::Panel^ MainMenu_pn;
	 protected:
	 private: System::Windows::Forms::Panel^ profile_pn;
	 private: System::Windows::Forms::Label^ AccName;
	 private: System::Windows::Forms::PictureBox^ AccPic;
	 private: System::Windows::Forms::Panel^ MainPage;
	 private: System::Windows::Forms::Button^ SendNotification;
	 private: System::Windows::Forms::FlowLayoutPanel^ ListOFUserEX;
	 private: System::Windows::Forms::Button^ AddNewUser;



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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(staffPage::typeid));
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->SendNotification = (gcnew System::Windows::Forms::Button());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainPage = (gcnew System::Windows::Forms::Panel());
			   this->ListOFUserEX = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->AddNewUser = (gcnew System::Windows::Forms::Button());
			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->MainPage->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->Controls->Add(this->AddNewUser);
			   this->MainMenu_pn->Controls->Add(this->SendNotification);
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(313, 739);
			   this->MainMenu_pn->TabIndex = 1;
			   // 
			   // SendNotification
			   // 
			   this->SendNotification->Dock = System::Windows::Forms::DockStyle::Top;
			   this->SendNotification->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->SendNotification->Location = System::Drawing::Point(0, 212);
			   this->SendNotification->Name = L"SendNotification";
			   this->SendNotification->Size = System::Drawing::Size(313, 68);
			   this->SendNotification->TabIndex = 2;
			   this->SendNotification->Text = L"Send Notification";
			   this->SendNotification->UseVisualStyleBackColor = true;
			   this->SendNotification->Click += gcnew System::EventHandler(this, &staffPage::SendNotification_Click);
			   // 
			   // profile_pn
			   // 
			   this->profile_pn->Controls->Add(this->AccName);
			   this->profile_pn->Controls->Add(this->AccPic);
			   this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			   this->profile_pn->Location = System::Drawing::Point(0, 0);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(313, 212);
			   this->profile_pn->TabIndex = 1;
			   // 
			   // AccName
			   // 
			   this->AccName->AutoSize = true;
			   this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->AccName->Location = System::Drawing::Point(3, 175);
			   this->AccName->Name = L"AccName";
			   this->AccName->Size = System::Drawing::Size(58, 22);
			   this->AccName->TabIndex = 1;
			   this->AccName->Text = L"label1";
			   // 
			   // AccPic
			   // 
			   this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			   this->AccPic->Location = System::Drawing::Point(38, 12);
			   this->AccPic->Name = L"AccPic";
			   this->AccPic->Size = System::Drawing::Size(213, 147);
			   this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->AccPic->TabIndex = 0;
			   this->AccPic->TabStop = false;
			   // 
			   // MainPage
			   // 
			   this->MainPage->Controls->Add(this->ListOFUserEX);
			   this->MainPage->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->MainPage->Location = System::Drawing::Point(313, 0);
			   this->MainPage->Name = L"MainPage";
			   this->MainPage->Size = System::Drawing::Size(960, 739);
			   this->MainPage->TabIndex = 2;
			   // 
			   // ListOFUserEX
			   // 
			   this->ListOFUserEX->AutoScroll = true;
			   this->ListOFUserEX->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->ListOFUserEX->Location = System::Drawing::Point(0, 0);
			   this->ListOFUserEX->Name = L"ListOFUserEX";
			   this->ListOFUserEX->Size = System::Drawing::Size(960, 739);
			   this->ListOFUserEX->TabIndex = 0;
			   // 
			   // AddNewUser
			   // 
			   this->AddNewUser->Dock = System::Windows::Forms::DockStyle::Top;
			   this->AddNewUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->AddNewUser->Location = System::Drawing::Point(0, 280);
			   this->AddNewUser->Name = L"AddNewUser";
			   this->AddNewUser->Size = System::Drawing::Size(313, 76);
			   this->AddNewUser->TabIndex = 3;
			   this->AddNewUser->Text = L"Register new user";
			   this->AddNewUser->UseVisualStyleBackColor = true;
			   this->AddNewUser->Click += gcnew System::EventHandler(this, &staffPage::AddNewUser_Click);
			   // 
			   // staffPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1273, 739);
			   this->Controls->Add(this->MainPage);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"staffPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"staffPage";
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->MainPage->ResumeLayout(false);
			   this->ResumeLayout(false);

		  }
#pragma endregion

	 private: System::Void SendNotification_Click(System::Object^ sender, System::EventArgs^ e) {

		  ListOFUserEX->Controls->Clear();
		  // Get the list of expired users
		  for (auto& entry : userList) {
			   User& user = entry.second;
			   int remainingDays = user.subscription.getRemainingDays();
			   if (remainingDays < 7) {
					// Create a new userExpired control
					userExpired^ Expired = gcnew userExpired();
					Expired->name->Text = "Name: " + gcnew  String(user.name.c_str());
					Expired->name->Tag = gcnew String(user.ID.c_str());
					Expired->expireDate->Text = "Expire date: " + gcnew String(user.subscription.getEndDate().c_str());
					Expired->TypeOFSub->Text = "Subscription Type: " + gcnew String(user.subscription.getType().c_str());
					Expired->AccType->Text = "Account Type: " + gcnew String(user.subscription.get_is_VIP() ? "VIP" : "Normal");


					ListOFUserEX->Controls->Add(Expired);
			   }
		  }
	 }
	 private: System::Void AddNewUser_Click(System::Object^ sender, System::EventArgs^ e) {
		  sighup^ newPage = gcnew sighup();
		  newPage->groupBox1->Visible = false;

		  newPage->ShowDialog();

	 }
	 };
}
