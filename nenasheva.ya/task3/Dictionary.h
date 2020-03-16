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
	Dictionary(const Dictionary  &str);
	Dictionary &operator=(const Dictionary &str);
	void Add_word(string, string);
	void Output();
	string Get_en(string);
	bool Check_word(string);
	int Get_count();
	bool Change(string, string);
	void Save_to_file(string);
	void Read_from_file(string);
};