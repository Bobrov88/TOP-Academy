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
	void shorten() {
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
		return !(*this > other);
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
	Fraction A;
	A.setNumerator(21);
	A.setDenominator(84);
	Fraction B(49,133);
	Fraction C = A + B;
	Fraction D = A - B;
	Fraction E = A * B;
	Fraction F = A / B;
	Fraction G = A++;
	Fraction H = ++B;
	cout << "A = "; A.print(); A.shorten(); cout << "--->"; A.print(); cout << endl;
	cout << "B = "; B.print(); B.shorten(); cout << "--->"; B.print(); cout << endl;
	cout << "C = "; C.print(); C.shorten(); cout << "--->"; C.print(); cout << endl;
	cout << "D = "; D.print(); D.shorten(); cout << "--->"; D.print(); cout << endl;
	cout << "E = "; E.print(); E.shorten(); cout << "--->"; E.print(); cout << endl;
	cout << "F = "; F.print(); F.shorten(); cout << "--->"; F.print(); cout << endl;
	cout << "G = "; G.print(); G.shorten(); cout << "--->"; G.print(); cout << endl;
	cout << "H = "; H.print(); H.shorten(); cout << "--->"; H.print(); cout << endl;
	cout << "D < E" << ((D < E) ? " true" : " false") << endl;
	cout << "G > C" << ((G > C) ? " true" : " false") << endl;
	
	return 0;

}