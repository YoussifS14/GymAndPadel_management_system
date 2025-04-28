#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <list>
#include <ctime>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>

#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace msclr::interop;
extern void writeStaffData();
static int baseID = 1000; 
extern std::string loginID;   // -1 means not logged in
// class Subscriptions // This gym subscription generally has nothing to do with classes.
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

static time_t getTime_t(const string date) {
	 tm ty{};
	 if (sscanf(date.c_str(), "%d/%d/%d", &ty.tm_mon, &ty.tm_mday, &ty.tm_year) != 3) {

		  return static_cast<time_t>(-1);
	 }

	 ty.tm_year -= 1900;
	 ty.tm_mon -= 1;

	 return mktime(&ty);
}
static string getFormat(time_t t) {
	 tm* tm = localtime(&t);
	 char buffer[11];
	 strftime(buffer, sizeof(buffer), "%m/%d/%Y", tm);
	 return string(buffer);
}


class User;
class GymClasses;

class Staff {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string phone;
	 string role; // Staff, Manager, Admin
	 string myClass = "null"; // if the staff is a coach, this will be the class(ID) they are coaching 
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
		  extern unordered_map<string, Staff> staffList;
		  auto it = staffList.begin();
		  while (it != staffList.end()) {
			   if (it->second.email == email && it->second.password == password) {
					loginID = it->second.ID;
					return true;
			   }
			   it++;
		  }
		  return false;
	 }
	 static string generateID() {
		  extern unordered_map<string, Staff> staffList;
		  string ID = "stf-";
		  ID += to_string(staffList.size() + 1);
		  return ID;
	 }
	 bool registerStaff(string Name, string Email, string Password, string Phone, string Role, string imagepath = "") {
		 extern unordered_map<string, Staff> staffList;
		 extern int baseID;

		 if (!isNameValid(Name)) return false;
		 if (!isEmailUnique(Email)) return false;
		 //if (Phone.length() < 11) return false;

		 Staff newStaff;
		 newStaff.name = Name;
		 newStaff.email = Email;
		 newStaff.password = Password;
		 newStaff.phone = Phone;
		 newStaff.role = Role;
		 newStaff.PicPath = imagepath;
		 // newStaff.PicPath = PicPath; 

		 string id;
		 if (Role == "Reception" || Role == "reception") {
			 id = "R" + to_string(++baseID);
		 }
		 else if (Role == "Coach" || Role == "coach") {
			 id = "C" + to_string(++baseID);
		 }
		 else {
			 return false;
		 }

		 newStaff.ID = id;
		 staffList[id] = newStaff;
		 writeStaffData();
		 return true;
	 }
	 bool isEmailCorrect(string email) {
		 if (email.find('@') == string::npos || email.size() < 5 || email.substr(email.size() - 4) != ".com") {
			 return false;
		 }
		 return true;
	 }
	 bool isEmailUnique(string email) {
		 extern unordered_map<string, Staff> staffList;
		 for (auto it = staffList.begin(); it != staffList.end(); ++it) {
			 if (it->second.email == email) {
				 return false;
			 }
		 }
		 return true;
	 }
	 bool isNameValid(string name) {
		 for (char c : name) {
			 if (!isalpha(c) && c != ' ') return false;
		 }
		 return !name.empty();
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

class Subscriptions {
private:
	 string type;           // 1 month,3 month,6 month,1 year
	 string start_date;
	 string end_date;
	 double price;
	 bool isActivated;/// for sendnotifications
	 bool is_VIP;
public:

	 Subscriptions(string _type, string  st_date, bool vip) {
		  type = _type;
		  start_date = st_date;
		  is_VIP = vip;
		  price = getPrice();
		  calculateEndDate();
	 }
	 Subscriptions() : type(""), start_date(""), end_date(""),
		  is_VIP(false), price(0.0), isActivated(false) {
	 }

	 double getPrice() {
		  if (type == "1 month")
			   price = 450.0;
		  else if (type == "3 month")
			   price = 1250.0;
		  else if (type == "6 month")
			   price = 2400.0;
		  else if (type == "1 year")
			   price = 4700.0;
		  if (is_VIP)
			   price += 100.0;
		  return price;
	 }
	 //void renewSubscription(string& newType, time_t newStdate);
	 bool isActive() {
		  time_t current_date = time(0);
		  time_t convertedStartDate = getTime_t(start_date);
		  time_t convertedEndDate = getTime_t(end_date);
		  return(current_date >= convertedStartDate && current_date <= convertedEndDate);
	 }
	 string getType() {
		  return type;
	 }
	 bool get_is_VIP() {
		  return is_VIP;
	 }
	 unordered_map<string, GymClasses>getAvailableClasses();
	 /*time_t calaculateEndDate() {
		   tm tmStart;
		   time_t convertedStartDate = User::getTime_t(start_date);
		   localtime_s(&tmStart, &convertedStartDate);

		   tmStart.tm_sec = 0;
		   tmStart.tm_min = 0;
		   tmStart.tm_hour = 0;

		   if (type == "1 month") {
				tmStart.tm_mon += 1;
		   }
		   else if (type == "3 month") {
				tmStart.tm_mon += 3;
		   }
		   else if (type == "6 month") {
				tmStart.tm_mon += 6;
		   }
		   else if (type == "1 year") {
				tmStart.tm_year += 1;
		   }

		   return mktime(&tmStart);
	  }*/

	 void calculateEndDate() {
		  struct tm t;
		  time_t convertedStartDate = getTime_t(start_date);
		  localtime_s(&t, &convertedStartDate);

		  if (type == "1 month")
			   t.tm_mon += 1;
		  else if (type == "3 months")
			   t.tm_mon += 3;
		  else if (type == "6 months")
			   t.tm_mon += 6;
		  else if (type == "1 year")
			   t.tm_year += 1;
		  time_t convertedEndDate = mktime(&t);
		  end_date = getFormat(convertedEndDate);
	 }

	 void set_is_VIP(bool vip) {
		  is_VIP = vip;
	 }
	 bool IsExpired() {
		  time_t convertedT = getTime_t(end_date);
		  return time(0) > convertedT;
	 }
	 bool createOffer() {
		  return (is_VIP == true);
	 }

	 double applyOffer(double basePrice) {
		  if (createOffer()) {
			   price = basePrice * 0.75;
		  }
		  else {
			   price = basePrice * 0.90;
		  }
		  return price;
	 }
	 string getStartDate() {
		  return start_date;
	 }

};

class User {
public:
	 string ID;
	 string name;
	 string email;

	 string password;
	 string Birthday;
	 string PicPath;
	 Subscriptions subscription; // 1 month, 3 month, 6 month, 1 year -> This is the gym subscription in general (type Subscriptions)

	 float myWallet; // cash back from cancelling
	 bool isVip;
	 vector<Slot> myReservations; // List of reserved slots
	 list<string> myClasses;  // List of reserved classes ->> classID




	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Birthday = "";
		  subscription = Subscriptions();
	 }
	 static bool login(string email, string password) {
		  extern unordered_map<string, User> userList;
		  auto it = userList.begin();
		  while (it != userList.end()) {
			   if (it->second.email == email && it->second.password == password) {
					loginID = it->second.ID;
					return true;
			   }
			   it++;
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

	 static string generateID() {
		  extern unordered_map<string, User> userList;
		  string ID = "usr-";
		  ID += to_string(userList.size() + 1);
		  return ID;
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
	 /*
	 Note:
	 All class members start their subscription at the same time and end at the same time,
	 even if all members do not subscribe at the same time,
	 The last day to subscribe to the class is the middle of the month.
	 */
	 string classID;
	 string className;
	 string instructor;
	 string startDate;
	 string endDate;
	 float price = 1.0;
	 int maxMembers; // Maximum number of members allowed in the class
	 unordered_map<string, User> members; // List of users enrolled in the class	
	 deque<string> waitingList; // List of userIDs on the waiting list

	 bool isFull() {
		  return members.size() == maxMembers;
	 }
	 static string  FindIndex(const string& classID) {
		  extern unordered_map<string, GymClasses> gymClassList;
		  auto it = gymClassList.find(classID);
		  if (it != gymClassList.end()) {
			   return it->first; // Return the classID
		  }


		  return ""; // Not found
	 }
	 int getDaysDifference() {
		  string date1 = User::getCurrentDate_MM_DD_YYYY();
		  time_t t1 = getTime_t(date1);
		  time_t t2 = getTime_t(startDate);
		  double secondsDiff = difftime(t2, t1);
		  int daysDiff = (int)(secondsDiff / (60 * 60 * 24));
		  return daysDiff;
	 }


};

struct PadelCourt {
	 string ID;//foramt "court-1"
	 string name;
	 string location;
	 float price; // Price per hour
	 vector<Slot> slots; // List of reserved slots

	 void deleteSlot(const string& ID) {
		  for (int i = 0; i < slots.size(); i++) {
			   if (slots[i].ID == ID) {
					slots.erase(slots.begin() + i);
					break;
			   }
		  }
	 }

	 static string searchCourt(const string& courtName) {
		  extern unordered_map<string, PadelCourt> courtList;

		  for (auto it = courtList.begin(); it != courtList.end(); it++) {
			   if (it->second.name == courtName) {
					return it->second.ID;
			   }
		  }
		  return ""; // Not found
	 }


};

struct Notification {
	 string ID;
	 string message;
	 string date; // MM/DD/YYYY
	 string time; // HH:MM
	 static int notificationCounter; // Counter to generate unique notification IDs
	 static string generateNotificationID() {
		  return "notification-" + to_string(notificationCounter++);
	 }
	 static string standardMessage(const string& message/*Subscriptions ss,gymClass gm*/) { //may be just gymClass
		  // Convert the message to a standard format
		  string standardMessage = message;/*
		  dear userName,
		  your subscription will expire on date ()
		  you have to renew it before date

		  thank you for using our service



		  */


		  return standardMessage;
	 }

};


extern vector<CreditCard> cardList;
extern unordered_map<string, User> userList;
extern unordered_map<string, Staff> staffList;
extern unordered_map<string, GymClasses> gymClassList;
extern unordered_map<string, PadelCourt> courtList;


extern void writeCreditCardData();
extern void writeUserData();

