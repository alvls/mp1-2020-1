#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURITYCRITICAL_ATTRIBUTE

using namespace std;

class matrix
{
private:
	int height;
	int *matr;
public:
	matrix() { height = 0; matr = new int[0]; }   // 1*
	matrix(const matrix &m3)
	{
		height = m3.height;
		matr = new int[height * height];
		for (int i = 0; i < height * height; i++)
			matr[i] = m3.matr[i];
	}
	~matrix() { delete[] matr; }

	void set_len(int _height)
	{
		height = _height;
		delete[] matr;
		matr = new int[height * height];
	}

	int len()
	{
		return height;
	}

	void set_value(int _height, int _width, int num)
	{
		matr[(_height -1)*height + _width - 1] = num;
	}

	int get_value(int _height, int _width)
	{
		return matr[(_height -1)*height + _width - 1];
	}

	void check_diag()
	{
		int i;
		int j;
		int num1;
		int num2 = 0;
		int flag = 0;
		for (i = 0; i < height; i++)
		{
			num1 = matr[(i-1)*height + i];
			for (j = 0; j < height; j++)
			num2 = num2 + matr[(j - 1)*height + j];
			num2 = num2 - num1;
			if (num2 > num1) flag = 1;
		}
		if (flag = 0) cout << "It`s a diagonally dominant matrix" << endl;
		else cout << "It is not a diagonally dominant matrix" << endl;
	}

	int matr()
	{
		return height;
	}

	matrix operator+(const matrix &m2)
	{
		int i;
		matrix result;
		result.set_len(height);
		for (i = 0; i < height*height; i++)
		result.matr[i] = this->matr[i]+m2.matr[i];
		return result;
	}
	matrix& operator=(const matrix &m3)
	{
		height = m3.height;
		delete[] matr;
		matr = new int[height*height];
		for (int i = 0; i < height*height; i++)
			matr[i] = m3.matr[i];
		return (*this);
	}
};


void main()
{
	cout << "Select function" << endl;
	cout << "1)Set length(a)" << endl;
	cout << "2)Show length" << endl;
	cout << "3)Set a number on place(a, b, num)" << endl;
	cout << "4)Check a number on place(a, b)" << endl;
	cout << "5)Check for a diagonally dominant matrix" << endl;
	cout << "6)Find a sum of matrix 1 and matrix 2 on matrix 3" << endl;
	int sw, matr;
	int height, width, num;
	matrix m1;
	matrix m2;
	matrix m3;
	while (true)
	{
		cin >> sw;
		switch (sw)
		{
		case 1:
			cout << "Set width, matrix 1/2" << endl;
 			cin >> height >> matr;
			switch (matr)
			{
			case 1:
				m1.set_len(height);
				break;
			case 2:
				m2.set_len(height);
				break;
			}
			break;


		case 2:
			cout << "Set matrix 1/2" << endl;
			cin >> matr;
			switch (matr)
			{
			case 1:
				m1.len();
				cout << m1.len() << '*' << m1.len() << endl;
				break;
			case 2:
				m2.len();
				cout << m2.len() << '*' << m2.len() << endl;
				break;
			}
			break;


		case 3:
			cout << "Set a, b, num, matrix 1/2" << endl;
			cin >> height >> width >> num >> matr;
			switch (matr)
			{
			case 1:
				m1.set_value(height, width, num);
				break;
			case 2:
				m2.set_value(height, width, num);
				break;
			}
			break;


		case 4:
			cout << "Set a, b, matrix 1/2/3" << endl;
			cin >> height >> height >> matr;
			switch (matr)
			{
			case 1:
				cout << m1.get_value(height, width) << endl;
				break;
			case 2:
				cout << m2.get_value(height, width) << endl;
				break;
			case 3:
				cout << m3.get_value(height, width) << endl;
				break;
			}
			break;

		case 5:
			cout << "Set matrix 1/2/3" << endl;
			cin >> matr;
			switch (matr)
			{
			case 1:
				m1.check_diag();
				break;
			case 2:
				m2.check_diag();
				break;
			}
			break;


		case 6:
			m3.set_len(m1.len());
			m3 = m1+m2;
			break;
		}


		cout << "End? Y/N" << endl;
		char conf;
		getchar();
		conf = getchar();
		if ((conf == 'Y') || (conf == 'y'))
			break;
	}
}