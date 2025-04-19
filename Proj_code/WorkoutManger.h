#pragma once
#include <iostream>
#include"Structure.h"
#include "Workout.h"
#include <vector>
#include <unordered_map>

using namespace std;

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

