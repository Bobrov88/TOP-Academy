// reservoir.h - только объявление класса и прототипов методов
// reservoir.cpp - реализация самих методов, то, что пишется в КЛАСС::МЕТОД
// main.cpp - исполняемый код
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Reservoir {
	double depth;
	double width;
	double length;
	bool isWaterMoving;
	//bool transparent;
public:
	Reservoir();
	Reservoir(double, double, double, bool);
	double getDepth() const;
	void setDepth(double);
	double getVolume();
	string defineType() const;
	double getSideLenght() const;
};