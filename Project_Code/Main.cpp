#include "LoginPage.h"


using namespace System;
using namespace System::Windows::Forms;
int Slot::slotCounter = 1;

int Notification::notificationCounter = 1;

string loginID;
string PassCode = "null";//create by manager 
vector<CreditCard> cardList;
unordered_map<string, User> userList;
unordered_map<string, Staff> staffList;
unordered_map<string, GymClasses> gymClassList;
unordered_map<string, PadelCourt> courtList;
WorkoutManger workoutManager;
string defaultImagePath = "accPic/default.png";
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
		  getline(ss, staff.role, ',');       // add comma here!
		  getline(ss, staff.PicPath);         // last one, no comma

		  /*
		  loop to load myClass

		  */

		  staffList[staff.ID] = staff;

	 }
	 file.close();
}

void readGymClasses() {
	 ifstream file("Data/gymClasses.csv");
	 if (!file.is_open()) {
		  System::Diagnostics::Debug::WriteLine("Error: Could not open Data/gymClasses.csv");
		  return;
	 }

	 string line;
	 getline(file, line); // Skip header

	 while (getline(file, line)) {
		  try {
			   GymClasses gymClass;
			   stringstream ss(line);
			   string temp;

			   getline(ss, gymClass.classID, ',');
			   getline(ss, gymClass.className, ',');
			   getline(ss, gymClass.instructor, ',');
			   getline(ss, gymClass.instructorID, ',');
			   getline(ss, gymClass.startDate, ',');
			   getline(ss, gymClass.endDate, ',');

			   // Sessions
			   getline(ss, temp, ',');
			   stringstream sessionStream(temp);
			   string sessionEntry;
			   while (getline(sessionStream, sessionEntry, ';')) {
					size_t colonPos = sessionEntry.find(':');
					size_t dashPos = sessionEntry.find('-');
					if (colonPos != string::npos && dashPos != string::npos && dashPos > colonPos) {
						 Session s;
						 s.date = sessionEntry.substr(0, colonPos);
						 s.startTime = sessionEntry.substr(colonPos + 1, dashPos - colonPos - 1);
						 s.endTime = sessionEntry.substr(dashPos + 1);
						 gymClass.sessions.push_back(s);
					}
			   }

			   // Max Members
			   getline(ss, temp, ',');
			   gymClass.maxMembers = stoi(temp);

			   // Price
			   getline(ss, temp, ',');
			   gymClass.price = stof(temp);

			   // Allowed Subscription Types
			   getline(ss, temp, ',');
			   stringstream subStream(temp);
			   string subType;
			   while (getline(subStream, subType, ';')) {
					if (!subType.empty())
						 gymClass.allowedSubTypes.push_back(subType);
			   }

			   // Waiting List
			   getline(ss, temp);
			   stringstream waitingStream(temp);
			   string userID;
			   while (getline(waitingStream, userID, '!')) {
					if (!userID.empty())
						 gymClass.waitingList.push_back(userID);
			   }

			   // reschedule the class is expired
			   time_t currentTime = time(0);
			   time_t endTime = getTime_t(gymClass.endDate);
			   if (currentTime > endTime) {
					gymClass.startDate = User::getCurrentDate_MM_DD_YYYY();
					gymClass.members.clear();
					/*while (!gymClass.waitingList.empty()) {
						 string userID = gymClass.waitingList.front();
						 gymClass.waitingList.pop_front();
						 gymClass.members.push_back(userID);
					}*/
					gymClass.waitingList.clear();
					gymClass.endDate = gymClass.calculateEndDate(gymClass.startDate);
					// reshedule sessions 
					string oldStartTime = gymClass.sessions[0].startTime;
					string oldEndTime = gymClass.sessions[0].endTime;
					string startDate = gymClass.startDate;
					string endDate = gymClass.endDate;
					gymClass.sessions.clear();
					gymClass.generateRecurringSessions(startDate, endDate, oldStartTime, oldEndTime, gymClass.recurringDays);
					gymClass.reSchedule = true;
			   }

			   // Save class
			   gymClassList[gymClass.classID] = gymClass;
		  }
		  catch (const std::exception& e) {
			   System::Diagnostics::Debug::WriteLine("Error parsing line: " + marshal_as<String^>(line) + ", Exception: " + marshal_as<String^>(e.what()));
		  }
	 }

	 file.close();
}

