#include <termios.h>
#include <stdio.h>

enum Colors
{
    RED = 41,
    BLACK = 0
};

enum KB
{
    KB_DEFAULT,
    KB_ENTER,
    KB_ESC,
    KB_ARROWUP,
    KB_ARROWDOWN,
    KB_ARROWLEFT,
    KB_ARROWRIGHT
};

static struct termios old_, new_;

void initTermios(int echo) 
{
    tcgetattr(0, &old_);
    new_ = old_;
    new_.c_lflag &= ~ICANON;
    new_.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new_);
}
 
void resetTermios(void) 
{
    tcsetattr(0, TCSANOW, &old_);
}

char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char getch()
{
    return getch_(0);
}

char getKey()
{
    char ch;
    ch = getch();
    if (ch == 10) return KB_ENTER;
    if (ch != 27) return KB_DEFAULT;
    ch = getch();
    if (ch != 91) return KB_DEFAULT;
    ch = getch();
    
    switch (ch)
    {
        case 65:
            return KB_ARROWUP;
        case 66:
            return KB_ARROWDOWN;
        case 67:
            return KB_ARROWRIGHT;
        case 68: //grab old terminal i/o settings_ARROWLEFT;
        default:
            return KB_DEFAULT;
    }   
}

void gotoxy(size_t x, size_t y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void clrscr()
{
    system("clear");
}

void textbackground(int color)
{
    std::cout << "\033[0;" << color << "m";
}