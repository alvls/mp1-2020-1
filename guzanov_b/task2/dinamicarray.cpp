// dinamicarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DArray.h"
using namespace std;
int main()
{
	DArray A;
	cout << "A:" << endl;
	for (int i = 0; i < A.GetSIZE(); i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	DArray B(5);  //1) задать размер массива,
	for (int i = 0; i < 5; i++)
	{
		B[i] = i * 2;
	}
	cout << "B:" << endl;
	for (int i = 0; i < B.GetSIZE(); i++)
	{
		cout << B[i] << "  ";
	}
	cout << endl;
	A = B;
	cout << "A:" << endl;
	for (int i = 0; i < A.GetSIZE(); i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	cout << "Enter size " << endl;
	int M;
	cin >> M;
	DArray D(M);
	cout << "Enter Array " << endl;
	for (int i = 0; i < D.GetSIZE(); i++)
	{
		cin >> D[i];
	}
	cout << "Min = " << D.Minim() << endl;
	cout << "A: " << A.ControleGreite() << endl;
	cout << "D: " << D.ControleGreite() << endl;
	DArray T;
	D.Chose(T);
	cout << "T:" << endl;
	for (int i = 0; i < T.GetSIZE(); i++)
	{
		cout << T[i] << "  ";
	}
	cout << endl;
	cout << "T:" << endl;
	cout << T << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
