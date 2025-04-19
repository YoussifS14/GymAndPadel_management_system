#include "LoginPage.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{	 
	 readStaffData();
	 readUserData();
	 readCreditCardData();
	 readPadelCourt();
	 readGymClasses();
	 // writeCreditCardData();
	 	 
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 ProjectCode::LoginPage form;
	 Application::Run(% form);
	 return 0;
}
