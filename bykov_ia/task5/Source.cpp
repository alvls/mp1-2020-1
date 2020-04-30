#include "TicketWindow.h"
#include <iostream>

using std::cout;

int main() {
	
	TicketWindow ticketWindow;
	vector<Ticket> tickets, vipTickets;
	double totalCost, vipTotalCost;

	ticketWindow.addHall(200, 3, 3, 100, 10, 10); // hall 10x10, in which there is a 3x3 vip zone
	ticketWindow.addSeance("2020_05_30", "20_00", "Titanic", 0);

	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //buy all tickets from the default zone
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //try again, return false
	ticketWindow.ReturnTicket(tickets);  //return tickets
	tickets.clear();
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //try buy again, return true
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 2, 9, vipTickets, vipTotalCost); //buy vip Tickets
}