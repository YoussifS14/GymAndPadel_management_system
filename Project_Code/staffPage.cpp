#include "staffPage.h"
#include "Structure.h"
#include <String>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
// Helper function to convert String^ to std::string
std::string toStdString(System::String^ str) {
    return msclr::interop::marshal_as<std::string>(str);
}


// Search button
System::Void Project13::MyForm::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string id = toStdString(txtMemberID->Text);

    auto it = userList.find(id);
    if (it != userList.end()) {
        User user = it->second;
        MessageBox::Show("Name: " + gcnew String(user.name.c_str()) + "\nEmail: " + gcnew String(user.email.c_str()));
    }
    else {
        MessageBox::Show("User not found.");
    }
}

// Renew Subscription button
System::Void Project13::MyForm::btnRenew_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string id = toStdString(txtMemberID->Text);

    auto it = userList.find(id);
    if (it != userList.end()) {
        newSubChoice(it->second); // direct call
        MessageBox::Show("Subscription Renewed Successfully.");
    }
    else {
        MessageBox::Show("User not found.");
    }
}

// Delete User button
System::Void Project13::MyForm::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string id = toStdString(txtMemberID->Text);

    auto it = userList.find(id);
    if (it != userList.end()) {
        newSubChoice(it->second); // direct call
        deleteUser_and_cancelsubscription(id);
        MessageBox::Show("User deleted successfully");
    }
    else {
        MessageBox::Show("User not found.");
    }
}
[STAThread]
void main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Project13::MyForm());

}
