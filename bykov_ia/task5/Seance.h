#pragma once
#include "Hall.h"
#include <string>
using std::string;
using std::vector;

struct Ticket {
	string Date;
	string Time;
	string Name;
	int HallNumber;
	int Row;
	int Col;
	int Type;
	double Cost;
};

class Seance
{
	Hall hall;
	string Date;
	string Time;
	string Name;
public:
	Seance();
	Seance(string date, string time, string name, Hall hall);

	void SetDate(string date);
	void SetTime(string time);
	void SetName(string name);
	void SetHall(Hall _hall);

	string GetName();
	string GetDate();
	string GetTime();
	Hall& GetHall();
};