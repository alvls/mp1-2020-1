#include <iostream>

#pragma once
class Konvert
{
private:
	double d;
public:
	Konvert();
	Konvert(double x);
	~Konvert();

	double arshin();
	double fut();
	double yard();
	double sagen();
	double metr();
	void set(double x);
	double get();
	void write();
};

#include <stdio.h>

Konvert::Konvert()
{
	d = 0;
}

Konvert::Konvert(double x)
{
	d = x;
}

Konvert::~Konvert()
{

}

double Konvert::metr()
{
	return d;
}

double Konvert::arshin()
{
	return d / 0.71;
}

double Konvert::fut()
{
	return d * 3.28;
}

double Konvert::yard()
{
	return d * 1.09;
}

double Konvert::sagen()
{
	return d / 2.13;
}

void Konvert::set(double x)
{
	d = x;
}

double Konvert::get()
{
	return d;
}

void Konvert::write()
{
	printf("%lf", d);
}

int main()
{
	printf("Vas privetstvuet konverter dlinn v1.0\n");
	double z;
	printf("Vvedite znachenie dlini v metrah: ");
	scanf_s("%lf", &z);

	Konvert Z(z);

	int k;
	printf("Uznat takushuyu dlinu v metrah\n1)Yes\n2)No\n");
	scanf_s("%d", &k);
	double znach;
	switch (k)
	{
	case 1:
		znach = Z.metr();
		printf("result = %lf metr\n", znach);
		break;
	case 2:
		break;
	}
	int f;
	printf("Napishite v kakuyu meru dlin perevesti:\n1)arshin\n2)fut\n3)yard\n4)sagen\n");
	scanf_s("%d", &f);

	switch (f)
	{
	case 1:
		znach = Z.arshin();
		printf("result = %lf arshin\n", znach);
		break;
	case 2:
		znach = Z.fut();
		printf("result = %lf fut\n", znach);
		break;
	case 3:
		znach = Z.yard();
		printf("result = %lf yard\n", znach);
		break;
	case 4:
		znach = Z.sagen();
		printf("result = %lf sagen\n", znach);
		break;
	}
	system("pause");
}