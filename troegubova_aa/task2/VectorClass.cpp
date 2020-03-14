#include <iostream>

#include "Vector.h"

Vector::Vector()
{
	count = 0;
	memo = nullptr;
}
Vector::Vector(int _count) : count(_count)
{
	memo = new int[count];
}
Vector::Vector(int _count, int d) : count(_count)
{
	memo = new int[count];
	for (int i = 0; i < count; ++i)
		memo[i] = d;
}
Vector::Vector(int _count, int* ar) : count(_count)
{
	memo = new int[count];
	for (int i = 0; i < count; ++i)
		memo[i] = ar[i];
}
Vector::Vector(const Vector &vec)
{
	count = vec.count;
	memo = new int[count];
	for (int i = 0; i < count; ++i)
		memo[i] = vec.memo[i];
}
Vector::~Vector()
{
	delete[] memo;
	memo = NULL;
	count = 0;
}

void Vector::outPut(const char* name)
{
	std::cout << name << ":\t ";
	for (int i = 0; i < count; ++i)
		std::cout << memo[i] << "\t";
	std::cout << std::endl;
}
void Vector::outPut(const char* name) const
{
	std::cout << name << ":\t ";
	for (int i = 0; i < count; ++i)
		std::cout << memo[i] << "\t";
	std::cout << std::endl;
}
void Vector::setSize(int _count)
{
	delete[] memo;
	count = _count;
	memo = new int(count);
}
void Vector::setComp(int _numd, int _valute)
{
	memo[_numd] = _valute;
}

int Vector::getSize()
{
	return count;
}
int Vector::getComp(int numb)
{
	return memo[numb];
}
double Vector::getLen()
{
	double len = 0;
	for (int i = 0; i < count; i++)
		len += memo[i] * memo[i];
	len = sqrt(len);
	return len;
}

int& Vector::operator[](int index)
{
	if (index < 0 || index >= count)
		abort();
	return memo[index];
}
Vector& Vector::operator=(const Vector &vec) {
	if (this != &vec)
	{
		if (count != vec.count)
		{
			delete[] memo;
			count = vec.count;
			memo = new int[count];
		}
		for (int i = 0; i < count; ++i)
			memo[i] = vec.memo[i];
	}
	return *this;
}
Vector  Vector::operator+(const Vector &vec) {
	if (count != vec.count)
		abort();
	Vector res(count);
	for (int i = 0; i < count; ++i)
		res.memo[i] = memo[i] + vec.memo[i];
	return res;
}
int  Vector::operator*(const Vector &vec) {
	if (count != vec.count)
		abort();
	int res = 0;
	for (int i = 0; i < count; ++i)
		res += memo[i] * vec.memo[i];
	return res;
}
Vector  operator*(int d, const Vector &vec) {
	Vector res(vec.count);
	for (int i = 0; i < vec.count; ++i)
		res.memo[i] = d * vec.memo[i];
	return res;
}
std::ostream& operator<<(std::ostream& stream, const Vector &vec)
{
	for (int i = 0; i < vec.count; ++i)
		stream << vec.memo[i] << " ";
	stream << std::endl;
	return stream;
}
std::istream& operator>>(std::istream& stream, Vector &vec) {
	int strCount;
	stream >> strCount;
	if (vec.count != strCount)
	{
		if (vec.memo != NULL)
			delete[] vec.memo;
		vec.count = strCount;
		vec.memo = new int[strCount];
	}
	for (int i = 0; i < vec.count; ++i)
		stream >> vec.memo[i];
	return stream;
}