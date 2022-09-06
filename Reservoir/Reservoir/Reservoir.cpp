#include "Reservoir.h"

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