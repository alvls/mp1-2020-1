#include "Calendar.h"

int getIndex(Calendar &calendar)
{
	int index;
	calendar.print();
	do
	{
		std::cout << "Select event(1-" + std::to_string(calendar.getLength()) + "): ";
		std::cin >> index;
	} while (index < 1 || index > calendar.getLength());
	return index - 1;
}

void setEvent(Calendar &calendar)
{
	int variable;
	do
	{
		std::cout << "Select:" << std::endl
			<< "1)Add new event" << std::endl
			<< "2)Add new event with shift" << std::endl;
		std::cin >> variable;
	} while (variable < 1 || variable > 2);
	if (variable == 1)
	{
		Event temp;
		std::cin >> temp;
		calendar.push_back(temp);
	}
	else
	{
		int index = getIndex(calendar);
		Date date;
		std::string name;
		unsigned char c;
		std::cout << "Enter event name: ";
		std::cin >> name;
		std::cout << "Enter shift" << std::endl;
		std::cin >> date;
		std::cout << "Select \"+\" or \"-\"";
		std::cin >> c;
		calendar.shiftEvent(name, date, c);
	}
}

void getDiff(Calendar &calendar)
{
	Date date;
	std::cin >> date;
	int index = getIndex(calendar);
	std::cout << "The difference between dates = " << calendar[index].getDiff(date) << std::endl;
}



int main(void)
{
	Calendar calendar;
	int variable, index;
	while (true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1)Set Event" << std::endl
			<< "2)Get event date" << std::endl
			<< "3)Get the difference between 2 dates" << std::endl
			<< "4)Print event list" << std::endl
			<< "5)Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			setEvent(calendar);
			break;
		case 2:
			index = getIndex(calendar);
			std::cout << calendar[index].getEventDate().getDate() << std::endl;
			break;
		case 3:
			getDiff(calendar);
			break;
		case 4:
			calendar.print();
			break;
		case 5:
			return 0;
			break;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}