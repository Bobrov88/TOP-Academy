#pragma once
#include <iostream>
#include "Reservoir.h"

class Interface {
	int size;
	Reservoir* _arr = nullptr;
public:
	explicit Interface(int&&) noexcept;
	explicit Interface(int&);
	void insert(Reservoir&&, int);
	void push_back(Reservoir&&);
	void push_back(Reservoir&);
	void push_front(Reservoir&&);
	void push_front(Reservoir&);
	void erase(int&&);
	void erase(int&);
	void pop_back();
	void pop_front();
	void print_all();
	void clear();
	Reservoir& operator[] (int);
	~Interface();
};