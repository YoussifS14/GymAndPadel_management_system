#include "WorkoutManger.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <algorithm>




using namespace std;
void WorkoutManger::viewWorkoutHistory(const User& user)
{
	auto it = workoutData.find(user.ID);

	if (it == workoutData.end() || it->second.empty()) {
		cout << " NO WORKOUT HISTORY FOR USER " << user.ID << endl;
		return;
	}

	cout << " Workout History For User " << user.name << endl;

	for (auto workoutIt = it->second.begin(); workoutIt != it->second.end(); workoutIt++) {
		workoutIt->display();
	}
}

void WorkoutManger::addWorkout(const User& user)
{
	string date, type;
	int duration;
	int bodyWeight;

	cout << " Enter workout date : ";
	cin >> date;

	cout << " Enter workout type (cardio , strength) : ";
	cin >> type;

	cout << " Enter workout duration in minutes : ";
	cin >> duration;
	if (duration < 0) {
		cout << " duration must be positive";
		cin >> duration;
	}

	cout << " Enter your body weight in Kg";
	cin >> bodyWeight;
	if (bodyWeight < 0) {
		cout << " bodyWeight must be positive";
		cin >> bodyWeight;
	}

	int calories = calcCalories(user, duration, type, bodyWeight);

	Workout w(date, type, duration, calories);

	recordWorkout(user.ID, w);

	cout << " The Workout Added successfully \n";

}

void WorkoutManger::TrackProgress(const User& user)
{
	auto it = workoutData.find(user.ID);
	if (it == workoutData.end() || it->second.empty())
	{
		cout << " No progress to show for this user  " << user.ID << endl;
		return;
	}


	int totalCalories = 0;
	int totalDuration = 0;

	for (auto workoutIt = it->second.begin(); workoutIt != it->second.end(); workoutIt++) {
		totalCalories += workoutIt->caloriesBurned;
		totalDuration += workoutIt->duration;
	}

	cout << " Total workouts for user " << user.ID << "  is " << it->second.size() << endl;
	cout << " Total duration  " << totalDuration << " minutes" << endl;
	cout << " Total burned calories  " << totalCalories << " Kcal" << endl;
}

void WorkoutManger::filterWorkout(const User& user, string type)
{
	auto it = workoutData.find(user.ID);
	if (it == workoutData.end() || it->second.empty())
	{
		cout << " No workout available to filter \n " << user.ID << endl;
		return;
	}


	bool found = false;

	cout << " Filtered workouts for " << type << " :\n";
	for (auto workoutIt = it->second.begin(); workoutIt != it->second.end(); workoutIt++) {
		if (workoutIt->type == type) {
			workoutIt->display();
			found = true;
		}
	}

	if (!found) {
		cout << "No workout matched this type \n";
	}
}

void WorkoutManger::recordWorkout(const string& memberID, const Workout& workout)
{
	if (memberID.empty()) {
		cout << "Error: Member ID is empty. Workout not recorded.\n";
		return;
	}
	workoutData[memberID].push_back(workout);

}

int WorkoutManger::calcCalories(User user, int duration, string type, int bodyWei)
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
		{"hitt", 9},
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


void WorkoutManger::display(User user)
{
	viewWorkoutHistory(user);
}

void WorkoutManger::loadFromFile(const string& filename, unordered_map<string, User>& users) {
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

void WorkoutManger::saveToFile(const string& filename) {
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





