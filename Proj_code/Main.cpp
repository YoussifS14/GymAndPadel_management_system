#include "Structure.h"
#include <regex>
#include <iomanip>
#include<map>
#include<algorithm>
#include "WorkoutManger.h"

string loginIndex;
vector<CreditCard> cardList;

unordered_map<string, User> userList;
unordered_map<string, Staff> staffList;
unordered_map<string, GymClasses> gymClassesList; // gymClass ID (key), gymClass(value)
vector<PadelCourt> courtList;
vector<Subscriptions> availableSubscriptions;


bool isValidTimeFormat(const string& time) {
	 // Regular expression to match HH:MM where HH is 00-23 and MM is 00-59
	 std::regex timeRegex(R"(^([01]?[0-9]|2[0-3]):([0-5][0-9])$)");
	 return std::regex_match(time, timeRegex);
}
int searchCourt(const string& courtName) {
	 for (int i = 0; i < courtList.size(); i++) {
		  if (courtList[i].name == courtName) {
			   return i;
		  }
	 }
	 return -1; // Not found
}
string getCurrentDate_MM_DD_YYYY() {
	 time_t now = time(0);
	 tm localTime;
	 localtime_s(&localTime, &now);

	 ostringstream dateStream;
	 dateStream << setfill('0') << setw(2) << (localTime.tm_mon + 1) << "/"
		  << setfill('0') << setw(2) << localTime.tm_mday << "/"
		  << (localTime.tm_year + 1900);

	 return dateStream.str();
}
int getHourDifferenceFromNow(const std::string& inputTime) {
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
	 tm localTime;
	 localtime_s(&localTime, &now); // Use localtime_s for thread safety
	 int currentHour = localTime.tm_hour;
	 int currentMinute = localTime.tm_min;

	 // Convert both times to total minutes
	 int inputTotalMinutes = inputHour * 60 + inputMinute;
	 int currentTotalMinutes = currentHour * 60 + currentMinute;

	 // Calculate the absolute difference in minutes
	 int diffMinutes = std::abs(currentTotalMinutes - inputTotalMinutes);

	 // Convert to full hours
	 int hourDiff = diffMinutes / 60;

	 return hourDiff;
}

void payment(float cost) {
	 CreditCard card;
	 cout << "Enter card ID: ";
	 cin >> card.cardID;
	 cout << "Enter card CVV: ";
	 cin >> card.cardCVV;
	 cin.ignore();
	 cout << "Enter card name: ";
	 getline(cin, card.cardName);
	 cout << "Enter expiration date (YY/MM): ";
	 cin >> card.ExpirationDate;
	 card.balance = cost;


	 if (CreditCard::validateCard(card)) {
		  cout << "Payment successful!" << endl;
	 }
	 else {
		  cout << "Payment failed!" << endl;
	 }

}

bool paymentChecking(double cost) {
	 CreditCard card;
	 cout << "Enter card ID: ";
	 cin >> card.cardID;
	 cout << "Enter card CVV: ";
	 cin >> card.cardCVV;
	 cin.ignore();
	 cout << "Enter card name: ";
	 getline(cin, card.cardName);
	 cout << "Enter expiration date (YY/MM): ";
	 cin >> card.ExpirationDate;
	 card.balance = cost;


	 if (CreditCard::validateCard(card)) {
		  cout << "Payment successful!" << endl;
		  return true;
	 }
	 else {
		  cout << "Payment failed!" << endl;
		  return false;
	 }

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
		  getline(ss, court.courtID, ',');
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
			   getline(ss, s.endTime);

			   court.slots.push_back(s);
		  }
		  courtList.push_back(court);
	 }
}

