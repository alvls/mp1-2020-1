#include "Temperature.h"

Temperature::Temperature(double t)
{
	this->t = t;
}

Temperature::Temperature(const Temperature &other)
{
	this->t = other.t;
}

Temperature::~Temperature() {}

void Temperature::setTemp(double t)
{
	this->t = t;
}

double Temperature::getTemp()
{
	return t;
}

void Temperature::print()
{
	std::cout << "Temperature: " << t << " C" << std::endl;
}

Temperature& Temperature::operator =(const Temperature &other)
{
	this->t = other.t;
	return *this;
}

Temperature& Temperature::operator =(const double &value)
{
	this->t = value;
	return *this;
}

Temperature Temperature::operator +(const Temperature &other)
{
	Temperature temp(this->t + other.t);
	return temp;
}

Temperature Temperature::operator +(const double &value)
{
	Temperature temp(this->t + value);
	return temp;
}

Temperature Temperature::operator -(const Temperature &other)
{
	Temperature temp(this->t - other.t);
	return temp;
}

Temperature Temperature::operator -(const double &value)
{
	Temperature temp(this->t - value);
	return temp;
}

Temperature Temperature::operator *(const double &value)
{
	Temperature temp(this->t * value);
	return temp;
}

Temperature Temperature::operator /(const double &value)
{
	Temperature temp(this->t / value);
	return temp;
}

bool Temperature::operator <=(const Temperature &other)
{
	return this->t <= other.t;
}

bool Temperature::operator >=(const Temperature &other)
{
	return this->t >= other.t;
}

bool Temperature::operator >(const Temperature &other)
{
	return !(*this <= other);
}

bool Temperature::operator <(const Temperature &other)
{
	return !(*this >= other);
}

bool Temperature::operator ==(const Temperature &other)
{
	return this->t == other.t;
}

bool Temperature::operator !=(const Temperature &other)
{
	return !(this->t == other.t);
}

double Temperature::toFahrenheit()
{
	return t * 9 / 5 + 32;
}
double Temperature::toKelvin()
{
	return t + 273.15;
}
double Temperature::toRankine()
{
	return t * 9 / 5 + 491.67;
}
double Temperature::toReaumur()
{
	return t * 4 / 5;
}
