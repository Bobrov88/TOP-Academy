#include <iostream>
using namespace std;
#define offset "\t\t\t\t"

double factorial(unsigned int number)
{
	double temp_fact = 1;
	if (!number) return 1;
	else
	{
		for (int i = 1; i <= number; i++)
		{
			temp_fact *= i;
		}
	}
	return temp_fact;
}

int razryad(int number)
{
	int R = 0;
	do
	{
		number /= 10;
		R++;
	} while (number);
	return R;
}

int length(int i)
{
	int s_length = 0;
	for (int j = 0; j <= i; j++)
	{
		s_length += razryad((int)(factorial(i) / (factorial(j) * factorial(i - j))));
		s_length++;
	}
	s_length--;
	return s_length;
}
void main()
{
	setlocale(LC_ALL, "");
	unsigned int n;
	cout << offset << "Треугольник Паскаля" << endl;
	cout << offset << "Введите количество строк (счёт с нуля): "; cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cout << offset;
		for (int k = 0; k < (length(n) - length(i)) / 2; k++) cout << " ";
		for (int j = 0; j <= i; j++)
		{
			cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";
		}
		cout << endl;
	}
}