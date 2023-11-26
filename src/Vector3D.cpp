#include <iostream>

#include "Vector3D.h"

void Vector3D::Show() {
	
	std::cout << "Vector has coordinates {" << this->x << ", " << this->y << ", "
			<< this->z << "} " ;	
}

void Vector3D::setX(double x) {
	this->x = x;
}

void Vector3D::setY(double y) {
	this->y = y;
}

void Vector3D::setZ(double z) {
	this->z = z;
}
