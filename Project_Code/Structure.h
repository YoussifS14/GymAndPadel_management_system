#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace std;

struct CreditCard {
	 string cardID;
	 string cardCVV;
	 string cardName;
	 string ExpirationDate; // MM/YY
	 float balance;

	 static bool validateCard(const CreditCard& CheckCard) {
		  extern vector<CreditCard> cardList;

		  for (CreditCard& card : cardList) {
			   if (card.cardID == CheckCard.cardID && card.cardCVV == CheckCard.cardCVV && card.cardName == CheckCard.cardName && card.ExpirationDate == CheckCard.ExpirationDate&& card.balance> CheckCard.balance) {
					card.balance -= CheckCard.balance;

					return true; // Placeholder for actual validation
			   }
		  }
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
		  for (const Staff& staff : staffList) {
			   if (staff.email == email && staff.password == password) {
					return true;
			   }
		  }
		  return false;
	 }

};

class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Brithday;
	 string subscription; // 1 month, 3 month, 6 month, 1 year

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
		  for (const User& user : userList) {
			   if (user.email == email && user.password == password) {
					return true;
			   }
		  }
		  return false;
	 }

};

vector<Staff> staffList;
vector<User> userList;
vector<CreditCard> cardList;

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
		  getline(ss, card.ExpirationDate);
		  getline(ss, card.cardCVV, ',');
		  getline(ss, temp);
		  card.balance = stof(temp);
		  cardList.push_back(card);

		  // Add the card to a vector or process it as needed
	 }
	 file.close();
}