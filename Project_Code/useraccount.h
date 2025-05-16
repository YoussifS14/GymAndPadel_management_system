#pragma once
#include "Structure.h"
namespace ProjectCode {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class useraccount : public System::Windows::Forms::Form
    {
    public:
        useraccount(void)
        {
            InitializeComponent();
        }

    protected:
        ~useraccount()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ nameLabel;
        System::Windows::Forms::Label^ emailLabel;
        System::Windows::Forms::Label^ passwordLabel;
        System::Windows::Forms::Label^ idLabel;
        System::Windows::Forms::Label^ birthdayLabel;
        System::Windows::Forms::Label^ nameValueLabel;
        System::Windows::Forms::Label^ emailValueLabel;
        System::Windows::Forms::Label^ passwordValueLabel;
        System::Windows::Forms::Label^ idValueLabel;
        System::Windows::Forms::Label^ birthdayValueLabel;
        System::Windows::Forms::Label^ subscriptionDetailsLabel;
        System::Windows::Forms::Label^ subscriptionHeaderLabel;
        System::Windows::Forms::Label^ classesHeaderLabel;
        System::Windows::Forms::Button^ backButton;
      
        System::Windows::Forms::DataGridView^ classesGridView;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->nameLabel = (gcnew System::Windows::Forms::Label());
            this->emailLabel = (gcnew System::Windows::Forms::Label());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->idLabel = (gcnew System::Windows::Forms::Label());
            this->birthdayLabel = (gcnew System::Windows::Forms::Label());
            this->nameValueLabel = (gcnew System::Windows::Forms::Label());
            this->emailValueLabel = (gcnew System::Windows::Forms::Label());
            this->passwordValueLabel = (gcnew System::Windows::Forms::Label());
            this->idValueLabel = (gcnew System::Windows::Forms::Label());
            this->birthdayValueLabel = (gcnew System::Windows::Forms::Label());
            this->subscriptionDetailsLabel = (gcnew System::Windows::Forms::Label());
            this->subscriptionHeaderLabel = (gcnew System::Windows::Forms::Label());
            this->classesHeaderLabel = (gcnew System::Windows::Forms::Label());
            this->backButton = (gcnew System::Windows::Forms::Button());
            this->classesGridView = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classesGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // nameLabel
            // 
            this->nameLabel->AutoSize = true;
            this->nameLabel->BackColor = System::Drawing::Color::Black;
            this->nameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->nameLabel->ForeColor = System::Drawing::Color::LightGray;
            this->nameLabel->Location = System::Drawing::Point(20, 20);
            this->nameLabel->Name = L"nameLabel";
            this->nameLabel->Size = System::Drawing::Size(53, 19);
            this->nameLabel->TabIndex = 0;
            this->nameLabel->Text = L"Name:";
            // 
            // emailLabel
            // 
            this->emailLabel->AutoSize = true;
            this->emailLabel->BackColor = System::Drawing::Color::Black;
            this->emailLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->emailLabel->ForeColor = System::Drawing::Color::LightGray;
            this->emailLabel->Location = System::Drawing::Point(20, 50);
            this->emailLabel->Name = L"emailLabel";
            this->emailLabel->Size = System::Drawing::Size(49, 19);
            this->emailLabel->TabIndex = 1;
            this->emailLabel->Text = L"Email:";
            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->BackColor = System::Drawing::Color::Black;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->passwordLabel->ForeColor = System::Drawing::Color::LightGray;
            this->passwordLabel->Location = System::Drawing::Point(20, 80);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(77, 19);
            this->passwordLabel->TabIndex = 2;
            this->passwordLabel->Text = L"Password:";
            // 
            // idLabel
            // 
            this->idLabel->AutoSize = true;
            this->idLabel->BackColor = System::Drawing::Color::Black;
            this->idLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->idLabel->ForeColor = System::Drawing::Color::LightGray;
            this->idLabel->Location = System::Drawing::Point(420, 20);
            this->idLabel->Name = L"idLabel";
            this->idLabel->Size = System::Drawing::Size(27, 19);
            this->idLabel->TabIndex = 3;
            this->idLabel->Text = L"ID:";
            // 
            // birthdayLabel
            // 
            this->birthdayLabel->AutoSize = true;
            this->birthdayLabel->BackColor = System::Drawing::Color::Black;
            this->birthdayLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->birthdayLabel->ForeColor = System::Drawing::Color::LightGray;
            this->birthdayLabel->Location = System::Drawing::Point(420, 50);
            this->birthdayLabel->Name = L"birthdayLabel";
            this->birthdayLabel->Size = System::Drawing::Size(70, 19);
            this->birthdayLabel->TabIndex = 4;
            this->birthdayLabel->Text = L"Birthday:";
            // 
            // nameValueLabel
            // 
            this->nameValueLabel->AutoSize = true;
            this->nameValueLabel->BackColor = System::Drawing::Color::Black;
            this->nameValueLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->nameValueLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->nameValueLabel->Location = System::Drawing::Point(100, 20);
            this->nameValueLabel->Name = L"nameValueLabel";
            this->nameValueLabel->Size = System::Drawing::Size(0, 19);
            this->nameValueLabel->TabIndex = 5;
            // 
            // emailValueLabel
            // 
            this->emailValueLabel->AutoSize = true;
            this->emailValueLabel->BackColor = System::Drawing::Color::Black;
            this->emailValueLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->emailValueLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->emailValueLabel->Location = System::Drawing::Point(100, 50);
            this->emailValueLabel->Name = L"emailValueLabel";
            this->emailValueLabel->Size = System::Drawing::Size(0, 19);
            this->emailValueLabel->TabIndex = 6;
            // 
            // passwordValueLabel
            // 
            this->passwordValueLabel->AutoSize = true;
            this->passwordValueLabel->BackColor = System::Drawing::Color::Black;
            this->passwordValueLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->passwordValueLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->passwordValueLabel->Location = System::Drawing::Point(100, 80);
            this->passwordValueLabel->Name = L"passwordValueLabel";
            this->passwordValueLabel->Size = System::Drawing::Size(0, 19);
            this->passwordValueLabel->TabIndex = 7;
            // 
            // idValueLabel
            // 
            this->idValueLabel->AutoSize = true;
            this->idValueLabel->BackColor = System::Drawing::Color::Black;
            this->idValueLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->idValueLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->idValueLabel->Location = System::Drawing::Point(500, 20);
            this->idValueLabel->Name = L"idValueLabel";
            this->idValueLabel->Size = System::Drawing::Size(0, 19);
            this->idValueLabel->TabIndex = 8;
            // 
            // birthdayValueLabel
            // 
            this->birthdayValueLabel->AutoSize = true;
            this->birthdayValueLabel->BackColor = System::Drawing::Color::Black;
            this->birthdayValueLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->birthdayValueLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->birthdayValueLabel->Location = System::Drawing::Point(500, 50);
            this->birthdayValueLabel->Name = L"birthdayValueLabel";
            this->birthdayValueLabel->Size = System::Drawing::Size(0, 19);
            this->birthdayValueLabel->TabIndex = 9;
            // 
            // subscriptionDetailsLabel
            // 
            this->subscriptionDetailsLabel->BackColor = System::Drawing::Color::Black;
            this->subscriptionDetailsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->subscriptionDetailsLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->subscriptionDetailsLabel->Location = System::Drawing::Point(20, 150);
            this->subscriptionDetailsLabel->Name = L"subscriptionDetailsLabel";
            this->subscriptionDetailsLabel->Size = System::Drawing::Size(400, 350);
            this->subscriptionDetailsLabel->TabIndex = 11;
            // 
            // subscriptionHeaderLabel
            // 
            this->subscriptionHeaderLabel->AutoSize = true;
            this->subscriptionHeaderLabel->BackColor = System::Drawing::Color::Black;
            this->subscriptionHeaderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
            this->subscriptionHeaderLabel->ForeColor = System::Drawing::Color::LightGray;
            this->subscriptionHeaderLabel->Location = System::Drawing::Point(20, 120);
            this->subscriptionHeaderLabel->Name = L"subscriptionHeaderLabel";
            this->subscriptionHeaderLabel->Size = System::Drawing::Size(227, 24);
            this->subscriptionHeaderLabel->TabIndex = 10;
            this->subscriptionHeaderLabel->Text = L"YOUR SUBSCRIPTION:";
            // 
            // classesHeaderLabel
            // 
            this->classesHeaderLabel->AutoSize = true;
            this->classesHeaderLabel->BackColor = System::Drawing::Color::Black;
            this->classesHeaderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
            this->classesHeaderLabel->ForeColor = System::Drawing::Color::LightGray;
            this->classesHeaderLabel->Location = System::Drawing::Point(440, 120);
            this->classesHeaderLabel->Name = L"classesHeaderLabel";
            this->classesHeaderLabel->Size = System::Drawing::Size(223, 24);
            this->classesHeaderLabel->TabIndex = 12;
            this->classesHeaderLabel->Text = L"ENROLLED CLASSES:";
            // 
            // backButton
            // 
            this->backButton->BackColor = System::Drawing::Color::LightGray;
            this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
            this->backButton->ForeColor = System::Drawing::Color::Black;
            this->backButton->Location = System::Drawing::Point(24, 512);
            this->backButton->Name = L"backButton";
            this->backButton->Size = System::Drawing::Size(125, 51);
            this->backButton->TabIndex = 13;
            this->backButton->Text = L"Back to main page";
            this->backButton->UseVisualStyleBackColor = false;
            this->backButton->Click += gcnew System::EventHandler(this, &useraccount::backButton_Click);
            // 
            // classesGridView
            // 
            this->classesGridView->AllowUserToAddRows = false;
            this->classesGridView->AllowUserToDeleteRows = false;
            this->classesGridView->BackgroundColor = System::Drawing::Color::Black;
            this->classesGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->classesGridView->Location = System::Drawing::Point(440, 150);
            this->classesGridView->Name = L"classesGridView";
            this->classesGridView->ReadOnly = true;
            this->classesGridView->RowHeadersVisible = false;
            this->classesGridView->RowTemplate->Height = 40;
            this->classesGridView->Size = System::Drawing::Size(400, 350);
            this->classesGridView->TabIndex = 15;
            // 
            // useraccount
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(860, 590);
            this->ControlBox = false;
            this->Controls->Add(this->classesGridView);
            this->Controls->Add(this->backButton);
            this->Controls->Add(this->classesHeaderLabel);
            this->Controls->Add(this->subscriptionDetailsLabel);
            this->Controls->Add(this->subscriptionHeaderLabel);
            this->Controls->Add(this->birthdayValueLabel);
            this->Controls->Add(this->idValueLabel);
            this->Controls->Add(this->passwordValueLabel);
            this->Controls->Add(this->emailValueLabel);
            this->Controls->Add(this->nameValueLabel);
            this->Controls->Add(this->birthdayLabel);
            this->Controls->Add(this->idLabel);
            this->Controls->Add(this->passwordLabel);
            this->Controls->Add(this->emailLabel);
            this->Controls->Add(this->nameLabel);
            this->Cursor = System::Windows::Forms::Cursors::Default;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"useraccount";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"User Account";
            this->Load += gcnew System::EventHandler(this, &useraccount::useraccount_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classesGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void populateUserDetails() {
            if (this->DesignMode) return;
            try {
                if (userList.find(loginID) != userList.end()) {
                    User& user = userList[loginID];
                    this->nameValueLabel->Text = gcnew String(user.name.c_str());
                    this->emailValueLabel->Text = gcnew String(user.email.c_str());
                    this->passwordValueLabel->Text = L"****";
                    this->idValueLabel->Text = gcnew String(user.ID.c_str());
                    this->birthdayValueLabel->Text = gcnew String(user.Birthday.c_str());
                }
                else {
                    this->nameValueLabel->Text = L"Error: User not found";
                    this->emailValueLabel->Text = L"Error: User not found";
                    this->passwordValueLabel->Text = L"Error: User not found";
                    this->idValueLabel->Text = L"Error: User not found";
                    this->birthdayValueLabel->Text = L"Error: User not found";
                }
            }
            catch (const std::exception& e) {
                this->nameValueLabel->Text = L"Error: " + gcnew String(e.what());
            }
        }

        void populateClassesGrid() {
            try {
                classesGridView->Rows->Clear();
                classesGridView->Columns->Clear();

                classesGridView->Columns->Add("ClassID", "Class ID");
                classesGridView->Columns->Add("ClassName", "Class Name");
                classesGridView->Columns->Add("SessionDate", "Date");
                classesGridView->Columns->Add("SessionTime", "Time");

                classesGridView->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular);
                classesGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
                classesGridView->AllowUserToOrderColumns = false;
                classesGridView->ColumnHeadersHeight = 40;
                classesGridView->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(255, 234, 0);
                classesGridView->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::Black;
                classesGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold);
                classesGridView->DefaultCellStyle->BackColor = System::Drawing::Color::Black;
                classesGridView->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(255, 234, 0);
                classesGridView->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
                classesGridView->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(255, 234, 0);
                classesGridView->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
                classesGridView->GridColor = System::Drawing::Color::FromArgb(255, 234, 0);
                classesGridView->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5, 10, 5, 10);
                classesGridView->CellBorderStyle = DataGridViewCellBorderStyle::Single;
                classesGridView->EnableHeadersVisualStyles = false;

