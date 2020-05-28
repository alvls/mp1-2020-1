#pragma once
#include <iostream>
#include <Windows.h>
#include "conio.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
 class element
{
private:
	int i, j;
	int priznak;//=1 -голова,2 -середина,3 - хвост,4 - и голова,и хвост
public:
	element(int x = 0, int y = 0, int priznak_ = 2)
	{
		i = y;
		j = x;
		priznak = priznak_;
	}
	~element() {};
	int operator==(const element& tmp)
	{
		if (i == tmp.i && j == tmp.j)
		{
			return 1;//совпали
		}
		else
			return 0;//не совпали
	}
	int geti()
	{
		return i;
	}
	int getj()
	{
		return j;
	}
	void seti(int i_)
	{
		i = i_;
	}
	void setj(int j_)
	{
		j = j_;
	}
	int getpriznak()
	{
		return priznak;
	}
	void setpriznak(int priznak_)
	{
		if (priznak_ >= 1 && priznak <= 4)
			priznak = priznak_;
	}
};

