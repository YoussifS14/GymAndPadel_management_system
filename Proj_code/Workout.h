#pragma once
#include <iostream>
#include"Structure.h"
#include <vector>
#include <unordered_map>

using namespace std;
class Workout
{

private:
	unordered_map<string, vector<Workout>>workoutData;

public:
	string date;
	string type;
	int duration;
	int caloriesBurned;


	Workout();
	Workout(string, string, int, int);
	void display();


};

