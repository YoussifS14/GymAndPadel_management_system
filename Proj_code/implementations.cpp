#include "Structure.h"


//*//
bool User::isEmailCorrect(string email) {
    if (email.find('@') == string::npos || email.size() < 5 || email.substr(email.size() - 4) != ".com") {
        return false;
    }
    return true;
}

bool User::isEmailUnique(string email) {
    extern vector<User> userList;
    for (int i = 0; i < userList.size(); ++i) {
        if (userList[i].email == email) {
            return false;
        }
    }
    return true;
}

bool User::isNameValid(string name) {
    for (int i = 0; i < name.size(); i++) {
        if (!isalpha(name[i])) {
            return false;
        }
    }
    return true;
}

bool User::isBirthdayValid(string bday) {
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

vector<string> Subscriptions::getAvailableClasses(string subscriptionType, bool isVIP) {
    extern vector<string> availableClasses;

    if (subscriptionType == "1 month") {
        availableClasses = { "Yoga", "Cardio", "Stretching" };
    }
    else if (subscriptionType == "3 month") {
        availableClasses = { "Yoga", "Cardio", "Pilates", "Zumba", "Spin" };
    }
    else if (subscriptionType == "6 month") {
        availableClasses = { "Yoga", "Cardio", "Pilates", "Zumba", "Strength Training", "HIIT" };
    }
    else if (subscriptionType == "1 year") {
        availableClasses = { "Yoga", "Cardio", "Pilates", "Zumba", "Strength Training", "HIIT", "Cycling", "Boxing", "Crossfit" };
    }

    if (isVIP) {
        if (subscriptionType == "1 month") {
            availableClasses.push_back("VIP Yoga - Private Session");
            availableClasses.push_back("VIP Zumba - Private Session");
        }
        else if (subscriptionType == "3 month") {
            availableClasses.push_back("VIP Pilates - Private Session");
            availableClasses.push_back("VIP Crossfit - Expert Trainer");
        }
        else if (subscriptionType == "6 month") {
            availableClasses.push_back("VIP Strength Training - Personal Coach");
            availableClasses.push_back("VIP HIIT - High-Intensity Class");
        }
        else if (subscriptionType == "1 year") {
            availableClasses.push_back("VIP Yoga - Exclusive");
            availableClasses.push_back("VIP Crossfit - Elite Coaching");
            availableClasses.push_back("VIP Zumba - Personal Trainer");
        }
    }

    return availableClasses;
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
    vector<string> classes = userSub.getAvailableClasses(subType, isVip);
    cout << "\nYour subscription: " << subType << (isVip ? " (VIP)" : "") << "\n";
    cout << "\nAvailable Classes for your subscription:\n";
    for (int i = 0; i < classes.size(); i++) {
        cout << "- " << classes[i] << endl;
    }
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
    if (role != "manager" || role != "Manager") {
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
