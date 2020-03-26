#include "Date.h"

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

unsigned int Date::maxDays()
{
	return maxDays(month, year);
}

unsigned int Date::maxDays(unsigned int month, unsigned int year)
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
	this->year += this->month / 12;
	this->month %= 12;
	this->day = day;
}

void Date::setMonth(unsigned int month)
{
	this->year += month / 12;
	this->month = month % 12;
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
	std::string res = (day < 10 ? "0" : "") + std::to_string(day);
	res += (month < 10 ? ".0" : ".") + std::to_string(month);
	res += "." + std::to_string(year);
	return res;
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

WeekDay Date::getWeekDay()
{
	return getWeekDay(day, month, year);
}

WeekDay Date::getWeekDay(unsigned int day, unsigned int month, unsigned int year)
{
	WeekDay weekDays[] = { Sat, Sun, Mon, Tue, Wed, Thu, Fri };
	if (month < 3)
	{
		month += 12;
		year--;
	}
	unsigned int wd = ((month + 1) * 26 / 10 + day + (year % 100) + (year % 100) / 4 + (year / 100) / 4 - (year / 100) * 2) % 7;
	return weekDays[wd];
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
	while (qt = maxDays(month, year) < day)
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
	year -= year == 0 ? 1 : 0;
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

std::istream& operator >>(std::istream &in, Date &date)
{
	char c;
	in >> date.day >> c >> date.month >> c >> date.year;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Date &date)
{
	std::string res = (date.day < 10 ? "0" : "") + std::to_string(date.day);
	res += (date.month < 10 ? ".0" : ".") + std::to_string(date.month);
	res += "." + std::to_string(date.year);
	out << res;
	return out;
}