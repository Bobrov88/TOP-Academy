#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	const auto eps{ 0.0000001 };
	float f{ 0.41002120f };
	long a {0};
	while (f - (int)f > eps) {
		f *= 10;
		++a;
	}
	cout << fixed<< f << endl;
	cout << pow(10, a) << endl;
	return 0;
}