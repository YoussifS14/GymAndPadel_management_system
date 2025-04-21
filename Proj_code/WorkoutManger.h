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
	 void viewWorkoutHistory(User);
	 void addWorkout(User);
	 void TrackProgress(User);
	 void filterWorkout(User, string);

private:
	 int calcCalories(User, int, string, int);
	 void display(User);
public:
	 void loadFromFile(const string&);
	 void saveToFile(const string&);



};

