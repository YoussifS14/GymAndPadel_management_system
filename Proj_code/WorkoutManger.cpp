#include "WorkoutManger.h"
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;
void WorkoutManger::viewWorkoutHistory(User user)
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

void WorkoutManger::addWorkout(User user)
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

	cout << " Enter your body weight in Kg";
	cin >> bodyWeight;

	int calories = calcCalories(user, duration, type, bodyWeight);

	Workout w(date, type, duration, calories);

	workoutData[user.ID].push_back(w);

	cout << " The Workout Added successfully \n";

}

void WorkoutManger::TrackProgress(User user)
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

void WorkoutManger::filterWorkout(User user, string type)
{
	auto it = workoutData.find(user.ID);
	if (it == workoutData.end() || it->second.empty())
	{
		cout << " No workout avaliable to filter \n " << user.ID << endl;
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

int WorkoutManger::calcCalories(User user, int duration, string type, int bodyWei)
{
	int met;
	int bodyWeight = bodyWei;

	if (type == "cardio" || type == "Cardio") {
		met = 8;
		return met * bodyWeight * (duration / 60.0);
	}
	else if (type == " strength" || type == "Strength") {
		met = 5;
		return met * bodyWeight * (duration / 60.0);
	}
}

void WorkoutManger::display(User user)
{
	viewWorkoutHistory(user);
}

void WorkoutManger::loadFromFile(const string& filename)
{
	ifstream inFile(filename);
	if (!inFile.is_open()) {
		cerr << "Error: Couldn't open file for loading.\n";
		return;
	}

	workoutData.clear(); // Clear existing data

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
		workoutData[userId].push_back(w);
	}

	inFile.close();
	cout << "Workout data loaded successfully.\n";
}

void WorkoutManger::saveToFile(const string& filename)
{
	ofstream outFile(filename);
	if (!outFile.is_open()) {
		cerr << "Error: Couldn't open file for saving.\n";
		return;
	}

	for (const auto& userPair : workoutData) {
		string userId = userPair.first;
		for (const Workout& w : userPair.second) {
			outFile << userId << ","
				<< w.date << ","
				<< w.type << ","
				<< w.duration << ","
				<< w.caloriesBurned << "\n";
		}
	}

	outFile.close();
	cout << "Workout data saved successfully.\n";
}



