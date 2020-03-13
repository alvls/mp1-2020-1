#pragma once
#include<string>
using namespace std;

class Dictionary
{
private: 
	string *ru;
	string *en;
	int n;
	int n_max;
public:
	Dictionary();
	~Dictionary();
	void Add_word(string, string);
	void Output();
	string Get_en(string);
	bool Check_word(string);
	int Get_count();
	bool Change(string, string);
	void Saved_to_file(string);
	void Read_form_file(string);
};