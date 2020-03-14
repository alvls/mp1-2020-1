#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class matrix
{
private:
int a;
int b;
int* qq;
public:
matrix() { a = b = 1; qq = new int[1]; }
~matrix() { delete[] qq; }

void set_len(int _a, int _b)
{
a = _a;
b = _b;
delete[] qq;
qq = new int[a * b];
}

void len()
{
cout << a << '*' << b << endl;

}

void set_num(int _a, int _b, int num)
{
qq[(_a-1)*b + _b - 1] = num;
}

int check_num(int _a, int _b)
{
return qq[(_a-1)*b + _b - 1];
}

void check_diag()
{
int i;
int j;
int num1;
int num2;
int flag = 0;
for (i = 0; i < a; i++)
{
num1 = qq[(i-1)*b + i];
for (j = 0; j < b; j++)
num2 = num2 + qq[(j - 1)*b + j];
num2 = num2 - num1;
if (num2 > num1) flag = 1;
}
if (flag = 0) cout << "It`s a diagonally dominant matrix"  << endl;
else cout << "It is not a diagonally dominant matrix" << endl;
}

int checkA()
{
return a;
}
int checkB()
{
return b;
}
matrix sum(const matrix &m2)
{
int i;
matrix result;
result.set_len(a, b);
for (i = 0; i < a*b; i++)
result.qq[i] = this->qq[i]+m2.qq[i];
return result;
}

matrix operator=(const matrix &m3)
{
a = m3.a;
b = m3.b;
delete[] qq;
qq = new int[a*b];
for (int i = 0; i < a*b; i++)
qq[i] = m3.qq[i];
return (*this);
}

};

int main()
{
    cout << "Select function" << endl;
    cout << "1)Set length(a, b)" << endl;
    cout << "2)Show length" << endl;
    cout << "3)Set a number on place(a, b, num)" << endl;
    cout << "4)Check a number on place(a, b)" << endl;
    cout << "5)Check for a diagonally dominant matrix" << endl;
    cout << "6)Show a sum of matrix 1 and matrix 2 on matrix 3" << endl;
    int sw, matr;
    int a, b, num;
    matrix m1;
    matrix m2;
    matrix m3;
    while (true)
    {
    cin >> sw;
    switch (sw)
    {
    case 1:
    cout << "Set a, b, matrix 1/2" << endl;
    cin >> a >> b >> matr;
    switch (matr)
    {
    case 1:
    m1.set_len(a, b);
    break;
    case 2:
    m2.set_len(a, b);
    break;
    }
    break;

    case 2:
    cout << "Set matrix 1/2" << endl;
    cin >> matr;
    switch (matr)
    {
    case 1:
    m1.len();
    break;
    case 2:
    m2.len();
    break;
    }
    break;

    case 3:
    cout << "Set a, b, num, matrix 1/2" << endl;
    cin >> a >> b >> num >> matr;
    switch (matr)
    {
    case 1:
    m1.set_num(a, b, num);
    break;
    case 2:
    m2.set_num(a, b, num);
    break;
    }
    break;

    case 4:
    cout << "Set a, b, matrix 1/2/3" << endl;
    cin >> a >> b >> matr;
    switch (matr)
    {
    case 1:
    cout << m1.check_num(a, b) << endl;
    break;
    case 2:
    cout << m2.check_num(a, b) << endl;
    break;
    case 3:
    cout << m3.check_num(a, b) << endl;
    break;
    }
    break;

    case 5:
    cout << "Set matrix 1/2/3" << endl;
    cin >> matr;
    switch (matr)
    {
    case 1:
    m1.check_diag();
    break;
    case 2:
    m2.check_diag();
    break;
    }
    break;

    case 6:
    // m3.set_len(m1.checkA(), m1.checkB());
    m3.set_len(1, 1);
    m3 = m1.sum(m2);
    break;
    }
    cout << "End? Y/N" << endl;
    char conf;
    getchar();
    conf = getchar();
    if ((conf == 'Y') || (conf == 'y'))
    break;
    }
    return 1;
}


// int main()
// {
//     matrix m1;
//     matrix m2;
//     m1.set_len(1,1);
//     m2.set_len(1,1);
//     m1.set_num(1,1,1);
//     m2.set_num(1,1,2);
//     matrix m3;
//     m3 = m1.sum(m2);
//     cout << m3.check_num(1,1) << endl;
// }