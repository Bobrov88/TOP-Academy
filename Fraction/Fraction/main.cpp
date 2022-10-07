#include "class.h"

int main() {
	//Fraction A;				// calling default constructor
	//A.setNumerator(21);			// calling setter for numerator
	//A.setDenominator(84);			// calling setter for denominator
	//Fraction B(133,49);			// calling constructor with parameters
	//Fraction C = A + B;			// calling copy constructor after getting result of '+'
	//Fraction D = A - B;			// calling copy constructor after getting result of '-'
	//Fraction E = A * B;			// calling copy constructor after getting result of '*'
	//Fraction F = A / B;			// calling copy constructor after getting result of '/'
	//Fraction G = A++;			// calling copy constructor after postfix-incrementing 'A'
	//Fraction H = ++B;			// calling copy constructor after prefix-incrementing 'H'
	//Fraction I(3, 7);			// calling constructor with parameters
	//I.Pow(3);				// Fraction I^3
	//Fraction J(4, 144);			// calling constructor with parameters
	//J.SquareRoot();				// Sqrt(J)
	//cout << "A = "; A.print(); A.reduction(); cout << "--->"; A.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "B = "; B.print(); B.reduction(); cout << "--->"; B.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "C = "; C.print(); C.reduction(); cout << "--->"; C.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "D = "; D.print(); D.reduction(); cout << "--->"; D.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "E = "; E.print(); E.reduction(); cout << "--->"; E.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "F = "; F.print(); F.reduction(); cout << "--->"; F.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "G = "; G.print(); G.reduction(); cout << "--->"; G.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "H = "; H.print(); H.reduction(); cout << "--->"; H.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "I = "; I.print(); I.reduction(); cout << "--->"; I.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << "J = "; J.print(); J.reduction(); cout << "--->"; J.print(); cout << endl; // printing fractions with reduction and defining integral part
	//cout << boolalpha;							// for printing boolean values as "true" of "false", not '0' or '1'
	//cout << "D < E - " << (D < E) << endl;		// fraction comparison
	//cout << "G > C - " << (G > C) << endl;		// fraction comparison
	//cout << "F >= H - " << (F >= H) << endl;	// fraction comparison
	//cout << "A <= B - " << (A <= B) << endl;	// fraction comparison

	Fraction FL(4.5663f);
	FL.reduction();
	FL.print();
	Fraction DB(0.0000123);
	DB.reduction();
	DB.print();
	Fraction LL(1234567812L);
	LL.reduction();
	LL.print();
	return 0;

};