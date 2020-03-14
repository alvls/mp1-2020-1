#include "Calendar.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(const Date &other)
{
	setYear(other.year);
	setMonth(other.month);
	setDay(other.day);
}

Date::~Date() {}

bool Date::leapYear(unsigned int year)
{
	bool leap = false;
	if (year % 4 == 0) leap = true;
	if (year % 100 == 0) leap = false;
	if (year % 400 == 0) leap = true;
	return leap;

}

int Date::maxDays()
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapYear(year)) days[1] = 29;
	return days[month - 1];
}

int Date::maxDays(unsigned int month, unsigned int year)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapYear(year)) days[1] = 29;
	return days[month - 1];
}

void Date::setDate(unsigned int day, unsigned int month, unsigned int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::setDay(unsigned int day)
{
	while (day > maxDays())
	{
		day -= maxDays();
		month++;
	}
	this->day = day;
}

void Date::setMonth(unsigned int month)
{
	while(month > 12)
	{
		month -= 12;
		year++;
	}
	this->month = month;
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

unsigned int Date::getDay()
{
	return day;
}

unsigned int Date::getMonth()
{
	return month;
}

unsigned int Date::getYear()
{
	return year;
}

std::string Date::getDate()
{
	std::string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	return std::to_string(day) + " " + months[month - 1] + " " + std::to_string(year);
}

Date Date::diff(const Date &first, const Date &second)
{
	unsigned int day, month, year;
	year = first.year - second.year;
	if (first.month < second.month)
	{
		month = 12 + first.month - second.month;
		year--;
	}
	else month = first.month - second.month;
	if (first.day < second.day)
	{
		if (month == 0)
		{
			month = 12;
			year--;
		}
		else month--;
		day = maxDays(month, year) + first.day - second.day;
	}
	else day = first.day - second.day;
	return Date(day, month, year);
}

Date Date::getDiff(const Date &date)
{
	if (*this > date) return diff(*this, date);
	else return diff(date, *this);
}

Date& Date::operator =(const Date &other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}

Date Date::operator +(const Date &other)
{
	unsigned int day, month, year, qt;
	year = this->year + other.year;
	month = this->month + other.month;
	if (month > 12)
	{
		month -= 12;
		year++;
	}
	day = this->day + other.day;
	while (qt = maxDays(month, year) < day )
	{
		if (day > qt)
		{
			day -= qt;
			month++;
			if (month > 12)
			{
				month -= 12;
				year++;
			}
		}
	}
	return Date(day, month, year);
}

Date Date::operator -(const Date &other)
{
	unsigned int day, month, year;
	year = this->year - other.year;
	if (this->month <= other.month)
	{
		month = 12 + this->month - other.month;
		year--;
	}
	else month = this->month - other.month;
	if (this->day <= other.day)
	{
		if (month == 1)
		{
			month = 12;
			year--;
		}
		else month--;
		day = maxDays(month, year) + this->day - other.day;
	}
	else day = this->day - other.day;
	return Date(day, month, year);
}

bool Date::operator ==(const Date &other)
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator !=(const Date &other)
{
	return !(*this == other);
}

bool Date::operator >=(const Date &other)
{
	return !(*this < other);
}

bool Date::operator <=(const Date &other)
{
	return !(*this > other);
}

bool Date::operator >(const Date &other)
{
	if (this->year > other.year) return true;
	if (this->year < other.year) return false;
	if (this->month > other.month) return true;
	if (this->month < other.month) return false;
	if (this->day > other.day) return true;
	return false;
}

bool Date::operator <(const Date &other)
{
	if (this->year < other.year) return true;
	if (this->year > other.year) return false;
	if (this->month < other.month) return true;
	if (this->month > other.month) return false;
	if (this->day < other.day) return true;
	return false;
}

//----------------------------------------------------------------------------------------------
Event::Event()
{

}

Event::Event(Date date, std::string name)
{
	this->date = date;
	this->name = name;
}

Event::Event(const Event &other)
{
	this->date = other.date;
	this->name = other.name;
}

Event::~Event() {}

void Event::setEvent(Date date, std::string name)
{
	this->date = date;
	this->name = name;
}

void Event::setEvent(unsigned int day, unsigned int month, unsigned int year, std::string name)
{
	date.setDate(day, month, year);
	this->name = name;
}

std::string Event::getEvent()
{
	return date.getDate() + " - " + name;
}

Date Event::getEventDate()
{
	return date;
}

std::string Event::getName()
{
	return name;
}

Date Event::getDiff(const Date &date)
{
	return this->date.getDiff(date);
}

Event& Event::operator =(const Event &other)
{
	this->date = other.date;
	this->name = other.name;
	return *this;
}

//----------------------------------------------------------------------------------------------
Calendar::Calendar(int length)
{
	this->length = length;
	size = 10;
	while (length > size) size *= 2;
	events = new Event[size];
}

Calendar::Calendar(const Calendar &other)
{
	this->length = other.length;
	this->size = other.size;
	events = new Event[size];
	for (int i = 0; i < length; i++) this->events[i] = other.events[i];
}

Calendar::~Calendar()
{
	delete[] events;
}

void Calendar::incSize()
{
	Event *temp = new Event[length];
	for (int i = 0; i < length; i++) temp[i] = events[i];
	delete[] events;
	size *= 2;
	events = new Event[size];
	for (int i = 0; i < length; i++) events[i] = temp[i];
	delete[] temp;
}

void Calendar::incLength(int length)
{
	if (length > size)
	{
		while (length > size) incSize();
	}
	else if (length < this->length)
	{
		Event *temp = new Event[length];
		for (int i = 0; i < length; i++) temp[i] = events[i];
		delete[] events;
		events = new Event[size];
		for (int i = 0; i < length; i++) events[i] = temp[i];
		delete[] temp;
	}
	this->length = length;
}

int Calendar::getLength()
{
	return length;
}

void Calendar::push_back(const Event &other)
{
	if (length + 1 >= size) incSize();
	events[length++] = other;
}

void Calendar::pop_back()
{
	events[--length].setEvent(Date(), std::string());
}

void Calendar::clear()
{
	delete[] events;
	length = 0;
	events = new Event[size];
}

bool Calendar::empty()
{
	return length == 0 ? true : false;
}

void Calendar::shiftEvent(std::string &name, const Date &date, unsigned char c)
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if (events[i].getName() == name)
		{
			index = i;
			break;
		}
	}
	if (index == -1) throw "Event doesn't exist";
	if (c == '+')
		push_back(Event(events[index].getEventDate() + date, events[index].getName()));
	else
		push_back(Event(events[index].getEventDate() - date, events[index].getName()));
}

void Calendar::print()
{
	std::cout << "Calendar of events:" << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << events[i].getEvent() << std::endl;
	}
}

Calendar& Calendar::operator =(const Calendar &other)
{
	this->length = other.length;
	this->size = other.size;
	delete[] events;
	events = new Event[size];
	for (int i = 0; i < this->length; i++) this->events[i] = other.events[i];
	return *this;
}

Event& Calendar::operator [](const int index)
{
	return events[index];
}

const Event& Calendar::operator [](const int index) const
{
	return events[index];
}

