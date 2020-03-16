#pragma once
#include <fstream> 
#include <vector>
#include <string>
#include <conio.h>

class Menu
{
private:
	int last_act;
	int count_act;
	std::vector <std::string> act_menu;
public:
	Menu();
	Menu(int _count_act);
	Menu(std::vector<std::string> &_act);
	Menu(const Menu &menu1);
	~Menu();

	void SetCountAct(int _count_act);
	int GetCountAct();
	void SetNameAct(int number, std::string name);
	void OutPut(int x, int y);
	int GetNumberAct();
	int GetLastAct();
};