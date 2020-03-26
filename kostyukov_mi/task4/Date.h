#pragma once
#include <string>
#include <iostream>
#include <fstream>
enum WeekDay { Sat, Sun, Mon, Tue, Wed, Thu, Fri};

class Date
{
private:
	unsigned int day, month, year;
	unsigned int maxDays();
	Date diff(const Date &, const Date &);
public:
	Date(unsigned int = 1, unsigned int = 1, unsigned int = 1);
	Date(const Date &);
	~Date();

	bool leapYear(unsigned int);
	unsigned int maxDays(unsigned int, unsigned int);

	void setDate(unsigned int, unsigned int, unsigned int);
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();
	std::string getDate();
	Date getDiff(const Date &);

	WeekDay getWeekDay();
	WeekDay getWeekDay(unsigned int, unsigned int, unsigned int);

	Date& operator =(const Date &);
	Date operator +(const Date &);
	Date operator -(const Date &);

	bool operator ==(const Date &);
	bool operator !=(const Date &);
	bool operator >=(const Date &);
	bool operator <=(const Date &);
	bool operator >(const Date &);
	bool operator <(const Date &);

	friend std::istream& operator >>(std::istream &, Date &);
	friend std::ostream& operator <<(std::ostream &, const Date &);
};