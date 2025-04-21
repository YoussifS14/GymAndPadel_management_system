#pragma once
#include <iostream>
#include"Structure.h"
#include <vector>
#include <unordered_map>

using namespace std;

struct Workout {
	 string date;
	 string type;
	 int duration;
	 int caloriesBurned;

	 Workout() : date(""), type(""), duration(0), caloriesBurned(0) {}
	 Workout(string d, string t, int dur, int cal) : date(d), type(t), duration(dur), caloriesBurned(cal) {}
	 void display() {
		  cout << "Date: " << date << "\nType: " << type << "\nDuration: " << duration << " minutes\nCalories Burned: " << caloriesBurned << endl;
	 }
};

class WorkoutManger
{
private:
	 unordered_map<string, vector<Workout>>workoutData;

public:
	void viewWorkoutHistory(const User&);
	void addWorkout(const User&);
	void TrackProgress(const User&);
	void filterWorkout(const User&, string);
	 void recordWorkout(const string& memberID, const Workout& workout);

private:
	 int calcCalories(User, int, string, int);
	 void display(User);
public:
	void loadFromFile(const string&, unordered_map<string, User>& users);
	 void saveToFile(const string&);



};

