#include "Structure.h"
#include <regex>
#include <iomanip>


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



void main() {

	 // readCreditCardData();
	 // readPadelCourt();
	  // cout << courtList[0].slots.size() << endl;
	 // reserveCourt();
	 string date1 = "04/12/2005";
	 string date2 = "04/12/2004";
	
	 
}
