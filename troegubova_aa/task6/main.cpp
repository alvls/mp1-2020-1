#include"Snake.h"
#include <Windows.h>
#include<conio.h>
#include <stdlib.h>

int main()
{
	Snake snake;
	Game l(&snake);
	while (true)
	{
		system("cls");
		l.GameStart();
		l.GameOver();
		int i;
		std::cout << "Start the game again? 1)Yes 2)No  ";
		std::cin >> i;
		if (i != 1)break;
	}
	system("pause");
	return 0;
}