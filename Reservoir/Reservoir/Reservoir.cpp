#include "reservoir.h"

Reservoir::Reservoir() : 
	name {"Noname"},
	depth {0},
	width {0},
	length {0},
	isWaterMoving {false} {}

explicit Reservoir::Reservoir(std::string& _name) :
	name { _name },
	depth{ 2.0 },
	width{ 5.5 },
	length{ 4.5 },
	isWaterMoving{ false } {}

Reservoir::Reservoir(std::string& _name, double& _depth) :
	name{_name},
	depth {_depth},
	width {_depth*2},
	length {_depth*2},
	isWaterMoving {false} {}

Reservoir::Reservoir(std::string& _name, double& _depth, double& _width) :
	name{ _name },
	depth{ _depth },
	width{ _width },
	length{ _depth * 3 },
	isWaterMoving{ false } {}

Reservoir::Reservoir(std::string& _name, double& _depth, double& _width, double &_length) :
	name{ _name },
	depth{ _depth },
	width{ _width },
	length{ _length },
	isWaterMoving{ false } {}

Reservoir::Reservoir(std::string& _name, double& _depth, double& _width, double& _length, bool _isWaterMoving) :
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

Reservoir::Reservoir(Reservoir&&)
{
	// later
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
	return std::string();
}

double Reservoir::getVolume() const
{
	return 0.0;
}

double Reservoir::getSurfaceSquare() const
{
	return 0.0;
}

bool Reservoir::isSurfaceTheSame(const Reservoir&) const
{
	return false;
}

Reservoir& Reservoir::operator=(const Reservoir&)
{
	// // O: insert return statement here
}

Reservoir::~Reservoir()
{
}
