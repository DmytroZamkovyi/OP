#include <string>
#include <iostream>
#include "help_modul_6.h"

using namespace std;

/*
* Побудувати дерево, елементами якого є символи. Визначити максимальну глибину дерева (число гілок на найбільшому з маршрутів від кореня дерева до листків).
*/

int main()
{
	string str;
	cout << "Enter string to generate tree: ";
	cin >> str;

	TNode* curr = 0;

	for (int i = 0; str[i]; i++)
	{
		add(str[i], curr);

	}

	print(curr);

	char* list = 0;
	int* num = 0;

	cout << endl << endl << "Number of branches on largest of routes from root of the tree to the leaves: " << max_len(curr) - 1 << endl;

	del_tree(curr);
}