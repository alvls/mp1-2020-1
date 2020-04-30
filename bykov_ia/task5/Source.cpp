#include "TicketWindow.h"
#include <iostream>

using std::cout;

int main() {
	
	TicketWindow ticketWindow;
	vector<Ticket> tickets, vipTickets;
	double totalCost, vipTotalCost;

	ticketWindow.addHall(200, 3, 3, 100, 10, 10); // зал 10 на 10, из которых есть вип-зона 3 на 3
	ticketWindow.addSeance("2020_05_30", "20_00", "Titanic", 0);

	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //покупаем все билеты из обычной зоны
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //пробуем еще раз, возвращается false
	ticketWindow.ReturnTicket(tickets);  //возвращаем билеты
	tickets.clear();
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //покупаем, возвращается true
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 2, 9, vipTickets, vipTotalCost); //покупаем вип
}