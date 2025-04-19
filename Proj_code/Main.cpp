#include "Structure.h"
#include <regex>
#include <iomanip>
#include<map>
#include<algorithm>


int indexOfUser = -1; // -1 means not logged in
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
	 extern vector<User> userList;
	 for (int i = 0; i < userList.size(); ++i) {
		  if (userList[i].email == email) {
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

void logout()
{
	loginIndex = -1;
	cout << "You have been logged out successfully.\n";
}

vector<GymClasses> Subscriptions::getAvailableClasses() {
	extern vector<GymClasses> gymClassesList;
	string subscriptionType = getType();
	bool isVIP = get_is_VIP();
	if (gymClassesList.empty()) {
		GymClasses yoga; yoga.className = "Yoga";
		GymClasses cardio; cardio.className = "Cardio";
		GymClasses pilates; pilates.className = "Pilates";
		GymClasses zumba; zumba.className = "Zumba";
		GymClasses spin; spin.className = "Spin";
		GymClasses stretching; stretching.className = "Stretching";
		GymClasses strength; strength.className = "Strength Training";
		GymClasses hiit; hiit.className = "HIIT";
		GymClasses cycling; cycling.className = "Cycling";
		GymClasses boxing; boxing.className = "Boxing";
		GymClasses crossfit; crossfit.className = "Crossfit";

		gymClassesList = { yoga, cardio, pilates, zumba, spin, stretching,
						   strength, hiit, cycling, boxing, crossfit };
	}
	if (subscriptionType == "1 month") {
		for (int i = 0; i < gymClassesList.size(); i++) {
			if (gymClassesList[i].className == "Yoga" || gymClassesList[i].className == "Cardio" || gymClassesList[i].className == "Stretching") {
				cout << gymClassesList[i].className << endl;
			}
		}
	}
	else if (subscriptionType == "3 month") {
		for (int i = 0; i < gymClassesList.size(); i++) {
			if (gymClassesList[i].className == "Yoga" || gymClassesList[i].className == "Cardio" || gymClassesList[i].className == "Pilates" ||
				gymClassesList[i].className == "Zumba" || gymClassesList[i].className == "Spin") {
				cout << gymClassesList[i].className << endl;
			}
		}
	}
	else if (subscriptionType == "6 month") {
		for (int i = 0; i < gymClassesList.size(); i++) {
			if (gymClassesList[i].className == "Yoga" || gymClassesList[i].className == "Cardio" || gymClassesList[i].className == "Pilates" ||
				gymClassesList[i].className == "Zumba" || gymClassesList[i].className == "Strength Training" || gymClassesList[i].className == "HIIT") {
				cout << gymClassesList[i].className << endl;
			}
		}
	}
	else if (subscriptionType == "1 year") {
		for (int i = 0; i < gymClassesList.size(); i++) {
			if (gymClassesList[i].className == "Yoga" || gymClassesList[i].className == "Cardio" || gymClassesList[i].className == "Pilates" ||
				gymClassesList[i].className == "Zumba" || gymClassesList[i].className == "Strength Training" || gymClassesList[i].className == "HIIT" ||
				gymClassesList[i].className == "Cycling" || gymClassesList[i].className == "Boxing" || gymClassesList[i].className == "Crossfit") {
				cout << gymClassesList[i].className << endl;
			}
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

	return gymClassesList;
}

bool User::registerMember() {
	string id, name, email, password, bday, sub;
	extern vector<User> userList;
	cout << "====================================\n";
	cout << "   Welcome to ysm GYM SYSTEM   \n";
	cout << "====================================\n";
	string subType;
	char vipChoice;

	bool isVip = false;
	while (true) {
		cout << "Enter your Name: ";
		cin >> name;
		if (!isNameValid(name)) {
			cout << "Invalid name. Use letters and spaces only.\n";
		}
		else break;
	}

	while (true) {
		cout << "Enter Email: ";
		cin >> email;
		if (!isEmailCorrect(email))
			cout << "Invalid format. Must contain '@' and end with '.com'.\n";
		else if (!isEmailUnique(email))
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
	newUser.name = name;
	newUser.email = email;
	newUser.password = password;
	newUser.Brithday = bday;
	newUser.subscription = userSub;
	newUser.classEntered = 0;
	userList.push_back(newUser);
	cout << "Member registered successfully.\n";
	return true;
}
User* Staff::searchUserByID(string userID) {
	 if (loginIndex == -1) {
		  cout << "You must be logged in as a staff to search for users." << endl;
		  return nullptr;
	 }

	 for (int i = 0; i < userList.size(); i++) {
		  if (userList[i].ID == userID) {
			   return &userList[i];
		  }
	 }

	 return nullptr;
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


Subscriptions::Subscriptions() : type(""), start_date(0), end_date(0), is_VIP(false), price(0.0) {}
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

	 for (int i = 0; i < userList.size(); ++i) {
		  if (userList[i].subscription.isActive()) {
			   activeUsers.push_back(userList[i]);
			   string type = userList[i].subscription.getType();
			   double price = userList[i].subscription.getPrice();
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
		  if (activeUsers[i].subscription.get_is_VIP())
			   cout << "YES\n";
		  else cout << "NO\n";
	 }
	 cout << "----------------------------------------------------------\n";
	 // Revenue and subscription stats
	 cout << "\033[1;35m>>Subscription Summary by Type:\n\033[0m";
	 cout << "----------------------------------------------------------\n";
	 map<string, pair<int, double> >::iterator it;
	 for (it = SubscriptionState.begin(); it != SubscriptionState.end(); ++it) {
		  cout << "\033[1;36mNumber of subscriptions at " << it->first << " plan:\033[0m " << it->second.first << " users | " << it->second.second << " EGP\n";
	 }
	 cout << "===========================================================\n";
	 // Total revenue
	 cout << "\033[1;35m>>Total Subscription Revenue this Month:\033[0m\n " << totalRevenue << " EGP\n";
	 cout << "===========================================================\n";
}
void Subscriptions::set_is_VIP(bool vip) {
	 is_VIP = vip;
}

void newSubChoice(User user) { 
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
void RenewSubscription(T userORstaff) {
	if (loginIndex == -1) {
		cout << "\033[1;31mSorry! you must be logged in as a manager or reception to renew members subscriptions\n\033[0m ";
		return;
	}
	string userID;
	cout << "Enter user id\n";
	cin >> userID;
	if constexpr (is_same<T, Staff>::value) {
		if (userORstaff.role == "manager" || userORstaff.role == "Manager" || userORstaff.role == "Reciption" || userORstaff.role == "reciption") {
			for (int i = 0; i < userList.size(); ++i) {
				if (userList[i].ID == userID) {
					newSubChoice(userList[i]); 
					return;
				}
			}
		}
		else {
			cout << "\033[1;31mSorry! You do not have permission to renew subscriptions. Only reception and manager roles are allowed.\n\033[0m";
			return;
		}
	}
	else if constexpr (is_same<T, User>::value) {
		if (userList[loginIndex].ID == userID) {
			newSubChoice(userList[loginIndex]); 
			return;
		}
		else {
			cout << "You can only renew your own subscription.\n";
			return;
		}
	}
}


//void viewWaitingListEachclass() {
//	 cout << "___________________\n";
//	 cout << "Waiting list for each class:\n";
//	 for (GymClasses& gymClass : gymClassesList) {
//		  cout << "Class: " << gymClass.className << endl;
//		  cout << "Waiting List:" << endl;
//		  for (User& user : gymClass.waitingList) {
//			   cout << user.name << endl;
//		  }
//		  cout << endl;
//	 }
//}




void main() {

	 // readCreditCardData();
	 // readPadelCourt();
	  // cout << courtList[0].slots.size() << endl;
	 // reserveCourt();
	 cout << " g\033[0mg";
	 
	
}