void reserveCourt() {
	 string Loc, date, time;
	 cout << "Enter location: ";
	 getline(cin, Loc);
	 cout << "Enter date (MM/DD/YYYY): ";
	 cin >> date;
	 cout << "Enter time (HH:MM): ";
	 do
	 {
		  cin >> time;
	 } while (!isValidTimeFormat(time));
	 int i = 1;
	 for (PadelCourt& court : courtList) {
		  if (court.location == Loc) {
			   bool exist = false;
			   if (court.slots.size() != 0)
					for (Slot& slot : court.slots) {
						 if (slot.date == date && slot.startTime == time) {
							  exist = true;
						 }
					}
			   if (!exist) {
					cout << i << '-' << court.name << "\tPrice : " << court.price << endl;
					i++;

			   }

		  }
	 }
	 cout << "you want to reserve court ?(y/n) ";
	 char choice;
	 cin >> choice;
	 if (choice == 'y' || choice == 'Y') {
		  cout << "Enter court name: ";
		  string courtName;
		  int courtIndex;
		  int checkEnd = 0;
		  cin.ignore(); // Clear the newline character from the input buffer
		  do {

			   getline(cin, courtName);
			   courtIndex = searchCourt(courtName);
			   checkEnd++;
			   cout << courtIndex << endl;
			   if (checkEnd > 3) {
					cout << "You have exceeded the maximum number of attempts." << endl;
					cout << "Reservation cancelled." << endl;
					return;
			   }
		  } while (courtIndex == -1);
		  cout << " Starting payment for court: " << courtList[courtIndex].name << endl;
		  payment(courtList[courtIndex].price);
		  cout << "Reservation successful!" << endl;
	 }
	 else {
		  cout << "Reservation cancelled." << endl;
	 }
}

