#pragma once
#include "string"
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
class slaves {
private:
	int size_people;
	int count_people;
	int* arr_size_measusements;
	int* arr_count_measusements;
	//int size_measusements;
	//int count_measusements;
	int day;
	int mounth;
	int year;
	string* name_of_people;
	float** history_of_weight;
	int** history_of_day_of_measurement;
	int** history_of_mounth_of_measurement;
	int** history_of_year_of_measurement;

	int iscpm(int fd, int fm, int fy, int sd, int sm, int sy)
	{
		int res = 0;
		if (fy < sy)
		{
			res = -1;
		}
		else
		{
			if (fy > sy)
			{
				res = 1;
			}
			else
			{
				if (fm < sm)
				{
					res = -1;
				}
				else
					if (fm > sm)
					{
						res = 1;
					}
					else
					{
						if (fd < sd)
						{
							res = -1;
						}
						else
							if (fd > sd)
							{
								res = 1;
							}
					}

			}
		}
		return res;
	}
public:
	/*string getdata(int day_, int mounth_, int year_, int l)
	{
		string* Data;
		Data = new string[arr_count_measusements[l]];
		for (int i = 0; i < arr_count_measusements[l]; i++)
		{
			itoa(atoi(history_of_day_of_measurement[l][i].c_str()), Data[i], atoi(history_of_mounth_of_measurement[l][i].c_str());
		}
	}*/
	slaves(int size_measurements_ = 5)
	{
		size_people = size_measurements_;
		count_people = 0;
		//count_measusements = 0;
		//size_measusements = size_measurements_;
		arr_size_measusements = new int[size_people];
		arr_count_measusements = new int[size_people];

		name_of_people = new string[size_people];
		history_of_weight = new float* [size_people];
		history_of_day_of_measurement = new int* [size_people];
		history_of_mounth_of_measurement = new int* [size_people];
		history_of_year_of_measurement = new int* [size_people];
		for (int i = 0; i < size_people; i++)
			arr_count_measusements[i] = 0;
		for (int i = 0; i < size_people; i++)
		{
			arr_size_measusements[i] = 10;
			history_of_weight[i] = new float[10];
			history_of_day_of_measurement[i] = new int[10];
			history_of_mounth_of_measurement[i] = new int[10];
			history_of_year_of_measurement[i] = new int[10];
		}
		for (int i = 0; i < size_people; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				history_of_weight[i][j] = 0;
				history_of_day_of_measurement[i][j] = 0;
				history_of_mounth_of_measurement[i][j] = 0;
				history_of_year_of_measurement[i][j] = 0;
			}
		}
	}
	~slaves()
	{
		delete[] arr_size_measusements;
		delete[] arr_count_measusements;
		delete[] name_of_people;
		for (int j = 0; j < size_people; j++)
		{
			delete[] history_of_weight[j];
			delete[] history_of_day_of_measurement[j];
			delete[] history_of_mounth_of_measurement[j];
			delete[] history_of_year_of_measurement[j];
		}
		delete[] history_of_weight;
		delete[] history_of_mounth_of_measurement;
		delete[] history_of_day_of_measurement;
		delete[] history_of_year_of_measurement;
	}
	slaves(const slaves& tmp)
	{
		size_people = tmp.size_people;
		count_people = tmp.count_people;
		for (int i = 0; i < count_people; i++)
		{
			name_of_people[i] = tmp.name_of_people[i];
			arr_count_measusements[i] = tmp.arr_count_measusements[i];
			arr_size_measusements[i] = tmp.arr_size_measusements[i];
		}
		//day = tmp.day;
		//mounth = tmp.mounth;
		//year = tmp.year;
		for (int i = 0; i < count_people; i++)
		{
			for (int j = 0; j < arr_count_measusements[i]; j++)
			{
				history_of_weight[i][j] = tmp.history_of_weight[i][j];
				history_of_day_of_measurement[i][j] = tmp.history_of_day_of_measurement[i][j];
				history_of_mounth_of_measurement[i][j] = tmp.history_of_mounth_of_measurement[i][j];
				history_of_year_of_measurement[i][j] = tmp.history_of_year_of_measurement[i][j];
			}
		}
	}
	slaves& operator=(const slaves& tmp)
	{

		for (int i = 0; i < count_people; i++)
		{
			delete[] history_of_weight[i];
			delete[] history_of_day_of_measurement[i];
			delete[] history_of_mounth_of_measurement[i];
			delete[] history_of_year_of_measurement[i];
		}
		delete[] history_of_weight;
		delete[] history_of_mounth_of_measurement;
		delete[] history_of_day_of_measurement;
		delete[] history_of_year_of_measurement;
		count_people = tmp.count_people;

		size_people = tmp.size_people;
		for (int i = 0; i < size_people; i++)
		{
			arr_count_measusements[i] = tmp.arr_count_measusements[i];
			arr_size_measusements[i] = tmp.arr_size_measusements[i];
			history_of_weight[i] = new float[arr_size_measusements[i]];
			history_of_day_of_measurement[i] = new int[arr_size_measusements[i]];
			history_of_mounth_of_measurement[i] = new int[arr_size_measusements[i]];
			history_of_year_of_measurement[i] = new int[arr_size_measusements[i]];
		}
		for (int i = 0; i < size_people; i++)
		{
			name_of_people[i] = tmp.name_of_people[i];
			for (int j = 0; j < arr_count_measusements[i]; j++)
			{
				history_of_weight[i][j] = tmp.history_of_weight[i][j];
				history_of_day_of_measurement[i][j] = tmp.history_of_day_of_measurement[i][j];
				history_of_mounth_of_measurement[i][j] = tmp.history_of_mounth_of_measurement[i][j];
				history_of_year_of_measurement[i][j] = tmp.history_of_year_of_measurement[i][j];
			}
		}
		return *this;
	}
	void print(string d)
	{
		cout << d;
	}
	void print(float d)
	{
		cout << d;
	}
	void add(string name, int newday = 0, int newmounth = 0, int newyear = 0, float newweight = 0)
	{
		int l = -1;

		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name)
				l = i;
		}
		if (l > -1)
		{//3) задать наблюдение
			int L = -1;
			for (int i = 0; (i < arr_size_measusements[l]) && (L == -1); i++)
			{
				if (iscpm(history_of_day_of_measurement[l][i], history_of_mounth_of_measurement[l][i], history_of_year_of_measurement[l][i], newday, newmounth, newyear) == 0) { L = i; }
			}
			if (L >= 0)
			{
				history_of_weight[l][L] = newweight;
			}
			else
			{
				if (arr_count_measusements[l] < arr_size_measusements[l] - 1)
				{
					history_of_day_of_measurement[l][arr_count_measusements[l]] = newday;
					history_of_mounth_of_measurement[l][arr_count_measusements[l]] = newmounth;
					history_of_year_of_measurement[l][arr_count_measusements[l]] = newyear;
					history_of_weight[l][arr_count_measusements[l]++] = newweight;
				}
				else
				{
					float* a;
					a = new float[2 * arr_size_measusements[l]];
					int* b;
					b = new int[2 * arr_size_measusements[l]];
					int* c;
					c = new int[2 * arr_size_measusements[l]];
					int* d;
					d = new int[2 * arr_size_measusements[l]];
					for (int i = 0; i < arr_count_measusements[l]; i++)
					{
						a[i] = history_of_day_of_measurement[l][i];
						b[i] = history_of_mounth_of_measurement[l][i];
						c[i] = history_of_year_of_measurement[l][i];
						d[i] = history_of_weight[l][i];
					}
					delete[] history_of_weight[l];
					delete[] history_of_day_of_measurement[l];
					delete[] history_of_mounth_of_measurement[l];
					delete[] history_of_year_of_measurement[l];
					history_of_weight[l] = a;
					history_of_mounth_of_measurement[l] = c;
					history_of_day_of_measurement[l] = b;
					history_of_year_of_measurement[l] = d;
					history_of_day_of_measurement[l][arr_count_measusements[l]] = newday;
					history_of_mounth_of_measurement[l][arr_count_measusements[l]] = newmounth;
					history_of_year_of_measurement[l][arr_count_measusements[l]] = newyear;
					history_of_weight[l][arr_count_measusements[l]] = newweight;
					arr_count_measusements[l]++;
					arr_size_measusements[l] *= 2;
				}
			}
		}
		else
		{
			if (count_people < size_people - 1)
			{
				name_of_people[count_people] = name;
				history_of_weight[count_people] = new float[10];
				history_of_day_of_measurement[count_people] = new int[10];
				history_of_mounth_of_measurement[count_people] = new int[10];
				history_of_year_of_measurement[count_people] = new int[10];
				arr_count_measusements[count_people] = 1;
				history_of_weight[count_people][0] = newweight;
				history_of_day_of_measurement[count_people][0] = newday;
				history_of_mounth_of_measurement[count_people][0] = newmounth;
				history_of_year_of_measurement[count_people++][0] = newyear;

			}
		}

	}
	int Getcount_measurement(string name)//4) узнать вес в выбранном наблюдении
	{
		int l = -1;
		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name) { l = i; }
		}
		if (l >= 0)
		{
			return arr_count_measusements[l];
		}
		else return 0;
	}
	float* GetWeight(string name)//4) узнать вес в выбранном наблюдении
	{
		int l = -1;
		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name) { l = i; }
		}
		if (l >= 0)
		{
			return history_of_weight[l];
		}
		else return NULL;
	}
	float Getminweight(string name, int mounth_ = 0)
	{
		int l = -1;
		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name)
				l = i;
		}
		if (l > -1)
		{

			float min = 500;
			int L = -1;
			if (mounth_ == 0)
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					if (history_of_weight[l][i] < min)
					{
						min = history_of_weight[l][i];
						L = i;
					}
				}
				return min;
			}
			else
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					if (history_of_mounth_of_measurement[l][i] == mounth_)
					{
						if (history_of_weight[l][i] < min)
						{
							min = history_of_weight[l][i];
							L = i;
						}
					}
				}
				if (L > -1)
					return min;
			}
		}
		else
			return -1;
	}
	float Getmaxweight(string name, int mounth_ = 0)
	{
		int l = -1;
		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name)
				l = i;
		}
		if (l > -1)
		{
			float max = 0;
			int L = -1;
			if (mounth_ == 0)
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					if (history_of_weight[l][i] > max)
					{
						max = history_of_weight[l][i];
						L = i;
					}
				}
				return max;
			}
			else
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					if (history_of_mounth_of_measurement[l][i] == mounth_)
					{
						if (history_of_weight[l][i] > max)
						{
							max = history_of_weight[l][i];
							L = i;
						}
					}
				}
				return max;
			}

		}
		else
			return -1;
	}

	float Getmiddleweight(string name, int mounth_ = 0)
	{
		int l = -1;
		for (int i = 0; (i < count_people) && (l == -1); i++)
		{
			if (name_of_people[i] == name)
				l = i;
		}
		if (l > -1)
		{
			float sum = 0;
			int k = 0;
			if (mounth_ == 0)
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					sum += history_of_weight[l][i];
				}
				return sum / arr_count_measusements[l];
			}
			else
			{
				for (int i = 0; i < arr_count_measusements[l]; i++)
				{
					if (history_of_mounth_of_measurement[l][i] == mounth_)
					{
						sum += history_of_weight[l][i];
						k++;
					}
				}
				if (k != 0)
					return sum / k;
				else
					return 0;
			}
		}
		else
			return -1;
	}
	string operator[](int i)
	{
		if ((i < count_people) && (i >= 0))
			return name_of_people[i];
		else
			return "";
	}
	int Getcount_people()
	{
		return count_people;
	}
	void save_data()//8) сохранить историю наблюдений в файл !!!!!!!!!!!!!!!!!!!!!!!!
	{
		string f = "fille.txt";
		ofstream fout;
		fout.open(f);
		if (fout.is_open())
		{
			fout << count_people << endl;
			for (int i = 0; i < count_people; i++)
			{
				fout << name_of_people[i] << endl;
				fout << arr_count_measusements[i] << endl;
				for (int j = 0; j < arr_count_measusements[i]; j++)
				{
					fout << history_of_weight[i][j] << endl;
					fout << history_of_day_of_measurement[i][j] << endl;
					fout << history_of_mounth_of_measurement[i][j] << endl;
					fout << history_of_year_of_measurement[i][j] << endl;
				}
			}
		}
		fout.close();
	}
	void read_file()
	{
		string f = "fille.txt";
		string tmp;
		ifstream fout;
		fout.open(f);
		if (fout.is_open())
		{
			fout >> tmp;
			count_people = atoi(tmp.c_str());
			for (int i = 0; i < count_people; i++)
			{
				fout >> name_of_people[i];
				print(name_of_people[i]);
				print("\n");
				fout >> tmp;
				arr_count_measusements[i] = atoi(tmp.c_str());
				print(tmp);
				print("\n");
				for (int j = 0; j < arr_count_measusements[i]; j++)
				{
					fout >> tmp;
					history_of_weight[i][j] = atoi(tmp.c_str());
					fout >> tmp;
					print(tmp);
					print("\n");
					history_of_day_of_measurement[i][j] = atoi(tmp.c_str());
					print(tmp);
					print(":");
					fout >> tmp;
					history_of_mounth_of_measurement[i][j] = atoi(tmp.c_str());
					print(tmp);
					print(":");
					fout >> tmp;
					history_of_year_of_measurement[i][j] = atoi(tmp.c_str());
					print(tmp);
					print("\n");
				}
			}
		}
		fout.close();
	}
};


