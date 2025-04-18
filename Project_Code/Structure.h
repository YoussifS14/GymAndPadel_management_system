#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>

#include <msclr/marshal_cppstd.h>

using namespace std;

int loginIndex = -1; // -1 means not logged in

struct CreditCard {
	 string cardID;
	 string cardCVV;
	 string cardName;
	 string ExpirationDate; // YY/MM
	 float balance;

	 static bool validateCard(const CreditCard& CheckCard) {
		  extern vector<CreditCard> cardList;

		  for (CreditCard& card : cardList) {
			   if (card.cardID == CheckCard.cardID && card.cardCVV == CheckCard.cardCVV && card.cardName == CheckCard.cardName && card.ExpirationDate == CheckCard.ExpirationDate && card.balance > CheckCard.balance) {
					card.balance -= CheckCard.balance;

					return true; // Placeholder for actual validation
			   }
		  }
		  return false; // Card not found or invalid
	 }
};

class Staff {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string phone;
	 string role; // Staff, Manager, Admin
	 string PicPath;
	 Staff() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  phone = "";
		  role = "";
	 }
	 static bool login(string email, string password) {
		  extern vector<Staff> staffList;
		  for (int i = 0; i < staffList.size(); i++) {
			   if (staffList[i].email == email && staffList[i].password == password) {
					loginIndex = i;
					return true;
			   }
		  }
		  return false;
	 }

};
struct Slot {
	 string ID;
	 string courtName;
	 string date; // MM/DD/YYYY
	 string startTime;
	 // string endTime; 
	 static int slotCounter; // Counter to generate unique slot IDs
	 static string generateSlotID() {
		  return "slot-" + to_string(slotCounter++);
	 }

};
int Slot::slotCounter = 1;

class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Brithday;
	 string subscription; // 1 month, 3 month, 6 month, 1 year
	 float myWallet; // cash back from cancelling
	 vector<Slot> myReservations; // List of reserved slots


	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Brithday = "";
		  subscription = "";
	 }
	 static bool login(string email, string password) {
		  extern vector<User> userList;
		  for (int i = 0; i < userList.size(); i++) {
			   if (userList[i].email == email && userList[i].password == password) {
					loginIndex = i;
					return true;
			   }
		  }
		  return false;
	 }

	 static string getCurrentDate_MM_DD_YYYY() {
		  time_t now = time(0);
		  tm* localTime = localtime(&now);

		  ostringstream dateStream;
		  dateStream << setfill('0') << setw(2) << (localTime->tm_mon + 1) << "/"
			   << setfill('0') << setw(2) << localTime->tm_mday << "/"
			   << (localTime->tm_year + 1900);

		  return dateStream.str();
	 }
	 static int getHourDifferenceFromNow(const string& inputTime) {
		  // Parse input time (HH:MM)
		  int inputHour, inputMinute;
		  char colon;
		  std::istringstream iss(inputTime);
		  iss >> inputHour >> colon >> inputMinute;

		  if (iss.fail() || colon != ':' || inputHour < 0 || inputHour > 23 || inputMinute < 0 || inputMinute > 59) {
			   throw std::invalid_argument("Invalid time format");
		  }

		  // Get current time
		  time_t now = time(0);
		  tm* localTime = localtime(&now);
		  int currentHour = localTime->tm_hour;
		  int currentMinute = localTime->tm_min;

		  // Convert both times to total minutes
		  int inputTotalMinutes = inputHour * 60 + inputMinute;
		  int currentTotalMinutes = currentHour * 60 + currentMinute;

		  // Calculate the absolute difference in minutes
		  int diffMinutes = std::abs(currentTotalMinutes - inputTotalMinutes);

		  // Convert to full hours
		  int hourDiff = diffMinutes / 60;

		  return hourDiff;
	 }
	 static time_t getTime_t(const string date) {
		  tm tm = { 0 };
		  sscanf(date.c_str(), "%d/%d/%d", &tm.tm_mon, &tm.tm_mday, &tm.tm_year);
		  tm.tm_year -= 1900; // Year since 1900
		  tm.tm_mon -= 1; // Months are 0-11
		  return mktime(&tm);
	 }
	 static string getFormat(time_t t) {
		  tm* tm = localtime(&t);
		  char buffer[11];
		  strftime(buffer, sizeof(buffer), "%m/%d/%Y", tm);
		  return string(buffer);
	 }


	 int searchSlot(const string& ID) {
		  for (int i = 0; i < myReservations.size(); i++) {
			   if (myReservations[i].ID == ID) {
					return i;
			   }
		  }
		  return -1; // Not found
	 }


};

class GymClasses {
public:
	 string classID;
	 string className;
	 string instructor;
	 string startDate;
	 string endDate;
	 float price;
	 int maxMembers; // Maximum number of members allowed in the class
	 vector<User> members; // List of users enrolled in the class	
	 deque<User> waitingList;

	 bool isFull() {
		  return members.size() == maxMembers;
	 }
	 static int FindIndex(const string& classID) {
		  extern vector<GymClasses> gymClassList;
		  for (int i = 0; i < gymClassList.size(); i++) {
			   if (gymClassList[i].classID == classID) {
					return i;
			   }
		  }
		  return -1; // Not found
	 }

};

struct PadelCourt {
	 string ID;//foramt "court-1"
	 string name;
	 string location;
	 float price; // Price per hour
	 vector<Slot> slots; // List of reserved slots

	 static int searchCourt(const string& courtName) {
		  extern vector<PadelCourt> courtList;

		  for (int i = 0; i < courtList.size(); i++) {
			   if (courtList[i].name == courtName) {
					return i;
			   }
		  }
		  return -1; // Not found
	 }


};


vector<Staff> staffList;
vector<User> userList;
vector<CreditCard> cardList;
vector<PadelCourt> courtList;
vector<GymClasses> gymClassList;

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
		  staffList.push_back(staff);
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
		  userList.push_back(user);
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
		  courtList.push_back(court);
	 }
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
		  load waiting list and members

		  */
		  gymClassList.push_back(gymClass);
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