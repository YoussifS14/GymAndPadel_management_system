#pragma once
#include "../Structure.h"

namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 /// <summary>
	 /// Summary for PaymentPage
	 /// </summary>
	 public ref class PaymentPage : public System::Windows::Forms::Form
	 {
	 public:
		  property bool OperationResult;
		  float transactionCost;
		  PaymentPage(float Cost)
		  {
			   transactionCost = Cost;
			   InitializeComponent();
			   //
			   //TODO: Add the constructor code here
			   //
		  }

	 protected:
		  /// <summary>
		  /// Clean up any resources being used.
		  /// </summary>
		  ~PaymentPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::Button^ confirm_btn;
	 protected:
	 private: System::Windows::Forms::Button^ cancelling_btn;
	 private: System::Windows::Forms::TextBox^ CardID_txb;

	 private: System::Windows::Forms::Label^ label1;
	 private: System::Windows::Forms::Label^ label2;
	 private: System::Windows::Forms::TextBox^ CardExp_txb;





	 private: System::Windows::Forms::Label^ label4;
	 private: System::Windows::Forms::TextBox^ CardCVV_txb;

	 private: System::Windows::Forms::Label^ label5;
	 private: System::Windows::Forms::TextBox^ CardName_txb;
	 private: System::Windows::Forms::Label^ displayPrice;



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
			   this->confirm_btn = (gcnew System::Windows::Forms::Button());
			   this->cancelling_btn = (gcnew System::Windows::Forms::Button());
			   this->CardID_txb = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->CardExp_txb = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->CardCVV_txb = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->CardName_txb = (gcnew System::Windows::Forms::TextBox());
			   this->displayPrice = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // confirm_btn
			   // 
			   this->confirm_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->confirm_btn->Location = System::Drawing::Point(26, 396);
			   this->confirm_btn->Name = L"confirm_btn";
			   this->confirm_btn->Size = System::Drawing::Size(163, 64);
			   this->confirm_btn->TabIndex = 0;
			   this->confirm_btn->Text = L"Pay";
			   this->confirm_btn->UseVisualStyleBackColor = true;
			   this->confirm_btn->Click += gcnew System::EventHandler(this, &PaymentPage::confirm_btn_Click);
			   // 
			   // cancelling_btn
			   // 
			   this->cancelling_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->cancelling_btn->Location = System::Drawing::Point(267, 396);
			   this->cancelling_btn->Name = L"cancelling_btn";
			   this->cancelling_btn->Size = System::Drawing::Size(163, 64);
			   this->cancelling_btn->TabIndex = 1;
			   this->cancelling_btn->Text = L"cancel";
			   this->cancelling_btn->UseVisualStyleBackColor = true;
			   this->cancelling_btn->Click += gcnew System::EventHandler(this, &PaymentPage::cancelling_btn_Click);
			   // 
			   // CardID_txb
			   // 
			   this->CardID_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CardID_txb->Location = System::Drawing::Point(12, 87);
			   this->CardID_txb->Name = L"CardID_txb";
			   this->CardID_txb->Size = System::Drawing::Size(319, 30);
			   this->CardID_txb->TabIndex = 2;
			   this->CardID_txb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PaymentPage::CardID_txb_KeyPress);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(21, 59);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(126, 25);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"Card number";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(7, 243);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(190, 25);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"Expire date(YY/MM)";
			   // 
			   // CardExp_txb
			   // 
			   this->CardExp_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CardExp_txb->Location = System::Drawing::Point(12, 282);
			   this->CardExp_txb->Name = L"CardExp_txb";
			   this->CardExp_txb->Size = System::Drawing::Size(71, 30);
			   this->CardExp_txb->TabIndex = 4;
			   this->CardExp_txb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PaymentPage::CardMM_txb_KeyPress);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(276, 254);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(55, 25);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"CVV";
			   // 
			   // CardCVV_txb
			   // 
			   this->CardCVV_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CardCVV_txb->Location = System::Drawing::Point(276, 282);
			   this->CardCVV_txb->Name = L"CardCVV_txb";
			   this->CardCVV_txb->Size = System::Drawing::Size(61, 30);
			   this->CardCVV_txb->TabIndex = 8;
			   this->CardCVV_txb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PaymentPage::CardCVV_txb_KeyPress);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(21, 147);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(112, 25);
			   this->label5->TabIndex = 11;
			   this->label5->Text = L"Card Name";
			   // 
			   // CardName_txb
			   // 
			   this->CardName_txb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CardName_txb->Location = System::Drawing::Point(12, 175);
			   this->CardName_txb->Name = L"CardName_txb";
			   this->CardName_txb->Size = System::Drawing::Size(319, 30);
			   this->CardName_txb->TabIndex = 10;
			   this->CardName_txb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PaymentPage::CardName_txb_KeyPress);
			   // 
			   // displayPrice
			   // 
			   this->displayPrice->AutoSize = true;
			   this->displayPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->displayPrice->Location = System::Drawing::Point(21, 9);
			   this->displayPrice->Name = L"displayPrice";
			   this->displayPrice->Size = System::Drawing::Size(178, 25);
			   this->displayPrice->TabIndex = 12;
			   this->displayPrice->Text = L"Transaction price : ";
			   // 
			   // PaymentPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(466, 512);
			   this->ControlBox = false;
			   this->Controls->Add(this->displayPrice);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->CardName_txb);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->CardCVV_txb);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->CardExp_txb);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->CardID_txb);
			   this->Controls->Add(this->cancelling_btn);
			   this->Controls->Add(this->confirm_btn);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Name = L"PaymentPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"PaymentPage";
			   this->Load += gcnew System::EventHandler(this, &PaymentPage::PaymentPage_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		  }
