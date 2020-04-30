#include "TicketWindow.h"
#include <ctime>
using std::to_string;

TicketWindow::TicketWindow() {}

string TicketWindow::RealTimeAdd10Minutes() //calculates present + 10 minutes to check seance availability
{
	time_t sec;
	sec = time(NULL);
	string realDate = asctime(localtime(&sec));

	string year = realDate.substr(20, 4);

	string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string smonth = realDate.substr(4, 3);
	int monthNum;
	for (int i = 0; i < 13; i++) {
		if (months[i] == smonth) monthNum = i;
	}
	if (monthNum < 10) smonth = string("0") + to_string(monthNum);
	else smonth = to_string(monthNum);

	string day = realDate.substr(8, 2);
	

	int hour = std::stoi(realDate.substr(11, 2));
	int minutes = std::stoi(realDate.substr(14, 2));
	if (minutes + 10 >= 60) {
		hour++;
		minutes = (minutes + 10) % 60;
	}
	else
		minutes = minutes + 10;

	string shour;
	string sminutes;

	if (hour < 10) shour = string("0") + to_string(hour);
	else shour = to_string(hour);
	
	if (minutes < 10) sminutes = string("0") + to_string(minutes);
	else sminutes = to_string(minutes);

	string date = year + string("_") + smonth + string("_") + day;
	string timeAdd10Minutes = shour + string("_") + sminutes;

	return date + timeAdd10Minutes;
}

void TicketWindow::addSeance(string date, string time, string name, int hallId)
{
	cinema.GetSeances().push_back(Seance(date, time, name, cinema.GetHall(hallId)));
}

void TicketWindow::addHall(int vipCost, int vipRows, int vipCols, int defCost, int defRows, int defCols)
{
	cinema.GetHalls().push_back(Hall(vipCost, vipRows, vipCols, defCost, defRows, defCols));
}

bool TicketWindow::BuyTicket(string date, string time, string name, int hallNumber, int type, int seatsNum, vector<Ticket>& tickets, double &totalCost)
{
	totalCost = 0;
	for (Seance &seance : cinema.GetSeances())
		if ((seance.GetName() == name) && (seance.GetDate() == date) && (seance.GetTime() == time) && (RealTimeAdd10Minutes() < date + time))
		{
			if (seance.GetHall().GetFreePlaces(type) < seatsNum)
				return false;
			for (int i = 0; i < seatsNum; i++)
			{
				Ticket ticket;
				seance.GetHall().BuyTicket(type, ticket.Row, ticket.Col);
				ticket.Date = date;
				ticket.Time = time;
				ticket.HallNumber = hallNumber;
				ticket.Name = name;
				ticket.Type = type;
				if (time < "12_00")
					ticket.Cost = seance.GetHall().GetCost(type) * 0.75;
				else
					if (time > "18_00")
						ticket.Cost = seance.GetHall().GetCost(type) * 1.5;
					else
						ticket.Cost = seance.GetHall().GetCost(type);
				tickets.push_back(ticket);
				totalCost += ticket.Cost;
			}
			return true;
		}
	return false;
}

bool TicketWindow::ReturnTicket(vector<Ticket>& tickets)
{
	Ticket ticket0 = tickets[0];
	vector<int> rows, cols;
	for (Seance &seance : cinema.GetSeances())
		if ((seance.GetName() == ticket0.Name) && (seance.GetDate() == ticket0.Date) && (seance.GetTime() == ticket0.Time))
		{
			for (Ticket ticket : tickets)
			{
				rows.push_back(ticket.Row);
				cols.push_back(ticket.Col);
			}
			seance.GetHall().ReturnTicket(rows, cols, ticket0.Type);
		}
	return true;
}