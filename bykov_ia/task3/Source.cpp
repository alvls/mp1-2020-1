#include <cmath>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::pair;
using std::string;

class IntegralCalculation {
	private:
		double (*func) (double x);
		double leftBorder, rightBorder;
		int numSegments;
		
		int method;
		enum { LEFT, MIDDLE, RIGHT };

		double val;
	public:
		IntegralCalculation(double(*_func)(double) = exp, double _leftBorder = 0, double _rightBorder = 0, int _numSegments = 1, int _method = 0) :
			func(_func), leftBorder(_leftBorder), rightBorder(_rightBorder), numSegments(_numSegments), method(_method), val(0)
		{}

		IntegralCalculation(const IntegralCalculation& copy) :
			func(copy.func), leftBorder(copy.leftBorder), rightBorder(copy.rightBorder), numSegments(copy.numSegments), method(copy.method), val(copy.val)
		{}

		IntegralCalculation& operator=(const IntegralCalculation& _IntCal)
		{
			if (this == &_IntCal)
				return *this;

			func = _IntCal.func;
			leftBorder = _IntCal.leftBorder;
			rightBorder = _IntCal.rightBorder;
			numSegments = _IntCal.numSegments;
			method = _IntCal.method;
			val = _IntCal.val;
			return *this;
		}

		void calculate() {
			double step = (rightBorder - leftBorder)/numSegments;
			double point;
			
			switch (method) {
			case LEFT:
				point = leftBorder;
				break;
			case MIDDLE:
				point = leftBorder + step/2;
				break;
			case RIGHT:
				point = leftBorder + step;
				break;
			}

			for (int i = 0; i < numSegments; i++)
			{
				val += func(point);
				point = point + step;
			}
			val *= step;
		}

		void print()
		{
			cout << val << endl;
		}


		void setFunction(double (*_func) (double x)) {
			func = _func;
		}

		void setBorders(double _leftBorder, double _rightBorder) {
			leftBorder = _leftBorder;
			rightBorder = _rightBorder;
		}

		void setNumSegments(int _numSegments) {
			numSegments = _numSegments;
		}

		void setMethod(int _method) {
			method = _method;
		}

		pair<double, double> getBorders() {
			pair<double, double> borders;
			borders.first = leftBorder;
			borders.second = rightBorder;
			return borders;
		}
};

void main(){
	IntegralCalculation m;
	m.setFunction(sin);
	m.setBorders(0, 3.1415);
	m.setNumSegments(20);
	m.setMethod(1);
	m.calculate();
	m.print();

	IntegralCalculation l = m;
	l.setMethod(0);
	l.calculate();
	l.print();

	IntegralCalculation r = IntegralCalculation(m);
	r.setMethod(2);
	r.calculate();
	r.print();

	double leftBorder = m.getBorders().first;
	double rightBorder = m.getBorders().second;
	cout << leftBorder << " " << rightBorder << endl;
}