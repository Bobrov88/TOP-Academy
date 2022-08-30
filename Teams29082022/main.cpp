#include <iostream>
using namespace std;
class Fraction {
private:
	int num;
	int den;
	int integral;
public:
	Fraction() {}
	Fraction(int _num, int _den) : num(_num), den{_den}, integral{0} { }
	Fraction(const Fraction &F)
	void Print() {
		cout << num << "/" << den << endl;
	}
	Fraction operator+(const Fraction& F) {
		Fraction C;
		C.num = num * F.den + den * F.num;
		C.den = den * F.den;
		C.integral = 0;
		return C;
	}
	bool operator>(const Fraction& F) {
		return (num * F.den > F.num * den);
	}

};

int main()
{
	Fraction F(1, 3);
	Fraction G(2, 6);
	Fraction I(G); I{ G };
	Fraction H = G + F;
	int a{ 1 };
	int b{ 2 };
	cout<<std::boolalpha;
	cout<< (a > b);
	cout << (G > F);
}