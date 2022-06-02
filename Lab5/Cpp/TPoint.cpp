#include "TPoint.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

double random_val()
{
	return (-10 + rand() % 20 + rand() / 10000.0);
}

void TPoint::output(string str)
{
	cout << "========" << str << "========" << endl;
	cout << "\tx: " << coord.get_x() << endl
		 << "\ty: " << coord.get_y() << endl
		 << "\tz: " << coord.get_z() << endl;
}

TPoint_xy::TPoint_xy(double t)
{
	double x0 = random_val();
	double ax = random_val();
	double y0 = random_val();
	double ay = random_val();
	coord.set_x(x0 + ax * sin(t));
	coord.set_y(y0 + ay * cos(t));
	coord.set_z(0);
}

TPoint_xy::TPoint_xy(double x0, double ax, double y0, double ay, double t)
{
	coord.set_x(x0 + ax * sin(t));
	coord.set_y(y0 + ay * cos(t));
	coord.set_z(0);
}

double TPoint_xy::count_distace(TCoordinates t)
{
	return sqrt(pow(t.get_x() - coord.get_x(), 2) + pow(t.get_y() - coord.get_y(), 2));
}

TPoint_xyz::TPoint_xyz(double t)
{
	double  x0 = random_val(),
			ax = random_val(),
			y0 = random_val(),
			ay = random_val(),
			z0 = random_val(),
			az = random_val();
	coord.set_x(x0 + ax * sin(t));
	coord.set_y(y0 + ay * cos(t));
	coord.set_z(z0 + az *  t * t);
}

TPoint_xyz::TPoint_xyz(double x0, double ax, double y0, double ay, double z0, double az, double t)
{
	coord.set_x(x0 + ax * sin(t));
	coord.set_y(y0 + ay * cos(t));
	coord.set_z(z0 + az *  t * t);
}

double TPoint_xyz::count_distace(TCoordinates t)
{
	return sqrt(pow(t.get_x() - coord.get_x(), 2) + pow(t.get_y() - coord.get_y(), 2) + pow(t.get_z() - coord.get_z(), 2));
}
