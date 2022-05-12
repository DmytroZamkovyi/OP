#pragma once
#include <string>
#include <iostream>
using namespace std;

class Geometric_progression
{
private:
	double a;
	double q;
	unsigned int n;

public:
	Geometric_progression(double set_a, double set_q, int set_n) : a(set_a), q(set_q), n(set_n) {};
	double get_a();
	double get_q();
	unsigned int get_n();
	void output_str(int);
};

