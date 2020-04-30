#include "TicketWindow.h"
#include <iostream>

using std::cout;

int main() {
	
	TicketWindow ticketWindow;
	vector<Ticket> tickets, vipTickets;
	double totalCost, vipTotalCost;

	ticketWindow.addHall(200, 3, 3, 100, 10, 10); // ��� 10 �� 10, �� ������� ���� ���-���� 3 �� 3
	ticketWindow.addSeance("2020_05_30", "20_00", "Titanic", 0);

	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //�������� ��� ������ �� ������� ����
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //������� ��� ���, ������������ false
	ticketWindow.ReturnTicket(tickets);  //���������� ������
	tickets.clear();
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 0, 100 - 9, tickets, totalCost); //��������, ������������ true
	ticketWindow.BuyTicket("2020_05_30", "20_00", "Titanic", 0, 2, 9, vipTickets, vipTotalCost); //�������� ���
}