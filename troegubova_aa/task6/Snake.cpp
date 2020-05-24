#include"Snake.h"
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<time.h>
#include <windows.h>


Food::Food(): Line()
{
	color = { 245, 17, 97 };
}

Food::~Food()
{}

void Food::Draw()
{
	x2 = x1;
	y2 = y1;
	Line::Draw();
}

bool Food::Check()
{
	if (((x1 + 5) % 15 == 0)&&((y1 + 5) % 15 == 0))
		return true;
	return false;

}

void Food::RandFood()
{
	srand(time(0));
	bool check = false;
	while (!check)
	{
		x1 = rand() % ((40 + 66 * SIZE_CELL) - 55) + 55;
		y1 = rand() % ((40 + 33 * SIZE_CELL) - 55) + 55;
		check = Check();
	}	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Line::Line(): x1(0), x2(0), y1(0), y2(0)
{
	color.resize(3);
}

Line::~Line()
{}

Line::Line(int _x1, int _y1, int _x2, int _y2, std::vector <int> _color)
{
	SetLine(_x1, _y1, _x2, _y2);
	color = _color;
}

void Line::SetLine(int _x1, int _y1, int _x2, int _y2)
{
	x1 = _x1;
	x2 = _x2;
	y1 = _y1;
	y2 = _y2;
}

Line& Line::operator =(const Line &line)
{
	x1 = line.x1;
	x2 = line.x2;
	y1 = line.y1;
	y2 = line.y2;
	color = line.color;
	return *this;
}

void Line::Draw()
{

	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);

	HPEN cP = CreatePen(PS_SOLID, SIZE_CELL, RGB(color[0], color[1], color[2]));
	SelectObject(hDC, cP);
	POINT p;

	MoveToEx(hDC, x1, y1, &p);
	LineTo(hDC, x2, y2);
}

int Line::GetX1()
{
	return x1;
}

int Line::GetY1()
{
	return y1;
}

int Line::GetX2()
{
	return x2;
}

int Line::GetY2()
{
	return y2;
}

void Line:: SetX1(int _x1)
{
	x1 = _x1;
}

void Line::SetY1(int _y1)
{
	y1 = _y1;
}

void Line::SetX2(int _x2)
{
	x2 = _x2;
}

void Line::SetY2(int _y2)
{
	y2 = _y2;
}

void Line:: DrawColor(std::vector <int> _color)
{

	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);

	HPEN cP = CreatePen(PS_SOLID, SIZE_CELL, RGB(_color[0], _color[1], _color[2]));
	SelectObject(hDC, cP);
	POINT p;

	MoveToEx(hDC, x1, y1, &p);
	LineTo(hDC, x2, y2);	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Barrier::Barrier(): Line(40, 40, 40 + 67 * SIZE_CELL, 40, { 207, 25, 179 })
{
	width = 67 * SIZE_CELL;//ширина(68 клеток)
	height = 34 * SIZE_CELL;//высота(35 клетки)
}

Barrier::~Barrier()
{}

void::Barrier::Draw()
{
	Line::Draw();
	x2 = 40;
	y2 += height;
	Line::Draw();
	y1 += height;
	x2 += width;
	Line::Draw();
	x1 += width;
	y1 = 40;
	Line::Draw();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Snake::Snake(): size(5)
{
	snake.resize(0);
	snake.push_back(Line(805, 325, 730, 325, { 46, 149, 232 }));
	head = Line(730, 325, 730, 325, { 72, 219, 116 });
	dir = "left"; 
	continuation = true;
}

Snake::~Snake()
{}

void Snake::Draw()
{
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].Draw();
	}
	head.Draw();
}

void Snake::DrawColor(std::vector<int> _color)
{
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].DrawColor(_color);
	}
	head.DrawColor({ 207, 25, 179 });
}

bool Snake::CheckYourself()
{

	for (int i = 0; i < (snake.size() - 1); i++)
	{
		if (snake[i].GetX1() < snake[i].GetX2())
		{
			if ((head.GetX1() >= snake[i].GetX1()) && (head.GetX1() <= snake[i].GetX2()))
			{
				if (snake[i].GetY1() < snake[i].GetY2())
				{
					if ((head.GetY1() >= snake[i].GetY1()) && (head.GetY1() <= snake[i].GetY2()))
						return false;
				}
				else
				{
					if ((head.GetY1() <= snake[i].GetY1()) && (head.GetY1() >= snake[i].GetY2()))
						return false;
				}
				
			}
		}
		else
		{
			if ((head.GetX1() <= snake[i].GetX1()) && (head.GetX1() >= snake[i].GetX2()))
			{
				if (snake[i].GetY1() < snake[i].GetY2())
				{
					if ((head.GetY1() >= snake[i].GetY1()) && (head.GetY1() <= snake[i].GetY2()))
						return false;
				}
				else
				{
					if ((head.GetY1() <= snake[i].GetY1()) && (head.GetY1() >= snake[i].GetY2()))
						return false;
				}

			}
		}
		
	}
	return true;
}

