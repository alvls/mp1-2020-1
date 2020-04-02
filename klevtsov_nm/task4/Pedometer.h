#pragma once
#include <string>
#include <iostream>
#include <fstream>
enum class WeekDay { Sat, Sun, Mon, Tue, Wed, Thu, Fri};

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

//----------------------------------------------------------------------------------------------
class Time
{
private:
	unsigned int hour, min, sec;
public:
	Time(unsigned int = 0, unsigned int = 0, unsigned int = 0);
	Time(const Time &);
	~Time();

	void setTime(unsigned int, unsigned int, unsigned int);
	void setHour(unsigned int);
	void setMin(unsigned int);
	void setSec(unsigned int);
	unsigned int getHour();
	unsigned int getMin();
	unsigned int getSec();
	std::string getTime();

	Time& operator =(const Time &);
	Time operator +(const Time &);
	Time operator -(const Time &);

	bool operator ==(const Time &);
	bool operator !=(const Time &);
	bool operator >=(const Time &);
	bool operator <=(const Time &);
	bool operator >(const Time &);
	bool operator <(const Time &);

	friend std::istream& operator >>(std::istream &, Time &);
	friend std::ostream& operator <<(std::ostream &, const Time &);
};

//----------------------------------------------------------------------------------------------
class Count
{
private:
	Date date;
	std::pair<Time, Time> interval;
	unsigned int steps;
public:
	Count(const Date & = Date(), const std::pair<Time, Time> & = std::pair<Time, Time>(Time(), Time()), unsigned int = 0);
	Count(const Count &);
	~Count();

	void setCount(const Date &, const std::pair<Time, Time> &, unsigned int);
	void setDate(const Date &);
	void setInterval(const std::pair<Time, Time> &);
	void setSteps(unsigned int);
	Date getDate();
	std::pair<Time, Time> getInterval();
	unsigned int getSteps();
	std::string getInfo();

	Count& operator =(const Count &);

	friend std::istream& operator >>(std::istream &, Count &);
	friend std::ostream& operator <<(std::ostream &, const Count &);
};

//----------------------------------------------------------------------------------------------
class Pedometer
{
private:
	Count *counts;
	Date beginnigDate;
	size_t size;
	size_t length;
	void incSize();
public:
	Pedometer(size_t = 0);
	Pedometer(const Pedometer &);
	~Pedometer();

	size_t getLength();
	void incLength(size_t length);
	void pushBack(Count &count);
	void popBack();
	void clear();
	bool empty();

	void setBeginningDate(const Date & = Date());
	Date getBeginningDate();
	unsigned int getAverageSteps(unsigned int = 0);
	unsigned int getAverageSteps(WeekDay);
	Count getMaxDaysCount(unsigned int = 0);
	void writeTo(const std::string & = "counts.txt");
	void readFrom(const std::string & = "counts.txt");

	Pedometer& operator =(const Pedometer &other);
	Count& operator [](size_t index);
	const Count& operator [](size_t index) const;
};