#include <string>;
#include <iostream>;
class Calendar
{
private:
	unsigned int* days, * months, * years, lenght;
	std::string* names;
public:
	Calendar()
	{
		days = new unsigned int[30];
		months = new unsigned int[30];
		years = new unsigned int[30];
		names = new std::string[30];
		lenght = 0;
	}
	Calendar(const Calendar& other)
	{
		days = new unsigned int[30];
		months = new unsigned int[30];
		years = new unsigned int[30];
		names = new std::string[30];
		lenght = other.lenght;
		for (int i = 0; i < lenght; i++)
		{
			days[i] = other.days[i];
			months[i] = other.months[i];
			years[i] = other.years[i];
			names[i] = other.names[i];
		}
	}

	~Calendar()
	{
		delete[] days;
		delete[] months;
		delete[] years;
		delete[] names;
	}
	Calendar& operator=(const Calendar& other)
	{
		lenght = other.lenght;
		for (int i = 0; i < lenght; i++)
		{
			days[i] = other.days[i];
			months[i] = other.months[i];
			years[i] = other.years[i];
			names[i] = other.names[i];
		}
		return *this;
	}
	void push_back(std::string name, unsigned int day, unsigned int month, unsigned int year)
	{
		if (lenght + 1 < 30)
		{
			days[lenght] = day;
			months[lenght] = month;
			years[lenght] = year;
			names[lenght] = name;
			lenght++;
		}
	}
	void pop_back()
	{ 
		if (lenght > 0) lenght--;
	}

bool get_date(std::string name, unsigned int &found_day, unsigned int &found_month, unsigned int &found_year)
	{
		
		for (int i = 0; i < lenght; i++)
		{
			if (name == names[i])
			{
				found_day = days[i];
				found_month = months[i];
				found_year = years[i];
				return true;
			}
		} 
		return false;
	}
	
	int get_diff(std::string& name, unsigned int& new_day, unsigned int& new_month, unsigned int& new_year, unsigned int &diff)
	{
		unsigned int first_date, second_date, diff_date;
		unsigned int found_year, found_month, found_day;
		bool flag=get_date(name, found_day, found_month, found_year);
		if (flag == false) return -1;
		first_date = new_day + new_month * 30 + new_year * 365;
		second_date = found_day + found_month * 30 + found_year * 365;
		if (first_date >= second_date) diff_date = first_date - second_date;
		else diff_date = second_date - first_date;
		return diff_date;
	}
	bool shift_event(std::string name, unsigned int& shift_day, unsigned int& shift_month, unsigned int& shift_year, int choice)
	{
		unsigned int found_year, found_month, found_day;
		bool flag = get_date(name, found_day, found_month, found_year);
		if (flag == false) return false;
		if (choice == 1)
		{

			shift_year = found_day + shift_year;
			if ((shift_month + found_month) > 12)
			{
				shift_year++;
				shift_month = shift_month + found_month - 12;
			}
			else shift_month = shift_month + found_month;
			if ((shift_day + found_day) > 30)
			{
				shift_month++;
				shift_day = shift_day + found_day - 30;
			}
			else shift_day = shift_day + found_day;
		}
		else
		{
			shift_year = found_day - shift_year;
			if (shift_month > found_month) 
			{
				shift_year--;
				shift_month = found_month + 12 - shift_month;
			}
			else shift_month = found_month - shift_month;
			if (shift_day > found_day) 
			{
				shift_day = found_day - shift_day + 30;
				shift_year--;
				shift_month = 12;
			}
			else shift_day = shift_day - found_day;
		}
		push_back(name, shift_day, shift_year, shift_month);
		return true;
	}

	void print()
	{
		std::cout << "List of events:" << std::endl;
		for (int i = 0; i < lenght; i++)
			std::cout << names[i] << " - " << days[i] << "." << months[i] << "." << years[i] << std::endl;
	}
	unsigned int get_lenght()
	{
		return lenght;
	}
		
};
int main() 
{
	Calendar calendar;
	int variable, choice;
	bool flag;
	unsigned int day, month, year, diff;
	std::string name;
	while (true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1)Set event" << std::endl
			<< "2)Get event date" << std::endl
			<< "3)Get the difference betweeen 2 dates" << std::endl
			<< "4)Add a new event shifting the old one" << std::endl
			<< "5)Print event list" << std::endl
			<< "6)Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			std::cout << "Enter the date (dd mm yyyy)" << std::endl;
			std::cin >> day >> month >> year;
			std::cout << "Enter event name" << std::endl;
			getline(std::cin, name);
			getline(std::cin, name);
			calendar.push_back(name, day, month, year);
			break;
		case 2:
			std::cout << "Enter the event name" << std::endl;
			getline(std::cin, name);
			getline(std::cin, name);
			flag = calendar.get_date(name, day, month, year);
			if (flag == true)
				std::cout << day << " " << month << " " << year << " - " << name << std::endl;
			else std::cout << "Event with this name does not exist!" << std::endl;
			break;
		case 3:
			std::cout << "Enter event name" << std::endl;
			getline(std::cin, name);
			getline(std::cin, name);
			std::cout << "Enter the date (dd mm yyyy)" << std::endl;
			std::cin >> day >> month >> year;
			calendar.get_diff(name, day, month, year, diff);
			if (calendar.get_diff(name, day, month, year, diff) == -1) std::cout << "Event with this name does not exist!" << std::endl;
			else std::cout << "Difference is " << diff << " days, or " << diff / 30 << " months, or " << diff / 365 << " years";
			break;
		case 4:
			std::cout << "Enter event name" << std::endl;
			getline(std::cin, name);
			getline(std::cin, name);
			std::cout << "Enter shifting date" << std::endl;
			std::cin >> day >> month >> year;
			std::cout << "More(1) or less(2)?" << std::endl;
			std::cin >> choice;
			flag = calendar.shift_event(name, day, month, year, choice);
			break;
		case 5:
			calendar.print();
			break;
		case 6:
			return 0;
			break;

		}
	}
}