bool Snake::CheckBarrier()
{
	
	if ((head.GetY1() == 40) || (head.GetY1() == 550))
	{
		return false;
	}
	if ((head.GetX1() == 40) || (head.GetX1() == 1045))
	{
		return false;
	}
	return true;

}

void Snake:: MoveLeft()
{
	if (dir == "right")
	{
		MoveRight();
	}
	else
	{
		snake[0].DrawColor({ 12, 12, 12 });

		if (dir != "left")
		{
			snake.push_back(Line(snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), { 46, 149, 232 }));
			dir = "left";
		}

		if ((snake[0].GetY1() != snake[0].GetY2()) && ((snake.size() % 2 == 0)))
		{
			snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() - SIZE_CELL);
			if (snake[0].GetY1() < snake[0].GetY2())
				snake[0].SetY1(snake[0].GetY1() + SIZE_CELL);
			else
				snake[0].SetY1(snake[0].GetY1() - SIZE_CELL);
			head.SetX1(head.GetX1() - SIZE_CELL);
			head.SetX2(head.GetX2() - SIZE_CELL);
			if (snake[0].GetY1() == snake[0].GetY2())
			{
				snake.erase(snake.begin());
			}
		}
		else
			if ((snake[0].GetX1() != snake[0].GetX2()) && (snake.size() > 1))
			{
				snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() - SIZE_CELL);
				if (snake[0].GetX1() < snake[0].GetX2())
					snake[0].SetX1(snake[0].GetX1() + SIZE_CELL);
				else
					snake[0].SetX1(snake[0].GetX1() - SIZE_CELL);
				head.SetX1(head.GetX1() - SIZE_CELL);
				head.SetX2(head.GetX2() - SIZE_CELL);
				if (snake[0].GetX1() == snake[0].GetX2())
				{
					snake.erase(snake.begin());
				}
			}
			else
			{

				snake[snake.size() - 1].SetX1(snake[snake.size() - 1].GetX1() - SIZE_CELL);
				snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() - SIZE_CELL);
				head.SetX1(head.GetX1() - SIZE_CELL);
				head.SetX2(head.GetX2() - SIZE_CELL);

			}
		if (CheckYourself() && CheckBarrier())
		{
			Draw();
			Sleep(100);
		}
		else
		{
			DrawColor({ 10, 10, 10 });
			continuation = false;
		}
	}
}

void Snake::MoveRight()
{
	if (dir == "left")
	{
		MoveLeft();
	}
	else
	{
		snake[0].DrawColor({ 12, 12, 12 });
		if (dir != "right")
		{
			snake.push_back(Line(snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), { 46, 149, 232 }));
			dir = "right";
		}


		if ((snake[0].GetY1() != snake[0].GetY2()) && (snake.size() % 2 == 0))
		{
			snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() + SIZE_CELL);
			if (snake[0].GetY1() > snake[0].GetY2())
				snake[0].SetY1(snake[0].GetY1() - SIZE_CELL);
			else
				snake[0].SetY1(snake[0].GetY1() + SIZE_CELL);

			head.SetX1(head.GetX1() + SIZE_CELL);
			head.SetX2(head.GetX2() + SIZE_CELL);
			if (snake[0].GetY1() == snake[0].GetY2())
			{
				snake.erase(snake.begin());
			}
		}
		else
			if ((snake[0].GetX1() != snake[0].GetX2()) && (snake.size() > 1))
			{
				snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() + SIZE_CELL);
				if (snake[0].GetX1() > snake[0].GetX2())
					snake[0].SetX1(snake[0].GetX1() - SIZE_CELL);
				else
					snake[0].SetX1(snake[0].GetX1() + SIZE_CELL);

				head.SetX1(head.GetX1() + SIZE_CELL);
				head.SetX2(head.GetX2() + SIZE_CELL);
				if (snake[0].GetX1() == snake[0].GetX2())
				{
					snake.erase(snake.begin());
				}
			}
			else
			{
				snake[snake.size() - 1].SetX1(snake[snake.size() - 1].GetX1() + SIZE_CELL);
				snake[snake.size() - 1].SetX2(snake[snake.size() - 1].GetX2() + SIZE_CELL);
				head.SetX1(head.GetX1() + SIZE_CELL);
				head.SetX2(head.GetX2() + SIZE_CELL);
			}
		if (CheckYourself() && CheckBarrier())
		{
			Draw();
			Sleep(100);
		}
		else
		{
			DrawColor({ 10, 10, 10 });
			continuation = false;
		}
	}
}

