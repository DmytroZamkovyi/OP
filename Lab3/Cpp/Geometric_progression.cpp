#include "Geometric_progression.h"

double Geometric_progression::get_a()
{
	return a;
}

double Geometric_progression::get_q()
{
	return q;
}

unsigned int Geometric_progression::get_n()
{
	return n;
}

void Geometric_progression::output_str(int num)
{
	cout << endl << endl << "Progresion " << num << " :";
	cout << endl << "\tFirst member: " << a << endl
				 << "\tDifference: " << q << endl
				 << "\tNumber: " << n;
}
