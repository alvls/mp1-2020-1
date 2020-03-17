
#pragma once
#include "Tab.h"
float exponenta(float j)
{
    return exp(j);
}
float cosinus(float j)
{
    return cos(j);
}
float sinus(float j)
{
    return sin(j);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Tab A;
    cout << "A:" << endl;
    cout << "Количество точек табулирования point = " << A.getpoint() << endl;//3) узнать текущее число точек табулирования
    cout << "Левая граница табулирования = " << A.getleft() << endl;
    cout << "Правая граница табулирования = " << A.getright() << endl;

    Tab B(2,18,4,exponenta);
    cout << "A = B" << endl;
    A = B;
    cout << "A:" << endl;
    cout << "Количество точек табулирования point = " << A.getpoint() << endl;
    cout << "Левая граница табулирования = " << A.getleft() << endl;
    cout << "Правая граница табулирования = " << A.getright() << endl;
    float right_;
    float left_;
    float point_;
    cout << "B:" << endl;
    cout << "Введите левую границу табулирования" << endl;// 4) задать отрезок табулирования , , , .
    cin >> left_;
    B.setleft(left_);
    cout << "Введите правую границу табулирования" << endl;// 4) задать отрезок табулирования , , , .
    cin >> right_;
    B.setright(right_);
    cout << "Введите число точек табулирования" << endl;//2) задать текущее число точек табулирования
    cin >> point_;
    B.setpoint(point_);
    cout << "B:" << endl;
    cout << "Число точек табулирования point = " << B.getpoint() << endl;
    cout << "Отрезок табулирования  : " <<" left= "<<B.getleft() << " right= " << B.getright() << endl;//5) узнать отрезок табулирования
    int k = B.tabulate();//6) выполнить табулирование функции
    cout << "Результаты табулирования:" << endl;//7) выдать результаты табулирования
    B.save_to_file(k);
    B.read_file();
    system("pause");
}
/*
//char menu1[5][15] = { "1)экспонента","2)косинус","3)синус" };
// int choice = item(menu1, 5);
    //int choice;
    //cin >> choice;
    Tab A;//1) задать текущую функцию
int item(char menu[][15], int nmenu) {//
    int i, k;
    for (i = 0; i < nmenu; i++)
        printf("%s\n", menu[i]);
    cin >> k;
    return k;
      //B.rec(k);
        //
       //
}*/
//unum ={}