void cancelReservation() {
	 cout << "___________________\n";
	 int i = 1;
	 cout << "Your reservations are:\n";

	 for (Slot& slot : userList[loginIndex].myReservations) {
		  cout << i << '-' << slot.courtName << "\tDate: " << slot.date << "\tTime: " << slot.startTime << endl;
		  i++;
	 }

	 cout << "Enter the number of the reservation you want to cancel: ";
	 int reservationNumber;
	 cin >> reservationNumber; //infinte

	 if (reservationNumber < 1 || reservationNumber > userList[loginIndex].myReservations.size()) {
		  cout << "Invalid reservation number." << endl;
		  return;
	 }

	 Slot& selectedSlot = userList[loginIndex].myReservations[reservationNumber - 1];
	 if (selectedSlot.date == getCurrentDate_MM_DD_YYYY()) {
		  int hourDiff = getHourDifferenceFromNow(selectedSlot.startTime);
		  if (hourDiff < 4) {
			   cout << "You cannot cancel a reservation within 1 hour of the start time." << endl;
			   return;
		  }

	 }
	 // Find the corresponding court
	 int courtIndex = searchCourt(selectedSlot.courtName);
	 for (int i = 0; i < courtList[courtIndex].slots.size(); i++) {
		  if (courtList[courtIndex].slots[i].ID == selectedSlot.ID) {
			   // Remove the slot from the court's list
			   courtList[courtIndex].slots.erase(courtList[courtIndex].slots.begin() + i);
			   break;
		  }
	 }
	 // Remove the reservation from the user's list
	 userList[loginIndex].myReservations.erase(userList[loginIndex].myReservations.begin() + reservationNumber - 1);
	 cout << "Reservation cancelled successfully." << endl;


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
bool isNameValid(string name) {
	 for (int i = 0; i < name.size(); i++) {
		  if (!isalpha(name[i])) {
			   return false;
		  }
	 }
	 return true;
}

bool isBirthdayValid(string bday) {
	 if (bday.size() != 10) return false;
	 if (bday[2] != '/' || bday[5] != '/') return false;
	 for (int i = 0; i < bday.size(); ++i) {
		  if ((i != 2 && i != 5) && !isdigit(bday[i])) {
			   return false;
		  }
	 }
	 if (bday[0] < '0' || bday[0] > '1' || (bday[0] == '1' && bday[1] > '2')) return false;
	 if (bday[3] < '0' || bday[3] > '3' || (bday[3] == '3' && bday[4] > '1')) return false;
	 return true;
}
unordered_map<string, GymClasses> Subscriptions::getAvailableClasses() {
	extern unordered_map<string, GymClasses> gymClassesList;
	unordered_map<string, GymClasses> filteredClasses;
	string subscriptionType = getType();
	bool isVIP = get_is_VIP();



	for (const auto& pair : gymClassesList) {
		const GymClasses& gymClass = pair.second;
		if (find(gymClass.allowedSubTypes.begin(), gymClass.allowedSubTypes.end(), subscriptionType) != gymClass.allowedSubTypes.end()) {
			cout << gymClass.className << endl;
			filteredClasses[pair.first] = gymClass;
		}
	}



	if (isVIP) {
		if (subscriptionType == "1 month") {
			cout << "VIP Yoga - Private Session" << endl;
			cout << "VIP Zumba - Private Session" << endl;
		}
		else if (subscriptionType == "3 month") {
			cout << "VIP Pilates - Private Session" << endl;
			cout << "VIP Crossfit - Expert Trainer" << endl;
		}
		else if (subscriptionType == "6 month") {
			cout << "VIP Strength Training - Personal Coach" << endl;
			cout << "VIP HIIT - High-Intensity Class" << endl;
		}
		else if (subscriptionType == "1 year") {
			cout << "VIP Yoga - Exclusive" << endl;
			cout << "VIP Crossfit - Elite Coaching" << endl;
			cout << "VIP Zumba - Personal Trainer" << endl;
		}
	}

	return filteredClasses;
}


bool User::registerMember() {
	 string id, Name, Email, password, bday, sub;
	 extern unordered_map<string, User> userList;
	 cout << "====================================\n";
	 cout << "   Welcome to ysm GYM SYSTEM   \n";
	 cout << "====================================\n";
	 string subType;
	 char vipChoice;

	 bool isVip = false;
	 while (true) {
		  cout << "Enter your Name: ";
		  cin >> Name;
		  if (!isNameValid(Name)) {
			   cout << "Invalid name. Use letters and spaces only.\n";
		  }
		  else break;
	 }

	 while (true) {
		  cout << "Enter Email: ";
		  cin >> Email;
		  if (!isEmailCorrect(Email))
			   cout << "Invalid format. Must contain '@' and end with '.com'.\n";
		  else if (!isEmailUnique(Email))
			   cout << "Email already exists. Try another.\n";
		  else break;
	 }

	 cout << "Enter Password: ";
	 cin >> password;
	 while (true) {
		  cout << "Enter Birthday (MM/DD/YYYY): ";
		  cin >> bday;
		  if (!isBirthdayValid(bday)) {
			   cout << "Invalid birthday format.\n";
		  }
		  else break;
	 }
	 int subChoice;
	 while (true) {
		  cout << "\nChoose a Subscription:\n";
		  cout << "1. 1 Month\n";
		  cout << "2. 3 Months\n";
		  cout << "3. 6 Months\n";
		  cout << "4. 1 Year\n";
		  cout << "Enter choice (1-4): ";
		  cin >> subChoice;

		  switch (subChoice) {
		  case 1: subType = "1 month"; break;
		  case 2: subType = "3 month"; break;
		  case 3: subType = "6 month"; break;
		  case 4: subType = "1 year"; break;
		  default:
			   cout << "Invalid choice. Try again.\n";
			   continue;
		  }
		  break;
	 }
	 cout << "Do you want VIP benefits for extra features? (y/n): ";
	 cin >> vipChoice;
	 if (vipChoice == 'y' || vipChoice == 'Y') {
		  isVip = true;
	 }
	 Subscriptions userSub(subType, time(0), isVip);
	 userSub.getAvailableClasses();

	 double price = userSub.getPrice();
	 cout << "Total Price: $" << price << endl;
	 id = "M" + to_string(++baseID);
	 cout << "Your ID is: " << id << "\n";
	 User newUser;
	 newUser.ID = id;
	 newUser.name = Name;
	 newUser.email = Email;
	 newUser.password = password;
	 newUser.Brithday = bday;
	 newUser.subscription = userSub;
	 newUser.classEntered = 0;
	 userList[id] = newUser;
	 cout << "Member registered successfully.\n";
	 return true;
}
bool Staff::registerStaff() {
	 string Name, Email, Password, phonenumber, Role, id;
	 extern unordered_map<string, Staff> staffList;
	 while (true) {
		  cout << "Enter your Name: ";
		  cin >> Name;
		  if (!isNameValid(Name)) {
			   cout << "Invalid name. Use letters and spaces only.\n";
		  }
		  else break;
	 }
	 while (true) {
		  cout << "Enter Email: ";
		  cin >> Email;
		  if (!isEmailCorrect(Email))
			   cout << "Invalid format. Must contain '@' and end with '.com'.\n";
		  else if (!isEmailUnique(Email))
			   cout << "Email already exists. Try another.\n";
		  else break;
	 }
	 cout << "Enter password: ";
	 cin >> Password;
	 while (true) {
		  cout << "Enter phone number (at least 11 digits): ";
		  cin >> phonenumber;
		  if (phonenumber.length() < 11) {
			   cout << "Phone number must be at least 11 digits.\n";
		  }
		  else break;
	 }
	 cout << "Enter role (Coach/Reception): ";
	 cin >> Role;

	 Staff newStaff;
	 newStaff.name = Name;
	 newStaff.email = Email;
	 newStaff.password = Password;
	 newStaff.phone = phonenumber;
	 newStaff.role = Role;
	 if (Role == "Reception" || Role == "reception") {
		  cout << "Reception staff cannot assign classes.\n";
		  id = "R" + to_string(++baseID);
		  cout << "Reception staff registered successfully.\n";
	 }
	 else if (Role == "Coach" || Role == "coach") {
		  id = "C" + to_string(++baseID);
		  cout << "Coach staff registered successfully.\n";
	 }
	 else {
		  cout << "Invalid role entered.\n";
		  return false;
	 }
	 newStaff.ID = id;
	 staffList[id] = newStaff;
	 cout << "Staff registered successfully. Your ID is: " << id << "\n";
	 return true;
}
User Staff::searchUserByID(string userID) {
	 extern unordered_map<string, User> userList;
	 if (loginIndex == "") {
		  cout << "You must be logged in as a staff to search for users.\n";
		  return User();
	 }
	 unordered_map<string, User>::iterator it = userList.find(userID);
	 if (it != userList.end()) {
		  return it->second;
	 }
	 cout << "User with ID " << userID << " not found.\n";
	 return User();
}
//*//
Subscriptions::Subscriptions(string _type, time_t st_date, bool vip) {
	 type = _type;
	 start_date = st_date;
	 is_VIP = vip;
	 price = getPrice();
	 end_date = calaculateEndDate();

}
time_t Subscriptions::calaculateEndDate() {
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


Subscriptions::Subscriptions() : type(""), start_date(0), end_date(0),
is_VIP(false), price(0.0), isActivated(false) {
}
double Subscriptions::getPrice() {
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

bool Subscriptions::isActive() {
	 time_t current_date = time(0);
	 return(current_date >= start_date && current_date <= end_date);
}
string Subscriptions::getType() {
	 return type;
}
bool Subscriptions::get_is_VIP() {
	 return is_VIP;
}
void Staff::generateMonthlyReport() {        //Bounce (only manager can generate and access reports)
	 if (!(role == "manager" || role == "Manager"))
	 {
		  cout << "\033[1;31mSorry!! only managers can access reports\033[0m\n ";
		  return;
	 }
	 time_t currentDate = time(0);
	 tm localTime;
	 localtime_s(&localTime, &currentDate);
	 int currentYear = localTime.tm_year + 1900;
	 int currentMonth = localTime.tm_mon + 1;
	 cout << "\n=================Monthly Report for ";
	 if (currentMonth < 10)
		  cout << "0";
	 cout << currentMonth << "-" << currentYear << "=================\n";
	 vector<User> activeUsers;
	 double totalRevenue = 0.0;
	 map<string, pair<int, double>>SubscriptionState;

	 for (auto& entry : userList) { //*
		  User& user = entry.second;
		  if (user.subscription.isActive()) {
			   activeUsers.push_back(user);

			   string type = user.subscription.getType();
			   double price = user.subscription.getPrice();

			   SubscriptionState[type].first += 1;
			   SubscriptionState[type].second += price;
			   totalRevenue += price;
		  }
	 }

	 sort(activeUsers.begin(), activeUsers.end(), Staff::comparingActivity);

	 cout << "\033[1;35m>>Most active members:\n\033[0m ";
	 cout << "----------------------------------------------------------\n";
	 cout << "\033[1;36mName\t\tid\tnumber of classes attended\tVIP\n\033[0m";

	 int numberOfmembers = min(10, static_cast<int>(activeUsers.size()));
	 for (int i = 0; i < numberOfmembers; ++i) {
		  cout << activeUsers[i].name << "\t\t" << activeUsers[i].ID << "\t\t" << activeUsers[i].classEntered << "\t\t\t";
		  cout << (activeUsers[i].subscription.get_is_VIP() ? "YES\n" : "NO\n");
	 }

	 cout << "----------------------------------------------------------\n";
	 cout << "\033[1;35m>>Subscription Summary by Type:\n\033[0m";
	 cout << "----------------------------------------------------------\n";

	 for (auto it = SubscriptionState.begin(); it != SubscriptionState.end(); ++it) {
		  cout << "\033[1;36mNumber of subscriptions at " << it->first
			   << " plan:\033[0m " << it->second.first << " users | "
			   << it->second.second << " EGP\n";
	 }
	 cout << "===========================================================\n";
	 cout << "\033[1;35m>>Total Subscription Revenue this Month:\033[0m\n " << totalRevenue << " EGP\n";
	 cout << "===========================================================\n";
}
void Subscriptions::set_is_VIP(bool vip) {
	 is_VIP = vip;
}

void newSubChoice(User& user) {
	 int subChoice;
	 string subType;
	 while (true) {
		  cout << "\033[1;36mChoose a new Subscription:\n\033[0m";
		  cout << "1. 1 Month\n";
		  cout << "2. 3 Months\n";
		  cout << "3. 6 Months\n";
		  cout << "4. 1 Year\n";
		  cout << "\033[1;35mEnter choice (1-4):\033[0m ";
		  cin >> subChoice;

		  switch (subChoice) {
		  case 1: subType = "1 month"; break;
		  case 2: subType = "3 month"; break;
		  case 3: subType = "6 month"; break;
		  case 4: subType = "1 year"; break;
		  default:
			   cout << "Invalid choice. Try again.\n";
			   continue;
		  }
		  break;
	 }

	 char vipChoice;
	 bool isVip = false;
	 cout << "\033[1;35mDo you want VIP benefits for extra features? (y/n): \033[0m";
	 cin >> vipChoice;
	 if (vipChoice == 'y' || vipChoice == 'Y') {
		  isVip = true;
	 }

	 Subscriptions newSub(subType, time(0), isVip);
	 user.subscription = newSub;
	 double cost = user.subscription.getPrice();
	 if (paymentChecking(cost)) {
		  cout << "\nSubscription successfully renewed for " << user.name << endl;
		  cout << "\033[1;36mNew Subscription:\033[0m " << subType << (isVip ? " (VIP)" : "") << endl;
		  time_t endDay = user.subscription.calaculateEndDate();
		  //cout << "Valid until: " << ctime(&endDay) << endl;
		  char buffer[26];
		  ctime_s(buffer, sizeof(buffer), &endDay);
		  cout << "\033[1;36mValid until:\033[0m " << buffer << endl;

	 }
}
template<typename T>
void RenewSubscription(T userOrStaff) {
	 extern unordered_map<string, User> userList;
	 extern unordered_map<string, Staff> staffList;

	 if (loginIndex == "") {
		  cout << "\033[1;31mSorry! You must be logged in as a manager or receptionist to renew subscriptions.\n\033[0m";
		  return;
	 }

	 string targetID;
	 cout << "Enter member ID to renew: ";
	 cin >> targetID;

	 if constexpr (is_same<T, Staff>::value) {
		  if (userOrStaff.role == "Manager" || userOrStaff.role == "manager" ||
			   userOrStaff.role == "Reception" || userOrStaff.role == "reception") {

			   if (userList.find(targetID) != userList.end()) {
					newSubChoice(userList[targetID]);
					return;
			   }
			   else {
					cout << "User not found.\n";
			   }
		  }
		  else {
			   cout << "\033[1;31mYou do not have permission to renew subscriptions.\n\033[0m";
		  }
	 }

	 else if constexpr (is_same<T, User>::value) {
		  if (userOrStaff.ID == targetID) {
			   newSubChoice(userOrStaff);
			   return;
		  }
		  else {
			   cout << "You can only renew your own subscription.\n";
		  }
	 }
}

bool isTimeOverlap(string start1, string end1, string start2, string end2) {
	 return !(end1 <= start2 || start1 >= end2);
}

bool isCoachAvailable(Staff coach, string date, string startTime, string endTime) {
	 extern unordered_map<string, GymClasses> gymClassesList;
	 for (auto pair : gymClassesList) {
		  GymClasses cls = pair.second;
		  if (cls.coachName.ID == coach.ID && cls.date == date) {
			   if (isTimeOverlap(cls.startTime, cls.endTime, startTime, endTime)) {
					return false;
			   }
		  }
	 }
	 return true;
}


GymClasses Staff::createClass() {
	extern unordered_map<string, GymClasses> gymClassesList;
	extern unordered_map<string, Staff> staffList;
	if (loginIndex == "") {
		cout << "You must be logged in to create classes.\n";
		return GymClasses();
	}
	if (role != "Manager" && role != "manager") {
		cout << "Only a manager can create classes.\n";
		return GymClasses();
	}

	GymClasses newClass;
	while (true) {
		cout << "Enter class name: ";
		cin.ignore();
		getline(cin, newClass.className);
		if (!isNameValid(newClass.className)) {
			cout << "Invalid class name. Use letters and spaces only.\n";
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Enter class date (MM/DD/YYYY): ";
		cin >> newClass.date;
		if (!isBirthdayValid(newClass.date)) {
			cout << "Invalid date format.\n";
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Enter class start time (HH:MM): ";
		cin >> newClass.startTime;
		if (!isValidTimeFormat(newClass.startTime)) {
			cout << "Invalid time format.\n";
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Enter class end time (HH:MM): ";
		cin >> newClass.endTime;
		if (!isValidTimeFormat(newClass.endTime)) {
			cout << "Invalid time format.\n";
		}
		else if (newClass.endTime <= newClass.startTime) {
			cout << "End time must be after start time.\n";
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "Enter the maximum number of members: ";
		cin >> newClass.maxMembers;
		if (newClass.maxMembers <= 0) {
			cout << "Invalid number of members. Must be greater than 0.\n";
		}
		else {
			break;
		}
	}
	while (true) {
		Staff coachInput;
		cout << "Enter instructor (coach) name: ";
		cin.ignore();
		getline(cin, coachInput.name);
		cout << "Enter instructor (coach) ID: ";
		cin >> coachInput.ID;
		bool found = false;
		for (auto& pair : staffList) {
			if (pair.second.name == coachInput.name && pair.second.ID == coachInput.ID &&
				(pair.second.role == "Coach" || pair.second.role == "coach")) {
				if (!isCoachAvailable(pair.second, newClass.date, newClass.startTime, newClass.endTime)) {
					cout << "This coach already has another class at this time.\n";
					return GymClasses();
				}
				newClass.coachName = pair.second;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Coach not found in staff list or not a coach.\n";
		}
		else break;

	}

	cout << "Select subscription types allowed to enroll (enter numbers, 0 to finish):\n";
	cout << "1. 1 Month\n2. 3 Months\n3. 6 Months\n4. 1 Year\n";
	int subChoice;
	while (true) {
		cout << "Enter choice (1-4, 0 to finish): ";
		cin >> subChoice;
		if (subChoice == 0) break;
		string subType;
		switch (subChoice) {
		case 1: subType = "1 month"; break;
		case 2: subType = "3 month"; break;
		case 3: subType = "6 month"; break;
		case 4: subType = "1 year"; break;
		default:
			cout << "Invalid choice. Try again.\n";
			continue;
		}
		// Add to allowed types if not already in
		if (find(newClass.allowedSubTypes.begin(), newClass.allowedSubTypes.end(), subType) == newClass.allowedSubTypes.end()) {
			newClass.allowedSubTypes.push_back(subType);
			//	newClass.usersEnrolled[subType] = vector<User>(); // Initialize vector for enrolled users
		}
	}

	newClass.currentMembersCount = 0;
	newClass.classID = newClass.generateUniqueID();
	gymClassesList[newClass.classID] = newClass;
	cout << "Class created successfully with ID: " << newClass.classID << "\n";
	return newClass;
}

void Staff::displayCoachClasses(string coachID = "")
{
	//extern unordered_map<string, GymClasses> gymClassesList;
	//extern unordered_map<string, Staff> staffList;

	if (role == "Coach" || role == "coach") {
		coachID = ID;
	}
	else if ((role == "Manager" || role == "manager" ||
		role == "Reception" || role == "reception") && coachID.empty()) {
		cout << "\033[1;35mEnter Coach ID: \033[0m";
		cin >> coachID;
	}

	if (staffList.find(coachID) == staffList.end() ||
		(staffList[coachID].role != "Coach" && staffList[coachID].role != "coach")) {
		cout << "\033[1;31mError: Coach with ID " << coachID
			<< " not found or not a coach.\033[0m\n";
		return;
	}
	cout << "\n\033[1;35m=== Classes for Coach " << staffList[coachID].name
		<< " (ID: " << coachID << ") ===\033[0m\n";
	cout << "----------------------------------------------------------\n";

	bool hasClasses = false;
	unordered_map<string, GymClasses>::iterator it;
	for (it = gymClassesList.begin(); it != gymClassesList.end(); ++it) {
		GymClasses gymClass = it->second;

		if (gymClass.coachName.ID == coachID) {
			hasClasses = true;
			cout << "\033[1;36mClass ID:\033[0m " << gymClass.classID << "\n";
			cout << "\033[1;36mClass Name:\033[0m " << gymClass.className << "\n";
			cout << "\033[1;36mDate:\033[0m " << gymClass.date << "\n";
			cout << "\033[1;36mTime:\033[0m " << gymClass.startTime << " - " << gymClass.endTime << "\n";
			cout << "\033[1;36mcurrentMembersCount: \033[0m" << gymClass.currentMembersCount
				<< "\t" << "\033[1;36mmaxMembers: \033[0m" << gymClass.maxMembers << "\n";
			cout << "\033[1;36mStatus:\033[0m " << (gymClass.isFull() ? "Full" : "Available") << "\n";

			cout << "\033[1;36mEnrolled Members:\033[0m\n";
			if (gymClass.usersEnrolled.empty()) {
				cout << "  No members enrolled\n";
			}
			else {
				unordered_map<string, vector<User>>::iterator subit;
				for (subit = gymClass.usersEnrolled.begin(); subit != gymClass.usersEnrolled.end(); ++subit) {
					cout << "  " << subit->first << " Subscription:\n";
					if (subit->second.empty()) {
						cout << "No members\n";
					}
					else {
						for (int i = 0; i < subit->second.size(); ++i) {
							User user = subit->second[i];
							cout << "member name is" << "\t" << user.name << "\t" << " ID: " << user.ID << endl;
						}

					}
				}
			}
			cout << "\033[1;36mWaiting List:\033[0m\n";
			if (gymClass.waitingList.empty()) {
				cout << " No members in waiting list\n";
			}
			else {
				for (int i = 0; i < gymClass.waitingList.size(); ++i) {
					cout << "member name in waitingList" << "\t" << gymClass.waitingList[i].name << "\t" << "ID: " << gymClass.waitingList[i].ID << endl;
				}
			}

			cout << "----------------------------------------------------------\n";
		}
	}

	if (!hasClasses) {
		cout << "\033[1;33mNo classes assigned to this coach.\033[0m\n";
	}
}

bool GymClasses::isFull() {
	 return currentMembersCount >= maxMembers;
}

void viewWaitingListEachclass() {
	 cout << "___________________\n";
	 cout << "Waiting list for each class:\n";

	 for (auto it = gymClassesList.begin(); it != gymClassesList.end(); it++) {
		  cout << "Class: " << it->second.className << endl;
		  cout << "Waiting List:" << endl;
		  for (User& user : it->second.waitingList) {
			   cout << user.name << endl;
		  }
		  cout << endl;
	 }
}
void notifyExpiringSubscriptions( string& staffID) {
	extern unordered_map<string, Staff> staffList;
	extern unordered_map<string, User> userList;

	auto staffIt = staffList.find(staffID);
	if (staffIt == staffList.end() || staffIt->second.role != "Manager" && staffIt->second.role != "manager") {
		cout << "Access denied. Only Managers can send notifications.\n";
		return;
	}

	time_t now = time(0);
	const int warningDays = 5;

	for (auto& pair : userList) {
		User& user = pair.second;
		time_t endDate = user.subscription.calaculateEndDate();
		double daysLeft = difftime(endDate, now) / (60 * 60 * 24);

		if (daysLeft <= warningDays && user.subscription.isActive()) {
			string msg = "Reminder: Your subscription is about to expire in " + to_string((int)daysLeft) + " day(s). Please renew.";
			cout << "Sending to " << user.email << ": " << msg << endl;

		}
		else if (user.subscription.IsExpired()) {
			string msg = "Your subscription has expired. Please renew to continue enjoying our services.";
			cout << "Sending to " << user.email << ": " << msg << endl;

		}
	}
}
void deleteUser_and_cancelsubscription(string& userID) {
	extern unordered_map<string, User> userList;

	auto it = userList.find(userID);
	if (it == userList.end()) {
		cout << "User not found.\n";
		return;
	}

	userList.erase(it);
	cout << "User " << userID << " has been removed from the system.\n";
}
void User::displayUserEnrolledClasses() {  //    علشان دي تشتغل  صحgymClassesList  تبقي لينكد مع enrollClass Function لازم ال  
	extern unordered_map<string, GymClasses> gymClassesList;
	bool hasClasses = false;
	cout << "\n=== Enrolled Classes for " << name << " (ID: " << ID << ") ===\n";
	cout << "----------------------------------------------------------\n";
	for (auto& pair : gymClassesList) {
		GymClasses& gymClass = pair.second;
		for (auto& subPair : gymClass.usersEnrolled) {
			for (User& user : subPair.second) {
				if (user.ID == ID) {
					hasClasses = true;
					cout << "Class ID: " << gymClass.classID << "\n";
					cout << "Class Name: " << gymClass.className << "\n";
					cout << "Coach: " << gymClass.coachName.name << "\n";
					cout << "Date: " << gymClass.date << "\n";
					cout << "Time: " << gymClass.startTime << " - " << gymClass.endTime << "\n";
					cout << "Status: " << (gymClass.isFull() ? "Full" : "Available") << "\n";
					cout << "----------------------------------------------------------\n";
				}
			}
		}
	}
	if (!hasClasses)
		cout << "No classes enrolled.\n";
	cout << "----------------------------------------------------------\n";
}
void main() {

	 // readCreditCardData();
	 // readPadelCourt();
	  // cout << courtList[0].slots.size() << endl;
	 // reserveCourt();
	 cout << " g\033[0mg";

	

}
