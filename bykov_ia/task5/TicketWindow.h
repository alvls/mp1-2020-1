#pragma once
#include "Seance.h"
#include "Cinema.h"

class TicketWindow
{
	Cinema cinema;
	string RealTimeAdd10Minutes();
public:
	TicketWindow();

	void addSeance(string date, string time, string name, int hallId);
	void addHall(int vipCost, int vipRows, int vipCols, int defCost, int defRows, int defCols);

	bool BuyTicket(string date, string time, string name, int hallNumber, int type, int seatsNum, vector<Ticket>& tickets, double &totalCost);
	bool ReturnTicket(vector<Ticket>& tickets);
};