#ifndef CIRCLES_H
#define CIRCLES_H 1

#include "Curves.h"
#include "Point3D.h"

#include "Vector3D.h"


class Circles: public Curves {
	//Circles are defined thoughout a radius r
	double radius;

public:
	Circles(double radius);
	~Circles() override;
	Point3D getPoint(double t) override;
    Vector3D getFirstDerivative(double t) override;
    void getType() override;
    double getRadius();

};

#endif
