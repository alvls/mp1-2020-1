#pragma once

struct Observation
{
	int day, month, year;
	int time;
	int t;
};

class Weather
{
private:
	Observation start;
	Observation data[24][365];
	int days[12] = { 31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31 };
	int Days_before(int);
public:
	Weather();
	Weather(const Weather &);
	Weather& operator=(const Weather &);
	~Weather();
	void Set_start(int, int, int, int);
	Observation Get_start();
	void Set_observation(int, int, int, int, int);
	int Get_T(int, int, int, int);
	void Save_to_file(char*);
	void Read_from_file(char*);
	void Set_series(int, int, int, int, int, int*);
	double Search_average_T_for_year();
	double Search_average_T_for_month(int, int);
	double Search_average_T_for_day(int, int, int);
	double Search_average_T(int, int, int, int);
};