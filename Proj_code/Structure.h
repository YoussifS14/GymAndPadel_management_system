#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cctype>
using namespace std;
static int baseID = 1000;
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
		  for (int i = 0; i < staffList.size();i++) {
			   if (staffList[i].email == email && staffList[i].password == password) {
					loginIndex = i;
					return true;
			   }
		  }
		  return false;
	 }

};
struct Slot {
	 static int slotCount;
	 string ID;
	 string courtName; 
	 string date; // MM/DD/YYYY
	 string startTime; 
	 string endTime;
	 //superkey ->courtName + ID
};

class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Brithday;
	 string subscription; // 1 month, 3 month, 6 month, 1 year
	 vector<Slot> myReservations; // List of reserved slots

	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Brithday = "";
		  subscription = "";
	 }
	 //
	 User(string id, string name, string email, string password, string bday, string sub);
	 static bool isEmailCorrect(string email);
	 static bool isEmailUnique(string email);
	 static bool isNameValid(string name);
	 static bool isBirthdayValid(string bday);
	 static bool registerMember();
	 //
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

};


struct PadelCourt {
	 string courtID;//foramt "court-1"
	 string name;
	 string location;
	 float price; // Price per hour
	 vector<Slot> slots; // List of reserved slots
	
	
};


vector<Staff> staffList;
vector<User> userList;
vector<CreditCard> cardList;
vector<PadelCourt> courtList;


