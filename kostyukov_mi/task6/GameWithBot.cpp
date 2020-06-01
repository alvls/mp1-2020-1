#include <iostream>
#include <time.h>
#include "Player.h"

using namespace std;

int main()
{

    BattleMap battlemap(1,1);
    NetworkEnemy player(battlemap);

    player.createGame("Max");

    clrscr();

    char winner = 0;    

    srand(time(NULL));
    Player player("Player", BattleMap(1,1));
    BotEnemy enemy("Bot", BattleMap(40,1, 1));

    gotoxy(0,25);
    cout << "Arrows - move boat" << endl;
    cout << "Space - rotate boat" << endl;
    cout << "Enter - place boat";
    player.placeBoats();

    clrscr();
    player.getBattlemap().draw();
    enemy.getBattlemap().draw();

    while (true)
    {
        char h = -1;
        pair<int, int> xy;
        do
        {  
            xy = player.move();
            h = enemy.getEnemyMove(xy.first, xy.second);
        }
        while (h < 0);

        enemy.getBattlemap().draw();

        if (h == 2) 
        {
            if (player.boatKilled())
            {
                winner = 1;
                break;
            };
        }

        do
        {  
            xy=enemy.move();
            h = player.getEnemyMove(xy.first, xy.second);
        }
        while (h < 0);

        player.getBattlemap().draw();

        if (h == 2) 
        {
            if (enemy.boatKilled())
            {
                winner = -1;
                break;
            };
        }
    }

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