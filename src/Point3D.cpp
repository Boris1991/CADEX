#include <iostream>

#include "Point3D.h"

void Point3D::Show() {
	
	std::cout << "Point has coordinates {" << this->x << ", " << this->y << ", "
			<< this->z << "} " ;
}

void Point3D::setX(double x) {
	this->x = x;
}

void Point3D::setY(double y) {
	this->y = y;
}

void Point3D::setZ(double z) {
	this->z = z;
}
