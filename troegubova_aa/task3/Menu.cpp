#include <clocale>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "Menu.h"

void error(std::string message, int errorcode)
{
	std::cout << std::endl << message;
	system("pause>nul");
	exit(errorcode);
}

int Control(int left_border, int right_border, int num)
{
	while ((num < left_border) || (num > right_border))
	{
		std::cout << "Incorrect value entered\n";
		std::cin >> num;
	}
	return num;
}

void SetCount_Act(Menu menu1)
{
	std::cout << "Enter the numder of commands in the menu:";
	int act;
	std::cin >> act;
	Control(1, 1000000, act);
	menu1.setCount_act(act);
}

void SetName_Act(Menu menu3)
{
	std::string name; int num;
	std::cout << "Set the name of the menu item:";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "Indicate the item number:";
	std::cin >> num;
	int count_act = menu3.getCount_act() - 1;
	num = Control(0, count_act, num);
	menu3.setName_act(num, name);
}

void GetCount_Act(Menu menu2)
{
	std::cout << "The number of commands in the menu:" << menu2.getCount_act() << std::endl;
}

Menu OutPut(Menu menu2)
{
	int x, y, item;
	std::cout << "Enter the coordinates:";
	std::cin >> x >> y;
	menu2.outPut(x, y);
	item = menu2.getNumber_act();
	return menu2;
}

void GetLast_Act(Menu menu2)
{
	std::cout << "The number of the last selected menu item('-1' means the user has not selected a menu item before):" << menu2.getLast_act() << std::endl;
}

int main()
{
	std::string act;
	std::vector<std::string> act_menu;
	std::ifstream file("Menu.txt");
	if (!file)
	{
		error(std::string("Error opening output file"), 1);
	}
	while (getline(file, act))
	{
		act_menu.push_back(act);
	}
	file.close();

	Menu menu1, menu2(act_menu), menu3(15);
	int i, item;
	while (true)
	{
		system("cls");
		std::cout << "1)set the number of commands in the menu\n2)set menu item name\n3)display the number of the last selected menu item\n4)find out the number of commands in the menu\n5)display the menu on the screen with the subsequent selection of one of the menu items\n";
		std::cin >> item;
		Control(1, 5, item);
		switch (item)
		{
		case 1:
			SetCount_Act(menu1);
			break;
		case 2:
			SetName_Act(menu3);
			break;
		case 3:
			GetLast_Act(menu2);
			break;
		case 4:
			GetCount_Act(menu2);
			break;
		case 5:
			menu2 = OutPut(menu2);
			break;
		default:
			break;
		}
		std::cout << "To continue the program?\n1)yes\n2)no\n";
		std::cin >> i;
		if (i != 1)break;
	}
	system("pause");
}