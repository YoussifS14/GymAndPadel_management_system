#pragma once
#include "Structure.h"
#include "userExpired.h"
#include "sighup.h"
#include "AttedanceInfo.h"

// Note: Ensure Structure.h, userExpired.h, and sighup.h do not include native C++ headers
// like <exception>, <string>, or <vector> without proper guards. Use #pragma unmanaged/#pragma managed
// or move to a native file if they use native types.

namespace ProjectCode {

	 using namespace System;
	 using namespace System::ComponentModel;
	 using namespace System::Collections;
	 using namespace System::Windows::Forms;
	 using namespace System::Data;
	 using namespace System::Drawing;

	 public ref class staffPage : public System::Windows::Forms::Form {
	 public:
		  staffPage(void) {
			   InitializeComponent();
			   // Initially hide panels
			 //  searchCoach->Visible = false;
			   //searchUser->Visible = false;
		  }

	 protected:
		  ~staffPage() {
			   if (components) {
					delete components;
			   }
		  }

	 private:
		  // UI Components
		  System::Windows::Forms::Panel^ MainMenu_pn;
		  System::Windows::Forms::Panel^ profile_pn;
		  System::Windows::Forms::Label^ AccName;
		  System::Windows::Forms::PictureBox^ AccPic;
		  System::Windows::Forms::Panel^ MainPage;
		  System::Windows::Forms::Button^ SendNotification;
		  System::Windows::Forms::FlowLayoutPanel^ ListOFUserEX;
		  System::Windows::Forms::Button^ AddNewUser;
		  System::Windows::Forms::Button^ displayclasses;
		  System::Windows::Forms::Panel^ searchCoach;
		  System::Windows::Forms::TextBox^ coachIDTextBox;
		  System::Windows::Forms::Button^ searchCoachButton;
		  System::Windows::Forms::DataGridView^ classGridView;
		  System::Windows::Forms::Label^ coachInfoLabel;
		  System::Windows::Forms::Panel^ searchUser;
		  System::Windows::Forms::TextBox^ userIDTextBox;
		  System::Windows::Forms::Button^ searchUserButton;
		  System::Windows::Forms::Label^ userIDLabel;
		  System::Windows::Forms::FlowLayoutPanel^ userInfoPanel;
		  System::Windows::Forms::Button^ button1; // Search User button
		  System::ComponentModel::Container^ components;

	 private: System::Windows::Forms::FlowLayoutPanel^ userAttend;

			// Flag to track if Display Classes is active for reception
			bool isDisplayClassesActive = false;

			void loadpic(PictureBox^ pic) {
				 string val = staffList[loginID].PicPath;
				 if (val != "null")
					  pic->Image = System::Drawing::Image::FromFile(gcnew String(val.c_str()));
				 else
					  pic->Image = System::Drawing::Image::FromFile(gcnew String(defaultImagePath.c_str()));
			}

			void MakePictureCircular(PictureBox^ picBox) {
				 Bitmap^ bmp = gcnew Bitmap(picBox->Image);
				 int diameter = Math::Min(bmp->Width, bmp->Height);
				 Bitmap^ circularBmp = gcnew Bitmap(diameter, diameter);
				 Graphics^ g = Graphics::FromImage(circularBmp);
				 g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
				 GraphicsPath^ path = gcnew GraphicsPath();
				 path->AddEllipse(0, 0, diameter, diameter);
				 g->SetClip(path);
				 int offsetX = (bmp->Width - diameter) / 2;
				 int offsetY = (bmp->Height - diameter) / 2;
				 g->DrawImage(bmp, -offsetX, -offsetY);
				 picBox->Image = circularBmp;
			}

			void SearchUserByID(System::String^ userIDText, System::Windows::Forms::FlowLayoutPanel^ infoPanel) {
				 extern unordered_map<std::string, User> userList;
				 System::String^ trimmedID = userIDText->Trim();
				 infoPanel->Controls->Clear();

				 if (String::IsNullOrEmpty(trimmedID)) {
					  Label^ errorLabel = gcnew Label();
					  errorLabel->AutoSize = true;
					  errorLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  errorLabel->ForeColor = Color::Red;
					  errorLabel->Text = L"Please enter a valid user ID.";
					  infoPanel->Controls->Add(errorLabel);
					  return;
				 }

				 std::string userID = msclr::interop::marshal_as<std::string>(trimmedID);
				 User foundUser;
				 for (const auto& pair : userList) {
					  if (pair.first == userID) {
						   foundUser = pair.second;
						   break;
					  }
				 }

				 if (foundUser.ID != "") {
					  // Header
					  Label^ headerLabel = gcnew Label();
					  headerLabel->AutoSize = true;
					  headerLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
					  headerLabel->ForeColor = Color::DarkBlue;
					  headerLabel->Text = L"User Information:\n";
					  infoPanel->Controls->Add(headerLabel);

					  // Name
					  Label^ nameLabel = gcnew Label();
					  nameLabel->AutoSize = true;
					  nameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  nameLabel->Text = L"Name: " + gcnew String(foundUser.name.c_str());
					  infoPanel->Controls->Add(nameLabel);

					  // Birthday
					  Label^ birthdayLabel = gcnew Label();
					  birthdayLabel->AutoSize = true;
					  birthdayLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  birthdayLabel->Text = L"Birthday: " + gcnew String(foundUser.Birthday.c_str());
					  infoPanel->Controls->Add(birthdayLabel);

					  // Subscription
					  Label^ subscriptionLabel = gcnew Label();
					  subscriptionLabel->AutoSize = true;
					  subscriptionLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  subscriptionLabel->Text = L"Subscription: " + gcnew String(foundUser.subscription.getType().c_str());
					  infoPanel->Controls->Add(subscriptionLabel);

					  // Classes Entered
					  Label^ classesEnteredLabel = gcnew Label();
					  classesEnteredLabel->AutoSize = true;
					  classesEnteredLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  classesEnteredLabel->Text = L"Classes Entered: " + foundUser.classEntered.ToString();
					  infoPanel->Controls->Add(classesEnteredLabel);

					  // Wallet
					  Label^ walletLabel = gcnew Label();
					  walletLabel->AutoSize = true;
					  walletLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  walletLabel->Text = L"Wallet Balance: " + String::Format(L"${0:F2}", foundUser.myWallet);
					  infoPanel->Controls->Add(walletLabel);

					  // VIP Status
					  Label^ vipLabel = gcnew Label();
					  vipLabel->AutoSize = true;
					  vipLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  vipLabel->Text = L"VIP Status: " + (foundUser.isVip ? L"Yes" : L"No");
					  infoPanel->Controls->Add(vipLabel);

					  // Picture Path
					  Label^ picPathLabel = gcnew Label();
					  picPathLabel->AutoSize = true;
					  picPathLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
					  picPathLabel->Text = L"Picture Path: " + gcnew String(foundUser.PicPath.c_str()) + L"\n";
					  infoPanel->Controls->Add(picPathLabel);

					  // Reserved Classes
					  Label^ reservedClassesHeader = gcnew Label();
					  reservedClassesHeader->AutoSize = true;
					  reservedClassesHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  reservedClassesHeader->ForeColor = Color::Navy;
					  reservedClassesHeader->Text = L"Reserved Classes:\n";
					  infoPanel->Controls->Add(reservedClassesHeader);

					  if (foundUser.myClasses.empty()) {
						   Label^ noClassesLabel = gcnew Label();
						   noClassesLabel->AutoSize = true;
						   noClassesLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noClassesLabel->ForeColor = Color::DarkGreen;
						   noClassesLabel->Text = L"  None";
						   infoPanel->Controls->Add(noClassesLabel);
					  }
					  else {
						   for (const auto& classID : foundUser.myClasses) {
								Label^ classLabel = gcnew Label();
								classLabel->AutoSize = true;
								classLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								classLabel->ForeColor = Color::DarkGreen;
								classLabel->Text = L"  - " + gcnew String(classID.c_str());
								infoPanel->Controls->Add(classLabel);
						   }
					  }

					  // Waiting List
					  Label^ waitingListHeader = gcnew Label();
					  waitingListHeader->AutoSize = true;
					  waitingListHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  waitingListHeader->ForeColor = Color::Navy;
					  waitingListHeader->Text = L"\nWaiting List Classes:\n";
					  infoPanel->Controls->Add(waitingListHeader);

					  if (foundUser.myWaitingList.empty()) {
						   Label^ noWaitingLabel = gcnew Label();
						   noWaitingLabel->AutoSize = true;
						   noWaitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noWaitingLabel->ForeColor = Color::DarkGreen;
						   noWaitingLabel->Text = L"  None";
						   infoPanel->Controls->Add(noWaitingLabel);
					  }
					  else {
						   for (const auto& classID : foundUser.myWaitingList) {
								Label^ waitingLabel = gcnew Label();
								waitingLabel->AutoSize = true;
								waitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								waitingLabel->ForeColor = Color::DarkGreen;
								waitingLabel->Text = L"  - " + gcnew String(classID.c_str());
								infoPanel->Controls->Add(waitingLabel);
						   }
					  }

					  // Reservations
					  Label^ reservationsHeader = gcnew Label();
					  reservationsHeader->AutoSize = true;
					  reservationsHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  reservationsHeader->ForeColor = Color::Navy;
					  reservationsHeader->Text = L"\nReserved Slots:\n";
					  infoPanel->Controls->Add(reservationsHeader);

					  if (foundUser.myReservations.empty()) {
						   Label^ noReservationsLabel = gcnew Label();
						   noReservationsLabel->AutoSize = true;
						   noReservationsLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
						   noReservationsLabel->ForeColor = Color::DarkGreen;
						   noReservationsLabel->Text = L"  None";
						   infoPanel->Controls->Add(noReservationsLabel);
					  }
					  else {
						   int slotIndex = 1;
						   for (const auto& slot : foundUser.myReservations) {
								Label^ slotHeader = gcnew Label();
								slotHeader->AutoSize = true;
								slotHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								slotHeader->ForeColor = Color::DarkGreen;
								slotHeader->Text = String::Format(L"  Slot {0}:", slotIndex);
								infoPanel->Controls->Add(slotHeader);

								Label^ courtNameLabel = gcnew Label();
								courtNameLabel->AutoSize = true;
								courtNameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								courtNameLabel->ForeColor = Color::DarkGreen;
								courtNameLabel->Text = L"    Court Name: " + gcnew String(slot.courtName.c_str());
								infoPanel->Controls->Add(courtNameLabel);

								Label^ dateLabel = gcnew Label();
								dateLabel->AutoSize = true;
								dateLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								dateLabel->ForeColor = Color::DarkGreen;
								dateLabel->Text = L"    Date: " + gcnew String(slot.date.c_str());
								infoPanel->Controls->Add(dateLabel);

								Label^ startTimeLabel = gcnew Label();
								startTimeLabel->AutoSize = true;
								startTimeLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								startTimeLabel->ForeColor = Color::DarkGreen;
								startTimeLabel->Text = L"    Start Time: " + gcnew String(slot.startTime.c_str());
								infoPanel->Controls->Add(startTimeLabel);

								Label^ courtIDLabel = gcnew Label();
								courtIDLabel->AutoSize = true;
								courtIDLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
								courtIDLabel->ForeColor = Color::DarkGreen;
								courtIDLabel->Text = L"    Court ID: " + gcnew String(slot.ID.c_str());
								infoPanel->Controls->Add(courtIDLabel);

								slotIndex++;
						   }
					  }
				 }
				 else {
					  Label^ notFoundLabel = gcnew Label();
					  notFoundLabel->AutoSize = true;
					  notFoundLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
					  notFoundLabel->ForeColor = Color::Red;
					  notFoundLabel->Text = L"User not found.";
					  infoPanel->Controls->Add(notFoundLabel);
				 }
			}

			void displayCoachClasses(System::String^ coachIDText, System::Windows::Forms::DataGridView^ gridView, System::Windows::Forms::Label^ infoLabel) {
				 extern unordered_map<std::string, Staff> staffList;
				 extern unordered_map<std::string, GymClasses> gymClassList;

				 System::String^ trimmedID = coachIDText->Trim();
				 gridView->Visible = false;
				 infoLabel->Visible = false;
				 gridView->Rows->Clear();
				 gridView->Columns->Clear();
				 infoLabel->Text = L"";

				 if (String::IsNullOrEmpty(trimmedID)) {
					  MessageBox::Show("Please enter a valid Coach ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }
				 std::string coachID = msclr::interop::marshal_as<std::string>(trimmedID);

				 if (staffList.empty()) {
					  MessageBox::Show("No staff data available. Please ensure staff list is populated.",
						   "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }

				 Staff foundCoach;
				 bool coachFound = false;
				 for (const auto& pair : staffList) {
					  if (pair.first == coachID && _stricmp(pair.second.role.c_str(), "coach") == 0) {
						   foundCoach = pair.second;
						   coachFound = true;
						   break;
					  }
				 }

				 if (!coachFound) {
					  bool idExists = staffList.find(coachID) != staffList.end();
					  String^ errorMsg = "Coach with ID " + trimmedID + " not found or not a coach.\n";
					  if (idExists) {
						   errorMsg += "ID exists but role is '" + gcnew String(staffList[coachID].role.c_str()) + "'. Expected 'Coach'.";
					  }
					  else {
						   errorMsg += "ID not found in staff list.";
					  }
					  errorMsg += "\nPlease verify the ID and role.";
					  MessageBox::Show(errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					  return;
				 }

				 infoLabel->Text = "Coach Information\n" +
					  "Name: " + gcnew String(foundCoach.name.c_str()) + "\n" +
					  "Email: " + gcnew String(foundCoach.email.c_str()) + "\n" +
					  "Phone: " + gcnew String(foundCoach.phone.c_str());
				 infoLabel->Visible = true;

				 gridView->Columns->Add("ClassID", "Class ID");
				 gridView->Columns->Add("ClassName", "Class Name");
				 gridView->Columns->Add("Date", "Date");
				 gridView->Columns->Add("StartTime", "Start Time");
				 gridView->Columns->Add("EndTime", "End Time");

				 bool hasClasses = false;
				 for (const auto& pair : gymClassList) {
					  const GymClasses& gymClass = pair.second;
					  if (gymClass.instructorID == coachID) {
						   hasClasses = true;
						   for (const auto& session : gymClass.sessions) {
								gridView->Rows->Add(
									 gcnew String(gymClass.classID.c_str()),
									 gcnew String(gymClass.className.c_str()),
									 gcnew String(session.date.c_str()),
									 gcnew String(session.startTime.c_str()),
									 gcnew String(session.endTime.c_str()));
						   }
					  }
				 }

				 if (!hasClasses) {
					  MessageBox::Show("No classes assigned to this Coach yet.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 }
				 else {
					  gridView->Visible = true;
				 }
			}

#pragma region Windows Form Designer generated code
	 private:
		  void InitializeComponent(void) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(staffPage::typeid));
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->displayclasses = (gcnew System::Windows::Forms::Button());
			   this->AddNewUser = (gcnew System::Windows::Forms::Button());
			   this->SendNotification = (gcnew System::Windows::Forms::Button());
			   this->profile_pn = (gcnew System::Windows::Forms::Panel());
			   this->AccName = (gcnew System::Windows::Forms::Label());
			   this->AccPic = (gcnew System::Windows::Forms::PictureBox());
			   this->MainPage = (gcnew System::Windows::Forms::Panel());
			   this->userAttend = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->ListOFUserEX = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->searchCoach = (gcnew System::Windows::Forms::Panel());
			   this->coachInfoLabel = (gcnew System::Windows::Forms::Label());
			   this->coachIDTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->searchCoachButton = (gcnew System::Windows::Forms::Button());
			   this->classGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->searchUser = (gcnew System::Windows::Forms::Panel());
			   this->searchUserButton = (gcnew System::Windows::Forms::Button());
			   this->userInfoPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->userIDTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->userIDLabel = (gcnew System::Windows::Forms::Label());
			   this->MainMenu_pn->SuspendLayout();
			   this->profile_pn->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
			   this->MainPage->SuspendLayout();
			   this->searchCoach->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->BeginInit();
			   this->searchUser->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // MainMenu_pn
			   // 
			   this->MainMenu_pn->Controls->Add(this->button1);
			   this->MainMenu_pn->Controls->Add(this->displayclasses);
			   this->MainMenu_pn->Controls->Add(this->AddNewUser);
			   this->MainMenu_pn->Controls->Add(this->SendNotification);
			   this->MainMenu_pn->Controls->Add(this->profile_pn);
			   this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
			   this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
			   this->MainMenu_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MainMenu_pn->Name = L"MainMenu_pn";
			   this->MainMenu_pn->Size = System::Drawing::Size(313, 738);
			   this->MainMenu_pn->TabIndex = 1;
			   // 
			   // button1
			   // 
			   this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->button1->Location = System::Drawing::Point(0, 429);
			   this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(313, 73);
			   this->button1->TabIndex = 5;
			   this->button1->Text = L"Search User";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &staffPage::button1_Click);
			   // 
			   // displayclasses
			   // 
			   this->displayclasses->Dock = System::Windows::Forms::DockStyle::Top;
			   this->displayclasses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->displayclasses->Location = System::Drawing::Point(0, 356);
			   this->displayclasses->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->displayclasses->Name = L"displayclasses";
			   this->displayclasses->Size = System::Drawing::Size(313, 73);
			   this->displayclasses->TabIndex = 4;
			   this->displayclasses->Text = L"Display Classes";
			   this->displayclasses->UseVisualStyleBackColor = true;
			   this->displayclasses->Click += gcnew System::EventHandler(this, &staffPage::displayclasses_Click);
			   // 
			   // AddNewUser
			   // 
			   this->AddNewUser->Dock = System::Windows::Forms::DockStyle::Top;
			   this->AddNewUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->AddNewUser->Location = System::Drawing::Point(0, 280);
			   this->AddNewUser->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->AddNewUser->Name = L"AddNewUser";
			   this->AddNewUser->Size = System::Drawing::Size(313, 76);
			   this->AddNewUser->TabIndex = 3;
			   this->AddNewUser->Text = L"Register new user";
			   this->AddNewUser->UseVisualStyleBackColor = true;
			   this->AddNewUser->Click += gcnew System::EventHandler(this, &staffPage::AddNewUser_Click);
			   // 
			   // SendNotification
			   // 
			   this->SendNotification->Dock = System::Windows::Forms::DockStyle::Top;
			   this->SendNotification->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->SendNotification->Location = System::Drawing::Point(0, 212);
			   this->SendNotification->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			   this->profile_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->profile_pn->Name = L"profile_pn";
			   this->profile_pn->Size = System::Drawing::Size(313, 212);
			   this->profile_pn->TabIndex = 1;
			   // 
			   // AccName
			   // 
			   this->AccName->AutoSize = true;
			   this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			   this->AccName->Location = System::Drawing::Point(3, 175);
			   this->AccName->Name = L"AccName";
			   this->AccName->Size = System::Drawing::Size(58, 22);
			   this->AccName->TabIndex = 1;
			   this->AccName->Text = L"label1";
			   // 
			   // AccPic
			   // 
			   this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
			   this->AccPic->Location = System::Drawing::Point(37, 12);
			   this->AccPic->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->AccPic->Name = L"AccPic";
			   this->AccPic->Size = System::Drawing::Size(213, 146);
			   this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->AccPic->TabIndex = 0;
			   this->AccPic->TabStop = false;
			   this->AccPic->Click += gcnew System::EventHandler(this, &staffPage::AccPic_Click);
			   // 
			   // MainPage
			   // 
			   this->MainPage->Controls->Add(this->userAttend);
			   this->MainPage->Controls->Add(this->ListOFUserEX);
			   this->MainPage->Controls->Add(this->searchCoach);
			   this->MainPage->Controls->Add(this->searchUser);
			   this->MainPage->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->MainPage->Location = System::Drawing::Point(313, 0);
			   this->MainPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MainPage->Name = L"MainPage";
			   this->MainPage->Size = System::Drawing::Size(960, 738);
			   this->MainPage->TabIndex = 2;
			   // 
			   // userAttend
			   // 
			   this->userAttend->AutoScroll = true;
			   this->userAttend->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->userAttend->Location = System::Drawing::Point(0, 0);
			   this->userAttend->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->userAttend->Name = L"userAttend";
			   this->userAttend->Size = System::Drawing::Size(960, 738);
			   this->userAttend->TabIndex = 3;
			   // 
			   // ListOFUserEX
			   // 
			   this->ListOFUserEX->AutoScroll = true;
			   this->ListOFUserEX->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->ListOFUserEX->Location = System::Drawing::Point(0, 0);
			   this->ListOFUserEX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->ListOFUserEX->Name = L"ListOFUserEX";
			   this->ListOFUserEX->Size = System::Drawing::Size(960, 738);
			   this->ListOFUserEX->TabIndex = 0;
			   // 
			   // searchCoach
			   // 
			   this->searchCoach->Controls->Add(this->coachInfoLabel);
			   this->searchCoach->Controls->Add(this->coachIDTextBox);
			   this->searchCoach->Controls->Add(this->searchCoachButton);
			   this->searchCoach->Controls->Add(this->classGridView);
			   this->searchCoach->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->searchCoach->Location = System::Drawing::Point(0, 0);
			   this->searchCoach->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->searchCoach->Name = L"searchCoach";
			   this->searchCoach->Size = System::Drawing::Size(960, 738);
			   this->searchCoach->TabIndex = 1;
			   this->searchCoach->Leave += gcnew System::EventHandler(this, &staffPage::searchCoach_Leave);
			   // 
			   // coachInfoLabel
			   // 
			   this->coachInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			   this->coachInfoLabel->Location = System::Drawing::Point(29, 121);
			   this->coachInfoLabel->Margin = System::Windows::Forms::Padding(4);
			   this->coachInfoLabel->Name = L"coachInfoLabel";
			   this->coachInfoLabel->Size = System::Drawing::Size(301, 80);
			   this->coachInfoLabel->TabIndex = 13;
			   // 
			   // coachIDTextBox
			   // 
			   this->coachIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			   this->coachIDTextBox->Location = System::Drawing::Point(360, 74);
			   this->coachIDTextBox->Margin = System::Windows::Forms::Padding(4);
			   this->coachIDTextBox->Name = L"coachIDTextBox";
			   this->coachIDTextBox->Size = System::Drawing::Size(187, 34);
			   this->coachIDTextBox->TabIndex = 3;
			   // 
			   // searchCoachButton
			   // 
			   this->searchCoachButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->searchCoachButton->Location = System::Drawing::Point(359, 11);
			   this->searchCoachButton->Margin = System::Windows::Forms::Padding(4);
			   this->searchCoachButton->Name = L"searchCoachButton";
			   this->searchCoachButton->Size = System::Drawing::Size(188, 55);
			   this->searchCoachButton->TabIndex = 4;
			   this->searchCoachButton->Text = L"Enter Coach ID";
			   this->searchCoachButton->UseVisualStyleBackColor = true;
			   this->searchCoachButton->Click += gcnew System::EventHandler(this, &staffPage::searchCoachButton_Click);
			   // 
			   // classGridView
			   // 
			   this->classGridView->AllowUserToAddRows = false;
			   this->classGridView->AllowUserToDeleteRows = false;
			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::AliceBlue;
			   this->classGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			   this->classGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->classGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::Navy;
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->classGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->classGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			   dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
			   dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::LightBlue;
			   dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->classGridView->DefaultCellStyle = dataGridViewCellStyle3;
			   this->classGridView->EnableHeadersVisualStyles = false;
			   this->classGridView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   this->classGridView->GridColor = System::Drawing::Color::LightGray;
			   this->classGridView->Location = System::Drawing::Point(7, 237);
			   this->classGridView->Margin = System::Windows::Forms::Padding(4);
			   this->classGridView->Name = L"classGridView";
			   this->classGridView->ReadOnly = true;
			   this->classGridView->RowHeadersVisible = false;
			   this->classGridView->RowHeadersWidth = 51;
			   this->classGridView->RowTemplate->Height = 40;
			   this->classGridView->Size = System::Drawing::Size(940, 488);
			   this->classGridView->TabIndex = 12;
			   // 
			   // searchUser
			   // 
			   this->searchUser->BackColor = System::Drawing::SystemColors::Control;
			   this->searchUser->Controls->Add(this->searchUserButton);
			   this->searchUser->Controls->Add(this->userInfoPanel);
			   this->searchUser->Controls->Add(this->userIDTextBox);
			   this->searchUser->Controls->Add(this->userIDLabel);
			   this->searchUser->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->searchUser->Location = System::Drawing::Point(0, 0);
			   this->searchUser->Margin = System::Windows::Forms::Padding(5);
			   this->searchUser->Name = L"searchUser";
			   this->searchUser->Size = System::Drawing::Size(960, 738);
			   this->searchUser->TabIndex = 2;
			   this->searchUser->Leave += gcnew System::EventHandler(this, &staffPage::searchUser_Leave);
			   // 
			   // searchUserButton
			   // 
			   this->searchUserButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->searchUserButton->Location = System::Drawing::Point(667, 23);
			   this->searchUserButton->Margin = System::Windows::Forms::Padding(5);
			   this->searchUserButton->Name = L"searchUserButton";
			   this->searchUserButton->Size = System::Drawing::Size(195, 36);
			   this->searchUserButton->TabIndex = 11;
			   this->searchUserButton->Text = L"Search";
			   this->searchUserButton->UseVisualStyleBackColor = true;
			   this->searchUserButton->Click += gcnew System::EventHandler(this, &staffPage::searchUserButton_Click);
			   // 
			   // userInfoPanel
			   // 
			   this->userInfoPanel->AutoScroll = true;
			   this->userInfoPanel->BackColor = System::Drawing::SystemColors::Control;
			   this->userInfoPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			   this->userInfoPanel->Location = System::Drawing::Point(73, 121);
			   this->userInfoPanel->Margin = System::Windows::Forms::Padding(5);
			   this->userInfoPanel->Name = L"userInfoPanel";
			   this->userInfoPanel->Size = System::Drawing::Size(827, 554);
			   this->userInfoPanel->TabIndex = 8;
			   this->userInfoPanel->WrapContents = false;
			   // 
			   // userIDTextBox
			   // 
			   this->userIDTextBox->BackColor = System::Drawing::SystemColors::Control;
			   this->userIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			   this->userIDTextBox->Location = System::Drawing::Point(267, 25);
			   this->userIDTextBox->Margin = System::Windows::Forms::Padding(4, 2, 4, 2);
			   this->userIDTextBox->Name = L"userIDTextBox";
			   this->userIDTextBox->Size = System::Drawing::Size(265, 34);
			   this->userIDTextBox->TabIndex = 10;
			   // 
			   // userIDLabel
			   // 
			   this->userIDLabel->AutoSize = true;
			   this->userIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->userIDLabel->Location = System::Drawing::Point(67, 25);
			   this->userIDLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->userIDLabel->Name = L"userIDLabel";
			   this->userIDLabel->Size = System::Drawing::Size(111, 35);
			   this->userIDLabel->TabIndex = 9;
			   this->userIDLabel->Text = L"User ID";
			   // 
			   // staffPage
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1273, 738);
			   this->Controls->Add(this->MainPage);
			   this->Controls->Add(this->MainMenu_pn);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"staffPage";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"staffPage";
			   this->Load += gcnew System::EventHandler(this, &staffPage::staffPage_Load);
			   this->MainMenu_pn->ResumeLayout(false);
			   this->profile_pn->ResumeLayout(false);
			   this->profile_pn->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->EndInit();
			   this->MainPage->ResumeLayout(false);
			   this->searchCoach->ResumeLayout(false);
			   this->searchCoach->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->EndInit();
			   this->searchUser->ResumeLayout(false);
			   this->searchUser->PerformLayout();
			   this->ResumeLayout(false);

		  }
#pragma endregion

	 private:
		  System::Void staffPage_Load(System::Object^ sender, System::EventArgs^ e) {
			   this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");

			   if (staffList.find(loginID) != staffList.end()) {
					AccName->Text = gcnew String(staffList[loginID].name.c_str());
					if (_stricmp(staffList[loginID].role.c_str(), "coach") == 0) {
						 // button1->Visible = true;
						 SendNotification->Visible = false;
						 AddNewUser->Visible = false;
					}
					else {
						 button1->Visible = false;

					}
			   }

			   else {
					MessageBox::Show("Staff member not found for loginID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					AccName->Text = L"Unknown";
			   }
			   loadpic(AccPic);
			   MakePictureCircular(AccPic);
			   MainPage->Controls->Clear();
			   MainPage->Controls->Add(ListOFUserEX);
			   // 			   ListOFUserEX->BringToFront();
			   // 			   searchCoach->Visible = false;
			   // 			   searchUser->Visible = false;
		  }

		  System::Void AccPic_Click(System::Object^ sender, System::EventArgs^ e) {
		  }

		  System::Void SendNotification_Click(System::Object^ sender, System::EventArgs^ e) {
			   MainPage->Controls->Clear();
			   MainPage->Controls->Add(ListOFUserEX);
			   ListOFUserEX->Controls->Clear();
			   // 			   ListOFUserEX->BringToFront();
			   // 			   searchCoach->Visible = false;
			   // 			   searchUser->Visible = false;
			   isDisplayClassesActive = false;
			   bool printed = false;
			   for (auto& entry : userList) {
					User& user = entry.second;
					int remainingDays = user.subscription.getRemainingDays();
					if (remainingDays < 7) {
						 userExpired^ Expired = gcnew userExpired();
						 Expired->name->Text = "Name: " + gcnew String(user.name.c_str());
						 Expired->name->Tag = gcnew String(user.ID.c_str());
						 Expired->expireDate->Text = "Expire date: " + gcnew String(user.subscription.getEndDate().c_str());
						 Expired->TypeOFSub->Text = "Subscription Type: " + gcnew String(user.subscription.getType().c_str());
						 Expired->AccType->Text = "Account Type: " + gcnew String(user.subscription.get_is_VIP() ? "VIP" : "Normal");
						 ListOFUserEX->Controls->Add(Expired);
						 printed = true;
					}
			   }
			   if (!printed)
					MessageBox::Show("There are no users whose subscriptions are close to expiring.", "Alert", MessageBoxButtons::OK, MessageBoxIcon::Information);

		  }

		  System::Void AddNewUser_Click(System::Object^ sender, System::EventArgs^ e) {
			   sighup^ newPage = gcnew sighup();
			   newPage->groupBox1->Visible = false;
			   newPage->ShowDialog();
			   searchCoach->Visible = false;
			   searchUser->Visible = false;
			   isDisplayClassesActive = false;
		  }

		  System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			   MainPage->Controls->Clear();
			   MainPage->Controls->Add(searchUser);
			   searchUser->BringToFront();
			   searchCoach->Visible = false;
			   searchUser->Visible = true;
			   userIDTextBox->Text = "";
			   userInfoPanel->Controls->Clear();
			   isDisplayClassesActive = false;
		  }

		  System::Void searchUserButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ userIDText = userIDTextBox->Text->Trim();
			   if (String::IsNullOrEmpty(userIDText)) {
					MessageBox::Show("Please enter a valid user ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
			   SearchUserByID(userIDText, userInfoPanel);
			   userInfoPanel->Visible = true;
		  }

		  System::Void searchUser_Leave(System::Object^ sender, System::EventArgs^ e) {
			   userInfoPanel->Controls->Clear();
			   userIDTextBox->Clear();
			   searchUser->Visible = false;
		  }

		  System::Void displayclasses_Click(System::Object^ sender, System::EventArgs^ e) {
			   extern unordered_map<std::string, Staff> staffList;
			   if (staffList.find(loginID) == staffList.end()) {
					MessageBox::Show("Staff member not found for loginID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
			   MainPage->Controls->Clear();
			   searchUser->Visible = false;
			   if (_stricmp(staffList[loginID].role.c_str(), "coach") == 0) {



					MainPage->Controls->Add(classGridView);
					MainPage->Controls->Add(coachInfoLabel);
					classGridView->BringToFront();
					coachInfoLabel->BringToFront();
					searchCoach->Visible = false;
					isDisplayClassesActive = false;

					displayCoachClasses(gcnew String(loginID.c_str()), classGridView, coachInfoLabel);
			   }
			   else if (_stricmp(staffList[loginID].role.c_str(), "reception") == 0) {
					MainPage->Controls->Add(searchCoach);
					searchCoach->Visible = true;
					searchCoach->BringToFront();
					coachIDTextBox->Clear();
					coachInfoLabel->Text = L"";
					classGridView->Rows->Clear();
					classGridView->Columns->Clear();
					isDisplayClassesActive = true;
			   }
			   else {
					searchCoach->Visible = false;
					isDisplayClassesActive = false;
			   }
		  }

		  System::Void searchCoachButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ coachIDText = coachIDTextBox->Text->Trim();
			   if (String::IsNullOrEmpty(coachIDText)) {
					MessageBox::Show("Please enter a valid Coach ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
			   }
			   displayCoachClasses(coachIDText, classGridView, coachInfoLabel);
		  }

		  System::Void searchCoach_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (isDisplayClassesActive) {
					coachInfoLabel->Text = L"";
					classGridView->Rows->Clear();
					classGridView->Columns->Clear();
					coachIDTextBox->Clear();
			   }
			   else {
					searchCoach->Visible = false;
			   }
		  }

	 };
}