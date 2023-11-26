#include <iostream>
#include <cmath>

#include "Helixes3D.h"

Helixes3D::Helixes3D(double radius, double pitch) {
	if(radius > 0 and pitch > 0) {
		this->radius =radius;
		this->pitch = pitch;
	}
	else {
		std::cout << "Error! The radius or the pitch are incorrect. It have to be more than 0." << std::endl;
		std::cout << "By default radius and pitch are equal to 1." << std::endl;

		this->radius = 1;
		this->pitch = 1;
	}
	//std::cout << "Calling Helix3D()" << std::endl;

}

Helixes3D::~Helixes3D(){
	//std::cout << "Calling ~Helix3D()" << std::endl;
}

Point3D Helixes3D::getPoint(double t) {
	Point3D point3d;
	point3d.setX(radius * std::cos(t));
	point3d.setY(radius * std::sin(t));
	point3d.setZ(pitch / (2 * M_PI) * t);

	return point3d;
}

Vector3D Helixes3D::getFirstDerivative(double t) {
	Vector3D vector3d;
	vector3d.setX(-radius * std::sin(t));
	vector3d.setY(radius * std::cos(t));
	vector3d.setZ(pitch / (2 * M_PI));
	//std::cout << "radius" << radius << " t = " << t << std::endl;
	return vector3d;
}

void Helixes3D::getType() {
	 std::cout << "Hellix";
};
