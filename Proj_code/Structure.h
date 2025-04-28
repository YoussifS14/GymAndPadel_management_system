#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <cctype>
#include<map>
#include<algorithm>
#include<unordered_map>

using namespace std;
static int baseID = 1000;//**
extern string loginIndex;

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


struct Slot {
	 static int slotCount;
	 string ID;
	 string courtName;
	 string date; // MM/DD/YYYY
	 string startTime;
	 string endTime;
	 //superkey ->courtName + ID
};

class GymClasses;//Subscriptions ???? ??? ??user ???? ?? GymClasses ????? ?????? هتتعدل

class Subscriptions {
private:
	 string type;           // 1 month,3 month,6 month,1 year
	 time_t start_date;
	 time_t end_date;
	 double price;
	 bool is_VIP;
	 bool isActivated;/// for sendnotifications
public:

	 Subscriptions(string _type, time_t st_date, bool vip) {
		  type = _type;
		  start_date = st_date;
		  is_VIP = vip;
		  price = getPrice();
		  end_date = calaculateEndDate();

	 }
	 Subscriptions() : type(""), start_date(0), end_date(0),
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
		  return(current_date >= start_date && current_date <= end_date);
	 }
	 string getType() {
		  return type;
	 }
	 bool get_is_VIP() {
		  return is_VIP;
	 }
	 unordered_map<string, GymClasses>getAvailableClasses();
	 time_t calaculateEndDate() {
		  tm tmStart;
		  localtime_s(&tmStart, &start_date);

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
	 }

	 void calculateEndDate() {
		  struct tm t;
		  localtime_s(&t, &start_date);

		  if (type == "1 month")
			   t.tm_mon += 1;
		  else if (type == "3 months")
			   t.tm_mon += 3;
		  else if (type == "6 months")
			   t.tm_mon += 6;
		  else if (type == "1 year")
			   t.tm_year += 1;

		  end_date = mktime(&t);
	 }

	 void set_is_VIP(bool vip) {
		  is_VIP = vip;
	 }
	 bool IsExpired() {
		  return time(0) > end_date;
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


};

class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Birthday;
	 Subscriptions subscription; // 1 month, 3 month, 6 month, 1 year
	 int classEntered;
	 vector<Slot> myReservations; // List of reserved slots
	 User(string _id, string _name, Subscriptions sub, int classes) {
		  ID = _id;
		  name = _name;
		  subscription = sub;
		  classEntered = classes;
	 }
	 //*//
	 User(string _id, string _name, string _email, string _password, string _birthday, Subscriptions _sub, int _classEntered, vector<Slot> _reservations) {
		  ID = _id;
		  name = _name;
		  email = _email;
		  password = _password;
		  Birthday = _birthday;
		  subscription = _sub;
		  classEntered = _classEntered;
		  myReservations = _reservations;
	 }
	 User(string Id, string Name, string Email, string pass, string bday, Subscriptions Sub) {
		  ID = Id;
		  name = Name;
		  email = Email;
		  password = pass;
		  Birthday = bday;
		  subscription = Sub;
	 }

	 static bool registerMember();
	 //*//
	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Birthday = "";
		  classEntered = 0;
	 }
	 bool login(string email, string password) {
		  extern unordered_map<string, User> userList;
		  for (auto it = userList.begin(); it != userList.end(); ++it) {
			   if (it->second.email == email && it->second.password == password) {
					loginIndex = 1;
					this->ID = it->second.ID;
					this->name = it->second.name;
					this->email = it->second.email;
					this->password = it->second.password;
					this->Birthday = it->second.Birthday;
					this->subscription = it->second.subscription;
					this->classEntered = it->second.classEntered;
					this->myReservations = it->second.myReservations;
					return true;
			   }
		  }

		  cout << "Login failed. Incorrect email or password.\n";
		  return false;
	 }
	 void displayUserEnrolledClasses();
};


struct PadelCourt {
	 string courtID;//foramt "court-1"
	 string name;
	 string location;
	 float price; // Price per hour
	 vector<Slot> slots; // List of reserved slots


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
	 //*//
	 Staff(string id, string Name, string Email, string Password, string Phone, string Role, string picPath = " ") {
		  ID = id;
		  name = Name;
		  email = Email;
		  password = Password;
		  phone = Phone;
		  role = Role;
		  //PicPath = picPath; //gui
	 }
	 //*//
	 bool login(string email, string password) {
		  extern unordered_map<string, Staff> staffList;
		  for (auto it = staffList.begin(); it != staffList.end(); ++it) {
			   if (it->second.email == email && it->second.password == password) {
					loginIndex = 1;
					this->name = it->second.name;
					this->email = it->second.email;
					this->password = it->second.password;
					this->phone = it->second.phone;
					this->role = it->second.role;
					this->ID = it->second.ID;
					this->PicPath = it->second.PicPath;

					return true;
			   }
		  }
		  cout << "Login failed. Incorrect email or password.\n";
		  return false;
	 }
	 static bool comparingActivity(const User& user1, const User& user2) {
		  return user1.classEntered > user2.classEntered;
	 }
	 //*//
	 bool registerStaff();
	 User searchUserByID(string userID);
	 //**//
	 void generateMonthlyReport();
	 GymClasses createClass();   // only manager can acess 
	 void displayCoachClasses(string coachID);
};

class GymClasses {
public:

	 string classID;
	 string className;
	 Staff coachName;
	 string date; // MM/DD/YYYY
	 string startTime;
	 string endTime;
	 int maxMembers; // Maximum number of members allowed in the class
	 int currentMembersCount;
	 unordered_map<string, vector<User>> usersEnrolled; // connect the subscription type(key) with users enrolled in this class(value)
	 //vector<User> members; // List of users enrolled in the class	
	 deque<User> waitingList;
	 vector<string>allowedSubTypes;

	 GymClasses(string id, string name, Staff coach, string dt, string startT, string endT, int maxMem, int currentMem, unordered_map<string, vector<User>> enrolled, deque<User> waitList) {
		  classID = id;
		  className = name;
		  coachName = coach;
		  date = dt;
		  startTime = startT;
		  endTime = endT;
		  maxMembers = maxMem;
		  currentMembersCount = currentMem;
		  usersEnrolled = enrolled;
		  waitingList = waitList;
	 }
	 GymClasses(string name, Staff coach, string dt, string startT, string endT, int capacity) {
		  classID = generateUniqueID();
		  className = name;
		  coachName = coach;
		  date = dt;
		  startTime = startT;
		  endTime = endT;
		  maxMembers = capacity;
		  currentMembersCount = 0;
	 }

	 GymClasses() {
		  classID = "";
		  className = "";
		  date = "";
		  startTime = "";
		  endTime = "";
		  maxMembers = 0;
		  currentMembersCount = 0;
	 }


	 bool isFull();


	 string generateUniqueID() {
		  static int lastID = 0;
		  lastID++;
		  return "CLASS" + to_string(lastID);
	 }
};


extern unordered_map<string, User> userList;
extern unordered_map<string, Staff> staffList;
extern unordered_map<string, GymClasses> gymClassesList; // gymClass ID (key), gymClass(value)
extern vector<CreditCard> cardList;
extern vector<PadelCourt> courtList;
extern vector<Subscriptions> availableSubscriptions;

