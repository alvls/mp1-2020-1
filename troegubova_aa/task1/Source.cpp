#include <iostream> 

typedef unsigned int uint;
typedef long long ll;

#define MAX_UINT 4294967295

class LongNumber
{
private:
	int high_part;
	uint low_part;
	int sign;

public:
	LongNumber()
	{
		high_part = 0;
		low_part = 0;
		sign = 1;
	}

	LongNumber(const LongNumber& num)
	{
		high_part = num.high_part;
		low_part = num.low_part;
		sign = num.sign;
	}

	LongNumber(const ll& num)
	{
		if (num < 0)
			low_part = (num * (-1)) & MAX_UINT;
		else
			low_part = num & MAX_UINT;
		high_part = (uint)(num / 0x100000000);
		if (num < 0)
			sign = -1;
		else
			sign = 1;
	}

	~LongNumber()
	{
		high_part = 0;
		low_part = 0;
		sign = 1;
	}

	void Abs(const LongNumber& num)
	{
		if (num.high_part < 0)
		{
			high_part = -1 * num.high_part;
		}
		else
			high_part = num.high_part;
		sign = 1;
		low_part = num.low_part;
	}

	LongNumber Add(const LongNumber& num)
	{
		LongNumber Result;
		int flag = 0;
		Result.low_part = low_part + num.low_part;
		if (MAX_UINT - low_part < num.low_part)
			flag++;
		Result.high_part = high_part + num.high_part + sign * flag;
		Result.sign = sign;

		return Result;
	}

	LongNumber Sub(const LongNumber& num)
	{
		LongNumber Result;
		int flag = 0;
		if (low_part < num.low_part)
			flag = (int)((low_part - num.low_part + 0x100000000) / 0x100000000);
		Result.low_part = low_part - num.low_part + 0x100000000;
		Result.high_part = high_part - num.high_part - flag;
		return Result;
	}

	LongNumber Mul(const LongNumber& num)
	{
		LongNumber Result, _num(num), tmp(*this);

		int x = _num.low_part % 10;
		while (_num.high_part || (_num.low_part / 10))
		{
			int flag = 0;
			for (int i = 0; i < x; i++)
			{
				if (MAX_UINT - tmp.low_part < Result.low_part)
					flag++;
				Result.low_part = Result.low_part + tmp.low_part;
			}
			Result.high_part = Result.high_part + tmp.high_part * x + flag;

			flag = _num.high_part % 10;
			_num.high_part /= 10;
			_num.low_part = (uint)((_num.low_part + flag * 0x100000000) / 10);

			flag = 0;
			uint _low = tmp.low_part;
			for (int i = 1; i < 10; i++)
			{
				if (MAX_UINT - tmp.low_part < _low)
					flag++;
				tmp.low_part = tmp.low_part + _low;
			}
			tmp.high_part = tmp.high_part * 10 + flag;
			x = _num.low_part % 10;
		}

		int flag = 0;
		for (int i = 0; i < x; i++)
		{
			if (MAX_UINT - tmp.low_part < Result.low_part)
				flag++;
			Result.low_part = Result.low_part + tmp.low_part;
		}
		Result.high_part = Result.high_part + tmp.high_part * x + flag;

		return Result;
	}

	LongNumber Div(const LongNumber& num)
	{
		LongNumber Result;
		Result.high_part = (int)(((high_part * 0x100000000 + low_part) / (num.high_part * 0x100000000 + num.low_part)) / 0x100000000);
		Result.low_part = (high_part * 0x100000000 + low_part) / (num.high_part * 0x100000000 + num.low_part);
		return Result;
	}

	LongNumber Mod(const LongNumber& num)
	{
		LongNumber Result = (*this) / num;
		Result = Result * num;
		Result = (*this) - Result;
		return Result;
	}

	void Write(const LongNumber& num)
	{

		if (*this == num)
			std::cout << " It's true" << std::endl;
		else
			std::cout << " It's false" << std::endl;

	}

	LongNumber& operator= (const LongNumber& num)
	{
		low_part = num.low_part;
		high_part = num.high_part;
		sign = num.sign;
		return *this;
	}

	LongNumber operator+ (const LongNumber& num)
	{
		if (sign == num.sign)
		{
			LongNumber* tmp = new LongNumber(this->Add(num));
			return *tmp;
		}
		else if (sign == 1)
		{
			LongNumber _num = num;
			_num.sign = 1;
			LongNumber* tmp = new LongNumber(this->Sub(_num));

			return *tmp;
		}
		else
		{
			LongNumber& _num = *this;
			_num.sign = 1;
			LongNumber* x = new LongNumber(num);
			LongNumber* tmp = new LongNumber(x->Sub(_num));
			sign = -1;
			return *tmp;
		}
	}

