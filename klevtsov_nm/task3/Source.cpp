#include "Tabulator.h"

void setFunction(Tabulator &);
void saveValues(Tabulator &);

int main(void)
{
	Tabulator tabulator;
	Section section;
	int variable;
	while(true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1) Set function." << std::endl
			<< "2) Set amount of tabs." << std::endl
			<< "3) Get amount of tabs." << std::endl
			<< "4) Set section." << std::endl
			<< "5) Get section." << std::endl
			<< "6) Perform tabulation." << std::endl
			<< "7) Print values." << std::endl
			<< "8) Save values" << std::endl
			<< "9) Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			setFunction(tabulator);
			break;
		case 2:
			int amt;
			std::cout << "Enter amount of tabs: " << std::endl;
			std::cin >> amt;
			tabulator.setAmount(amt);
			break;
		case 3:
			std::cout << tabulator.getAmount() << std::endl;
			break;
		case 4:
			std::cin >> section;
			tabulator.setSection(section);
			break;
		case 5:
			std::cout << tabulator.getSection();
			break;
		case 6:
			tabulator.performTabulation();
			break;
		case 7:
			tabulator.printValues();
			break;
		case 8:
			saveValues(tabulator);
			break;
		case 9:
			return 0;
			break;
		}
		std::cout << std::endl << "______________" << std::endl;
	}
}

void setFunction(Tabulator &tabulator)
{
	double(*funcarr[])(double) = { exp,sin,cos,tan,asin,acos,atan,log,sqrt };
	int variable;
	do
	{
		std::cout << "Choose function:" << std::endl
			<< "1) exp(x)" << std::endl
			<< "2) sin(x)" << std::endl
			<< "3) cos(x)" << std::endl
			<< "4) tg(x)" << std::endl
			<< "5) arcsin(x)" << std::endl
			<< "6) arccos(x)" << std::endl
			<< "7) atctg(x)" << std::endl
			<< "8) ln(x)" << std::endl
			<< "9) sqrt(x)" << std::endl;
		std::cin >> variable;
		if (variable >= 1 && variable <= 9) tabulator.setFunction(funcarr[variable - 1]);
	} while (variable < 1 || variable > 9);
}

void saveValues(Tabulator &tabulator)
{
	std::string path;
	std::cout << "Enter path: ";
	std::cin >> path;
	tabulator.saveValues(path);
}