#pragma once
class Plural
{
	int* numbers;
	int size;

	void del_rep();
	bool find_num(int num);
	
public:
	Plural();
	Plural(int num);
	Plural(int len, int num);
	Plural(const Plural& obj);
	~Plural();
	void output_numbers();
	Plural operator + (const Plural obj);
	Plural operator * (const Plural obj);
	Plural operator - (const Plural obj);
};

