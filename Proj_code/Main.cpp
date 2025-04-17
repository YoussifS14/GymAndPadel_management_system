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
	 tm* localTime = localtime(&now);

	 ostringstream dateStream;
	 dateStream << setfill('0') << setw(2) << (localTime->tm_mon + 1) << "/"
		  << setfill('0') << setw(2) << localTime->tm_mday << "/"
		  << (localTime->tm_year + 1900);

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

void payment(float cost) {
	 CreditCard card;
	 cout << "Enter card ID: ";
	 cin >> card.cardID;
	 cout << "Enter card CVV: ";
	 cin >> card.cardCVV;
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

bool paymentChecking(float cost) {
	CreditCard card;
	cout << "Enter card ID: ";
	cin >> card.cardID;
	cout << "Enter card CVV: ";
	cin >> card.cardCVV;
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

void updateClassMembers() {
	 string className;
	 cout << "Enter the name of the class: ";
	 cin.ignore();
	 getline(cin, className);
	 for (GymClasses& gymClass : gymClassesList) {
		  if (gymClass.className == className) {
			   if (gymClass.members.size() < gymClass.maxMembers) {
					User temp = gymClass.waitingList.front();
					gymClass.waitingList.pop_front();
					gymClass.members.push_back(temp);
			   
			   }
			   return;
		  }
	 }
	 cout << "Class not found." << endl;
}

void viewWaitingListEachclass() {
	 cout << "___________________\n";
	 cout << "Waiting list for each class:\n";
	 for (GymClasses& gymClass : gymClassesList) {
		  cout << "Class: " << gymClass.className << endl;
		  cout << "Waiting List:" << endl;
		  for (User& user : gymClass.waitingList) {
			   cout << user.name << endl;
		  }
		  cout << endl;
	 }
}
template <typename T>
void renewSubscription(T& entity) {  // user can renew for himself and can also ask the reception to renew it for him
	if (loginIndex == -1) {
		cout << "\033[1;31mSorry! you must be logged in as a manager or reception to renew members subscriptions\n\033[0m ";
		return;
	}

	string userID;
	cout << "\033[1;35mEnter the member ID to renew the subscription.\n\033[0m";
	cout << "==============================================================\n";
	cin >> userID;

	User* user = nullptr;
	if constexpr (std::is_same<T, Staff>::value) {
		Staff& staff = static_cast<Staff&>(entity);

		// Only allow managers and receptionists to renew subscriptions for others
		if (staff.role != "manager" && staff.role != "Manager" && staff.role != "reception" && staff.role != "Reception") {
			cout << "\033[1;31mSorry! You do not have permission to renew subscriptions. Only reception and manager roles are allowed.\n\033[0m";
			return;
		}
		user = staff.searchUserByID(userID); // Search for user by ID if the staff is logged in
	}
	else if constexpr (std::is_same<T, User>::value) {
		// If the entity is User, assume the logged-in user is the one renewing their subscription
		user = &entity;
	}

	// Ensure the user exists
	if (user == nullptr) {
		cout << "There is no current subscription for user with ID: " << userID << endl;
		return;
	}

	bool isStaff = false;
	if constexpr (std::is_same<T, Staff>::value) {
		Staff& staff = static_cast<Staff&>(entity);
		isStaff = (staff.role == "manager" || staff.role == "Manager" || staff.role == "reception" || staff.role == "Reception");
	}

	// Ensure that the logged-in user is either renewing their own subscription or is allowed to do so as staff
	if (!isStaff && userList[loginIndex].ID != userID) {
		cout << "You can only renew your own subscription.\n";
		return;
	}

	cout << "Current Subscription: " << user->subscription.getType() << (user->subscription.get_is_VIP() ? " (VIP)" : "") << endl;

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
	user->subscription = newSub;
	float cost = static_cast<float>(user->subscription.getPrice());
	if (paymentChecking(cost)) {
		cout << "\nSubscription successfully renewed for " << user->name << endl;
		cout << "\033[1;36mNew Subscription:\033[0m " << subType << (isVip ? " (VIP)" : "") << endl;
		time_t endDay = user->subscription.calaculateEndDate();
		//cout << "Valid until: " << ctime(&endDay) << endl;
		char buffer[26];
		ctime_s(buffer, sizeof(buffer), &endDay);
		cout << "\033[1;36mValid until:\033[0m " << buffer << endl;

	}
}


void main() {

	 // readCreditCardData();
	 // readPadelCourt();
	  // cout << courtList[0].slots.size() << endl;
	 // reserveCourt();
	 string date1 = "04/12/2005";
	 string date2 = "04/12/2004";
	 time_t currentTime = time(nullptr);
	 
	
}
