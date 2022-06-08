#include <iostream>
#include "help_modul_6.h"
using namespace std;

void add(char a, TNode*& curr)
{
	if (!curr)
	{
		curr = new TNode;
		curr->inf = a;
		curr->left = 0;
		curr->right = 0;
		return;
	}
	if (curr->inf > a)
	{
		add(a, curr->left);
	}
	else if (curr->inf < a)
	{
		add(a, curr->right);
	}
}


void print(TNode* curr)
{
	cout << "Tree:";
	cout << endl << "================================================================" << endl;
	print_rec(curr, 0, 0);
	cout << "================================================================";
}


void del_tree(TNode* curr)
{
	if (!curr)
	{
		return;
	}
	del_tree(curr->left);
	del_tree(curr->right);
	delete curr;
}

void print_rec(TNode* curr, int tab, int max)
{
	if (!curr)
	{
		return;
	}
	print_rec(curr->right, ++tab, ++max);
	for (int i = 1; i < tab; i++) {
		cout << '\t';
	}
	cout << curr->inf << endl;
	print_rec(curr->left, tab, ++max);
}


int max_len(TNode* curr)
{
	if (curr == 0)
		return 0;
	int left, right;
	if (curr->left != NULL) {
		left = max_len(curr->left);
	}
	else
		left = -1;
	if (curr->right != NULL) {
		right = max_len(curr->right);
	}
	else
		right = -1;
	int max = left > right ? left : right;
	return max + 1;
}