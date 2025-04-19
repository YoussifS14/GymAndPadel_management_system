#include "Workout.h"

Workout::Workout()
{
	date = "";
	type = "";
	duration = 0;
	caloriesBurned = 0;

}

Workout::Workout(string date, string type, int duration, int caloriesBurned)
{
	this->date = date;
	this->type = type;
	this->duration = duration;
	this->caloriesBurned = caloriesBurned;

}

void Workout::display()
{
	cout << " Date : " << date << endl
		<< " Type: " << type << endl
		<< "Duration" << duration << endl
		<< "calpries Burned : " << caloriesBurned << endl;
}



