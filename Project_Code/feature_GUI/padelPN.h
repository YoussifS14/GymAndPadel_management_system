#pragma once
#include "Structure.h"
#include "feature_GUI/PaymentPage.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectCode {

	 /// <summary>
	 /// Summary for padelPN
	 /// </summary>
	 public ref class padelPN : public System::Windows::Forms::UserControl
	 {
	 public:
		  msclr::interop::marshal_context context;
		  padelPN(void)
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
		  ~padelPN()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 public: System::Windows::Forms::Label^ courtName;
	 public: System::Windows::Forms::Label^ courtLoc;
	 public: System::Windows::Forms::Label^ courtPrice;
	 public: System::Windows::Forms::Label^ courtDate;
	 public: System::Windows::Forms::Label^ courtAva;
	 private: System::Windows::Forms::Button^ reserCourt;
	 public:
	 protected:

	 protected:





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
			  this->courtLoc = (gcnew System::Windows::Forms::Label());
			  this->courtPrice = (gcnew System::Windows::Forms::Label());
			  this->courtDate = (gcnew System::Windows::Forms::Label());
			  this->courtAva = (gcnew System::Windows::Forms::Label());
			  this->reserCourt = (gcnew System::Windows::Forms::Button());
			  this->SuspendLayout();
			  // 
			  // courtName
			  // 
			  this->courtName->AutoSize = true;
			  this->courtName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtName->ForeColor = System::Drawing::Color::White;
			  this->courtName->Location = System::Drawing::Point(20, 15);
			  this->courtName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->courtName->Name = L"courtName";
			  this->courtName->Size = System::Drawing::Size(68, 24);
			  this->courtName->TabIndex = 0;
			  this->courtName->Text = L"name :";
			  // 
			  // courtLoc
			  // 
			  this->courtLoc->AutoSize = true;
			  this->courtLoc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtLoc->ForeColor = System::Drawing::Color::White;
			  this->courtLoc->Location = System::Drawing::Point(20, 62);
			  this->courtLoc->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->courtLoc->Name = L"courtLoc";
			  this->courtLoc->Size = System::Drawing::Size(91, 24);
			  this->courtLoc->TabIndex = 1;
			  this->courtLoc->Text = L"Location :";
			  // 
			  // courtPrice
			  // 
			  this->courtPrice->AutoSize = true;
			  this->courtPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtPrice->ForeColor = System::Drawing::Color::White;
			  this->courtPrice->Location = System::Drawing::Point(20, 108);
			  this->courtPrice->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->courtPrice->Name = L"courtPrice";
			  this->courtPrice->Size = System::Drawing::Size(68, 24);
			  this->courtPrice->TabIndex = 2;
			  this->courtPrice->Text = L"Price : ";
			  // 
			  // courtDate
			  // 
			  this->courtDate->AutoSize = true;
			  this->courtDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtDate->ForeColor = System::Drawing::Color::White;
			  this->courtDate->Location = System::Drawing::Point(20, 154);
			  this->courtDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->courtDate->Name = L"courtDate";
			  this->courtDate->Size = System::Drawing::Size(58, 24);
			  this->courtDate->TabIndex = 3;
			  this->courtDate->Text = L"Date :";
			  // 
			  // courtAva
			  // 
			  this->courtAva->AutoSize = true;
			  this->courtAva->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->courtAva->ForeColor = System::Drawing::Color::Green;
			  this->courtAva->Location = System::Drawing::Point(20, 201);
			  this->courtAva->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			  this->courtAva->Name = L"courtAva";
			  this->courtAva->Size = System::Drawing::Size(86, 24);
			  this->courtAva->TabIndex = 4;
			  this->courtAva->Text = L"Available";
			  // 
			  // reserCourt
			  // 
			  this->reserCourt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				  static_cast<System::Int32>(static_cast<System::Byte>(0)));
			  this->reserCourt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				  static_cast<System::Byte>(0)));
			  this->reserCourt->Location = System::Drawing::Point(421, 201);
			  this->reserCourt->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->reserCourt->Name = L"reserCourt";
			  this->reserCourt->Size = System::Drawing::Size(160, 42);
			  this->reserCourt->TabIndex = 5;
			  this->reserCourt->Text = L"Reserve";
			  this->reserCourt->UseVisualStyleBackColor = false;
			  this->reserCourt->Click += gcnew System::EventHandler(this, &padelPN::reserCourt_Click);
			  // 
			  // padelPN
			  // 
			  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->Controls->Add(this->reserCourt);
			  this->Controls->Add(this->courtAva);
			  this->Controls->Add(this->courtDate);
			  this->Controls->Add(this->courtPrice);
			  this->Controls->Add(this->courtLoc);
			  this->Controls->Add(this->courtName);
			  this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			  this->Name = L"padelPN";
			  this->Padding = System::Windows::Forms::Padding(0, 0, 0, 8);
			  this->Size = System::Drawing::Size(608, 258);
			  this->ResumeLayout(false);
			  this->PerformLayout();

		  }
#pragma endregion
	 private: System::Void reserCourt_Click(System::Object^ sender, System::EventArgs^ e) {

		  string storeCourtName = context.marshal_as<string>(courtName->Text);
		  storeCourtName = storeCourtName.substr(storeCourtName.find(":") + 1); // Remove "name : "

		  string courtIndex = PadelCourt::searchCourt(storeCourtName);
		  if (courtIndex == "") {
			   MessageBox::Show("Court not found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  PaymentPage^ pay = gcnew PaymentPage(courtList[courtIndex].price);
		  pay->ShowDialog();
		  if (pay->OperationResult) {
			   Slot ss;
			   ss.date = context.marshal_as<std::string>(courtDate->Text);
			   ss.date = ss.date.substr(ss.date.find(":") + 1); // Remove "name : "
			   String^ tagString = dynamic_cast<String^>(courtDate->Tag);
			   ss.startTime = context.marshal_as<std::string>(tagString);
			   ss.courtName = storeCourtName;
			   ss.ID = Slot::generateSlotID();

			   userList[loginID].myReservations.push_back(ss);
			   courtList[courtIndex].slots.push_back(ss);
			   this->Visible = false;

		  }
		  else {
			   MessageBox::Show("Payment failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
	 }
	 };
}
