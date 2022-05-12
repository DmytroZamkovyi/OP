#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Time
{
	int hour;
	int minute;
	Time();
	void setTime();
	string getTime();
};

struct Timetable
{
	string destination;
	Time departure_time;
	Time duration_trip;
	Timetable();
	void setTimetable();
	void outputTimetable();
};

void inputBus(vector<Timetable> &res);
void outputBusses(vector<Timetable> &busses);
void readFile(vector<Timetable>&, Timetable&, string fileName);
void writeFile(vector<Timetable>&, Timetable&, string fileName);
