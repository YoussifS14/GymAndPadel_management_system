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
	 /// Summary for CancellingReserv
	 /// </summary>
	 public ref class CancellingReserv : public System::Windows::Forms::UserControl
	 {
	 public:
		  CancellingReserv(void)
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
		  ~CancellingReserv()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 public: System::Windows::Forms::Label^ courtName;
	 protected:
	 public: System::Windows::Forms::Label^ ReservDate;
	 public: System::Windows::Forms::Label^ StartingTime;
	 public: System::Windows::Forms::Button^ Cancelling_btn;
	 public: System::Windows::Forms::Label^ Warning;



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
			  this->courtName = (gcnew System::Windows::Forms::Label());
			  this->ReservDate = (gcnew System::Windows::Forms::Label());
			  this->StartingTime = (gcnew System::Windows::Forms::Label());
			  this->Cancelling_btn = (gcnew System::Windows::Forms::Button());
			  this->Warning = (gcnew System::Windows::Forms::Label());
			  this->SuspendLayout();
			  // 
			  // courtName
			  // 
			  this->courtName->AutoSize = true;
			  this->courtName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->courtName->Location = System::Drawing::Point(3, 19);
			  this->courtName->Name = L"courtName";
			  this->courtName->Size = System::Drawing::Size(180, 32);
			  this->courtName->TabIndex = 0;
			  this->courtName->Text = L"Court Name :";
			  // 
			  // ReservDate
			  // 
			  this->ReservDate->AutoSize = true;
			  this->ReservDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->ReservDate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->ReservDate->Location = System::Drawing::Point(3, 71);
			  this->ReservDate->Name = L"ReservDate";
			  this->ReservDate->Size = System::Drawing::Size(196, 32);
			  this->ReservDate->TabIndex = 1;
			  this->ReservDate->Text = L"Booking date :";
			  // 
			  // StartingTime
			  // 
			  this->StartingTime->AutoSize = true;
			  this->StartingTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->StartingTime->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->StartingTime->Location = System::Drawing::Point(3, 122);
			  this->StartingTime->Name = L"StartingTime";
			  this->StartingTime->Size = System::Drawing::Size(198, 32);
			  this->StartingTime->TabIndex = 2;
			  this->StartingTime->Text = L"Starting Time :";
			  // 
			  // Cancelling_btn
			  // 
			  this->Cancelling_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->Cancelling_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->Cancelling_btn->Location = System::Drawing::Point(686, 132);
			  this->Cancelling_btn->Name = L"Cancelling_btn";
			  this->Cancelling_btn->Size = System::Drawing::Size(135, 39);
			  this->Cancelling_btn->TabIndex = 3;
			  this->Cancelling_btn->Text = L"Cancel";
			  this->Cancelling_btn->UseVisualStyleBackColor = false;
			  this->Cancelling_btn->Click += gcnew System::EventHandler(this, &CancellingReserv::Cancelling_btn_Click);
			  // 
			  // Warning
			  // 
			  this->Warning->AutoSize = true;
			  this->Warning->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->Warning->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->Warning->Location = System::Drawing::Point(240, 167);
			  this->Warning->Name = L"Warning";
			  this->Warning->Size = System::Drawing::Size(0, 25);
			  this->Warning->TabIndex = 4;
			  // 
			  // CancellingReserv
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->BackColor = System::Drawing::Color::Transparent;
			  this->Controls->Add(this->Warning);
			  this->Controls->Add(this->Cancelling_btn);
			  this->Controls->Add(this->StartingTime);
			  this->Controls->Add(this->ReservDate);
			  this->Controls->Add(this->courtName);
			  this->Name = L"CancellingReserv";
			  this->Padding = System::Windows::Forms::Padding(0, 0, 0, 10);
			  this->Size = System::Drawing::Size(840, 202);
			  this->ResumeLayout(false);
			  this->PerformLayout();

		  }
#pragma endregion
	 private: System::Void Cancelling_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  String^ courtID = (String^)courtName->Tag;
		  string courtIDString = msclr::interop::marshal_as<string>(courtID);
		  string courtNameString = msclr::interop::marshal_as<string>(courtName->Text);
		  courtNameString = courtNameString.substr(courtNameString.find(":") + 1);

		  string courtIndex = PadelCourt::searchCourt(courtNameString);
		  int slotIndex = userList[loginID].searchSlot(courtIDString);
		  if (slotIndex != -1 || courtIndex != "") {
			   userList[loginID].myReservations.erase(userList[loginID].myReservations.begin() + slotIndex);
			   courtList[courtIndex].deleteSlot(courtIDString);
			   MessageBox::Show("Reservation cancelled successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   this->Enabled = false;
		  }
		  else {
			   MessageBox::Show("Reservation not found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		  }
	 }
	 };
}
