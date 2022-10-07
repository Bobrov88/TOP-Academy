#pragma once
#include <iostream>
constexpr auto EPS{ 0.0000001 };
using namespace std;

class Fraction {

public:
	Fraction();
	explicit Fraction(int);
	explicit Fraction(float);
	explicit Fraction(double);
	explicit Fraction(long);
	Fraction(long, long);
	Fraction(const Fraction&);
	const int getNumerator();
	const int getDenominator();
	void setNumerator(long);
	void setDenominator(long);
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
	long numerator;
	long denominator;
	long integral;
	void EuclidAlgorighm();
//	void _preprint();
};
