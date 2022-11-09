#include <iostream>
#include <math.h>
using namespace std;

template <class T1, class T2>
class Fraction {
	T1 numerator;
	T2 denominator;
	T1 integral;
public:
	Fraction() = default;
	Fraction(T1 num, T2 den) : numerator{ num }, denominator{ den }, integral{ 0 } {}

	//void reduction() {
	//	if (abs(this->numerator) == abs(this->denominator)) {
	//		this->integral = this->numerator / this->denominator;
	//		this->numerator = 0;
	//		return;
	//	}
	//	if (abs(this->numerator) > abs(this->denominator)) {
	//		this->integral = this->numerator / this->denominator;
	//		this->numerator %= (T1)this->denominator;
	//		this->numerator = abs(this->numerator);
	//		this->denominator = abs(this->denominator);
	//	}
	//	if (this->numerator) EuclidAlgorighm();
	//}

	//void EuclidAlgorighm() {
	//	long numerator = this->numerator;
	//	long denominator = this->denominator;
	//	long remainder = this->denominator % this->numerator;
	//	while (remainder != 0) {
	//		denominator = numerator;
	//		numerator = remainder;
	//		remainder = denominator % numerator;
	//	}
	//	this->numerator /= numerator;
	//	this->denominator /= numerator;
	//}

	void print() {
	/*	if (typeid(T1) != typeid(char) &&
			typeid(T2) != typeid(T1))
			reduction();*/
		cout << "[" << numerator << "/" << denominator << "]" << endl;
	}
};

int main()
{
	Fraction<int, int> A(3, 6);
	Fraction<char, int> B('x', 4);
	Fraction<double, double> C(4.6, 3.5);
	A.print();
	B.print();
	C.print();
	return 0;
}