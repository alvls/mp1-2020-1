#include <iostream>
#include <math.h>
using namespace std;

class temperature_converter {
private:
	double temp;
public:
	temperature_converter(double temp = 0)
	{
		set_temp(temp);
	}
	temperature_converter(const temperature_converter& temper)
	{
		set_temp(temper.temp);
	}
	void set_temp(double temp)
	{
		this->temp = temp;
	}
	double get_temp()
	{
		return this->temp;
	}
	void print()
	{
		std::cout << "Temperature: " << temp << "C" << std::endl;
	}

	temperature_converter& operator= (const temperature_converter& temper)
	{
		set_temp(temper.temp);
		return *this;
	}

	double fahrenheit()
	{
		return get_temp() * 1, 8 + 32;
	}
	double kelvin()
	{
		return get_temp() + 273;
	}
	double rankine()
	{
		return get_temp() * 1, 8 + 491, 67;
	}


};
double get_temp(temperature_converter& temp, std::string& unit)
{
	int mera;
	do
	{
		std::cout << "Select:" << std::endl
			<< "1)Celsius" << std::endl
			<< "2)Fahrenheit" << std::endl
			<< "3)Kelvin" << std::endl
			<< "4)Rankine" << std::endl;
		std::cin >> mera;
	} while (mera < 1 || mera > 4);
	switch (mera)
	{
	case 1: unit = " C"; return temp.get_temp(); break;
	case 2: unit = " F"; return temp.fahrenheit(); break;
	case 3: unit = " K"; return temp.kelvin(); break;
	case 4: unit = " Ra"; return temp.rankine(); break;

	}
}
int main(void)
{
	temperature_converter temp;
	std::string unit;
	int mera;
	while (true)
	{
		std::cout << "What do you want?" << std::endl
			<< "1)Set temperature (Celsius)" << std::endl
			<< "2)Get temperature" << std::endl
			<< "3)Exit" << std::endl;
		std::cin >> mera;
		switch (mera)
		{
		case 1:
			double t;
			std::cout << "Enter temperature (Celsius)" << std::endl;
			std::cin >> t;
			temp.set_temp(t);
			break;
		case 2:
			std::cout << "Temperature: " << get_temp(temp, unit) << unit << std::endl;
			break;
		case 3:
			return 0;
			break;
		}



	}

}