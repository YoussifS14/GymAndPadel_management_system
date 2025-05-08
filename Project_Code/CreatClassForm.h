#pragma once
#include "Structure.h"
#include <unordered_map>
#include <string>
#include <regex>
#include <msclr/marshal_cppstd.h>

namespace ProjectCode {
	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;
	 using namespace msclr::interop;

	 public ref class CreatClassForm : public System::Windows::Forms::Form
	 {
	 public:
		  CreatClassForm(void)
		  {
			   InitializeComponent();
			   InitializeSubscriptions();
			   InitializeComboBoxes();
		  }

		  // Public property to access panel1
		  property System::Windows::Forms::Panel^ ClassPanel {
			   System::Windows::Forms::Panel^ get() { return panel1; }
		  }

	 protected:
		  ~CreatClassForm()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }

	 private:
		  System::Windows::Forms::Panel^ panel1;
		  System::Windows::Forms::CheckedListBox^ DaysofClassCheckbox;
		  System::Windows::Forms::Label^ label1;
		  System::Windows::Forms::Label^ labelClassName;
		  System::Windows::Forms::TextBox^ textBoxClassName;
		  System::Windows::Forms::Label^ DateLabel;
		  System::Windows::Forms::ComboBox^ YearcomboBox;
		  System::Windows::Forms::ComboBox^ MonthcomboBox;
		  System::Windows::Forms::ComboBox^ DaycomboBox;
		  System::Windows::Forms::Label^ labelStartTime;
		  System::Windows::Forms::TextBox^ textBoxStartTime;
		  System::Windows::Forms::Label^ labelEndTime;
		  System::Windows::Forms::TextBox^ textBoxEndTime;
		  System::Windows::Forms::Label^ labelMaxMembers;
		  System::Windows::Forms::TextBox^ textBoxMaxMembers;
		  System::Windows::Forms::Label^ labelInstructorName;
		  System::Windows::Forms::TextBox^ textBoxInstructorName;
		  System::Windows::Forms::Label^ labelInstructorID;
		  System::Windows::Forms::TextBox^ textBoxInstructorID;
		  System::Windows::Forms::Label^ labelSubscription;
		  System::Windows::Forms::CheckedListBox^ checkedListBoxSubscriptions;
		  System::Windows::Forms::Button^ buttonCreateClass;
		  System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		  void InitializeComponent(void)
		  {
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->DaysofClassCheckbox = (gcnew System::Windows::Forms::CheckedListBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->labelClassName = (gcnew System::Windows::Forms::Label());
			   this->textBoxClassName = (gcnew System::Windows::Forms::TextBox());
			   this->DateLabel = (gcnew System::Windows::Forms::Label());
			   this->YearcomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->MonthcomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->DaycomboBox = (gcnew System::Windows::Forms::ComboBox());
			   this->labelStartTime = (gcnew System::Windows::Forms::Label());
			   this->textBoxStartTime = (gcnew System::Windows::Forms::TextBox());
			   this->labelEndTime = (gcnew System::Windows::Forms::Label());
			   this->textBoxEndTime = (gcnew System::Windows::Forms::TextBox());
			   this->labelMaxMembers = (gcnew System::Windows::Forms::Label());
			   this->textBoxMaxMembers = (gcnew System::Windows::Forms::TextBox());
			   this->labelInstructorName = (gcnew System::Windows::Forms::Label());
			   this->textBoxInstructorName = (gcnew System::Windows::Forms::TextBox());
			   this->labelInstructorID = (gcnew System::Windows::Forms::Label());
			   this->textBoxInstructorID = (gcnew System::Windows::Forms::TextBox());
			   this->labelSubscription = (gcnew System::Windows::Forms::Label());
			   this->checkedListBoxSubscriptions = (gcnew System::Windows::Forms::CheckedListBox());
			   this->buttonCreateClass = (gcnew System::Windows::Forms::Button());
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->DaysofClassCheckbox);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->labelClassName);
			   this->panel1->Controls->Add(this->textBoxClassName);
			   this->panel1->Controls->Add(this->DateLabel);
			   this->panel1->Controls->Add(this->YearcomboBox);
			   this->panel1->Controls->Add(this->MonthcomboBox);
			   this->panel1->Controls->Add(this->DaycomboBox);
			   this->panel1->Controls->Add(this->labelStartTime);
			   this->panel1->Controls->Add(this->textBoxStartTime);
			   this->panel1->Controls->Add(this->labelEndTime);
			   this->panel1->Controls->Add(this->textBoxEndTime);
			   this->panel1->Controls->Add(this->labelMaxMembers);
			   this->panel1->Controls->Add(this->textBoxMaxMembers);
			   this->panel1->Controls->Add(this->labelInstructorName);
			   this->panel1->Controls->Add(this->textBoxInstructorName);
			   this->panel1->Controls->Add(this->labelInstructorID);
			   this->panel1->Controls->Add(this->textBoxInstructorID);
			   this->panel1->Controls->Add(this->labelSubscription);
			   this->panel1->Controls->Add(this->checkedListBoxSubscriptions);
			   this->panel1->Controls->Add(this->buttonCreateClass);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Margin = System::Windows::Forms::Padding(4);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1113, 703);
			   this->panel1->TabIndex = 0;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CreatClassForm::panel1_Paint);
			   // 
			   // DaysofClassCheckbox
			   // 
			   this->DaysofClassCheckbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->DaysofClassCheckbox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
					L"Sunday", L"Monday", L"Tuesday", L"Wednesday",
						 L"Thursday", L"Friday", L"Saturday"
			   });
			   this->DaysofClassCheckbox->Location = System::Drawing::Point(700, 325);
			   this->DaysofClassCheckbox->Margin = System::Windows::Forms::Padding(4);
			   this->DaysofClassCheckbox->Name = L"DaysofClassCheckbox";
			   this->DaysofClassCheckbox->Size = System::Drawing::Size(207, 91);
			   this->DaysofClassCheckbox->TabIndex = 41;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(528, 273);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(165, 29);
			   this->label1->TabIndex = 40;
			   this->label1->Text = L"Days of class :";
			   // 
			   // labelClassName
			   // 
			   this->labelClassName->AutoSize = true;
			   this->labelClassName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->labelClassName->Location = System::Drawing::Point(16, 109);
			   this->labelClassName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelClassName->Name = L"labelClassName";
			   this->labelClassName->Size = System::Drawing::Size(150, 29);
			   this->labelClassName->TabIndex = 21;
			   this->labelClassName->Text = L"Class Name:";
			   // 
			   // textBoxClassName
			   // 
			   this->textBoxClassName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxClassName->Location = System::Drawing::Point(272, 109);
			   this->textBoxClassName->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxClassName->Name = L"textBoxClassName";
			   this->textBoxClassName->Size = System::Drawing::Size(211, 34);
			   this->textBoxClassName->TabIndex = 22;
			   // 
			   // DateLabel
			   // 
			   this->DateLabel->AutoSize = true;
			   this->DateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->DateLabel->Location = System::Drawing::Point(509, 112);
			   this->DateLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->DateLabel->Name = L"DateLabel";
			   this->DateLabel->Size = System::Drawing::Size(69, 29);
			   this->DateLabel->TabIndex = 23;
			   this->DateLabel->Text = L"Date:";
			   // 
			   // YearcomboBox
			   // 
			   this->YearcomboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->YearcomboBox->FormattingEnabled = true;
			   this->YearcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
					L"2025", L"2026", L"2027", L"2028", L"2029",
						 L"2030"
			   });
			   this->YearcomboBox->Location = System::Drawing::Point(818, 112);
			   this->YearcomboBox->Margin = System::Windows::Forms::Padding(4);
			   this->YearcomboBox->Name = L"YearcomboBox";
			   this->YearcomboBox->Size = System::Drawing::Size(89, 37);
			   this->YearcomboBox->TabIndex = 24;
			   this->YearcomboBox->Text = L"Year";
			   // 
			   // MonthcomboBox
			   // 
			   this->MonthcomboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->MonthcomboBox->FormattingEnabled = true;
			   this->MonthcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
					L"01", L"02", L"03", L"04", L"05", L"06", L"07",
						 L"08", L"09", L"10", L"11", L"12"
			   });
			   this->MonthcomboBox->Location = System::Drawing::Point(711, 109);
			   this->MonthcomboBox->Margin = System::Windows::Forms::Padding(4);
			   this->MonthcomboBox->Name = L"MonthcomboBox";
			   this->MonthcomboBox->Size = System::Drawing::Size(89, 37);
			   this->MonthcomboBox->TabIndex = 25;
			   this->MonthcomboBox->Text = L"Month";
			   // 
			   // DaycomboBox
			   // 
			   this->DaycomboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->DaycomboBox->FormattingEnabled = true;
			   this->DaycomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
					L"01", L"02", L"03", L"04", L"05", L"06", L"07",
						 L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
						 L"26", L"27", L"28", L"29", L"30", L"31"
			   });
			   this->DaycomboBox->Location = System::Drawing::Point(604, 109);
			   this->DaycomboBox->Margin = System::Windows::Forms::Padding(4);
			   this->DaycomboBox->Name = L"DaycomboBox";
			   this->DaycomboBox->Size = System::Drawing::Size(89, 37);
			   this->DaycomboBox->TabIndex = 26;
			   this->DaycomboBox->Text = L"Day";
			   // 
			   // labelStartTime
			   // 
			   this->labelStartTime->AutoSize = true;
			   this->labelStartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->labelStartTime->Location = System::Drawing::Point(16, 273);
			   this->labelStartTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelStartTime->Name = L"labelStartTime";
			   this->labelStartTime->Size = System::Drawing::Size(226, 29);
			   this->labelStartTime->TabIndex = 27;
			   this->labelStartTime->Text = L"Start Time(HH:MM):";
			   // 
			   // textBoxStartTime
			   // 
			   this->textBoxStartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxStartTime->Location = System::Drawing::Point(272, 268);
			   this->textBoxStartTime->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxStartTime->Name = L"textBoxStartTime";
			   this->textBoxStartTime->Size = System::Drawing::Size(211, 34);
			   this->textBoxStartTime->TabIndex = 28;
			   this->textBoxStartTime->TextChanged += gcnew System::EventHandler(this, &CreatClassForm::textBoxStartTime_TextChanged);
			   // 
			   // labelEndTime
			   // 
			   this->labelEndTime->AutoSize = true;
			   this->labelEndTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->labelEndTime->Location = System::Drawing::Point(502, 215);
			   this->labelEndTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelEndTime->Name = L"labelEndTime";
			   this->labelEndTime->Size = System::Drawing::Size(226, 29);
			   this->labelEndTime->TabIndex = 29;
			   this->labelEndTime->Text = L"End Time (HH:MM):";
			   // 
			   // textBoxEndTime
			   // 
			   this->textBoxEndTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->textBoxEndTime->Location = System::Drawing::Point(738, 212);
			   this->textBoxEndTime->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxEndTime->Name = L"textBoxEndTime";
			   this->textBoxEndTime->Size = System::Drawing::Size(191, 34);
			   this->textBoxEndTime->TabIndex = 30;
			   // 
			   // labelMaxMembers
			   // 
			   this->labelMaxMembers->AutoSize = true;
			   this->labelMaxMembers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->labelMaxMembers->Location = System::Drawing::Point(502, 165);
			   this->labelMaxMembers->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelMaxMembers->Name = L"labelMaxMembers";
			   this->labelMaxMembers->Size = System::Drawing::Size(171, 29);
			   this->labelMaxMembers->TabIndex = 31;
			   this->labelMaxMembers->Text = L"Max Members:";
			   // 
			   // textBoxMaxMembers
			   // 
			   this->textBoxMaxMembers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxMaxMembers->Location = System::Drawing::Point(738, 157);
			   this->textBoxMaxMembers->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxMaxMembers->Name = L"textBoxMaxMembers";
			   this->textBoxMaxMembers->Size = System::Drawing::Size(189, 34);
			   this->textBoxMaxMembers->TabIndex = 32;
			   // 
			   // labelInstructorName
			   // 
			   this->labelInstructorName->AutoSize = true;
			   this->labelInstructorName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->labelInstructorName->Location = System::Drawing::Point(16, 215);
			   this->labelInstructorName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelInstructorName->Name = L"labelInstructorName";
			   this->labelInstructorName->Size = System::Drawing::Size(188, 29);
			   this->labelInstructorName->TabIndex = 33;
			   this->labelInstructorName->Text = L"Instructor Name:";
			   this->labelInstructorName->Click += gcnew System::EventHandler(this, &CreatClassForm::labelInstructorName_Click);
			   // 
			   // textBoxInstructorName
			   // 
			   this->textBoxInstructorName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxInstructorName->Location = System::Drawing::Point(272, 210);
			   this->textBoxInstructorName->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxInstructorName->Name = L"textBoxInstructorName";
			   this->textBoxInstructorName->Size = System::Drawing::Size(211, 34);
			   this->textBoxInstructorName->TabIndex = 34;
			   // 
			   // labelInstructorID
			   // 
			   this->labelInstructorID->AutoSize = true;
			   this->labelInstructorID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->labelInstructorID->Location = System::Drawing::Point(16, 165);
			   this->labelInstructorID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelInstructorID->Name = L"labelInstructorID";
			   this->labelInstructorID->Size = System::Drawing::Size(146, 29);
			   this->labelInstructorID->TabIndex = 35;
			   this->labelInstructorID->Text = L"Instructor ID:";
			   // 
			   // textBoxInstructorID
			   // 
			   this->textBoxInstructorID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxInstructorID->Location = System::Drawing::Point(272, 160);
			   this->textBoxInstructorID->Margin = System::Windows::Forms::Padding(4);
			   this->textBoxInstructorID->Name = L"textBoxInstructorID";
			   this->textBoxInstructorID->Size = System::Drawing::Size(211, 34);
			   this->textBoxInstructorID->TabIndex = 36;
			   this->textBoxInstructorID->TextChanged += gcnew System::EventHandler(this, &CreatClassForm::textBoxInstructorID_TextChanged);
			   // 
			   // labelSubscription
			   // 
			   this->labelSubscription->AutoSize = true;
			   this->labelSubscription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->labelSubscription->Location = System::Drawing::Point(16, 325);
			   this->labelSubscription->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelSubscription->Name = L"labelSubscription";
			   this->labelSubscription->Size = System::Drawing::Size(271, 29);
			   this->labelSubscription->TabIndex = 37;
			   this->labelSubscription->Text = L"Required Subscriptions:";
			   // 
			   // checkedListBoxSubscriptions
			   // 
			   this->checkedListBoxSubscriptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->checkedListBoxSubscriptions->Location = System::Drawing::Point(263, 358);
			   this->checkedListBoxSubscriptions->Margin = System::Windows::Forms::Padding(4);
			   this->checkedListBoxSubscriptions->Name = L"checkedListBoxSubscriptions";
			   this->checkedListBoxSubscriptions->Size = System::Drawing::Size(220, 91);
			   this->checkedListBoxSubscriptions->TabIndex = 38;
			   // 
			   // buttonCreateClass
			   // 
			   this->buttonCreateClass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->buttonCreateClass->Location = System::Drawing::Point(414, 533);
			   this->buttonCreateClass->Margin = System::Windows::Forms::Padding(4);
			   this->buttonCreateClass->Name = L"buttonCreateClass";
			   this->buttonCreateClass->Size = System::Drawing::Size(203, 64);
			   this->buttonCreateClass->TabIndex = 39;
			   this->buttonCreateClass->Text = L"Create ";
			   this->buttonCreateClass->Click += gcnew System::EventHandler(this, &CreatClassForm::buttonCreateClass_Click);
			   // 
			   // CreatClassForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ClientSize = System::Drawing::Size(1113, 703);
			   this->Controls->Add(this->panel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->MaximizeBox = false;
			   this->Name = L"CreatClassForm";
			   this->Text = L"Create New Gym Class";
			   this->Load += gcnew System::EventHandler(this, &CreatClassForm::CreatClassForm_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		  }
#pragma endregion

	 private:
		  void InitializeSubscriptions()
		  {
			   std::vector<std::string> subs = { "1 month", "3 month", "6 month", "1 year" };
			   for (const auto& sub : subs)
			   {
					checkedListBoxSubscriptions->Items->Add(marshal_as<String^>(sub));
			   }
		  }

		  void InitializeComboBoxes()
		  {
			   for (int i = 1; i <= 31; i++)
			   {
					DaycomboBox->Items->Add(i.ToString("D2"));
			   }
			   DaycomboBox->Text = L"Day";

			   for (int i = 1; i <= 12; i++)
			   {
					MonthcomboBox->Items->Add(i.ToString("D2"));
			   }
			   MonthcomboBox->Text = L"Month";

			   for (int i = 2025; i <= 2030; i++)
			   {
					YearcomboBox->Items->Add(i.ToString());
			   }
			   YearcomboBox->Text = L"Year";
		  }

		  bool isNameValid(string name)
		  {
			   for (char c : name)
			   {
					if (!isalpha(c) && c != ' ')
					{
						 return false;
					}
			   }
			   return true;
		  }

		  bool isValidTimeFormat(const string& time) {
			   regex timeRegex(R"(^(?:[01][0-9]|2[0-3]):[0-5][0-9]$)");
			   return regex_match(time, timeRegex);
		  }

		  bool isTimeOverlap(const string& start1, const string& end1,
			   const string& start2, const string& end2) {
			   return !(end1 <= start2 || start1 >= end2);
		  }

		  void parseDate(const string& date, int& month, int& day, int& year) {
			   sscanf_s(date.c_str(), "%d/%d/%d", &month, &day, &year);
		  }

		  std::string formatDate(int month, int day, int year) {
			   char buffer[11];
			   sprintf_s(buffer, "%02d/%02d/%04d", month, day, year);
			   return string(buffer);
		  }

		  bool isValidDate(int month, int day, int year) {
			   if (month < 1 || month > 12 || day < 1 || year < 2025 || year > 2030) return false;
			   int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			   if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth[1] = 29;
			   return day <= daysInMonth[month - 1];
		  }

		  long daysSinceEpoch(int month, int day, int year) {
			   long days = (year - 1970) * 365 + (year - 1969) / 4 - (year - 1901) / 100 + (year - 1601) / 400;
			   int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			   if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth[1] = 29;
			   for (int i = 1; i < month; ++i) days += daysInMonth[i - 1];
			   days += day - 1;
			   return days;
		  }

		  int getDayOfWeek(int month, int day, int year) {
			   long days = daysSinceEpoch(month, day, year);
			   return (days + 4) % 7;
		  }

		  bool isDateLessOrEqual(const string& date1, const string& date2) {
			   int m1, d1, y1, m2, d2, y2;
			   parseDate(date1, m1, d1, y1);
			   parseDate(date2, m2, d2, y2);
			   if (y1 != y2) return y1 <= y2;
			   if (m1 != m2) return m1 <= m2;
			   return d1 <= d2;
		  }

		  string getFirstDayOfWeekAfter(const string& startDate, int targetWeekday) {
			   time_t t = getTime_t(startDate);
			   tm timeinfo;
			   localtime_s(&timeinfo, &t);
			   int currentWDay = timeinfo.tm_wday;

			   int daysToAdd = (targetWeekday - currentWDay + 7) % 7;
			   if (daysToAdd == 0) {
					daysToAdd = 7;
			   }

			   timeinfo.tm_mday += daysToAdd;
			   time_t nextDate = mktime(&timeinfo);
			   return getFormat(nextDate);
		  }

		  string isCoachAvailable(Staff coach, const string& startDate, const string& startTime, const string& endTime, const vector<int>& recurringDays) {
			   extern unordered_map<string, Staff> staffList;
			   bool coachExists = false;
			   for (const auto& pair : staffList) {
					std::string staffRole = pair.second.role;
					std::transform(staffRole.begin(), staffRole.end(), staffRole.begin(), ::tolower);
					if (pair.second.ID == coach.ID && pair.second.name == coach.name && staffRole == "coach") {
						 coachExists = true;
						 break;
					}
			   }
			   if (!coachExists) {
					return "Coach " + coach.name + " does not exist or is not a valid coach.";
			   }
			   GymClasses temp;
			   string endDate = temp.calculateEndDate(startDate);

			   int startMonth, startDay, startYear;
			   int endMonth, endDay, endYear;
			   parseDate(startDate, startMonth, startDay, startYear);
			   parseDate(endDate, endMonth, endDay, endYear);

			   vector<string> sessionDates;
			   set<int> daysSet(recurringDays.begin(), recurringDays.end());
			   string firstSessionDate = startDate;
			   if (!recurringDays.empty()) {
					int earliestDayOfWeek = *min_element(recurringDays.begin(), recurringDays.end());
					firstSessionDate = getFirstDayOfWeekAfter(startDate, earliestDayOfWeek);
			   }
			   int currentMonth, currentDay, currentYear;
			   parseDate(firstSessionDate, currentMonth, currentDay, currentYear);

			   while (isDateLessOrEqual(formatDate(currentMonth, currentDay, currentYear), endDate)) {
					if (isValidDate(currentMonth, currentDay, currentYear)) {
						 int weekday = getDayOfWeek(currentMonth, currentDay, currentYear);
						 if (daysSet.find(weekday) != daysSet.end()) {
							  sessionDates.push_back(formatDate(currentMonth, currentDay, currentYear));
						 }
					}
					currentDay++;
					int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
					if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) daysInMonth[1] = 29;
					if (currentDay > daysInMonth[currentMonth - 1]) {
						 currentDay = 1;
						 currentMonth++;
						 if (currentMonth > 12) {
							  currentMonth = 1;
							  currentYear++;
						 }
					}
			   }
			   extern unordered_map<string, GymClasses> gymClassList;
			   for (const auto& pair : gymClassList) {
					GymClasses cls = pair.second;
					if (cls.instructorID == coach.ID) {
						 for (const auto& session : cls.sessions) {
							  for (const auto& date : sessionDates) {
								   if (session.date == date && isTimeOverlap(session.startTime, session.endTime, startTime, endTime)) {
										return "Coach " + coach.name + " is unavailable on " + date +
											 " from " + startTime + " to " + endTime +
											 " due to a conflict with class '" + cls.className +
											 "' from " + session.startTime + " to " + session.endTime + ".";
								   }
							  }
						 }
					}
			   }
			   return "Coach " + coach.name + " is available.";
		  }

		  bool ValidateInput()
		  {
			   std::string className = marshal_as<std::string>(textBoxClassName->Text);
			   String^ dayStr = DaycomboBox->SelectedItem ? DaycomboBox->SelectedItem->ToString() : "";
			   String^ monthStr = MonthcomboBox->SelectedItem ? MonthcomboBox->SelectedItem->ToString() : "";
			   String^ yearStr = YearcomboBox->SelectedItem ? YearcomboBox->SelectedItem->ToString() : "";
			   string startTime = marshal_as<std::string>(textBoxStartTime->Text);
			   string endTime = marshal_as<std::string>(textBoxEndTime->Text);
			   string maxMembers = marshal_as<std::string>(textBoxMaxMembers->Text);
			   string instructorName = marshal_as<std::string>(textBoxInstructorName->Text);
			   string instructorID = marshal_as<std::string>(textBoxInstructorID->Text);

			   if (className.empty() || !isNameValid(className))
			   {
					MessageBox::Show(L"Please enter a valid class name (letters only).", L"Input Error");
					return false;
			   }

			   if (String::IsNullOrWhiteSpace(dayStr) || String::IsNullOrWhiteSpace(monthStr) ||
					String::IsNullOrWhiteSpace(yearStr))
			   {
					MessageBox::Show(L"Please select a valid date (day, month, and year).", L"Input Error");
					return false;
			   }

			   int day = System::Convert::ToInt32(dayStr);
			   int month = System::Convert::ToInt32(monthStr);
			   int year = System::Convert::ToInt32(yearStr);

			   if (!isValidTimeFormat(startTime))
			   {
					MessageBox::Show(L"Please enter a valid start time (HH:MM).", L"Input Error");
					return false;
			   }
			   if (!isValidTimeFormat(endTime))
			   {
					MessageBox::Show(L"Please enter a valid end time (HH:MM).", L"Input Error");
					return false;
			   }

			   if (endTime <= startTime) {
					MessageBox::Show(L"End time must be after start time (including overnight sessions).", L"Input Error");
					return false;
			   }

			   try
			   {
					int max = std::stoi(maxMembers);
					if (max <= 0)
					{
						 MessageBox::Show(L"Please enter a positive number for max members.", L"Input Error");
						 return false;
					}
			   }
			   catch (...)
			   {
					MessageBox::Show(L"Please enter a valid number for max members.", L"Input Error");
					return false;
			   }

			   if (instructorName.empty() || !isNameValid(instructorName))
			   {
					MessageBox::Show(L"Please enter a valid instructor name.", L"Input Error");
					return false;
			   }
			   if (instructorID.empty())
			   {
					MessageBox::Show(L"Please enter a valid instructor ID.", L"Input Error");
					return false;
			   }

			   if (checkedListBoxSubscriptions->CheckedItems->Count == 0)
			   {
					MessageBox::Show(L"Please select at least one subscription type.", L"Input Error");
					return false;
			   }
			   if (DaysofClassCheckbox->CheckedItems->Count == 0)
			   {
					MessageBox::Show(L"Please select at least one day for the class.", L"Input Error");
					return false;
			   }
			   bool coachFound = false;
			   for (const auto& pair : staffList)
			   {
					std::string staffRole = pair.second.role;
					std::string staffName = pair.second.name;
					std::string staffID = pair.second.ID;
					staffName.erase(staffName.find_last_not_of(" \n\r\t") + 1);
					staffID.erase(staffID.find_last_not_of(" \n\r\t") + 1);
					std::transform(staffRole.begin(), staffRole.end(), staffRole.begin(), ::tolower);
					if (staffName == instructorName && staffID == instructorID && staffRole == "coach")
					{
						 coachFound = true;
						 break;
					}
			   }
			   if (!coachFound)
			   {
					MessageBox::Show(L"Coach not found or not a valid coach.", L"Input Error");
					return false;
			   }

			   Staff coach;
			   coach.name = instructorName;
			   coach.ID = instructorID;
			   coach.role = "Coach";
			   string date = marshal_as<string>(String::Format("{0:00}/{1:00}/{2}", month, day, year));
			   vector<int> recurringDays;
			   for each (String ^ day in DaysofClassCheckbox->CheckedItems)
			   {
					if (day == L"Sunday") recurringDays.push_back(0);
					else if (day == L"Monday") recurringDays.push_back(1);
					else if (day == L"Tuesday") recurringDays.push_back(2);
					else if (day == L"Wednesday") recurringDays.push_back(3);
					else if (day == L"Thursday") recurringDays.push_back(4);
					else if (day == L"Friday") recurringDays.push_back(5);
					else if (day == L"Saturday") recurringDays.push_back(6);
			   }
			   string availabilityMessage = isCoachAvailable(coach, date, startTime, endTime, recurringDays);
			   if (availabilityMessage.find("unavailable") != string::npos)
			   {
					MessageBox::Show(marshal_as<String^>(availabilityMessage), L"Scheduling Conflict");
					return false;
			   }

			   return true;
		  }

	 public:
		  void createClass()
		  {
			   if (!ValidateInput())
			   {
					return;
			   }

			   std::string className = marshal_as<std::string>(textBoxClassName->Text);
			   int day = System::Convert::ToInt32(DaycomboBox->SelectedItem->ToString());
			   int month = System::Convert::ToInt32(MonthcomboBox->SelectedItem->ToString());
			   int year = System::Convert::ToInt32(YearcomboBox->SelectedItem->ToString());
			   string startDate = marshal_as<string>(String::Format("{0:00}/{1:00}/{2}", month, day, year));
			   string startTime = marshal_as<string>(textBoxStartTime->Text);
			   string endTime = marshal_as<string>(textBoxEndTime->Text);
			   int maxMembers = System::Convert::ToInt32(textBoxMaxMembers->Text);
			   string instructorName = marshal_as<string>(textBoxInstructorName->Text);
			   string instructorID = marshal_as<string>(textBoxInstructorID->Text);

			   Staff coach;
			   coach.name = instructorName;
			   coach.ID = instructorID;
			   coach.role = "Coach";

			   vector<int> recurringDays;
			   for each (String ^ day in DaysofClassCheckbox->CheckedItems)
			   {
					if (day == L"Sunday") recurringDays.push_back(0);
					else if (day == L"Monday") recurringDays.push_back(1);
					else if (day == L"Tuesday") recurringDays.push_back(2);
					else if (day == L"Wednesday") recurringDays.push_back(3);
					else if (day == L"Thursday") recurringDays.push_back(4);
					else if (day == L"Friday") recurringDays.push_back(5);
					else if (day == L"Saturday") recurringDays.push_back(6);
			   }
			   string firstSessionDate = startDate;
			   if (!recurringDays.empty()) {
					firstSessionDate = getFirstDayOfWeekAfter(startDate, recurringDays[0]);
			   }

			   GymClasses newClass;
			   newClass.classID = newClass.generateUniqueID();
			   newClass.className = className;
			   newClass.instructor = coach.name;
			   newClass.instructorID = coach.ID;
			   newClass.startDate = startDate;
			   newClass.endDate = newClass.calculateEndDate(startDate);
			   newClass.maxMembers = maxMembers;

			   newClass.generateRecurringSessions(startDate, newClass.endDate, startTime, endTime, recurringDays);
			   for each (String ^ sub in checkedListBoxSubscriptions->CheckedItems)
			   {
					newClass.allowedSubTypes.push_back(marshal_as<std::string>(sub));
			   }
			   extern unordered_map<string, GymClasses> gymClassList;
			   gymClassList[newClass.classID] = newClass;

			   MessageBox::Show(L"Class created successfully with ID: " +
					marshal_as<String^>(newClass.classID), L"Success");
			   this->Close();
		  }

	 private:
		  System::Void buttonCreateClass_Click(System::Object^ sender, System::EventArgs^ e)
		  {
			   createClass();
		  }

		  System::Void DaysofClassCheckbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		  }

	 private:
		  System::Void CreatClassForm_Load(System::Object^ sender, System::EventArgs^ e) {
			   this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
		  }
	 private: System::Void textBoxInstructorID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	 }
	 private: System::Void textBoxStartTime_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	 }
	 private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	 }
	 private: System::Void labelInstructorName_Click(System::Object^ sender, System::EventArgs^ e) {
	 }
	 };
}