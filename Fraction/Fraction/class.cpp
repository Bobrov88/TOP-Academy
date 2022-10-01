#include "class.h"

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
	integral = 0;
}

Fraction::Fraction(int numerator) : Fraction() {
	this->numerator = numerator;
}

Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	this->integral = 0;
}

Fraction::Fraction(const Fraction& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->integral = other.integral;
}

const int Fraction::getNumerator()
{
	return numerator;
}

const int Fraction::getDenominator()
{
	return denominator;
}

void Fraction::setNumerator(int numerator) {
	this->numerator = numerator;
}

void Fraction::setDenominator(int denominator) {
	if (denominator != 0)	this->denominator = denominator;
}

Fraction& Fraction::operator=(const Fraction& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->integral = other.integral;
	return *this;
}

Fraction Fraction::operator+(const Fraction& other) {
	Fraction result;
	result.setNumerator(this->numerator * other.denominator + other.numerator * this->denominator);
	result.setDenominator(this->denominator * other.denominator);
	return result;
}

Fraction Fraction::operator-(const Fraction& other) {
	Fraction result;
	result.setNumerator(this->numerator * other.denominator - other.numerator * this->denominator);
	result.setDenominator(this->denominator * other.denominator);
	return result;
}

Fraction Fraction::operator*(const Fraction& other) {
	Fraction result;
	result.setNumerator(this->numerator * other.numerator);
	result.setDenominator(this->denominator * other.denominator);
	return result;
}

Fraction Fraction::operator/(const Fraction& other) {
	Fraction result;
	result.setNumerator(this->numerator * other.denominator);
	result.setDenominator(this->denominator * other.numerator);
	return result;
}

Fraction& Fraction::operator++() {
	this->numerator += this->denominator;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction oldFraction = *this;
	this->numerator += this->denominator;
	return oldFraction;
}

void Fraction::Pow(int __pow) {
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

void Fraction::SquareRoot() {
	this->numerator = sqrt(this->numerator);		// possible data losing because of casting result of SQRT to int
	this->denominator = sqrt(this->denominator);	// possible data losing because of casting result of SQRT to int
}

void Fraction::reduction() {
	if (abs(this->numerator) == abs(this->denominator)) {
		this->integral = this->numerator / this->denominator;
		this->numerator = 0;
		return;
	}
	if (abs(this->numerator) > abs(this->denominator)) {
		this->integral = this->numerator / this->denominator;
		this->numerator %= this->denominator;
	}
	EuclidAlgorighm();
}

bool Fraction::operator==(const Fraction& other) const {
	if (this->numerator * other.denominator == this->denominator * other.numerator)
		return true;
	return false;
}

bool Fraction::operator!=(const Fraction& other) const {
	return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
	if (this->numerator * other.denominator > this->denominator * other.numerator)
		return true;
	return false;
}

bool Fraction::operator<(const Fraction& other) const {
	if (this->numerator * other.denominator < this->denominator * other.numerator)
		return true;
	return false;
}

bool Fraction::operator>=(const Fraction& other) const {
	if (this->numerator * other.denominator >= this->denominator * other.numerator)
		return true;
	return false;
}

bool Fraction::operator<=(const Fraction& other) const {
	if (this->numerator * other.denominator <= this->denominator * other.numerator)
		return true;
	return false;
}

void Fraction::print() {
	_preprint();
	if (this->integral) cout << this->integral;
	cout << "[" << this->numerator << "/" << this->denominator << "]" << endl;
}

void Fraction::EuclidAlgorighm() {
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

void Fraction::_preprint() {
	if (this->denominator < 0) {
		this->denominator *= -1;
		this->numerator *= -1;
	}
	if (this->integral != 0) {
		if (this->numerator < 0)
			this->integral *= -1;
		this->numerator = abs(this->numerator);
	}
}