                System::Text::StringBuilder^ subDetails = gcnew System::Text::StringBuilder();
                if (userList.find(loginID) == userList.end()) {
                    subDetails->AppendLine("Error: User not found.");
                    subscriptionDetailsLabel->Text = subDetails->ToString();
                    classesGridView->Rows->Add("Error", "User not found.", "", "");
                    return;
                }

                User& user = userList[loginID];
                if (!user.subscription.isActive() && user.subscription.IsExpired()) {
                    subDetails->AppendLine("Your subscription has expired. Please renew to continue using our services.");
                    subscriptionDetailsLabel->Text = subDetails->ToString();
                    classesGridView->Rows->Add("", "No classes enrolled (subscription expired).", "", "");
                  
                    return;
                }

                std::string endDateStr = user.subscription.getEndDate();
                if (endDateStr.empty()) {
                    subDetails->AppendLine("Error: Failed to retrieve subscription end date.");
                    subscriptionDetailsLabel->Text = subDetails->ToString();
                    classesGridView->Rows->Add("Error", "Failed to retrieve subscription end date.", "", "");
                    return;
                }

                //
                time_t now = time(nullptr);
                const int warningDays = 5;
                time_t endDate = getTime_t(endDateStr);
                int daysLeft = static_cast<int>(ceil(difftime(endDate, now) / (60.0 * 60 * 24)));

