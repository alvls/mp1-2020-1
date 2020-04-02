#include "Pedometer.h"

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
	WeekDay weekDays[] = { WeekDay::Sat, WeekDay::Sun, WeekDay::Mon, WeekDay::Tue, WeekDay::Wed, WeekDay::Thu, WeekDay::Fri };
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

//----------------------------------------------------------------------------------------------
Time::Time(unsigned int hour, unsigned int min, unsigned int sec)
{
	setHour(hour);
	setMin(min);
	setSec(sec);
}

Time::Time(const Time &other) : hour(other.hour), min(other.min), sec(other.sec) {}

Time::~Time() {}

void Time::setTime(unsigned int hour, unsigned int min, unsigned int sec)
{
	setHour(hour);
	setMin(min);
	setSec(sec);
}

void Time::setHour(unsigned int hour)
{
	this->hour = hour % 24;
}

void Time::setMin(unsigned int min)
{
	this->hour += min / 60;
	this->hour %= 24;
	this->min = min % 60;
}

void Time::setSec(unsigned int sec)
{
	this->min += sec / 60;
	this->hour += this->min / 60;
	this->min %= 60;
	this->hour %= 24;
	this->sec = sec % 60;
}

unsigned int Time::getHour()
{
	return hour;
}

unsigned int Time::getMin()
{
	return min;
}

unsigned int Time::getSec()
{
	return sec;
}

std::string Time::getTime()
{
	std::string res = (hour < 10 ? "0" : "") + std::to_string(hour);
	res += (min < 10 ? ":0" : ":") + std::to_string(min);
	res += (sec < 10 ? ":0" : ":") + std::to_string(sec);
	return res;
}

Time& Time::operator =(const Time &other)
{
	this->hour = other.hour;
	this->min = other.min;
	this->sec = other.sec;
	return *this;
}

Time Time::operator +(const Time &other)
{
	unsigned int hour = this->hour + other.hour;
	unsigned int min = this->min + other.min;
	unsigned int sec = this->sec + other.sec;
	return Time(hour, min, sec);
}

Time Time::operator -(const Time &other)
{
	unsigned int hour, min, sec;
	hour = this->hour > other.hour ? this->hour - other.hour : 24 + this->hour - other.hour;
	if (this->min < other.min)
	{
		min = 60 + this->min - other.min;
		hour = hour == 0 ? 23 : hour - 1;
	}
	else min = this->min - other.min;
	if (this->sec < other.sec)
	{
		sec = 60 + this->sec - other.sec;
		if (min == 0)
		{
			min = 59;
			hour = hour == 0 ? 23 : hour - 1;
		}
		else min--;
	}
	return Time(hour, min, sec);
}

bool Time::operator ==(const Time &other)
{
	return this->hour == other.hour && this->min == other.min && this->sec == other.sec;
}

bool Time::operator !=(const Time &other)
{
	return !(*this == other);
}

bool Time::operator >=(const Time &other)
{
	return !(*this < other);
}

bool Time::operator <=(const Time &other)
{
	return !(*this > other);
}

bool Time::operator >(const Time &other)
{
	if (this->hour > other.hour) return true;
	if (this->hour < other.hour) return false;
	if (this->min > other.min) return true;
	if (this->min < other.min) return false;
	if (this->sec > other.sec) return true;
	return false;
}

bool Time::operator <(const Time &other)
{
	if (this->hour < other.hour) return true;
	if (this->hour > other.hour) return false;
	if (this->min < other.min) return true;
	if (this->min > other.min) return false;
	if (this->sec < other.sec) return true;
	return false;
}

std::istream& operator >>(std::istream &in, Time &time)
{
	char c;
	in >> time.hour >> c >> time.min >> c >> time.sec;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Time &time)
{
	std::string res = (time.hour < 10 ? "0" : "") + std::to_string(time.hour);
	res += (time.min < 10 ? ":0" : ":") + std::to_string(time.min);
	res += (time.sec < 10 ? ":0" : ":") + std::to_string(time.sec);
	out << res;
	return out;
}

//----------------------------------------------------------------------------------------------
Count::Count(const Date &date, const std::pair<Time, Time> &interval, unsigned int steps) : date(date), interval(interval), steps(steps) {}

Count::Count(const Count &other) : date(other.date), interval(other.interval), steps(other.steps) {}

Count::~Count() {}

void Count::setCount(const Date &date, const std::pair<Time, Time> &interval, unsigned int steps)
{
	this->date = date;
	this->interval = interval;
	this->steps = steps;
}

void Count::setDate(const Date &date)
{
	this->date = date;
}

void Count::setInterval(const std::pair<Time, Time> &interval)
{
	this->interval = interval;
}

void Count::setSteps(unsigned int steps)
{
	this->steps = steps;
}

