#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "Dictionary.h"
using namespace std;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary Sl;
	Sl.Read_form_file("�������.txt");

	string r, e;
	int w;
	while(true)
	{
		cout << "������� �����: ";
		cin >> r;
		cout << "������� ��� �������: ";
		cin >> e;
		Sl.Add_word(r, e);
		cout << "������ �������� ��� �����? (��/���)" << endl;
		cin >> r;
		if (r == "���")
			break;
	}
	Sl.Output();

	string a, b;
	cout << "������� ����� ��� ������: ";
	cin >> a;
	cout << "������� ������� ��� ������: ";
	cin >> b;
	if (Sl.Change(a, b))
	{
		cout << "����� �������: " << endl;
		Sl.Output();
	}
	else
		cout << "������ ����� ���" << endl;

	cout << "� ������� " << Sl.Get_count() << " " << "����(�)" << endl;
	string q;
	cout << "������� ����� ��� ��������: ";
	cin >> q;
	if (Sl.Check_word(q))
		cout << "����� ����� ����" << endl;      
	else cout << "������ ����� ���" << endl;
	string p = Sl.Get_en(q);
	cout << p << endl;

	Sl.Saved_to_file("�������.txt");

	system("pause");
	return 0;
}