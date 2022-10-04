#include "Flat.h"

Flat::Flat(double _square, double _price, size_t _rooms) :
    square{ _square },
    price{ _price },
    rooms{ _rooms } {
    ++number_of_flats;
    cout << "Flat #" << number_of_flats << " created with parameters!" << endl;
}

Flat::Flat(const Flat& obj) :
    square{ obj.square },
    price{ obj.price },
    rooms{ obj.rooms } {
    ++number_of_flats;
    cout << "Flat #" << number_of_flats << " created by copying!" << endl;
}

Flat& Flat::operator=(const Flat& obj)
{
    square = obj.square;
    price = obj.price;
    rooms = obj.rooms;
    return *this;
}

void Flat::setSquare(double square)
{
    this->square = square;
}

void Flat::setPrice(double price)
{
    this->price = price;
}

void Flat::setRooms(size_t rooms)
{
    this->rooms = rooms;
}

double Flat::getSquare() const
{
    return square;
}

double Flat::getPrice() const
{
    return price;
}

size_t Flat::getRooms() const
{
    return rooms;
}

bool Flat::operator==(const Flat& obj) const
{
    return square == obj.square;
}

bool Flat::operator!=(const Flat& obj) const
{
    return square != obj.square;
}

bool Flat::operator>(const Flat& obj) const
{
    return price > obj.price;
}

bool Flat::operator<(const Flat& obj) const
{
    return price < obj.price;
}

Flat::~Flat()
{
    cout << "Flat #" << number_of_flats << " destructed!" << endl;
    --number_of_flats;
}

size_t Flat::getNumber_of_flats()
{
    return number_of_flats;
}

void Flat::setInitialNumber_of_flat()
{
    number_of_flats = 0;
}
