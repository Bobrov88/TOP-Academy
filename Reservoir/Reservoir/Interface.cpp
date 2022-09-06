#include "includes.h"

Interface::Interface(int&& _size) : _arr{ new Reservoir[_size] }, size{ _size } {
	for (int i{ 0 }; i < _size; ++i) {
		int tempValue{ 0 };
		std::string tempString{ };
		std::cout << "Name: "; std::cin >> tempString;  _arr[i].setName(tempString);
		std::cout << "Width: "; std::cin >> tempValue;  _arr[i].setWidth(tempValue);
		std::cout << "Length "; std::cin >> tempValue;  _arr[i].setLength(tempValue);
		std::cout << "Depth ";	std::cin >> tempValue;  _arr[i].setDepth(tempValue);
		std::cout << "Depth ";	std::cin >> tempValue;  _arr[i].setDepth(tempValue);
		std::cout << "Is water moving: Yes - 1, No - 0 "; std::cin >> tempValue;  _arr[i].setWaterMovable(tempValue);
	}
}
void Interface::push_back(Reservoir& other) {
	Reservoir* temparr = new Reservoir[++size];
	for (int i{ 0 }; i < size - 1; ++i)
		temparr[i] = std::move(_arr[i]);
	temparr[size - 1] = std::move(other);
	delete[]_arr;
	_arr = temparr;
	temparr = nullptr;
}

void Interface::pop_back() {
	Reservoir* temparr = new Reservoir[--size];
	for (int i{ 0 }; i < size; ++i)
		temparr[i] = std::move(_arr[i]);
	delete[]_arr;
	_arr = temparr;
	temparr = nullptr;
}

Interface::~Interface()
{
	delete[]_arr;
	_arr = nullptr;
}