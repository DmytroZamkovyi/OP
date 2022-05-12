#include "Lib.h"

//Варіант 14.
//
//Створити файл з розкладом руху міжміських автобусів: пункт призначення,
//час відправлення, та тривалість поїздки (у годинах та хвилинах). Видалити з файлу
//інформацію про рейси, в яких хоча б части ну шляху потрапляє на нічний час (з
//23:00 до 6:00). Виняток становлять маршрути з тривалістю шляху понад 17 годин.
//Визначити час відправлення останнього автобуса в заданий пункт призначення

int main() {
	vector<Timetable> busses;
	vector<Timetable> updateBusses;
	Timetable bus;

	string fileName = "txt.bin";
	int h, m;
	
	writeFile(busses, bus, fileName);
	busses.clear();
	cout << endl;

	cout << "Verified records for compliance with the condition: ";
	readFile(busses, bus, fileName);


	for (int i = 0; i < busses.size(); i++)
	{
		busses[i].outputTimetable();
		updateBusses.push_back(busses[i]);
		h = busses[i].departure_time.hour + busses[i].duration_trip.hour;
		m = busses[i].departure_time.minute + busses[i].duration_trip.minute;
		if (m >= 60)
		{
			m = m - 60;
			h++;
		}
		if (h >= 23 || h < 6 || (h == 6 && m == 0))
		{
			if (busses[i].duration_trip.hour >= 17)
			{
				cout << " - night time, but more than 17 hours";
			}
			else
			{
				cout << " - night time, but less than 17 hours";
				updateBusses.pop_back();
			}
		} 
	}
	
	ofstream fout;
	fout.open(fileName, ios::binary);

	for (int i = 0; i < updateBusses.size(); i++)
	{
		fout.write((char*)&updateBusses[i], sizeof(Timetable));
	}

	fout.close();
	cout << endl << "File after deletion:";

	for (int i = 0; i < updateBusses.size(); i++)
	{
		busses[i].outputTimetable();
	}
}