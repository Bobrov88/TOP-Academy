#include "Flat.h"
	size_t Flat::number_of_flats = 0;

int main()
{
	// creating object with parametered constructor
	Flat A(36.5, 3100000, 1);
	Flat B(66.2, 5200000, 2);
	// creating object with copying constructor
	Flat C(A);
	Flat D(B);
	// operator > < (comparing prices)
	cout << boolalpha;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	// operator == (comparing squares)
	cout << (A == B) << endl;
	return 0;
}