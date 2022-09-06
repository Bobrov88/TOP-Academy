#include "Interface.h"

Interface::Interface(int&& _size) noexcept : _arr{ new Reservoir[_size] }, size{ _size } {
	for (int i{ 0 }; i < _size; ++i) {
		int tempValue{ 0 };
		std::string tempString{ };
		std::cout << "Name: ";	std::cin >> tempString;  _arr[i].setName(tempString);
		std::cout << "Width: "; std::cin >> tempValue;  _arr[i].setWidth(tempValue);
		std::cout << "Length "; std::cin >> tempValue;  _arr[i].setLength(tempValue);
		std::cout << "Depth ";	std::cin >> tempValue;  _arr[i].setDepth(tempValue);
		do {
			std::cout << "Is water moving: Yes - 1, No - 0 "; std::cin >> tempValue;
		} while ((tempValue != 0) && (tempValue != 1));
		_arr[i].setWaterMovable(tempValue);
	}
}

Interface::Interface(int& _size) : Interface(std::move(_size)) {}

void Interface::insert(Reservoir&& other, int _idx) {
	Reservoir* temparr = new Reservoir[++size];
	for (int i{ 0 }; i < _idx; ++i)
		temparr[i] = _arr[i];
	temparr[_idx] = other;
	for (int i{ _idx + 1 }; i < size; ++i)
		temparr[i] = _arr[i - 1];
	delete[]_arr;
	_arr = temparr;
	temparr = nullptr;
}

void Interface::push_back(Reservoir&& other) {
	Interface::insert(std::move(other), size);
}

void Interface::push_back(Reservoir& other) {
	Interface::insert(std::move(other), size);
}

void Interface::push_front(Reservoir&& other) {
	Interface::insert(std::move(other), 0);
}

void Interface::push_front(Reservoir& other) {
	Interface::insert(std::move(other), 0);
}

void Interface::erase(int&& _idx) {
	Reservoir* temparr = new Reservoir[--size];
	for (int i{ 0 }; i < _idx; ++i)
		temparr[i] = _arr[i];
	for (int i{ _idx }; i < size; i++)
		temparr[i] = _arr[i + 1];
	delete[]_arr;
	_arr = temparr;
	temparr = nullptr;
}

void Interface::erase(int& _idx) {
	Interface::erase(std::move(_idx));
}

void Interface::pop_back() {
	Interface::erase(size - 1);
}

void Interface::pop_front() {
	Interface::erase(0);
}

void Interface::print_all() {
	for (int i{ 0 }; i < size; ++i) {
		std::cout << "#" << i + 1 << " " << _arr[i].getName()
			<< " width: " << _arr[i].getWidth()
			<< " length: " << _arr[i].getlength()
			<< " depth: " << _arr[i].getWidth()
			<< " with " << (_arr[i].getWaterMovable() ? "moving" : "still")
			<< " water" << std::endl;
	}
}

Reservoir& Interface::operator[](int _idx) {
	if (_idx < size) return _arr[_idx];
	throw("out of range");
}

void Interface::clear() {
	delete[]_arr;
	_arr = nullptr;
	size = 0;
}

Interface::~Interface()
{
	if (size) clear();
}