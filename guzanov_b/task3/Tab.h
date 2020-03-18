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
	float* arr;
public:
	Tab(float _left = 0, float _right = 10.0, int _point = 1, float(*funz)(float) = [](float i) {return i * i * i; })//1) задать текущую функцию
	{
		left = _left;
		right = _right;
		point = _point;
		tabfunc = funz;
		arr = new float[point];//
		for (int i = 0; i < point; i++)
		{
			arr[i] = 0;
		}
	};
	~Tab()
	{
		delete[] arr;
	}
	float tabulate()
	{
		float sum;
		float i;
		int j;
		float val;
		int flag = 0;
		sect = right - left;
		step = sect / point;
			if (right > left)
				
			for (i = left; i <= sect; i += step)
			{
				val = tabfunc(i);
				arr[flag] = val;
				
				flag++;
			}
			
			cout << endl;
			
		return flag;
	}
	void read_file()
	{
		string f = "file.txt";
		ifstream fin;
		fin.open(f);
		string s;
		if (fin.is_open()) {
			int i = 0;
			//while (!fin.eof())
			//{
				for (int i = 0; i < point;i++)
				{
				//getline(arr[i], s);
				fin >> arr[i];
				cout << arr[i] << endl;
				}
			//}
			cout << endl;
			fin.close();
			remove("file.txt");
		}
	}
	//float(*getArray)()
	//{
	//	return arr;
	//}
	void save_to_file(int flag)//8) сохранить результаты табулирования в файл
	{
		string f = "file.txt";
		ofstream fout;
		fout.open(f, ofstream::app);
	
		if (fout.is_open()) {
			
			
			for (int i = 0; i < flag; i++) 
			{
				fout << arr[i];
				fout << "\n";
			}
		}	
	};
	
	void print_screen()
	{
		for (int i = 0; i < point; i++)
			cout << arr[i] << endl;
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
	float getleft()//5) узнать левую границу табулирования
	{
		return left;
	};
	void setright(float rightz)//4) задать правую границу табулирования
	{
		right = rightz;
	};
	float getright()//5) узнать правую границу табулирования
	{
		return right;
	};
	Tab& operator=(const Tab& tmp)//1!!!
	{
		this->left = tmp.left;
		this->right = tmp.right;
		this->tabfunc = tmp.tabfunc;
		if (this->point != tmp.point)
		{
			delete[] arr;
			this->point = tmp.point;
			arr = new float[point];
		}
		
		for (int i = 0; i < point; i++)
		{
			arr[i] = tmp.arr[i];
		}
		return *this;
	};

};
/*float (*func)(float) =  */
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
/*DArray(int _n = 1)  //1) задать размер массива,
	{
		SIZE = _n;
		arr = new float[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = 0;
		}
	};
	~DArray()
	{
		delete[] arr;
	};
	DArray(const DArray& tmp)
	{
		SIZE = tmp.SIZE;
		arr = new float[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = tmp.arr[i];
		}
	};
	DArray& operator=(DArray tmp)
	{
		if (SIZE != tmp.SIZE)
		{
			if (SIZE != 0)
			{
				delete arr;
			}
			SIZE = tmp.SIZE;
			arr = new float[SIZE];
		}
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = tmp.arr[i];
		}
		return *this;
	};
	float& operator[](int index)  //3) задать/узнать элемент массива по его индексу,
	{
		float error = 2147483647.;
		if ((index >= 0) && (index < SIZE))
		{
			return arr[index];
		}
		else
		{
			return error;
		}*/
		/*float& operator[](int index)  // задать/узнать элемент массива значений табулирования по его индексу,
			{
				float error = 2147483647;
				try
				{
					if ((index < 0) || (index >= size)) {
						throw("Error!An item with this index does not exist. ");
					}
					return arr[index];
				}
				catch (char* str)
				{
					cout << str << endl;
					return error;
				}
			};
			*/
			//try
					//{
            //throw "Error right is beter left ";
            //cout << i <<"  "<< val <<endl;
//read_file();
//try
		//{
//}
		/*catch (char* err)
		{
			cout << err << endl;
			return flag;
		}*/
		//		throw "File is not open";
//}
		/*catch (string lin)
		{
			cout << lin << endl;
		}
		fout.close();
		*/
		//cout << "Результаты табулирования в классе :" << endl;//7) выдать результаты табулирования
					//for(j=0;j<flag;j++)
					//cout << arr[j] << endl;
/*void read_file()
	{
		string f = "file.txt";
		ifstream fin;
		fin.open(f);
		string s;
		if (fin.is_open()) {
			int i = 0;
			while (!fin.eof())
			{
				//for (int i = 0; i < point;)
				//{
					getline(fin, s);
					fin>>arr[i++];
				//}
				//cout << s << endl;
			}
			fin.close();
			remove("file.txt");
		}
	}
	*/