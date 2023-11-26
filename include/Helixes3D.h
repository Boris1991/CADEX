#ifndef HELIXES_H
#define HELIXES_H 1

#include "Curves.h"
#include "Point3D.h"
#include "Vector3D.h"

class Helixes3D: public Curves {
	
	//Helixes are defined thoughout a radius r and step along Z
	double radius, pitch;

public:
	Helixes3D(double radius, double pitch);
	~Helixes3D() override;
	Point3D getPoint(double t) override;
    Vector3D getFirstDerivative(double t) override;
    void getType() override;
};

#endif
