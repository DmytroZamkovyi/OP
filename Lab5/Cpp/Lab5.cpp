#include "TPoint.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

/*
* Спроектувати клас "Рухома матеріальна точка", який представляє точку, що
* рухається в певному напрямку і містить методи для визначення координат точки
* в заданий момент часу t та обчислити відстань від неї до іншої точки. На основі
* цього класу створити класи-нащадки "Рухома матеріальна точка (x, y, z)", яка ру-
* хається у просторі і її координати визначаються як x=x0+a1*sin(t), y=y0+a2*cos(t),
* z=z0+a3*t^2 та "Рухома матеріальна точка (x, y)", яка рухається по площині і її ко-
* ординати визначаються як x=x0+a1*sin(t), y=y0+a2*cos(t), z=0. Створити q об'єктів
* класу "Рухома матеріальна точка (x, y, z)" та k об'єктів класу "Рухома матеріальна
* точка (x, y)" (дані згенерувати випадковим чином). Визначити найменшу відстань
* між рухомими матеріальними точками у заданий користувачем момент часу t
*/

int main()
{
	char mode;
	int q, k, t;
	cout << "Рухома матеріальна точка (x, y, z)" << endl;
	do {
		cout << "Генерувати випадкові числа? (+/-): "; cin >> mode;
	} while (mode != '+' && mode != '-');
	do {
		cout << "Введіть q: "; cin >> q;
	} while (q < 2);
	do {
		cout << "Введіть t: "; cin >> t;
	} while (t < 0);
	vector<TPoint_xyz> xyz;
	if (mode == '+')
	{
		srand(time(NULL));
		for (int i = 0; i < q; i++)
		{
			
			xyz.push_back(TPoint_xyz(t));
		}
	}
	else
	{
		double x0, ax, y0, ay, z0, az;
		for (int i = 0; i < q; i++)
		{
			cout << i + 1 << ": Введіть значення (x0, ax, y0, ay, z0, az): ";
			cin >> x0 >> ax >> y0 >> ay >> z0 >> az;
			xyz.push_back(TPoint_xyz(x0, ax, y0, ay, z0, az, t));
		}
	}
	double min_val = INFINITY, tmp;
	int min_t1 = 0,
		min_t2 = 0;

	for (int i = 0; i < q - 1; i++)
	{
		for (int j = i + 1; j < q; j++)
		{
			tmp = xyz[i].count_distace(xyz[j].get_coord());
			if (tmp < min_val)
			{
				min_t1 = i;
				min_t2 = j;
				min_val = tmp;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		xyz[i].output(to_string(i));
	}
	cout << "Найменше значення між точками " << min_t1 << " і " << min_t2 << " : " << min_val;
	

	cout << endl << endl << "=======================" << endl << endl;


	cout << "Рухома матеріальна точка (x, y)" << endl;
	do {
		cout << "Генерувати випадкові числа? (+/-): "; cin >> mode;
	} while (mode != '+' && mode != '-');
	do {
		cout << "Введіть k: "; cin >> k;
	} while (k < 2);
	do {
		cout << "Введіть t: "; cin >> t;
	} while (t < 0);
	vector<TPoint_xy> xy;
	if (mode == '+')
	{
		for (int i = 0; i < k; i++)
		{
			xy.push_back(TPoint_xy(t));
		}
	}
	else
	{
		double x0, ax, y0, ay;
		for (int i = 0; i < k; i++)
		{
			cout << i + 1 << ": Введіть значення (x0, ax, y0, ay): ";
			cin >> x0 >> ax >> y0 >> ay;
			xy.push_back(TPoint_xy(x0, ax, y0, ay, t));
		}
	}
	min_val = INFINITY;
	min_t1 = 0;
	min_t2 = 0;

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			tmp = xy[i].count_distace(xy[j].get_coord());
			if (tmp < min_val)
			{
				min_t1 = i;
				min_t2 = j;
				min_val = tmp;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		xy[i].output(to_string(i));
	}
	cout << "Найменше значення між точками " << min_t1 << " і " << min_t2 << " : " << min_val;
}