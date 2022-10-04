#pragma once
#include <iostream>
using namespace std;

class Flat {
	double square;
	double price;
	size_t rooms;
	static size_t number_of_flats;
public:
	Flat() = default;
	Flat(double) = delete;
	Flat(double, double) = delete;
	Flat(double, double, size_t);
	Flat(const Flat&);

	Flat& operator=(const Flat&);

	void setSquare(double);
	void setPrice(double);
	void setRooms(size_t);

	double getSquare() const;
	double getPrice() const;
	size_t getRooms() const;

	bool operator==(const Flat&) const;
	bool operator!=(const Flat&) const;
	bool operator>(const Flat&) const;
	bool operator<(const Flat&) const;
	~Flat();

	static size_t getNumber_of_flats();
	static void setInitialNumber_of_flat();
};