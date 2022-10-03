#include <iostream>
using namespace std;

class Human {
	int age;
	int* p;
public:
	Human() : age{ 0 }, p{ nullptr } { cout << "Default" << endl; }
	Human(int _age) : age{ _age }, p{ new int[_age] {} } { cout << "Parameters" << endl; }
	Human(const Human& obj) : age{ obj.age }, p{ new int[age]} {
		for (int i = 0; i < 5; i++) p[i] = obj.p[i];
		cout << "Copy" << endl;
	}
	Human(Human&& obj) : age{ obj.age } {
		p = obj.p;
		obj.p = nullptr;
		cout << "Move" << endl;
	}
	Human& operator=(Human&& obj) {
		age = obj.age;
		delete[]p;
		p = obj.p;
		obj.p = nullptr;
		return *this;
	}
	~Human() { delete[]p; cout << "Dest" << endl; }
};

Human func(int a) {
	Human C(5);
	//
	return C;
}
LEETCODE.COM->problems -> LEETCODE 75 Study plan
int main()
{
	Human a(5);
	Human b(a);
	Human z(5);
	b = z + func(5);
}