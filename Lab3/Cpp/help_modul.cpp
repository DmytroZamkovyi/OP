#include "help_modul.h"

vector<Geometric_progression> input_geo_progressions(int length)
{
	vector<Geometric_progression> geo_progressions;
	double a, q;
	unsigned int n;

	for (int i = 0; i < length; i++)
	{
		cout << endl << "Progresion " << i + 1 << " :" << endl;
		
		cout << "Enter a: ";
		cin >> a;

		cout << "Enter q: ";
		cin >> q;

		cout << "Enter n: ";
		cin >> n;

		Geometric_progression progres(a, q, n);
		geo_progressions.push_back(progres);
	}
	return geo_progressions;
}

int find_max(vector<Geometric_progression> progressions)
{
	double max_value = progressions[0].get_a() * (power(progressions[0].get_q(), progressions[0].get_n() - 1));
	int max_pos = 0;
	double temp;
	for (int i = 0; i < progressions.size(); i++)
	{
		temp = progressions[i].get_a() * (power(progressions[i].get_q(), progressions[i].get_n() - 1));
		if (temp > max_value)
		{
			max_value = temp;
			max_pos = i;
		}
	}
	return max_pos;
}

double power(double a, int n)
{
	double res = 1;
	for (int i = 0; i < n; i++)
	{
		res = res * a;
	}
	return res;
}