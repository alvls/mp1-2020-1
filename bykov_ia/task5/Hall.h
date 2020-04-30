#pragma once
#include <vector>
using std::vector;

class Hall
{
	struct VIPZone
	{
		double Cost;
		int Rows;
		int Cols;
	};
	struct DefaultZone
	{
		double Cost;
		int Rows;
		int Cols;
	};

	DefaultZone defaultZone;
	VIPZone vipZone;

	int** HallMatrix;
	int FreeDefPlaces;
	int FreeVIPPlaces;
public:
	Hall();
	Hall(double vipCost, int vipRows, int vipCols, double defCost, int defRows, int defCols);
	Hall(const Hall& hall);
	Hall& operator=(const Hall& hall);
	void Init();
	~Hall();

	void SetVIPCost(double cost);
	void SetVIPCols(int cols);
	void SetVIPRows(int rows);
	void SetDefCost(double cost);
	void SetDefCols(int cols);
	void SetDefRows(int rows);

	int GetVIPCols();
	int GetVIPRows();
	double GetCost(int type);
	int GetDefCols();
	int GetDefRows();

	void DecFreePlaces(int type);
	void IncFreePlaces(int type);
	int GetFreePlaces(int type);

	void BuyTicket(int type, int& row, int& seat);
	void ReturnTicket(vector<int> rows, vector<int> cols, int type);
};