#pragma endregion

	 private: System::Void CardID_txb_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		  if (!Char::IsDigit(e->KeyChar) && e->KeyChar != (char)Keys::Back && !(Control::ModifierKeys == Keys::Control)) {
			   e->Handled = true;
		  }
	 }
	 private: System::Void CardName_txb_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		  if (!Char::IsLetter(e->KeyChar) && e->KeyChar != (char)Keys::Back && e->KeyChar != ' ' && !(Control::ModifierKeys == Keys::Control)) {
			   e->Handled = true;
		  }

	 }
	 private: System::Void CardMM_txb_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		  if (!Char::IsDigit(e->KeyChar) && e->KeyChar != (char)Keys::Back) {
			   e->Handled = true;
		  }
		  if (CardExp_txb->Text->Length == 2 && e->KeyChar != (char)Keys::Back) {
			   CardExp_txb->Text += "/";
			   CardExp_txb->SelectionStart = CardExp_txb->Text->Length;
		  }
		  if (CardExp_txb->Text->Length == 5) {
			   if (e->KeyChar != (char)Keys::Back) {
					e->Handled = true;
			   }
		  }

	 }

	 private: System::Void CardCVV_txb_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		  if (!Char::IsDigit(e->KeyChar) && e->KeyChar != (char)Keys::Back) {
			   e->Handled = true;
		  }
	 }

	 private: System::Void PaymentPage_Load(System::Object^ sender, System::EventArgs^ e) {
		  displayPrice->Text = "Transaction price : " + transactionCost.ToString() + " $";
	 }
	 private: System::Void confirm_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  // Check if all fields are filled
		  if (CardID_txb->Text == "" || CardExp_txb->Text == "" || CardCVV_txb->Text == "" || CardName_txb->Text == "") {
			   MessageBox::Show("Please fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  // Check if the card number is valid
		  if (CardID_txb->Text->Length != 16) {
			   MessageBox::Show("Invalid card number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  // Check if the expiration date is valid

		  string ExpDate = msclr::interop::marshal_as<string>(CardExp_txb->Text);

		  stringstream ss(ExpDate);
		  string temp;
		  getline(ss, temp, '/');
		  int year = stoi(temp);
		  int month;
		  ss >> month;


		  if (month < 1 || month > 12 || year < 0 || year > 99) {
			   MessageBox::Show("Invalid expiration date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  // Check if the CVV is valid
		  if (CardCVV_txb->Text->Length != 3) {
			   MessageBox::Show("Invalid CVV", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return;
		  }
		  CreditCard card;
		  card.cardID = msclr::interop::marshal_as<string>(CardID_txb->Text);
		  card.cardCVV = msclr::interop::marshal_as<string>(CardCVV_txb->Text);
		  card.cardName = msclr::interop::marshal_as<string>(CardName_txb->Text);
		  card.ExpirationDate = msclr::interop::marshal_as<string>(CardExp_txb->Text);
		  card.balance = transactionCost;

		  if (CreditCard::validateCard(card)) {// transaction is successful
			   OperationResult = true;
			   MessageBox::Show("Payment successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   this->Close();
		  }
		  else {
			   MessageBox::Show(CardExp_txb->Text, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			   MessageBox::Show("Payment failed! Please check your card details or card balance.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		  }

	 }
	 private: System::Void cancelling_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  OperationResult = false;

		  this->Close();
	 }
	 };
}
