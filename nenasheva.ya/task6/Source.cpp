#include "BullsAndCows.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");

	BullsAndCows BC;

	cout << "Добро пожаловать в игру 'Быки и коровы'" << endl;
	bool win = 0;
	int n;
	int num;
	cout << "Введите длину числа: ";
	cin >> n;
	BC.Set_length(n);
	BC.Set_number();
	while (!win)
	{
		cout << "Введите число из " << n << " знаков: ";
		cin >> num;
		BC.Guessing(num);
		win = BC.Win_check();
	}
	system("pause");
	return 0;
}