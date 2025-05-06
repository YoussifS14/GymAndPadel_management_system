#pragma once
#include "Structure.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectCode {

	 /// <summary>
	 /// Summary for userExpired
	 /// </summary>
	 public ref class userExpired : public System::Windows::Forms::UserControl
	 {
	 public:
		  userExpired(void)
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
		  ~userExpired()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 public: System::Windows::Forms::Label^ name;
	 protected:
	 public: System::Windows::Forms::Label^ expireDate;
	 public: System::Windows::Forms::Label^ TypeOFSub;
	 public: System::Windows::Forms::Label^ AccType;
	 public: System::Windows::Forms::Button^ button1;

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
			   this->name = (gcnew System::Windows::Forms::Label());
			   this->expireDate = (gcnew System::Windows::Forms::Label());
			   this->TypeOFSub = (gcnew System::Windows::Forms::Label());
			   this->AccType = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // name
			   // 
			   this->name->AutoSize = true;
			   this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->name->Location = System::Drawing::Point(14, 14);
			   this->name->Name = L"name";
			   this->name->Size = System::Drawing::Size(92, 32);
			   this->name->TabIndex = 0;
			   this->name->Text = L"label1";
			   // 
			   // expireDate
			   // 
			   this->expireDate->AutoSize = true;
			   this->expireDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->expireDate->Location = System::Drawing::Point(14, 68);
			   this->expireDate->Name = L"expireDate";
			   this->expireDate->Size = System::Drawing::Size(92, 32);
			   this->expireDate->TabIndex = 1;
			   this->expireDate->Text = L"label1";
			   // 
			   // TypeOFSub
			   // 
			   this->TypeOFSub->AutoSize = true;
			   this->TypeOFSub->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->TypeOFSub->Location = System::Drawing::Point(14, 122);
			   this->TypeOFSub->Name = L"TypeOFSub";
			   this->TypeOFSub->Size = System::Drawing::Size(92, 32);
			   this->TypeOFSub->TabIndex = 2;
			   this->TypeOFSub->Text = L"label1";
			   // 
			   // AccType
			   // 
			   this->AccType->AutoSize = true;
			   this->AccType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->AccType->Location = System::Drawing::Point(14, 176);
			   this->AccType->Name = L"AccType";
			   this->AccType->Size = System::Drawing::Size(92, 32);
			   this->AccType->TabIndex = 3;
			   this->AccType->Text = L"label1";
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(814, 162);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(128, 52);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Send";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &userExpired::button1_Click);
			   // 
			   // userExpired
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->AccType);
			   this->Controls->Add(this->TypeOFSub);
			   this->Controls->Add(this->expireDate);
			   this->Controls->Add(this->name);
			   this->Name = L"userExpired";
			   this->Padding = System::Windows::Forms::Padding(0, 0, 0, 15);
			   this->Size = System::Drawing::Size(960, 244);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		  }
#pragma endregion
	 private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		  String^ userID = name->Tag->ToString();
		  string userIDStr = marshal_as<string>(userID);

		  string  msg = Notification::standardMessage(userList[userIDStr], "", 0);
		  Notification notify;
		  notify.message = msg;
		  userList[userIDStr].myNotifications.push_back(notify);
		  MessageBox::Show("The message was sent successfully.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
		  button1->Enabled = false;



	 }
	 };
}
