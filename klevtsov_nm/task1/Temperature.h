#pragma once
#include <iostream>
class Temperature
{
private:
	double t;
public:
	Temperature(double t = 0);
	Temperature(const Temperature &other);
	~Temperature();

	void setTemp(double t);
	double getTemp();
	void print();

	Temperature& operator =(const Temperature &other);
	Temperature& operator =(const double &value);
	Temperature operator +(const Temperature &other);
	Temperature operator +(const double &value);
	Temperature operator -(const Temperature &other);
	Temperature operator -(const double &value);
	Temperature operator *(const double &value);
	Temperature operator /(const double &value);

	bool operator <=(const Temperature &other);
	bool operator >=(const Temperature &other);
	bool operator >(const Temperature &other);
	bool operator <(const Temperature &other);
	bool operator ==(const Temperature &other);
	bool operator !=(const Temperature &other);

	friend std::istream& operator >>(std::istream &in, Temperature &temp)
	{
		in >> temp.t;
		return in;
	}
	friend std::ostream& operator <<(std::ostream &out, const Temperature &temp)
	{
		out << temp.t;
		return out;
	}

	double toFahrenheit();
	double toKelvin();
	double toRankine();
	double toReaumur();
};

