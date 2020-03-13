#include "Dictionary.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

Dictionary::Dictionary()
{
	n = 0;
	n_max = 1000;
	ru = new string[n_max];
	en = new string[n_max];
}


Dictionary::~Dictionary()
{
	delete[]ru;
	delete[]en;
}

void Dictionary::Add_word(string r, string e)
{
	ru[n] = r;
	en[n] = e;
	n++;
}

void Dictionary::Output()
{
	for (int i = 0; i < n; i++)
	{
		cout << ru[i];
		cout << " - ";
		cout << en[i];
		cout << endl;
	}
}

string Dictionary::Get_en(string r)
{
	for (int i = 0; i < n; i++)
	{
		if (ru[i] == r)
			return en[i];
	}
	return string();
}

bool Dictionary::Check_word(string r)
{
	for (int i = 0; i < n; i++)
	{
		if (r == ru[i])
			return true;
	}
	return false;
}

int Dictionary::Get_count()
{
	return n;
}

bool Dictionary::Change(string a, string b)
{
	if (Check_word(a) == false)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (a == ru[i])
		{
			en[i] = b;
			return true;
		}
	}
	return true;
}

void Dictionary::Saved_to_file(string name)
{
	FILE* out;
	fopen_s(&out, name.c_str(), "w");

	for (int i = 0; i < n; i++)
	{
		fprintf(out, "%s - %s\n", ru[i].c_str(), en[i].c_str());
	}

	fclose(out);
}

void Dictionary::Read_form_file(string name)
{
	FILE* in;
   	errno_t err = fopen_s(&in, name.c_str(), "r");
	if (in == NULL)
	{
		return;
	}
	char r[100], e[100];
	n = 0;
	while (fgets(r, 100, in))
	{
 		r[strlen(r) - 1] = 0;
		char* s = strchr(r, ' ');
		*s = 0;
		ru[n] = string(r);
		en[n] = string(s + 3);
		n++;
	}

	fclose(in);
}
