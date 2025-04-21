#include "LoginPage.h"


using namespace System;
using namespace System::Windows::Forms;

string loginIndex;
vector<CreditCard> cardList;

unordered_map<string, User> userList;
unordered_map<string, Staff> staffList;
unordered_map<string, GymClasses> gymClassList; // gymClass ID (key), gymClass(value)
unordered_map<string, PadelCourt> courtList;//vector<Subscriptions> availableSubscriptions;


void readStaffData() {
	 ifstream file("Data/staffData.csv");
	 string line;
	 getline(file, line); // Skip the header line
	 while (getline(file, line)) {
		  Staff staff;
		  stringstream ss(line);
		  getline(ss, staff.ID, ',');
		  getline(ss, staff.name, ',');
		  getline(ss, staff.email, ',');
		  getline(ss, staff.password, ',');
		  getline(ss, staff.phone, ',');
		  getline(ss, staff.role);
		  /*
		  loop to load myClass

		  */

		  staffList[staff.ID] = staff;

	 }
	 file.close();
}

void readUserData() {
	 ifstream file("Data/usrData.csv");
	 string line;
	 getline(file, line); // Skip the header line
	 while (getline(file, line)) {
		  User user;
		  stringstream ss(line);
		  getline(ss, user.ID, ',');
		  getline(ss, user.name, ',');
		  getline(ss, user.email, ',');
		  getline(ss, user.password, ',');
		  getline(ss, user.Brithday, ',');
		  getline(ss, user.subscription);
		  // getline(ss, user.myWallet);
		  // getline(ss, user.isVip);
		  /*
		  loop to load myReservations
		  save the slot in padelCourt
		  Slot::slotCounter++;
		  */
		  userList[user.ID] = user; // Use ID as key
		  // userList.push_back(user);
	 }
	 file.close();
}

void readCreditCardData() {
	 ifstream file("Data/DBofCredit.csv");
	 string line;
	 getline(file, line); // Skip the header line
	 while (getline(file, line)) {
		  CreditCard card;
		  string temp;
		  stringstream ss(line);
		  getline(ss, card.cardID, ',');
		  getline(ss, card.cardName, ',');
		  getline(ss, card.ExpirationDate, ',');
		  getline(ss, card.cardCVV, ',');
		  getline(ss, temp);
		  card.balance = stof(temp);
		  // Remove the 'a' character from cardID
		  card.cardID.resize(card.cardID.size() - 1);
		  card.cardCVV.resize(card.cardCVV.size() - 1);
		  cardList.push_back(card);

		  // Add the card to a vector or process it as needed
	 }
	 file.close();
}

void readPadelCourt() {
	 ifstream  padelFile("Data/padelData.txt");
	 string line;
	 while (getline(padelFile, line)) {
		  PadelCourt court;
		  stringstream ss(line);
		  getline(ss, court.ID, ',');
		  getline(ss, court.name, ',');
		  getline(ss, court.location, ',');
		  ss >> court.price;
		  // Read slots
		  string slotLine;
		  while (getline(padelFile, slotLine) && !slotLine.empty()) {
			   Slot s;

			   stringstream ss(slotLine);
			   getline(ss, s.ID, ',');
			   getline(ss, s.date, ',');
			   getline(ss, s.startTime, ',');
			   //   getline(ss, s.endTime);
			   Slot::slotCounter++;

			   court.slots.push_back(s);
		  }
		  courtList[court.ID] = court; // Use ID as key
	 }
	 padelFile.close();
}

void readGymClasses() {
	 ifstream file("Data/gymClasses.csv");
	 string line;
	 getline(file, line); // Skip the header line is Class ID, Class Name, Instructor, Start Date, End Date, Max Members
	 while (getline(file, line)) {
		  GymClasses gymClass;
		  stringstream ss(line);
		  getline(ss, gymClass.classID, ',');
		  getline(ss, gymClass.className, ',');
		  getline(ss, gymClass.instructor, ',');
		  getline(ss, gymClass.startDate, ',');
		  getline(ss, gymClass.endDate, ',');
		  ss >> gymClass.maxMembers;
		  /*
		  * load price
		  * load waiting list and members

		  */
		  gymClassList[gymClass.classID] = gymClass; // Use classID as key
	 }
	 file.close();
}

void writeCreditCardData() {
	 ofstream file("Data/DBofCredit.csv");
	 file << "CardID,CardName,ExpirationDate,CardCVV,Balance\n"; // Write header
	 for (const CreditCard& card : cardList) {
		  file << card.cardID << "a," << card.cardName << "," << card.ExpirationDate << "," << card.cardCVV << "a," << card.balance << "\n";
	 }
	 file.close();
}

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
