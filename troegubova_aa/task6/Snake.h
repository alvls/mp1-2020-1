#pragma once
#include<iostream>
#include<vector>
#include<string>

#define SIZE_CELL 15

//	std::vector <int> pink = { 207, 25, 179 };
//	std::vector <int> blue = { 26, 237, 209 };
//	std::vector <int> dark_blue = { 422, 23, 209 };
//	std::vector <int> read = { 245, 17, 97 };

class Line
{
protected:
	std::vector <int> color;
	int x1, y1;//координаты начала линии
	int x2, y2;//координаты конца линии
public:
	Line();
	~Line();
	Line(int _x1, int _y1, int _x2, int _y2, std::vector <int> _color);
	Line& operator =(const Line &line);
	void SetLine(int _x1, int _y1, int _x2, int _y2);
	void DrawColor(std::vector <int> _color);
	int GetX1();
	int GetY1();
	int GetX2();
	int GetY2();
	void SetX1(int _x1);
	void SetY1(int _y1);
	void SetX2(int _x2);
	void SetY2(int _y2);
	void Draw();
};

class Food : public Line
{
	bool Check();
public:
	Food();
	~Food();
	void RandFood();
	void Draw();
};


class Barrier: public Line
{
	std::vector <int> pink = { 207, 25, 179 };
	int width;//ширина
	int height;//высота

public:
	Barrier();
	~Barrier();
	void Draw();
};


class Snake
{
	std::vector<Line> snake;
	Line head;// голова
	int size;//текущий размер
	const int max_size = 50;
	bool continuation;
	std::string dir; //клавиша
public:
	friend class Game;
	Snake();
	~Snake();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();
	bool CheckYourself();
	bool CheckBarrier();
	void DrawColor(std::vector<int> _color);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Game
{
	Barrier barrier;
	Food food;
	Snake *snake;
	
public:
	Game(Snake *_snake); 
	~Game(); 
	void Increase();
	bool CheckFood();
	void Move();
	void WriteSize();
	void DrawFood();
	void GameStart();
};
