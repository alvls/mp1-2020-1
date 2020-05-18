#include "Cinema.h"

Cinema::Cinema() {}

Hall Cinema::GetHall(int number)
{
	return Halls[number];
}

vector<Seance>& Cinema::GetSeances()
{
	return Seances;
}
vector<Hall>& Cinema::GetHalls()
{
	return Halls;
}