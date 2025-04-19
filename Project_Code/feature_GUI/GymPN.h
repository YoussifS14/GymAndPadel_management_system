#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProjectCode {

	 /// <summary>
	 /// Summary for GymPN
	 /// </summary>
	 public ref class GymPN : public System::Windows::Forms::UserControl
	 {
	 public:
		  GymPN(void)
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
		  ~GymPN()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 public: System::Windows::Forms::Label^ CName;
	 public: System::Windows::Forms::Label^ CInstructor;

	 public: System::Windows::Forms::Label^ CStart;
	 public: System::Windows::Forms::Label^ CEnd;
	 public: System::Windows::Forms::Button^ Reserv_btn;
	 public: System::Windows::Forms::Label^ CPrice;
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
			   this->CName = (gcnew System::Windows::Forms::Label());
			   this->CInstructor = (gcnew System::Windows::Forms::Label());
			   this->CStart = (gcnew System::Windows::Forms::Label());
			   this->CEnd = (gcnew System::Windows::Forms::Label());
			   this->Reserv_btn = (gcnew System::Windows::Forms::Button());
			   this->CPrice = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // CName
			   // 
			   this->CName->AutoSize = true;
			   this->CName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CName->Location = System::Drawing::Point(3, 9);
			   this->CName->Name = L"CName";
			   this->CName->Size = System::Drawing::Size(90, 29);
			   this->CName->TabIndex = 0;
			   this->CName->Text = L"Name :";
			   // 
			   // CInstructor
			   // 
			   this->CInstructor->AutoSize = true;
			   this->CInstructor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CInstructor->Location = System::Drawing::Point(3, 57);
			   this->CInstructor->Name = L"CInstructor";
			   this->CInstructor->Size = System::Drawing::Size(123, 29);
			   this->CInstructor->TabIndex = 1;
			   this->CInstructor->Text = L"Instructor :";
			   // 
			   // CStart
			   // 
			   this->CStart->AutoSize = true;
			   this->CStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CStart->Location = System::Drawing::Point(3, 153);
			   this->CStart->Name = L"CStart";
			   this->CStart->Size = System::Drawing::Size(127, 29);
			   this->CStart->TabIndex = 2;
			   this->CStart->Text = L"Start date :";
			   // 
			   // CEnd
			   // 
			   this->CEnd->AutoSize = true;
			   this->CEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CEnd->Location = System::Drawing::Point(3, 201);
			   this->CEnd->Name = L"CEnd";
			   this->CEnd->Size = System::Drawing::Size(121, 29);
			   this->CEnd->TabIndex = 3;
			   this->CEnd->Text = L"End date :";
			   // 
			   // Reserv_btn
			   // 
			   this->Reserv_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Reserv_btn->Location = System::Drawing::Point(632, 191);
			   this->Reserv_btn->Name = L"Reserv_btn";
			   this->Reserv_btn->Size = System::Drawing::Size(123, 39);
			   this->Reserv_btn->TabIndex = 4;
			   this->Reserv_btn->Text = L"Reserve";
			   this->Reserv_btn->UseVisualStyleBackColor = true;
			   this->Reserv_btn->Click += gcnew System::EventHandler(this, &GymPN::Reserv_btn_Click);
			   // 
			   // CPrice
			   // 
			   this->CPrice->AutoSize = true;
			   this->CPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CPrice->Location = System::Drawing::Point(3, 105);
			   this->CPrice->Name = L"CPrice";
			   this->CPrice->Size = System::Drawing::Size(81, 29);
			   this->CPrice->TabIndex = 5;
			   this->CPrice->Text = L"Price :";
			   // 
			   // GymPN
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->CPrice);
			   this->Controls->Add(this->Reserv_btn);
			   this->Controls->Add(this->CEnd);
			   this->Controls->Add(this->CStart);
			   this->Controls->Add(this->CInstructor);
			   this->Controls->Add(this->CName);
			   this->Name = L"GymPN";
			   this->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
			   this->Size = System::Drawing::Size(785, 264);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		  }
#pragma endregion

	 private: System::Void Reserv_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  // Check if the class is full
		  String^ classID = CName->Tag->ToString();
		  string classIDStr = msclr::interop::marshal_as<string>(classID);
		  int index = GymClasses::FindIndex(classIDStr);
		  if (index != -1) {
			   if (gymClassList[index].isFull()) {
					DialogResult result = MessageBox::Show("This class is full. You can join the waiting list.\n!!Warning: If you want to skip the waiting period, you must pay for a subscription", "Request wait", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

					if (result == DialogResult::OK) {
						 PaymentPage^ paymentPage = gcnew PaymentPage(gymClassList[index].price);
						 paymentPage->ShowDialog();
						 if (paymentPage->OperationResult) {
							  // Add the user to the waiting list
							  gymClassList[index].waitingList.push_back(userList[loginIndex]);
							  MessageBox::Show("You have been added to the waiting list.");
						 }
						 else {
							  // User cancelled the payment
							  MessageBox::Show("Payment cancelled.");
						 }
					}
					else if (result == DialogResult::Cancel) {
						 // User chose not to join the waiting list
						 MessageBox::Show("You can look for another class.");

					}


			   }
			   else {
					PaymentPage^ paymentPage = gcnew PaymentPage(gymClassList[index].price);
					paymentPage->ShowDialog();
					if (paymentPage->OperationResult) {
						 // Add the user to the waiting list
						 if (userList[loginIndex].isVip)
							  gymClassList[index].waitingList.push_front(userList[loginIndex]);
						 else
							  gymClassList[index].waitingList.push_back(userList[loginIndex]);
						 MessageBox::Show("You have been added to the waiting list.");
					}
					else {
						
						 MessageBox::Show("Payment cancelled.");
					}
					if (paymentPage->OperationResult)
						 gymClassList[index].members.push_back(userList[loginIndex]), MessageBox::Show("You have successfully reserved a spot in this class.");
			   }
		  }
		  else {
			   MessageBox::Show("Class not found.");
		  }
	 }
	 };
}
