#include <string>
#include "Temperature.h"

double getTemp(Temperature &temp, std::string &unit)
{
	int variable;
	do
	{
		std::cout << "Select:" << std::endl
			<< "1)Celsius" << std::endl
			<< "2)Fahrenheit" << std::endl
			<< "3)Kelvin" << std::endl
			<< "4)Rankine" << std::endl
			<< "5)Reaumur" << std::endl;
		std::cin >> variable;
	} while (variable < 1 || variable > 5);
	switch (variable)
	{
	case 1: unit = " C"; return temp.getTemp();
	case 2: unit = " F"; return temp.toFahrenheit();
	case 3: unit = " K"; return temp.toKelvin();
	case 4: unit = " Ra"; return temp.toRankine();
	case 5: unit = " R"; return temp.toReaumur();
	}
}

int main(void)
{
	Temperature temp;
	std::string unit;
	int variable;
	while (true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1)Set temperature (Celsius)" << std::endl
			<< "2)Get temperature" << std::endl
			<< "3)Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			std::cout << "Enter temperature (Celsius): ";
			std::cin >> temp;
			break;
		case 2:
			std::cout << "Temperature: " << getTemp(temp, unit) << unit << std::endl;
			break;
		case 3:
			return 0;
			break;
		}
		std::cout << std::endl;
	}
}