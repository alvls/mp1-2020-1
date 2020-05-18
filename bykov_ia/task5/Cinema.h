#pragma once
#include "Seance.h"

class Cinema
{
	vector<Seance> Seances;
	vector<Hall> Halls;
public:
	Cinema();	
	Hall GetHall(int number);

	vector<Seance>& GetSeances();
	vector<Hall>& GetHalls();
};