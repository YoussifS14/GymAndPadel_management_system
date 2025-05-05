#pragma once
#include "Structure.h"
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

            // Display user information in the RichTextBox
            richTextBox1->Text =
                "Welcome: " + gcnew String(userList[loginID].name.c_str()) + "\n" +
                "Your email is: " + gcnew String(userList[loginID].email.c_str()) + "\n" +
                "Your password is: " + gcnew String(userList[loginID].password.c_str()) + "\n" +
                "Your ID is: " + gcnew String(userList[loginID].ID.c_str()) + "\n" +
                "Your birthday is: " + gcnew String(userList[loginID].Birthday.c_str()) + "\n\n";
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

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Label^ subscriptionDetailsLabel;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(23, 26);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(36, 24);
            this->label1->TabIndex = 0;
            this->label1->Text = L"HI ";
            this->label1->Visible = false;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(584, 26);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(227, 24);
            this->label2->TabIndex = 2;
            this->label2->Text = L"YOUR SUBSCRIPTION:";
            this->label2->Visible = false;
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(417, 333);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(202, 89);
            this->button2->TabIndex = 4;
            this->button2->Text = L"Back to main page";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &useraccount::button2_Click);
            // 
            // subscriptionDetailsLabel
            // 
            this->subscriptionDetailsLabel->AutoSize = true;
            this->subscriptionDetailsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->subscriptionDetailsLabel->Location = System::Drawing::Point(584, 100);
            this->subscriptionDetailsLabel->Name = L"subscriptionDetailsLabel";
            this->subscriptionDetailsLabel->Size = System::Drawing::Size(0, 17);
            this->subscriptionDetailsLabel->TabIndex = 5;
            this->subscriptionDetailsLabel->Visible = false;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(24, 71);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(57, 20);
            this->label3->TabIndex = 6;
            this->label3->Text = L"label3";
            this->label3->Visible = false;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(23, 104);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(57, 20);
            this->label4->TabIndex = 7;
            this->label4->Text = L"label4";
            this->label4->Visible = false;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(24, 141);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(57, 20);
            this->label5->TabIndex = 8;
            this->label5->Text = L"label5";
            this->label5->Visible = false;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(23, 187);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(57, 20);
            this->label6->TabIndex = 9;
            this->label6->Text = L"label6";
            this->label6->Visible = false;
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(738, 333);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(202, 89);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Update subscription";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &useraccount::button1_Click);
            // 
            // richTextBox1
            // 
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(12, 26);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->ReadOnly = true;
            this->richTextBox1->Size = System::Drawing::Size(1004, 288);
            this->richTextBox1->TabIndex = 11;
            this->richTextBox1->Text = L"";
            // 
            // useraccount
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1028, 495);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->subscriptionDetailsLabel);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
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
                    richTextBox1->Text += "Error: User not found.\n";
                    return;
                }

                User& user = userList[loginID];

                if (!user.subscription.isActive() && user.subscription.IsExpired()) {
                    richTextBox1->Text +=
                        "Your subscription has expired. Please renew to continue using our services.\n";
                    button1->Visible = true;
                    return;
                }

                std::string endDateStr = user.subscription.calculateEndDate();
                if (endDateStr.empty()) {
                    richTextBox1->Text += "Failed to retrieve subscription end date.\n";
                    return;
                }

                time_t endDate = getTime_t(endDateStr);
                int daysLeft = static_cast<int>(ceil(difftime(endDate, now) / (60.0 * 60 * 24)));

                String^ details =
                    "Subscription Details:\n" +
                    "Type: " + gcnew String(user.subscription.getType().c_str()) + "\n" +
                    "Start: " + gcnew String(user.subscription.getStartDate().c_str()) + "\n" +
                    "End: " + gcnew String(endDateStr.c_str()) + "\n" +
                    "Price: " + user.subscription.getPrice().ToString() + "\n";

                if (user.subscription.isActive() && daysLeft > 0 && daysLeft <= warningDays) {
                    details += "\nYour subscription will expire in " + daysLeft.ToString() + " day(s).\n";
                }

                richTextBox1->Text += details + "\n";
            }
            catch (const std::exception& e) {
                richTextBox1->Text += "Error processing subscription: " + gcnew String(e.what()) + "\n";
            }
        }

        void displayEnrolledClasses() {
            try {
                if (userList.find(loginID) == userList.end()) {
                    richTextBox1->Text += "Error: User not found.\n";
                    return;
                }

                User& user = userList[loginID];
                System::Text::StringBuilder^ report = gcnew System::Text::StringBuilder();
                report->AppendLine("Enrolled Classes:");
                report->AppendLine("-----------------------------");

                bool hasClasses = false;
                // Assuming User has a field myClasses (std::vector<std::string>)
                for (const auto& classID : user.myClasses) {
                    if (gymClassList.find(classID) != gymClassList.end()) {
                        hasClasses = true;
                        const GymClasses& gymClass = gymClassList[classID];
                        report->AppendLine("Class ID   : " + gcnew String(gymClass.classID.c_str()));
                        report->AppendLine("Class Name : " + gcnew String(gymClass.className.c_str()));
                        report->AppendLine("Sessions:");
                        for (const auto& session : gymClass.sessions) {
                            report->AppendLine("  Date: " + gcnew String(session.date.c_str()) +
                                " | Time: " + gcnew String(session.startTime.c_str()) +
                                " - " + gcnew String(session.endTime.c_str()));
                        }
                        report->AppendLine("-----------------------------");
                    }
                }

                if (!hasClasses) {
                    report->AppendLine("No classes enrolled.");
                }

                richTextBox1->Text += report->ToString();
            }
            catch (const std::exception& e) {
                richTextBox1->Text += "Error processing enrolled classes: " + gcnew String(e.what()) + "\n";
            }
        }

        void displayAllowedClasses() {
            try {
                if (userList.find(loginID) == userList.end()) {
                    richTextBox1->Text += "Error: User not found.\n";
                    return;
                }

                User& user = userList[loginID];
                string userSubType = user.subscription.getType();

                GymClasses temp;
                string classList = temp.displayClassesForUserSubscription(userSubType);

                richTextBox1->Text += "\n" + gcnew String(classList.c_str());
            }
            catch (const std::exception& e) {
                richTextBox1->Text += "Error retrieving available classes: " + gcnew String(e.what()) + "\n";
            }
        }

    private: System::Void useraccount_Load(System::Object^ sender, System::EventArgs^ e) {
        notifyExpiringSubscriptions();

        if (userList.find(loginID) != userList.end()) {
            User& user = userList[loginID];
            if (user.subscription.isActive() && !user.subscription.IsExpired()) {
                GymClasses temp;
                string classList = temp.displayClassesForUserSubscription(user.subscription.getType());
                richTextBox1->Text += "\n" + gcnew String(classList.c_str());
                // Only display enrolled classes if there are available classes
                if (classList.find("No classes available") == string::npos) {
                    displayEnrolledClasses();
                }
            }
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Implement subscription update logic if needed
    }

#pragma endregion
    };
}