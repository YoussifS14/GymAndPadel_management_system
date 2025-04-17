#pragma once
#include "Structure.h"
#include "feature_GUI/padelPN.h"
#include "feature_GUI/CancellingReserv.h"

namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 /// <summary>
	 /// Summary for userPage
	 /// </summary>
	 public ref class userPage : public System::Windows::Forms::Form
	 {
	 public:
		  msclr::interop::marshal_context context;
		  userPage(void)
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
		  ~userPage()
		  {
			   if (components)
			   {
					delete components;
			   }
		  }
	 private: System::Windows::Forms::Panel^ MainMenu_pn;
	 private: System::Windows::Forms::Button^ Padel;
	 protected:


	 private: System::Windows::Forms::PictureBox^ AccPic;
	 private: System::Windows::Forms::Panel^ profile_pn;
	 private: System::Windows::Forms::Label^ AccName;
	 private: System::Windows::Forms::Panel^ MainPage;
	 private: System::Windows::Forms::Panel^ PadelPage;
	 private: System::Windows::Forms::Label^ label4;
	 private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	 private: System::Windows::Forms::Label^ label2;
	 private: System::Windows::Forms::ComboBox^ comboBox2;
	 private: System::Windows::Forms::Label^ label1;
	 private: System::Windows::Forms::ComboBox^ comboBox1;
	 private: System::Windows::Forms::Button^ searchOFcourts;
	 private: System::Windows::Forms::FlowLayoutPanel^ listOfCourts;
	 private: System::Windows::Forms::Button^ ListReserPadel;
	 private: System::Windows::Forms::Panel^ CancelPadel_pg;
	 private: System::Windows::Forms::Label^ label3;
	 private: System::Windows::Forms::FlowLayoutPanel^ ListOfMyRes;


	 private: System::ComponentModel::IContainer^ components;













	 private:
		  /// <summary>
		  /// Required designer variable.
		  /// </summary>


#pragma region Windows Form Designer generated code
		  /// <summary>
		  /// Required method for Designer support - do not modify
		  /// the contents of this method with the code editor.
		  /// </summary>
		  void InitializeComponent(void)
		  {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userPage::typeid));
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->Padel = (gcnew System::Windows::Forms::Button());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->ListReserPadel = (gcnew System::Windows::Forms::Button());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainPage = (gcnew System::Windows::Forms::Panel());
			   this->CancelPadel_pg = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->ListOfMyRes = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->PadelPage = (gcnew System::Windows::Forms::Panel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->searchOFcourts = (gcnew System::Windows::Forms::Button());
			   this->listOfCourts = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->MainPage->SuspendLayout();
			   this->CancelPadel_pg->SuspendLayout();
			   this->PadelPage->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->Controls->Add(this->Padel);
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(313, 739);
			   this->MainMenu_pn->TabIndex = 0;
			   // 
			   // Padel
			   // 
			   this->Padel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->Padel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->Padel->Location = System::Drawing::Point(0, 212);
			   this->Padel->Name = L"Padel";
			   this->Padel->Size = System::Drawing::Size(313, 66);
			   this->Padel->TabIndex = 1;
			   this->Padel->Text = L"Padel Court";
			   this->Padel->UseVisualStyleBackColor = true;
			   this->Padel->Click += gcnew System::EventHandler(this, &userPage::Padel_Click);
			   // 
			   // profile_pn
			   // 
			   this->profile_pn->Controls->Add(this->ListReserPadel);
			   this->profile_pn->Controls->Add(this->AccName);
			   this->profile_pn->Controls->Add(this->AccPic);
			   this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
			   this->profile_pn->Location = System::Drawing::Point(0, 0);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(313, 212);
			   this->profile_pn->TabIndex = 1;
			   // 
			   // ListReserPadel
			   // 
			   this->ListReserPadel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ListReserPadel.BackgroundImage")));
			   this->ListReserPadel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ListReserPadel->Location = System::Drawing::Point(277, 12);
			   this->ListReserPadel->Name = L"ListReserPadel";
			   this->ListReserPadel->Size = System::Drawing::Size(30, 36);
			   this->ListReserPadel->TabIndex = 2;
			   this->ListReserPadel->UseVisualStyleBackColor = true;
			   this->ListReserPadel->Click += gcnew System::EventHandler(this, &userPage::ListReserPadel_Click);
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
			   this->MainPage->Controls->Add(this->CancelPadel_pg);
			   this->MainPage->Controls->Add(this->PadelPage);
			   this->MainPage->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainPage->Location = System::Drawing::Point(313, 0);
			   this->MainPage->Name = L"MainPage";
			   this->MainPage->Size = System::Drawing::Size(958, 739);
			   this->MainPage->TabIndex = 1;
			   // 
			   // CancelPadel_pg
			   // 
			   this->CancelPadel_pg->Controls->Add(this->label3);
			   this->CancelPadel_pg->Controls->Add(this->ListOfMyRes);
			   this->CancelPadel_pg->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->CancelPadel_pg->Location = System::Drawing::Point(0, 0);
			   this->CancelPadel_pg->Name = L"CancelPadel_pg";
			   this->CancelPadel_pg->Size = System::Drawing::Size(958, 739);
			   this->CancelPadel_pg->TabIndex = 0;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::Color::Red;
			   this->label3->Location = System::Drawing::Point(47, 12);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(791, 72);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"You must cancel appointments at least 3 hours in advance.\n\n";
			   // 
			   // ListOfMyRes
			   // 
			   this->ListOfMyRes->AutoScroll = true;
			   this->ListOfMyRes->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ListOfMyRes->Location = System::Drawing::Point(0, 70);
			   this->ListOfMyRes->Name = L"ListOfMyRes";
			   this->ListOfMyRes->Size = System::Drawing::Size(958, 669);
			   this->ListOfMyRes->TabIndex = 1;
			   // 
			   // PadelPage
			   // 
			   this->PadelPage->Controls->Add(this->label4);
			   this->PadelPage->Controls->Add(this->dateTimePicker1);
			   this->PadelPage->Controls->Add(this->label2);
			   this->PadelPage->Controls->Add(this->comboBox2);
			   this->PadelPage->Controls->Add(this->label1);
			   this->PadelPage->Controls->Add(this->comboBox1);
			   this->PadelPage->Controls->Add(this->searchOFcourts);
			   this->PadelPage->Controls->Add(this->listOfCourts);
			   this->PadelPage->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->PadelPage->Location = System::Drawing::Point(0, 0);
			   this->PadelPage->Name = L"PadelPage";
			   this->PadelPage->Size = System::Drawing::Size(958, 739);
			   this->PadelPage->TabIndex = 0;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(184, 9);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(48, 22);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Date";
			   // 
			   // dateTimePicker1
			   // 
			   this->dateTimePicker1->CustomFormat = L"MM/dd/yyyy";
			   this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			   this->dateTimePicker1->Location = System::Drawing::Point(173, 37);
			   this->dateTimePicker1->MaxDate = System::DateTime(2026, 2, 28, 0, 0, 0, 0);
			   this->dateTimePicker1->Name = L"dateTimePicker1";
			   this->dateTimePicker1->Size = System::Drawing::Size(121, 27);
			   this->dateTimePicker1->TabIndex = 8;
			   this->dateTimePicker1->Value = System::DateTime(2025, 4, 16, 0, 0, 0, 0);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(351, 9);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(51, 22);
			   this->label2->TabIndex = 5;
			   this->label2->Text = L"From";
			   // 
			   // comboBox2
			   // 
			   this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox2->FormattingEnabled = true;
			   this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
					L"01:00", L"02:00", L"03:00", L"04:00", L"05:00",
						 L"06:00", L"07:00", L"08:00", L"09:00", L"10:00", L"11:00", L"12:00", L"16:00"
			   });
			   this->comboBox2->Location = System::Drawing::Point(355, 40);
			   this->comboBox2->Name = L"comboBox2";
			   this->comboBox2->Size = System::Drawing::Size(73, 24);
			   this->comboBox2->TabIndex = 4;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(15, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(72, 22);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"location";
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
					L"sheikh zayed", L"6th october", L"rehab city",
						 L"tagamoa", L"new cairo", L"naser city", L"maadi", L"madinaty"
			   });
			   this->comboBox1->Location = System::Drawing::Point(10, 40);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(102, 24);
			   this->comboBox1->TabIndex = 2;
			   // 
			   // searchOFcourts
			   // 
			   this->searchOFcourts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
			   this->searchOFcourts->Location = System::Drawing::Point(811, 26);
			   this->searchOFcourts->Name = L"searchOFcourts";
			   this->searchOFcourts->Size = System::Drawing::Size(137, 38);
			   this->searchOFcourts->TabIndex = 1;
			   this->searchOFcourts->Text = L"search";
			   this->searchOFcourts->UseVisualStyleBackColor = true;
			   this->searchOFcourts->Click += gcnew System::EventHandler(this, &userPage::searchOFcourts_Click);
			   // 
			   // listOfCourts
			   // 
			   this->listOfCourts->AutoScroll = true;
			   this->listOfCourts->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->listOfCourts->Location = System::Drawing::Point(0, 70);
			   this->listOfCourts->Name = L"listOfCourts";
			   this->listOfCourts->Size = System::Drawing::Size(958, 669);
			   this->listOfCourts->TabIndex = 0;
			   // 
			   // userPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1273, 739);
			   this->Controls->Add(this->MainPage);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Name = L"userPage";
			   this->Text = L"userPage";
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->MainPage->ResumeLayout(false);
			   this->CancelPadel_pg->ResumeLayout(false);
			   this->CancelPadel_pg->PerformLayout();
			   this->PadelPage->ResumeLayout(false);
			   this->PadelPage->PerformLayout();
			   this->ResumeLayout(false);

		  }
