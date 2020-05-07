#include "Hall.h"

Hall::Hall() {}

Hall::Hall(double vipCost, int vipRows, int vipCols, double defCost, int defRows, int defCols) :
	vipZone({ vipCost, vipRows, vipCols }), defaultZone({ defCost, defRows, defCols })
{
	HallMatrix = new int* [defRows];
	for (int i = 0; i < defRows; i++)
	{
		HallMatrix[i] = new int[defCols];
	}

	Init();

	FreeVIPPlaces = vipCols * vipRows;
	FreeDefPlaces = defCols * defRows - FreeVIPPlaces;
}

Hall::Hall(const Hall& hall)
{
	vipZone.Cols = hall.vipZone.Cols;
	vipZone.Rows = hall.vipZone.Rows;
	vipZone.Cost = hall.vipZone.Cost;
	defaultZone.Cols = hall.defaultZone.Cols;
	defaultZone.Rows = hall.defaultZone.Rows;
	defaultZone.Cost = hall.defaultZone.Cost;
	FreeDefPlaces = hall.FreeDefPlaces;
	FreeVIPPlaces = hall.FreeVIPPlaces;


	HallMatrix = new int* [defaultZone.Rows];
	for (int i = 0; i < defaultZone.Rows; i++)
	{
		HallMatrix[i] = new int[defaultZone.Cols];
	}

	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			HallMatrix[i][j] = hall.HallMatrix[i][j];
}

Hall& Hall::operator=(const Hall& hall)
{
	if (this == &hall)
		return *this;
	
	vipZone.Cols = hall.vipZone.Cols;
	vipZone.Rows = hall.vipZone.Rows;
	vipZone.Cost = hall.vipZone.Cost;
	defaultZone.Cols = hall.defaultZone.Cols;
	defaultZone.Rows = hall.defaultZone.Rows;
	defaultZone.Cost = hall.defaultZone.Cost;
	FreeDefPlaces = hall.FreeDefPlaces;
	FreeVIPPlaces = hall.FreeVIPPlaces;

	HallMatrix = new int* [defaultZone.Rows];
	for (int i = 0; i < defaultZone.Rows; i++)
	{
		HallMatrix[i] = new int[defaultZone.Cols];
	}

	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			HallMatrix[i][j] = hall.HallMatrix[i][j];

	return *this;
}

void Hall::Init()
{
	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			if ((i < (defaultZone.Rows / 2 - vipZone.Rows / 2)) || (i > (defaultZone.Rows / 2 + vipZone.Rows / 2)) //center vip-zone
				|| (j < (defaultZone.Cols / 2 - vipZone.Cols / 2)) || (j > (defaultZone.Cols / 2 + vipZone.Cols / 2)))
				HallMatrix[i][j] = 0; //default
			else
				HallMatrix[i][j] = 2; //vip
}

Hall::~Hall()
{
	for (int i = 0; i < defaultZone.Rows; i++)
		delete[] HallMatrix[i];
}

void Hall::SetVIPCost(double cost) { vipZone.Cost = cost; }
void Hall::SetVIPCols(int cols) { vipZone.Cols = cols; }
void Hall::SetVIPRows(int rows) { vipZone.Rows = rows; }
void Hall::SetDefCost(double cost) { defaultZone.Cost = cost; }
void Hall::SetDefCols(int cols) { defaultZone.Cols = cols; }
void Hall::SetDefRows(int rows) { defaultZone.Rows = rows; }

int Hall::GetVIPCols() { return vipZone.Cols; }
int Hall::GetVIPRows() { return vipZone.Rows; }
int Hall::GetDefCols() { return defaultZone.Cols; }
int Hall::GetDefRows() { return defaultZone.Rows; }

double Hall::GetCost(int type)
{
	if (type == 0)
		return defaultZone.Cost;
	else
		return vipZone.Cost;
}

void Hall::DecFreePlaces(int type)
{
	if (type == 0)
		FreeDefPlaces--;
	else
		FreeVIPPlaces--;
}

void Hall::IncFreePlaces(int type)
{
	if (type == 0)
		FreeDefPlaces++;
	else
		FreeVIPPlaces++;
}

int Hall::GetFreePlaces(int type)
{
	if (type == 0)
		return FreeDefPlaces;
	else
		return FreeVIPPlaces;
}

void Hall::BuyTicket(int type, int& row, int& seat)
{
	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			if ((HallMatrix[i][j] == type) && (HallMatrix[i][j] != 1)) 
			{
				HallMatrix[i][j] = 1; //seat taken
				DecFreePlaces(type);
				row = i;
				seat = j;
				return;
			}
}

void Hall::ReturnTicket(vector<int> rows, vector<int> cols, int type)
{
	for (int i = 0; i < rows.size(); i++)
	{
		HallMatrix[rows[i]][cols[i]] = type;
		IncFreePlaces(type);
	}
}