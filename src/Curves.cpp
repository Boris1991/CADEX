#include <iostream>

#include "Point3D.h"
#include "Vector3D.h"

#include "Curves.h"
//#include "Circles.h"
//#include "Elipses.h"
//#include "Helixes3D.h"


Curves::Curves(){
	//std::cout << "Calling Curves()" << std::endl;
}

Curves::~Curves(){
	//std::cout << "Calling ~Curves()" << std::endl;
}

Point3D Curves::getPoint(double t) {
	Point3D point3d;
	return point3d;
}

Vector3D Curves::getFirstDerivative(double t) {
	Vector3D vector3d;
	return vector3d;
}

void Curves::getType() {
	 std::cout << "The figure is not recognised";
};
