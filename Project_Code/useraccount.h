#pragma once
#include "Structure.h""
namespace ProjectCode {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for useraccount
	/// </summary>
	public ref class useraccount : public System::Windows::Forms::Form
	{
	public:
		useraccount(void)
		{
			InitializeComponent();
			button1->Visible = false;
			this->label1->Text = "Welcom:" + "   " + gcnew String(userList[loginID].name.c_str());
			this->label3->Text = "your email is: " + "   " + gcnew String(userList[loginID].email.c_str());
			this->label4->Text = "your password is:" + "   " + gcnew String(userList[loginID].password.c_str());
			this->label5->Text = "your id is:" + "   " + gcnew String(userList[loginID].ID.c_str());
			this->label6->Text = "your birthday is:" + "   " + gcnew String(userList[loginID].Birthday.c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~useraccount()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ subscriptionDetailsLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->subscriptionDetailsLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(31, 32);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"HI ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(779, 32);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(292, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"YOUR SUBSCRIPTION:";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(556, 410);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(269, 110);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Back to main page";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &useraccount::button2_Click);
			// 
			// subscriptionDetailsLabel
			// 
			this->subscriptionDetailsLabel->AutoSize = true;
			this->subscriptionDetailsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->subscriptionDetailsLabel->Location = System::Drawing::Point(779, 123);
			this->subscriptionDetailsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->subscriptionDetailsLabel->Name = L"subscriptionDetailsLabel";
			this->subscriptionDetailsLabel->Size = System::Drawing::Size(0, 20);
			this->subscriptionDetailsLabel->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(32, 87);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(31, 128);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(32, 174);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 25);
			this->label5->TabIndex = 8;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(31, 230);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 25);
			this->label6->TabIndex = 9;
			this->label6->Text = L"label6";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(984, 410);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(269, 110);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Update subscription";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &useraccount::button1_Click);
			// 
			// useraccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1469, 609);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->subscriptionDetailsLabel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"useraccount";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"useraccount";
			this->Load += gcnew System::EventHandler(this, &useraccount::useraccount_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void notifyExpiringSubscriptions() {
			try {
				time_t now = time(nullptr);
				const int warningDays = 5;

				if (userList.find(loginID) == userList.end()) {
					subscriptionDetailsLabel->Text = "Error: User not found.";
					return;
				}

				User& user = userList[loginID];

				if (!user.subscription.isActive() && user.subscription.IsExpired()) {
					subscriptionDetailsLabel->Text =
						"Your subscription has expired.Please renew to continue using our services.";
					button1->Visible = true;
					return;
				}

				std::string endDateStr = user.subscription.calculateEndDate();
				if (endDateStr.empty()) {
					subscriptionDetailsLabel->Text = "Failed to retrieve subscription end date.";
					return;
				}

				time_t endDate = getTime_t(endDateStr);
				int daysLeft = static_cast<int>(ceil(difftime(endDate, now) / (60.0 * 60 * 24)));

				String^ details =
					"Type: " + gcnew String(user.subscription.getType().c_str()) + "\n" +
					"Start: " + gcnew String(user.subscription.getStartDate().c_str()) + "\n" +
					"End: " + gcnew String(endDateStr.c_str()) + "\n" +
					"Price: " + user.subscription.getPrice().ToString() + "\n";

				if (user.subscription.isActive() && daysLeft > 0 && daysLeft <= warningDays) {
					details += "\n Your subscription will expire in " + daysLeft.ToString() + " day(s).";
				}

				subscriptionDetailsLabel->Text = details;
			}
			catch (const std::exception& e) {
				subscriptionDetailsLabel->Text = "Error processing subscription: " + gcnew String(e.what());
			}
		}


	private: System::Void useraccount_Load(System::Object^ sender, System::EventArgs^ e) {
		notifyExpiringSubscriptions();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

#pragma endregion
	};
}