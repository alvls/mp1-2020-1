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
	float sec;
	float p;
	float h;
	float (*tabfunc)(float);
public:
	Tab(float _sec = 10, float _p = 1, float (*func)(float) = [](float i) {return cos(i); })//1) задать текущую функцию
	{
		sec = _sec;
		p = _p;
		tabfunc = func;
	};
	~Tab()
	{
		std::cout << "Destructor works!" << endl;
	}
	float tab(float  sec, float p)
	{
		float S;
		float i;
		float q;
		S = 0;
		h = sec / p;
		for (i = 0; i <= sec; i += h)
		{
			q = tabfunc(i);
			S += q;
		}
		return S;
	}
	void rec(float s)//8) сохранить результаты табулирования в файл
	{
		string f = "file.txt";
		ofstream fout;
		fout.open(f, ofstream::app);
		try
		{
			if (!fout.is_open())
				throw "Файл не открыт";
			cout << "Все нормально с открытием файла" << endl;
			fout << s;
			fout << "\n";
		}
		catch (string l)
		{
			cout << l << endl;
		}
		fout.close();
	};
	void setp(float ps)//2) задать текущее число точек табулирования
	{
		p = ps;
	};
	float getp()//3) узнать текущее число точек табулирования
	{
		return p;
	};
	void setsec(float secs)//4) задать отрезок табулирования
	{
		sec = secs;
	};
	float getsec()//5) узнать отрезок табулирования
	{
		return sec;
	};
	Tab& operator=(const Tab& tmp)//1!!!
	{
		this->sec = tmp.sec;
		this->p = tmp.p;
		return *this;
	};

};
