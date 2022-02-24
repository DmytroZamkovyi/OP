#include "Header.h"

int characters_per_line(string s1, string s2);

void f_read(string path) {
	ifstream f(path);
	if (f.is_open()) {
		cout << "Text in file:" << endl;
		string line;
		while (!f.eof())
		{
			getline(f, line);
			cout << line << endl;
		}
		f.close();
		cout << "End of file";
	}
	else
	{
		cout << "Error: unable to read file";
	}
}

void f_write(string path) {

	string mode;
	cout << "\n\nDo you want to clear the file?" << endl
		<< "y - for yes" << endl << "n - for no" << endl;
	cin >> mode;
	while (mode != "y" and mode != "n")
	{
		cout << "ERROR: invalid value" << endl;
		cin >> mode;
	}

	if (mode == "y")
	{
		ofstream f(path, ofstream::out|ofstream::trunc);
		if (f.is_open()) {
			cout << "\nEnter text" << endl
				<< "<ENTER> - to enter a new line" << endl
				<< "<Ctrl+Z> - to complete the input" << endl;
			string line;
			while (getline(cin, line, '\26')) //<Ctrl+Z>
			{
				f << line;
			}
			f.close();
		}
		else
		{
			cout << "ERROR: could not open file";
		}
	}
	else
	{
		ofstream f(path, ofstream::app);
		if (f.is_open()) {
			string line;
			cout << "\nEnter text" << endl
				<< "<ENTER> - to enter a new line" << endl
				<< "<Ctrl+Z> - to complete the input" << endl;
			while (getline(cin, line, '\26')) //<Ctrl+Z>
			{
				f << line;
			}
			f.close();
		}
		else
		{
			cout << "ERROR: could not open file";
		}
	}
}

void f_check(string path)
{
	int braces[8] = {};
	string line;
	ifstream f(path);
	if (f.is_open())
	{
		cout << "Verified text: " << endl;
		while (!f.eof())
		{
			getline(f, line);
			braces[0] = characters_per_line(line, "(");
			braces[1] = characters_per_line(line, ")");
			braces[2] = characters_per_line(line, "{");
			braces[3] = characters_per_line(line, "}");
			braces[4] = characters_per_line(line, "[");
			braces[5] = characters_per_line(line, "]");
			braces[6] = characters_per_line(line, "<");
			braces[7] = characters_per_line(line, ">");

			bool ifTrue = braces[0] == braces[1] && braces[2] == braces[3] && braces[4] == braces[5] && braces[6] == braces[7];
			if (ifTrue)
			{
				cout << line << " - " << "All good!" << endl;
			}
			else
			{
				cout << line << " - " << "Somethink bad" << endl;
			}
		}
		f.close();
	}
	else
	{
		cout << "ERROR: unable to read file";
	}
	
}

int characters_per_line(string s1, string s2)
{
	int cnt = 0;
	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i] == s2[0])
		{
			if (s1.substr(i, s2.length()) == s2)
			{
				++cnt;
				i += s2.length() - 1;
			}
		}
	}
	return cnt;
}