#pragma once
#include <fstream> 

class Vector
{
private:
	int *memo;
	int count;
public:
	Vector();
	explicit Vector(int _count);
	Vector(int _count, int d);
	Vector(int _count, int* ar);
	Vector(const Vector &vec);
	~Vector();

	void outPut(const char* name);
	void outPut(const char* name) const;
	void setSize(int n);
	void setComp(int _numd, int _valute);
	int getSize();
	int getComp(int numb);
	double getLen();

	int& operator[](int index);
	Vector& operator=(const Vector &vec);
	Vector  operator+(const Vector &vec);
	int  operator*(const Vector &vec);
	friend Vector  operator*(int d, const Vector &vec);
	friend std::ostream& operator<<(std::ostream& stream, const Vector &vec);
	friend std::istream& operator>>(std::istream& stream, Vector &vec);
};

