#include <stdio.h>
#include <numeric>
#include <iostream>
using std::cout;
using std::endl;


class RationalFraction {
private:
	int numerator, denominator;
public:
	RationalFraction(int _numerator, int _denominator) {
		try {
			if (!_denominator) {
				throw "IncorrectDenominator";
			}

			int gcd = std::gcd(_numerator, _denominator);
			numerator = _numerator / gcd;
			denominator = _denominator / gcd;
		}
		catch (char *s) {
			printf("%s\n", s);
		}
	}

	int getNumerator() {
		return numerator;
	}
	int getDenominator() {
		return denominator;
	}

	void print() {
		printf("%d/%d", numerator, denominator);
	}

	RationalFraction& operator= (RationalFraction& rf)
	{
		if (this == &rf)
			return *this;


		numerator = rf.getNumerator();
		denominator = rf.getDenominator();

		return *this;
	}
};

RationalFraction operator+ (RationalFraction rf1, RationalFraction rf2) {
	int a = rf1.getNumerator();
	int b = rf1.getDenominator();
	int c = rf2.getNumerator();
	int d = rf2.getDenominator();

	int numerator = a * d + b * c;
	int denominator = b * d;

	return RationalFraction(numerator, denominator);
}

RationalFraction operator- (RationalFraction rf1, RationalFraction rf2) {
	int a = rf1.getNumerator();
	int b = rf1.getDenominator();
	int c = rf2.getNumerator();
	int d = rf2.getDenominator();

	int numerator = a * d - b * c;
	int denominator = b * d;

	return RationalFraction(numerator, denominator);
}

RationalFraction operator* (RationalFraction rf1, RationalFraction rf2) {
	int a = rf1.getNumerator();
	int b = rf1.getDenominator();
	int c = rf2.getNumerator();
	int d = rf2.getDenominator();

	int numerator = a * c;
	int denominator = b * d;

	return RationalFraction(numerator, denominator);
}

RationalFraction operator/ (RationalFraction rf1, RationalFraction rf2) {
	int a = rf1.getNumerator();
	int b = rf1.getDenominator();
	int c = rf2.getNumerator();
	int d = rf2.getDenominator();

	int numerator = a * d;
	int denominator = b * c;

	return RationalFraction(numerator, denominator);
}

int main()
{
	RationalFraction a(2, 4); 
	RationalFraction b(1, 3);
	RationalFraction incorrect(1, 0);
	RationalFraction sum = a + b;
	RationalFraction dif = a - b;
	RationalFraction mul = a * b;
	RationalFraction div = a / b;

	a.print();
	cout << endl;
	
	sum.print();
	cout << endl;
	
	dif.print();
	cout << endl;
	
	mul.print();
	cout << endl;
	
	div.print();
	cout << endl;
		
	div = mul = dif;
	div.print();
	cout << endl;

	return 0;
}
