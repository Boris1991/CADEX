#include <iostream>
#include <cmath>

#include "Elipses.h"

Elipses::Elipses(double radiusX, double radiusY){
	if(radiusX > 0 and radiusY > 0) {
		this->radiusX = radiusX;
		this->radiusY = radiusY;
	} else {
		std::cout << "Error! One of the radii or both are incorrect. They have to be more than 0." 
				<< std::endl;		
		std::cout << "By default radii are equal to 1." << std::endl;
		this->radiusX = 1;
		this->radiusY = 1;
	}
	//std::cout << "Calling Elipses" << std::endl;
}

Elipses::~Elipses(){
	//std::cout << "Calling ~Elipses()" << std::endl;
}

Point3D Elipses::getPoint(double t) {
	Point3D point3d;
	point3d.setX(radiusX * std::cos(t));
	point3d.setY(radiusY * std::sin(t));
	return point3d;
}

Vector3D Elipses::getFirstDerivative(double t) {
	Vector3D vector3d;
	vector3d.setX(-radiusX * std::sin(t));
	vector3d.setY(radiusY * std::cos(t));
	return vector3d;
}

void Elipses::getType() {
	 std::cout << "Elipse";
};

