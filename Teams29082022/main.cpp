#include <iostream>
using namespace std;
using std::cout;
class Fraction {
private:
	int num;
	int den;
	int integral;
public:
	void set(int&, int&);
	Fraction();

	Fraction(int _num, int _den) : num(_num), den{ _den }, integral{ 0 }
	{ cout << "Param " << this << endl; }
	Fraction(const Fraction& F) : num{ F.num }, den{ F.den }, integral{ F.integral }
	{ cout << "Copy" << this << endl; }
		void Print() {
		cout << num << "/" << den << endl;
	}
	Fraction operator+(const Fraction& F) {
		Fraction C;
		cout << "Called +" << this << endl;
		C.num = num * F.den + den * F.num;
		C.den = den * F.den;
		C.integral = 0;
		return C;
	}
	bool operator>(const Fraction& F) {
		return (num * F.den > F.num * den);
	}
	~Fraction() { cout << "Called destructor! " << this << endl; }
};

void Fraction::set(int& num, int& den)
{
	this->num = num;
	this->den = den;
	// code...
}
Fraction::Fraction() : num(0), den{ 1 }, integral{ 0 }
{ cout << "Default " << this << endl; }

int main()
{
	Fraction A;
	Fraction G(2, 6);
	Fraction F(1, 3);
	Fraction I(G);
	Fraction H = G + F;
	int a{ 1 };
	int b{ 2 };
	F.set(a, b);
//	G.Print();
//	cout << std::boolalpha;
//	cout << (a > b);
//	cout << (G > F);
}