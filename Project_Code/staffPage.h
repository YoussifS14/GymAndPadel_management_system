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
    using namespace System::Drawing::Drawing2D;

    public ref class staffPage : public System::Windows::Forms::Form {
    public:
        staffPage(void) {
            InitializeComponent();
            // Initially hide panels
            searchCoach->Visible = false;
            searchUser->Visible = false;
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
        System::Windows::Forms::FlowLayoutPanel^ userAttend;
        System::Windows::Forms::Button^ LogOutbutton; // Logout button
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Panel^ panel1;

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
                   errorLabel->ForeColor = Color::FromArgb(255, 234, 0);
                   errorLabel->BackColor = Color::Black;
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
                   headerLabel->ForeColor = Color::FromArgb(255, 234, 0);
                   headerLabel->BackColor = Color::Black;
                   headerLabel->Text = L"User Information:\n";
                   infoPanel->Controls->Add(headerLabel);

                   // Name
                   Label^ nameLabel = gcnew Label();
                   nameLabel->AutoSize = true;
                   nameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   nameLabel->ForeColor = Color::White;
                   nameLabel->BackColor = Color::Black;
                   nameLabel->Text = L"Name: " + gcnew String(foundUser.name.c_str());
                   infoPanel->Controls->Add(nameLabel);

                   // Birthday
                   Label^ birthdayLabel = gcnew Label();
                   birthdayLabel->AutoSize = true;
                   birthdayLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   birthdayLabel->ForeColor = Color::White;
                   birthdayLabel->BackColor = Color::Black;
                   birthdayLabel->Text = L"Birthday: " + gcnew String(foundUser.Birthday.c_str());
                   infoPanel->Controls->Add(birthdayLabel);

                   // Subscription
                   Label^ subscriptionLabel = gcnew Label();
                   subscriptionLabel->AutoSize = true;
                   subscriptionLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   subscriptionLabel->ForeColor = Color::White;
                   subscriptionLabel->BackColor = Color::Black;
                   subscriptionLabel->Text = L"Subscription: " + gcnew String(foundUser.subscription.getType().c_str());
                   infoPanel->Controls->Add(subscriptionLabel);

                   // Classes Entered
                   Label^ classesEnteredLabel = gcnew Label();
                   classesEnteredLabel->AutoSize = true;
                   classesEnteredLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   classesEnteredLabel->ForeColor = Color::White;
                   classesEnteredLabel->BackColor = Color::Black;
                   classesEnteredLabel->Text = L"Classes Entered: " + foundUser.classEntered.ToString();
                   infoPanel->Controls->Add(classesEnteredLabel);

                   // Wallet
                   Label^ walletLabel = gcnew Label();
                   walletLabel->AutoSize = true;
                   walletLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   walletLabel->ForeColor = Color::White;
                   walletLabel->BackColor = Color::Black;
                   walletLabel->Text = L"Wallet Balance: " + String::Format(L"${0:F2}", foundUser.myWallet);
                   infoPanel->Controls->Add(walletLabel);

                   // VIP Status
                   Label^ vipLabel = gcnew Label();
                   vipLabel->AutoSize = true;
                   vipLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   vipLabel->ForeColor = Color::White;
                   vipLabel->BackColor = Color::Black;
                   vipLabel->Text = L"VIP Status: " + (foundUser.isVip ? L"Yes" : L"No");
                   infoPanel->Controls->Add(vipLabel);

                   // Picture Path
                   Label^ picPathLabel = gcnew Label();
                   picPathLabel->AutoSize = true;
                   picPathLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                   picPathLabel->ForeColor = Color::White;
                   picPathLabel->BackColor = Color::Black;
                   picPathLabel->Text = L"Picture Path: " + gcnew String(foundUser.PicPath.c_str()) + L"\n";
                   infoPanel->Controls->Add(picPathLabel);

                   // Reserved Classes
                   Label^ reservedClassesHeader = gcnew Label();
                   reservedClassesHeader->AutoSize = true;
                   reservedClassesHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
                   reservedClassesHeader->ForeColor = Color::FromArgb(255, 234, 0);
                   reservedClassesHeader->BackColor = Color::Black;
                   reservedClassesHeader->Text = L"Reserved Classes:\n";
                   infoPanel->Controls->Add(reservedClassesHeader);

                   if (foundUser.myClasses.empty()) {
                       Label^ noClassesLabel = gcnew Label();
                       noClassesLabel->AutoSize = true;
                       noClassesLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                       noClassesLabel->ForeColor = Color::White;
                       noClassesLabel->BackColor = Color::Black;
                       noClassesLabel->Text = L"  None";
                       infoPanel->Controls->Add(noClassesLabel);
                   }
                   else {
                       for (const auto& classID : foundUser.myClasses) {
                           Label^ classLabel = gcnew Label();
                           classLabel->AutoSize = true;
                           classLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           classLabel->ForeColor = Color::White;
                           classLabel->BackColor = Color::Black;
                           classLabel->Text = L"  - " + gcnew String(classID.c_str());
                           infoPanel->Controls->Add(classLabel);
                       }
                   }

                   // Waiting List
                   Label^ waitingListHeader = gcnew Label();
                   waitingListHeader->AutoSize = true;
                   waitingListHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
                   waitingListHeader->ForeColor = Color::FromArgb(255, 234, 0);
                   waitingListHeader->BackColor = Color::Black;
                   waitingListHeader->Text = L"\nWaiting List Classes:\n";
                   infoPanel->Controls->Add(waitingListHeader);

                   if (foundUser.myWaitingList.empty()) {
                       Label^ noWaitingLabel = gcnew Label();
                       noWaitingLabel->AutoSize = true;
                       noWaitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                       noWaitingLabel->ForeColor = Color::White;
                       noWaitingLabel->BackColor = Color::Black;
                       noWaitingLabel->Text = L"  None";
                       infoPanel->Controls->Add(noWaitingLabel);
                   }
                   else {
                       for (const auto& classID : foundUser.myWaitingList) {
                           Label^ waitingLabel = gcnew Label();
                           waitingLabel->AutoSize = true;
                           waitingLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           waitingLabel->ForeColor = Color::White;
                           waitingLabel->BackColor = Color::Black;
                           waitingLabel->Text = L"  - " + gcnew String(classID.c_str());
                           infoPanel->Controls->Add(waitingLabel);
                       }
                   }

                   // Reservations
                   Label^ reservationsHeader = gcnew Label();
                   reservationsHeader->AutoSize = true;
                   reservationsHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
                   reservationsHeader->ForeColor = Color::FromArgb(255, 234, 0);
                   reservationsHeader->BackColor = Color::Black;
                   reservationsHeader->Text = L"\nReserved Slots:\n";
                   infoPanel->Controls->Add(reservationsHeader);

                   if (foundUser.myReservations.empty()) {
                       Label^ noReservationsLabel = gcnew Label();
                       noReservationsLabel->AutoSize = true;
                       noReservationsLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                       noReservationsLabel->ForeColor = Color::White;
                       noReservationsLabel->BackColor = Color::Black;
                       noReservationsLabel->Text = L"  None";
                       infoPanel->Controls->Add(noReservationsLabel);
                   }
                   else {
                       int slotIndex = 1;
                       for (const auto& slot : foundUser.myReservations) {
                           Label^ slotHeader = gcnew Label();
                           slotHeader->AutoSize = true;
                           slotHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           slotHeader->ForeColor = Color::White;
                           slotHeader->BackColor = Color::Black;
                           slotHeader->Text = String::Format(L"  Slot {0}:", slotIndex);
                           infoPanel->Controls->Add(slotHeader);

                           Label^ courtNameLabel = gcnew Label();
                           courtNameLabel->AutoSize = true;
                           courtNameLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           courtNameLabel->ForeColor = Color::White;
                           courtNameLabel->BackColor = Color::Black;
                           courtNameLabel->Text = L"    Court Name: " + gcnew String(slot.courtName.c_str());
                           infoPanel->Controls->Add(courtNameLabel);

                           Label^ dateLabel = gcnew Label();
                           dateLabel->AutoSize = true;
                           dateLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           dateLabel->ForeColor = Color::White;
                           dateLabel->BackColor = Color::Black;
                           dateLabel->Text = L"    Date: " + gcnew String(slot.date.c_str());
                           infoPanel->Controls->Add(dateLabel);

                           Label^ startTimeLabel = gcnew Label();
                           startTimeLabel->AutoSize = true;
                           startTimeLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           startTimeLabel->ForeColor = Color::White;
                           startTimeLabel->BackColor = Color::Black;
                           startTimeLabel->Text = L"    Start Time: " + gcnew String(slot.startTime.c_str());
                           infoPanel->Controls->Add(startTimeLabel);

                           Label^ courtIDLabel = gcnew Label();
                           courtIDLabel->AutoSize = true;
                           courtIDLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
                           courtIDLabel->ForeColor = Color::White;
                           courtIDLabel->BackColor = Color::Black;
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
                   notFoundLabel->ForeColor = Color::White;
                   notFoundLabel->BackColor = Color::Black;
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

               infoLabel->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Regular);
               infoLabel->ForeColor = Color::White;
               infoLabel->BackColor = Color::Black;
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
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
            this->profile_pn = (gcnew System::Windows::Forms::Panel());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->SendNotification = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->AddNewUser = (gcnew System::Windows::Forms::Button());
            this->displayclasses = (gcnew System::Windows::Forms::Button());
            this->LogOutbutton = (gcnew System::Windows::Forms::Button());
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
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
            this->MainPage->SuspendLayout();
            this->searchCoach->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->BeginInit();
            this->searchUser->SuspendLayout();
            this->SuspendLayout();
            // 
            // MainMenu_pn
            // 
            this->MainMenu_pn->BackColor = System::Drawing::Color::Black;
            this->MainMenu_pn->Controls->Add(this->profile_pn);
            this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
            this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
            this->MainMenu_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->MainMenu_pn->Name = L"MainMenu_pn";
            this->MainMenu_pn->Size = System::Drawing::Size(297, 738);
            this->MainMenu_pn->TabIndex = 1;
            // 
            // profile_pn
            // 
            this->profile_pn->BackColor = System::Drawing::Color::Black;
            this->profile_pn->Controls->Add(this->panel1);
            this->profile_pn->Controls->Add(this->LogOutbutton);
            this->profile_pn->Controls->Add(this->AccName);
            this->profile_pn->Controls->Add(this->AccPic);
            this->profile_pn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->profile_pn->Location = System::Drawing::Point(0, 0);
            this->profile_pn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->profile_pn->Name = L"profile_pn";
            this->profile_pn->Size = System::Drawing::Size(297, 738);
            this->profile_pn->TabIndex = 1;
            // 
            // panel1
            // 
            this->panel1->Controls->Add(this->SendNotification);
            this->panel1->Controls->Add(this->button1);
            this->panel1->Controls->Add(this->AddNewUser);
            this->panel1->Controls->Add(this->displayclasses);
            this->panel1->Location = System::Drawing::Point(3, 214);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(291, 429);
            this->panel1->TabIndex = 0;
            // 
            // SendNotification
            // 
            this->SendNotification->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->SendNotification->Dock = System::Windows::Forms::DockStyle::Top;
            this->SendNotification->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->SendNotification->ForeColor = System::Drawing::Color::Black;
            this->SendNotification->Location = System::Drawing::Point(0, 200);
            this->SendNotification->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->SendNotification->Name = L"SendNotification";
            this->SendNotification->Size = System::Drawing::Size(291, 76);
            this->SendNotification->TabIndex = 2;
            this->SendNotification->Text = L"Send Notification";
            this->SendNotification->UseVisualStyleBackColor = false;
            this->SendNotification->Click += gcnew System::EventHandler(this, &staffPage::SendNotification_Click);
            this->SendNotification->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->SendNotification->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->button1->Dock = System::Windows::Forms::DockStyle::Top;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::Black;
            this->button1->Location = System::Drawing::Point(0, 128);
            this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(291, 72);
            this->button1->TabIndex = 5;
            this->button1->Text = L"Search User";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &staffPage::button1_Click);
            this->button1->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->button1->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // AddNewUser
            // 
            this->AddNewUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->AddNewUser->Dock = System::Windows::Forms::DockStyle::Top;
            this->AddNewUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->AddNewUser->ForeColor = System::Drawing::Color::Black;
            this->AddNewUser->Location = System::Drawing::Point(0, 62);
            this->AddNewUser->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->AddNewUser->Name = L"AddNewUser";
            this->AddNewUser->Size = System::Drawing::Size(291, 66);
            this->AddNewUser->TabIndex = 3;
            this->AddNewUser->Text = L"Register new user";
            this->AddNewUser->UseVisualStyleBackColor = false;
            this->AddNewUser->Click += gcnew System::EventHandler(this, &staffPage::AddNewUser_Click);
            this->AddNewUser->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->AddNewUser->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // displayclasses
            // 
            this->displayclasses->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->displayclasses->Dock = System::Windows::Forms::DockStyle::Top;
            this->displayclasses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->displayclasses->ForeColor = System::Drawing::Color::Black;
            this->displayclasses->Location = System::Drawing::Point(0, 0);
            this->displayclasses->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->displayclasses->Name = L"displayclasses";
            this->displayclasses->Size = System::Drawing::Size(291, 62);
            this->displayclasses->TabIndex = 4;
            this->displayclasses->Text = L"Display Classes";
            this->displayclasses->UseVisualStyleBackColor = false;
            this->displayclasses->Click += gcnew System::EventHandler(this, &staffPage::displayclasses_Click);
            this->displayclasses->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->displayclasses->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // LogOutbutton
            // 
            this->LogOutbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->LogOutbutton->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->LogOutbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LogOutbutton->ForeColor = System::Drawing::Color::Black;
            this->LogOutbutton->Location = System::Drawing::Point(0, 679);
            this->LogOutbutton->Name = L"LogOutbutton";
            this->LogOutbutton->Size = System::Drawing::Size(297, 59);
            this->LogOutbutton->TabIndex = 6;
            this->LogOutbutton->Text = L"Log out";
            this->LogOutbutton->UseVisualStyleBackColor = false;
            this->LogOutbutton->Click += gcnew System::EventHandler(this, &staffPage::LogOutbutton_Click);
            this->LogOutbutton->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->LogOutbutton->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // AccName
            // 
            this->AccName->AutoSize = true;
            this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->AccName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->AccName->Location = System::Drawing::Point(12, 154);
            this->AccName->Name = L"AccName";
            this->AccName->Size = System::Drawing::Size(62, 23);
            this->AccName->TabIndex = 1;
            this->AccName->Text = L"Name";
            // 
            // AccPic
            // 
            this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
            this->AccPic->Location = System::Drawing::Point(27, 23);
            this->AccPic->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->AccPic->Name = L"AccPic";
            this->AccPic->Size = System::Drawing::Size(213, 110);
            this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->AccPic->TabIndex = 0;
            this->AccPic->TabStop = false;
            this->AccPic->Click += gcnew System::EventHandler(this, &staffPage::AccPic_Click);
            // 
            // MainPage
            // 
            this->MainPage->BackColor = System::Drawing::Color::Black;
            this->MainPage->Controls->Add(this->userAttend);
            this->MainPage->Controls->Add(this->ListOFUserEX);
            this->MainPage->Controls->Add(this->searchCoach);
            this->MainPage->Controls->Add(this->searchUser);
            this->MainPage->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MainPage->Location = System::Drawing::Point(297, 0);
            this->MainPage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->MainPage->Name = L"MainPage";
            this->MainPage->Size = System::Drawing::Size(976, 738);
            this->MainPage->TabIndex = 2;
            // 
            // userAttend
            // 
            this->userAttend->AutoScroll = true;
            this->userAttend->BackColor = System::Drawing::Color::Black;
            this->userAttend->Dock = System::Windows::Forms::DockStyle::Fill;
            this->userAttend->Location = System::Drawing::Point(0, 0);
            this->userAttend->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->userAttend->Name = L"userAttend";
            this->userAttend->Size = System::Drawing::Size(976, 738);
            this->userAttend->TabIndex = 3;
            // 
            // ListOFUserEX
            // 
            this->ListOFUserEX->AutoScroll = true;
            this->ListOFUserEX->BackColor = System::Drawing::Color::Black;
            this->ListOFUserEX->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ListOFUserEX->Location = System::Drawing::Point(0, 0);
            this->ListOFUserEX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->ListOFUserEX->Name = L"ListOFUserEX";
            this->ListOFUserEX->Size = System::Drawing::Size(976, 738);
            this->ListOFUserEX->TabIndex = 0;
            // 
            // searchCoach
            // 
            this->searchCoach->BackColor = System::Drawing::Color::Black;
            this->searchCoach->Controls->Add(this->coachInfoLabel);
            this->searchCoach->Controls->Add(this->coachIDTextBox);
            this->searchCoach->Controls->Add(this->searchCoachButton);
            this->searchCoach->Controls->Add(this->classGridView);
            this->searchCoach->Dock = System::Windows::Forms::DockStyle::Fill;
            this->searchCoach->Location = System::Drawing::Point(0, 0);
            this->searchCoach->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->searchCoach->Name = L"searchCoach";
            this->searchCoach->Size = System::Drawing::Size(976, 738);
            this->searchCoach->TabIndex = 1;
            this->searchCoach->Leave += gcnew System::EventHandler(this, &staffPage::searchCoach_Leave);
            // 
            // coachInfoLabel
            // 
            this->coachInfoLabel->BackColor = System::Drawing::Color::Black;
            this->coachInfoLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->coachInfoLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->coachInfoLabel->Location = System::Drawing::Point(29, 121);
            this->coachInfoLabel->Margin = System::Windows::Forms::Padding(4);
            this->coachInfoLabel->Name = L"coachInfoLabel";
            this->coachInfoLabel->Size = System::Drawing::Size(301, 80);
            this->coachInfoLabel->TabIndex = 13;
            // 
            // coachIDTextBox
            // 
            this->coachIDTextBox->BackColor = System::Drawing::Color::Black;
            this->coachIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
            this->coachIDTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->coachIDTextBox->Location = System::Drawing::Point(360, 74);
            this->coachIDTextBox->Margin = System::Windows::Forms::Padding(4);
            this->coachIDTextBox->Name = L"coachIDTextBox";
            this->coachIDTextBox->Size = System::Drawing::Size(187, 34);
            this->coachIDTextBox->TabIndex = 3;
            // 
            // searchCoachButton
            // 
            this->searchCoachButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->searchCoachButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
            this->searchCoachButton->ForeColor = System::Drawing::Color::Black;
            this->searchCoachButton->Location = System::Drawing::Point(359, 11);
            this->searchCoachButton->Margin = System::Windows::Forms::Padding(4);
            this->searchCoachButton->Name = L"searchCoachButton";
            this->searchCoachButton->Size = System::Drawing::Size(188, 55);
            this->searchCoachButton->TabIndex = 4;
            this->searchCoachButton->Text = L"Enter Coach ID";
            this->searchCoachButton->UseVisualStyleBackColor = false;
            this->searchCoachButton->Click += gcnew System::EventHandler(this, &staffPage::searchCoachButton_Click);
            this->searchCoachButton->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->searchCoachButton->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // classGridView
            // 
            this->classGridView->AllowUserToAddRows = false;
            this->classGridView->AllowUserToDeleteRows = false;
            dataGridViewCellStyle4->BackColor = System::Drawing::Color::Black;
            dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
            this->classGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle4;
            this->classGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->classGridView->BackgroundColor = System::Drawing::Color::Black;
            dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
            dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
            dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->classGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
            this->classGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle6->BackColor = System::Drawing::Color::Black;
            dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            dataGridViewCellStyle6->ForeColor = System::Drawing::Color::White;
            dataGridViewCellStyle6->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
            dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
            dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::White;
            dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->classGridView->DefaultCellStyle = dataGridViewCellStyle6;
            this->classGridView->EnableHeadersVisualStyles = false;
            this->classGridView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->classGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
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
            this->searchUser->BackColor = System::Drawing::Color::Black;
            this->searchUser->Controls->Add(this->searchUserButton);
            this->searchUser->Controls->Add(this->userInfoPanel);
            this->searchUser->Controls->Add(this->userIDTextBox);
            this->searchUser->Controls->Add(this->userIDLabel);
            this->searchUser->Dock = System::Windows::Forms::DockStyle::Fill;
            this->searchUser->Location = System::Drawing::Point(0, 0);
            this->searchUser->Margin = System::Windows::Forms::Padding(5);
            this->searchUser->Name = L"searchUser";
            this->searchUser->Size = System::Drawing::Size(976, 738);
            this->searchUser->TabIndex = 2;
            this->searchUser->Leave += gcnew System::EventHandler(this, &staffPage::searchUser_Leave);
            // 
            // searchUserButton
            // 
            this->searchUserButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->searchUserButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
            this->searchUserButton->ForeColor = System::Drawing::Color::Black;
            this->searchUserButton->Location = System::Drawing::Point(667, 23);
            this->searchUserButton->Margin = System::Windows::Forms::Padding(5);
            this->searchUserButton->Name = L"searchUserButton";
            this->searchUserButton->Size = System::Drawing::Size(146, 47);
            this->searchUserButton->TabIndex = 11;
            this->searchUserButton->Text = L" Search";
            this->searchUserButton->UseVisualStyleBackColor = false;
            this->searchUserButton->Click += gcnew System::EventHandler(this, &staffPage::searchUserButton_Click);
            this->searchUserButton->MouseEnter += gcnew System::EventHandler(this, &staffPage::button_MouseEnter);
            this->searchUserButton->MouseLeave += gcnew System::EventHandler(this, &staffPage::button_MouseLeave);
            // 
            // userInfoPanel
            // 
            this->userInfoPanel->AutoScroll = true;
            this->userInfoPanel->BackColor = System::Drawing::Color::Black;
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
            this->userIDTextBox->BackColor = System::Drawing::Color::Black;
            this->userIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
            this->userIDTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->userIDTextBox->Location = System::Drawing::Point(267, 25);
            this->userIDTextBox->Margin = System::Windows::Forms::Padding(4, 2, 4, 2);
            this->userIDTextBox->Name = L"userIDTextBox";
            this->userIDTextBox->Size = System::Drawing::Size(265, 34);
            this->userIDTextBox->TabIndex = 10;
            // 
            // userIDLabel
            // 
            this->userIDLabel->AutoSize = true;
            this->userIDLabel->BackColor = System::Drawing::Color::Black;
            this->userIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->userIDLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
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
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(1273, 738);
            this->Controls->Add(this->MainPage);
            this->Controls->Add(this->MainMenu_pn);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"staffPage";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Staff Page";
            this->Load += gcnew System::EventHandler(this, &staffPage::staffPage_Load);
            this->MainMenu_pn->ResumeLayout(false);
            this->profile_pn->ResumeLayout(false);
            this->profile_pn->PerformLayout();
            this->panel1->ResumeLayout(false);
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

            if (String::IsNullOrEmpty(gcnew String(loginID.c_str()))) {
                MessageBox::Show("Error: loginID is empty.", "Initialization Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                AccName->Text = L"Unknown";
                return;
            }

            if (staffList.find(loginID) != staffList.end()) {
                AccName->Text = gcnew String(staffList[loginID].name.c_str());
                if (_stricmp(staffList[loginID].role.c_str(), "reception") == 0) {
                    button1->Visible = true;
                    SendNotification->Visible = true;
                    AddNewUser->Visible = true;
                }
                else if (_stricmp(staffList[loginID].role.c_str(), "coach") == 0) {
                    button1->Visible = false;
                    SendNotification->Visible = false;
                    AddNewUser->Visible = false;
                }
                else {
                    button1->Visible = false;
                    SendNotification->Visible = false;
                    AddNewUser->Visible = false;
                }
            }
            else {
                MessageBox::Show("Staff member not found for loginID: " + gcnew String(loginID.c_str()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                AccName->Text = L"Unknown";
                button1->Visible = false;
                SendNotification->Visible = false;
                AddNewUser->Visible = false;
            }

            loadpic(AccPic);
            if (AccPic->Image != nullptr) {
                MakePictureCircular(AccPic);
            }
            else {
                MessageBox::Show("No image loaded for AccPic.", "Image Load Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
            MainPage->Controls->Clear();
            MainPage->Controls->Add(ListOFUserEX);
        }


        System::Void AccPic_Click(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void SendNotification_Click(System::Object^ sender, System::EventArgs^ e) {
            MainPage->Controls->Clear();
            MainPage->Controls->Add(ListOFUserEX);
            ListOFUserEX->Controls->Clear();
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

        System::Void LogOutbutton_Click(System::Object^ sender, System::EventArgs^ e) {
            LoadingPage^ loadingPage = gcnew LoadingPage();
            loadingPage->label1->Text = "Logging out...";
            this->Hide();
            loadingPage->ShowDialog();
            loginID = "";
            this->Close();
        }

        // Hover event handlers for buttons
        System::Void button_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
            Button^ btn = dynamic_cast<Button^>(sender);
            btn->BackColor = Color::Black;
            btn->ForeColor = Color::FromArgb(255, 234, 0);
        }

        System::Void button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
            Button^ btn = dynamic_cast<Button^>(sender);
            btn->BackColor = Color::FromArgb(255, 234, 0);
            btn->ForeColor = Color::Black;
        }
    };
}