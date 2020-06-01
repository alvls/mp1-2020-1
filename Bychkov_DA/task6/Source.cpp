#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
class Field
{ 
public:
	short** cell;
	Field()
	{
		cell = new short* [10];
		for (int i = 0; i < 10; i++)
		{
			cell[i] = new short[10];
			for (int k = 0; k < 10; k++)
			{
				cell[i][k] = 0;
			}
		}
	}
	bool Fill(short x, short y)
	{
		if ((x > 9) || (y > 9) || (x < 0) || (y < 0))
		{
			return false;
		}
			if (cell[x][y] == 0)
			{
				if ((x == 0) &&(y == 0))
				{
					cell[x][y] = 1;
					cell[x + 1][y] = 2;
					cell[x + 1][y + 1] = 2;
					cell[x][y + 1] = 2;
				}
				else if ((x == 9) && (y == 0))
				{
					cell[x][y] = 1;
					cell[x - 1][y] = 2;
					cell[x - 1][y + 1] = 2;
					cell[x][y + 1] = 2;
				}
				else if ((x == 9) && (y == 9))
				{
					cell[x][y] = 1;
					cell[x - 1][y] = 2;
					cell[x - 1][y - 1] = 2;
					cell[x][y - 1] = 2;
				}
				else if ((x == 0) && (y == 9))
				{
					cell[x][y] = 1;
					cell[x + 1][y] = 2;
					cell[x + 1][y - 1] = 2;
					cell[x][y - 1] = 2;
				}
				else if (x == 0) //left
				{
					cell[x][y] = 1;
					cell[x + 1][y] = 2;
					cell[x + 1][y - 1] = 2;
					cell[x][y - 1] = 2;
					cell[x + 1][y + 1] = 2;
					cell[x][y + 1] = 2;
				}
				else if (y == 0)  //up
				{
					cell[x][y] = 1;
					cell[x - 1][y] = 2;
					cell[x - 1][y + 1] = 2;
					cell[x][y + 1] = 2;
					cell[x + 1][y + 1] = 2;
					cell[x + 1][y] = 2;
				}
				else if (x == 9)  //right
				{
					cell[x][y] = 1;
					cell[x - 1][y] = 2;
					cell[x - 1][y - 1] = 2;
					cell[x][y - 1] = 2;
					cell[x][y + 1] = 2;
					cell[x - 1][y + 1] = 2;
				}
				else if (y == 9)  //down
				{
					cell[x][y] = 1;
					cell[x - 1][y] = 2;
					cell[x - 1][y - 1] = 2;
					cell[x][y - 1] = 2;
					cell[x + 1][y - 1] = 2;
					cell[x + 1][y] = 2;
				}
				else
				{
					cell[x][y] = 1;
					cell[x + 1][y] = 2;
					cell[x + 1][y + 1] = 2;
					cell[x][y + 1] = 2;
					cell[x + 1][y - 1] = 2;
					cell[x][y - 1] = 2;
					cell[x - 1][y - 1] = 2;
					cell[x - 1][y] = 2;
					cell[x - 1][y + 1] = 2;
				}
				return true;
			}
			else
			{
				return false;
			}
	}
	bool FillDouble(short x, short y, short direction)
	{
		if ((x > 9) || (y > 9) || (x < 0) || (y < 0))
		{
			return false;
		}
			switch (direction)
			{
			case 1:
				if ((y == 0) || (cell[x][y - 1] == 2) || (cell[x][y] == 2))
				{
					return false;
				}
				else
				{
					Fill(x, y);
					cell[x][y - 1] = 0;
					Fill(x, y - 1);
					cell[x][y] = 1;
					return true;
				}
				break;
			case 2:
					if ((x == 9) || (cell[x + 1][y] == 2)||(cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						Fill(x, y);
						cell[x + 1][y] = 0;
						Fill(x + 1, y);
						cell[x][y] = 1;
						return true;
					}
				break;
			case 3:
					if ((y == 9) || (cell[x][y + 1] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						Fill(x, y);
						cell[x][y + 1] = 0;
						Fill(x, y + 1);
						cell[x][y] = 1;
						return true;
					}
				break;
			case 4:
					if ((x == 0) || (cell[x - 1][y] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						Fill(x, y);
						cell[x - 1][y] = 0;
						Fill(x - 1, y);
						cell[x][y] = 1;
						return true;
					}
				break;
			}
	}
	bool FillTriple(short x, short y, short direction)
	{
			if ((x > 9) || (y > 9) || (x < 0) || (y < 0))
			{
				return false;
			}
			switch (direction)
			{
			case 1:
					if ((y <= 1) || (cell[x][y - 1] == 2) || (cell[x][y - 2] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						FillDouble(x, y, 1);
						cell[x][y - 2] = 0;
						Fill(x, y - 2);
						cell[x][y - 1] = 1;
						return true;
					}
				break;
			case 2:				
					if ((x >= 8) || (cell[x + 1][y] == 2) || (cell[x + 2][y] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						FillDouble(x, y, 2);
						cell[x + 2][y] = 0;
						Fill(x + 2, y);
						cell[x + 1][y] = 1;
						return true;
					}
				break;
			case 3:				
					if ((y >= 8) || (cell[x][y + 1] == 2) || (cell[x][y + 2] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						FillDouble(x, y, 3);
						cell[x][y + 2] = 0;
						Fill(x, y + 2);
						cell[x][y + 1] = 1;
						return true;
					}
				break;
			case 4:
					if ((x <= 1) || (cell[x - 1][y] == 2) || (cell[x - 2][y] == 2) || (cell[x][y] == 2))
					{
						return false;
					}
					else
					{
						FillDouble(x, y, 4);
						cell[x - 2][y] = 0;
						Fill(x - 2, y);
						cell[x - 1][y] = 1;
						return true;
					}
				break;
			}
	}
	bool FillQuad(short x, short y, short direction)
	{
			if ((x > 9) || (y > 9) || (x < 0) || (y < 0))
			{
				return false;
			}
			switch (direction)
			{
			case 1:
				if ((y <= 2) || (cell[x][y - 1] == 2) || (cell[x][y - 2] == 2) || (cell[x][y - 3] == 2) || (cell[x][y] == 2))
				{
					return false;
				}
				else
				{
					FillTriple(x, y, 1);
					cell[x][y - 3] = 0;
					Fill(x, y - 3);
					cell[x][y - 2] = 1;
					return true;
				}
				break;
			case 2:
				if ((x >= 7) || (cell[x + 1][y] == 2) || (cell[x + 2][y] == 2) || (cell[x + 3][y] == 2) || (cell[x][y] == 2))
				{
					return false;
				}
				else
				{
					FillTriple(x, y, 2);
					cell[x + 3][y] = 0;
					Fill(x + 3, y);
					cell[x + 2][y] = 1;
					return true;
				}
				break;
			case 3:
				if ((y >= 7) || (cell[x][y + 1] == 2) || (cell[x][y + 2] == 2) || (cell[x][y + 3] == 2) || (cell[x][y] == 2))
				{
					return false;
				}
				else
				{
					FillTriple(x, y, 3);
					cell[x][y + 3] = 0;
					Fill(x, y + 3);
					cell[x][y + 2] = 1;
					return true;
				}
				break;
			case 4:
				if ((x <= 2) || (cell[x - 1][y] == 2) || (cell[x - 2][y] == 2) || (cell[x - 3][y] == 2) || (cell[x][y] == 2))
				{
					return false;
				}
				else
				{
					FillTriple(x, y, 4);
					cell[x - 3][y] = 0;
					Fill(x - 3, y);
					cell[x - 2][y] = 1;
					return true;
				}
				break;
			}
	}
	void Draw()
	{
		cout << "    0     1     2     3     4     5     6     7     8     9   x" << endl;
			for (int j = 0; j < 10; j++)
			{
				cout << j << "   ";
				for (int i = 0; i < 10; i++)
				{
					if (cell[i][j] == 0) cout << "_  ";
					else if (cell[i][j] == 1) cout << "o  ";
					else if (cell[i][j] == 2) cout << "s  ";
					else if (cell[i][j] == 3) cout << "m  ";
					else if (cell[i][j] == 4) cout << "x  ";
					cout << "   ";
				}
				cout << endl;
			}
			cout << "y"<<endl;
	}
	~Field()
	{
		for (int i = 0; i < 10; i++)
		{
			delete[] cell[i];
		}
	}
};
class seafight
{
private:
	Field playerfield1;
	Field playerfield2;
	Field enemyfield1;
	bool turn; // true - player, false - enemy
	bool end;// true - end
	short coord_x;
	short coord_y;
	short dir;
	void Clear()
	{
		system("cls");
	}
	void FillPlayer() 
	{
		Clear();
		playerfield1.Draw();
		cout << "Enter coords of first singledeck" << endl;
		cin >> coord_x >> coord_y;
		while (playerfield1.Fill(coord_x, coord_y) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords of second singledeck" << endl;
		cin >> coord_x >> coord_y;
		while (playerfield1.Fill(coord_x, coord_y) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords of third singledeck" << endl;
		cin >> coord_x >> coord_y;
		while (playerfield1.Fill(coord_x, coord_y) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords of fourth singledeck" << endl;
		cin >> coord_x >> coord_y;
		while (playerfield1.Fill(coord_x, coord_y) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of first doubledeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of second doubledeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of third doubledeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of first tripledeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillTriple(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of second tripledeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillTriple(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
		cout << "Enter coords and direction(1-up,2-right,3-down,4-left) of quaddeck" << endl;
		cin >> coord_x >> coord_y >> dir;
		while (playerfield1.FillQuad(coord_x, coord_y, dir) == false)
		{
			cout << "wrong input try again" << endl;
			cin >> coord_x >> coord_y >> dir;
		};
		Clear();
		playerfield1.Draw();
	};
	void FillEnemy()
	{
		coord_x = rand() % 10;
		coord_y = rand() % 10;

		while (enemyfield1.Fill(coord_x, coord_y) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		while (enemyfield1.Fill(coord_x, coord_y) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		while (enemyfield1.Fill(coord_x, coord_y) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		while (enemyfield1.Fill(coord_x, coord_y) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillDouble(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillTriple(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillTriple(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
		coord_x = rand() % 10;
		coord_y = rand() % 10;
		dir = rand() % 5;
		while (enemyfield1.FillQuad(coord_x, coord_y, dir) == false)
		{
			coord_x = rand() % 10;
			coord_y = rand() % 10;
			dir = rand() % 5;
		};
	};
	short GetPlayerDecks()
	{
		short playerdecks = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (playerfield1.cell[i][j] == 1) playerdecks++;
			}
		}
		return playerdecks;
	}
	short GetEnemyDecks()
	{
		short enemydecks=0;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (enemyfield1.cell[i][j] == 1) enemydecks++;
			}
		}
		return enemydecks;
	}
public:
	seafight()
	{
		FillPlayer();
		FillEnemy();
		Clear();
		while (end != true)
		{
			cout << "your field" << endl;
			playerfield1.Draw();
			cout << endl << endl << endl;
			cout << "enemy field" << endl;
			playerfield2.Draw();
			bool tmp[100];
				for (int k = 0; k < 100; k++)
				{
					tmp[k] = false;
				}
			while (turn == true)
			{
				cout << "where are we going to shoot?"<<endl;
				cin >> coord_x >> coord_y;
				if (enemyfield1.cell[coord_x][coord_y] == 1)
				{
					cout << "hit"<<endl;
					system("pause");
					playerfield2.cell[coord_x][coord_y] = 4;
					Clear();
					cout << "your field" << endl;
					playerfield1.Draw();
					cout << endl << endl << endl;
					cout << "enemy field" << endl;
					playerfield2.Draw();
					if (GetPlayerDecks() == 0)
					{
						cout << "congratulations"; 
						end = true;
					}
				} 
				else 
				{
					cout << "miss"<<endl;
					system("pause");
					playerfield2.cell[coord_x][coord_y] = 3;
					Clear();
					cout << "your field" << endl;
					playerfield1.Draw();
					cout << endl << endl << endl;
					cout << "enemy field" << endl;
					playerfield2.Draw();
					turn = false;
				}
			}
			while (turn == false)
			{
				bool stop = false;
				while (stop == false)
				{
					coord_x = rand() % 10;
					coord_y = rand() % 10;
					if (tmp[coord_x*10 + coord_y] == false)
					{
						if (playerfield1.cell[coord_x][coord_y] == 1)
						{
							playerfield1.cell[coord_x][coord_y] = 4;
							if (GetPlayerDecks() == 0) 
							{
								cout << "Hmm...";
								end = true;
							}
						}
						else
						{
							playerfield1.cell[coord_x][coord_y] = 3;
							turn = true;
						}
						tmp[coord_x * 10 + coord_y] = true;
						stop = true;
					}
				}
				Clear();
				cout << "your field" << endl;
				playerfield1.Draw();
				cout << endl << endl << endl;
				cout << "enemy field" << endl;
				playerfield2.Draw();
			}
		}
	}
};
void main()//game ends when one of the players has no decks left
{
	seafight aasdas;
	system("pause");
}