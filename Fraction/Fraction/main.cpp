#include <iostream>
using namespace std;

class Fraction {

public:
	Fraction()
	{
		numerator = 0;
		denominator = 1;
		integral = 0;
	}
	Fraction(int numerator) : Fraction() {
		this->numerator = numerator;
	}
	Fraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
		this->integral = 0;
	}
	Fraction(const Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integral = other.integral;
	}
	const int getNumerator()
	{
		return numerator;
	}
	const int getDenominator()
	{
		return denominator;
	}
	void setNumerator(int numerator) {
		this->numerator = numerator;
	}
	void setDenominator(int denominator) {
		if (denominator!=0)	this->denominator = denominator;
	}
	Fraction& operator=(const Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integral = other.integral;
		return *this;
	}
	Fraction operator+(const Fraction& other) {
		Fraction result;
		result.setNumerator(this->numerator * other.denominator + other.numerator * this->denominator);
		result.setDenominator(this->denominator * other.denominator);
		return result;
	}
	Fraction operator-(const Fraction& other) {
		Fraction result;
		result.setNumerator(this->numerator * other.denominator - other.numerator * this->denominator);
		result.setDenominator(this->denominator * other.denominator);
		return result;
	}
	Fraction operator*(const Fraction& other) {
		Fraction result;
		result.setNumerator(this->numerator * other.numerator);
		result.setDenominator(this->denominator * other.denominator);
		return result;
	}
	Fraction operator/(const Fraction& other) {
		Fraction result;
		result.setNumerator(this->numerator * other.denominator);
		result.setDenominator(this->denominator * other.numerator);
		return result;
	}
	Fraction& operator++() {
		this->numerator += this->denominator;
		return *this;
	}
	Fraction operator++(int) {
		Fraction oldFraction = *this;
		this->numerator += this->denominator;
		return oldFraction;
	}
	void Pow(int __pow) {
		if (__pow == 0) {
			this->numerator = this->denominator = 1;
			return;
		}
		if (__pow < 0) {
			__pow *= -1;
			int __temp = this->numerator;
			this->numerator = this->denominator;
			this->denominator = __temp;
		}
			int __temp_numerator = 1;
			int __temp_denominator = 1;
		do {
			__temp_denominator *= this->denominator;
			__temp_numerator *= this->numerator;
			--__pow;
		} while (__pow != 0);
		this->numerator = __temp_numerator;
		this->denominator = __temp_denominator;
	}
	void SquareRoot() {
		this->numerator = sqrt(this->numerator);
		this->denominator = sqrt(this->denominator);
	}
	void reduction() {
		if (this->numerator == this->denominator) {
			this->integral = 1;
			this->numerator = 0;
			return;
		}
		if (this->numerator > this->denominator) {
			this->integral = this->numerator / this->denominator;
			this->numerator %= this->denominator;
		}
		EuclidAlgorighm();
	}
	bool operator==(Fraction& other) {
		if (this->numerator * other.denominator == this->denominator * other.numerator)
			return true;
		return false;
	}
	bool operator!=(Fraction& other) {
		return !(*this == other);
	}
	bool operator>(Fraction& other) {
		if (this->numerator * other.denominator > this->denominator * other.numerator)
			return true;
		return false;
	}
	bool operator<(Fraction& other) {
		if (this->numerator * other.denominator < this->denominator * other.numerator)
			return true;
		return false;
	}
	bool operator>=(Fraction& other) {
		if (this->numerator * other.denominator >= this->denominator * other.numerator)
			return true;
		return false;
	}
	bool operator<=(Fraction& other) {
		if (this->numerator * other.denominator <= this->denominator * other.numerator)
			return true;
		return false;
	}
	void print() {
		if (this->denominator < 0) {
			this->denominator *= -1;
			this->numerator *= -1;
		}
		if (this->integral != 0) {
			if (this->numerator < 0) cout << "-";
			cout << this->integral;
			this->numerator = abs(this->numerator);
		}
		cout << "[" << this->numerator << "/" << this->denominator << "]" << endl;
	}

private:
	int numerator;
	int denominator;
	int integral;

	void EuclidAlgorighm() {
		int numerator = this->numerator;
		int denominator = this->denominator;
		int remainder = this->denominator % this->numerator;
		while (remainder != 0) {
			denominator = numerator;
			numerator = remainder;
			remainder = denominator % numerator;
		}
		this->numerator /= numerator;
		this->denominator /= numerator;
	}
};


int main() {

	Fraction A;					// calling default constructor
	A.setNumerator(21);			// calling setter for numerator
	A.setDenominator(84);		// calling setter for denominator
	Fraction B(49,133);			// calling constructor with parameters
	Fraction C = A + B;			// calling copy constructor after getting result of '+'
	Fraction D = A - B;			// calling copy constructor after getting result of '-'
	Fraction E = A * B;			// calling copy constructor after getting result of '*'
	Fraction F = A / B;			// calling copy constructor after getting result of '/'
	Fraction G = A++;			// calling copy constructor after postfix-incrementing 'A'
	Fraction H = ++B;			// calling copy constructor after prefix-incrementing 'H'
	Fraction I(3, 7);			// calling constructor with parameters
	I.Pow(3);					// Fraction I^3
	Fraction J(4, 144);			// calling constructor with parameters
	J.SquareRoot();				// Sqrt(J)

	cout << "A = "; A.print(); A.reduction(); cout << "--->"; A.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "B = "; B.print(); B.reduction(); cout << "--->"; B.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "C = "; C.print(); C.reduction(); cout << "--->"; C.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "D = "; D.print(); D.reduction(); cout << "--->"; D.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "E = "; E.print(); E.reduction(); cout << "--->"; E.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "F = "; F.print(); F.reduction(); cout << "--->"; F.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "G = "; G.print(); G.reduction(); cout << "--->"; G.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "H = "; H.print(); H.reduction(); cout << "--->"; H.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "I = "; I.print(); I.reduction(); cout << "--->"; I.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << "J = "; J.print(); J.reduction(); cout << "--->"; J.print(); cout << endl; // printing fractions with reduction and defining integral part
	cout << boolalpha;							// for printing boolean values as "true" of "false", not '0' or '1'
	cout << "D < E - " << (D < E) << endl;		// fraction comparison
	cout << "G > C - " << (G > C) << endl;		// fraction comparison
	cout << "F >= H - " << (F >= H) << endl;	// fraction comparison
	cout << "A <= B - " << (A <= B) << endl;	// fraction comparison

	return 0;

};