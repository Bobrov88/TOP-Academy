#pragma once
#include <iostream>
#include <string>

class Reservoir {
	std::string name;
	double depth;
	double width;
	double length;
	bool isWaterMoving;
public:
	Reservoir();
	explicit Reservoir(std::string&);
	Reservoir(std::string&, double&);
	Reservoir(std::string&, double&, double&);
	Reservoir(std::string&, double&, double&, double&);
	Reservoir(std::string&, double&, double&, double&, bool);
	Reservoir(const Reservoir&);
	Reservoir(Reservoir&&);
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