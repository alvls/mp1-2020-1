#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include "windows.h"
#include "stdio.h"
#include "memory.h"
#include "Menu.h"

Menu::Menu()
{
	last_act = -1;
	count_act = 0;
	act_menu.resize(count_act);
}

Menu::Menu(int _count_act) : count_act(_count_act), act_menu(_count_act)
{
	last_act = -1;
}

Menu::Menu(std::vector<std::string> &_act)
{
	last_act = -1;
	count_act = _act.size();
	act_menu.assign(_act.begin(), _act.end());
}

Menu::Menu(const Menu &menu1)
{
	last_act = menu1.last_act;
	count_act = menu1.count_act;
	act_menu.assign(menu1.act_menu.begin(), menu1.act_menu.end());
}

Menu::~Menu()
{}

void Menu::OutPut(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	COORD pos;
	pos.X = x;
	pos.Y = y;

	std::vector<std::string>::iterator it;
	for (it = act_menu.begin(); it != act_menu.end(); ++it)
	{

		SetConsoleCursorPosition(Console, pos);
		std::cout << *it << std::endl;
		pos.Y++;
	}
}

int Menu::GetNumberAct()
{
	std::cin >> last_act;
	while ((last_act < 0) || (last_act > count_act - 1))
	{
		std::cout << "Invalid value entered" << std::endl;
		std::cin >> last_act;
	}
	return last_act;
}

int Menu::GetLastAct()
{
	if (last_act != -1)
		return last_act;
	else
		return -1;
}

void Menu::SetCountAct(int _count_act)
{
	count_act = _count_act;
	act_menu.resize(_count_act);
}

int Menu::GetCountAct()
{
	return count_act;
}

void Menu::SetNameAct(int number, std::string name)
{
	act_menu[number] = name;
}