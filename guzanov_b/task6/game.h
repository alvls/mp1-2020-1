#pragma once
#include "snake.h"
#include <thread> 
#include <chrono>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
class game
{
private:
	int exeatfood;
	snake*snakke;
	int N;
	int Maxsize;
	int M;
	int rx, ry;
public:

	game(int N_,int M_,int Maxsize_)
	{
		exeatfood = 0;
		Maxsize = Maxsize_;
		N = N_;
		M = M_;
		snakke = new snake(N / 2, M / 2, N * M);
	}
	~game() {
		delete snakke;
	};
	game(const game& tmp)
	{
		Maxsize = tmp.Maxsize;
		N = tmp.N;
		M = tmp.M;
		snakke = new snake(*(tmp.snakke));
	}
	game& operator=(const game& tmp)
	{
		Maxsize = tmp.Maxsize;
		N = tmp.N;
		M = tmp.M;
		*(snakke) = *(tmp.snakke);
	}
	/*void game_repeat(System::Windows::Forms::DataGridView^ DGV,char dir)
	{
		auto lastUpdate = std::chrono::steady_clock::now();
		char ch = 0;
		while (ch != 27) {
			auto now(std::chrono::steady_clock::now());
			auto dt = now - lastUpdate;
			if (dt >= std::chrono::seconds(1)) {
				lastUpdate = now;
				play(DGV,dir);
				// здесь производим необходимые действия - тоесть сдвигаем змейку на 1 позициию
			}

			if (kbhit()) {
				// обработка ввода
				ch = getch();
				switch (ch)
				{
				case 37:
				{
					dir = 'L';
					break;
				}
				case 38:
				{
					dir = 'U';
					break;
				}
				case 39:
				{
					dir = 'R';
					break;
				}
				case 40:
				{
					dir = 'D';
					break;
				}
				}

			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	*/
	int play(System::Windows::Forms::DataGridView^ DGV,char dir)
	{
		int headx, heady;
		headx = snakke->getheadx();
		heady = snakke->getheady();


		//DGV->Rows[10]->Cells[10]->Style->BackColor = Color::White;
		snakke->show_snake(DGV);
		switch (dir)
		{
		case 'D':
		{
			heady++;
			break;
		}
		case 'U':
		{
			heady--;
			break;
		}
		case 'L':
		{
			headx--;
			break;
		}
		case 'R':
		{
			headx++;
			break;
		}
		}
		if(headx==0||heady==0|| headx == M+1|| heady == N+1)
		{
				return -1;//error
		}
	if(exeatfood==0)
	{
		rx = rand() % M + 1;
		ry = rand() % N + 1;
		exeatfood = 1;
	}
		
			if (headx == rx && heady == ry)
			{
				exeatfood = 0;
				snakke->add(dir);
				if (snakke->getcount() == Maxsize)
				{
					return 3;
				}
			}
			for (int i = 1; i < N + 1; i++)
			{


				for (int j = 1; j < M + 1; j++)
				{
					DGV->Rows[i]->Cells[j]->Style->BackColor = Color::Blue;
				}
			}
			
			DGV->Rows[ry]->Cells[rx]->Style->BackColor = Color::White;
				int error=snakke->move(dir);
				snakke->show_snake(DGV);
				if (error == 0)
				{
					return -1;
				}
				return 0;
						
	}
};

