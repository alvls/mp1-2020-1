#include"RailwayTicketOffice.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>


int main()
{
	int item, i;
	RailwayTicketOffice ticket_office;
	Date date_flight;
	int number_train;
	std::string type_of_wagon = "swallow";
	int count_seating = 0;
	int count_upper_berth = 0;
	int count_lower_berth = 0;
	std::vector<std::string> full_names;
	Date today(28,04,2020);

	while (true)
	{
		system("cls");
		std::cout << "1) accept client data\n2) to check availability \n3) to reserve tickets\n4) cancel the order\n5) calculate the total cost of tickets\n6) generate tickets\n";
		std::cin >> item;
		switch (item)
		{
		case 1:
			type_of_wagon = "swallow";
			count_seating = 0;
			count_upper_berth = 0;
		    count_lower_berth = 0;
			std::cout << "Today: " << today <<std::endl << "Enter your trip date (day.month.year; example:01.10.2020): ";
			std::cin >> date_flight;
			std::cout << "\n numder        type of train          direction\n";
			std::cout << "  12             swallow        Nizhny Novgorod -> Moscow\n";
			std::cout << "  15             swallow        Nizhny Novgorod -> Moscow\n";
			std::cout << "  18             swallow        Nizhny Novgorod -> Moscow\n";
			std::cout << "  21             swallow        Moscow -> Nizhny Novgorod\n";
			std::cout << "  24             swallow        Moscow -> Nizhny Novgorod\n";
			std::cout << "  27             swallow        Moscow -> Nizhny Novgorod\n";
			std::cout << "  75            fast train      Nizhny Novgorod -> Moscow\n";
			std::cout << "  80            fast train      Moscow -> Nizhny Novgorod\n";
			std::cout << "  60            firm train      Nizhny Novgorod -> Moscow\n";
			std::cout << "  64            firm train      Moscow -> Nizhny Novgorod\n";			
			std::cout << "Enter the train number: ";
			std::cin >> number_train;
			if ((number_train == 75) || (number_train == 80))
			{
				std::cout << " Enter the car type (coupe or reserved seat): ";
				std::getline(std::cin, type_of_wagon);
				std::getline(std::cin, type_of_wagon);
			}
			else
			{
				if ((number_train == 64) || (number_train == 60))
				{
					std::cout << " Enter the car type (coupe or reserved seat or SV): ";
					std::getline(std::cin, type_of_wagon);
					std::getline(std::cin, type_of_wagon);
				}
			}
			if ((type_of_wagon == "swallow") || (type_of_wagon == "SV"))
			{
				std::cout << " Enter the number of seats: ";
				std::cin >> count_seating;
			}
			else
			{
				std::cout << " Enter the number of lower seats: ";
				std::cin >> count_lower_berth;
				std::cout << " Enter the number of upper seats: ";
				std::cin >> count_upper_berth;
			}
			for (int i = 0; i < count_lower_berth + count_upper_berth + count_seating; i++)
			{
				std::string name;
				std::cout << " Enter the passenger's full name: ";
				if (i != 0)
					std::getline(std::cin, name);
				else
				{
					std::getline(std::cin, name);
					std::getline(std::cin, name);
				}
				full_names.push_back(name);
			}
			ticket_office.SetData(today, date_flight, number_train, type_of_wagon, count_seating, count_upper_berth, count_lower_berth, full_names);
			break;
		case 2:
			std::cout << ticket_office.CheckAvailabilityOfTickets() << std::endl;
			break;
		case 3:
			ticket_office.ReserveOfTickets();
			std::cout << "The order is reserved\n";
			break;
		case 4:
			ticket_office.CancelOrder();
			std::cout << "The order has been cancelled\n";
			break;
		case 5:
			std::cout << ticket_office.CostOfTickets() << " rub" <<std::endl;
			break;
		case 6:
			std::cout << ticket_office.GetOfTickets() << std::endl;
		default:
			break;
		}
		std::cout << "Continue running the program?\n1)Yes\n2)No\n";
		std::cin >> i;
		if (i != 1)break;
	}
	return(0);
}