#include <iostream>

using namespace std;

class Singleton {
private:
	static Singleton* _instance[3];
	static int count;
	int d;
protected:
	Singleton() { d = 0; }
public:
	static Singleton* Instance() {
		if (count < 3)
		{
			_instance[count] = /*(Singleton*)*/ new Singleton();
			count++;
			return _instance[count-1];
		}
		else
		{
			return nullptr;
		}
	}
	int Get() { return d; }
	void Set(int _d) { d = _d; }
	void Print() { cout << "d=" << d << endl; }
	~Singleton() {
		if (count > 0) {
			for (int i{ 0 }; i < count; i++)
				delete _instance[i];
			delete[] _instance;
		}
	}
	};

Singleton* Singleton::_instance[] = { nullptr,nullptr,nullptr };
int Singleton::count = 0;

void main() {
	Singleton* obj[3];
	for (int i = 0; i < 3; i++) {
		obj[i] = Singleton::Instance();
		if (obj[i] != nullptr) {
			obj[i]->Set(i * 5);
			obj[i]->Print();
		}
	}
	Singleton* obj4 = Singleton::Instance();
	if (obj4 != nullptr) {
		obj4->Set(234);
		obj4->Print();
	}
}