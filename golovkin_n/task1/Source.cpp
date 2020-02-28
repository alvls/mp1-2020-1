#include <iostream>
#include <cmath>
using namespace std;
class vremya
{
	int h, m, s;
public:
	vremya() { h = m = s = 0; }
	vremya& operator=(const vremya& other)
	{
		h = other.h;
		m = other.m;
		s = other.s;
		return *this;
	}
	void ystanovka_vremeni(int _h, int _m, int _s)
	{
		h = _h;
		m = _m;
		s = _s;
	}
	void vivod_vremeni()
	{
		cout << h << "Chasiki" << m << "Minytki" << s << "Sekyndochki";
	}
	vremya(int _h, int _m, int _s)
	{
		h = _h;
		m = _m;
		s = _s;
	}

	vremya raznica(vremya& other)
	{
		int _h = other.h;
		int _m = other.m;
		int _s = other.s;
		_h = h - _h;
		_m = m - _m;
		_s = s - _s;
		if (_h < 0)
		{
			_h = 24 + (_h % 24);
			if (_h == -24)
				_h = 0;
		}
		if (_m < 0)
		{
			_h = _h + _m / 60;
			if (_m != 0)
				_h--;
			_m = 60 + (_m % 60);
			if (_m == -60)
				_m = 0;
		}
		if (_s < 0)
		{
			_m = _m + _s / 60;
			if (_s != 0)
				_m--;
			_s = 60 + (_s % 60);
			if (_s == -60)
				_s = 0;
		}
		other.h = _h;
		other.m = _m;
		other.s = _s;
		return other;
	}
	vremya ybivanie(vremya& other)
	{
		int _h = other.h;
		int _m = other.m;
		int _s = other.s;
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
		other.h = h;
		other.m = m;
		other.s = s;
		return other;
	}
	vremya vozrastanie(vremya& other)
	{
		int _h = other.h;
		int _m = other.m;
		int _s = other.s;
		_h = h + _h;
		_m = m + _m;
		_s = s + _s;
		if (_s > 59)
		{
			_m = _m + _s / 60;
			s = s % 60;
		}
		if (_m > 59)
		{
			_h = _h + _m / 60;
			_m = _m % 60;
		}
		if (_h > 23)
			_h = _h % 24;
		h = _h;
		m = _m;
		s = _s;
		other.h = _h;
		other.m = _m;
		other.s = _s;
		return other;
	}
};
	void main()
	{
		int h,m,s;
		int flag;
		h = m = s = 0;
		int count;
		vremya a,b,c;
		cout << "vibiraite rezim" << endl;
		cout << "1 - Nastroite vremya" << endl;
		cout << "2 - Yznaite vremya " << endl;
		cout << "3 - Yznaite raznicy vremeni" << endl;
		cout << "4 - Povernyt' vremya v spyat' ili vpered'" << endl;
		while (true)
		{
			cin >> count;
			switch (count)
			{
			case 1:
				cout << "Nastroite vremyachko" << endl;
				cout << "Chasiki: ";
				cin >> h;
				cout << " Minytki: ";
				cin >> m;
				cout << " Sekyndochki: ";
				cin >> s;
				a.ystanovka_vremeni(h, m, s);
				break;
			case 2:
				a.vivod_vremeni();
				break;
			case 3:
				cout << "Vvedite vremya dlya sravneniya" << endl;
				cout << "Chasiki: ";
				cin >> h;
				cout << " Minytki: ";
				cin >> m;
				cout << " Sekyndochki: ";
				cin >> s;
				b.ystanovka_vremeni(h, m, s);
				c = a.raznica(b);
				cout << "Raznica: ";
				c.vivod_vremeni();
				break;
			case 4:
				cout << "Vvedite vremya dlya podschetov" << endl;
				cout << "Chasiki: ";
				cin >> h;
				cout << " Minytki: ";
				cin >> m;
				cout << " Sekyndochki: ";
				cin >> s;
				cout << "0 - Pribavit', 1 - vichest' ";
				cin >> flag;
				b.ystanovka_vremeni(h, m, s);
				if (flag == 0)
					c = a.vozrastanie(b);
				else
					c = a.ybivanie(b);
				c.vivod_vremeni();
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