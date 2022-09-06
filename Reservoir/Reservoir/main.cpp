//#include "includes.h"

#include <iostream>
#include <string>
constexpr auto KOEFF{ 0.7 };

class Reservoir {
	std::string name{};
	double depth{};
	double width{};
	double length{};
	bool isWaterMoving{};
public:
	Reservoir();
	Reservoir(std::string, double, double, double, bool);
	Reservoir(const Reservoir&);
	void setName(const std::string&);
	void setDepth(const double&);
	void setWidth(const double&);
	void setLength(const double&);
	void setWaterMovable(const bool&);
	std::string getName() const;
	double getDepth() const;
	double getWidth() const;
	double getlength() const;
	bool getWaterMovable() const;
	std::string defineType() const;
	double getVolume() const;
	double getSurfaceSquare() const;
	bool isSurfaceTheSame(const Reservoir&) const;
	Reservoir& operator=(const Reservoir&);
	~Reservoir();
};

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

int main()
{
	Interface R(1);
	R.push_back(Reservoir{ "First",3.0,0.3,5.5,false });
	R.push_front(Reservoir{ "Second",3.1,4.13,9.2,true });
	R.pop_back();
	R.print_all();
	R.clear();
	return 0;
}


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
		} while ((tempValue != 0) || (tempValue != 1));
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
	Interface::insert(std::move(other),0);
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
	Interface::erase(size-1);
}

void Interface::pop_front() {
	Interface::erase(0);
}

void Interface::print_all() {
	for (int i{ 0 }; i < size; ++i) {
		std::cout << "#" << i + 1 << " " << _arr[i].getName()
			<< " width: "	<< _arr[i].getWidth()
			<< " length: "	<< _arr[i].getlength()
			<< " depth: "	<< _arr[i].getWidth()
			<< " with "		<< (_arr[i].getWaterMovable() ? "moving" : "still")
			<< " water"		<< std::endl;
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

Reservoir::Reservoir() { }

Reservoir::Reservoir(std::string _name, double _depth, double _width, double _length, bool _isWaterMoving) :
	name{ _name },
	depth{ _depth },
	width{ _width },
	length{ _length },
	isWaterMoving{ _isWaterMoving } {}

Reservoir::Reservoir(const Reservoir& other)
{
	this->name = other.name;
	this->depth = other.depth;
	this->width = other.width;
	this->length = other.length;
	this->isWaterMoving = other.isWaterMoving;
}

void Reservoir::setName(const std::string& name)
{
	this->name = name;
}

void Reservoir::setDepth(const double& depth)
{
	this->depth = depth;
}

void Reservoir::setWidth(const double& width)
{
	this->width = width;
}

void Reservoir::setLength(const double& lenght)
{
	this->length = length;
}

void Reservoir::setWaterMovable(const bool& isWaterMoving)
{
	this->isWaterMoving = isWaterMoving;
}

std::string Reservoir::getName() const
{
	return name;
}

double Reservoir::getDepth() const
{
	return depth;
}

double Reservoir::getWidth() const
{
	return width;
}

double Reservoir::getlength() const
{
	return length;
}

bool Reservoir::getWaterMovable() const
{
	return isWaterMoving;
}

std::string Reservoir::defineType() const
{
	if (isWaterMoving) {
		if (width <= 2.0) return "Creek\n";
		else return "River\n";
	}
	if ((depth < 0.5) && (width < 2.0) && (length < 3.0)) return "Puddle\n";
	if (depth < 0.5 && (width > 2.0 && width < 4.0) && (length > 2.0 && length < 4.0)) return "Pond\n";
	if ((depth > 0.5 && depth < 2.5) && (width > 2.0 && width < 10.0) && (length > 3.0 && length < 10.0)) return "Pool\n";
	if ((depth > 2.5 && depth < 50.0) && (width > 10.0 && width < 3000.0) && (length > 10.0 && length < 3000.0)) return "Sea\n";
	if (depth > 50.0 && width > 3000.0 && length > 3000.0) return "Ocean\n";
	return "Type not defined\n";
}

double Reservoir::getVolume() const
{
	return width * depth * length * KOEFF;
}

double Reservoir::getSurfaceSquare() const
{
	return width * length;
}

bool Reservoir::isSurfaceTheSame(const Reservoir& other) const
{
	return this->getSurfaceSquare() == other.getSurfaceSquare();
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
	this->name = other.name;
	this->depth = other.depth;
	this->width = other.width;
	this->length = other.length;
	this->isWaterMoving = other.isWaterMoving;
	return *this;
}

Reservoir::~Reservoir()
{
	this->name = "";
	this->depth = 0;
	this->width = 0;
	this->length = 0;
	this->isWaterMoving = false;
}