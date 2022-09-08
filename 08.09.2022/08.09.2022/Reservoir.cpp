#include "Reservoir.h"

Reservoir::Reservoir()
{
}

Reservoir::Reservoir(double _depth, double _width, double _length,
    bool _isWaterMoving) :
    depth{ _depth }, width{ _width }, length{ _length },
    isWaterMoving{ _isWaterMoving } { }

double Reservoir::getDepth() const
{
    return depth;
}

void Reservoir::setDepth(double _depth)
{
    depth = _depth;
}

double Reservoir::getVolume()
{
    return depth * width * length;
}

string Reservoir::defineType() const
{
    if ((depth < 1.0) && (width < 3.0) && (length < 1.5) && (isWaterMoving == false))
        return "Pond";
    if ((depth > 1000.0) && (width > 3000.0) && (length > 10000.5)) return "Ocean";
}

double Reservoir::getSideLenght() const
{
    return 0.0;
}
