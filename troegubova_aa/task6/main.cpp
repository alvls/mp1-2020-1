#include"Snake.h"
#include <Windows.h>
#include<conio.h>
#include <stdlib.h>

int main()
{
	Snake snake;
	Game l(&snake);
	l.GameStart();
	system("pause");
	return 0;
}