void readUserData() {
	 readGymClasses();
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
		  getline(ss, user.Birthday, ',');
		  // getline(ss, user.classEnteredStr, ',');
		  string temp;
		  getline(ss, temp, ',');
		  stringstream subs(temp);
		  string startDate, endDate, S_Type;
		  bool is_VIP;

		  getline(subs, S_Type, '!');
		  getline(subs, startDate, '!');
		  getline(subs, endDate, '!');
		  getline(ss, user.PicPath, ',');
		  subs >> is_VIP;
		  Subscriptions subscription(S_Type, startDate, endDate, is_VIP);
		  user.subscription = subscription;

		  /*
		  loop to load myClass
		  */
		  string myClassStr;
		  getline(ss, myClassStr, ',');
		  stringstream myClassStream(myClassStr);
		  while (getline(myClassStream, myClassStr, '!')) {
			   string classID = myClassStr;
			   if (gymClassList.find(classID) != gymClassList.end()) {
					if (gymClassList[classID].reSchedule)
						 continue;
					user.myClasses.push_back(classID);
					gymClassList[classID].members.push_back(user.ID); // Add user to the class's member list

			   }

		  }
		  for (auto it : gymClassList) {
			   if (it.second.existInWaitingList(user.ID)) {
					user.myWaitingList.push_back(it.first);
			   }
		  }

		  ss >> user.myWallet;
		  userList[user.ID] = user;
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
		  getline(ss, court.ID, ',');
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
			   //   getline(ss, s.endTime);
			   Slot::slotCounter++;

			   court.slots.push_back(s);
		  }
		  courtList[court.ID] = court; // Use ID as key
	 }
	 padelFile.close();
}

void readNotfication() {
	 ifstream file("Data/msgSheet.csv");
	 string line;
	 getline(file, line); // Skip the header line
	 //userID,notif.ID,Date,Hour,className,type,isRead

	 while (getline(file, line)) {
		  stringstream ss(line);
		  string userID, NotifID, Date, hour, classname, type;
		  //User usr,string _ID,string _Date,string _hour,string cls,int type,bool _isRead
		  bool isRead = false;
		  getline(ss, userID, ',');
		  getline(ss, NotifID, ',');
		  getline(ss, Date, ',');
		  getline(ss, hour, ',');
		  getline(ss, classname, ',');
		  getline(ss, type, ',');
		  string isReadStr;
		  getline(ss, isReadStr);
		  if (isReadStr == "1") {
			   isRead = true;
		  }
		  int typeInt = stoi(type);
		  Notification notification(userList[userID], NotifID, Date, hour, classname, typeInt, isRead);
		  userList[userID].myNotifications.push_back(notification);

	 }

}

void readSlotData() {
	 ifstream file("Data/SlotsData.csv");
	 string line;
	 getline(file, line); // Skip the header line
	 while (getline(file, line)) {
		  Slot slot;
		  stringstream ss(line);
		  string userID;
		  getline(ss, userID, ',');
		  getline(ss, slot.courtName, ',');
		  getline(ss, slot.ID, ',');
		  getline(ss, slot.date, ',');
		  getline(ss, slot.startTime, ',');
		  /*  string courtID = PadelCourt::searchCourt(slot.courtName);
			Slot::slotCounter++;
			 load padel court && user data first
			courtList[courtID].slots.push_back(slot);
			if want remove slot from court's file
			*/
		  userList[userID].myReservations.push_back(slot);
	 }
	 file.close();
}
void readWorkoutData() {
	 ifstream file("Data/WorkoutData.csv");
	 string line;
	 getline(file, line);

	 // workout file format: userID,type,date,duration,caloriesBurned
	 while (getline(file, line)) {
		  stringstream ss(line);
		  string userID, type, date;
		  int duration = 0;
		  float calories = 0.0f;

		  getline(ss, userID, ',');
		  getline(ss, type, ',');
		  getline(ss, date, ',');
		  ss >> duration;
		  ss.ignore(); // skip comma
		  ss >> calories;


		  Workout w(date, type, duration, calories);
		  w.caloriesBurned = calories;

		  workoutManager.getWorkoutData()[userID].push_back(w);
	 }

}
void saveWorkoutData() {
	 ofstream file("Data/WorkoutData.csv");

	 file << "userID,type,date,duration,caloriesBurned\n";

	 const auto& data = workoutManager.getWorkoutData();
	 for (const auto& userEntry : data) {
		  const string& userID = userEntry.first;
		  const vector<Workout>& workouts = userEntry.second;

		  for (const auto& w : workouts) {
			   file << userID << ","
					<< w.type << ","
					<< w.date << ","
					<< w.duration << ","
					<< w.caloriesBurned << "\n";
		  }
	 }

	 file.close();
}


