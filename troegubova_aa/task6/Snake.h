﻿#pragma once
#include<iostream>
#include<vector>
#include<string>

#define SIZE_CELL 15

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
	const int max_size = 200;
	bool continuation;
	std::string dir; //клавиша
	int difficulty;
	void Continuation();
	bool CheckYourself();
	bool CheckBarrier();
public:
	friend class Game;
	Snake();
	~Snake();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Draw();
	void DrawColor(std::vector<int> _color);
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Game
{
	Barrier barrier;
	Food food;
	Snake *snake;
	
	void Increase();
	bool CheckFood(); 
	void Move();
	void WriteSize();
	void Customization();
	void DrawFood();
	void GameStart();
	void GameOver();
public:
	Game(Snake *_snake); 
	~Game(); 
	void game();
	
};
