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
using namespace std;
static int baseID = 1000;//**
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


struct Slot {
	 static int slotCount;
	 string ID;
	 string courtName; 
	 string date; // MM/DD/YYYY
	 string startTime; 
	 string endTime;
	 //superkey ->courtName + ID
};
class Subscriptions {
private:
	string type;           // 1 month,3 month,6 month,1 year
	time_t start_date;
	time_t end_date;
	double price;
	bool is_VIP;
	bool isActivated;
public:
	Subscriptions(string _type, time_t st_date, bool vip);
	Subscriptions();
	double getPrice();
	//void renewSubscription(string& newType, time_t newStdate);
	bool isActive();
	string getType();
	bool get_is_VIP();
	vector<string> getAvailableClasses(string subscriptionType, bool isVIP);
	time_t calaculateEndDate();
	void set_is_VIP(bool vip);  
	bool IsExpired() {
		 return time(0) > end_date;
	}
	void cancelSubscriptions() {
		 end_date = time(0);
		 isActivated = false;
		 is_VIP = false;
	}
    bool createOffer() {
        return ( is_VIP== true);
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
//// problem
  static void sendNotifications(vector<Subscription>& subs) {
      time_t now = time(0);
      for (auto& sub : subs) {
          if (!sub.isActivated) continue;

          double sec_left = difftime(sub.end_date, now);
          int days_left = sec_left / (60 * 60 * 24);

          if (days_left <= 7 && days_left >= 0) {
              sub.sendNotification("Your subscription will end in " + to_string(days_left) + " days.");
          }
      }
  }

    void displaysubscriptions() {
        cout << "Member ID: " << member_id << endl;
        cout << "Duration: " << duration << endl;
        cout << "Status: " << (isActivated ? "Active" : "Cancelled") << endl;
        cout << "Price after discount: " << price << endl;
        cout << "End Date: " << ctime(&end_date);
    }
~Subscription() {
    cout << "Subscription for member ID: " << member_id << " has been destroyed." << endl;
}
};
class User {
public:
	 string ID;
	 string name;
	 string email;
	 string password;
	 string Brithday;
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
	 User(string Id, string Name, string Email, string pass, string bday, Subscriptions Sub) {
		 ID = Id;
		 name = Name;
		 email = Email;
		 password = pass;
		 Brithday = bday;
		 subscription = Sub;
	 }
	 static bool isEmailCorrect(string email);
	 static bool isEmailUnique(string email);
	 static bool isNameValid(string name);
	 static bool isBirthdayValid(string bday);
	 static bool registerMember();
	 //*//
	 User() {
		  ID = "";
		  name = "";
		  email = "";
		  password = "";
		  Brithday = "";
		  classEntered = 0;
	 }
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
	Staff(string id, string Name, string Email, string Password, string Phone, string Role, string picPath=" ") {
		ID = id;
		name = Name;
		email = Email;
		password = Password;
		phone = Phone;
		role = Role;
		//PicPath = picPath; //gui
	}
	//*//
	static bool login(string email, string password) {
		extern vector<Staff> staffList;
		for (int i = 0; i < staffList.size(); i++) {
			if (staffList[i].email == email && staffList[i].password == password) {
				loginIndex = i;
				return true;
			}
		}
		return false;
	}
	static bool comparingActivity(const User& user1, const User& user2) {
		return user1.classEntered > user2.classEntered;
	}
	//*//
	User* searchUserByID(string userID);
	//**//
	void generateMonthlyReport();
};
class GymClasses {
public:
	 string classID;
	 string className;
	 string instructor;
	 string date; // MM/DD/YYYY
	 /* string startTime;
	  string endTime;*/
	 int maxMembers; // Maximum number of members allowed in the class
	 vector<User> members; // List of users enrolled in the class	
	 deque<User> waitingList;

	 bool isFull() {
		  return members.size() == maxMembers;
	 }
};

vector<Staff> staffList;
vector<User> userList;
vector<CreditCard> cardList;
vector<PadelCourt> courtList;
vector<Subscriptions> availableSubscriptions;
vector<string> availableClasses;//?
vector<GymClasses> gymClassesList;
