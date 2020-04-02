#include "Pedometer.h"

void getInfo(Pedometer &);
unsigned int getMonth();
WeekDay getWeekDay();

int main(void)
{
	Pedometer pedometer;
	Count count;
	Date date;
	int variable;
	do
	{
		system("cls");
		std::cout << "1) Set the beginning date" << std::endl
			<< "2) Get the biggining date" << std::endl
			<< "3) Set count" << std::endl
			<< "4) Get information about count" << std::endl
			<< "5) Get average steps in month" << std::endl
			<< "6) Get average steps in week day" << std::endl
			<< "7) Get count and with max days in month" << std::endl
			<< "8) Save counts to file" << std::endl
			<< "9) Read counts from file" << std::endl
			<< "10) Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			std::cout << "Enter the date (<DD.MM.YYYY>): ";
			std::cin >> date;
			pedometer.setBeginningDate(date);
			break;
		case 2:
			std::cout << pedometer.getBeginningDate() << std::endl;
			break;
		case 3:
			std::cout << "Enter count (<DD.MM.YYYY> <hh:mm:ss-hh:mm:ss> <amount of steps>): ";
			std::cin >> count;
			pedometer.pushBack(count);
			break;
		case 4:
			getInfo(pedometer);
			break;
		case 5:
			std::cout << "Average steps is " << pedometer.getAverageSteps(getMonth()) << std::endl;
			break;
		case 6:
			std::cout << "Average steps is " << pedometer.getAverageSteps(getWeekDay()) << std::endl;
			break;
		case 7:
			count = pedometer.getMaxDaysCount();
			std::cout << count.getDate() << " " << count.getSteps() << std::endl;
			break;
		case 8:
			pedometer.writeTo();
			break;
		case 9:
			pedometer.readFrom();
			break;
		}
	} while (variable != 10);
	return 0;
}

void getInfo(Pedometer &pedometer)
{
	Date date;
	std::cout << "Enter date: ";
	std::cin >> date;
	for (size_t i = 0; i < pedometer.getLength(); i++)
	{
		if (pedometer[i].getDate() == date) std::cout << std::endl << pedometer[i].getInfo() << std::endl;
	}
}

unsigned int getMonth()
{
	std::string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	std::string month;
	do
	{
		std::cout << "Enter month(<DD.MM.YYYY>): ";
		std::cin >> month;
		for (size_t i = 0; i < 12; i++) if (months[i] == month) return i + 1;
	} while (true);
}

WeekDay getWeekDay()
{
	WeekDay wd[7] = {WeekDay::Sat, WeekDay::Sun, WeekDay::Mon, WeekDay::Tue, WeekDay::Wed, WeekDay::Thu, WeekDay::Fri};
	std::string weekDays[7] = {"Sat","Sun","Mon","Tue","Wed","Thu","Fri"};
	std::string weekDay;
	do
	{
		std::cout << "Enter week day: ";
		std::cin >> weekDay;
		for (size_t i = 0; i < 7; i++) if (weekDays[i] == weekDay) 	return wd[i];
	} while (true);
}