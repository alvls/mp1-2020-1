#include <iostream>
#include <cmath>
using namespace std;
class Matrix
{
	int x;
	int matrix[8][8];
public:
	Matrix(int size = 0)
	{
		setSize(size);
	}
	void setSize(int size)
	{
		x = size;
		for (int i = 1; i < x + 1; i++)
		{
			for (int j = 1; j < x + 1; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	int outputSize()
	{
		cout << x;
		return x;
	}
	void setElement(int i, int j, int value)
	{
		matrix[i][j] = value;
	}
	int outputElement(int i, int j)
	{
		cout << matrix[i][j];
		return matrix[i][j];
	}
	bool DigPreobladanie()
	{
		int i, j;
		int sum = 0;
		bool flag = false;
		for (i = 1; i < x + 1; i++)
		{
			for (j = 1; j < x + 1; j++)
			{
				if (i!=j)
				sum = abs(matrix[i][j]);
			}
			if (matrix[i][i] < sum)
				return false;
			else
				flag = true;
		}
		return flag;
	}
	Matrix operator+(const Matrix& other)
	{
		int i, j;
		if (x != other.x)
		{
			cout << "Razmer matrix ne sovpadaet" << endl;
			return *this;
		}
		else
		{
			Matrix sum(x);
			for (i = 1; i < x + 1; i++)
			{
				for (j = 1; j < x + 1; j++)
				{
					sum.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
				}
			}
			return sum;
		}
	}
	Matrix& operator=(const Matrix& other)
	{
		int i, j;
		for ( i = 1; i < other.x + 1; i++)
		{
			for ( j = 1; j < other.x + 1; j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}
};
void main()
{
	int count,size,i,j,value,flag=1;
	bool otvet;
	Matrix a,b,c;
	cout << "vibiraite rezim" << endl;
	cout << "1 - Zadat' razmer" << endl;
	cout << "2 - Yznaite razmer " << endl;
	cout << "3 - Zadat' element po indeksam" << endl;
	cout << "4 - Yznat' element po indeksam" << endl;
	cout << "5 - Yznat' obladaet li matrica diogonal'nim preobladaniem" << endl;
	cout << "6 - vicheslit' symmy dvyh matric odnogo razmera" << endl;
	while (true)
	{
		cin >> count;
		switch (count)
		{
		    case 1:
				cout << " Ykazhite razmer: ";
				cout << " razmer: ";
				cin >> size;
				a.setSize(size);
				break;
			case 2:
				a.outputSize();
				break;
			case 3:
				cout << " viberite stroky: ";
				cin >> i;
				cout << " viberite stolbec: ";
				cin >> j;
				cout << " viberite znachenie: ";
				cin >> value;
				a.setElement(i, j, value);
				break;
			case 4:
				cout << " viberite stroky: ";
				cin >> i;
				cout << " viberite stolbec: ";
				cin >> j;
				a.outputElement(i, j);
				break;
			case 5:
				otvet = a.DigPreobladanie();
				cout << otvet;
				break;
			case 6:
				cout << "viberite razmer matrici:";
				cin >> size;
				b.setSize(size);
				c.setSize(size);
				while (flag == 1)
				{
					cout << "zadaite element";
					cout << " viberite stroky: ";
					cin >> i;
					cout << " viberite stolbec: ";
					cin >> j;
					cout << " viberite znachenie: ";
					cin >> value;
					b.setElement(i, j, value);
					cout << "esli hotite esche viberete 1, esli net, 0";
					cin >> flag;
				}
				c = a + b;
				flag = 1;
				while (flag == 1)
				{
					cout << "yznaite element";
					cout << " viberite stroky: ";
					cin >> i;
					cout << " viberite stolbec: ";
					cin >> j;
					c.outputElement(i, j);
					cout << "esli hotite esche viberete 1, esli net, 0";
					cin >> flag;
				}
				break;
		}
		cout << "End? y/n" << endl;
		char conf;
		getchar();
		conf = getchar();
		if ((conf == 'Y') || (conf == 'y'))
			break;
	}
	system("pause");
}