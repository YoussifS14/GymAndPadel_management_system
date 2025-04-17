#include "Structure.h"

Subscriptions::Subscriptions(string _type, time_t st_date, bool vip) {
	type = _type;
	start_date = st_date;
	price = getPrice();
	is_VIP = vip;
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


Subscriptions::Subscriptions() : type(""), start_date(0), end_date(0) {}
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
void Staff ::generateMonthlyReport() {        //Bounce (only manager can generate and access reports)
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