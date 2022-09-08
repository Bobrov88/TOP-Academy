#include "Header.h"

Interface::Interface() : R{ nullptr },size{0}
{}

Interface::Interface(int _size) : size{ _size }, R{ new Reservoir[_size] }
{
	for (int i{ 0 }; i < size; i++) {
		double temp;
		cout << "Enter depth "; cin >> temp;
		R[i].setDepth(temp);
	}
}

void Interface::push_back(Reservoir& obj)
{
	++size;
	Reservoir* tempR = new Reservoir[size];
	for (int i{ 0 }; i < size-1; i++) tempR[i] = R[i];
	tempR[size - 1] = obj;
	delete[]R;
	R = tempR;
	tempR = nullptr;
}
				
void Interface::print(const Interface& I)
{
	for (int i{ 0 }; i < size; i++) cout << I.R[i].getDepth() << endl;
}