void writeCreditCardData() {
	 ofstream file("Data/DBofCredit.csv");
	 file << "CardID,CardName,ExpirationDate,CardCVV,Balance\n"; // Write header
	 for (const CreditCard& card : cardList) {
		  file << card.cardID << "a," << card.cardName << "," << card.ExpirationDate << "," << card.cardCVV << "a," << card.balance << "\n";
	 }
	 file.close();
}
void writeUserData() {
	 ofstream file("Data/usrData.csv");
	 file << "ID,name,email,password,Birthday,subscription,pic Path,my Classes list,myWallet\n"; // Write header

	 for (auto it = userList.begin(); it != userList.end(); ++it) {
		  User& user = it->second;
		  if (!user.ID.empty())
			   file << user.ID << "," << user.name << "," << user.email << "," << user.password << "," << user.Birthday << "," << user.subscription.getType() << "!" << user.subscription.getStartDate() << "!" << user.subscription.getEndDate() << "!" << user.subscription.get_is_VIP() << "," << user.PicPath << ",";
		  for (auto itCLass = user.myClasses.begin(); itCLass != user.myClasses.end();) {
			   file << *itCLass;
			   if ((++itCLass) != user.myClasses.end())
					file << "!";
		  }
		  file << "," << user.myWallet; // Add a comma after the class list
		  file << "\n";
	 }
	 file.close();
}
void writeStaffData() {
	 ofstream file("Data/staffData.csv");
	 file << "ID,Name,Email,password, PhoneNumber,Role,accountPic\n"; // Write header
	 for (auto it = staffList.begin(); it != staffList.end(); ++it) {
		  Staff staff = it->second;
		  if (!staff.ID.empty())
			   file << staff.ID << "," << staff.name << "," << staff.email << "," << staff.password << "," << staff.phone << "," << staff.role << "," << staff.PicPath << "\n";
	 }
	 file.close();
}
void writeGymClass() {
	 ofstream file("Data/gymClasses.csv");
	 if (!file.is_open()) {
		  System::Diagnostics::Debug::WriteLine("Error: Could not open Data/gymClasses.csv for writing");
		  return;
	 }

	 // Write header with all fields
	 file << "Class ID,Class Name,Instructor,InstructorID,Start Date,End Date,Sessions,Max Members,Price (EGP),AllowedSubTypes,Wait List\n";

	 for (const auto& pair : gymClassList) {
		  const GymClasses& gymClass = pair.second;

		  // Build sessions string
		  string sessionStr;
		  for (size_t i = 0; i < gymClass.sessions.size(); ++i) {
			   const Session& s = gymClass.sessions[i];
			   sessionStr += s.date + ":" + s.startTime + "-" + s.endTime;
			   if (i < gymClass.sessions.size() - 1)
					sessionStr += ";";
		  }

		  // Build allowed subscription types string
		  string allowedSubTypes;
		  for (size_t i = 0; i < gymClass.allowedSubTypes.size(); ++i) {
			   allowedSubTypes += gymClass.allowedSubTypes[i];
			   if (i < gymClass.allowedSubTypes.size() - 1)
					allowedSubTypes += ";";
		  }

		  // Build wait list string with '!' separator
		  string waitingListStr;
		  for (auto it = gymClass.waitingList.begin(); it != gymClass.waitingList.end(); ++it) {
			   waitingListStr += *it;
			   if (next(it) != gymClass.waitingList.end())
					waitingListStr += "!";
		  }

		  // Write all fields to file
		  file << gymClass.classID << "," << gymClass.className << "," << gymClass.instructor << ","
			   << gymClass.instructorID << "," << gymClass.startDate << "," << gymClass.endDate << ","
			   << sessionStr << "," << gymClass.maxMembers << "," << gymClass.price << ","
			   << allowedSubTypes << "," << waitingListStr << "\n";
	 }

	 file.close();
}

