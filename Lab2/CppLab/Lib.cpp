#include "Lib.h"

Time::Time() {
	hour = 0;
	minute = 0;
}

void Time::setTime() {
	cout << "Enter hour: ";
	cin >> hour;

	while (hour < 0 || hour > 23) {
		cout << "Please try again! Value of hour can range from 0 to 23 inclusive" << endl;
		cout << "Enter hour: ";
		cin >> hour;
	}

	cout << "Enter minute: ";
	cin >> minute;
	
	while (minute < 0 || minute > 59) {
		cout << "Please try again! Value of minute can range from 0 to 59 inclusive" << endl;
		cout << "Enter minute: ";
		cin >> minute;
	}
}

string Time::getTime()
{
	return to_string(hour) + ":" + to_string(minute);
}

Timetable::Timetable() {
	destination = "";
}

void Timetable::setTimetable() {
	cout << endl << "Enter destination: ";
	cin >> destination;
	while (destination.size() < 2)
	{
		cout << "Please try again! The number of characters in destination name is at least 3" << endl;
		cin >> destination;

	}

	cout << "Set departure time" << endl;
	departure_time.setTime();

	cout << "Set duration of trip" << endl;
	duration_trip.setTime();
}

void Timetable::outputTimetable()
{
	cout << endl << "City: " + destination + "\tDeparture time: " + departure_time.getTime() + "\tDuration of trip: " + duration_trip.getTime();
}

void inputBus(vector<Timetable> &res)
{
	unsigned int leng;
	
	cout << endl << "Enter how many buses you want to add: ";
	cin >> leng;
	
	for (int i = 0; i < leng; i++)
	{
		Timetable t;
		t.setTimetable();
		res.push_back(t);
	}
}

void writeFile(vector<Timetable>& busses, Timetable& bus, string fileName)
{
	char rewriteMod;
	ofstream fout;
	cout << "Do you want to rewrite the file (y/n)?";
	while (true)
	{
		cin >> rewriteMod;
		if (rewriteMod == 'y')
		{
			fout.open(fileName, ios::binary);
			break;
		}
		else if (rewriteMod == 'n')
		{
			readFile(busses, bus, fileName);
			cout << endl << "Old file:" << endl;
			outputBusses(busses);
			cout << endl;
			fout.open(fileName, ios::app || ios::binary);
			break;
		}
		else
		{
			cout << "ERROR: Enter y or n" << endl;
		}
	}
	
	if (!fout.is_open())
	{
		cout << "ERROR: Cannot open file";
		exit(0);
	}
	else
	{
		inputBus(busses);
		for (int i = 0; i < busses.size(); i++)
		{
			fout.write((char*)&busses[i], sizeof(Timetable));
		}
		
	}
	fout.close();
}

void readFile(vector<Timetable>& busses, Timetable& bus, string fileName)
{
	ifstream fin;

	fin.open(fileName, ios::binary);

	if (!fin.is_open())
	{
		cout << "ERROR: Unable to read file" << endl;
		exit(0);
	}
	else
	{
		while (fin.read((char*)&bus, sizeof(Timetable)))
		{
			busses.push_back(bus);
		}
	}
	
	fin.close();
}

void outputBusses(vector<Timetable>& busses)
{
	for (int i = 0; i < busses.size(); i++)
	{
		busses[i].outputTimetable();
	}
}