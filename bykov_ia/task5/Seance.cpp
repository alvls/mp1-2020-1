#include "Seance.h"

Seance::Seance() {}

Seance::Seance(string date, string time, string name, Hall hall) :
	Date(date), Time(time), Name(name), hall(hall) {}

void Seance::SetDate(string date) { Date = date; }
void Seance::SetTime(string time) { Time = time; }
void Seance::SetName(string name) { Name = name; }
void Seance::SetHall(Hall _hall) { hall = _hall; }

string Seance::GetName()
{
	return Name;
}

string Seance::GetDate()
{
	return Date;
}

string Seance::GetTime()
{
	return Time;
}

Hall& Seance::GetHall()
{
	return hall;
}