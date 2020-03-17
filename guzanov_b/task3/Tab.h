#pragma once
#include "math.h"
#include "locale.h"
#include<stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Tab
{
private:
	FILE* s1;
	float left;
	float right;
	int point;
	float sect;
	float step;
	float (*tabfunc)(float);
public:
	
	Tab(float _left = 0, float _right = 10.0, int _point = 1, float(*funz)(float) = [](float i) {return i * i * i; }/*float (*func)(float) =  */)//1) задать текущую функцию
	{
		left = _left;
		right = _right;
		point = _point;
		tabfunc = funz;
	};
	~Tab()
	{
		std::cout << "Destructor works!" << endl;
	}
	float tab(float  left_,float right_, int point_)
	{
		float sum;
		float i;
		float val;
		int flag = 0;
		sect = right_ - left_;
		step = sect / point_;
		try
		{
			if (right_ <= left_)
				throw "Error right is beter left ";
			flag++;
			for (i = left_; i <= sect; i += step)
			{
				val = tabfunc(i);
				//cout << i <<"  "<< val <<endl;
				rec(val);
			}
			cout << "Результаты табулирования :" << endl;//7) выдать результаты табулирования
			reex();
			return flag;
		}
		catch (char* err)
		{
			cout << err << endl;
			return flag;
		}
	}
	void rec(float valz)//8) сохранить результаты табулирования в файл
	{
		string f = "file.txt";
		ofstream fout;
		fout.open(f, ofstream::app);
		try
		{
			if (!fout.is_open())
				throw "File is not open";
			fout << valz;
			fout << "\n";
		}
		catch (string lin)
		{
			cout << lin << endl;
		}
		fout.close();
		
	};
	void reex()
	{
		string f = "file.txt";
		ifstream fin;
		fin.open(f);
		string s;
		while (!fin.eof())
		{
			getline(fin, s);
			cout << s << endl;
		}
		fin.close();
		remove("file.txt");
	}

	void setpoint(float pointz)//2) задать текущее число точек табулирования
	{
		point = pointz;
	};
	float getpoint()//3) узнать текущее число точек табулирования
	{
		return point;
	};
	void setleft(float leftz)//4) задать левую границу табулирования
	{
	    left = leftz;
	};
	float getleft()//5) узнать отрезок табулирования
	{
		return left;
	};
	void setright(float rightz)//4) задать левую границу табулирования
	{
		right = rightz;
	};
	float getright()//5) узнать отрезок табулирования
	{
		return right;
	};
	Tab& operator=(const Tab& tmp)//1!!!
	{
		this->right = tmp.right;
		this->point = tmp.point;
		this->tabfunc = tmp.tabfunc;
		return *this;
	};

};
//char str1[30] = "iz";
		//char str2[30] = "valz";
		//char s[] = "                                                                                       ";
			//fout << iz;
			//fout << "             ";
		//s.getline(str, 30);
		/*while (f.get())
		{

		}
				s[i + 2] = str1[i];
		//cin.getline(str, 30);
			for (int i = 0; str2[i] != '\0'; i++)
				s[i + 32] = str2[i];
			//fout << valz;
			cout << "\n";*/