	LongNumber operator- (const LongNumber& num)
	{
		if (sign == 1)
		{
			if (sign == num.sign)
			{
				LongNumber* tmp = new LongNumber(this->Sub(num));
				return *tmp;
			}
			else
			{
				LongNumber _num = num;
				_num.sign = 1;
				LongNumber* tmp = new LongNumber(this->Add(_num));
				return *tmp;
			}
		}
		else
		{
			if (num.sign == 1)
			{
				LongNumber _num = num;
				_num.sign = -1;
				LongNumber* tmp = new LongNumber(this->Add(_num));
				return *tmp;
			}
			else
			{
				LongNumber& x = *this;
				x.sign = 1;
				LongNumber* _num = new LongNumber(num);
				(*_num).sign = 1;

				LongNumber* tmp = new LongNumber(_num->Sub(x));
				sign = -1;
				return *tmp;
			}
		}
	}

	LongNumber operator* (const LongNumber& num)
	{
		LongNumber x, y;
		x.Abs(*this);
		y.Abs(num);
		LongNumber* tmp = new LongNumber(x.Mul(y));
		(*tmp).sign = (*this).sign * num.sign;
		if ((*tmp).sign == -1)
			(*tmp).high_part *= -1;
		return *tmp;
	}

	LongNumber operator/ (const LongNumber& num)
	{
		LongNumber x, y;
		x.Abs(*this);
		y.Abs(num);
		LongNumber* tmp = new LongNumber(x.Div(y));
		(*tmp).sign = (*this).sign * num.sign;
		if ((*tmp).sign == -1)
			(*tmp).high_part *= -1;
		return *tmp;
	}

	LongNumber operator% (const LongNumber& num)
	{
		LongNumber* tmp = new LongNumber(this->Mod(num));
		return *tmp;
	}

	bool operator== (const LongNumber& num)
	{
		return low_part == num.low_part && high_part == num.high_part && sign == num.sign;
	}

	bool operator> (const LongNumber& num)
	{
		if (high_part > num.high_part)
			return true;
		else if (high_part == num.high_part)
			if (sign == num.sign)
				if (sign == 1)
					return low_part > num.low_part;
				else
					return low_part < num.low_part;
			else
				if (sign == 1)
					return true;
				else
					return false;
		return false;
	}

	bool operator>= (const LongNumber& num)
	{
		return *this > num || *this == num;
	}

	bool operator< (const LongNumber& num)
	{
		if (high_part > num.high_part)
			return true;
		else if (high_part == num.high_part)
			if (sign == num.sign)
				if (sign == 1)
					return low_part < num.low_part;
				else
					return low_part > num.low_part;
			else
				if (sign == 1)
					return false;
				else
					return true;
		return false;
	}

	bool operator<= (const LongNumber& num)
	{
		return *this < num || *this == num;
	}

	friend std::ostream& operator<<(std::ostream& stream, const LongNumber& num)
	{
		if (num.sign > 0)
			stream << (num.high_part * 0x100000000 + num.low_part) << std::endl;
		else
			stream << (num.high_part * 0x100000000 - num.low_part) << std::endl;
		return stream;
	}
};

int main()
{
	LongNumber x(1000000000000), y(333), a(-128), b(-2500);
	std::cout << " x = " << x << " y = " << y << " a = " << a << " b = " << b;
	std::cout << std::endl;

	LongNumber z = x + y;
	std::cout << " x + y = " << z;
	z = a + b;
	std::cout << " a + b = " << z;
	z = y + a;
	std::cout << " y + a = " << z;
	std::cout << std::endl;

	z = x - y;
	std::cout << " x - y = " << z;
	z = y - a;
	std::cout << " y - a = " << z;
	z = a - b;
	std::cout << " a - b = " << z;
	std::cout << std::endl;

	z = x * y;
	std::cout << " x * y = " << z;
	z = y * a;
	std::cout << " y * a = " << z;
	z = a * b;
	std::cout << " a * b = " << z;
	std::cout << std::endl;

	z = x / y;
	std::cout << " x / y = " << z;
	z = y / a;
	std::cout << " y / a = " << z;
	z = b / a;
	std::cout << " b / a = " << z;
	std::cout << std::endl;

	z = x % y;
	std::cout << " x % y = " << z;
	z = y % a;
	std::cout << " y % a = " << z;
	z = b % a;
	std::cout << " b % a = " << z;
	std::cout << std::endl;

	LongNumber n = 1;
	z = x > y;
	std::cout << " x > y ";
	n.Write(z);
	z = y < a;
	std::cout << " y < a ";
	n.Write(z);
	z = b <= a;
	std::cout << " b <= a ";
	n.Write(z);
	z = x <= a;
	std::cout << " x =< a ";
	n.Write(z);
	std::cout << std::endl;
	system("pause");
}