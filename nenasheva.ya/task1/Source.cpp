#include <iostream>
#include "Konverter.h"

int main()
{
	double z;
	printf("Enter value in meters: ");
	scanf_s("%lf", &z);
	Konverter Z(z);

	int r;
	printf("Measures of quantity for conversion:\n1)dume\n2)fut\n3)yard\n4)mile\n5)arshin\n6)millimeter\n");
	printf("Choose a measure of magnitude to conversion: ");
	scanf_s("%d", &r);

	double result;
	switch (r)
	{
	case 1:
		result = Z.dume();
		printf("result = %lf(dume)\n", result);
		break;
	case 2:
		result = Z.fut();
		printf("result = %lf(fut)\n", result);
		break;
	case 3:
		result = Z.yard();
		printf("result = %lf(yard)\n", result);
		break;
	case 4:
		result = Z.mile();
		printf("result = %lf(mile)\n", result);
		break;
	case 5:
		result = Z.arshin();
		printf("result = %lf(arshin)\n", result);
		break;
	case 6:
		result = Z.millimeter();
		printf("result = %lf(millimeter)\n", result);
		break;
	}

	printf("Enter new value in meters: ");
	scanf_s("%lf", &z);
	Z.set(z);
	printf("At the moment, inside me: %lf\n", Z.get());
	printf("We print the contents of the object: ");
	Z.write();
	printf("\n");

	system("pause");
}