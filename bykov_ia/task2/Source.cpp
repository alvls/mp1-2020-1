#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Polynomial {
	private:
		int power;
		float *coefficients;
	public:
		Polynomial(int _power, float *_coefficients) {
			if (_power < 0 || _power > 12)
				throw "IncorrectPower";
			power = _power;
			coefficients = new float[power + 1];
			for (int i = 0; i <= power; i++)
				coefficients[i] = _coefficients[i];
		}

		~Polynomial() {
			delete[] coefficients;
		}

		int getPower() {
			return power;
		}

		float getCoefficient(int num) {
			if (num < 0 || num > power)
				throw "IncorrectNumberCoefficient";
			return coefficients[num];
		}

		float getValue(float x) {
			float val = coefficients[power];
			for (int i = 1; i <= power; i++)
			{
				val *= x;
				val += coefficients[power - i];
			}
			return val;
		}

		Polynomial getDerivative() {
			int powerDer = power - 1;
			float coefficientsDer[12];
			for (int i = 0; i <= powerDer; i++) {
				coefficientsDer[i] = coefficients[i + 1] * (i + 1);
			}
			return Polynomial(powerDer, coefficientsDer);
		}

		void print() {
			int isPrintPrev = 0;
			for (int i = 0; i <= power; i++) {
				if (isPrintPrev)
					printf(" + ");
				if (coefficients[i] != 0) {
					printf("%g", coefficients[i]);
					isPrintPrev = 1;

					if (i != 0)
						printf("x");
					if (i >= 2)
						printf("^%d", i);
				}
			}
		}

		Polynomial& operator= (Polynomial& pol)
		{
			if (this == &pol)
				return *this;

			if (coefficients) delete[] coefficients;

			power = pol.power;
			coefficients = new float[power + 1];
			for(int i = 0; i <= power; i++)
				coefficients[i] = pol.coefficients[i];

			return *this;
		}

		Polynomial (const Polynomial& pol) {
			power = pol.power;
			coefficients = new float[power + 1];
			for (int i = 0; i <= power; i++)
				coefficients[i] = pol.coefficients[i];
		}
};

int main() {
	try {
		float arr[3] = { 1., 2., 0.9 };
		Polynomial a(2, arr);
		Polynomial b = a;
		b.print();
		cout << endl;

		Polynomial incorrect(-1, arr);

		cout << a.getPower() << endl;
		cout << a.getCoefficient(2) << endl;
		cout << a.getCoefficient(4) << endl;

		a.print();
		cout << endl;
		a.getDerivative().print();
		return 0;
	}
	catch (char* s) {
		printf("%s", s);
	}
}