void writeSlotData() {
	 ofstream file("Data/SlotsData.csv");
	 file << "UserID,CourtName,SlotID,Date,StartTime\n"; // Write header
	 for (auto it = userList.begin(); it != userList.end(); ++it) {
		  User& user = it->second;
		  for (auto itSlot = user.myReservations.begin(); itSlot != user.myReservations.end(); ++itSlot) {
			   Slot slot = *itSlot;
			   file << user.ID << "," << slot.courtName << "," << slot.ID << "," << slot.date << "," << slot.startTime << "\n";
		  }
	 }
	 file.close();

}
void writePadelCourt() {
	 ofstream file("Data/padelData.txt");
	 for (auto it = courtList.begin(); it != courtList.end(); ++it) {
		  PadelCourt& court = it->second;
		  file << court.ID << "," << court.name << "," << court.location << "," << court.price << "\n";
		  for (auto itSlot = court.slots.begin(); itSlot != court.slots.end(); ++itSlot) {
			   Slot slot = *itSlot;
			   file << slot.ID << "," << slot.date << "," << slot.startTime << "\n";
		  }
		  file << "\n"; // Add a blank line to separate courts
	 }
	 file.close();
}

string extractClass(const string& msg) {
	 string key = "You have been added to ";
	 size_t start = msg.find(key);
	 if (start == string::npos)
		  return "";

	 start += key.length();
	 size_t end = msg.find("\n", start);
	 return msg.substr(start, end - start);
}
void writeNotification() {
	 ofstream file("Data/msgSheet.csv");
	 file << "UserID,NotifID,Date,Hour,ClassName,Type,isRead\n"; // Write header
	 for (auto it = userList.begin(); it != userList.end(); ++it) {
		  User& user = it->second;
		  for (auto itNotif = user.myNotifications.begin(); itNotif != user.myNotifications.end(); ++itNotif) {

			   Notification notif = *itNotif;
			   int type = -1;
			   if (notif.message.find("subscription will expire") != string::npos)
					type = 0;
			   else if (notif.message.find("You have been added to") != string::npos)
					type = 1;
			   else if (notif.message.find("You applied to join the class") != string::npos)
					type = 2;

			   string className = extractClass(notif.message);

			   file << user.ID << "," << notif.ID << "," << notif.date << "," << notif.hour << "," << className << "," << type << "," << notif.isRead << "\n";
		  }
	 }
	 file.close();
}

[STAThreadAttribute]
int main()
{
	 readStaffData();
	 readUserData();
	 readCreditCardData();
	 readPadelCourt();
	 //readGymClasses(); called in readUserData
	 readSlotData();
	 readNotfication(); //done
	 readWorkoutData();
	 for (auto& itUser : userList) {
		  User& user = itUser.second;
		  time_t end = getTime_t(user.subscription.getEndDate());
		  time_t currentTime = time(0);
		  if (currentTime > end) {
			   user.subscription.setActivated(false);
		  }
	 }
	 for (auto& itClass : gymClassList) {
		  if (itClass.second.getDaysDifference() >= 15) {
			   string clssName = itClass.second.className;
			   while (!itClass.second.waitingList.empty()) {
					string userID = itClass.second.waitingList.front();
					string msg = Notification::standardMessage(userList[userID], clssName, 2);
					Notification notify;
					notify.message = msg;
					itClass.second.waitingList.pop_front();
					userList[userID].myNotifications.push_back(notify);
					userList[userID].myWallet += itClass.second.price;
					userList[userID].myWaitingList.remove(itClass.first);
			   }

		  }
	 }

	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 ProjectCode::LoginPage form;
	 Application::Run(% form);
	 writeCreditCardData();
	 writeStaffData();
	 writeUserData();
	 writeGymClass();
	 writePadelCourt();
	 writeSlotData();
	 saveWorkoutData();
	 // writeNotification(); //done
	 return 0;
}

bool User::MessagesNotRead() {
	 for (auto& it : myNotifications) {
		  if (!it.isRead) {
			   return true;
		  }
	 }
	 return false;
}

unordered_map<string, GymClasses> Subscriptions::getAvailableClasses() {
	 extern unordered_map<string, GymClasses> gymClassList; // Assuming this is defined globally
	 unordered_map<string, GymClasses> filteredClasses;
	 string subscriptionType = getType();
	 bool isVIP = get_is_VIP();
	 for (auto it = gymClassList.begin(); it != gymClassList.end(); ++it) {
		  GymClasses& gymClass = it->second;
		  /*if (isVIP) {
			   filteredClasses[gymClass.classID] = gymClass;
			   continue;
		  }*/
		  for (int i = 0; i < gymClass.allowedSubTypes.size(); i++) {
			   if (gymClass.allowedSubTypes[i] == subscriptionType) {
					filteredClasses[gymClass.classID] = gymClass;
					break;
			   }
		  }
	 }
	 return filteredClasses;
}