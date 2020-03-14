#include <iostream>
using namespace std;

class Fraction
{
private:
	int num;
	int denom;
public:
	Fraction()
	{
		num = 0;
		denom = 1;
	}

	Fraction(int a, int b)
	{
		num = a;
		denom = b;
		if (denom == 0)
			cout << "Error//b!=0" << endl;
		else
			Cancellation();
	}

	void Show()
	{
		cout << num << "/" << denom;
	}

	void Cancellation()
	{
		if (num != 0)
		{
			int m = denom,
				n = num,
				ost = m % n;
			while (ost != 0)
			{
				m = n; n = ost;
				ost = m % n;
			}
			int nod = n;
			if (nod != 1)
			{
				num /= nod; denom /= nod;
			}
		}
		if (denom < 0)
		{
			num *= -1;
			denom *= -1;
		}
	}

	Fraction(const Fraction& frac)
	{
		num = frac.num;
		denom = frac.denom;
	}

	Fraction& operator= (const Fraction& frac)
	{
		num = frac.num;
		denom = frac.denom;
		Cancellation();
		return *this;
	}
	
	int NOD (int a, int b)
	{
		while ((a != 0) && (b != 0))
		{
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}
		if (a == 0)
			return b;
		else
			return a;
	}

	Fraction operator+ (const Fraction& frac)
	{
		int nok = denom * frac.denom / NOD(denom, frac.denom);
		int sl_nom = num * nok / denom + frac.num * nok / frac.denom;
		int sl_denom = nok;
		Fraction sl = Fraction(sl_nom, sl_denom);
		return sl;
	}

	Fraction operator- (const Fraction& frac)
	{
		int nok = denom * frac.denom / NOD(denom, frac.denom);
		int sl_nom = num * nok / denom - frac.num * nok / frac.denom;
		int sl_denom = nok;
		Fraction sl = Fraction(sl_nom, sl_denom);
		return sl;
	}

	Fraction operator* (const Fraction& frac)
	{
		int sl_num = num * frac.num;
		int sl_denom = denom * frac.denom;
		Fraction sl= Fraction(sl_num, sl_denom);
		return sl;
	}

	Fraction operator/ (const Fraction& frac)
	{
		int sl_num = num * frac.denom;
		int sl_denom = denom * frac.num;
		Fraction sl = Fraction(sl_num, sl_denom);
		return sl;
	}
};

void main()
{
	Fraction frac_1, frac_2;
	int regim,exit;
	do
	{
		int num_1, denom_1;
		do
		{
			cout << "Enter the first fraction in this form a/b: ";
			char sl;
			cin >> num_1 >> sl >> denom_1;
			frac_1 = Fraction(num_1, denom_1);
		} while (denom_1 == 0);

		int num_2, denom_2;
		do
		{
			cout << "Enter the second fraction in this form a/b: ";
			char sl;
			cin >> num_2 >> sl >> denom_2;
			frac_2 = Fraction(num_2, denom_2);
		} while (denom_2 == 0);

		cout << "Choose an operation:" << endl;
		cout << "1. +" << endl << "2. -" << endl << "3. *" << endl << "4. /" << endl;
		cin >> regim;
		Fraction res;
		switch (regim)
		{
		case 1:
			res = frac_1 + frac_2;
			break;
		case 2:
			res = frac_1 - frac_2;
			break;
		case 3:
			res = frac_1 * frac_2;
			break;
		case 4:
			res = frac_1 / frac_2;
			break;
		}
		cout << endl; res.Show(); cout << endl << endl;

		cout << "1  - continue, 0 - exit" << endl;
		cin >> exit;
	}
	while (exit == 1);
}