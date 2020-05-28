#include "Game.h"

#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>


#ifdef __linux
    #include <unistd.h>
#else
    #include <io.h>
#endif

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <sstream>
#include <string>

class Player
{
protected:
    std::string nickname ;
    std::pair<uint, uint> lastMove;
    BattleMap battlemap;
    uint score=0;
public:
    Player(BattleMap _battlemap)
    {
        nickname = "";
        battlemap = _battlemap;
    }
    Player(std::string _nickname, BattleMap _battlemap)
    {
        nickname = _nickname;
        battlemap = _battlemap;
    }
    std::pair<uint, uint> move()
    {
        char x; int y;
        do
        {
            gotoxy(0,25);
            std::cout<<"Your turn(example: a 1):\n";
            std::cin>>x>>y;
        }
        while ((x < 97) || (x > 106) || (y < 1) || (y > 10));
        return std::pair<int,int>(x-97,y-1);
    }
    std::string getNickname()
    {
        return nickname;
    }
    bool boatKilled()
    {
        score++;
        return (score == 10);
    }
    char getEnemyMove(uint x, uint y)
    {
        return battlemap.hit(x,y);
    }
    BattleMap getBattlemap()
    {
        return battlemap;
    }
    void waitForPlayer()
    {
        return;
    }
    void placeBoat(Boat boat)
    {
        char c;
        bool bad = false;
        bool vert = false;
        uint x0 = battlemap.x0;
        uint y0 = battlemap.y0;
        uint x=0,y=0;

        battlemap.draw();

        while (true)
        {
            for(size_t i=0; i<boat.size;i++)
            {
                gotoxy(x0+x*3+3+i*3*vert, y0+y*2+2+i*2*(!vert));
                std::cout<<"[]";
            }
            c = getKey();

            for(size_t i=0; i<boat.size;i++)
            {
                gotoxy(x0+x*3+3+i*3*vert, y0+y*2+2+i*2*(!vert));
                std::cout<<battlemap.cell(x+i*vert, y+i*(!vert));
            }

            switch (c)
            {
            case KB_ARROWLEFT:
                if (x > 0) x--;
                break;
            case KB_ARROWRIGHT:
                if (x < 9-(boat.size-1)*vert) x++;
                break;
            case KB_ARROWUP:
                if (y > 0) y--;
                break;
            case KB_ARROWDOWN:
                if (y < 9-(boat.size-1)*(!vert)) y++;
                break;
            case KB_ENTER:

                bad = false;

                if (vert)
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((x == 0) && (i == 0)) i++;
                        if (x+i == 11) break;
                        if ((y>0) && (battlemap.map[(y-1)*10+x+i-1] > 0)) {bad = 1; break;}
                        if (battlemap.map[y*10+x+i-1] > 0)                {bad = 1; break;}
                        if ((y<9) && (battlemap.map[(y+1)*10+x+i-1] > 0)) {bad = 1; break;}
                    }
                } 
                else
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((y == 0) && (i == 0)) i++;
                        if (y+i == 11) break;
                        if ((x>0) &&(battlemap.map[(y+i-1)*10+x-1] > 0)) {bad = 1; break;}
                        if (battlemap.map[(y+i-1)*10+x] > 0)             {bad = 1; break;}
                        if ((x<9) &&(battlemap.map[(y+i-1)*10+x+1] > 0)) {bad = 1; break;}

                    }
                }

                if (bad) continue;

                boat.x = x;
                boat.y = y;
                boat.horizontal = vert;
                battlemap.boats.push_back(boat);
                if(vert)
                {
                    for(int i=0; i<boat.size; i++)
                    {
                        battlemap.map[y*10+x+i] = battlemap.boats.size();
                    }
                }
                else
                {
                    for(int i=0; i<boat.size; i++)
                    {
                        battlemap.map[(y+i)*10+x] = battlemap.boats.size();
                    }
                }
                battlemap.draw();
                return;

            default:
                if (vert)
                {
                    if (y >= 10-boat.size)
                    {
                        y = 10-boat.size;
                    }
                }       
                else
                {
                    if (x >= 10-boat.size)
                    {
                        x = 10-boat.size;
                    }
                }
                vert = !vert;
                break;
            }
        }
    }
    void placeBoats()
    {
        for (int i=0; i<4; i++)
            placeBoat(Boat(1));
        for (int i=0; i<3; i++)
            placeBoat(Boat(2));
        for (int i=0; i<2; i++)
            placeBoat(Boat(3));
        placeBoat(Boat(4));
    }
};