void Snake::MoveUp()
{
	if (dir == "down")
	{
		MoveDown();
	}
	else
	{
		snake[0].DrawColor({ 12, 12, 12 });
		if (dir != "up")
		{
			snake.push_back(Line(snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), { 46, 149, 232 }));
			dir = "up";
		}

		if ((snake[0].GetX1() != snake[0].GetX2()) && (snake.size() % 2 == 0))
		{
			snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() - SIZE_CELL);
			if (snake[0].GetX1() > snake[0].GetX2())
				snake[0].SetX1(snake[0].GetX1() - SIZE_CELL);
			else
				snake[0].SetX1(snake[0].GetX1() + SIZE_CELL);

			head.SetY1(head.GetY1() - SIZE_CELL);
			head.SetY2(head.GetY2() - SIZE_CELL);
			if (snake[0].GetX1() == snake[0].GetX2())
			{
				snake.erase(snake.begin());
			}
		}
		else
			if ((snake[0].GetY1() != snake[0].GetY2()) && (snake.size() > 1))
			{
				snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() - SIZE_CELL);
				if (snake[0].GetY1() > snake[0].GetY2())
					snake[0].SetY1(snake[0].GetY1() - SIZE_CELL);
				else
					snake[0].SetY1(snake[0].GetY1() + SIZE_CELL);

				head.SetY1(head.GetY1() - SIZE_CELL);
				head.SetY2(head.GetY2() - SIZE_CELL);
				if (snake[0].GetY1() == snake[0].GetY2())
				{
					snake.erase(snake.begin());
				}
			}
			else
			{
				snake[snake.size() - 1].SetY1(snake[snake.size() - 1].GetY1() - SIZE_CELL);
				snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() - SIZE_CELL);
				head.SetY1(head.GetY1() - SIZE_CELL);
				head.SetY2(head.GetY2() - SIZE_CELL);
			}

		if (CheckYourself() && CheckBarrier())
		{
			Draw();
			Sleep(100);
		}
		else
		{
			DrawColor({ 10, 10, 10 });
			continuation = false;
		}
	}
}

