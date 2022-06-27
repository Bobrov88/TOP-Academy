#include <iostream>
using namespace std;
#define offset "\t\t\t\t"

void main()
{
	setlocale(LC_ALL, "");
	int figure_size;
	int i = 0, j = 0;
	cout << offset << "Введите размер фигуры: "; cin >> figure_size;
	cout << offset << "Фигура 0:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = 0; j < figure_size; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << offset << "Фигура 1:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << offset << "Фигура 2:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = figure_size - i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << offset << "Фигура 3:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (j = i; j < figure_size; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << offset << "Фигура 4:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = 0; j < figure_size - i - 1; j++)
		{
			cout << " ";
		}
		for (j = figure_size - i - 1; j < figure_size; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << offset << "Фигура 5:" << endl;
	for (i = 0; i < figure_size * 2; i++)
	{
		cout << offset;
		for (j = 0; j < figure_size * 2; j++)
		{
			if (((j == figure_size - i - 1) && (i < figure_size)) || ((j == 3 * figure_size - i - 1) && (i >= figure_size)))
			{
				cout << "/";
			}
			else
			{
				if (((j == figure_size + i) && (i < figure_size)) || ((j == i - figure_size) && (i >= figure_size)))
				{
					cout << "\\";
				}
				else cout << " ";
			}
		}
		cout << endl;
	}
	cout << offset << "Фигура 6:" << endl;
	for (i = 0; i < figure_size; i++)
	{
		cout << offset;
		for (j = 0; j < figure_size; j++)
		{
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0))) cout << "+";
			else cout << "-";
			cout << " ";
		}
		cout << endl;
	}
}