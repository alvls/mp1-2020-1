#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
enum CellState { Empty, Miss, Deck, HitDeck, No};//—осто€ни€ клетки
class Cell
{
private:
	int x;
	int y;
    CellState state;
public:
	Cell(int _x = 0, int _y = 0, CellState _state = Empty) : x(_x), y(_y), state(_state) {}
	int Setx(int _x)
	{
		x = _x;
	}
	int Getx()
	{
		return x;
	}
	int Sety(int _y)
	{
		x = _y;
	}
	int Gety()
	{
		return y;
	}
	void SetState(CellState _state)
	{
		state = _state;
	}
	CellState GetState()
	{
		return state;
	}
	void Print()
	{
		if (state == Empty)
			cout << ' ';
		else if (state == HitDeck)
			cout << 'x';
		else if (state == Deck)
			cout << 'd';
		else
			cout << '*';
	}
};
class GameBoard
{
private:
	static const int _size = 10;
	Cell cells[_size][_size];// поле игрока
	Cell cells1[_size][_size];// поле кораблей бота
	Cell cells2[_size][_size];// поле дл€ контрол€ выстрелов бота
	Cell cells3[_size][_size];// поле бота высвечивающеес€ игроку
	int sizeShip;
	int Ship1 = 0;
	int Ship2 = 0;
	int Ship3 = 0;
	int Ship4 = 0;
public:
	GameBoard() {}
	void Generate() //«аполнение всех клеток наименованием пусто 
	{
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
				cells[i][j].SetState(Empty);
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
				cells2[i][j].SetState(Empty);
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
				cells1[i][j].SetState(Empty);
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
				cells3[i][j].SetState(Empty);
	}
	void CreatorShipPlayer(int _sizeShip,int _y,int _x,bool horizontal)
	{
		sizeShip = _sizeShip;
		while ((Ship1 < 5) && (Ship2 < 4) && (Ship3 < 3) && (Ship4 < 2))
		{
			if (sizeShip == 1)
				Ship1++;
			if (sizeShip == 2)
				Ship2++;
			if (sizeShip == 3)
				Ship3++;
			if (sizeShip == 4)
				Ship4++;
			for (int i = 0; i < sizeShip; i++)
			{
				if (horizontal)
					cells[_y][_x + i].SetState(Deck);
				else
					cells[_y + i][_x].SetState(Deck);
			}
			break;
		}
	}
	void ShootPlayer(int _y, int _x)
	{
		CellState p = cells1[_y][_x].GetState();
		if (p == Empty)
			cells3[_y][_x].SetState(Miss);
		else
			cells3[_y][_x].SetState(HitDeck);
	}
	bool GameEnd()
	{
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
			{
				CellState p = cells1[i][j].GetState();
				if (p == Deck)
					return false;
			}
		return true;
	}
	void CreatorShipIi()
	{
		srand(time(NULL));
		int x, y, sizeShip;
		int gorizontal;
		int count1 = 0;
		int size1 = 4;
		int size2 = 3;
		int size3 = 2;
		int size4 = 1;
		while (count1 < 10)// ѕока кол-во кораблей не 10, он их создает
		{
			if (size4 == 1)
			{

				gorizontal = rand() % (1 - 0) + 0;
				switch (gorizontal)
				{
				case 0://¬ертикальный 4-х палубник(vertik)
					sizeShip = 4;
					y = rand() % (6 - 0) + 0;
					x = rand() % (9 - 0) + 0;
					for (int i = 0; i < sizeShip; i++)
						cells1[y + i][x].SetState(Deck);
					count1++;
					size4--;
					if (x > 0)
						for (int i = 0; i < 4; i++)
							cells1[y + i][x - 1].SetState(No);
					if (x < 9)
						for (int i = 0; i < 4; i++)
							cells1[y + i][x + 1].SetState(No);
					for (int i = 0; i < 3; i++)
					{
						if (y > 0)
							if ((x > 0) && (x < 11))
								cells1[y - 1][x - 1].SetState(No);
						if (y < 6)
							if ((x > 0) && (x < 11))

								cells1[y + 4][x - 1].SetState(No);
						x++;
					}
					break;
				case 1: // √оризонтальный 4-ч палубник (Gorizont)
					sizeShip = 4;
					y = rand() % (9 - 0) + 0;
					x = rand() % (6 - 0) + 0;
					for (int i = 0; i < sizeShip; i++)
						cells1[y][x + i].SetState(Deck);
					count1++;
					size4--;
					if (y > 0)
						for (int i = 0; i < 4; i++)
							cells1[y - 1][x + i].SetState(No);
					if (y < 9)
						for (int i = 0; i < 4; i++)
							cells1[y + 1][x + i].SetState(No);
					for (int i = 0; i < 3; i++)
					{
						if (x > 0)
							if ((y > 0) && (y < 11))
								cells1[y - 1][x - 1].SetState(No);
						if (x < 6)
							if ((y > 0) && (y < 11))
								cells1[y - 1][x + 4].SetState(No);
						y++;
					}
					break;
				}
			}
			bool flag, flag1;
			int count = 0;
			if ((size3 < 3) && (size3 > 0))
			{// “еперь 3-х палубники
				flag = false;
				flag1 = true;
				do
				{
					gorizontal = rand() % (1 - 0) + 0;
					switch (gorizontal)
					{
					case 0: // ¬ертикальный(vertik)
						sizeShip = 3;
						do
						{
							do
							{
								x = rand() % (9 - 0) + 0;
								y = rand() % (7 - 0) + 0;
							} while ((cells1[y][x].GetState() == Deck) || (cells1[y][x].GetState() == No));// проверка свободна ли клетка
							for (int i = 0; i < 3;)// проверка на возможность установки корабл€
								if (cells1[y + i][x].GetState() != No)
									i++;
								else
									flag1 = false;
						} while (flag1 == false);
						if (flag1 == true)
						{
							for (int i = 0; i < sizeShip; i++)
								cells1[y + i][x].SetState(Deck);
							count1++;
							size3--;
							if (x > 0)
								for (int i = 0; i < 3; i++)
									cells1[y + i][x - 1].SetState(No);
							if (x < 9)
								for (int i = 0; i < 3; i++)
									cells1[y + i][x + 1].SetState(No);
							for (int i = 0; i < 3; i++)
							{
								if (y > 0)
									if ((x > 0) && (x < 11))
										cells1[y - 1][x - 1].SetState(No);
								if (y < 7)
									if ((x > 0) && (x < 11))
										cells1[y + 3][x - 1].SetState(No);
								x++;
							}
							count++;
						}
						break;
					case 1:// √оризонтальный (Gorizont)
						sizeShip = 3;
						do
						{
							do
							{
								x = rand() % (7 - 0) + 0;
								y = rand() % (9 - 0) + 0;
							} while ((cells1[y][x].GetState() == Deck) || (cells1[y][x].GetState() == No));
							for (int i = 0; i < 3;)
								if (cells1[y][x + i].GetState() != No)
									i++;
								else
									flag1 = false;
						} 
						while (flag1 == false);
						if (flag1 == true)
						{
							for (int i = 0; i < sizeShip; i++)
								cells1[y][x + i].SetState(Deck);
							count1++;
							size3--;
							if (y > 0)
								for (int i = 0; i < 3; i++)
									cells1[y - 1][x + i].SetState(No);
							if (y < 9)
								for (int i = 0; i < 3; i++)
									cells1[y + 1][x + i].SetState(No);
							for (int i = 0; i < 3; i++)
							{
								if (x > 0)
									if ((y > 0) && (y < 11))

										cells1[y - 1][x - 1].SetState(No);
								if (x < 7)
									if ((y > 0) && (y < 11))

										cells1[y - 1][x + 3].SetState(No);
								y++;
							}
							count++;
						}
						break;
					}
				} while (count != 2);
			}
			count = 0;
			if ((size2 < 4) && (size2 > 0)) // “еперь 2-х палубники
			{
				flag = false;
				flag1 = true;
				do
				{
					gorizontal = rand() % (1 - 0) + 0;
					switch (gorizontal)
					{
					case 0: // ¬ертикальный (Vert)
						sizeShip = 2;
						do {
							do
							{
								x = rand() % (9 - 0) + 0;
								y = rand() % (8 - 0) + 0;
							} while ((cells1[y][x].GetState() == Deck) || (cells1[y][x].GetState() == No));
							if (cells1[y + 1][x].GetState() != No)
								flag1 = true;
							else
								flag1 = false;

						} while (flag1 == false);
							for (int i = 0; i < sizeShip; i++)
								cells1[y + i][x].SetState(Deck);
							count1++;
							size2--;
							if (x > 0)
								for (int i = 0; i < 2; i++)
									cells1[y + i][x - 1].SetState(No);
							if (x < 9)
								for (int i = 0; i < 2; i++)
									cells1[y + i][x + 1].SetState(No);
							for (int i = 0; i < 3; i++)
							{
								if (y > 0)
									if ((x > 0) && (x < 11))

										cells1[y - 1][x - 1].SetState(No);
								if (y < 8)
									if ((x > 0) && (x < 11))

										cells1[y + 2][x - 1].SetState(No);
								x++;
							}
							count++;
						break;
					case 1:// √оризонтальный (Gor)
						sizeShip = 2;
						do
						{
							do
							{
								x = rand() % (8 - 0) + 0;
								y = rand() % (9 - 0) + 0;
							} while ((cells1[y][x].GetState() == Deck) || (cells1[y][x].GetState() == No));
							if (cells1[y][x + 1].GetState() != No)
								flag1 = true;
							else
								flag1 = false;
						} while (flag1 == false);
						if (flag1 == true)
						{
							for (int i = 0; i < sizeShip; i++)
								cells1[y][x + i].SetState(Deck);
							count1++;
							size2--;
							if (y > 0)
								for (int i = 0; i < 2; i++)
									cells1[y - 1][x + i].SetState(No);
							if (y < 9)
								for (int i = 0; i < 2; i++)
									cells1[y + 1][x + i].SetState(No);
							for (int i = 0; i < 3; i++)
							{
								if (x > 0)
									if ((y > 0) && (y < 11))
										cells1[y - 1][x - 1].SetState(No);
								if (x < 8)
									if ((y > 0) && (y < 11))
										cells1[y - 1][x + 2].SetState(No);
								y++;
							}
							count++;
						}
						break;
					}

				} while (count != 3);
			}
			if ((size1 < 5) && (size1 > 0))
			{
				flag = false;
				do
				{
						sizeShip = 1;
						do
						{
							x = rand() % (9 - 0) + 0;
							y = rand() % (9 - 0) + 0;
						} while ((cells1[y][x].GetState() == Deck) || (cells1[y][x].GetState() == No));// проверка свободна ли клетка
						for (int i = 0; i < sizeShip; i++)
							cells1[y + i][x].SetState(Deck);
						count1++;
						size1--;
						if (y > 0)
								cells1[y - 1][x].SetState(No);
						if (y < 9)
								cells1[y + 1][x].SetState(No);
						for (int i = 0; i < 3; i++)
						{
							if (x > 0)
								if ((y > 0) && (y < 11))
									cells1[y - 1][x - 1].SetState(No);
							if (x < 9)
								if ((y > 0) && (y < 11))
									cells1[y - 1][x + 1].SetState(No);
							y++;
						}
					if (size1 == 0)
						flag = true;
				} while (flag == false);
			}
		}
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
				if (cells1[i][j].GetState() == No)
					cells1[i][j].SetState(Empty);
	}
	void ShootIi()
	{
		int x, y;
		bool flag = false;
		x = rand() % (9 - 0) + 0;
		y = rand() % (9 - 0) + 0;
		do
		{
			if (cells2[y][x].GetState() != No)
			{
				cells2[y][x].SetState(No);
				if (cells[y][x].GetState() == Empty)
					cells[y][x].SetState(Miss);
				if (cells[y][x].GetState() == Deck)
					cells[y][x].SetState(HitDeck);
				flag = true;
			}
		} while (flag == false);
	}
	void ShowBoard()
	{
		cout << "       0 1 2 3 4 5 6 7 8 9                  0 1 2 3 4 5 6 7 8 9" << endl;
		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i << "     "<< "|";
			for (int j = 0; j < 10; j++)
			{
				cells[i][j].Print();
				cout << "|";
			}
			cout << "          ";
			cout << i << "     " << "|";
			for (int j = 0; j < 10; j++)
			{
				cells3[i][j].Print();
				cout << "|";
			}
			cout << endl;
		}
	}
};
void main()
{
	GameBoard Board;
	int count = 0, size, x, y;
	bool hor;
	while (count < 10)
	{
		cout << "vvedite razmer" << endl;
		cin >> size;
		cout << "vvedite x" << endl;
		cin >> x;
		cout << "vvedite y" << endl;
		cin >> y;
		cout << "vvedite hor" << endl;
		cin >> hor;
		Board.CreatorShipPlayer(size,y,x,hor);
		count++;
	}
	Board.CreatorShipIi();
	Board.ShowBoard();
	do
	{
		cout << "Enter x coord: " << endl;
		int x;
		cin >> x;
		cout << "Enter y coord: " << endl;
		int y;
		cin >> y;
		Board.ShootPlayer(y, x);
		Board.ShootIi();
		system("cls");
		Board.ShowBoard();
	} while (!Board.GameEnd());
	system("pause");
}