#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

class Section
{
private:
	double leftBoarder;
	double rightBoarder;
public:
	Section(double = 1, double = 0);
	Section(const Section &);
	~Section();

	void setSection(double = 1, double = 0);
	void setLeftBoarder(double);
	void setRightBoarder(double);
	double getLeftBoarder();
	double getRightBoarder();
	std::string getSection();

	Section& operator =(const Section &);

	friend std::istream& operator >>(std::istream &, Section &);
	friend std::ostream& operator <<(std::ostream &, const Section &);
};

//--------------------------------------------------------------------------------
class Tabulator
{
private:
	int amt;
	Section section;
	double(*func)(double);
	std::vector<double> values;
public:
	Tabulator(int = 1, const Section & = Section(), double(*)(double) = [](double x)
	{
		return x;
	});
	Tabulator(int, double, double, double(*)(double));
	Tabulator(const Tabulator &);
	~Tabulator();

	void setFunction(double(*)(double));
	void setAmount(int);
	void setSection(const Section &);
	void setSection(double = 1, double = 0);
	double(*getFunction())(double);
	int getAmount();
	Section getSection();

	void performTabulation();
	void printValues();
	void saveValues(std::string);

	Tabulator& operator =(const Tabulator &);
};