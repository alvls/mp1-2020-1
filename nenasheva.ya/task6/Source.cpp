#include "BullsAndCows.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));
	BullsAndCows BC;

	bool win = 0;
	int length;
	cout << "Введите длину числа: ";
	cin >> length;
	BC.Set_length(length);
	BC.Set_number();
	while (!win)
	{
		BC.Guessing();
		win = BC.Win_check();
	}
	system("pause");
	return 0;
}