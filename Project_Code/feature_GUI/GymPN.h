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
		  bool res;
		  GymPN(bool temp)
		  {
			   InitializeComponent();
			   res = temp;
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
	 public: System::Windows::Forms::Button^ cancelling_btn;
	 public: System::Windows::Forms::Label^ label1;
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
			   this->cancelling_btn = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // CName
			   // 
			   this->CName->AutoSize = true;
			   this->CName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CName->ForeColor = System::Drawing::Color::White;
			   this->CName->Location = System::Drawing::Point(2, 7);
			   this->CName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->CName->Name = L"CName";
			   this->CName->Size = System::Drawing::Size(71, 24);
			   this->CName->TabIndex = 0;
			   this->CName->Text = L"Name :";
			   // 
			   // CInstructor
			   // 
			   this->CInstructor->AutoSize = true;
			   this->CInstructor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CInstructor->ForeColor = System::Drawing::Color::White;
			   this->CInstructor->Location = System::Drawing::Point(2, 46);
			   this->CInstructor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->CInstructor->Name = L"CInstructor";
			   this->CInstructor->Size = System::Drawing::Size(96, 24);
			   this->CInstructor->TabIndex = 1;
			   this->CInstructor->Text = L"Instructor :";
			   // 
			   // CStart
			   // 
			   this->CStart->AutoSize = true;
			   this->CStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CStart->ForeColor = System::Drawing::Color::White;
			   this->CStart->Location = System::Drawing::Point(2, 124);
			   this->CStart->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->CStart->Name = L"CStart";
			   this->CStart->Size = System::Drawing::Size(97, 24);
			   this->CStart->TabIndex = 2;
			   this->CStart->Text = L"Start date :";
			   // 
			   // CEnd
			   // 
			   this->CEnd->AutoSize = true;
			   this->CEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CEnd->ForeColor = System::Drawing::Color::White;
			   this->CEnd->Location = System::Drawing::Point(2, 163);
			   this->CEnd->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->CEnd->Name = L"CEnd";
			   this->CEnd->Size = System::Drawing::Size(96, 24);
			   this->CEnd->TabIndex = 3;
			   this->CEnd->Text = L"End date :";
			   // 
			   // Reserv_btn
			   // 
			   this->Reserv_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->Reserv_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Reserv_btn->ForeColor = System::Drawing::Color::Black;
			   this->Reserv_btn->Location = System::Drawing::Point(474, 155);
			   this->Reserv_btn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->Reserv_btn->Name = L"Reserv_btn";
			   this->Reserv_btn->Size = System::Drawing::Size(92, 32);
			   this->Reserv_btn->TabIndex = 4;
			   this->Reserv_btn->Text = L"Reserve";
			   this->Reserv_btn->UseVisualStyleBackColor = false;
			   this->Reserv_btn->Visible = false;
			   this->Reserv_btn->Click += gcnew System::EventHandler(this, &GymPN::Reserv_btn_Click);
			   // 
			   // CPrice
			   // 
			   this->CPrice->AutoSize = true;
			   this->CPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->CPrice->ForeColor = System::Drawing::Color::White;
			   this->CPrice->Location = System::Drawing::Point(2, 85);
			   this->CPrice->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->CPrice->Name = L"CPrice";
			   this->CPrice->Size = System::Drawing::Size(63, 24);
			   this->CPrice->TabIndex = 5;
			   this->CPrice->Text = L"Price :";
			   // 
			   // cancelling_btn
			   // 
			   this->cancelling_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->cancelling_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->cancelling_btn->ForeColor = System::Drawing::Color::Black;
			   this->cancelling_btn->Location = System::Drawing::Point(386, 155);
			   this->cancelling_btn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->cancelling_btn->Name = L"cancelling_btn";
			   this->cancelling_btn->Size = System::Drawing::Size(92, 32);
			   this->cancelling_btn->TabIndex = 6;
			   this->cancelling_btn->Text = L"Cancel";
			   this->cancelling_btn->UseVisualStyleBackColor = false;
			   this->cancelling_btn->Visible = false;
			   this->cancelling_btn->Click += gcnew System::EventHandler(this, &GymPN::cancelling_btn_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::DarkGreen;
			   this->label1->Location = System::Drawing::Point(226, 169);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(50, 18);
			   this->label1->TabIndex = 7;
			   this->label1->Text = L"Status";
			   this->label1->Visible = false;
			   // 
			   // GymPN
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->cancelling_btn);
			   this->Controls->Add(this->CPrice);
			   this->Controls->Add(this->Reserv_btn);
			   this->Controls->Add(this->CEnd);
			   this->Controls->Add(this->CStart);
			   this->Controls->Add(this->CInstructor);
			   this->Controls->Add(this->CName);
			   this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->Name = L"GymPN";
			   this->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			   this->Size = System::Drawing::Size(589, 214);
			   this->Load += gcnew System::EventHandler(this, &GymPN::GymPN_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		  }
#pragma endregion

	 private: System::Void Reserv_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  // Check if the class is full
		  String^ classID = CName->Tag->ToString();
		  string classIDStr = msclr::interop::marshal_as<string>(classID);
		  string index = GymClasses::FindIndex(classIDStr);
		  if (index != "") {
			   if (gymClassList[classIDStr].isFull() && gymClassList[classIDStr].waitingList.size() == gymClassList[classIDStr].maxMembers) {
					MessageBox::Show("This class not accept any order  again  you can check another class.");
					return;
			   }
			   if (gymClassList[classIDStr].isFull()) {
					DialogResult result = MessageBox::Show("This class is full. You can join the waiting list.\n!!Warning: If you want to skip the waiting period, you must pay for a subscription", "Request wait", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

					if (result == DialogResult::OK) {
						 PaymentPage^ paymentPage = gcnew PaymentPage(gymClassList[classIDStr].price);
						 paymentPage->ShowDialog();
						 if (paymentPage->OperationResult) {
							  // Add the user to the waiting list
							  if (userList[loginID].isVip) {
								   stack<string>tempstack;

								   while (!gymClassList[classIDStr].waitingList.empty() &&
										userList[gymClassList[classIDStr].waitingList.front()].isVip) {
										tempstack.push(gymClassList[classIDStr].waitingList.front());
										gymClassList[classIDStr].waitingList.pop_front();
								   }
								   // gymClassList[classIDStr].waitingList.push_front(loginID);
								   tempstack.push(loginID);
								   while (!tempstack.empty()) {
										gymClassList[classIDStr].waitingList.push_front(tempstack.top());
										tempstack.pop();
								   }


							  }
							  else
								   gymClassList[classIDStr].waitingList.push_back(loginID);
							  MessageBox::Show("You have been added to the waiting list.");
							  userList[loginID].myWaitingList.push_back(classIDStr);
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
					PaymentPage^ paymentPage = gcnew PaymentPage(gymClassList[classIDStr].price);
					paymentPage->ShowDialog();
					if (paymentPage->OperationResult) {
						 // Add the user to the member list
						 gymClassList[classIDStr].members.push_back(loginID);// = userList[loginID];
						 userList[loginID].myClasses.push_back(classIDStr);
						 MessageBox::Show("You have successfully reserved a spot in this class.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
						 this->Visible = false;

					}
					else {

						 MessageBox::Show("Payment cancelled.", "Failed", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

			   }
		  }
		  else {
			   MessageBox::Show("Class not found.");
		  }
	 }
	 private: System::Void GymPN_Load(System::Object^ sender, System::EventArgs^ e) {
		  if (res)
			   Reserv_btn->Visible = true;
		  else {
			   label1->Visible = true;
			   cancelling_btn->Visible = true;
		  }
	 }
	 private: System::Void cancelling_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		  DialogResult result = MessageBox::Show("Are you sure you want to cancel?\nWarning: You will lose 50% of your subscription.", "Cancel reservation", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		  if (result == DialogResult::Cancel) {
			   // User chose not to cancel
			   return;
		  }
		  else if (result == DialogResult::OK) {

			   String^ classID = CName->Tag->ToString();
			   string classIDStr = msclr::interop::marshal_as<string>(classID);
			   string index = GymClasses::FindIndex(classIDStr);
			   if (index != "") {
					// Remove the user from the member list
					if (gymClassList[classIDStr].memberExist(loginID)) {
						 gymClassList[classIDStr].members.remove(loginID);
						 userList[loginID].myClasses.remove(classIDStr);
						 //add member from waiting list to member list
						 string newEntered;
						 if (!gymClassList[classIDStr].waitingList.empty()) {
							  newEntered = gymClassList[classIDStr].waitingList.front();
							  gymClassList[classIDStr].waitingList.pop_front();
							  gymClassList[classIDStr].members.push_back(newEntered);
							  userList[newEntered].myClasses.push_back(classIDStr);
							  userList[newEntered].myWaitingList.remove(classIDStr);
							  string msg = Notification::standardMessage(userList[newEntered], gymClassList[classIDStr].className, 1);
							  Notification notify;
							  notify.message = msg;
							  userList[newEntered].myNotifications.push_back(notify);
						 }

					}
					else if (!gymClassList[classIDStr].waitingList.empty()) {
						 userList[loginID].myWaitingList.remove(classIDStr);
						 // Remove the user from the waiting list
						 gymClassList[classIDStr].removeFromWaitingList(loginID);
					}
					else {
						 MessageBox::Show("Invalid Reservation", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						 return;
					}


					userList[loginID].myWallet += gymClassList[classIDStr].price * 0.5; // Refund 50% of the price
					MessageBox::Show("You have successfully cancelled your reservation.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->Visible = false;
			   }
			   else {
					MessageBox::Show("Class not found.");
			   }
		  }
	 }
	 };
}
