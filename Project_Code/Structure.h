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
#include<set>
#include <iomanip>
#include<map>
#include<stack>
#include <filesystem>  
#include <Windows.h>  
#include <msclr/marshal_cppstd.h>

#define aliens System::Windows::Forms
#define PicAsset "accPic/" 


using namespace std;
using namespace msclr::interop;
static int baseID = 1000;
static int baseClassID = 0;
extern string loginID;   // -1 means not logged in
// class Subscriptions // This gym subscription generally has nothing to do with classes.
extern string defaultImagePath;
extern string PassCode;
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
	 if (tm == nullptr) {
		  return "Invalid date";
	 }
	 char buffer[11];
	 strftime(buffer, sizeof(buffer), "%m/%d/%Y", tm);
	 return string(buffer);
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


class User;
class GymClasses;
class Notification;

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

	 Subscriptions(string _type, string st_date, string ed_date, bool vip) {
		  type = _type;
		  start_date = st_date;
		  end_date = ed_date;
		  is_VIP = vip;
		  price = getPrice();

	 }
	 Subscriptions(string _type, string  st_date, bool vip) {
		  type = _type;
		  start_date = st_date;
		  is_VIP = vip;
		  price = getPrice();
		  end_date = calculateEndDate();
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

	 bool isActive() {
		  time_t current_date = time(0);
		  time_t convertedStartDate = getTime_t(start_date);
		  time_t convertedEndDate = getTime_t(end_date);
		  return(current_date >= convertedStartDate && current_date <= convertedEndDate);
	 }
	 bool isActive(int month, int year) {
		  // Create time_t for the first and last day of the specified month/year
		  tm firstDay = {};
		  firstDay.tm_year = year - 1900;
		  firstDay.tm_mon = month - 1;
		  firstDay.tm_mday = 1;
		  time_t firstDayTime = mktime(&firstDay);

		  tm lastDay = firstDay;
		  lastDay.tm_mon += 1; // Next month
		  if (lastDay.tm_mon == 12) {
			   lastDay.tm_mon = 0;
			   lastDay.tm_year += 1;
		  }
		  time_t lastDayTime = mktime(&lastDay) - 1; // Last second of the month

		  time_t startTime = getTime_t(start_date);
		  time_t endTime = getTime_t(end_date);

		  // Check if subscription overlaps with the specified month
		  return (startTime <= lastDayTime && endTime >= firstDayTime);
	 }
	 string getType() {
		  return type;
	 }
	 bool get_is_VIP() {
		  return is_VIP;
	 }
	 // Fix for the error: 'allowedSubTypes': is not a member of 'System::Int32'
	 // Ensure that the `gymClass` object is of type `GymClasses` and not mistakenly treated as an integer.

	 // Ensure this is declared globally or in the appropriate scope.

	 unordered_map<string, GymClasses> getAvailableClasses();

	 string calculateEndDate() {
		  struct tm t;
		  time_t convertedStartDate = getTime_t(start_date);
		  localtime_s(&t, &convertedStartDate);

		  if (type == "1 month")
			   t.tm_mon += 1;
		  else if (type == "3 month")
			   t.tm_mon += 3;
		  else if (type == "6 month")
			   t.tm_mon += 6;
		  else if (type == "1 year")
			   t.tm_year += 1;
		  time_t convertedEndDate = mktime(&t);

		  string str = getFormat(convertedEndDate);
		  return  str;
	 }
	 string endTimeAfterRenew() {
		  struct tm t;
		  time_t convertedStartDate = getTime_t(end_date);
		  localtime_s(&t, &convertedStartDate);
		  t.tm_mday += 1;
		  if (type == "1 month")
			   t.tm_mon += 1;
		  else if (type == "3 month")
			   t.tm_mon += 3;
		  else if (type == "6 month")
			   t.tm_mon += 6;
		  else if (type == "1 year")
			   t.tm_year += 1;
		  time_t convertedEndDate = mktime(&t);
		  end_date = getFormat(convertedEndDate);
		  return end_date;
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

	 double applyOffer(int remainingDays) {

		  if (createOffer() && (remainingDays >= 3 && remainingDays <= 5)) {
			   return 0.15;
		  }
		  else if (!createOffer() && (remainingDays >= 3 && remainingDays <= 5)) {
			   return 0.10;
		  }

		  return 0.0;
	 }
	 string getStartDate() {
		  return start_date;
	 }
	 string getEndDate() {
		  return end_date;
	 }
	 int getRemainingDays() {
		 time_t currentDate = time(0);
		 time_t endDate = getTime_t(end_date);
		 double secondsDiff = difftime(endDate, currentDate);
		 int daysRemaining = static_cast<int>(secondsDiff / (60 * 60 * 24));
		 return daysRemaining;
	 }

	 void renewSub(Subscriptions sub) {
		  type = sub.type;
		  is_VIP = sub.is_VIP;
		  price = sub.price;
		  end_date = endTimeAfterRenew();

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
	 int classEntered = 0;
	 float myWallet; // cash back from cancelling
	 bool isVip;
	 // bool isActive = true;
	 list<Notification> myNotifications; // List of notifications
	 vector<Slot> myReservations; // List of reserved slots
	 list<string> myClasses;  // List of reserved classes ->> classID
	 list<string> myWaitingList; // List of waiting classes ->> classID

	 std::string classEnteredStr = std::to_string(classEntered);

	 User(string id, string nm, string em, string pass, string bday, Subscriptions sub, string pic, string classes) {
		  ID = id;
		  name = nm;
		  email = em;
		  password = pass;
		  Birthday = bday;
		  subscription = sub;
		  PicPath = pic;


		  if (classes != "null" && !classes.empty()) {
			   stringstream ss(classes);
			   string classID;
			   while (getline(ss, classID, ';')) {
					if (!classID.empty()) {
						 myClasses.push_back(classID);
					}
			   }
			   classEntered = myClasses.size();
		  }
	 }
	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Birthday = "";
		  PicPath = "null";
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
		  ID += to_string(1001 + userList.size());
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
	 bool isNameValid(string name) {
		  for (char c : name) {
			   if (!isalpha(c) && c != ' ') return false;
		  }
		  return !name.empty();
	 }
	 bool isEmailCorrect(string email) {
		  if (email.find('@') == string::npos || email.size() < 5 || email.substr(email.size() - 4) != ".com") {
			   return false;
		  }
		  return true;
	 }
	 bool isEmailUnique(string email) {
		  extern unordered_map<string, User> userList;
		  for (auto it = userList.begin(); it != userList.end(); ++it) {
			   if (it->second.email == email) {
					return false;
			   }
		  }
		  return true;
	 }
	 bool registerMember(string Name, string Email, string Password, string Bday, string subType, bool isVip, string picPath) {
		  extern int baseID;
		  extern unordered_map<string, User>userList;
		  initializeBaseIDUser();
		  if (!isNameValid(Name)) return false;
		  if (!isEmailCorrect(Email) || !isEmailUnique(Email)) return false;
		  // if (!isBirthdayValid(Bday)) return false;
		  if (subType != "1 month" && subType != "3 month" && subType != "6 month" && subType != "1 year")
			   return false;
		  Subscriptions userSub(subType, getCurrentDate_MM_DD_YYYY(), isVip);
		  // userSub.getAvailableClasses();

		  ID = "M" + to_string(++baseID);// replace with the generateID function
		  name = Name;
		  email = Email;
		  password = Password;
		  Birthday = Bday;
		  subscription = userSub;
		  PicPath = picPath;
		  classEntered = 0;

		  userList[ID] = *this;
		  return true;
	 }
	 static void initializeBaseIDUser() {
		  extern unordered_map<string, User> userList;
		  int maxID = 1000; // Default starting point

		  for (const auto& pair : userList) {
			   const string& id = pair.first;
			   if (id.length() > 1 && id[0] == 'M') {
					try {
						 int num = stoi(id.substr(1));
						 if (num > maxID) {
							  maxID = num;
						 }
					}
					catch (const exception& e) {
						 continue;
					}
			   }
		  }
		  baseID = maxID;

	 }
	 bool isClassReserved(const string& classID) {
		  for (const auto& it : myClasses) {
			   if (it == classID) {
					return true;
			   }
		  }
		  return false;
	 }
	 bool isClassWaiting(const string& classID) {
		  for (const auto& it : myWaitingList) {
			   if (it == classID) {
					return true;
			   }
		  }
		  return false;
	 }
	 bool MessagesNotRead();
};

struct Notification {
	 string ID;
	 string message;
	 string date; // MM/DD/YYYY
	 string hour; // HH:MM
	 bool isRead = false; // true if the user has read the notification
	 static int notificationCounter;
	 static string generateNotificationID() {
		  return "noti-" + to_string(1000 + notificationCounter++);
	 }
	 static string standardMessage(User usr, string cls, int type) { //0-> renew notification, 1-> waitlist notification
		  // Convert the message to a standard format
		  string standardMessage;
		  if (type == 0) {
			   standardMessage = "Dear " + usr.name + ",\nyour subscription will expire on date " + usr.subscription.getEndDate() +
					"\nyou have to renew it before " + "\n\nThank you for using our service :)";
		  }
		  else if (type == 1) {
			   standardMessage = "Dear " + usr.name + ",\nYou have been added to " + cls +
					"\nyou were waiting for." + "\n\nHave a nice day :)";
		  }
		  else if (type == 2) {
			   standardMessage = "Dear " + usr.name + ",\nYou applied to join the class \" " + cls +
					"\"\n and it's no longer possible to join this class this month.\nYou can explore the available classes as they start.\nYour payment has been refunded." + "\n\nHave a nice day :)";
		  }

		  /*
		  You applied to join the class, but no one responded, and it's no longer possible to join this class this month. You can explore the available classes as they start. Your payment has been refunded.

		  */





		  return standardMessage;
	 }
	 Notification(User usr, string _ID, string _Date, string _hour, string cls, int type, bool _isRead) {
		  ID = _ID;
		  date = _Date;
		  hour = _hour;
		  message = standardMessage(usr, cls, type);
		  isRead = _isRead;
		  notificationCounter++;

	 }
	 Notification() {
		  date = User::getCurrentDate_MM_DD_YYYY();
		  time_t now = time(0);
		  tm* localtm = localtime(&now);

		  stringstream ss;
		  ss << setfill('0') << setw(2) << localtm->tm_hour << ":"
			   << setfill('0') << setw(2) << localtm->tm_min;
		  hour = ss.str();
		  ID = generateNotificationID();
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
		  PicPath = defaultImagePath;
	 }


	 string generateMonthlyReport(const string& selectedMonth, int selectedYear) {
		  extern unordered_map<string, User> userList;

		  vector<User> activeUsers;
		  double totalRevenue = 0.0;
		  map<string, pair<int, double>> subscriptionState;
		  int currentMonth = stoi(selectedMonth);

		  stringstream report;
		  report << "================Monthly Report for ";
		  if (currentMonth < 10) report << "0";
		  report << currentMonth << "-" << selectedYear << " ================\n\n";

		  // Most Active Members Section
		  report << ">> Most Active Members (Top 10 Active Members):\n";
		  report << "--------------------------------------------------------------------------\n";
		  report << left << setw(30) << "Name"
			   << setw(15) << "ID"
			   << setw(20) << "Classes Attended"
			   << setw(10) << "VIP" << "\n";
		  report << "--------------------------------------------------------------------------\n";

		  for (auto& entry : userList) {
			   User& user = entry.second;
			   if (user.subscription.isActive(currentMonth, selectedYear)) {
					activeUsers.push_back(user);
					string type = user.subscription.getType();
					double price = user.subscription.getPrice();

					subscriptionState[type].first += 1;
					subscriptionState[type].second += price;
					totalRevenue += price;
			   }
		  }

		  // Sort active users by number of classes attended
		  sort(activeUsers.begin(), activeUsers.end(), [](const User& user1, const User& user2) {
			   return user1.myClasses.size() > user2.myClasses.size();
			   });

		  // Display top 10 most active members
		  int numberOfMembers = min(10, static_cast<int>(activeUsers.size()));
		  for (int i = 0; i < numberOfMembers; ++i) {
			   string name = activeUsers[i].name;
			   if (name.length() > 24) {
					name = name.substr(0, 21) + "...";
			   }

			   report << left << setw(25) << name
					<< setw(12) << activeUsers[i].ID
					<< setw(18) << activeUsers[i].myClasses.size()
					<< setw(8) << (activeUsers[i].subscription.get_is_VIP() ? "YES" : "NO") << "\n";
		  }


		  // Subscription Summary Section
		  report << "--------------------------------------------------------------------------\n";
		  report << ">> Subscription Summary by Type:\n";
		  report << "--------------------------------------------------------------------------\n";
		  report << left << setw(25) << "Plan Type"
			   << setw(15) << "Subscribers"
			   << setw(20) << "Total Revenue (EGP)" << "\n";
		  report << "--------------------------------------------------------------------------\n";
		  for (const auto& it : subscriptionState) {
			   report << left << setw(25) << it.first
					<< setw(15) << it.second.first
					<< fixed << setprecision(2) << setw(20) << it.second.second << "\n";
		  }

		  report << "==========================================================================\n";
		  report << ">> Total Subscription Revenue this Month: " << fixed << setprecision(2) << totalRevenue << " EGP\n";
		  report << "==========================================================================\n";

		  if (activeUsers.empty()) {
			   return "";
		  }

		  return report.str();
	 }

	 static void initializeBaseID() {
		  extern unordered_map<string, Staff> staffList;
		  int maxID = 1000; // Default starting point

		  for (const auto& pair : staffList) {
			   const string& id = pair.first;
			   if (id.length() > 1 && (id[0] == 'R' || id[0] == 'C')) {
					try {
						 int num = stoi(id.substr(1));
						 if (num > maxID) {
							  maxID = num;
						 }
					}
					catch (const exception& e) {
						 continue;
					}
			   }
		  }
		  baseID = maxID;

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

	 bool registerStaff(string Name, string Email, string Password, string Phone, string Role, string imagepath = "") {
		  extern unordered_map<string, Staff> staffList;
		  extern int baseID;
		  initializeBaseID();
		  if (!isNameValid(Name)) return false;
		  if (!isEmailUnique(Email)) return false;
		  name = Name;
		  email = Email;
		  password = Password;
		  phone = Phone;
		  role = Role;
		  PicPath = imagepath;
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

		  ID = id;
		  staffList[id] = *this;
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
struct Session {
	 string date;
	 string startTime;
	 string endTime;
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
	 string instructorID;
	 string startDate;
	 string endDate;
	 float price = 1.0;
	 int maxMembers; // Maximum number of members allowed in the class
	 bool reSchedule = false; // true if the class is rescheduled;
	 list <string> members; // List of user IDs enrolled in the class
	 // unordered_map<string, User> members; // List of users enrolled in the class	
	 deque<string> waitingList; // List of userIDs on the waiting list
	 vector<string>allowedSubTypes;
	 vector<Session> sessions;
	 vector<int> recurringDays;
	 GymClasses() {
		  classID = "";
		  instructor = "";
		  instructorID = "";
	 }
	 GymClasses(string name, Staff coach, string st, string endT, string sessionDate, string sessionStart, string sessionEnd, int capacity, float pri) {
		  classID = generateUniqueID();
		  className = name;
		  instructor = coach.name;
		  instructorID = coach.ID;
		  startDate = st;
		  endDate = calculateEndDate(startDate);
		  maxMembers = capacity;
		  price = pri;

		  Session session;
		  session.date = sessionDate;
		  session.startTime = sessionStart;
		  session.endTime = sessionEnd;
		  sessions.push_back(session);
	 }

	 bool memberExist(const string& userID) {
		  for (const auto& it : members) {
			   if (it == userID) {
					return true;
			   }
		  }
		  return false;
	 }

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
		  double secondsDiff = difftime(t1, t2);
		  int daysDiff = (int)(secondsDiff / (60 * 60 * 24));
		  return daysDiff;
	 }
	 void removeFromWaitingList(const string& userID) {
		  auto it = find(waitingList.begin(), waitingList.end(), userID);
		  if (it != waitingList.end()) {
			   waitingList.erase(it);

		  }
	 }
	 string generateUniqueID() {
		  static bool initialized = false;
		  if (!initialized) {
			   extern unordered_map<string, GymClasses> gymClassList;
			   int maxID = 0;

			   for (const auto& pair : gymClassList) {
					const string& id = pair.first;
					if (id.length() > 5 && id.substr(0, 5) == "CLASS") {
						 try {
							  int num = stoi(id.substr(5));
							  if (num > maxID) {
								   maxID = num;
							  }
						 }
						 catch (...) {
							  continue;
						 }
					}
			   }

			   baseClassID = maxID;
			   initialized = true;
		  }

		  baseClassID++;
		  return "CLASS" + to_string(baseClassID);
	 }

	 void generateRecurringSessions(const string& startDt, const string& endDt, const string& startT, const string& endT, const vector<int>& recurringDays) {
		  time_t startTime = getTime_t(startDt);
		  time_t endTime = getTime_t(endDt);
		  tm current;
		  localtime_s(&current, &startTime);

		  set<int> daysSet(recurringDays.begin(), recurringDays.end());  	 // (0=Sunday, 1=Monday, ...)
		  while (startTime <= endTime) {
			   localtime_s(&current, &startTime);
			   int currentWday = current.tm_wday; // 0=Sunday, 1=Monday, ..., 6=Saturday

			   if (daysSet.find(currentWday) != daysSet.end()) {
					string dateStr = getFormat(startTime);
					bool alreadyExists = false;
					for (const auto& existing : sessions) {
						 if (existing.date == dateStr && existing.startTime == startT && existing.endTime == endT) {
							  alreadyExists = true;
							  break;
						 }
					}

					if (!alreadyExists) {
						 Session session;
						 session.date = dateStr;
						 session.startTime = startT;
						 session.endTime = endT;
						 sessions.push_back(session);
					}
			   }


			   // Move to next day
			   current.tm_mday += 1;
			   startTime = mktime(&current);
		  }
	 }
	 bool createClass(const string& sessionStartTime, const string& sessionEndTime, vector<int> recurringDays) {
		  generateRecurringSessions(startDate, endDate, sessionStartTime, sessionEndTime, recurringDays);
		  extern unordered_map<string, GymClasses> gymClassList;
		  gymClassList[classID] = *this;
		  return true;
	 }
	 bool existInWaitingList(const string& userID) {
		  for (const auto& it : waitingList) {
			   if (it == userID) {
					return true;
			   }
		  }
		  return false;
	 }

	 string calculateEndDate(const string& startDt) {
		  time_t startTime = getTime_t(startDt);
		  tm t;
		  localtime_s(&t, &startTime);
		  t.tm_mon += 1; // Add one month
		  time_t endTime = mktime(&t);
		  return getFormat(endTime);
	 }
	 string displayClassesForUserSubscription(const string& userSubType) {
		  extern unordered_map<string, GymClasses> gymClassList;
		  stringstream result;

		  // Check if there are any classes for the subscription type
		  bool hasClasses = false;
		  for (const auto& pair : gymClassList) {
			   const GymClasses& gymClass = pair.second;
			   if (find(gymClass.allowedSubTypes.begin(), gymClass.allowedSubTypes.end(), userSubType) != gymClass.allowedSubTypes.end()) {
					hasClasses = true;
					break;
			   }
		  }

		  if (hasClasses) {
			   // Generate output for available classes
			   result << "Classes Available for Subscription Type: " << userSubType << "\n";
			   result << "================================================================================\n";
			   result << left << setw(10) << "Class ID"
					<< setw(20) << "Class Name"
					<< setw(20) << "Instructor"
					<< setw(15) << "Start Date"
					<< setw(15) << "End Date"
					<< setw(10) << "Price"
					<< setw(15) << "Max Members" << "\n";
			   result << "================================================================================\n";

			   for (const auto& pair : gymClassList) {
					const GymClasses& gymClass = pair.second;
					if (find(gymClass.allowedSubTypes.begin(), gymClass.allowedSubTypes.end(), userSubType) != gymClass.allowedSubTypes.end()) {
						 string className = gymClass.className;
						 if (className.length() > 17) {
							  className = className.substr(0, 14) + "...";
						 }
						 string instructor = gymClass.instructor;
						 if (instructor.length() > 17) {
							  instructor = instructor.substr(0, 14) + "...";
						 }

						 result << left << setw(10) << gymClass.classID
							  << setw(20) << className
							  << setw(20) << instructor
							  << setw(15) << gymClass.startDate
							  << setw(15) << gymClass.endDate
							  << fixed << setprecision(2) << setw(10) << gymClass.price
							  << setw(15) << gymClass.maxMembers << "\n";

						 result << "Sessions:\n";
						 for (const auto& session : gymClass.sessions) {
							  result << "  Date: " << session.date << ", Time: " << session.startTime << " - " << session.endTime << "\n";
						 }
						 result << "--------------------------------------------------------------------------------\n";
					}
			   }
			   result << "================================================================================\n";
		  }
		  else {

			   return "No classes available for your subscription type: " + userSubType;
		  }

		  return result.str();
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

struct Workout {
	 string date;
	 string type;
	 int duration;
	 int caloriesBurned;

	 Workout() : date(""), type(""), duration(0), caloriesBurned(0) {}
	 Workout(string d, string t, int dur, int cal) : date(d), type(t), duration(dur), caloriesBurned(cal) {}
	 void display() {
		  cout << "Date: " << date << "\nType: " << type << "\nDuration: " << duration << " minutes\nCalories Burned: " << caloriesBurned << endl;
	 }
};

class WorkoutManger
{
private:
	 unordered_map<string, vector<Workout>>workoutData;

public:



	 void recordWorkout(const string& memberID, const Workout& workout)
	 {
		  if (memberID.empty()) {
			   cout << "Error: Member ID is empty. Workout not recorded.\n";
			   return;
		  }
		  workoutData[memberID].push_back(workout);

	 }

	 int calcCalories(const User& user, int duration, string type, int bodyWei)
	 {
		  int bodyWeight = bodyWei;

		  type.erase(remove_if(type.begin(), type.end(), ::isspace), type.end());
		  transform(type.begin(), type.end(), type.begin(), ::tolower);

		  // MET values for different workouts
		  unordered_map<string, int> metValues = {
			  {"cardio", 8},
			  {"strength", 5},
			  {"yoga", 3},
			  {"cycling", 7},
			  {"hiit", 9},
			  {"pilates", 4}
		  };

		  // Find MET value or fallback to default
		  int met = 5; // Default MET
		  if (metValues.find(type) != metValues.end()) {
			   met = metValues[type];
		  }
		  else {
			   cout << "Unknown workout type \"" << type << "\". Using default MET = 5\n";
		  }

		  // Calculate calories burned
		  return static_cast<int>(met * bodyWeight * (duration / 60.0));
	 }

	 void loadFromFile(const string& filename, unordered_map<string, User>& users) {
		  ifstream inFile(filename);
		  if (!inFile.is_open()) {
			   cerr << "Error: Couldn't open file for loading.\n";
			   return;
		  }

		  workoutData.clear();
		  string line;
		  while (getline(inFile, line)) {
			   stringstream ss(line);
			   string userId, date, type, durationStr, caloriesStr;
			   getline(ss, userId, ',');
			   getline(ss, date, ',');
			   getline(ss, type, ',');
			   getline(ss, durationStr, ',');
			   getline(ss, caloriesStr, ',');

			   int duration = stoi(durationStr);
			   int calories = stoi(caloriesStr);


			   Workout w(date, type, duration, calories);
			   recordWorkout(userId, w);
		  }

		  inFile.close();
		  cout << "Workout data loaded successfully.\n";
	 }

	 void saveToFile(const string& filename) {
		  ofstream outFile(filename);
		  if (!outFile.is_open()) {
			   cerr << "Error: Couldn't open file for saving.\n";
			   return;
		  }

		  for (const auto& userPair : workoutData) {
			   for (const Workout& w : userPair.second) {
					outFile << userPair.first << ","
						 << w.date << ","
						 << w.type << ","
						 << w.duration << ","
						 << w.caloriesBurned << "\n";
			   }
		  }

		  outFile.close();
		  cout << "Workout data saved successfully.\n";
	 }

	 unordered_map<string, vector<Workout>>& getWorkoutData() { return workoutData; }


};


extern vector<CreditCard> cardList;
extern unordered_map<string, User> userList;
extern unordered_map<string, Staff> staffList;
extern unordered_map<string, GymClasses> gymClassList;
extern unordered_map<string, PadelCourt> courtList;
extern WorkoutManger workoutManager;


extern void writeCreditCardData();
extern void writeUserData();