#pragma once
class DM
{
private:
	int n;
	double *arr;
public:
	DM();
	DM(int q);
	DM(const DM &x);
	~DM();

	DM& operator=(const DM &x);

	void set_n(int f);
	int get_n();

	void set_element(int x, double y);
	double get_element(int x);

	double get_min();
	int test();

	DM select();
};

