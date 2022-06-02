#pragma once
#include <string>

double random_val();

class TCoordinates {
private:
	double x, y, z;
public:
	TCoordinates() { x = 0; y = 0; z = 0; };
	TCoordinates(double tx, double ty, double tz) : x(tx), y(ty), z(tz) {};
	double get_x() { return x; };
	double get_y() { return y; };
	double get_z() { return z; };
	void set_x(double val) { x = val; };
	void set_y(double val) { y = val; };
	void set_z(double val) { z = val; };
};

class TPoint
{
protected:
	TCoordinates coord;
public:
	void output(std::string str);
	TCoordinates get_coord() { return coord; };

	virtual double count_distace(TCoordinates t) = 0;
};


class TPoint_xy :
	public TPoint
{
public:
	TPoint_xy(double t);
	TPoint_xy(double x0, double ax, double y0, double ay, double t);
	double count_distace(TCoordinates t);
};


class TPoint_xyz :
	public TPoint
{
public:
	TPoint_xyz(double t);
	TPoint_xyz(double x0, double ax, double y0, double ay, double z0, double az, double t);
	double count_distace(TCoordinates t);
};
