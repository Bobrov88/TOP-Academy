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
	int getNumerator()
	{
		return numerator;
	}
	int getDenominator()
	{
		return denominator;
	}
	void setNumerator(int numerator) {
		this->numerator = numerator;
	}
	void setDenominator(int denominator) {
		this->denominator = denominator;
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
	Fraction& shorten() {
		if (this->numerator == this->denominator) {
			this->integral = 1;
			this->numerator = 0;
			return *this;
		}
		if (this->numerator > this->denominator) {
			this->integral = this->numerator / this->denominator;
			this->numerator %= this->denominator;
		}
		EuclidAlgorighm();
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
	return 0;

}