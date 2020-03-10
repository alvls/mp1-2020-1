#include <iostream>

using namespace std;

class MATRIX {
private:
	int matrix[8][8];
	int size;

public:
	MATRIX()
	{
		size = 0;
	}

	~MATRIX()
	{
		for (int i = 0; i < 8; ++i)
			delete matrix[i];
		delete &size;
	}

	void SetSize(int sz)
	{
		size = sz;
	}

	int GetSize()
	{
		return size;
	}

	void SetElement(int row, int col, int element)
	{
		matrix[row][col] = element;
	}

	int GetElement(int row, int col)
	{
		return matrix[row][col];
	}

	bool isDiagDominate()
	{
		int sum = 0;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
			{
				if (i == j) continue;
				sum += matrix[i][j];
			}
		for (int i = 0; i < size; ++i)
			if (matrix[i][i] < sum) return false;
		return true;
	}

	MATRIX operator+(MATRIX& matrix2)
	{
		MATRIX result;
		result.SetSize(matrix2.GetSize());
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				result.SetElement(i, j, this->GetElement(i, j) + matrix2.GetElement(i, j));
		return result;
	}

	MATRIX& operator= (MATRIX matrix2)
	{
		size = matrix2.GetSize();
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				this->SetElement(i, j, matrix2.GetElement(i, j));
		return *this;
	}

	void Print()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
				cout << this->GetElement(i, j) << " ";
			cout << endl;
		}
	}

};

int main()
{
	MATRIX a, b;
	a.SetSize(4);
	b.SetSize(4);
	int k = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			a.SetElement(i, j, i*j);
			b.SetElement(i, j, i*j + k);
			k++;
		}
	cout << "First:" << endl;
	a.Print();
	cout << "Second:" << endl;
	b.Print();

	MATRIX c;
	c = a + b;
	cout << "Third:" << endl;
	c.Print();

	return 0;
}