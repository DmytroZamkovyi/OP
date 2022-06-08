#pragma once

struct TNode
{
	char inf;
	TNode* left;
	TNode* right;
};

void add(char a, TNode*& curr);
void print(TNode* curr);
void del_tree(TNode* curr);
void print_rec(TNode* curr, int tab, int max);
int max_len(TNode* curr);