#pragma endregion
	 private: System::Void searchOFcourts_Click(System::Object^ sender, System::EventArgs^ e) {

		  listOfCourts->Controls->Clear();
		  if (comboBox1->SelectedItem == nullptr || comboBox2->SelectedItem == nullptr) {
			   MessageBox::Show("Please select a location and time.");
			   return;
		  }
		  String^ location = comboBox1->SelectedItem->ToString();
		  String^ time = comboBox2->SelectedItem->ToString();
		  String^ date = dateTimePicker1->Value.ToString("MM/dd/yyyy");
		  Slot s;
		  MessageBox::Show("date: " + date + "\nlocation: " + location + "\ntime: " + time);
		  s.date = context.marshal_as<std::string>(date);
		  s.startTime = context.marshal_as<std::string>(time);

		  //  s.endTime = context.marshal_as<std::string>(time);


		  for (const PadelCourt& co : courtList) {

			   bool exists = false;
			   if (co.location == context.marshal_as<std::string>(location)) {
					if (co.slots.size() == 0) {
						 exists = false;
					}
					else {
						 for (const Slot& slo : co.slots) {
							  if (slo.date == s.date && slo.startTime == s.startTime) {
								   exists = true;
								   break;
							  }
						 }
					}
					if (!exists) {
						 padelPN^ court = gcnew padelPN();
						 court->courtName->Text += gcnew String(co.name.c_str());
						 court->courtLoc->Text += gcnew String(co.location.c_str());
						 court->courtPrice->Text += co.price.ToString();
						 court->courtDate->Text += gcnew String(s.date.c_str());
						 court->courtDate->Tag += gcnew String(s.startTime.c_str());


						 listOfCourts->Controls->Add(court);
					}
			   }
		  }
		  if (listOfCourts->Controls->Count == 0) {
			   MessageBox::Show("No available courts found for the selected date and time.\nYou can check another time.");
		  }
	 }

	 private: System::Void ListReserPadel_Click(System::Object^ sender, System::EventArgs^ e) {
		  MainPage->Controls->Clear();
		  MainPage->Controls->Add(CancelPadel_pg);
		  CancelPadel_pg->BringToFront();
		  ListOfMyRes->Controls->Clear();
		  for (int i = 0; i < userList[loginIndex].myReservations.size(); i++) {
			   CancellingReserv^ res = gcnew CancellingReserv();
			   res->courtName->Text += gcnew String(userList[loginIndex].myReservations[i].courtName.c_str());
			   res->courtName->Tag = gcnew String(userList[loginIndex].myReservations[i].ID.c_str());
			   res->ReservDate->Text += gcnew String(userList[loginIndex].myReservations[i].date.c_str());
			   res->StartingTime->Text += gcnew String(userList[loginIndex].myReservations[i].startTime.c_str());
			   if (userList[loginIndex].myReservations[i].date == User::getCurrentDate_MM_DD_YYYY()) {
					int hourDiff = User::getHourDifferenceFromNow(userList[loginIndex].myReservations[i].startTime);
					if (hourDiff < 3) 
						 res->Cancelling_btn->Enabled = false;
						
			   }if (userList[loginIndex].myReservations[i].date < User::getCurrentDate_MM_DD_YYYY()) {
					res->Cancelling_btn->Enabled = false;
					res->Warning->Text = "This reservation is expired";
			   }
			   ListOfMyRes->Controls->Add(res);
		  }
	 }
private: System::Void Padel_Click(System::Object^ sender, System::EventArgs^ e) {
	 MainPage->Controls->Clear();
	 MainPage->Controls->Add(PadelPage);
	 PadelPage->BringToFront();
	 comboBox1->SelectedIndex = -1;
	 comboBox2->SelectedIndex = -1;
	 listOfCourts->Controls->Clear();
	 dateTimePicker1->Value = System::DateTime::Now;
	 comboBox1->SelectedIndex = 0;
	 comboBox2->SelectedIndex = 0;
}
};
}
