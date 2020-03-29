#include <iostream>
#include "Weather.h"
using namespace std;


Weather::Weather()
{
	start.day = 0;
	start.month = 0;
	start.year = 0;
	start.time = 0;
	start.t = 0;
	for (int j = 0; j < 365; j++)
		for (int i = 0; i < 24; i++)
		{
			data[i][j] = start;
		}
}

Weather::Weather(const Weather &x)
{
	start = x.start;
	for (int j = 0; j < 365; j++)
		for (int i = 0; i < 24; i++)
		{
			data[i][j] = x.data[i][j];
		}
}

Weather & Weather::operator=(const Weather &x)
{
	if (this ==  &x)
	{
		return *this;
	}
	start = x.start;
	for (int j = 0; j < 365; j++)
		for (int i = 0; i < 24; i++)
		{
			data[i][j] = x.data[i][j];
		}
	return *this;
}

Weather::~Weather()
{
}

void Weather::Set_start(int d, int m, int y, int h)
{
	start.day = d;
	start.month = m;
	start.year = y;
	start.time = h;
	start.t = 0;
}

Observation Weather::Get_start()
{
	return start;
}

void Weather::Set_observation(int d, int m, int y, int h, int t)
{
	Observation temp;
	temp.day = d;
	temp.month = m;
	temp.year = y;
	temp.time = h;
	temp.t = t;
	int d1 = start.year * 365 + Days_before(start.month) + start.day;
	int d2 = y * 365 + Days_before(m) + d;
	if (d2 < d1)
	{
		cout << "Дата раньше, чем начало наблюдений" << endl;
		return;
	}
	if (d2 > d1 + 365)
	{
		cout << "Дата больше, чем окончание наблюдений" << endl;
		return;
	}
	data[h][d2 - d1] = temp;
}

int Weather::Get_T(int d, int m, int y, int h)
{
	int d1 = start.year * 365 + Days_before(start.month) + start.day;
	int d2 = y * 365 + Days_before(m) + d;
	Observation temp = data[h][d2 - d1];
	return temp.t;
}

void Weather::Save_to_file(char* name)
{
	FILE* out;
	fopen_s(&out, name, "w");

	for (int j = 0; j < 365; j++)
		for (int i = 0; i < 24; i++)
		{
			fprintf(out, "%d %d %d %d %d\n", 
				data[i][j].day, data[i][j].month, data[i][j].year, 
				data[i][j].time, data[i][j].t);
		}
	fclose(out);
}

void Weather::Read_from_file(char* name)
{
	FILE* in;
	errno_t err = fopen_s(&in, name, "r");
	if (in == NULL)
	{
		return;
	}
	char r[100];
	int j = 0, i = 0;
	while (fgets(r, 100, in))
	{
		r[strlen(r) - 1] = 0;
		sscanf_s(r, "%d %d %d %d %d", &data[i][j].day, &data[i][j].month, &data[i][j].year,
			&data[i][j].time, &data[i][j].t);
		i++;
		if (i == 24)   //чтобы ходить по столбикам
		{
			i = 0; 
			j++;
		}
	}
	fclose(in);
}

void Weather::Set_series(int d, int m, int y, int from, int to)
{
	for (int h = from; h <= to; h++)
	{
		int t;
		cout << "Введите температуру для " << h << ": ";
		cin >> t;
		Set_observation(d, m, y, h, t);
	}
}

double Weather::Search_average_T_for_year()
{
	double a = 0;
	int d = 0;
	for (int i = 0; i < 365 * 24; i++)
	{
		if (data[i % 24][i / 24].year == 0)
			continue;
		a += data[i % 24][i / 24].t;  //индексы часа и дня
		d++;
	}
	return (a / d);

}

double Weather::Search_average_T_for_month(int m, int y)
{
	double a = 0;
	for (int d = 1; d <= days[m - 1]; d++)
	{
		for(int h = 0; h < 24; h++)
		a += Get_T(d, m, y, h); 
	}
	return (a / days[m - 1]);
}

double Weather::Search_average_T_for_day(int d, int m, int y)
{
	double a = 0;
	for (int h = 0; h < 24; h++)
	{
		a += Get_T(d, m, y, h);
	}
	return (a / 24);
}

double Weather::Search_average_T(int m, int y, int h1, int h2)
{
	double a = 0;
	for (int d = 1; d <= days[m - 1]; d++)
	{
		for (int h = h1; h <= h2; h++)
			a += Get_T(d, m, y, h); 
	}
	return (a / days[m - 1]);
}

int Weather::Days_before(int m)
{
	int sum = 0;
	for (int i = 0; i < m - 1; i++)
	{
		sum += days[i];
	}
	return sum;
}