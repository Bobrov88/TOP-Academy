#pragma once
#include "Reservoir.h"
class Interface {
	Reservoir* R;
	int size;
public:
	Interface();
	Interface(int _size);
	void push_back(Reservoir& obj);
	void print(const Interface& I);
};
