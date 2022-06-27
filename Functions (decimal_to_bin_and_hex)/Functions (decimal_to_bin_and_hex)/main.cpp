#include <iostream>
using namespace std;

#define offset "\t\t\t\t"

void printnumber(int number[], int position)
{
	for (int i = position - 1; i >= 0; i--)
	{
		if (number[i] > 9)
		{
			cout << (char)(65 + number[i] % 10);
		}
		else cout << number[i];
	}
	cout << endl;
}

void transpon(long long int number10, int sys, bool negative)
{
	int number[100], position = 0, i, length;
	do
	{
		number[position] = number10 % sys;
		number10 /= sys;
		position++;
	} while (number10);
	if (!negative)
	{
		switch (sys)
		{
		case 2: length = 64; break;
		case 8: length = 21; break;
		case 16: length = 16; break;
		}
		while (position < length)
		{
			number[position] = 0;
			position++;
		}
		for (i = 0; i < position; i++)
		{
			number[i] = sys - 1 - number[i];
		}
		i = 0;
		number[0]++;
		do
		{
			if (number[i] == sys)
			{
				number[i + 1]++;
				number[i] = 0;
			}
			i++;
		} while (number[i] == sys);
	}
	printnumber(number, position);
}

void main()
{
	setlocale(LC_ALL, "");
	long long int number10;
	bool negative = true;
	cout << offset << "Введите десятичное число: "; cin >> number10;
	if (number10 < 0)
	{
		negative = false;
		number10 = -number10;
	}
	cout << offset << "В двоичной системе: ";
	transpon(number10, 2, negative);
	cout << offset << "В восьмиричной системе: " << ((!negative) ? "1" : "");
	transpon(number10, 8, negative);
	cout << offset << "В шестнадцатиричной системе: ";
	transpon(number10, 16, negative);
	cout << endl;
}