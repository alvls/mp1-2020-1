#include <iostream>
using namespace std;
class lengths
{
private:
	float meters;
public:
	lengths()
	{
		meters = 0;
	}
	lengths(float m)
	{
		meters = m;
	}
	lengths(const lengths &lenn)
	{
		meters = lenn.meters;
	}
	lengths& operator=(const lengths &lenn)
	{
		meters = lenn.meters;
		return *this;
	}
	float met()
	{
		return meters;
	}
	float arshin()
	{
		return meters * 1.406074;
	}
	float ft()
	{
		return meters * 3.28084;
	}
	float inch()
	{
		return meters * 39.37008;
	}
	float mile()
	{
		return meters * 0.00062137;
	}
	float sazhen()
	{
		return meters * 0.46869;
	}
	void Printt()
	{
		cout << meters << " meters." << endl;
	}
};
int main(void)
{
	float a = -1;
	cout << "Enter the length in meters: " << endl;
	do
	{
		cin >> a;
		if (a < 0)
		{
			cout << "Enter the length in meters: " << endl;
		}
	} while (a < 0);
	lengths lenn(a);
	int type = 0, k = -1;
	lengths check;
	check = lenn;
	cout << "Want to know the current length in meters?\n 1-yes,0-no " << endl;
	cin >> k;
	while ((k != 0) && (k != 1))
	{
		cout << ("Enter 1 or 0.\n");
		cin >> k;
	}
	switch (k)
	{
	case 1:
		check.Printt();
		cout << " Current length  " << lenn.met() << " meters\n";
		break;

	case 0:

		break;
	}
	do
	{
		cout << "Enter the type of length measurement :\n 1) Arshin.\n 2)ft.\n 3)Inch.\n 4)Mile.\n 5)Sazhen." << endl;//ft-ôóò
		cin >> type;
	} while ((type < 1) || (type > 5));
	switch (type)
	{
	case 1:
		check.Printt();
		cout << " It's " << lenn.arshin() << " arshin\n";
		break;
	case 2:
		check.Printt();
		cout << " It's " << lenn.ft() << " ft\n";
		break;
	case 3:
		check.Printt();
		cout << " It's " << lenn.inch() << "inch\n";
		break;
	case 4:
		check.Printt();
		cout << " It's " << lenn.mile() << " mile\n";
		break;
	case 5:
		check.Printt();
		cout << " It's " << lenn.sazhen() << " sazhen\n";
		break;
	}
	system("pause");
	return 0;
}