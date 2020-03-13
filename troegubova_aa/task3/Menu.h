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

	void setCount_act(int _count_act);
	int getCount_act();
	void setName_act(int number, std::string name);
	void outPut(int x, int y);
	int getNumber_act();
	//void getLact_act(int _last_act);
	int getLast_act();
};