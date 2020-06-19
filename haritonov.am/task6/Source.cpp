#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

namespace xy {
#include "console.cpp"
}

using namespace std;

struct pos
{
	int x;
	int y;
};

class Snake
{
	vector <pos> snake;
	int M, N;				// <x> <y>
	int direction = 1;	    // <left> <up> <right>  <down>
	pos tail = {1, 1};
	pos fruit;
	int point = 0;
public:
	int random(int a, int b)
	{
		if (a > 0) return a + rand() % (b - a);
		else return a + rand() % (abs(a) + b);
	}

	void create_a_field(int _N, int _M)
	{
		N = _N;
		M = _M;
		xy::textbackground(xy::GREEN);

		xy::gotoxy(0, 0);
		for(int i = 0; i < N; i++)
			cout << " ";

		xy::gotoxy(0, M);
		for (int i = 0; i <= N; i++)
			cout << " ";

		for (int i = 0; i < M; i++)
		{
			xy::gotoxy(0, i);
			cout << " ";
		}

		for (int i = 0; i < M; i++)
		{
			xy::gotoxy(N, i);
			cout << " ";
		}
		xy::textbackground(xy::BLACK);
	}

	void create_a_snake()
	{
		pos pos;
		int x = random(1, N - 6);
		int y = random(1, M - 1);
		for (int i = 0; i < 5; i++)
		{
			pos.x = x + i;
			pos.y = y;
			snake.push_back(pos);
		}
	}

	void paint_a_snake()
	{
		xy::gotoxy(snake[0].x, snake[0].y);
		xy::textbackground(xy::YELLOW);
		cout << " ";
		for (int i = 1; i < snake.size(); i++)
		{
			xy::gotoxy(snake[i].x, snake[i].y);
			xy::textbackground(xy::CYAN);
			cout << " ";
			xy::gotoxy(tail.x, tail.y);
		}
		xy::textbackground(xy::BLACK);
		tail.x = snake[snake.size() - 1].x;
		tail.y = snake[snake.size() - 1].y;
	}

	void step()
	{
		switch (direction)
		{
		case 1:
			for (int i = snake.size() - 1; i >= 1; i--)
				snake[i] = snake[i - 1];
			snake[0].x--;
			break;
		case 2:
			for (int i = snake.size() - 1; i >= 1; i--)
				snake[i] = snake[i - 1];
			snake[0].y--;
			break;
		case 3:
			for (int i = snake.size() - 1; i >= 1; i--)
				snake[i] = snake[i - 1];
			snake[0].x++;
			break;
		case 4:
			for (int i = snake.size() - 1; i >= 1; i--)
				snake[i] = snake[i - 1];
			snake[0].y++;
			break;
		}
	}

	void turn_check()
	{
		int button;
		if (_kbhit())
		{
			button = _getch();
			switch (button)
			{
			case 75: if (direction != 3) direction = 1; break;	//¬лево
			case 72: if (direction != 4) direction = 2; break;	//¬верх
			case 77: if (direction != 1) direction = 3; break;	//¬право
			case 80: if (direction != 2) direction = 4; break;	//¬низ
			}
		}
	}

	int crash_check()
	{
		for (int i = 1; i < snake.size(); i++)
			if ((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y))
				return 1;
		if ((snake[0].x == 0) || (snake[0].x == N))
			return 1;
		if ((snake[0].y == 0) || (snake[0].y == M))
			return 1;
		return 0;
	}

	void fruit_spawn()
	{
  		int agree = 0, time = 0;
  		while (agree == 0)
  		{
  			agree = 1;
			fruit.x = random(1, N - 1);
			fruit.y = random(1, M - 1);
  			for (int i = 0; i < snake.size(); i++)
  				if ((fruit.x == snake[i].x) && (fruit.y == snake[i].y))
  					agree = 0;
		}		
		xy::gotoxy(fruit.x, fruit.y);
		xy::textbackground(xy::RED);
		cout << " ";
		xy::textbackground(xy::BLACK);
	}

	int eat_check()
	{
		if ((snake[0].x == fruit.x) && (snake[0].y == fruit.y))
		{
			point++;
			return 1;
		}
		return 0;
	}

	void grow()
	{
		pos buffer;
		buffer.x = snake[snake.size() - 1].x;
		buffer.y = snake[snake.size() - 1].y;
		xy::Sleep(15);
		step();
		snake.push_back(buffer);
		fruit_spawn();
	}

	int speed(int _speed)
	{
		switch (_speed)
		{
		case 1: return 300; break;
		case 2: return 200; break;
		case 3: return 150; break;
		case 4: return 100; break;
		case 5: return 50;  break;
		}
	}

	int move(int _length, int _speed)
	{
		while (true)
		{	
			xy::Sleep(speed(_speed));
			turn_check();
			step();
			paint_a_snake();
			turn_check();
			if (crash_check() == 1)
				return 0;
			if (eat_check() == 1)
				grow();
			if (point == _length - 5)
				return(1);
		}
	}

	void start_game(int _N, int _M, int _length, int _speed)
	{
		srand(time(NULL));
		int win;
		xy::HideCursor();
		create_a_field(_N, _M);
		create_a_snake();
		paint_a_snake();
		_getch();
		fruit_spawn();
		win = move(_length, _speed);
		if (win == 0)
		{
			xy::clrscr();
			xy::gotoxy(0, 0);
			cout << "Game over!";
		}
		else
		{
			{
				xy::clrscr();
				xy::gotoxy(0, 0);
				cout << "Congratulations!";
			}
		}
		xy::gotoxy(0, 1);
	}
};


int main()
{
	Snake p1;
	int N, M;
	int length;
	int speed;
	cout << "Select the field frame x*y, length to win , difficulty(1,2,3,4,5)" << endl;
	cin >> N >> M >> length >> speed;
	xy::clrscr();
	p1.start_game(N, M, length, speed);

	system("pause");
	return(0);
}