void Snake::MoveDown()
{
	if (dir == "up")
	{
		MoveUp();
	}
	else
	{
		snake[0].DrawColor({ 12, 12, 12 });
		if (dir != "down")
		{
			snake.push_back(Line(snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), snake[snake.size() - 1].GetX2(), snake[snake.size() - 1].GetY2(), { 46, 149, 232 }));
			dir = "down";
		}
		if ((snake[0].GetX1() != snake[0].GetX2()) && (snake.size() % 2 == 0))
		{
			snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() + SIZE_CELL);
			if (snake[0].GetX1() < snake[0].GetX2())
				snake[0].SetX1(snake[0].GetX1() + SIZE_CELL);
			else
				snake[0].SetX1(snake[0].GetX1() - SIZE_CELL);
			head.SetY1(head.GetY1() + SIZE_CELL);
			head.SetY2(head.GetY2() + SIZE_CELL);
			if (snake[0].GetX1() == snake[0].GetX2())
			{
				snake.erase(snake.begin());
			}
		}
		else
			if ((snake[0].GetY1() != snake[0].GetY2()) && (snake.size() > 1))
			{
				snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() + SIZE_CELL);
				if (snake[0].GetY1() < snake[0].GetY2())
					snake[0].SetY1(snake[0].GetY1() + SIZE_CELL);
				else
					snake[0].SetY1(snake[0].GetY1() - SIZE_CELL);
				head.SetY1(head.GetY1() + SIZE_CELL);
				head.SetY2(head.GetY2() + SIZE_CELL);
				if (snake[0].GetY1() == snake[0].GetY2())
				{
					snake.erase(snake.begin());
				}
			}
			else
			{
				snake[snake.size() - 1].SetY1(snake[snake.size() - 1].GetY1() + SIZE_CELL);
				snake[snake.size() - 1].SetY2(snake[snake.size() - 1].GetY2() + SIZE_CELL);
				head.SetY1(head.GetY1() + SIZE_CELL);
				head.SetY2(head.GetY2() + SIZE_CELL);
			}
		if (CheckYourself() && CheckBarrier())
		{
			Draw();
			Sleep(100);
		}
		else
		{
			DrawColor({ 10, 10, 10 });
			continuation = false;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Game::Game(Snake * _snake)
{
	snake = _snake;
}

Game::~Game() {}

bool Game::CheckFood()//проверка на правильность еды
{
	
	for (int i = 0; i < snake->snake.size(); i++)
	{
		if (snake->snake[i].GetX1() < snake->snake[i].GetX2())
		{
			if ((food.GetX1() >= snake->snake[i].GetX1()) && (food.GetX1() <= snake->snake[i].GetX2()))
			{
				if (snake->snake[i].GetY1() < snake->snake[i].GetY2())
				{
					if ((food.GetY1() >= snake->snake[i].GetY1()) && (food.GetY1() <= snake->snake[i].GetY2()))
						return false;
				}
				else
				{
					if ((food.GetY1() <= snake->snake[i].GetY1()) && (food.GetY1() >= snake->snake[i].GetY2()))
						return false;
				}

			}
		}
		else
		{
			if ((food.GetX1() <= snake->snake[i].GetX1()) && (food.GetX1() >= snake->snake[i].GetX2()))
			{
				if (snake->snake[i].GetY1() < snake->snake[i].GetY2())
				{
					if ((food.GetY1() >= snake->snake[i].GetY1()) && (food.GetY1() <= snake->snake[i].GetY2()))
						return false;
				}
				else
				{
					if ((food.GetY1() <= snake->snake[i].GetY1()) && (food.GetY1() >= snake->snake[i].GetY2()))
						return false;
				}
			}
		}
	}
	return true;
}

void Game::DrawFood()//рисуется еда с учётом положения змейки
{
	bool check = false;
	while (!check)
	{
		food.RandFood();//задались координады в нужном диапазоне
		check = CheckFood();
	}
	food.Draw();
}

void Game::Increase()//увеличение
{
	if (snake->snake[0].GetX1() == snake->snake[0].GetX2())
	{

		if (snake->snake[0].GetY1() > snake->snake[0].GetY2())
			snake->snake[0].SetY1(snake->snake[0].GetY1() + SIZE_CELL);
		else
			snake->snake[0].SetY1(snake->snake[0].GetY1() - SIZE_CELL);
	}
	else {

		if (snake->snake[0].GetX1() > snake->snake[0].GetX2())
			snake->snake[0].SetX1(snake->snake[0].GetX1() + SIZE_CELL);
		else
			snake->snake[0].SetX1(snake->snake[0].GetX1() - SIZE_CELL);
	}
	snake->size++;
}

void Game::Move()
{
	int act;
	while ((snake->continuation)&&(snake->size < snake->max_size))
	{
		while (!_kbhit() && (snake->continuation))
		{
			snake->MoveLeft();
			if (!CheckFood())
			{
				Increase();
				WriteSize();
				DrawFood();
			}
		}
		act = _getch();
		switch (act)
		{
		case 72://вверх
			while ((!_kbhit())&&(snake->continuation))
			{
				snake->MoveUp();
				if (!CheckFood())
				{
					Increase();
					WriteSize();
					DrawFood();
				}
			}
			break;
		case 80:
			while (!_kbhit() && (snake->continuation))
			{
				snake->MoveDown();
				if (!CheckFood())
				{
					Increase();
					WriteSize();
					DrawFood();
				}
			}
			break;
		case 75:
			while (!_kbhit() && (snake->continuation))
			{
				snake->MoveLeft();
				if (!CheckFood())
				{
					Increase();
					WriteSize();
					DrawFood();
				}
			}
			break;
		case 77:
			while (!_kbhit() && (snake->continuation))
			{
				snake->MoveRight();
				if (!CheckFood())
				{
					Increase();
					WriteSize();
					DrawFood();
				}
			}
			break;
		default:
			break;
		}
	}
	if (snake->max_size == snake->size)
		std::cout << " You won!!!";
	else
	{
		std::cout << " Game over.";	
	}
}

void Game::WriteSize()
{
	COORD position = { 0,0 }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	std::cout << "Snake size: " << snake->size;
}

void Game::GameStart()
{
	barrier.Draw();
	snake->Draw();//начальное положение
	DrawFood();
	WriteSize();
	Move();
}