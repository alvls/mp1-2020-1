#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class time
{
	int h;
	int m;
	int s;
public:
	time() { h = m = s = 0; }
	void set_time(int _h, int _m, int _s)
	{
		h = _h;
		m = _m;
		s = _s;
	}

	void show_time(int *hh, int *mm, int *ss)
	{
		*hh = h;
		*mm = m;
		*ss = s;
	}

	void find_diff(int *hh, int *mm, int *ss)
	{
		int sec = s + 60 * m + 3600 * h;
		int _sec = (*ss) + 60 * (*mm) + 3600 * (*hh);
		sec = fabs(sec - _sec);
		*hh = sec / 3600;
		*mm = (sec / 60) % 60;
		*ss = (sec % 60);
	}

	void set_diff(int _h, int _m, int _s, char way)
	{
		if (way == 'f')
		{
			s = s + _s;
			if (s > 59)
			{
				m = m + 1;
				s = s - 60;
			}
			m = m + _m;
			if (m > 59)
			{
				h = h + 1;
				m = m - 60;
			}
			h = h + _h;
			if (h > 23)
			{
				h = h - 24;
			}
		}
		if (way == 'b')
		{
			s = s - _s;
			if (s < 0)
			{
				m = m - 1;
				s = s + 60;
			}
			m = m - _m;
			if (m < 0)
			{
				h = h - 1;
				m = m + 60;
			}
			h = h - _h;
			if (h < 0)
			{
				h = h + 24;
			}
		}
	}
};

void main()
{
	cout << "Select function" << endl;
	cout << "1)Set time(h, m, s)" << endl;
	cout << "2)Show time" << endl;
	cout << "3)Find difference (h, m, s)" << endl;
	cout << "4)Set difference (h, m, s, f/b)" << endl;
	int sw;
	int h, m, s;
	time t1;
	while (true)
	{
		cin >> sw;
		switch (sw)
		{
		case 1:
			cout << "Set hour, minute, second" << endl;
			cin >> h >> m >> s;
			t1.set_time(h, m, s);
			getchar();
			break;
		case 2:
			t1.show_time(&h, &m, &s);
			cout << h << " hours  " << m << " minutes  " << s << " seconds" << endl;
			break;
		case 3:
			cout << "Set hour, minute, second" << endl;
			cin >> h >> m >> s;
			t1.find_diff(&h, &m, &s);
			cout << h << " hours  " << m << " minutes  " << s << " seconds" << endl;
			break;
		case 4:
			char way;
			cout << "Set hour, minute, second, f/b (forward or back)" << endl;
			cin >> h >> m >> s >> way;
			t1.set_diff(h, m, s, way);
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