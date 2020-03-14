#include "Konverter.h"
#include <stdio.h>

Konverter::Konverter()  //конструктор по умолчанию без параметров в скобках
{
	d = 0;
}

Konverter::Konverter(double x)
{
	d = x;
}

Konverter::~Konverter()  //пустой
{
	//память освобождается автоматически
}

double Konverter::dume()
{
	return d * 100 / 2.5;
}

double Konverter::fut()
{
	return d * 3.28;
}

double Konverter::yard()
{
	return d * 1.1;
}

double Konverter::mile()
{
	return d * 0.000621371;
}

double Konverter::arshin()
{
	return d * 1.406;
}

double Konverter::millimeter()
{
	return d * 1000;
}

void Konverter::set(double x)  //положить
{
	d = x;
}

double Konverter::get()//взять
{
	return d;
}

void Konverter::write()
{
	printf("%lf", d);
}