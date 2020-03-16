#include "Tabulator.h"

Section::Section(double leftBorder, double rightBorder):rightBorder(rightBorder), leftBorder(leftBorder) {}

Section::Section(const Section &other)
{
	this->leftBorder = other.leftBorder;
	this->rightBorder = other.rightBorder;
}

Section::~Section() {}

void Section::setSection(double leftBorder, double rightBorder)
{
	this->leftBorder = leftBorder;
	this->rightBorder = rightBorder;
}

void Section::setLeftBorder(double border)
{
	this->leftBorder = border;
}

void Section::setRightBorder(double border)
{
	this->rightBorder = border;
}

double Section::getLeftBorder()
{
	return leftBorder;
}

double Section::getRightBorder()
{
	return rightBorder;
}

std::string Section::getSection()
{
	return "[" + std::to_string(leftBorder) + "," + std::to_string(rightBorder) + "]";
}

Section& Section::operator =(const Section &other)
{
	this->leftBorder = other.leftBorder;
	this->rightBorder = other.rightBorder;
	return *this;

}

std::istream& operator >>(std::istream &in, Section &section)
{
	std::cout << "Enter left border: ";
	in >> section.leftBorder;
	std::cout << "Enter right border: ";
	in >> section.rightBorder;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Section &section)
{
	out << "[" + std::to_string(section.leftBorder) + "," + std::to_string(section.rightBorder) + "]" << std::endl;
	return out;
}

//--------------------------------------------------------------------------------
Tabulator::Tabulator(int amt, const Section &section, double(*func)(double)) : amt(amt), section(section), func(func) {}

Tabulator::Tabulator(int amt, double leftBorder, double rightBorder, double(*func)(double)) : amt(amt), section(leftBorder, rightBorder), func(func) {}

Tabulator::Tabulator(const Tabulator &other) : amt(other.amt), section(other.section), func(other.func) {}

Tabulator::~Tabulator() {}

void Tabulator::setFunction(double(*func)(double))
{
	this->func = func;
}

void Tabulator::setAmount(int amt)
{
	this->amt = amt;
}

void Tabulator::setSection(const Section &section)
{
	this->section = section;
}

void Tabulator::setSection(double leftBorder, double rightBorder)
{
	section.setSection(leftBorder, rightBorder);
}

double (*Tabulator::getFunction())(double)
{
	return func;
}

int Tabulator::getAmount()
{
	return amt;
}

Section Tabulator::getSection()
{
	return section;
}

void Tabulator::performTabulation()
{
	values.clear();
	double step = (section.getRightBorder() - section.getLeftBorder()) / (amt - 1);
	int i = 0;
	for (double x = section.getLeftBorder(); i < amt; x += step, i++)
	{
		values.push_back(func(x));
	}
}

void Tabulator::printValues()
{
	for (size_t i = 0; i < values.size(); i++)
	{
		std::cout << values[i] << std::endl;
	}
}

void Tabulator::saveValues(std::string path = "test.txt")
{
	std::fstream file;
	file.open(path, std::fstream::out);
	if (!file.is_open())
	{
		std::cout << "File not open" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < values.size(); i++)
		{
			file << values[i] << std::endl;
		}
		std::cout << "Saving succeed" << std::endl;
	}
	file.close();
}

Tabulator& Tabulator::operator =(const Tabulator &other)
{
	this->amt = other.amt;
	this->section = other.section;
	this->func = other.func;
	return *this;
}