#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>

#include <msclr/marshal_cppstd.h>

using namespace std;
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


class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Brithday;
	 string subscription; // 1 month, 3 month, 6 month, 1 year -> This is the gym subscription in general (type Subscriptions)
	 float myWallet; // cash back from cancelling
	 bool isVip;
	 vector<Slot> myReservations; // List of reserved slots
	 /*
	 list<string> myClasses;  // List of reserved classes ->> classID
	 */


	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Brithday = "";
		  subscription = "";
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
	 deque<User> waitingList;

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
		  time_t t1 = User::getTime_t(date1);
		  time_t t2 = User::getTime_t(startDate);
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


extern std::vector<CreditCard> cardList;
extern std::unordered_map<std::string, User> userList;
extern std::unordered_map<std::string, Staff> staffList;
extern std::unordered_map<std::string, GymClasses> gymClassList;
extern std::unordered_map<std::string, PadelCourt> courtList;
