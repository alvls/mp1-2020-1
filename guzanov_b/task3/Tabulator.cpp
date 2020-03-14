
#pragma once
#include "Tab.h"
int main()
{
    setlocale(LC_ALL, "Russian");

    Tab A(12, 1);
    cout << "A:" << endl;
    cout << "Количество точек табулирования p = " << A.getp() << endl;
    cout << "Отрезок табулирования sec = " << A.getsec() << endl;
    Tab B(17, 1);
    cout << "A = B" << endl;
    A = B;
    cout << "A:" << endl;
    cout << "Количество точек табулирования p = " << A.getp() << endl;
    cout << "Отрезок табулирования sec = " << A.getsec() << endl;
    float sec_;
    float p_;
    cout << "B:" << endl;
    cout << "Введите sec(отрезок табулирования)" << endl;// 4) задать отрезок табулирования , , , .
    cin >> sec_;
    B.setsec(sec_);
    cout << "Введите p (количество точек табулирования)" << endl;
    cin >> p_;
    B.setp(p_);
    cout << "B:" << endl;
    cout << "Количество точек табулирования p = " << B.getp() << endl;
    cout << "Отрезок табулирования = " << B.getsec() << endl;//5) узнать отрезок табулирования
    float k = B.tab(sec_, p_);//6) выполнить табулирование функции
    cout << "Результат табулирования - " << k << endl;//7) выдать результаты табулирования
    B.rec(k);
    //Tab Pifunction();
    //Tab Pifunction(0.5,0.5);
    system("pause");
}
