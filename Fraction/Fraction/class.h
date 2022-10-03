#pragma once
#include <iostream>
using namespace std;

class Fraction {

public:
	Fraction();
	explicit Fraction(int);
	Fraction(int, int);
	Fraction(const Fraction&);
	const int getNumerator();
	const int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	Fraction& operator=(const Fraction&);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	Fraction& operator++();
	Fraction operator++(int);
	void Pow(int);
	void SquareRoot();
	void reduction();
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator>(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator>=(const Fraction&) const;
	bool operator<=(const Fraction&) const;
	void print() const;

private:
	int numerator;
	int denominator;
	int integral;
	void EuclidAlgorighm();
//	void _preprint();
};
