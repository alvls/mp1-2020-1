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

	void show_time()
	{
		cout << h << " hours  " << m << " minutes  " << s << " seconds" << endl;
	}

	void find_diff(int _h, int _m, int _s)
	{
		int sec = s  +  60*m  +  3600*h;
		int _sec = _s  +  60*_m  +  3600*_h;
		sec = fabs(sec - _sec);
		_h = sec / 3600;
		_m = (sec / 60) % 60;
		_s = (sec % 60);
		cout << _h << " hours  " << _m << " minutes  " << _s << " seconds" << endl;
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
/*	{
	_s = s - _s;
		if (_s < 0)
		{
			_m = _m - 1;
			_s = _s + 60;
		}
		_m = m - _m;
		if (_m < 0)
		{
			_h = _h - 1;
			_m = _m + 60;
		}
		_h = h - _h;
	} */
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
			t1.show_time();
			break;
		case 3:
			cout << "Set hour, minute, second" << endl;
			cin >> h >> m >> s;
			t1.find_diff(h, m, s);
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