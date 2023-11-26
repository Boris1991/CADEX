#include <iostream>
#include <cmath>

#include "Circles.h"

Circles::Circles(double radius){
	if(radius > 0) {
		this->radius = radius;
	}
	else {
		std::cout << "Error! The radius is incorrect. It have to be more than 0." 
				<< std::endl;
		std::cout << "By default radius is equal to 1." << std::endl;
		this->radius = 1;
	}
	//std::cout << "Calling Circles()" << std::endl;
}

Circles::~Circles(){
	//std::cout << "Calling ~Circles()" << std::endl;
}

Point3D Circles::getPoint(double t) {
	Point3D point3d;
	point3d.setX(radius * std::cos(t));
	point3d.setY(radius * std::sin(t));
	return point3d;
}

Vector3D Circles::getFirstDerivative(double t) {
	Vector3D vector3d;
	vector3d.setX(-radius * std::sin(t));
	vector3d.setY(radius * std::cos(t));
	return vector3d;
}

void Circles::getType() {
	 std::cout << "Circle";
};

double Circles::getRadius() {
	return this->radius;
}
