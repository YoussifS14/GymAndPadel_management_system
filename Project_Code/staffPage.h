#pragma once
#include "Structure.h"
#include "userExpired.h"
#include "sighup.h" 

// Note: Inspect Structure.h, userExpired.h, and sighup.h to ensure they do not include
// native C++ headers like <exception>, <string>, or <vector> without proper guards.
// If they use native types, wrap them in #pragma unmanaged/#pragma managed or move to a native file.

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
            // Initially hide the searchCoach panel
            searchCoach->Visible = false;
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
        System::ComponentModel::Container^ components;

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
            System::ComponentModel::ComponentResourceManager^ resources =
                (gcnew System::ComponentModel::ComponentResourceManager(staffPage::typeid));
            this->MainMenu_pn = (gcnew System::Windows::Forms::Panel());
            this->displayclasses = (gcnew System::Windows::Forms::Button());
            this->AddNewUser = (gcnew System::Windows::Forms::Button());
            this->SendNotification = (gcnew System::Windows::Forms::Button());
            this->profile_pn = (gcnew System::Windows::Forms::Panel());
            this->AccName = (gcnew System::Windows::Forms::Label());
            this->AccPic = (gcnew System::Windows::Forms::PictureBox());
            this->MainPage = (gcnew System::Windows::Forms::Panel());
            this->searchCoach = (gcnew System::Windows::Forms::Panel());
            this->coachInfoLabel = (gcnew System::Windows::Forms::Label());
            this->coachIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->searchCoachButton = (gcnew System::Windows::Forms::Button());
            this->classGridView = (gcnew System::Windows::Forms::DataGridView());
            this->ListOFUserEX = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->MainMenu_pn->SuspendLayout();
            this->profile_pn->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccPic))->BeginInit();
            this->MainPage->SuspendLayout();
            this->searchCoach->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classGridView))->BeginInit();
            this->SuspendLayout();

            // MainMenu_pn
            this->MainMenu_pn->Controls->Add(this->displayclasses);
            this->MainMenu_pn->Controls->Add(this->AddNewUser);
            this->MainMenu_pn->Controls->Add(this->SendNotification);
            this->MainMenu_pn->Controls->Add(this->profile_pn);
            this->MainMenu_pn->Dock = System::Windows::Forms::DockStyle::Left;
            this->MainMenu_pn->Location = System::Drawing::Point(0, 0);
            this->MainMenu_pn->Name = L"MainMenu_pn";
            this->MainMenu_pn->Size = System::Drawing::Size(313, 739);
            this->MainMenu_pn->TabIndex = 1;

            // displayclasses
            this->displayclasses->Dock = System::Windows::Forms::DockStyle::Top;
            this->displayclasses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
            this->displayclasses->Location = System::Drawing::Point(0, 356);
            this->displayclasses->Name = L"displayclasses";
            this->displayclasses->Size = System::Drawing::Size(313, 73);
            this->displayclasses->TabIndex = 4;
            this->displayclasses->Text = L"Display Classes";
            this->displayclasses->UseVisualStyleBackColor = true;
            this->displayclasses->Click += gcnew System::EventHandler(this, &staffPage::displayclasses_Click);

            // AddNewUser
            this->AddNewUser->Dock = System::Windows::Forms::DockStyle::Top;
            this->AddNewUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
            this->AddNewUser->Location = System::Drawing::Point(0, 280);
            this->AddNewUser->Name = L"AddNewUser";
            this->AddNewUser->Size = System::Drawing::Size(313, 76);
            this->AddNewUser->TabIndex = 3;
            this->AddNewUser->Text = L"Register new user";
            this->AddNewUser->UseVisualStyleBackColor = true;
            this->AddNewUser->Click += gcnew System::EventHandler(this, &staffPage::AddNewUser_Click);

            // SendNotification
            this->SendNotification->Dock = System::Windows::Forms::DockStyle::Top;
            this->SendNotification->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
            this->SendNotification->Location = System::Drawing::Point(0, 212);
            this->SendNotification->Name = L"SendNotification";
            this->SendNotification->Size = System::Drawing::Size(313, 68);
            this->SendNotification->TabIndex = 2;
            this->SendNotification->Text = L"Send Notification";
            this->SendNotification->UseVisualStyleBackColor = true;
            this->SendNotification->Click += gcnew System::EventHandler(this, &staffPage::SendNotification_Click);

            // profile_pn
            this->profile_pn->Controls->Add(this->AccName);
            this->profile_pn->Controls->Add(this->AccPic);
            this->profile_pn->Dock = System::Windows::Forms::DockStyle::Top;
            this->profile_pn->Location = System::Drawing::Point(0, 0);
            this->profile_pn->Name = L"profile_pn";
            this->profile_pn->Size = System::Drawing::Size(313, 212);
            this->profile_pn->TabIndex = 1;

            // AccName
            this->AccName->AutoSize = true;
            this->AccName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular));
            this->AccName->Location = System::Drawing::Point(3, 175);
            this->AccName->Name = L"AccName";
            this->AccName->Size = System::Drawing::Size(58, 22);
            this->AccName->TabIndex = 1;
            this->AccName->Text = L"label1";

            // AccPic
            this->AccPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AccPic.Image")));
            this->AccPic->Location = System::Drawing::Point(38, 12);
            this->AccPic->Name = L"AccPic";
            this->AccPic->Size = System::Drawing::Size(213, 147);
            this->AccPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->AccPic->TabIndex = 0;
            this->AccPic->TabStop = false;
            this->AccPic->Click += gcnew System::EventHandler(this, &staffPage::AccPic_Click);

            // MainPage
            this->MainPage->Controls->Add(this->searchCoach);
            this->MainPage->Controls->Add(this->ListOFUserEX);
            this->MainPage->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MainPage->Location = System::Drawing::Point(313, 0);
            this->MainPage->Name = L"MainPage";
            this->MainPage->Size = System::Drawing::Size(960, 739);
            this->MainPage->TabIndex = 2;

            // searchCoach
            this->searchCoach->Controls->Add(this->coachInfoLabel);
            this->searchCoach->Controls->Add(this->coachIDTextBox);
            this->searchCoach->Controls->Add(this->searchCoachButton);
            this->searchCoach->Controls->Add(this->classGridView);
            this->searchCoach->Dock = System::Windows::Forms::DockStyle::Fill;
            this->searchCoach->Location = System::Drawing::Point(0, 0);
            this->searchCoach->Name = L"searchCoach";
            this->searchCoach->Size = System::Drawing::Size(960, 739);
            this->searchCoach->TabIndex = 1;
            this->searchCoach->Leave += gcnew System::EventHandler(this, &staffPage::searchCoach_Leave);

            // coachInfoLabel
            this->coachInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular));
            this->coachInfoLabel->Location = System::Drawing::Point(29, 120);
            this->coachInfoLabel->Margin = System::Windows::Forms::Padding(4);
            this->coachInfoLabel->Name = L"coachInfoLabel";
            this->coachInfoLabel->Size = System::Drawing::Size(301, 80);
            this->coachInfoLabel->TabIndex = 13;

            // coachIDTextBox
            this->coachIDTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular));
            this->coachIDTextBox->Location = System::Drawing::Point(360, 74);
            this->coachIDTextBox->Margin = System::Windows::Forms::Padding(4);
            this->coachIDTextBox->Name = L"coachIDTextBox";
            this->coachIDTextBox->Size = System::Drawing::Size(187, 34);
            this->coachIDTextBox->TabIndex = 3;

            // searchCoachButton
            this->searchCoachButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
            this->searchCoachButton->Location = System::Drawing::Point(359, 11);
            this->searchCoachButton->Margin = System::Windows::Forms::Padding(4);
            this->searchCoachButton->Name = L"searchCoachButton";
            this->searchCoachButton->Size = System::Drawing::Size(188, 55);
            this->searchCoachButton->TabIndex = 4;
            this->searchCoachButton->Text = L"Enter Coach ID";
            this->searchCoachButton->UseVisualStyleBackColor = true;
            this->searchCoachButton->Click += gcnew System::EventHandler(this, &staffPage::searchCoachButton_Click);

            // classGridView
            this->classGridView->AllowUserToAddRows = false;
            this->classGridView->AllowUserToDeleteRows = false;
            this->classGridView->BackgroundColor = System::Drawing::SystemColors::Control;
            this->classGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->classGridView->Location = System::Drawing::Point(29, 210);
            this->classGridView->Margin = System::Windows::Forms::Padding(4);
            this->classGridView->Name = L"classGridView";
            this->classGridView->ReadOnly = true;
            this->classGridView->RowHeadersVisible = false;
            this->classGridView->RowHeadersWidth = 51;
            this->classGridView->RowTemplate->Height = 40;
            this->classGridView->Size = System::Drawing::Size(900, 500);
            this->classGridView->TabIndex = 12;
            this->classGridView->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular);
            this->classGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->classGridView->AllowUserToOrderColumns = false;
            this->classGridView->ColumnHeadersHeight = 40;
            this->classGridView->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Navy;
            this->classGridView->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
            this->classGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold);
            this->classGridView->DefaultCellStyle->BackColor = System::Drawing::Color::White;
            this->classGridView->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
            this->classGridView->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::AliceBlue;
            this->classGridView->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightBlue;
            this->classGridView->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
            this->classGridView->GridColor = System::Drawing::Color::LightGray;
            this->classGridView->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
            this->classGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Single;
            this->classGridView->EnableHeadersVisualStyles = false;

            // ListOFUserEX
            this->ListOFUserEX->AutoScroll = true;
            this->ListOFUserEX->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ListOFUserEX->Location = System::Drawing::Point(0, 0);
            this->ListOFUserEX->Name = L"ListOFUserEX";
            this->ListOFUserEX->Size = System::Drawing::Size(960, 739);
            this->ListOFUserEX->TabIndex = 0;

            // staffPage
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1273, 739);
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
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void staffPage_Load(System::Object^ sender, System::EventArgs^ e) {
            this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
            if (staffList.find(loginID) != staffList.end()) {
                AccName->Text = gcnew String(staffList[loginID].name.c_str());
            }
            else {
                MessageBox::Show("Staff member not found for loginID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                AccName->Text = L"Unknown";
            }
            loadpic(AccPic);
            MakePictureCircular(AccPic);
            MainPage->Controls->Clear();
            MainPage->Controls->Add(ListOFUserEX);
            ListOFUserEX->BringToFront();
            searchCoach->Visible = false;
        }

        System::Void AccPic_Click(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void SendNotification_Click(System::Object^ sender, System::EventArgs^ e) {
            MainPage->Controls->Clear();
            MainPage->Controls->Add(ListOFUserEX);
            ListOFUserEX->Controls->Clear();
            ListOFUserEX->BringToFront();
            searchCoach->Visible = false;
            isDisplayClassesActive = false;
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
                }
            }
        }

        System::Void AddNewUser_Click(System::Object^ sender, System::EventArgs^ e) {
            sighup^ newPage = gcnew sighup();
            newPage->groupBox1->Visible = false;
            newPage->ShowDialog();
            searchCoach->Visible = false;
            isDisplayClassesActive = false;
        }

        System::Void displayclasses_Click(System::Object^ sender, System::EventArgs^ e) {
            extern unordered_map<std::string, Staff> staffList;
            if (staffList.find(loginID) == staffList.end()) {
                MessageBox::Show("Staff member not found for loginID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            MainPage->Controls->Clear();
            if (_stricmp(staffList[loginID].role.c_str(), "coach") == 0) {
                DataGridView^ tempGridView = gcnew DataGridView();
                tempGridView->AllowUserToAddRows = false;
                tempGridView->AllowUserToDeleteRows = false;
                tempGridView->BackgroundColor = System::Drawing::SystemColors::Control;
                tempGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
                tempGridView->Location = System::Drawing::Point(19, 210);
                tempGridView->Margin = System::Windows::Forms::Padding(4);
                tempGridView->Name = L"tempGridView";
                tempGridView->ReadOnly = true;
                tempGridView->RowHeadersVisible = false;
                tempGridView->RowHeadersWidth = 51;
                tempGridView->RowTemplate->Height = 40;
                tempGridView->Size = System::Drawing::Size(900, 500);
                tempGridView->TabIndex = 12;
                tempGridView->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular);
                tempGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
                tempGridView->AllowUserToOrderColumns = false;
                tempGridView->ColumnHeadersHeight = 40;
                tempGridView->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Navy;
                tempGridView->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
                tempGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold);
                tempGridView->DefaultCellStyle->BackColor = System::Drawing::Color::White;
                tempGridView->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
                tempGridView->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::AliceBlue;
                tempGridView->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightBlue;
                tempGridView->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
                tempGridView->GridColor = System::Drawing::Color::LightGray;
                tempGridView->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
                tempGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Single;
                tempGridView->EnableHeadersVisualStyles = false;

                Label^ tempInfoLabel = gcnew Label();
                tempInfoLabel->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular);
                tempInfoLabel->Location = System::Drawing::Point(29, 120);
                tempInfoLabel->Margin = System::Windows::Forms::Padding(4);
                tempInfoLabel->Name = L"tempInfoLabel";
                tempInfoLabel->Size = System::Drawing::Size(301, 80);
                tempInfoLabel->TabIndex = 13;

                MainPage->Controls->Add(tempGridView);
                MainPage->Controls->Add(tempInfoLabel);
                tempGridView->BringToFront();
                tempInfoLabel->BringToFront();
                searchCoach->Visible = false;
                isDisplayClassesActive = false;

                displayCoachClasses(gcnew String(loginID.c_str()), tempGridView, tempInfoLabel);
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