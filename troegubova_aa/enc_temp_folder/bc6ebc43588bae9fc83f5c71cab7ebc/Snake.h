#pragma once
#include<iostream>
#include<vector>
#include<string>

#define SIZE_CELL 15


class Color
{
	enum {red, yellow, blue, pink};

};

class Cell
{
protected:
	const int size = 15; //пикселей
	//Color color;
public:
	Cell();
	~Cell();
	void Draw(int xCo, int yCo);

};

class Barrier
{
	int width;//ширина кол-во клеток
	int height;//высота 
	const int xCo = 50;
	const int yCo = 50;//координаты верхнего правого угла, в пикселях
	//Color color;

public:
	Barrier();
	Barrier(int _width, int _height);
	~Barrier();
	void Draw() const;
};

class Food: public Cell 
{
	int xCo;
	int yCo;
	std::vector<int> RandCo();
public:
	Food();
	~Food();
	void Draw();
};

class shake
{

};



class Game
{
	Barrier barrier;

};