                subDetails->AppendLine("VIP Status: " + (user.subscription.get_is_VIP() ? "Yes" : "No"));
                subDetails->AppendLine("Type: " + gcnew String(user.subscription.getType().c_str()));
                subDetails->AppendLine("Start Date: " + gcnew String(user.subscription.getStartDate().c_str()));
                subDetails->AppendLine("End Date: " + gcnew String(endDateStr.c_str()));
                subDetails->AppendLine("Price: " + user.subscription.getPrice().ToString());
                if (user.subscription.isActive() && daysLeft > 0 && daysLeft <= warningDays) {
                    subDetails->AppendLine("Warning: Your subscription will expire in " + daysLeft.ToString() + " day(s).");
                }
                subscriptionDetailsLabel->Text = subDetails->ToString();
                bool hasClasses = false;
                for (const auto& classID : user.myClasses) {
                    if (gymClassList.find(classID) != gymClassList.end()) {
                        hasClasses = true;
                        const GymClasses& gymClass = gymClassList[classID];
                        for (const auto& session : gymClass.sessions) {
                            classesGridView->Rows->Add(
                                gcnew String(gymClass.classID.c_str()),
                                gcnew String(gymClass.className.c_str()),
                                gcnew String(session.date.c_str()),
                                gcnew String(session.startTime.c_str()) + " - " + gcnew String(session.endTime.c_str())
                            );
                        }
                    }
                }

                if (!hasClasses) {
                    classesGridView->Rows->Add("", "No classes enrolled.", "", "");
                }
            }
            catch (const std::exception& e) {
                subscriptionDetailsLabel->Text = "Error processing data: " + gcnew String(e.what());
                classesGridView->Rows->Add("Error", "Error processing enrolled classes: " + gcnew String(e.what()), "", "");
            }
        }

    private:
        System::Void useraccount_Load(System::Object^ sender, System::EventArgs^ e) {
            populateUserDetails();
            populateClassesGrid();
            this->Icon = gcnew System::Drawing::Icon("assets/program Icon.ico");
        }

        System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        
    };
}