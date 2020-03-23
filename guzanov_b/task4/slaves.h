#pragma once
#include"math.h"
#include <fstream>
#include <iostream>
using namespace std;
class slaves
{
private:
	int hours;
	int minutes;
	int seconds;
	float weight;
	float* arr;
	string* time;
	int flag;
	float max;
	float min;
	float middle;
public:
	slaves(int hours_ = 0, int minutes_ = 0, int seconds_ = 0)// 1) установить начальную дату наблюдений//float weight_=50
	{
		hours = hours_;
		minutes = minutes_;
		seconds = seconds_;
		//weight = weight_;
		flag = 0;
		arr = new float[500];
		time = new string[500];
		for (int i = 0; i < 500; i++)
		{
			arr[i] = 0;
		}
	}
	~slaves() {};
	void save_data()//8) сохранить историю наблюдений в файл
	{
		string f = "fille.txt";
		ofstream fout;
		fout.open(f /*,ofstream::app*/);
		if (fout.is_open())
		{
			//for (int i = 0; i < flag; i++)
			//{
			for (int i = 0; i < flag; i++)
			{
				fout << arr[i];
				//arr[i] = 0;
				fout << " ";
				fout << time[i];
				fout << "\n";
				//time[i] = "";
				//fout.seekp(8, ios::beg);
				//}
			}
			fout << min;
			fout << "\n";
			fout << max;
			fout << "\n";
			fout << middle;
			fout << "\n";
		}
		fout.close();
	};
	void read_file()
	{
		string f = "fille.txt";
		ifstream fin;
		fin.open(f);
		string s;
		if (fin.is_open()) {
			int i = 0;
			//while (!fin.eof())
			//{
			for (int i = 0; i < flag; i++)
			{
				fin >> arr[i];
				fin >> time[i];
				cout << arr[i] << " " << time[i] << endl;
				//cout << arr[i] << endl;
			}
			fin >> min;
			fin >> max;
			fin >> middle;
			cout << " Min = " << min << " Max = " << max << " Middle = " << middle << endl;
			remove("fille.txt");
		}
	}
	void gettime()
	{
		cout << hours << " : " << minutes << " : " << seconds << endl;
	}
	int getflag()
	{
		return flag;
	}
	void setweight(float weight_, string tim)
	{
		weight = weight_;
		arr[flag] = weight;
		time[flag] = tim;
		flag++;
	}
	void getweight()
	{
		float n;
		cout << (int)weight << " " << "kg" << " " << modf(weight, &n) * 1000 << " " << "g" << endl;
	}
	float finf_middle_weight()
	{
		float sum = 0;
		for (int i = 0; i < flag; i++)
			sum += arr[i];
		middle = sum / flag;
		return middle;
	}
	float minim() //6) найти минимальный вес члена семьи в выбранном месяце или за всю историю наблюдений и дату, когда он наблюдался
	{
		min = arr[0];
		int j = 0;
		for (int i = 0; i < flag; i++)
		{
			if (min > arr[i])
			{
				min = arr[i];
				j = i;
			}
		}
		cout << "Минимальный вес=";
		cout << (int)min << " " << "kg" << " " << modf(min, &weight) * 1000 << " " << "g" << endl;
		cout << "Время,когда был минимальный вес = ";
		cout << time[j] << endl;
		return min;
	}
	float maxim() //7) найти максимальный вес члена семьи в выбранном месяце или за всю историю наблюдений и дату, когда он наблюдался
	{
		max = arr[0];
		int j = 0;
		for (int i = 0; i < flag; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
				j = i;
			}
		}
		cout << "Максимальный вес=";
		cout << (int)max << " " << "kg" << " " << modf(max, &weight) * 1000 << " " << "g" << endl;
		cout << "Время,когда был максимальный вес = ";
		cout << time[j] << endl;
		return max;
	}
	
};


