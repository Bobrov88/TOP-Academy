#pragma once
#include <iostream>
constexpr auto EPS{ 0.0000001 };
using namespace std;

class Fraction {

	long numerator;
	long denominator;
	long integral;
	void EuclidAlgorighm();

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

	bool operator==(int) const;
	bool operator==(float) const;
	bool operator==(double) const;
	bool operator==(long) const;

	bool operator!=(int) const;
	bool operator!=(float) const;
	bool operator!=(double) const;
	bool operator!=(long) const;

	bool operator>(int) const;
	bool operator>(float) const;
	bool operator>(double) const;
	bool operator>(long) const;

	bool operator<(int) const;
	bool operator<(float) const;
	bool operator<(double) const;
	bool operator<(long) const;

	bool operator>=(float) const;
	bool operator>=(double) const;
	bool operator>=(long) const;
	bool operator>=(int) const;

	bool operator<=(int) const;
	bool operator<=(float) const;
	bool operator<=(double) const;
	bool operator<=(long) const;

	Fraction operator+(int);
	Fraction operator-(int);
	Fraction operator*(int);
	Fraction operator/(int);
			 
	Fraction operator+(float);
	Fraction operator-(float);
	Fraction operator*(float);
	Fraction operator/(float);
			 
	Fraction operator/(double);
	Fraction operator-(double);
	Fraction operator*(double);
	Fraction operator+(double);
			 
	Fraction operator*(long);
	Fraction operator-(long);
	Fraction operator+(long);
	Fraction operator/(long);
			  
	void print() const;

	//private:
	//	void _preprint();
};

bool operator==(int, const Fraction&);
bool operator==(float, const Fraction&);
bool operator==(double, const Fraction&);
bool operator==(long, const Fraction&);
				
bool operator!=(int, const Fraction&);
bool operator!=(float, const Fraction&);
bool operator!=(double, const Fraction&);
bool operator!=(long, const Fraction&);
				
bool operator>(int, const Fraction&);
bool operator>(float, const Fraction&);
bool operator>(double, const Fraction&);
bool operator>(long, const Fraction&);
				
bool operator<(int, const Fraction&);
bool operator<(float, const Fraction&);
bool operator<(double, const Fraction&);
bool operator<(long, const Fraction&);
				
bool operator>=(float, const Fraction&);
bool operator>=(double, const Fraction&);
bool operator>=(long, const Fraction&);
bool operator>=(int, const Fraction&);
				
bool operator<=(int, const Fraction&);
bool operator<=(float, const Fraction&);
bool operator<=(double, const Fraction&);
bool operator<=(long, const Fraction&);

Fraction operator+(int, const Fraction&);
Fraction operator-(int, const Fraction&);
Fraction operator*(int, const Fraction&);
Fraction operator/(int, const Fraction&);

Fraction operator+(float, const Fraction&);
Fraction operator-(float, const Fraction&);
Fraction operator*(float, const Fraction&);
Fraction operator/(float, const Fraction&);

Fraction operator+(double, const Fraction&);
Fraction operator-(double, const Fraction&);
Fraction operator*(double, const Fraction&);
Fraction operator/(double, const Fraction&);

Fraction operator*(long, const Fraction&); 
Fraction operator-(long, const Fraction&); 
Fraction operator+(long, const Fraction&);
Fraction operator/(long, const Fraction&);
