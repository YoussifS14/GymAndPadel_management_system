#include "Structure.h"


User::User(string id, string name, string email, string password, string bday, string sub) {
    ID = id;
    this->name = name;
    this->email = email;
    this->password = password;
    Brithday = bday;
    subscription = sub;
}

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
        if (!isalpha(name[i]) && name[i] != ' ') {
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

bool User::registerMember() {
    string id, name, email, password, bday, sub;
    extern vector<User> userList;

    cout << "====================================\n";
    cout << "   Welcome to ysm GYM SYSTEM   \n";
    cout << "====================================\n";

    while (true) {
        cout << "Enter your Name: ";
        cin.ignore();
        getline(cin, name);
        if (!isNameValid(name)) {
            cout << "Invalid name. Use letters and spaces only.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Enter Email: ";
        cin >> email;
        if (!isEmailCorrect(email)) {
            cout << "Invalid format. Must contain '@' and end with '.com'.\n";
        }
        else if (!isEmailUnique(email)) {
            cout << "Email already exists. Try another.\n";
        }
        else {
            break;
        }
    }

    cout << "Enter Password: ";
    cin >> password;

    while (true) {
        cout << "Enter Birthday (MM/DD/YYYY): ";
        cin >> bday;
        if (!isBirthdayValid(bday)) {
            cout << "Invalid birthday format.\n";
        }
        else {
            break;
        }
    }

    int subChoice;
    while (true) {
        cout << "\nChoose a Subscription:\n";
        cout << "1. (1 Month)\n";
        cout << "2. (3 Months)\n";
        cout << "3. (6 Months)\n";
        cout << "4. (1 Year)\n";
        cout << "5. (VIP)\n";
        cout << "Enter choice (1-5): ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            sub = "1month";
            cout << "\n Subscription: 1 Month\n";
            cout << " Price: $500\n";
            cout << " Duration: 30 days\n";
            cout << " Classes: Yoga, Zumba, Cardio\n";
            cout << " Offer: Free protein shake on first visit\n";
            break;
        case 2:
            sub = "3months";
            cout << "\n Subscription: 3 Months\n";
            cout << " Price: $700\n";
            cout << " Duration: 90 days\n";
            cout << " Classes: Yoga, Zumba, Pilates\n";
            cout << " Offer: Free gym bag + 10% off on supplements\n";
            break;
        case 3:
            sub = "6months";
            cout << "\n Subscription: 6 Months\n";
            cout << " Price: $1000\n";
            cout << " Duration: 180 days\n";
            cout << " Classes: All regular classes + Advanced Cardio\n";
            cout << " Offer: Bring a friend = get 1 month free\n";
            break;
        case 4:
            sub = "1year";
            cout << "\n Subscription: 1 Year\n";
            cout << " Price: $1500\n";
            cout << " Duration: 365 days\n";
            cout << " Classes: All + Personal trainer once a month\n";
            cout << " Offer: 2 free guest passes\n";
            break;
        case 5:
            sub = "VIP";
            cout << "\n VIP Subscription Selected!\n";
            cout << " Price: $2000\n";
            cout << " Duration: 365 days\n";
            cout << " Unlimited access to all classes\n";
            cout << " Includes: VIP Lounge, Sauna, Private Coach\n";
            cout << " Offer: Full merchandise kit + Monthly guest access\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
            continue;
        }
        break;
    }

    id = "M" + to_string(++baseID);
    cout << "your id is: " << id << "\n";

    userList.push_back(User(id, name, email, password, bday, sub));
    cout << "Member registered successfully.\n";
    return true;
}
