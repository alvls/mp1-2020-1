#include <iostream>
#include <time.h>
#include "Player.h"

using namespace std;

int main()
{
    clrscr();
    BattleMap battlemap1(1,1);
    BattleMap battlemap2(40,1);

    Player player(battlemap1);
    NetworkEnemy enemy(battlemap2);
    int n;
    string nickname;

    cout << "1) Create game" << endl;
    cout << "2) Connect game" << endl;
    cin >> n;
    cout << "Your nickname: ";
    cin >> nickname;



    switch (n)
    {
    case 1:

        if (!enemy.createGame(nickname))
        {
            cout << "Error\n";
            return 0;
        }
        break;
    case 2:
        string ip;
        cout << "IP adress: ";
        cin >> ip;
        if (!enemy.connectToGame(nickname, ip))
        {
            cout << "Error\n";
            return 0;
        }
        break;
    }

    clrscr();
    getch();

    gotoxy(0,25);
    cout << "Arrows - move boat" << endl;
    cout << "Space - rotate boat" << endl;
    cout << "Enter - place boat";

    player.placeBoats();

    pair<int,int> xy;
    pair<int,int> boatxy;
    char h;
    char winner;

    clrscr();

    player.getBattlemap().draw();
    enemy.getBattlemap().draw();

    if (enemy.isServer)
    {
        do
        {
            enemy.waitForPlayer();
            do
            {
                xy = player.move();
                h = enemy.getEnemyMove(xy.first, xy.second);
                clrscr();
                player.getBattlemap().draw();
                enemy.getBattlemap().draw();
            }while(h < 0);

            if (h!=1 && h!=0)
            {
                if(player.boatKilled())
                {
                    winner = 1;
                    break;
                }
            }
            gotoxy(0,25);
            std::cout<< enemy.getNickname() <<"'s turn\n";
            xy = enemy.move();
            boatxy = player.getBattlemap().getBoatCoords(xy.first, xy.second);
            h = player.getEnemyMove(xy.first, xy.second);

            if (h!=1 && h!=0)
            {
                if(enemy.boatKilled())
                {
                    winner = -1;
                    break;
                }
                enemy.sendMoveResult(h, boatxy.first, boatxy.second);
            }
            else
            {
                enemy.sendMoveResult(h);
            }
            player.getBattlemap().draw();
        }while(true);
    }
    else
    {
        do
        {
            gotoxy(0,25);
            std::cout<< enemy.getNickname() <<"'s turn\n";
            xy = enemy.move();
            boatxy = player.getBattlemap().getBoatCoords(xy.first, xy.second);
            h = player.getEnemyMove(xy.first, xy.second);

            if (h!=1 && h!=0)
            {
                if(enemy.boatKilled())
                {
                    winner = -1;
                    break;
                }
                enemy.sendMoveResult(h, boatxy.first, boatxy.second);
            }
            else
            {
                enemy.sendMoveResult(h);
            }
            player.getBattlemap().draw();
            enemy.waitForPlayer();
            do
            {
                xy = player.move();
                h = enemy.getEnemyMove(xy.first, xy.second);
                clrscr();
                player.getBattlemap().draw();
                enemy.getBattlemap().draw();
            }while(h < 0);

            if (h!=1 && h!=0)
            {
                if(player.boatKilled())
                {
                    winner = 1;
                    break;
                }
            }
        }while(true);
    }

    clrscr();

    if (winner == 1)
    {
        gotoxy(0, 30);
        cout <<player.getNickname() << "wins!";
    }
    if (winner == -1)
    {
        gotoxy(0, 30);
        cout << enemy.getNickname() << "wins!";
    }
    
}