Date Count::getDate()
{
	return date;
}

std::pair<Time, Time> Count::getInterval()
{
	return interval;
}

unsigned int Count::getSteps()
{
	return steps;
}

std::string Count::getInfo()
{
	return "Date: " + date.getDate() + "\nInterval: " + interval.first.getTime() + "-" + interval.second.getTime() + "\nAmount of steps: " + std::to_string(steps);
}

Count& Count::operator =(const Count &other)
{
	this->date = other.date;
	this->interval = other.interval;
	this->steps = other.steps;
	return *this;
}

std::istream& operator >>(std::istream &in, Count &count)
{
	char c;
	in >> count.date >> count.interval.first >> c >> count.interval.second >> count.steps;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Count &count)
{
	out << count.date << " " << count.interval.first << "-" << count.interval.second << " " << count.steps;
	return out;
}

//----------------------------------------------------------------------------------------------
Pedometer::Pedometer(size_t length) : length(length), size(10)
{
	while (length > size) size *= 2;
	counts = new Count[size];
}

Pedometer::Pedometer(const Pedometer &other) : length(other.length), size(other.size)
{
	counts = new Count[size];
	for (size_t i = 0; i < length; i++) this->counts[i] = other.counts[i];
}

Pedometer::~Pedometer()
{
	delete[] counts;
}

void Pedometer::incSize()
{
	size *= 2;
	Count *temp = new Count[size];
	for (size_t i = 0; i < length; i++) temp[i] = counts[i];
	delete[] counts;
	counts = temp;
}

void Pedometer::incLength(size_t length)
{
	while (length > size) incSize();
	if (length < this->length)
	{
		Count *temp = new Count[size];
		for (size_t i = 0; i < length; i++) temp[i] = counts[i];
		delete[] counts;
		counts = temp;
	}
	this->length = length;
}

size_t Pedometer::getLength()
{
	return length;
}

void Pedometer::pushBack(Count &other)
{
	if (other.getDate() < beginnigDate) throw "Date of this count is earlier than the beginning date";
	if (length + 1 > size) incSize();
	counts[length++] = other;
}

void Pedometer::popBack()
{
	counts[--length].setCount(Date(), std::pair<Time, Time>(Time(), Time()), 0);
}

void Pedometer::clear()
{
	delete[] counts;
	length = 0;
	counts = new Count[size];
}

bool Pedometer::empty()
{
	return length == 0 ? true : false;
}

void Pedometer::setBeginningDate(const Date &date)
{
	this->beginnigDate = date;
}

Date Pedometer::getBeginningDate()
{
	return beginnigDate;
}

unsigned int Pedometer::getAverageSteps(unsigned int month)
{
	unsigned int sum = 0, qt = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (month == 0 || month == counts[i].getDate().getMonth())
		{
			sum += counts[i].getSteps();
			qt++;
		}
	}
	return sum / qt;
}

unsigned int Pedometer::getAverageSteps(WeekDay wd)
{
	unsigned int sum = 0, qt = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (wd == counts[i].getDate().getWeekDay())
		{
			sum += counts[i].getSteps();
			qt++;
		}
	}
	if (qt == 0) return qt;
	return sum / qt;
}

Count Pedometer::getMaxDaysCount(unsigned int month)
{
	Count res;
	unsigned int max = 0;
	for (size_t i = 1; i < length; i++)
	{
		if (month == 0 || month == counts[i].getDate().getMonth())
		{
			if (max < counts[i].getSteps())
			{
				res = counts[i];
				max = res.getSteps();
			}
		}
	}
	if (max == 0) throw "Maximum quantity of steps doesn't exist!";
	return res;
}

void Pedometer::writeTo(const std::string &path)
{
	std::fstream file;
	file.open(path, std::fstream::out);
	if (!file.is_open())
	{
		std::cout << "File not open!" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < length - 1; i++)
		{
			file << counts[i] << std::endl;
		}
		file << counts[length - 1];
		std::cout << "Saving succeed!" << std::endl;
	}
	file.close();
}

void Pedometer::readFrom(const std::string &path)
{
	std::fstream file;
	file.open(path, std::fstream::in);
	if (!file.is_open())
	{
		std::cout << "File not open!" << std::endl;
	}
	else
	{
		clear();
		while (!file.eof())
		{
			Count count;
			file >> count;
			pushBack(count);
		}
	}
	file.close();
}

Pedometer& Pedometer::operator =(const Pedometer &other)
{
	this->length = other.length;
	this->size = other.size;
	delete[] counts;
	counts = new Count[size];
	for (size_t i = 0; i < this->length; i++) this->counts[i] = other.counts[i];
	return *this;
}

Count& Pedometer::operator [](size_t index)
{
	return counts[index];
}

const Count& Pedometer::operator [](size_t index) const
{
	return counts[index];
}