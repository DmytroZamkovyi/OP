#include "Plurar.h"
#include <iostream>
#include <iomanip>

Plural::Plural()
{
	int num;
	srand(time(NULL));
	size = 5 + rand() % 10;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		num = rand() % 10;
		if (find_num(num))
		{
			i--;
		}
		else
		{
			numbers[i] = num;
		}
	}
}

Plural::Plural(int num)
{
	size = num;
	numbers = new int[size];
	int tmp;
	std::cout << "Enters plural: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> tmp;
		numbers[i] = tmp;
	}
	del_rep();
}

Plural::Plural(int len, int num)
{
	size = len;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		numbers[i] = num;
	}
}

Plural::Plural(const Plural& obj)
{
	size = obj.size;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		numbers[i] = obj.numbers[i];
	}
}

Plural::~Plural()
{
	delete[] numbers;
}

void Plural::output_numbers()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(5) << numbers[i];
	}
	std::cout << std::endl;
}

Plural Plural::operator+(const Plural obj)
{
	Plural tmp(size + obj.size, 0);
	for (int i = 0; i < size; i++)
	{
		tmp.numbers[i] = numbers[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		tmp.numbers[i + size] = obj.numbers[i];
	}
	tmp.del_rep();
	return tmp;
}

Plural Plural::operator*(const Plural obj)
{
	int leng,
		n = 0;
	if (size >= obj.size)
	{
		leng = size;
	}
	else
	{
		leng = obj.size;
	}
	Plural tmp(leng, 0);
	
	for (int i = 0; i < obj.size; i++)
	{
		if (find_num(obj.numbers[i]))
		{
			tmp.numbers[n] = obj.numbers[i];
			n++;
		}
	}
	tmp.size = n;
	tmp.del_rep();
	return tmp;
}

Plural Plural::operator-(const Plural obj)
{
	int n = 0;
	bool flag;
	Plural tmp(size, 0);
	for (int i = 0; i < size; i++)
	{
		flag = true;
		for (int j = 0; j < obj.size; j++)
		{
			if (obj.numbers[j] == numbers[i])
			{
				flag = false;
			}
		}
		if (flag)
		{
			tmp.numbers[n] = numbers[i];
			n++;
		}
	}
	tmp.size = n;
	return tmp;
}

void Plural::del_rep()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numbers[i] == numbers[j])
			{
				for (int k = j; k < size - 1; k++)
				{
					numbers[k] = numbers[k + 1];
				}
				size--;
			}
		}
	}
}

bool Plural::find_num(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == num)
		{
			return true;
		}
	}
	return false;
}
