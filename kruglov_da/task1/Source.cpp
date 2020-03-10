#include <iostream>
using namespace std;

class Time
{
	int m_Hours;
	int m_Minutes;
	int m_Seconds;

public:
	Time() { m_Hours = m_Minutes = m_Seconds = 0; } // ����������� 
	Time(int hours, int minutes, int seconds)
	{
		m_Hours = hours;
		m_Minutes = minutes;
		m_Seconds = seconds;
	}
	void SetTime(int hours, int minutes, int seconds)
	{
		m_Hours = hours;
		m_Minutes = minutes;
		m_Seconds = seconds;
	}
	void difference(int h, int m, int s)// ��������� ������� ����� �������� �������� � ������������� (� �����, ������� � ��������)
	{
		int seczad = 0, secust = 0;
		int diff;
		seczad = h * 3600 + m * 60 + s;
		secust = m_Hours * 3600 + m_Minutes * 60 + m_Seconds;
		diff = abs(seczad - secust);
		h = diff / 3600;
		m = (diff - h * 3600) / 60;
		s = diff - h * 3600 - m * 60;
		cout << h << " : " << m << " : " << s << endl;
	}
	Time shiftpluse(int h, int m, int s)//�������� ����� �� �������� ��������(� �����, ������� � ��������)  � ������� �������
	{
		int seczad = 0, secust = 0;
		int pluse;
		seczad = h * 3600 + m * 60 + s;
		secust = m_Hours * 3600 + m_Minutes * 60 + m_Seconds;
		pluse = seczad + secust;
		pluse = pluse % 86400;
		m_Hours = pluse / 3600;
		m_Minutes = (pluse - h * 3600) / 60;
		m_Seconds = pluse - h * 3600 - m * 60;
		Time t(h, m, s);
		return t;

	}
	Time shiftminuse(int h, int m, int s)//�������� ����� �� �������� ��������(� �����, ������� � ��������) � ������� �������
	{
		int seczad = 0, secust = 0;
		int minuse;
		seczad = h * 3600 + m * 60 + s;
		secust = m_Hours * 3600 + m_Minutes * 60 + m_Seconds;
		minuse = secust - seczad;
		if (seczad > secust) {
			minuse += 86400;
		}
		m_Hours = minuse / 3600;
		m_Minutes = (minuse - h * 3600) / 60;;
		m_Seconds = minuse - h * 3600 - m * 60;
		Time t(h, m, s);
		return t;
	}
	void printTime()  // ������ �����
	{
		cout << m_Hours << " : " << m_Minutes << " : " << m_Seconds << endl;
	}

};


int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int h, m, s, p;
	int f;
	Time t;
	cout << " �������� ����� " << endl << "1 - ��������� ������� " << endl << "2 - ������ ����� " << endl << " 3 -��������� ������� ����� �������� �������� � ������������� (� �����, ������� � ��������) " << endl << "4 - �������� ����� �� �������� �������� (� �����, ������� � ��������) � ������� � � ������� �������" << endl << "���� ������ ������� 0" << endl;
	cin >> f;
	while (f != 0) {
		h = m = s = 0;
		switch (f) {
		case 1:
			cout << "����� ��������� �������, ������� ���� ������ � �������" << endl;
			cin >> h >> m >> s;
			t.SetTime(h, m, s);
		case 2:
			cout << f << endl;
			t.printTime();
		case 3:
			cout << "����� ��������� �������, ������� ���� ������ � �������" << endl;
			cin >> h >> m >> s;
			t.SetTime(h, m, s);
			h = m = s = 0;
			cout << "������� �������� ����� " << endl;
			cin >> h >> m >> s;
			cout << "��� �������" << endl;
			t.difference(h, m, s);
		case 4:
			cout << "�������� � ������� ������� 1 � ������� 2" << endl;
			cin >> p;
			cout << "������� ����� �� ������� ������ �������� " << endl;
			cin >> h >> m >> s;
			if (p == 1) {
				Time shiftpluse(h, m, s);
				t.printTime();
			}
			else {
				Time shiftminuse(h, m, s);
				t.printTime();
			}
		}
		cout << " �������� ����� " << endl << "1 - ��������� ������� " << endl << "2 - ������ ����� " << endl << " 3 -��������� ������� ����� �������� �������� � ������������� (� �����, ������� � ��������) " << endl << "4 - �������� ����� �� �������� �������� (� �����, ������� � ��������) � ������� � � ������� �������" << endl << "���� ������ ������� 0" << endl;
		cin >> f;

	}
	cout << endl;
	system("pause");
	return 0;
}
