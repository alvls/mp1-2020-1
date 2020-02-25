#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
class Longint
{
private:
	int tempsign;
	int sign;
	unsigned int modul;
public:
	Longint()
	{
		sign = 1;
		modul = 0;
	}
	Longint(const long long& value)
	{
		if (value < 0)
		{
			sign = -1;
			modul = abs(value);
		}
		else
		{
				sign = 1;
 			modul = value;	
		}
	};
	Longint operator+ (const Longint& other)
	{ 
		if ((sign == 1)&&(other.sign == 1) )
		{
			sign = 1;
			return modul + other.modul;
		}
		if ((sign == 1) && (other.sign == -1)&&(modul > other.modul))
		{
			sign = 1;
			return modul - other.modul;
		}
		if ((sign == -1) && (other.sign == 1) && (modul > other.modul))
		{
			Longint temp(modul - other.modul);
			temp.sign = -1;
			return temp;
		}
		if ((sign == 1) && (other.sign == -1) && (modul < other.modul))
		{
			Longint temp(other.modul - modul);
			temp.sign = -1;
		return temp;
		}
		if ((sign == -1) && (other.sign == 1) && (modul < other.modul))
		{
			return other.modul - modul;
		}
		if ((sign == -1) && (other.sign == -1))
		{
			Longint temp(other.modul + modul);
			temp.sign = -1;
			return temp;
		}
	}
	Longint operator- (const Longint& other)
	{
		if ((sign == 1) && (other.sign == 1) && (modul > other.modul))        
		{
			sign = 1;
			return modul - other.modul;
		}
		if ((sign == -1) && (other.sign == -1) && (modul < other.modul))         
		{
			sign = 1;
			return other.modul - modul;
		}
		if ((sign == -1) && (other.sign == -1) && (modul > other.modul))
		{
			Longint temp(modul - other.modul);
			temp.sign = -1;
			return temp;
		}
		if ((sign == -1) && (other.sign == 1))                 
		{
			Longint temp(modul + other.modul);
			temp.sign = -1;
			return temp;
		}
		if ((sign == 1) && (other.sign == -1))  
		{
			sign = 1;
			return modul + other.modul;
		}
		if ((sign == 1) && (other.sign == 1) && (modul < other.modul))      
		{
			Longint temp(other.modul + modul);
			temp.sign = -1;
			return temp;	
		}
	}
	Longint operator* (const Longint& other) 
	{
		if (((sign == 1) && (other.sign == 1))||((sign == -1) && (other.sign == -1)))
		{
			sign = 1;
			return modul * other.modul;
		}
		if (((sign == -1) && (other.sign == 1)) || ((sign == 1) && (other.sign == -1)))
		{
			Longint temp(modul * other.modul);
			temp.sign = -1;
			return temp;
		}
	}
	Longint operator/ (const Longint& other)
	{
		if (((sign == 1) && (other.sign == 1)) || ((sign == -1) && (other.sign == -1)))
		{
			sign = 1;
			return modul / other.modul;
		}
		if (((sign == -1) && (other.sign == 1)) || ((sign == 1) && (other.sign == -1)))
		{
			Longint temp(modul / other.modul);
			temp.sign = -1;
			return temp;
		}
	}
	Longint operator% (const Longint& other)
	{
		sign = 1;
		return modul % other.modul;
	}
	friend ostream& operator << (ostream& out, const Longint& f);
};
ostream& operator << (ostream& out, const Longint& f) // out
{
	if (f.sign==1)
	{out << f.modul << endl;
	return out;
	}
	if (f.sign==-1)
	{
		out<< "-" << f.modul << endl;
		return out;
	}
}

void main()
{
	Longint a1(-9000000);
	cout <<"a1 = "  << a1;
	Longint b1(333);
	cout << "b1 = " << b1;
	Longint p1 = a1 + b1;
	cout << "a1 + b1 = " << p1;
	Longint p2 = a1 - b1;
	cout << "a1 - b1 = " << p2;
	Longint p3 = a1 / b1;
	cout << "a1 / b1 = " << p3;
	Longint p4 = a1 * b1;
	cout << "a1 * b1 = " << p4;
	Longint p5 = a1 % b1;
	cout << "a1 % b1 = " << p5;
	system("pause");
}