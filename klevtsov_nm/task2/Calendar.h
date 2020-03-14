#pragma once
#include <string>
#include <iostream>
class Date
{
private:
	unsigned int day, month, year;
	int maxDays();
	Date diff(const Date &first, const Date &second);
public:
	Date(unsigned int day = 1, unsigned int month = 1, unsigned int year = 1);
	Date(const Date &other);
	~Date();

	bool leapYear(unsigned int year);
	int maxDays(unsigned int month, unsigned int year);

	void setDate(unsigned int day, unsigned int month, unsigned int year);
	void setDay(unsigned int day);
	void setMonth(unsigned int month);
	void setYear(unsigned int year);
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();
	std::string getDate();
	Date getDiff(const Date &date);

	Date& operator =(const Date &other);
	Date operator +(const Date &other);
	Date operator -(const Date &other);

	bool operator ==(const Date &other);
	bool operator !=(const Date &other);
	bool operator >=(const Date &other);
	bool operator <=(const Date &other);
	bool operator >(const Date &other);
	bool operator <(const Date &other);

	friend std::istream& operator >>(std::istream &in, Date &date)
	{
		std::cout << "Enter date(dd mm yyyy): ";
		in >> date.day >> date.month >> date.year;
		return in;
	}
	friend std::ostream& operator <<(std::ostream &out, const Date &date)
	{
		std::string res = (date.day < 10 ? "0" : "") + std::to_string(date.day);
		res += (date.month < 10 ? ".0" : ".") + std::to_string(date.month);
		res += "." + std::to_string(date.year);
		out <<  res;
		return out;
	}
};

//----------------------------------------------------------------------------------------------
class Event
{
private:
	Date date;
	std::string name;
public:
	Event();
	Event(Date date, std::string name);
	Event(const Event &other);
	~Event();

	void setEvent(Date date, std::string name);
	void setEvent(unsigned int day, unsigned int month, unsigned int year, std::string name);
	std::string getEvent();
	Date getEventDate();
	std::string getName();
	Date getDiff(const Date &date);

	Event& operator =(const Event &other);

	friend std::istream& operator >>(std::istream &in, Event &e)
	{
		in >> e.date;
		std::cout << "Enter event name: ";
		getline(in, e.name);
		getline(in, e.name);
		return in;
	}
	friend std::ostream& operator <<(std::ostream &out, const Event &e)
	{
		out << e.date << " - " << e.name;
		return out;
	}
};

//----------------------------------------------------------------------------------------------
class Calendar
{
private:
	Event *events;
	int size;
	int length;
	void incSize();
public:
	Calendar(int length = 0);
	Calendar(const Calendar &other);
	~Calendar();

	int getLength();
	void incLength(int length);
	void push_back(const Event &event);
	void pop_back();
	void clear();
	bool empty();
	void shiftEvent(std::string &name, const Date &date, unsigned char c);
	void print();

	Calendar& operator =(const Calendar &other);
	Event& operator [](const int index);
	const Event& operator [](const int index) const;
};