#include <iostream>
#include <math.h>


class Point {
public:
	Point() {
		this->x = 0;
		this->y = 0;
	}
	Point(double& x, double& y) {
		this->x = x;
		this->y = y;
	}
	double getX() const { return this->x; }
	double getY() const { return this->y; }
	void setX(double& x) { this->x = x; }
	void setY(double& y) { this->y = y; }

	double distance() const {
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}

	~Point() {};

private:
	double x;
	double y;
};

double distance(const Point&, const Point&);

int main() {

	double x = 0, y = 0;

	std::cout << "Point A: Enter x = "; std::cin >> x;
	std::cout << "         Enter y = "; std::cin >> y;

	Point A;
	A.setX(x);
	A.setY(y);
	// or another way
	// Point A(x, y);

	std::cout << "Point B: Enter x = "; std::cin >> x;
	std::cout << "         Enter y = "; std::cin >> y;
	
	Point B;
	B.setX(x);
	B.setY(y);
	// or another way
	// Point B(x, y);
	
	std::cout << "You entered A(" << A.getX() << ";" << A.getY() << ")\n";
	std::cout << "You entered B(" << B.getX() << ";" << B.getY() << ")\n";
	std::cout << "Distance to A from (0;0) is " << A.distance() << "\n";
	std::cout << "Distance to B from (0;0) is " << B.distance() << "\n";
	std::cout << "Distance from A to B is " << distance(A, B);

	return 0;
}

double distance(const Point& a, const Point& b) {
	return	sqrt(pow(a.getX() - b.getX(), 2) +
				 pow(a.getY() - b.getY(), 2));
}