class BotEnemy:public Player
{
public: 
    BotEnemy(std::string _nickname, BattleMap _battlemap):Player(_nickname, _battlemap)
    {

    }
    std::pair<uint, uint> move()
    {
        int x = rand() % 10;
        int y = rand() % 10;
        return std::pair<int,int>(x,y);
    }
    void placeBoat(Boat boat)
    {
        uint x,y;
        bool vert;
        bool bad = true;
        while (bad)
        {
            vert = rand()%2;
            if (vert)
            {
                x = rand()%(10-boat.size);
                y = rand()%10;
            }
            else
            {
                x = rand()%10;
                y = rand()%(10-boat.size);
            }

            bad = false;

            if (vert)
            {
                for (int i=0;i<boat.size+2; i++)
                {
                    if ((x == 0) && (i == 0)) i++;
                    if (x+i == 11) break;
                    if ((y>0) && (battlemap.map[(y-1)*10+x+i-1] > 0)) {bad = 1; break;}
                    if (battlemap.map[y*10+x+i-1] > 0)                {bad = 1; break;}
                    if ((y<9) && (battlemap.map[(y+1)*10+x+i-1] > 0)) {bad = 1; break;}
                }
            } 
            else
            {
                for (int i=0;i<boat.size+2; i++)
                {
                    if ((y == 0) && (i == 0)) i++;
                    if (y+i == 11) break;
                    if ((x>0) &&(battlemap.map[(y+i-1)*10+x-1] > 0)) {bad = 1; break;}
                    if (battlemap.map[(y+i-1)*10+x] > 0)             {bad = 1; break;}
                    if ((x<9) &&(battlemap.map[(y+i-1)*10+x+1] > 0)) {bad = 1; break;}

                }
            }
        }
        boat.x = x;
        boat.y = y;
        boat.horizontal = vert;
        battlemap.boats.push_back(boat);
        if(vert)
        {
            for(int i=0; i<boat.size; i++)
            {
                battlemap.map[y*10+x+i] = battlemap.boats.size();
            }
        }
        else
        {
            for(int i=0; i<boat.size; i++)
            {
                battlemap.map[(y+i)*10+x] = battlemap.boats.size();
            }
        }
    }
    void placeBoats()
    {
        for (int i=0; i<4;i++)
        {
            placeBoat(Boat(1));
        }
        for (int i=0; i<3;i++)
        {
            placeBoat(Boat(2));
        }
        for (int i=0; i<2;i++)
        {
            placeBoat(Boat(3));
        }
        placeBoat(Boat(4));
        battlemap.draw();
    }

};

class NetworkEnemy:public Player
{
private:
    int PORT = 5000;
    
    struct hostent *server;
    int sockfd;
    int enemysockfd;
    struct sockaddr_in serv_addr, cli_addr;
public:
    bool isServer;
    NetworkEnemy(BattleMap _battlemap):Player(_battlemap)
    {

    }
    bool createGame(std::string playerNick)
    {
        isServer = true;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(PORT);

        if ( bind(sockfd, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) < 0 )
            return 0;

        listen(sockfd, 1);

        socklen_t clilen = sizeof(cli_addr);

        enemysockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        char buffer[256];
        bzero(buffer, 256);

        recv(enemysockfd, buffer, 255, 0);

        std::stringstream request(buffer);
        
        std::string req;
        request >> req;
        if (req == "SeaBattle")
        {
            request >> nickname;
        }
        else
        {
            return 0;
        }
        

        std::string response = "SeaBattle "+playerNick;
        send(enemysockfd, response.c_str(), response.length(), 0);

        return 1;
    }
    bool connectToGame(std::string playerNick, std::string adress)
    {
        isServer = false;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        server = gethostbyname(adress.c_str());
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;

        bcopy((char *)server->h_addr, 
            (char *)&serv_addr.sin_addr.s_addr,
            server->h_length);
        serv_addr.sin_port = htons(PORT);

        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
            return 0;

        enemysockfd = sockfd;

        std::string request = "SeaBattle "+playerNick;

        send(sockfd, request.c_str(), request.length(), 0);
    
        char buffer[256];
        bzero(buffer, 256);
        recv(sockfd, buffer, 255, 0);

        std::stringstream response(buffer);
        std::string r;
        response >> r;
        if (r == "SeaBattle")
            response >> nickname;
        else
        {
            return 0;
        }
        
        return 1;
    }
    void waitForPlayer()
    {
        char buffer[256];
        do
        {
            do
            {
                bzero(buffer, 256);
            }
            while (!recv(enemysockfd, buffer, 255, 0));

        }while(std::string(buffer) != "SeaBattle move");

    }
    std::pair<int, int> move()
    {
        char buffer[256];

        send(enemysockfd, "SeaBattle move", 14, 0);

        do
        {
            bzero(buffer, 256);
        }
        while (!recv(enemysockfd, buffer, 255, 0));

        std::stringstream response(buffer);

        int x;
        int y;

        std::string r;
        response >> r;

        if (r == "SeaBattle")
            response >> x >> y;

        return std::pair<int, int>(x,y);
    }
    void sendMoveResult(char res, uint x=0, uint y=0)
    {
        std::stringstream request;
        request << "SeaBattle " << res;
        if (res != 0 && res != 1)
        {
            request << " " << x << " " << y;
        }
        send(enemysockfd, request.str().c_str(), request.str().length(), 0);
    }
    char getEnemyMove(int x, int y)
    {
        if (battlemap.map[y*10+x] < 0)
            return battlemap.map[y*10+x];

        std::stringstream request;
        request << "SeaBattle " << x << " " << y;
        send(enemysockfd, request.str().c_str(), request.str().length(), 0);

        char buffer[256];

        do
        {
            bzero(buffer, 256);
        }
        while (!recv(enemysockfd, buffer, 255, 0));

        std::stringstream response(buffer);

        std::string r;
        char res;

        response >> r;

        if (r == "SeaBattle")
            response >> res;
        
        gotoxy(0,40);
        std::cout<<res;

        if (res == 0)
        {
            battlemap.map[y*10 + x] = -1;
            return 0;
        }
        if (res == 1)
        {
            battlemap.map[y*10 + x] = -2;
        }
        else
        {
            response >> x >> y;
            bool vert = 0;
            if (res < 0){vert = 1; res = (-1)*res;}
            res-=1;
            battlemap.map[y*10 + x] = -2;
            battlemap.boatKilled(x, y, res, vert);
        }
        return res;
    }
    ~NetworkEnemy()
    {
        close(sockfd);
        close(enemysockfd);    
    }
};